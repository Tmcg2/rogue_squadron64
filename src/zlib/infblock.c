#include "common.h"

#include "main/192E0.h"
#include "zlib/infutil.h"
#include "zlib/infblock.h"

/* Table for deflate from PKZIP's appnote.txt. */
u32 border[] = { /* Order of the bit length code lengths */
        16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15};

// DO NOT DELTE ME I AM REQUIRED FOR MATCHING
u32 data_junk_zlib_infblock = 0xAE020038;

void inflate_blocks_reset(inflate_blocks_statef *s, z_stream *z, u32 *c) {
    if (s->checkfn != Z_NULL) *c = s->check;
    if (s->mode == BTREE || s->mode == DTREE) ZFREE(z, s->sub.trees.blens);
    if (s->mode == CODES) {
        inflate_codes_free(s->sub.decode.codes, z);
        inflate_trees_free(s->sub.decode.td, z);
        inflate_trees_free(s->sub.decode.tl, z);
    }
    s->mode = TYPE;
    s->bitk = 0;
    s->bitb = 0;
    s->read = s->write = s->window;
    if (s->checkfn != Z_NULL) z->adler = s->check = (*s->checkfn)(0L, Z_NULL, 0);
}

inflate_blocks_statef *inflate_blocks_new(z_stream *z, check_func c, u32 w) {
    inflate_blocks_statef *s;

    if ((s = (inflate_blocks_statef *)ZALLOC(z,1,sizeof(struct inflate_blocks_state))) == Z_NULL) return s;
    if ((s->window = (u8 *)ZALLOC(z, 1, w)) == Z_NULL) {
        ZFREE(z, s);
        return Z_NULL;
    }
    s->end = s->window + w;
    s->checkfn = c;
    s->mode = TYPE;
    ///////// This is an inlined version of `inflate_blocks_reset`
    if (s->checkfn != Z_NULL) s->check = s->check;
    if (s->mode == BTREE || s->mode == DTREE) ZFREE(z, s->sub.trees.blens);
    if (s->mode == CODES) {
        inflate_codes_free(s->sub.decode.codes, z);
        inflate_trees_free(s->sub.decode.td, z);
        inflate_trees_free(s->sub.decode.tl, z);
    }
    s->mode = TYPE;
    s->bitk = 0;
    s->bitb = 0;
    s->read = s->write = s->window;
    if (s->checkfn != Z_NULL) z->adler = s->check = (*s->checkfn)(0L, Z_NULL, 0);
    /////////
    return s;
}

