#ifndef ZUTIL_H
#define ZUTIL_H

#include "PR/ultratypes.h"

typedef u32 (*check_func)(u32 check, u8 *buf, u32 len);

void *zcalloc(void*, u32, u32);
void zcfree(void*, void*);

#define ZALLOC(strm, items, size) \
           (*((strm)->zalloc))((strm)->opaque, (items), (size))
#define ZFREE(strm, addr)  (*((strm)->zfree))((strm)->opaque, (void*)(addr))
#define TRY_FREE(s, p) {if (p) ZFREE(s, p);}

#endif
