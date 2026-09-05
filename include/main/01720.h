#ifndef MAIN_01720_H
#define MAIN_01720_H

#include "PR/ultratypes.h"

struct overlay_dma {
    /* 0x00 */ void *src_addrs[8];
    /* 0x20 */ void *dest_addrs[8];
    /* 0x40 */ u32 dma_size[8];
    /* 0x60 */ u32 transaction_count;
    /* 0x64 */ u32 bss_addr;
    /* 0x68 */ u32 bss_size;
}; // size = 0x6C

void loadOverlay(s32);
s32  returnZeroStub(void);

#endif
