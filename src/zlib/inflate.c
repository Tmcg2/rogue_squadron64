#include "common.h"

#include "PR/ultratypes.h"
#include "zlib/zlib.h"
#include "zlib/forward_declares.h"
#include "zlib/zutil.h"
#include "zlib/adler32.h"

struct internal_state {

  /* mode */
  // The names here are purely an artifact of my wacky include structure, they have less verbose names in the zlib source
  enum {
      RS_INFLATE_METHOD,   /* waiting for method byte */
      RS_INFLATE_FLAG,     /* waiting for flag byte */
      RS_INFLATE_DICT4,    /* four dictionary check bytes to go */
      RS_INFLATE_DICT3,    /* three dictionary check bytes to go */
      RS_INFLATE_DICT2,    /* two dictionary check bytes to go */
      RS_INFLATE_DICT1,    /* one dictionary check byte to go */
      RS_INFLATE_DICT0,    /* waiting for inflateSetDictionary */
      RS_INFLATE_BLOCKS,   /* decompressing blocks */
      RS_INFLATE_CHECK4,   /* four check bytes to go */
      RS_INFLATE_CHECK3,   /* three check bytes to go */
      RS_INFLATE_CHECK2,   /* two check bytes to go */
      RS_INFLATE_CHECK1,   /* one check byte to go */
      RS_INFLATE_DONE,     /* finished check, done */
      RS_INFLATE_BAD}      /* got an error--stay here */
    mode;               /* current inflate mode */

  /* mode dependent information */
  union {
    u32 method;        /* if FLAGS, method byte */
    struct {
      u32 was;                /* computed check value */
      u32 need;               /* stream check value */
    } check;            /* if CHECK, check values to compare */
    u32 marker;        /* if BAD, inflateSync's marker bytes count */
  } sub;        /* submode */

  /* mode independent information */
  s32  nowrap;          /* flag for no wrapper */
  u32 wbits;           /* log2(window size)  (8..15, defaults to 15) */
  inflate_blocks_statef 
    *blocks;            /* current inflate_blocks state */

};

s32 inflateReset(z_stream *z) {
  u32 c;

  if (z == Z_NULL || z->state == Z_NULL)
    return Z_STREAM_ERROR;
  z->total_in = z->total_out = 0;
  z->msg = Z_NULL;
  z->state->mode = z->state->nowrap ? RS_INFLATE_BLOCKS : RS_INFLATE_METHOD;
  inflate_blocks_reset(z->state->blocks, z, &c);
  return Z_OK;
}

s32 inflateEnd(z_stream *z) {
  u32 c;

  if (z == Z_NULL || z->state == Z_NULL || z->zfree == Z_NULL)
    return Z_STREAM_ERROR;
  if (z->state->blocks != Z_NULL)
    inflate_blocks_free(z->state->blocks, z, &c);
  ZFREE(z, z->state);
  z->state = Z_NULL;
  return Z_OK;
}

s32 inflateInit2_(z_stream *z, s32 w, const char *version, s32 stream_size) {
  if (version == Z_NULL || version[0] != "f5"[0] ||
      stream_size != sizeof(z_stream))
      return Z_VERSION_ERROR;

  /* initialize state */
  if (z == Z_NULL)
    return Z_STREAM_ERROR;
  z->msg = Z_NULL;
  if (z->zalloc == Z_NULL)
  {
    z->zalloc = zcalloc;
    z->opaque = (void *)0;
  }
  if (z->zfree == Z_NULL) z->zfree = zcfree;
  if ((z->state = (struct internal_state*)
       ZALLOC(z,1,sizeof(struct internal_state))) == Z_NULL)
    return Z_MEM_ERROR;
  z->state->blocks = Z_NULL;

  /* handle undocumented nowrap option (no zlib header or check) */
  z->state->nowrap = 0;
  if (w < 0)
  {
    w = - w;
    z->state->nowrap = 1;
  }

  /* set window size */
  if (w < 8 || w > 15)
  {
    inflateEnd(z);
    return Z_STREAM_ERROR;
  }
  z->state->wbits = (u32)w;

  /* create inflate_blocks state */
  if ((z->state->blocks =
      inflate_blocks_new(z, z->state->nowrap ? Z_NULL : adler32, (u32)1 << w))
      == Z_NULL)
  {
    inflateEnd(z);
    return Z_MEM_ERROR;
  }

  /* reset state */
  inflateReset(z);
  return Z_OK;
}

s32 inflateInit_(z_stream *z, const char *version, s32 stream_size) {
  return inflateInit2_(z, DEF_WBITS, version, stream_size);
}

// These undefs are purely a result of the wacky include structure I have, they are not present in the zlib source
#undef NEEDBYTE
#undef NEXTBYTE
#define NEEDBYTE {if(z->avail_in==0)return r;r=Z_OK;}
#define NEXTBYTE (z->avail_in--,z->total_in++,*z->next_in++)

