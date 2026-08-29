#include "common.h"

#include "mission_overlay/0C7EB0.h"
#include "mission_overlay/0C84A0.h"
#include "mission_overlay/level_objective_handling/lv_6.h"

// I can't help but wonder if the weird goto in here is a leftover of some function inlining
s32 lv6_checkComplexObjectives(void) {
    if (getObjectiveCount(0x22) == 1) {
        why:
        func_mission_overlay_800C7738();
        playObjectiveVoiceLine1(0x65U);
        return 0;
    }
    if ((getObjectiveCount(0x23) != 1) && (getObjectiveCount(0x24) != 1) && (getObjectiveCount(0x25) != 1) && (getObjectiveCount(0x26) != 1) && (getObjectiveCount(0x27) != 1)) {
        if ((getObjectiveCount(0x62) == 6) && (getObjectiveBoolean(0x62) == 0)) {
            setObjectiveBoolean(0x62, 1U);
            increaseObjectiveCount(0x63, 1);
            playObjectiveVoiceLine2(0x64U, 0.0f);
            activateObjectiveCompleteFlag(1);
        }
        if ((getObjectiveCount(0x32) == 4) && (getObjectiveBoolean(0x63) == 0)) {
            setObjectiveBoolean(0x63, 1U);
            increaseObjectiveCount(0x63, 1);
        }
        if (getObjectiveBoolean(0x28) == 1) {
            activateObjectiveCompleteFlag(2);
        }
        if (getObjectiveBoolean(0x7D) == 1) {
            activateObjectiveCompleteFlag(3);
        }
        if ((getObjectiveCount(0x63) == 2) && (getObjectiveBoolean(0xB) == 0)) {
            setObjectiveBoolean(0xB, 1U);
            func_mission_overlay_800C776C();
        }
        return 0;
    }
    goto why;
}

const u8 lv_6_string[] = {
    "MUSICRNG_LevelSettings"
};

s32 lv6_initializeObjectTracking(void) {
    func_mission_overlay_800C7CEC(15.0f);
    addBooleanCountHandleWrapper(func_mission_overlay_8010444C, 0, 0, 0x14, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_8010447C, 0, 0, 0x15, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_80104498, 0, 0, 0xD, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_801044B4, 0x7F, 1, 0, 0);
    return 0;
}

s32 lv6_8010443C(void) {
    return 0;
}

s32 lv6_calculateFriendliesSaved(void) {
    return 0;
}

void func_mission_overlay_8010444C(void) {
    playObjectiveVoiceLine2(0x63U, 1.0f);
    playObjectiveVoiceLine2(0x101U, 1.6f);
}

void func_mission_overlay_8010447C(void) {
    playObjectiveVoiceLine1(0x150U);
}

void func_mission_overlay_80104498(void) {
    playObjectiveVoiceLine1(0x296U);
}

void func_mission_overlay_801044B4(void) {
    func_mission_overlay_800C7D60(lv_6_string, 0);
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/level_objective_handling/lv_6", fake_func_801044D8);
