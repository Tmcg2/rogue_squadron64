#ifndef INFUTIL_H
#define INFUTIL_H

#include "PR/ultratypes.h"
#include "zlib/inftrees.h"
#include "zlib/infcodes.h"

extern u32 inflate_mask[];

struct inflate_blocks_state {

  /* mode */
  enum {
      TYPE,     /* get type bits (3, including end bit) */
      LENS,     /* get lengths for stored */
      STORED,   /* processing stored block */
      TABLE,    /* get table lengths */
      BTREE,    /* get bit lengths tree for a dynamic block */
      DTREE,    /* get length, distance trees for a dynamic block */
      CODES,    /* processing fixed or dynamic block */
      DRY,      /* output remaining window bytes */
      DONE,     /* finished last block, done */
      BAD}      /* got a data error--stuck here */
    mode;               /* current inflate_block mode */

  /* mode dependent information */
  union {
    u32 left;          /* if STORED, bytes left to copy */
    struct {
      u32 table;               /* table lengths (14 bits) */
      u32 index;               /* index into blens (or border) */
      u32 *blens;             /* bit lengths of codes */
      u32 bb;                  /* bit length tree depth */
      inflate_huft *tb;         /* bit length decoding tree */
    } trees;            /* if DTREE, decoding info for trees */
    struct {
      inflate_huft *tl, *td;    /* trees to free */
      inflate_codes_statef 
         *codes;
    } decode;           /* if CODES, current state */
  } sub;                /* submode */
  u32 last;            /* true if this block is the last block */

  /* mode independent information */
  u32 bitk;            /* bits in bit buffer */
  u32 bitb;           /* bit buffer */
  u8 *window;        /* sliding window */
  u8 *end;           /* one byte after sliding window */
  u8 *read;          /* window read pointer */
  u8 *write;         /* window write pointer */
  check_func checkfn;   /* check function */
  u32 check;          /* check on output */

};

#endif
