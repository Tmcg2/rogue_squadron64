#include "common.h"

INCLUDE_ASM("asm/nonmatchings/main/01720", loadOverlay);

INCLUDE_ASM("asm/nonmatchings/main/01720", getGameConfig);

INCLUDE_ASM("asm/nonmatchings/main/01720", isPreNmiPending);

INCLUDE_ASM("asm/nonmatchings/main/01720", returnZeroStub);

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
