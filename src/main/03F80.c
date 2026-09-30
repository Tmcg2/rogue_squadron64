#include "common.h"

#include "main/03F80.h"
#include "main/04080.h"

u32 D_main_80037630 = 0;

void setVideoReadyFlag(void) {
    D_main_80037630 = 1;
}

s32 clearDmaReadyFlag(void) {
    D_main_80037630 = 0;
    return 1;
}

s32 processOverlayDmaStruct(struct overlay_dma *arg0) {
    s32 var_s1;

    for (var_s1 = 0; var_s1 < arg0->transaction_count; var_s1++) {
        synchronousDmaTransfer(arg0->src_addrs[var_s1], arg0->dest_addrs[var_s1], arg0->dma_size[var_s1]);
    }
    if (arg0->bss_addr != 0) {
        rs_memset(arg0->bss_addr, 0U, arg0->bss_size);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/main/03F80", fake_func_80003424);

// DO NOT DELETE ME I AM REQUIRED FOR MATCHING
u32 data_pad_03F80[] = {
    0x48861800,
    0x48821900,
    0x2545FFFF,
};
