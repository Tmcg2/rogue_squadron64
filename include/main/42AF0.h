#ifndef MAIN_42AF0_H
#define MAIN_42AF0_H

#include "common_types.h"

#include "PR/ultratypes.h"

struct hmp_related_linked_list {
    u16 prev;  /* 0x0 */
    u16 next;  /* 0x2 */
    u16 unk04; /* 0x4 */
    u16 unk06; /* 0x6 */
    u32 ukn08; /* 0x8 */
}; // size 0xC

void allocAndInitDoublyLinkedNodePool12(s32);
s32  rasterizeEdgeXSpansAscending(Vec3f, Vec3f, s32);
s32  rasterizeEdgeXSpansDescending(Vec3f, Vec3f, s32);
void scanConvertTriangleToSpanTable(Vec3f, Vec3f, Vec3f, f32);
void markLowLodCellsInGrid(f32, f32, f32, f32);
void markHighLodCellsInGrid(f32, f32, f32, f32);
s32  load_level_hmp(s32, char*);
void computeGridTileEdgeAdjacencyMasks(void);
void teardownAnimatedMapGridLayer(void);
void setGridLayerScrollX(f32);
void setGridLayerScrollBounds(f32, f32);

#endif