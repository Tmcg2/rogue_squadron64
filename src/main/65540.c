#include "common.h"

#include "level_objectives.h"

#include "main/65540.h"

INCLUDE_RODATA("asm/nonmatchings/main/65540", D_main_8003B830);

INCLUDE_ASM("asm/nonmatchings/main/65540", load_dat_file_assets);

INCLUDE_ASM("asm/nonmatchings/main/65540", setupNpcUpdateFunctions);

INCLUDE_ASM("asm/nonmatchings/main/65540", spawnDatStructureNpcByType);

INCLUDE_ASM("asm/nonmatchings/main/65540", parseDatSpawnPositions);

INCLUDE_ASM("asm/nonmatchings/main/65540", isDatItemConditionMet);

s32 missionCleanupNoopHook(void) {
    return 1;
}

void datItemSetObjectiveBooleanCount(s32 booleanIndex, s32 booleanValue, s32 count1Index, s32 count1Value, s32 count2Index, s32 count2Value) {
    if (booleanIndex != 0) {
        gObjectiveBooleans[booleanIndex - 1] = booleanValue;
    }
    if (count1Index != 0) {
        gObjectiveCounts[count1Index - 1] += count1Value;
    }
    if (count2Index != 0) {
        gObjectiveCounts[count2Index - 1] += count2Value;
    }
}

INCLUDE_ASM("asm/nonmatchings/main/65540", applyDatObjectiveTriggerEffect);

INCLUDE_ASM("asm/nonmatchings/main/65540", fake_func_80065A5C);

INCLUDE_RODATA("asm/nonmatchings/main/65540", D_main_8003C25C);
