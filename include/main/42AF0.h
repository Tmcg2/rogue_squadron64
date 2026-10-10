#ifndef MAIN_42AF0_H
#define MAIN_42AF0_H

#include "PR/ultratypes.h"

s32  load_level_hmp(s32, char*);
void computeGridTileEdgeAdjacencyMasks(void);
void teardownAnimatedMapGridLayer(void);
void setGridLayerScrollX(f32);
void setGridLayerScrollBounds(f32, f32);

#endif