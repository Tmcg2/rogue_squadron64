#ifndef INFBLOCK_H
#define INFBLOCK_H

#include "PR/ultratypes.h"
#include "zlib/zlib.h"
#include "zlib/forward_declares.h"

void inflate_blocks_reset(inflate_blocks_statef*, z_stream*, u32*);
inflate_blocks_statef *inflate_blocks_new(z_stream*, check_func, u32);
s32  inflate_blocks(inflate_blocks_statef*, z_stream*, s32);
s32  inflate_blocks_free(inflate_blocks_statef*, z_stream*, u32*);
void inflate_set_dictionary(inflate_blocks_statef*, const u8*, u32);

#endif
