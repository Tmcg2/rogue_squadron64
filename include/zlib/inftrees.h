#ifndef INFTREES_H
#define INFTREES_H

#include "PR/ultratypes.h"
#include "zlib/zlib.h"
#include "zlib/forward_declares.h"

s32 huft_build(u32*, u32, u32, u32*, u32*, inflate_huft**, u32*, z_stream*);
s32 inflate_trees_bits(u32*, u32*, inflate_huft**, z_stream*);
s32 inflate_trees_dynamic(u32, u32, u32*, u32*, u32*, inflate_huft**, inflate_huft**, z_stream*);
s32 inflate_trees_fixed(u32*, u32*, inflate_huft**, inflate_huft**);
s32 inflate_trees_free(inflate_huft*, z_stream*);
void *falloc(void*, u32, u32);

#endif
