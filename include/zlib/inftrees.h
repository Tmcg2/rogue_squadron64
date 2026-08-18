#ifndef INFTREES_H
#define INFTREES_H

#include "PR/ultratypes.h"
#include "zlib/zlib_types.h"

typedef struct inflate_huft_s inflate_huft;

/* simplify the use of the inflate_huft type with some defines */
#define base more.Base
#define next more.Next
#define exop word.what.Exop
#define bits word.what.Bits

struct inflate_huft_s {
  union {
    struct {
      u8 Exop;        /* number of extra bits or operation */
      u8 Bits;        /* number of bits in this code or subcode */
    } what;
    u8 *pad;         /* pad structure to a power of 2 (4 bytes for */
  } word;               /*  16-bit, 8 bytes for 32-bit machines) */
  union {
    u32 Base;          /* literal, length base, or distance base */
    inflate_huft *Next; /* pointer to next level of table */
  } more;
};

s32 huft_build(u32 *b, u32 n, u32 s, u32 *d, u32 *e, inflate_huft **t, u32 *m, z_stream *zs);
s32 inflate_trees_bits(u32*, u32*, inflate_huft**, z_stream*);
s32 inflate_trees_dynamic(u32, u32, u32*, u32*, u32*, inflate_huft**, inflate_huft**, z_stream*);
s32 inflate_trees_fixed(u32*, u32*, inflate_huft**, inflate_huft**);
s32 inflate_trees_free(inflate_huft*, z_stream*);
void *falloc(void*, u32, u32);

#endif
