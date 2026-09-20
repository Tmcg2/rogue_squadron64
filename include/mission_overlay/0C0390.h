#ifndef MISSION_0C0390_H
#define MISSION_0C0390_H

#include "PR/ultratypes.h"
#include "hud.h"
#include "common_types.h"

void updateHudHealthIndicator(struct func_800C0084_type*, f32);
void setHudSecondaryWeaponInfo(struct func_800C0084_type*);
s32  handleHUD(struct D_80130BB8_type*, s32, UNIDENTIFIED_TYPE*);
void spawnHudNpc(void);
f32  getPlayerHealthPercentage(s32);

#endif
