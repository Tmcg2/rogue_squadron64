#include "common.h"

#include "main/47220.h"

INCLUDE_ASM("asm/nonmatchings/main/47220", parseDatItemCommon);

INCLUDE_ASM("asm/nonmatchings/main/47220", loadDatFile);

INCLUDE_ASM("asm/nonmatchings/main/47220", updateActiveGridCellState);

INCLUDE_ASM("asm/nonmatchings/main/47220", parseDatItemSubtypes1To5);

INCLUDE_ASM("asm/nonmatchings/main/47220", freeLevelDatBuffers);

INCLUDE_ASM("asm/nonmatchings/main/47220", getLevelDatItemByName);

INCLUDE_ASM("asm/nonmatchings/main/47220", getDatItemByName);

INCLUDE_ASM("asm/nonmatchings/main/47220", findDatItemInTableByName);

INCLUDE_ASM("asm/nonmatchings/main/47220", isNpcWithinActiveReferenceRange);

s32 isPointXzWithinRangeOfRef(Vec3f arg0, Vec3f arg1) {
    f32 xdist;
    f32 zdist;

    xdist = (arg0[0] - arg1[0]) * 0.25f;
    zdist = (arg0[2] - arg1[2]) * 0.25f;
    if (144.0f < ((xdist * xdist) + (zdist * zdist))) {
        return 0;
    } else {
        return 1;
    }
}

static const u32 rodata_padding = 0x8FA605E8;

INCLUDE_ASM("asm/nonmatchings/main/47220", lookupActivePlayerCraftGridCell);
