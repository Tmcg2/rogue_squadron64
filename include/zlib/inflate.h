#ifndef ZLIB_INFLATE_H
#define ZLIB_INFLATE_H

#include "PR/ultratypes.h"
#include "zlib/zlib.h"

s32 inflateReset(z_stream*);
s32 inflateEnd(z_stream*);
s32 inflateInit2_(z_stream*, s32, const char*, s32;
s32 inflateInit_(z_stream*, const char*, s32);
s32 inflate(z_stream*, s32);
s32 inflateSetDictionary(z_stream*, const u8*, u32);
s32 inflateSync(z_stream*);

#endif
