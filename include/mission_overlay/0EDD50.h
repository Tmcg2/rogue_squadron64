#ifndef MISSION_0EDD50_H
#define MISSION_0EDD50_H

#include "PR/ultratypes.h"

u8   shouldSwitchToPendingSong(void);
void tickSongFadeTimer(f32);
void pushActiveSoundDescriptor(void);
void popActiveSoundDescriptor(void);
void preloadSceneReferencedSongs(void);
void resetMusicSubsystemState(u8);
s32  initLevelMusicBank(void);
void stopAllMusicWithFade(f32);
void triggerStageMusicForNamedDatItem(char*, s32);
void triggerStageAmbientForNamedDatItem(u8*, s32);
s32  stopMusicAndResetAudio(void);
s32  preloadSceneSongsWrapper(void);

#endif
