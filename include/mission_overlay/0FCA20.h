#ifndef MISSION_0FCA20_H
#define MISSION_0FCA20_H

#include "PR/ultratypes.h"
#include "common_types.h"

u8   configurePlayerSecondaryWeaponHud(u8, u8, u8, u8);
void teardownHudInstancesAndUnbindNpcs(void);
u8   refreshPlayerSecondaryWeaponHud(u8);
void resetTransientPlayerStateFlags(void);
void resetSecondaryWeaponCount(void);
s32  func_mission_overlay_800FEECC(void);
u8   getHudSecondaryWeponCount(void);

#endif