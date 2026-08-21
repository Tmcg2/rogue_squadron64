#ifndef INFFAST_H
#define INFFAST_H

#include "PR/ultratypes.h"
#include "zlib/zlib.h"
#include "zlib/forward_declares.h"

s32 inflate_fast(u32, u32, inflate_huft*, inflate_huft*, inflate_blocks_statef*, z_stream*);

#endif
