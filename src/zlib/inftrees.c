#include "common.h"

#include "zlib/inftrees.h"
#include "zlib/zutil.h"

char huh = '*';

/* Tables for deflate from PKZIP's appnote.txt. */
u32 cplens[31] = { /* Copy lengths for literal codes 257..285 */
        3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17, 19, 23, 27, 31,
        35, 43, 51, 59, 67, 83, 99, 115, 131, 163, 195, 227, 258, 0, 0};
        /* actually lengths - 2; also see note #13 above about 258 */
u32 cplext[31] = { /* Extra bits for literal codes 257..285 */
        0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2,
        3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 0, 192, 192}; /* 192==invalid */
u32 cpdist[30] = { /* Copy offsets for distance codes 0..29 */
        1, 2, 3, 4, 5, 7, 9, 13, 17, 25, 33, 49, 65, 97, 129, 193,
        257, 385, 513, 769, 1025, 1537, 2049, 3073, 4097, 6145,
        8193, 12289, 16385, 24577};
u32 cpdext[30] = { /* Extra bits for distance codes */
        0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6,
        7, 7, 8, 8, 9, 9, 10, 10, 11, 11,
        12, 12, 13, 13};


int fixed_built = 0;
#define FIXEDH 530      /* number of hufts used by fixed tables */
inflate_huft fixed_mem[FIXEDH];
u32 fixed_bl;
u32 fixed_bd;
inflate_huft *fixed_tl;
inflate_huft *fixed_td;

/* simplify the use of the inflate_huft type with some defines */
#define base more.Base
#define next more.Next
#define exop word.what.Exop
#define bits word.what.Bits

/* If BMAX needs to be larger than 16, then h and x[] should be uLong. */
#define BMAX 15         /* maximum bit length of any code */
#define N_MAX 288       /* maximum number of codes in any set */

