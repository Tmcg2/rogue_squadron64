#ifndef MISSION_0FAE50_H
#define MISSION_0FAE50_H

#include "PR/ultratypes.h"
#include "crafts.h"

extern u32 D_mission_overlay_8010C9E0;
extern u32 D_mission_overlay_8010CA1C;
extern u32 D_mission_overlay_8010CA20;

void func_mission_overlay_800FA250(void);
void func_mission_overlay_800FA6A4(void);
void choosePlayerCraftAssets(enum PlayerCraft*);
void endMissionCleanup(void);

#endif
