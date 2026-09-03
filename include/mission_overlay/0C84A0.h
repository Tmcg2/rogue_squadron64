#ifndef MISSION_0C84A0_H
#define MISSION_0C84A0_H

#include "PR/ultratypes.h"

f32  calculateDatItemDistanceToPlayer(u8*);
f32  getScaledPlayerCraftSpeed(void);
void spawnEffectOnNamedDatItem(u8*, f32, s32, f32);
s32  initAnchoredActorTowardNamedDatItem(u8*, u8*);
s32  getDatItemHealth(u8*);
f32  getDatItemHealthPercentage(u8*);
void setLevelObjectTrackingScalar(f32);
void playObjectiveVoiceLine1(u32);
void playObjectiveVoiceLine2(u32, f32);
void delegateToLevelStageTick(u8*, s32);
void triggerNamedAssetCue(u8*, s32);
void triggerSoundCueByType(s32);

#endif
