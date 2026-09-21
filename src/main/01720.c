#include "common.h"

#include "game_config.h"
#include "menu_overlay/linker_variables.h"
#include "mission_overlay/linker_variables.h"
#include "cinematic_overlay/linker_variables.h"
#include "main/01720.h"
#include "main/03F80.h"
#include "main/3EBA0.h"

struct game_config gBootConfig = {
    0x00000000,
    mainGameLoop,
    0x00000000,
    0x00000000,
    {
        0x0000,
        0x0140,
        0x00E0,
        0x0010,
        0x0200,
        0x0000,
    },
    {
        0x00005622,
        0x14,
        0x10,
        0x0700,
        0x00000000,
        0x00000000,
    },
    {
        0x00000400,
        0x00057800,
        0x00010000,
        0x0007D000,
        0x0400,
        0x0200,
        0x0008,
        0x0008,
        0x00001800,
    },
    0x00000000,
    0x00000000,
};

s32 gCurrentLoadedOverlay = -1;

void loadOverlay(s32 arg0) {
    struct overlay_dma local0;

    if (arg0 == gCurrentLoadedOverlay) return;

    switch (arg0) {
    case 0:
        local0.src_addrs[0]  = mission_overlay_BASEROM_START;
        local0.dest_addrs[0] = mission_overlay_VRAM;
        local0.dma_size[0]   = (u32)mission_overlay_ROM_SIZE;
        local0.transaction_count = 1;
        local0.bss_addr = (u32)mission_overlay_BSS_START;
        local0.bss_size = (u32)mission_overlay_BSS_SIZE;
        break;
    case 1:
        local0.src_addrs[0]  = menu_overlay_BASEROM_START;
        local0.dest_addrs[0] = menu_overlay_VRAM;
        local0.dma_size[0]   = (u32)menu_overlay_ROM_SIZE;
        local0.transaction_count = 1;
        local0.bss_addr = (u32)menu_overlay_BSS_START;
        local0.bss_size = (u32)menu_overlay_BSS_SIZE;
        break;
    case 2:
        local0.src_addrs[0]  = cinematic_overlay_BASEROM_START;
        local0.dest_addrs[0] = cinematic_overlay_VRAM;
        local0.dma_size[0]   = (u32)cinematic_overlay_ROM_SIZE;
        local0.transaction_count = 1;
        local0.bss_addr = (u32)cinematic_overlay_BSS_START;
        local0.bss_size = (u32)cinematic_overlay_BSS_SIZE;
        break;
    default:
        break;
    }
    processOverlayDmaStruct(&local0);
    gCurrentLoadedOverlay = arg0;
}

struct game_config *getGameConfig(void) {
    return &gBootConfig;
}

// DO NOT DELTE ME I AM REQUIRED FOR MATCHING
u32 data_pad_01720[] = {
    0x2542FFFF,
    0x48821800,
    0x488A1900,
};