s32 inflate_blocks(inflate_blocks_statef *s, z_stream *z, s32 r) {
  u32 t;               /* temporary storage */
  u32 b;              /* bit buffer */
  u32 k;               /* bits in bit buffer */
  u8 *p;             /* input data pointer */
  u32 n;               /* bytes available there */
  u8 *q;             /* output window write pointer */
  u32 m;               /* bytes to end of window or read pointer */

  /* copy input/output information to locals (UPDATE macro restores) */
  LOAD

  /* process input based on current state */
  while (1) switch (s->mode)
  {
    case TYPE:
      NEEDBITS(3)
      t = (u32)b & 7;
      s->last = t & 1;
      switch (t >> 1)
      {
        case 0:                         /* stored */
          DUMPBITS(3)
          t = k & 7;                    /* go to byte boundary */
          DUMPBITS(t)
          s->mode = LENS;               /* get length of stored block */
          break;
        case 1:                         /* fixed */
          {
            u32 bl, bd;
            inflate_huft *tl, *td;

            inflate_trees_fixed(&bl, &bd, &tl, &td);
            s->sub.decode.codes = inflate_codes_new(bl, bd, tl, td, z);
            if (s->sub.decode.codes == Z_NULL)
            {
              r = Z_MEM_ERROR;
              LEAVE
            }
            s->sub.decode.tl = Z_NULL;  /* don't try to free these */
            s->sub.decode.td = Z_NULL;
          }
          DUMPBITS(3)
          s->mode = CODES;
          break;
        case 2:                         /* dynamic */
          DUMPBITS(3)
          s->mode = TABLE;
          break;
        case 3:                         /* illegal */
          DUMPBITS(3)
          s->mode = BAD;
          r = Z_DATA_ERROR;
          LEAVE
      }
      break;
    case LENS:
      NEEDBITS(32)
      if ((((~b) >> 16) & 0xffff) != (b & 0xffff))
      {
        s->mode = BAD;
        r = Z_DATA_ERROR;
        LEAVE
      }
      s->sub.left = (u32)b & 0xffff;
      b = k = 0;                      /* dump bits */
      s->mode = s->sub.left ? STORED : (s->last ? DRY : TYPE);
      break;
    case STORED:
      if (n == 0)
        LEAVE
      NEEDOUT
      t = s->sub.left;
      if (t > n) t = n;
      if (t > m) t = m;
      zmemcpy(q, p, t);
      p += t;  n -= t;
      q += t;  m -= t;
      if ((s->sub.left -= t) != 0)
        break;
      s->mode = s->last ? DRY : TYPE;
      break;
    case TABLE:
      NEEDBITS(14)
      s->sub.trees.table = t = (u32)b & 0x3fff;
      if ((t & 0x1f) > 29 || ((t >> 5) & 0x1f) > 29)
      {
        s->mode = BAD;
        r = Z_DATA_ERROR;
        LEAVE
      }
      t = 258 + (t & 0x1f) + ((t >> 5) & 0x1f);
      if (t < 19)
        t = 19;
      if ((s->sub.trees.blens = (u32*)ZALLOC(z, t, sizeof(u32))) == Z_NULL)
      {
        r = Z_MEM_ERROR;
        LEAVE
      }
      DUMPBITS(14)
      s->sub.trees.index = 0;
      s->mode = BTREE;
    case BTREE:
      while (s->sub.trees.index < 4 + (s->sub.trees.table >> 10))
      {
        NEEDBITS(3)
        s->sub.trees.blens[border[s->sub.trees.index++]] = (u32)b & 7;
        DUMPBITS(3)
      }
      while (s->sub.trees.index < 19)
        s->sub.trees.blens[border[s->sub.trees.index++]] = 0;
      s->sub.trees.bb = 7;
      t = inflate_trees_bits(s->sub.trees.blens, &s->sub.trees.bb,
                             &s->sub.trees.tb, z);
      if (t != Z_OK)
      {
        r = t;
        if (r == Z_DATA_ERROR)
          s->mode = BAD;
        LEAVE
      }
      s->sub.trees.index = 0;
      s->mode = DTREE;
    case DTREE:
      while (t = s->sub.trees.table,
             s->sub.trees.index < 258 + (t & 0x1f) + ((t >> 5) & 0x1f))
      {
        inflate_huft *h;
        u32 i, j, c;

        t = s->sub.trees.bb;
        NEEDBITS(t)
        h = s->sub.trees.tb + ((u32)b & inflate_mask[t]);
        t = h->word.what.Bits;
        c = h->more.Base;
        if (c < 16)
        {
          DUMPBITS(t)
          s->sub.trees.blens[s->sub.trees.index++] = c;
        }
        else /* c == 16..18 */
        {
          i = c == 18 ? 7 : c - 14;
          j = c == 18 ? 11 : 3;
          NEEDBITS(t + i)
          DUMPBITS(t)
          j += (u32)b & inflate_mask[i];
          DUMPBITS(i)
          i = s->sub.trees.index;
          t = s->sub.trees.table;
          if (i + j > 258 + (t & 0x1f) + ((t >> 5) & 0x1f) ||
              (c == 16 && i < 1))
          {
            s->mode = BAD;
            r = Z_DATA_ERROR;
            LEAVE
          }
          c = c == 16 ? s->sub.trees.blens[i - 1] : 0;
          do {
            s->sub.trees.blens[i++] = c;
          } while (--j);
          s->sub.trees.index = i;
        }
      }
      inflate_trees_free(s->sub.trees.tb, z);
      s->sub.trees.tb = Z_NULL;
      {
        u32 bl, bd;
        inflate_huft *tl, *td;
        inflate_codes_statef *c;

        bl = 9;         /* must be <= 9 for lookahead assumptions */
        bd = 6;         /* must be <= 9 for lookahead assumptions */
        t = s->sub.trees.table;
#ifdef DEBUG
      inflate_hufts = 0;
#endif
        t = inflate_trees_dynamic(257 + (t & 0x1f), 1 + ((t >> 5) & 0x1f),
                                  s->sub.trees.blens, &bl, &bd, &tl, &td, z);
        if (t != Z_OK)
        {
          if (t == (u32)Z_DATA_ERROR)
            s->mode = BAD;
          r = t;
          LEAVE
        }
        if ((c = inflate_codes_new(bl, bd, tl, td, z)) == Z_NULL)
        {
          inflate_trees_free(td, z);
          inflate_trees_free(tl, z);
          r = Z_MEM_ERROR;
          LEAVE
        }
        ZFREE(z, s->sub.trees.blens);
        s->sub.decode.codes = c;
        s->sub.decode.tl = tl;
        s->sub.decode.td = td;
      }
      s->mode = CODES;
    case CODES:
      UPDATE
      if ((r = inflate_codes(s, z, r)) != Z_STREAM_END)
        return inflate_flush(s, z, r);
      r = Z_OK;
      inflate_codes_free(s->sub.decode.codes, z);
      inflate_trees_free(s->sub.decode.td, z);
      inflate_trees_free(s->sub.decode.tl, z);
      LOAD
      if (!s->last)
      {
        s->mode = TYPE;
        break;
      }
      if (k > 7)              /* return unused byte, if any */
      {
        k -= 8;
        n++;
        p--;                    /* can always return one */
      }
      s->mode = DRY;
    case DRY:
      FLUSH
      if (s->read != s->write)
        LEAVE
      s->mode = DONE;
    case DONE:
      r = Z_STREAM_END;
      LEAVE
    case BAD:
      r = Z_DATA_ERROR;
      LEAVE
    default:
      r = Z_STREAM_ERROR;
      LEAVE
  }
}

s32 inflate_blocks_free(inflate_blocks_statef *s, z_stream *z, u32 *c) {
    ///////// This is an inlined version of `inflate_blocks_reset`
    if (s->checkfn != Z_NULL) *c = s->check;
    if (s->mode == BTREE || s->mode == DTREE) ZFREE(z, s->sub.trees.blens);
    if (s->mode == CODES) {
        inflate_codes_free(s->sub.decode.codes, z);
        inflate_trees_free(s->sub.decode.td, z);
        inflate_trees_free(s->sub.decode.tl, z);
    }
    s->mode = TYPE;
    s->bitk = 0;
    s->bitb = 0;
    s->read = s->write = s->window;
    if (s->checkfn != Z_NULL) z->adler = s->check = (*s->checkfn)(0L, Z_NULL, 0);
    /////////

    ZFREE(z, s->window);
    ZFREE(z, s);
    return Z_OK;
}

void inflate_set_dictionary(inflate_blocks_statef *s, const u8 *d, u32 n) {
    zmemcpy((u8 *)s->window, d, n);
    s->read = s->write = s->window + n;
}

INCLUDE_ASM("asm/nonmatchings/zlib/infblock", fake_func_8002851C);

INCLUDE_RODATA("asm/nonmatchings/zlib/infblock", junk_80000AD8);
