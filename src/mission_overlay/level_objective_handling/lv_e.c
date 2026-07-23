#include "common.h"

INCLUDE_ASM("asm/nonmatchings/mission_overlay/level_objective_handling/lv_e", lve_initializeObjectTracking);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/level_objective_handling/lv_e", lve_checkComplexObjectives);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/level_objective_handling/lv_e", lve_80107E58);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/level_objective_handling/lv_e", lve_calculateFriendliesSaved);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/level_objective_handling/lv_e", fake_func_80107EA4);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/level_objective_handling/lv_e", D_mission_overlay_800A99E4);
