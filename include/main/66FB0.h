#ifndef MAIN_66FB0_H
#define MAIN_66FB0_H

#include "PR/os.h"
#include "PR/ultratypes.h"

void loadSndFiles(void);
void initAudioListenerFromCamera(void);
s32  loadSongAssetByName(OSId, s32);
void teardownAudioListenerNode(void);
void waitForAnyAudioSlot(void);
s32  parseLoadedSndSection(u16);
void freeAudioCacheEntry(s32);

#endif
