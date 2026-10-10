#ifndef MAIN_463D0_H
#define MAIN_463D0_H

#include "PR/ultratypes.h"

void initGridLayerFromLevelData(struct hmp_context*, s32);
void updateGridLayerScroll(f32);
void populateCraftSelectGrid(s32);
void loadGridCellTilesByDistance(f32);

#endif
