#include "common.h"

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/jfif_handling", D_menu_overlay_800A76E0);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/jfif_handling", D_menu_overlay_800A7730);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/jfif_handling", loadJfifAsset);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/jfif_handling", resetJfifDecodeState);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/jfif_handling", freeJfifDecodeState);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/jfif_handling", parseJfifSOIMarker);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/jfif_handling", parseJfifSOF0Marker);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/jfif_handling", parseJfifDQTMarker);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/jfif_handling", parseJfifDHTMarker);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/jfif_handling", paserJfifSOSMarker);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/jfif_handling", rebuildDebrisCellGeometry);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/jfif_handling", emitDebrisCellFaces);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/jfif_handling", computeCellGridIndices);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/jfif_handling", buildDebrisCellBitfield);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/jfif_handling", decodeDeltaCellCounts);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/jfif_handling", allocDebrisCellTable);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/jfif_handling", buildCellSlotTableAndFindFree);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/jfif_handling", findFreeCellBitSlot);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/jfif_handling", allocCellBitGroup);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/jfif_handling", allocCellGeometryBuffer);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/jfif_handling", buildDebrisMeshFromCells);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/jfif_handling", cloneCellBufferWithAlloc);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/jfif_handling", allocZeroedCellRecord);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/jfif_handling", D_menu_overlay_800A78A8);
