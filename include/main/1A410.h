#ifndef MAIN_1A410_H
#define MAIN_1A410_H

#include "common_types.h"

void awaitFrameSyncMesgBlock(void);
void signalFrameSyncMesgNonblock(void);
void viRetraceHandlerThread(void);
void yieldCurrentThread(void);
s32  getInactiveBufferIndex(void);
void spTaskSchedulerThread(void);
void yieldFromSpThread(void);
void yieldFromGfxFrame(void);
s32  requestViFeatureChange(s32);
s32  beginSceneRenderFrame(s32);
void clearPendingViChanges(void);
void applyPendingViChanges(void);
void swapBufferWithViMode(void);
s32  computeFramebufferByteSize(void);
void readBufferSwapState(s32*, s32*, s32*);
void bufferArbiterProducerMark(void);
void waitOnVideoQueue(void);
void bufferArbiterMarkSlotReady(void);
s32  bufferArbiterAllocSlot(u8);
s32  acquireFreeBufferSlot(void);
void postSwapRdpReset(void);
void setPostSwapPendingFlags(void);
void waitForPostSwapAck(void);
void clearPostSwapPendingFlags(void);
void dpInterruptHandlerThread(void);

#endif
