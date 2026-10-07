#include "common.h"

#include "PR/os.h"
#include "main/1A410.h"

INCLUDE_ASM("asm/nonmatchings/main/1A410", awaitFrameSyncMesgBlock);

INCLUDE_ASM("asm/nonmatchings/main/1A410", signalFrameSyncMesgNonblock);

INCLUDE_ASM("asm/nonmatchings/main/1A410", viRetraceHandlerThread);

void yieldCurrentThread(void) {
    osYieldThread();
}

INCLUDE_ASM("asm/nonmatchings/main/1A410", getInactiveBufferIndex);

INCLUDE_ASM("asm/nonmatchings/main/1A410", spTaskSchedulerThread);

void yieldFromSpThread(void) {
    osYieldThread();
}

void yieldFromGfxFrame(void) {
    osYieldThread();
}

INCLUDE_ASM("asm/nonmatchings/main/1A410", postViThreadCommand);

INCLUDE_ASM("asm/nonmatchings/main/1A410", initVideoSubsystem);

INCLUDE_ASM("asm/nonmatchings/main/1A410", requestViFeatureChange);

INCLUDE_ASM("asm/nonmatchings/main/1A410", beginSceneRenderFrame);

INCLUDE_ASM("asm/nonmatchings/main/1A410", clearPendingViChanges);

INCLUDE_ASM("asm/nonmatchings/main/1A410", applyPendingViChanges);

INCLUDE_ASM("asm/nonmatchings/main/1A410", swapBufferWithViMode);

INCLUDE_ASM("asm/nonmatchings/main/1A410", selectAndApplyViMode);

INCLUDE_ASM("asm/nonmatchings/main/1A410", computeFramebufferByteSize);

INCLUDE_ASM("asm/nonmatchings/main/1A410", readBufferSwapState);

INCLUDE_ASM("asm/nonmatchings/main/1A410", bufferArbiterProducerMark);

INCLUDE_ASM("asm/nonmatchings/main/1A410", waitOnVideoQueue);

INCLUDE_ASM("asm/nonmatchings/main/1A410", bufferArbiterMarkSlotReady);

INCLUDE_ASM("asm/nonmatchings/main/1A410", bufferArbiterAllocSlot);

INCLUDE_ASM("asm/nonmatchings/main/1A410", acquireFreeBufferSlot);

INCLUDE_ASM("asm/nonmatchings/main/1A410", postSwapRdpReset);

INCLUDE_ASM("asm/nonmatchings/main/1A410", setPostSwapPendingFlags);

INCLUDE_ASM("asm/nonmatchings/main/1A410", waitForPostSwapAck);

INCLUDE_ASM("asm/nonmatchings/main/1A410", clearPostSwapPendingFlags);

INCLUDE_ASM("asm/nonmatchings/main/1A410", setGfxTaskYieldParams);

INCLUDE_ASM("asm/nonmatchings/main/1A410", dpInterruptHandlerThread);

INCLUDE_ASM("asm/nonmatchings/main/1A410", fake_func_8001C3FC);
