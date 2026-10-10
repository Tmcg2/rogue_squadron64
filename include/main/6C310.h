#ifndef MAIN_6C310_H
#define MAIN_6C310_H

#include "PR/ultratypes.h"
#include "common_types.h"
#include "crafts.h"

void clearTrackedNpcSlots(void);
u32  load_naboo_starfighter(u32);
f32 *getCraftRecordByIdx(s32);
enum PlayerCraft getPlayerVehicleId(s32);
u16  getPlayerField2(s32 arg0);

extern u16 D_main_bss_8013A528[14];

#endif
