#ifndef MISSION_0BF800_H
#define MISSION_0BF800_H

#include "demo.h"

#include "PR/ultratypes.h"

void func_mission_overlay_800BEC00(void);
void applyDemoRecordedHudEvents(s32, struct demoInput*);
void clearPlayerSlotHudTracking(s32);
void initAllPlayersHudTracking(void);
void tickPlayerHudIndicators(f32);
void loadPlayerSlotHudPreset(s32, s32);
s32  countTrailingZeros16(u16);
void func_mission_overlay_800BF358(void);
void func_mission_overlay_800BF3A4(void);
void func_mission_overlay_800BF408(s32);
f32  getDemoRecordedTimestep(f32);

#endif
