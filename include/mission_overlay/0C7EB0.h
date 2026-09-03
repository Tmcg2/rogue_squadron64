#ifndef MISSION_0C70B0_H
#define MISSION_0C70B0_H

#include "PR/ultratypes.h"

#include "levels.h"
#include "crafts.h"

void initializeObjectiveTracking(void);
void func_mission_overlay_800C72E8(void);
void calculateFriendliesSaved(void);
void checkComplexObjectives(void);
s32  dealDamagetoDatItem(u8*, u32);
enum Level getCurrentLevel(void);
enum PlayerCraft getLocalPlayerVehicleId(void);
u32  setObjectiveBoolean(s32, u8);
void setObjectiveBooleans(u8*, s8);
s32  getObjectiveBoolean(s32);
u32  setObjectiveCount(s32, u32);
u32  increaseObjectiveCount(s32, s32);
s32  getObjectiveCount(s32);
u8   getAndSetByteAtLevelStateTable(s32, u8);
void setObjectiveHiddenFlag(s32, s32);
void activateObjectiveCompleteFlag(s32);
f32  getObjectiveTimer(s32);
f32  setObjectiveTimer(s32, f32);
void setHudEnableBit4(void);
void setHudEnableBit8(void);
void setFriendliesSaved(s32);
s16  randMod(s32);
u8   addBooleanCountHandleWrapper(void (*)(), s32, s32, s32, s32);
u8   addTimerHandleWrapper(void (*)(), f32);
void setHudFlagBit40AndStoreArg(u8*);

#endif