s32 huft_build(u32 *b, u32 n, u32 s, u32 *d, u32 *e, inflate_huft **t, u32 *m, z_stream *zs) {

  u32 a;                       /* counter for codes of length k */
  u32 c[BMAX+1];               /* bit length count table */
  u32 f;                       /* i repeats in table every f entries */
  s32 g;                        /* maximum code length */
  s32 h;                        /* table level */
  u32 i;              /* counter, current code */
  u32 j;              /* counter */
  s32 k;               /* number of bits in current code */
  s32 l;                        /* bits per table (returned in m) */
  u32 *p;            /* pointer into c[], b[], or v[] */
  inflate_huft *q;              /* points to current table */
  struct inflate_huft_s r;      /* table entry for structure assignment */
  inflate_huft *u[BMAX];        /* table stack */
  u32 v[N_MAX];                /* values in order of bit length */
  s32 w;               /* bits before this table == (l * h) */
  u32 x[BMAX+1];               /* bit offsets, then code stack */
  u32 *xp;                    /* pointer into x */
  s32 y;                        /* number of dummy codes added */
  u32 z;                       /* number of entries in current table */


  /* Generate counts for each bit length */
  p = c;
#define C0 *p++ = 0;
#define C2 C0 C0 C0 C0
#define C4 C2 C2 C2 C2
  C4                            /* clear c[]--assume BMAX+1 is 16 */
  p = b;  i = n;
  do {
    c[*p++]++;                  /* assume all entries <= BMAX */
  } while (--i);
  if (c[0] == n)                /* null input--all zero length codes */
  {
    *t = (inflate_huft *)Z_NULL;
    *m = 0;
    return Z_OK;
  }


  /* Find minimum and maximum length, bound *m by those */
  l = *m;
  for (j = 1; j <= BMAX; j++)
    if (c[j])
      break;
  k = j;                        /* minimum code length */
  if ((u32)l < j)
    l = j;
  for (i = BMAX; i; i--)
    if (c[i])
      break;
  g = i;                        /* maximum code length */
  if ((u32)l > i)
    l = i;
  *m = l;


  /* Adjust last length count to fill out codes, if needed */
  for (y = 1 << j; j < i; j++, y <<= 1)
    if ((y -= c[j]) < 0)
      return Z_DATA_ERROR;
  if ((y -= c[i]) < 0)
    return Z_DATA_ERROR;
  c[i] += y;


  /* Generate starting offsets into the value table for each length */
  x[1] = j = 0;
  p = c + 1;  xp = x + 2;
  while (--i) {                 /* note that i == g from above */
    *xp++ = (j += *p++);
  }


  /* Make a table of values in order of bit lengths */
  p = b;  i = 0;
  do {
    if ((j = *p++) != 0)
      v[x[j]++] = i;
  } while (++i < n);


  /* Generate the Huffman codes and for each, make the table entries */
  x[0] = i = 0;                 /* first Huffman code is zero */
  p = v;                        /* grab values in bit order */
  h = -1;                       /* no tables yet--level -1 */
  w = -l;                       /* bits decoded == (l * h) */
  u[0] = (inflate_huft *)Z_NULL;        /* just to keep compilers happy */
  q = (inflate_huft *)Z_NULL;   /* ditto */
  z = 0;                        /* ditto */

  /* go through the bit lengths (k already is bits in shortest code) */
  for (; k <= g; k++)
  {
    a = c[k];
    while (--a != -1)
    {
      /* here i is the Huffman code of length k bits for value *p */
      /* make tables up to required level */
      while (k > w + l)
      {
        h++;
        w += l;                 /* previous table always l bits */

        /* compute minimum size table less than or equal to l bits */
        z = g - w;
        z = z > (u32)l ? l : z;        /* table size upper limit */
        if ((f = 1 << (j = k - w)) > a + 1)     /* try a k-w bit table */
        {                       /* too few codes for k-w bit table */
          f -= a + 1;           /* deduct codes from patterns left */
          xp = c + k;
          if (j < z)
            while (++j < z)     /* try smaller tables up to z bits */
            {
              if ((f <<= 1) <= *++xp)
                break;          /* enough codes to use up j bits */
              f -= *xp;         /* else deduct codes from patterns */
            }
        }
        z = 1 << j;             /* table entries for j-bit table */

        /* allocate and link in new table */
        if ((q = (inflate_huft *)ZALLOC
             (zs,z + 1,sizeof(inflate_huft))) == Z_NULL)
        {
          if (h)
            inflate_trees_free(u[0], zs);
          return Z_MEM_ERROR;   /* not enough memory */
        }
#ifdef DEBUG
        inflate_hufts += z + 1;
#endif
        *t = q + 1;             /* link to list for huft_free() */
        *(t = &(q->next)) = Z_NULL;
        u[h] = ++q;             /* table starts after link */

        /* connect to last table, if there is one */
        if (h)
        {
          x[h] = i;             /* save pattern for backing up */
          r.bits = (u8)l;     /* bits to dump before this table */
          r.exop = (u8)j;     /* bits in this table */
          r.next = q;           /* pointer to this table */
          j = i >> (w - l);     /* (get around Turbo C bug) */
          u[h-1][j] = r;        /* connect to last table */
        }
      }

      /* set up table entry in r */
      r.bits = (u8)(k - w);
      if (p >= v + n)
        r.exop = 128 + 64;      /* out of values--invalid code */
      else if (*p < s)
      {
        r.exop = (u8)(*p < 256 ? 0 : 32 + 64);     /* 256 is end-of-block */
        r.base = *p++;          /* simple code is just the value */
      }
      else
      {
        r.exop = (u8)(e[*p - s] + 16 + 64);/* non-simple--look up in lists */
        r.base = d[*p++ - s];
      }

      /* fill code-like entries with r */
      f = 1 << (k - w);
      for (j = i >> w; j < z; j += f)
        q[j] = r;

      /* backwards increment the k-bit code i */
      for (j = 1 << (k - 1); i & j; j >>= 1)
        i ^= j;
      i ^= j;

      /* backup over finished tables */
      while ((i & ((1 << w) - 1)) != x[h])
      {
        h--;                    /* don't need to update q */
        w -= l;
      }
    }
  }


  /* Return Z_BUF_ERROR if we were given an incomplete table */
  return y != 0 && g != 1 ? Z_BUF_ERROR : Z_OK;
}

