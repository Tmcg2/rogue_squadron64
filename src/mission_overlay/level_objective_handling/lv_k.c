#include "common.h"

#include "mission_overlay/0C7EB0.h"
#include "mission_overlay/0C84A0.h"
#include "mission_overlay/level_objective_handling/lv_k.h"

s32 D_mission_overlay_8010D1F0;

const u8 lv_k_musicrng_levelsettings[32] = {
    "MUSICRNG_LevelSettings\x00\x00\x8F\xC2\x00\x24\x94\x43\x00\x00"
};

s32 lvk_checkComplexObjectives(void) {
    s32 temp_v0;

    if (D_mission_overlay_8010D1F0 == 0) {
        if ((getObjectiveCount(1) == 0x25) && (getObjectiveCount(2) == 0xF)) {
            D_mission_overlay_8010D1F0 = 1;
            func_mission_overlay_800C7D60(lv_k_musicrng_levelsettings, 0);
            func_mission_overlay_800C7D98(0);
            addTimerHandleWrapper(func_mission_overlay_80109558, 5.5f);
        } else if (getObjectiveCount(1) == 0x25) {
            temp_v0 = getObjectiveBoolean(4);
            if (temp_v0 == 1) {
                D_mission_overlay_8010D1F0 = temp_v0;
                func_mission_overlay_800C7D60(lv_k_musicrng_levelsettings, 0);
                func_mission_overlay_800C7D98(1);
                addTimerHandleWrapper(func_mission_overlay_80109574, 4.5f);
            }
        }
        if ((getObjectiveBoolean(3) == 0) && (getObjectiveCount(3) > 0)) {
            if (getObjectiveCount(3) == (0xF - getObjectiveCount(2))) {
                setObjectiveBoolean(3, 1U);
            }
        }
    }
    return 0;
}

void func_mission_overlay_80109558(void) {
    func_mission_overlay_800C776C();
}

void func_mission_overlay_80109574(void) {
    func_mission_overlay_800C7738();
}

s32 lvk_initializeObjectTracking(void) {
    addBooleanCountHandleWrapper(func_mission_overlay_801095DC, 1, 1, 0, 0);
    D_mission_overlay_8010D1F0 = 0;
    return 0;
}

s32 lvk_801095CC(void) {
    return 0;
}

s32 lvk_calculateFriendliesSaved(void) {
    return 0;
}

void func_mission_overlay_801095DC(void) {
    s32 var_s0;

    for (var_s0 = 0xA; var_s0 < 0x19; var_s0++) {
        setObjectiveBoolean(var_s0, 1);
    }
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/level_objective_handling/lv_k", fake_func_80109618);
