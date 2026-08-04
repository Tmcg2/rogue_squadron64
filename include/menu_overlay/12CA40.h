#ifndef MENU_12CA40_H
#define MENU_12CA40_H

#include "PR/ultratypes.h"
#include "common_types.h"

s32  getAvailablePlayerCraftFlagsConsiderUnlocks(enum Level);
s32  getAvailablePlayerCraftFlagsIgnoreUnlocks(enum Level);
void unlockLevelsAndCraftsBasedOnMedalsEarned(u8*);
s32  getLevelHardwiredDifficulty(u8);
u8   getSecondaryWeaponForLevelAndCraft(u8, u8, u8);
s32  hasKasanMoorDefected(u8);
u8   getLevelIntroCrawlId(u8);

#endif