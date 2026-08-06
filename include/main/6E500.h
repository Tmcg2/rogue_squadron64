#ifndef MAIN_66FB0_H
#define MAIN_66FB0_H

#include "PR/ultratypes.h"
#include "common_types.h"

void loadDefaultHighScores(void);
void highScoreBubbleSort(u8);
s32  getActiveAccountsBitmask(void);
s32  getAccountUnk51(void);
void initializeNumLives(void);
struct EliteRogueData *getSaveScratchBufferPtr(void);
u8   findUnusedAccountId(void);
void resetMixerVolumesAndFlags(void);
s32  isUnlockBitSet(u8);
void gatherActiveUnlockFlags(void);
void syncMissionUnlockBitsToSettings(void);
void unlockMissleUpgradeOnLevelCompletion(u8);
struct account_data *getAccountDataPtr(u8);
void copyAccountRecordAndMarkActive(struct account_data*, u8);
void clearAccountRecordAndMarkInactive(u8);
void cycleIdleDemoId(void);
s32  classifySaveStateFromInput(s32);
void persistSaveDataBody(void);
s32  isSaveStateNotPending(void);
void setAccountHighscore(u8, u16, u8);
s32  getAccountHighscore(u8);
s32  getSecondaryWeaponCount(u8, u8);

extern char *defaultHighscoreNames[0xA];

#endif