s32 inflate(z_stream *z, s32 f) {
  s32 r;
  u32 b;

  if (z == Z_NULL || z->state == Z_NULL || z->next_in == Z_NULL || f < 0)
    return Z_STREAM_ERROR;
  r = Z_BUF_ERROR;
  while (1) switch (z->state->mode)
  {
    case RS_INFLATE_METHOD:
      NEEDBYTE
      if (((z->state->sub.method = NEXTBYTE) & 0xf) != Z_DEFLATED)
      {
        z->state->mode = RS_INFLATE_BAD;
        z->state->sub.marker = 5;       /* can't try inflateSync */
        break;
      }
      if ((z->state->sub.method >> 4) + 8 > z->state->wbits)
      {
        z->state->mode = RS_INFLATE_BAD;
        z->state->sub.marker = 5;       /* can't try inflateSync */
        break;
      }
      z->state->mode = RS_INFLATE_FLAG;
    case RS_INFLATE_FLAG:
      NEEDBYTE
      b = NEXTBYTE;
      if (((z->state->sub.method << 8) + b) % 31)
      {
        z->state->mode = RS_INFLATE_BAD;
        z->state->sub.marker = 5;       /* can't try inflateSync */
        break;
      }
      if (!(b & PRESET_DICT))
      {
        z->state->mode = RS_INFLATE_BLOCKS;
	break;
      }
      z->state->mode = RS_INFLATE_DICT4;
    case RS_INFLATE_DICT4:
      NEEDBYTE
      z->state->sub.check.need = (u32)NEXTBYTE << 24;
      z->state->mode = RS_INFLATE_DICT3;
    case RS_INFLATE_DICT3:
      NEEDBYTE
      z->state->sub.check.need += (u32)NEXTBYTE << 16;
      z->state->mode = RS_INFLATE_DICT2;
    case RS_INFLATE_DICT2:
      NEEDBYTE
      z->state->sub.check.need += (u32)NEXTBYTE << 8;
      z->state->mode = RS_INFLATE_DICT1;
    case RS_INFLATE_DICT1:
      NEEDBYTE
      z->state->sub.check.need += (u32)NEXTBYTE;
      z->adler = z->state->sub.check.need;
      z->state->mode = RS_INFLATE_DICT0;
      return Z_NEED_DICT;
    case RS_INFLATE_DICT0:
      z->state->mode = RS_INFLATE_BAD;
      z->state->sub.marker = 0;       /* can try inflateSync */
      return Z_STREAM_ERROR;
    case RS_INFLATE_BLOCKS:
      r = inflate_blocks(z->state->blocks, z, r);
      if (r == Z_DATA_ERROR)
      {
        z->state->mode = RS_INFLATE_BAD;
        z->state->sub.marker = 0;       /* can try inflateSync */
        break;
      }
      if (r != Z_STREAM_END)
        return r;
      r = Z_OK;
      inflate_blocks_reset(z->state->blocks, z, &z->state->sub.check.was);
      if (z->state->nowrap)
      {
        z->state->mode = RS_INFLATE_DONE;
        break;
      }
      z->state->mode = RS_INFLATE_CHECK4;
    case RS_INFLATE_CHECK4:
      NEEDBYTE
      z->state->sub.check.need = (u32)NEXTBYTE << 24;
      z->state->mode = RS_INFLATE_CHECK3;
    case RS_INFLATE_CHECK3:
      NEEDBYTE
      z->state->sub.check.need += (u32)NEXTBYTE << 16;
      z->state->mode = RS_INFLATE_CHECK2;
    case RS_INFLATE_CHECK2:
      NEEDBYTE
      z->state->sub.check.need += (u32)NEXTBYTE << 8;
      z->state->mode = RS_INFLATE_CHECK1;
    case RS_INFLATE_CHECK1:
      NEEDBYTE
      z->state->sub.check.need += (u32)NEXTBYTE;

      if (z->state->sub.check.was != z->state->sub.check.need)
      {
        z->state->mode = RS_INFLATE_BAD;
        z->state->sub.marker = 5;       /* can't try inflateSync */
        break;
      }
      z->state->mode = RS_INFLATE_DONE;
    case RS_INFLATE_DONE:
      return Z_STREAM_END;
    case RS_INFLATE_BAD:
      return Z_DATA_ERROR;
    default:
      return Z_STREAM_ERROR;
  }
}

s32 inflateSetDictionary(z_stream *z, const u8 *dictionary, u32 dictLength) {
  u32 length = dictLength;

  if (z == Z_NULL || z->state == Z_NULL || z->state->mode != RS_INFLATE_DICT0)
    return Z_STREAM_ERROR;

  if (adler32(1L, dictionary, dictLength) != z->adler) return Z_DATA_ERROR;
  z->adler = 1L;

  if (length >= ((u32)1<<z->state->wbits))
  {
    length = (1<<z->state->wbits)-1;
    dictionary += dictLength - length;
  }
  inflate_set_dictionary(z->state->blocks, dictionary, length);
  z->state->mode = RS_INFLATE_BLOCKS;
  return Z_OK;
}

s32 inflateSync(z_stream *z) {
  u32 n;       /* number of bytes to look at */
  u8 *p;     /* pointer to bytes */
  u32 m;       /* number of marker bytes found in a row */
  u32 r, w;   /* temporaries to save total_in and total_out */

  /* set up */
  if (z == Z_NULL || z->state == Z_NULL)
    return Z_STREAM_ERROR;
  if (z->state->mode != RS_INFLATE_BAD)
  {
    z->state->mode = RS_INFLATE_BAD;
    z->state->sub.marker = 0;
  }
  if ((n = z->avail_in) == 0)
    return Z_BUF_ERROR;
  p = z->next_in;
  m = z->state->sub.marker;

  /* search */
  while (n && m < 4)
  {
    if (*p == (u8)(m < 2 ? 0 : 0xff))
      m++;
    else if (*p)
      m = 0;
    else
      m = 4 - m;
    p++, n--;
  }

  /* restore */
  z->total_in += p - z->next_in;
  z->next_in = p;
  z->avail_in = n;
  z->state->sub.marker = m;

  /* return no joy or set up to restart on a new block */
  if (m != 4)
    return Z_DATA_ERROR;
  r = z->total_in;  w = z->total_out;
  inflateReset(z);
  z->total_in = r;  z->total_out = w;
  z->state->mode = RS_INFLATE_BLOCKS;
  return Z_OK;
}

INCLUDE_RODATA("asm/nonmatchings/zlib/inflate", junk_80000AA8);
