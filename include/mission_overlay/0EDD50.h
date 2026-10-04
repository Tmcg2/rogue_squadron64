#ifndef MISSION_0EDD50_H
#define MISSION_0EDD50_H

#include "PR/ultratypes.h"

s32  initLevelMusicBank(void);
void stopAllMusicWithFade(f32);
void triggerStageAmbientForNamedDatItem(u8*, s32);
s32  stopMusicAndResetAudio(void);
s32  preloadSceneSongsWrapper(void);

#endif
