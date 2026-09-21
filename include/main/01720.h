#ifndef MAIN_01720_H
#define MAIN_01720_H

#include "PR/ultratypes.h"

struct overlay_dma {
    void *src_addrs[8];      /* 0x00 */
    void *dest_addrs[8];     /* 0x20 */
    u32   dma_size[8];       /* 0x40 */
    u32   transaction_count; /* 0x60 */
    u32   bss_addr;          /* 0x64 */
    u32   bss_size;          /* 0x68 */
}; // size 0x6C

void loadOverlay(s32);
struct game_config *getGameConfig(void);

#endif
