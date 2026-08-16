#include "common.h"

INCLUDE_ASM("asm/nonmatchings/main/48A50", allocAndInitGridCellArray);

INCLUDE_ASM("asm/nonmatchings/main/48A50", loadLevelTextureCache);

INCLUDE_ASM("asm/nonmatchings/main/48A50", buildGridCellAdjacencyTable);

INCLUDE_ASM("asm/nonmatchings/main/48A50", getGridCellValueAt);

INCLUDE_ASM("asm/nonmatchings/main/48A50", clampGridCellLookup);

INCLUDE_ASM("asm/nonmatchings/main/48A50", processGridCellByDistance);

INCLUDE_ASM("asm/nonmatchings/main/48A50", recycleGridCellToFreeList);

INCLUDE_ASM("asm/nonmatchings/main/48A50", freeGridCellBuffers);

INCLUDE_ASM("asm/nonmatchings/main/48A50", teardownGridLayerWorker);

INCLUDE_ASM("asm/nonmatchings/main/48A50", hudDisplayUpdateWorker);

INCLUDE_ASM("asm/nonmatchings/main/48A50", fake_func_800496F4);

INCLUDE_RODATA("asm/nonmatchings/main/48A50", D_main_8003A810);
