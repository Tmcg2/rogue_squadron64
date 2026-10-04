#ifndef MISSION_0BF800_H
#define MISSION_0BF800_H

#include "PR/ultratypes.h"
#include "PR/os.h"

#include "controller_settings.h"
#include "demo.h"

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

extern struct demoInput *demoInputs;
extern u32 D_mission_overlay_8010BCA4;
extern u32 D_mission_overlay_8010BCA8;
extern u8  D_mission_overlay_8010BCAC;
extern u8  D_mission_overlay_8010BCB0[0x128]; // why is it so big???
extern f32 D_mission_overlay_8010BDD8[4][2];
extern f32 D_mission_overlay_8010BDF8[4][2];
extern union ControllerSettings D_mission_overlay_8010BE18[4];
extern f32 D_mission_overlay_8010BEA8[4][0x10];
extern u16 D_mission_overlay_8010BFA8[4];
extern OSContPad D_mission_overlay_8010BFB0[4];

#endif
