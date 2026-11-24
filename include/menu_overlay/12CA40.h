#ifndef MENU_12CA40_H
#define MENU_12CA40_H

#include "PR/ultratypes.h"
#include "game_settings.h"
#include "levels.h"

void menuOverlayInit(struct GameSettings*, u8, u8);
s32  drawRadarIcon(struct GameSettings*, s32);
s32  getAvailablePlayerCraftFlagsConsiderUnlocks(enum Level);
s32  getAvailablePlayerCraftFlagsIgnoreUnlocks(enum Level);
void unlockLevelsAndCraftsBasedOnMedalsEarned(u8*);
f32  advanceWrappingPhaseAccumulator(void);
s32  getLevelHardwiredDifficulty(u8);
u8   getSecondaryWeaponForLevelAndCraft(u8, u8, u8);
s32  hasKasanMoorDefected(u8);
u8   runHangarMenuFromOverlay(struct GameSettings*, u8, s32);
u8   getLevelIntroCrawlId(u8);

#endif