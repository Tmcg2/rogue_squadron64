#include "common.h"

#include "level_objectives.h"
#include "mission_state.h"

#include "main/04030.h"
#include "main/6C310.h"
#include "mission_overlay/0C7EB0.h"
#include "mission_overlay/0F3E90.h"
#include "mission_overlay/level_objective_handling/all_levels.h"

struct D_8010A450_type D_mission_overlay_8010A450[0x15] = {
    {lv0_initializeObjectTracking,
    lv0_80101954,
    lv0_calculateFriendliesSaved,
    lv0_checkComplexObjectives,},

    {lv1_initializeObjectTracking,
    lv1_80101BE4,
    lv1_calculateFriendliesSaved,
    lv1_checkComplexObjectives,},

    {lv2_initializeObjectTracking,
    lv2_80102A64,
    lv2_calculateFriendliesSaved,
    lv2_checkComplexObjectives,},

    {lv3_initializeObjectTracking,
    lv3_80103528,
    lv3_calculateFriendliesSaved,
    lv3_checkComplexObjectives,},

    {lv4_initializeObjectTracking,
    lv4_80103CBC,
    lv4_calculateFriendliesSaved,
    lv4_checkComplexObjectives,},

    {lv5_initializeObjectTracking,
    lv5_80104110,
    lv5_calculateFriendliesSaved,
    lv5_checkComplexObjectives,},

    {lv6_initializeObjectTracking,
    lv6_8010443C,
    lv6_calculateFriendliesSaved,
    lv6_checkComplexObjectives,},

    {lv7_initializeObjectTracking,
    lv7_80104A58,
    lv7_calculateFriendliesSaved,
    lv7_checkComplexObjectives,},

    {lv8_initializeObjectTracking,
    lv8_80104E64,
    lv8_calculateFriendliesSaved,
    lv8_checkComplexObjectives,},

    {lv9_initializeObjectTracking,
    lv9_80105B00,
    lv9_calculateFriendliesSaved,
    lv9_checkComplexObjectives,},

    {lva_initializeObjectTracking,
    lva_80106100,
    lva_calculateFriendliesSaved,
    lva_checkComplexObjectives,},

    {lvb_initializeObjectTracking,
    lvb_80106B98,
    lvb_calculateFriendliesSaved,
    lvb_checkComplexObjectives,},

    {lvc_initializeObjectTracking,
    lvc_801071E8,
    lvc_calculateFriendliesSaved,
    lvc_checkComplexObjectives,},

    {lvd_initializeObjectTracking,
    lvd_80107290,
    lvd_calculateFriendliesSaved,
    lvd_checkComplexObjectives,},

    {lve_initializeObjectTracking,
    lve_80107E58,
    lve_calculateFriendliesSaved,
    lve_checkComplexObjectives,},

    {lvf_initializeObjectTracking,
    lvf_80108494,
    lvf_calculateFriendliesSaved,
    lvf_checkComplexObjectives,},

    {lvg_initializeObjectTracking,
    lvg_80108B7C,
    lvg_calculateFriendliesSaved,
    lvg_checkComplexObjectives,},

    {lvh_initializeObjectTracking,
    lvh_80108E68,
    lvh_calculateFriendliesSaved,
    lvh_checkComplexObjectives,},

    {lvi_initializeObjectTracking,
    lvi_801091F8,
    lvi_calculateFriendliesSaved,
    lvi_checkComplexObjectives,},

    {lvj_initializeObjectTracking,
    lvj_80109628,
    lvj_calculateFriendliesSaved,
    lvj_checkComplexObjectives,},

    {lvk_initializeObjectTracking,
    lvk_801095CC,
    lvk_calculateFriendliesSaved,
    lvk_checkComplexObjectives,},
};

void initializeObjectiveTracking(void) {
    D_mission_overlay_8010A450[gCurrentLevel].initializeObjectiveTracking();
}

void func_mission_overlay_800C72E8(void) {
    D_mission_overlay_8010A450[gCurrentLevel].unk4();
}

