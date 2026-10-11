#ifndef MAIN_84830_H
#define MAIN_84830_H

#include "PR/ultratypes.h"

void audioSeqMallocZero(void*);
u16  inlinedRand(void);
s16  lookupSineFromAngleTable(s32);
void tickMusyXIfActive(void);
void stopAllSynthVoices(u8);
void dispatchAudioCommand(u8, u16, u8, u8, u8);
void playSimpleAudioCmd(u8, u16, u8);
void applyMusicOrSfxVolume(u8, u16, u8, u8);
u32  isAudioFaderRampActive(u8);
void setupAudioFaderRamp(u8, u16, u8);
void setAudioFaderRampLocked(u8, u16, u8);
void setAudioFaderState(u8, u8);
void resetMusyXEngineState(s32);
void runMusyXTaskLocked(void);
s32  resolveVoiceSlotByHandle(s32);
s32  setVoiceParamByHandle(s32, u8);
s32  setVoiceParamByHandleLocked(s32, u8);
s32  applyVoiceCmdByHandle(s32, u8);
s32  applyVoiceCmdByHandleLocked(s32, u8);
s32  spreadVoicePanVolumeAcrossChain(u32, u16);
s32  safeLookup3DSoundEntry(s32, u16);
s32  flagVoiceChainForStop(u32);
s32  stopVoiceByHandleLocked(u32);
void shutdownMusyXEngine(void);
u8   isMusyXActive(void);

extern u8  gMusyXActiveFlag;
extern u32 D_main_800A0F54;
extern u16 D_main_800A0F58[];

#endif
