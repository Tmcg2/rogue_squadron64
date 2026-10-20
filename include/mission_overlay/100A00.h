#ifndef MISSION_100A00_H
#define MISSION_100A00_H

#include "PR/ultratypes.h"

void despawnCraftAnimationSlotNpcs(u8);
void despawnCraftAnimationSlotNpcsAndMarkStopping(u8);
void tickCraftAnimationSlot(u8, f32);
void freePlayerAuxBuffersIfActive(u8);
void resetCraftAnimationStateForSlot(u8);

#endif
