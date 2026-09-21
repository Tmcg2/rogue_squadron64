#ifndef MAIN_02420_H
#define MAIN_02420_H

#include "PR/ultratypes.h"
#include "PR/os.h"

struct D_main_bss_8010FF08_type {
    u32 dataAddress; /* 0x0 */
    u32 dataSize;    /* 0x4 */
}; // size 0x8

struct heapBlockHeader {
    u16 unk00;  /* 0x00 */
    u16 flags;  /* 0x02 */
    u32 size;   /* 0x04 */
    u32 pad[2]; /* 0x08 */
}; // size 0x10;

s32   queueDeferredClearRequest(struct heapBlockHeader*, s32);
void  clearFrameReadyFlag(void);
void  ensureHeapInitialized(void);
u32   getTotalFreeHeapSize(void);
u32   findLargestFreeHeapChunk(void);
void *rs_malloc(u32, u16);
void  rs_free(void*);
void buildHeapFreeList(struct heapBlockHeader**, u32, struct D_main_bss_8010FF08_type*, struct heapBlockHeader*, struct heapBlockHeader*, u8);

#endif
