#include "common.h"
#include "common_types.h"

#include "menu_overlay/linker_variables.h"
#include "mission_overlay/linker_variables.h"
#include "cinematic_overlay/linker_variables.h"
#include "main/01720.h"
#include "main/03F80.h"

/* Data Variables, uncomment when Data matching is possible
s32 gCurrentLoadedOverlay = -1;
*/

// Interim `extern` definitions for Data variables. Remove these when Data matching is possible.

extern s32 gCurrentLoadedOverlay;

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

INCLUDE_ASM("asm/nonmatchings/main/01720", getGameConfig);

INCLUDE_ASM("asm/nonmatchings/main/01720", isPreNmiPending);

s32 returnZeroStub(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/main/01720", mainBootstrapWorker);

INCLUDE_ASM("asm/nonmatchings/main/01720", partitionFramebufferMemory);

INCLUDE_ASM("asm/nonmatchings/main/01720", thread3_video_handle);

INCLUDE_ASM("asm/nonmatchings/main/01720", runVideoFrameTick);

INCLUDE_ASM("asm/nonmatchings/main/01720", main);

INCLUDE_ASM("asm/nonmatchings/main/01720", preNmiResetThread);

INCLUDE_ASM("asm/nonmatchings/main/01720", idle_thread_handle);

INCLUDE_ASM("asm/nonmatchings/main/01720", queueDeferredClearRequest);

INCLUDE_ASM("asm/nonmatchings/main/01720", clearFrameReadyFlag);

INCLUDE_ASM("asm/nonmatchings/main/01720", ensureHeapInitialized);

INCLUDE_ASM("asm/nonmatchings/main/01720", getTotalFreeHeapSize);

INCLUDE_ASM("asm/nonmatchings/main/01720", findLargestFreeHeapChunk);

INCLUDE_ASM("asm/nonmatchings/main/01720", rs_malloc);

INCLUDE_ASM("asm/nonmatchings/main/01720", rs_free);

INCLUDE_ASM("asm/nonmatchings/main/01720", buildHeapFreeList);

INCLUDE_ASM("asm/nonmatchings/main/01720", initMainHeap);

INCLUDE_ASM("asm/nonmatchings/main/01720", coalesceFreeHeapBlocks);

INCLUDE_ASM("asm/nonmatchings/main/01720", getResetVectorRegion);

INCLUDE_ASM("asm/nonmatchings/main/01720", fatalErrorHalt);

INCLUDE_ASM("asm/nonmatchings/main/01720", getUsableRdramSize);

INCLUDE_ASM("asm/nonmatchings/main/01720", computeElapsedMillis);
