#ifndef CINEMATIC_1381D0_H
#define CINEMATIC_1381D0_H

#include "PR/ultratypes.h"

u8     shouldShowCutsceneForLevelStage(u8, u8);
Vec3f *func_cinematic_overlay_800AEA18(void);
void   func_cinematic_overlay_800AEB30(void);
void   cinematicShutdownAudioAndAssets(void);
s32    bytesDiffer(u8 *arg0, u8 *arg1, u32 arg2);

#endif