s32 inflate_trees_bits(u32 *c, u32 *bb, inflate_huft **tb, z_stream *z) {
    s32 r;

    r = huft_build(c, 19, 19, (u32*)Z_NULL, (u32*)Z_NULL, tb, bb, z);
    if (r == Z_DATA_ERROR) {
        // z->msg = (char*)"oversubscribed dynamic bit lengths tree";
    } else if (r == Z_BUF_ERROR) {
        inflate_trees_free(*tb, z);
        // z->msg = (char*)"incomplete dynamic bit lengths tree";
        r = Z_DATA_ERROR;
    }
    return r;
}

s32 inflate_trees_dynamic(u32 nl, u32 nd, u32 *c, u32 *bl, u32 *bd, inflate_huft **tl, inflate_huft **td, z_stream *z) {
    s32 r;

    /* build literal/length tree */
    if ((r = huft_build(c, nl, 257, cplens, cplext, tl, bl, z)) != Z_OK) {
        if (r == Z_DATA_ERROR) {
            // z->msg = (char*)"oversubscribed literal/length tree";
        } else if (r == Z_BUF_ERROR) {
            inflate_trees_free(*tl, z);
            // z->msg = (char*)"incomplete literal/length tree";
            r = Z_DATA_ERROR;
        }
        return r;
    }

    /* build distance tree */
    if ((r = huft_build(c + nl, nd, 0, cpdist, cpdext, td, bd, z)) != Z_OK) {
        if (r == Z_DATA_ERROR) {
            // z->msg = (char*)"oversubscribed literal/length tree";
        } else if (r == Z_BUF_ERROR) {
            inflate_trees_free(*td, z);
            // z->msg = (char*)"incomplete literal/length tree";
            r = Z_DATA_ERROR;
        }
        inflate_trees_free(*tl, z);
        return r;
    }

    /* done */
    return Z_OK;
}

s32 inflate_trees_fixed(u32 *bl, u32 *bd, inflate_huft **tl, inflate_huft **td) {
  /* build fixed tables if not already (multiple overlapped executions ok) */
    if (!fixed_built) {
        s32 k;              /* temporary variable */
        u32 c[288];    /* length list for huft_build */
        z_stream z;         /* for falloc function */
        s32 f = FIXEDH;     /* number of hufts left in fixed_mem */

        /* set up fake z_stream for memory routines */
        z.zalloc = falloc;
        z.zfree = Z_NULL;
        z.opaque = (void *)&f;

        /* literal table */
        for (k = 0; k < 144; k++)
        c[k] = 8;
        for (; k < 256; k++)
        c[k] = 9;
        for (; k < 280; k++)
        c[k] = 7;
        for (; k < 288; k++)
        c[k] = 8;
        fixed_bl = 7;
        huft_build(c, 288, 257, cplens, cplext, &fixed_tl, &fixed_bl, &z);

        /* distance table */
        for (k = 0; k < 30; k++)
        c[k] = 5;
        fixed_bd = 5;
        huft_build(c, 30, 0, cpdist, cpdext, &fixed_td, &fixed_bd, &z);

        /* done */
        fixed_built = 1;
    }
    *bl = fixed_bl;
    *bd = fixed_bd;
    *tl = fixed_tl;
    *td = fixed_td;
    return Z_OK;
}

s32 inflate_trees_free(inflate_huft *t, z_stream *z) {
    inflate_huft *p, *q, *r;

    /* Reverse linked list */
    p = Z_NULL;
    q = t;
    while (q != Z_NULL) {
        r = (q - 1)->next;
        (q - 1)->next = p;
        p = q;
        q = r;
    }
    /* Go through linked list, freeing from the malloced (t[-1]) address. */
    while (p != Z_NULL) {
        q = (--p)->next;
        ZFREE(z,p);
        p = q;
    } 
    return Z_OK;
}

void *falloc(void *arg0, u32 arg1, u32 arg2) {
    s32 temp_v0;

    *(s32*)arg0 -= arg1 + arg2 - arg2;
    return fixed_mem + *(s32*)arg0;
}

INCLUDE_ASM("asm/nonmatchings/zlib/inftrees", fake_func_80029B14);
