#ifndef INFCODES_H
#define INFCODES_H

#include "zlib/inftrees.h"

/* simplify the use of the inflate_huft type with some defines */
#define base more.Base
#define next more.Next
#define exop word.what.Exop
#define bits word.what.Bits

/* inflate codes private state */
struct inflate_codes_state {

  /* mode */
  enum {        /* waiting for "i:"=input, "o:"=output, "x:"=nothing */
      START,    /* x: set up for LEN */
      LEN,      /* i: get length/literal/eob next */
      LENEXT,   /* i: getting length extra (have base) */
      DIST,     /* i: get distance next */
      DISTEXT,  /* i: getting distance extra */
      COPY,     /* o: copying bytes in window, waiting for space */
      LIT,      /* o: got literal, waiting for output space */
      WASH,     /* o: got eob, possibly still output waiting */
      END,      /* x: got eob and all data flushed */
      BADCODE}  /* x: got error */
    mode;               /* current inflate_codes mode */

  /* mode dependent information */
  u32 len;
  union {
    struct {
      inflate_huft *tree;       /* pointer into tree */
      u32 need;                /* bits needed */
    } code;             /* if LEN or DIST, where in tree */
    u32 lit;           /* if LIT, literal */
    struct {
      u32 get;                 /* bits to get for extra */
      u32 dist;                /* distance back to copy from */
    } copy;             /* if EXT or COPY, where and how much */
  } sub;                /* submode */

  /* mode independent information */
  u8 lbits;           /* ltree bits decoded per branch */
  u8 dbits;           /* dtree bits decoder per branch */
  inflate_huft *ltree;          /* literal/length/eob tree */
  inflate_huft *dtree;          /* distance tree */

};

typedef struct inflate_codes_state inflate_codes_statef;

#endif
