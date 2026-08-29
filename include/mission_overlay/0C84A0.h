#ifndef MISSION_0C84A0_H
#define MISSION_0C84A0_H

#include "PR/ultratypes.h"

f32  calculateDatItemDistanceToPlayer(u8*);
f32  func_mission_overlay_800C794C(void);
void func_mission_overlay_800C7978(u8*, f32, s32, f32);
s32  func_mission_overlay_800C7AB0(u8*, u8*);
s32  getDatItemHealth(u8*);
f32  getDatItemHealthPercentage(u8*);
void func_mission_overlay_800C7CEC(f32);
void playObjectiveVoiceLine1(u32);
void playObjectiveVoiceLine2(u32, f32);
void func_mission_overlay_800C7D60(u8*, s32);
void func_mission_overlay_800C7D7C(u8*, s32);
void func_mission_overlay_800C7D98(s32);

#endif
