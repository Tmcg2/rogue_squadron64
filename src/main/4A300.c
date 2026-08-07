#include "common.h"

INCLUDE_ASM("asm/nonmatchings/main/4A300", flushPendingGridCellTiles);

INCLUDE_ASM("asm/nonmatchings/main/4A300", emitGridCellTileStrip);

INCLUDE_ASM("asm/nonmatchings/main/4A300", emitGridCellTileStripAdjacent);

INCLUDE_ASM("asm/nonmatchings/main/4A300", emitGridCellTileStripDiagonal);

INCLUDE_ASM("asm/nonmatchings/main/4A300", transformWorldPosToGridSpace);

INCLUDE_ASM("asm/nonmatchings/main/4A300", mapCellGeometryToGridSpace);

INCLUDE_ASM("asm/nonmatchings/main/4A300", scaleObjectPosToGridUnits);

INCLUDE_ASM("asm/nonmatchings/main/4A300", unpackGridVertexBytes);

INCLUDE_ASM("asm/nonmatchings/main/4A300", buildGridCellMesh);

INCLUDE_ASM("asm/nonmatchings/main/4A300", getGridCellFromWorldPos);

INCLUDE_ASM("asm/nonmatchings/main/4A300", byteAnimatedDebrisNpcHandler);

INCLUDE_ASM("asm/nonmatchings/main/4A300", buildGridCellMeshNoLabel);

INCLUDE_ASM("asm/nonmatchings/main/4A300", fake_func_8004CCF8);
