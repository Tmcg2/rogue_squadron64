#ifndef MISSION_0C4DB0_H
#define MISSION_0C4DB0_H

#include "PR/ultratypes.h"

#include "radar.h"

void plotRadarBlipColumn(struct Radar*, s32);
void plotRadarBlipRow(struct Radar*, s32);
void resetCraftSelectionCounter(void);
void getAvailableShipsForLevel(void);
void accumulateClampedFloatField(struct Radar*, f32);
u8   getDisplayItemStateByte(struct Radar*);

#endif
