#ifndef MAIN_8F970_H
#define MAIN_8F970_H

#include "PR/ultratypes.h"

void waitForMusyXAudioTaskDone(void);
void factor5MutexAcquire(void);
void factor5MutexRelease(void);
void shutdownAudioEngine(void);
void stopVoiceMarkRetrigger(s32);
u8   isAudioSlotActive(s32);
s32  audioStubReturnZero();
void tickAudioBufferUpdate(void);
void freeAudioScratchBuffer(void);
f32  sqrtf_recomp(f32);

#endif