void calculateFriendliesSaved(void) {
    D_mission_overlay_8010A450[gCurrentLevel].calculateFriendliesSaved();
}

void checkComplexObjectives(void) {
    D_mission_overlay_8010A450[gCurrentLevel].checkComplexObjectives();
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C7EB0", dealDamagetoDatItem);

enum Level getCurrentLevel(void) {
    return gCurrentLevel;
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C7EB0", func_mission_overlay_800C7514);

enum PlayerCraft func_mission_overlay_800C7524(void) {
    return getPlayerVehicleId(0);
}

u32 setObjectiveBoolean(s32 booleanIndex, u8 booleanValue) {
    u32 blah;

    if (booleanIndex != 0) {
        blah = gObjectiveBooleans[booleanIndex - 1];
        gObjectiveBooleans[booleanIndex - 1] = booleanValue;
        return blah;
    } else {
        return 1;
    }
}

void setObjectiveBooleans(u8 *arg0, s8 arg1) {
    u8 *var_a0;
    u8 var_v0;

    while (*arg0 != 0) {
        gObjectiveBooleans[*arg0++ - 1] = arg1;
    }
}

s32 getObjectiveBoolean(s32 booleanIndex) {
    if (booleanIndex != 0) {
        return gObjectiveBooleans[booleanIndex - 1];
    } else {
        return 1U;
    }
}

u32 setObjectiveCount(s32 countIndex, u32 countValue) {
    u32 blah;

    if (countIndex != 0) {
        blah = gObjectiveCounts[countIndex - 1];
        gObjectiveCounts[countIndex - 1] = countValue;
        return blah;
    } else {
        return 0;
    }
}

u32 increaseObjectiveCount(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        gObjectiveCounts[arg0 - 1] += arg1;
        return gObjectiveCounts[arg0 - 1];
    } else {
        return 0;
    }
}

s32 getObjectiveCount(s32 countIndex) {
    if (countIndex != 0) {
        return gObjectiveCounts[countIndex - 1];
    } else {
        return 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C7EB0", func_mission_overlay_800C7648);

void setObjectiveHiddenFlag(s32 arg0, s32 arg1) {
    u32 temp_a1;
    struct MissionState *why;

    temp_a1 = arg1 - 1;
    if (temp_a1 >= 8) return;

    why = &gMissionState;
    if (arg0 != 0) {
        why->hiddenObjectiveFlags |= 1 << temp_a1;
    } else {
        why->hiddenObjectiveFlags &= ~(1 << temp_a1);
    }
}

void activateObjectiveCompleteFlag(s32 arg0) {
    u32 temp_a1;

    temp_a1 = arg0 - 1;
    if (temp_a1 < 8U) {
        gMissionState.completedObjectiveFlags |= 1 << temp_a1;
    }
}

f32 getObjectiveTimer(s32 timerIndex) {
    return gObjectiveTimers[timerIndex];
}

f32 setObjectiveTimer(s32 timerIndex, f32 timerValue) {
    f32 blah;
    blah = gObjectiveTimers[timerIndex];
    gObjectiveTimers[timerIndex] = timerValue;
    return blah;
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C7EB0", func_mission_overlay_800C7718);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C7EB0", func_mission_overlay_800C7728);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C7EB0", func_mission_overlay_800C7738);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C7EB0", func_mission_overlay_800C776C);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C7EB0", func_mission_overlay_800C77A0);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C7EB0", setFriendliesSaved);

s16 func_mission_overlay_800C77D0(s32 arg0) {
    return (rand() % arg0);
}

u8 addBooleanCountHandleWrapper(void (*handle)(), s32 booleanIndex, s32 booleanValue, s32 countIndex, s32 countValue) {
    return addBooleanCountHandle(handle, booleanIndex, booleanValue, countIndex, (u32) countValue, 0U);
}

u8 addTimerHandleWrapper(void (*handle)(), f32 timerValue) {
    return addTimerHandle(handle, timerValue);
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0C7EB0", func_mission_overlay_800C7884);
