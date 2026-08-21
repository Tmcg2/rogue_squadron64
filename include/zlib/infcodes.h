#ifndef INFCODES_H
#define INFCODES_H

#include "PR/ultratypes.h"
#include "zlib/zlib.h"
#include "zlib/forward_declares.h"

inflate_codes_statef *inflate_codes_new(u32, u32, inflate_huft*, inflate_huft*, z_stream*);
s32 inflate_codes(inflate_blocks_statef*, z_stream*, s32);
void inflate_codes_free(inflate_codes_statef*, z_stream*);

#endif
