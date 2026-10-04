#ifndef MAIN_83A20_H
#define MAIN_83A20_H

#include "PR/ultratypes.h"

void dispatchAudioCommand(u8, u16, u8, u8, u8);
void playSimpleAudioCmd(u8, u16, u8);
void setupAudioFaderRamp(u8, u16, u8);
void setAudioFaderRampLocked(u8, u16, u8);
s32  flagVoiceChainForStop(u32);
void factor5MutexAcquire(void);
void factor5MutexRelease(void);
f32  sqrtf_recomp(f32);

extern u8 gMusyXActiveFlag;

#endif
