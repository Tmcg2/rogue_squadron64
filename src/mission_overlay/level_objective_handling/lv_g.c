#include "common.h"

#include "mission_overlay/0C7EB0.h"
#include "mission_overlay/0C84A0.h"
#include "mission_overlay/level_objective_handling/lv_g.h"

s32 D_mission_overlay_8010D1C0;
s32 D_mission_overlay_8010D1C4;
s32 D_mission_overlay_8010D1C8;
s32 D_mission_overlay_8010D1CC;
s32 D_mission_overlay_8010D1D0;
s32 D_mission_overlay_8010D1D4;
s32 D_mission_overlay_8010D1D8;
s32 D_mission_overlay_8010D1DC;

s32 lvg_checkComplexObjectives(f32 arg0) {
    s32 temp_v0;
    s32 temp_v0_10;
    s32 temp_v0_11;
    s32 temp_v0_12;
    s32 temp_v0_13;
    s32 temp_v0_14;
    s32 temp_v0_15;
    s32 temp_v0_16;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 temp_v0_8;
    s32 temp_v0_9;

    if ((func_mission_overlay_800C77A0() == 0) && (D_mission_overlay_8010D1C8 == 0)) {
        D_mission_overlay_8010D1C8 = 1;
        playObjectiveVoiceLine2(0x17EU, 0.0f);
        playObjectiveVoiceLine2(0x17FU, 0.0f);
        playObjectiveVoiceLine2(0x26AU, 0.0f);
        playObjectiveVoiceLine2(0x39U, 0.0f);
        playObjectiveVoiceLine2(0x180U, 0.0f);
        playObjectiveVoiceLine2(0x252U, 0.0f);
    }
    temp_v0 = getObjectiveBoolean(3);
    if (temp_v0 == 1) {
        temp_v0_2 = getObjectiveBoolean(7);
        if ((temp_v0_2 == temp_v0) && (D_mission_overlay_8010D1CC == 0)) {
            func_mission_overlay_800C776C();
            func_mission_overlay_800C7884("Camera_Win");
            playObjectiveVoiceLine2(0x182U, 0.0f);
            playObjectiveVoiceLine2(0x253U, 0.0f);
            playObjectiveVoiceLine2(0x148U, 0.0f);
            setObjectiveBoolean(0xB, 1U);
            setFriendliesSaved(3);
            D_mission_overlay_8010D1CC = temp_v0_2;
        }
    }
    temp_v0_3 = getObjectiveBoolean(3);
    if (temp_v0_3 == 1) {
        temp_v0_4 = getObjectiveBoolean(8);
        if ((temp_v0_4 == temp_v0_3) && (D_mission_overlay_8010D1CC == 0)) {
            func_mission_overlay_800C776C();
            func_mission_overlay_800C7884("Camera_Win");
            playObjectiveVoiceLine2(0x181U, 0.0f);
            setObjectiveBoolean(0xB, 1U);
            setFriendliesSaved(2);
            D_mission_overlay_8010D1CC = temp_v0_4;
        }
    }
    temp_v0_5 = getObjectiveBoolean(3);
    if (temp_v0_5 == 1) {
        temp_v0_6 = getObjectiveBoolean(9);
        if ((temp_v0_6 == temp_v0_5) && (D_mission_overlay_8010D1CC == 0)) {
            func_mission_overlay_800C776C();
            func_mission_overlay_800C7884("Camera_Win");
            playObjectiveVoiceLine2(0x181U, 0.0f);
            setObjectiveBoolean(0xB, 1U);
            setFriendliesSaved(1);
            D_mission_overlay_8010D1CC = temp_v0_6;
        }
    }
    temp_v0_7 = getObjectiveBoolean(5);
    if (temp_v0_7 == 1) {
        temp_v0_8 = getObjectiveBoolean(7);
        if ((temp_v0_8 == temp_v0_7) && (D_mission_overlay_8010D1CC == 0)) {
            func_mission_overlay_800C7738();
            func_mission_overlay_800C7884("Camera_Lose");
            playObjectiveVoiceLine2(0x3AU, 0.0f);
            setObjectiveBoolean(0xA, 1U);
            setFriendliesSaved(0);
            D_mission_overlay_8010D1CC = temp_v0_8;
        }
    }
    temp_v0_9 = getObjectiveBoolean(4);
    if (temp_v0_9 == 1) {
        temp_v0_10 = getObjectiveBoolean(9);
        if ((temp_v0_10 == temp_v0_9) && (D_mission_overlay_8010D1CC == 0)) {
            func_mission_overlay_800C7738();
            func_mission_overlay_800C7884("Camera_Lose");
            playObjectiveVoiceLine2(0x3AU, 0.0f);
            setObjectiveBoolean(0xA, 1U);
            setFriendliesSaved(0);
            D_mission_overlay_8010D1CC = temp_v0_10;
        }
    }
    temp_v0_11 = getObjectiveBoolean(6);
    if (temp_v0_11 == 1) {
        temp_v0_12 = getObjectiveBoolean(8);
        if ((temp_v0_12 == temp_v0_11) && (D_mission_overlay_8010D1CC == 0)) {
            func_mission_overlay_800C7738();
            func_mission_overlay_800C7884("Camera_Lose");
            playObjectiveVoiceLine2(0x3AU, 0.0f);
            playObjectiveVoiceLine2(0x143U, 0.0f);
            setObjectiveBoolean(0xA, 1U);
            setFriendliesSaved(0);
            D_mission_overlay_8010D1CC = temp_v0_12;
        }
    }
    temp_v0_13 = getObjectiveBoolean(3);
    if ((temp_v0_13 == 1) && (getObjectiveBoolean(8) == 0) && (getObjectiveBoolean(9) == 0) && (getObjectiveBoolean(7) == 0) && (D_mission_overlay_8010D1CC == 0)) {
        func_mission_overlay_800C7738();
        func_mission_overlay_800C7884("Camera_Lose");
        playObjectiveVoiceLine2(0x26BU, 0.0f);
        playObjectiveVoiceLine2(0x3AU, 0.0f);
        D_mission_overlay_8010D1CC = temp_v0_13;
        setObjectiveBoolean(0xA, 1U);
        setFriendliesSaved(0);
    }
    if ((func_mission_overlay_800C794C() < -24.0f) && (D_mission_overlay_8010D1D0 == 0)) {
        D_mission_overlay_8010D1D0 = 1;
        playObjectiveVoiceLine1(0x26BU);
        increaseObjectiveCount(2, 1);
        addTimerHandleWrapper(func_mission_overlay_80108A64, 1.5f);
    }
    if (getObjectiveCount(2) >= 2) {
        func_mission_overlay_800C7738();
        func_mission_overlay_800C7884("Camera_Lose");
        playObjectiveVoiceLine2(0x26BU, 0.0f);
        playObjectiveVoiceLine2(0x3AU, 0.0f);
        D_mission_overlay_8010D1CC = 1;
        setObjectiveBoolean(0xA, 1U);
        setFriendliesSaved(0);
    }
    temp_v0_14 = getObjectiveBoolean(0x14);
    if ((temp_v0_14 == 1) && (D_mission_overlay_8010D1D4 == 0)) {
        func_mission_overlay_800C7738();
        playObjectiveVoiceLine2(0x1F0U, 0.0f);
        D_mission_overlay_8010D1D4 = temp_v0_14;
    }
    temp_v0_15 = getObjectiveBoolean(0x15);
    if ((temp_v0_15 == 1) && (D_mission_overlay_8010D1D8 == 0)) {
        func_mission_overlay_800C7738();
        playObjectiveVoiceLine2(0x1F0U, 0.0f);
        D_mission_overlay_8010D1D8 = temp_v0_15;
    }
    temp_v0_16 = getObjectiveBoolean(0x16);
    if ((temp_v0_16 == 1) && (D_mission_overlay_8010D1DC == 0)) {
        func_mission_overlay_800C7738();
        playObjectiveVoiceLine2(0x1F0U, 0.0f);
        D_mission_overlay_8010D1DC = temp_v0_16;
    }
    func_mission_overlay_80108A70(arg0);
    return 0;
}

void func_mission_overlay_80108A64(void) {
    D_mission_overlay_8010D1D0 = 0;
}

const u8 lv_g_musicrng_levelsettings[36] = {
    "MUSICRNG_LevelSettings\x00\x24\x94\x43\x00\x00\x00\x60\x20\x21\x0C\x01\x53\x78"
};

void func_mission_overlay_80108A70(f32 arg0) {
    s32 var_a0;
    s32 var_v0;

    if (D_mission_overlay_8010D1C0 == 0) {
        if (getObjectiveBoolean(9) != 0) {
            D_mission_overlay_8010D1C0 = 1;
        } else if (getObjectiveBoolean(8) != 0) {
            D_mission_overlay_8010D1C0 = 2;
        } else if (getObjectiveBoolean(7) != 0) {
            D_mission_overlay_8010D1C0 = 3;
        }
        func_mission_overlay_800C7D60(lv_g_musicrng_levelsettings, D_mission_overlay_8010D1C0);
    } else if (D_mission_overlay_8010D1C4 == 0) {
        if (getObjectiveBoolean(3) != 0) {
            D_mission_overlay_8010D1C4 = 1;
            func_mission_overlay_800C7D98(0);
        } else if (D_mission_overlay_8010D1CC != 0) {
            D_mission_overlay_8010D1C4 = 1;
            func_mission_overlay_800C7D98(1);
        }
    }
}

s32 lvg_initializeObjectTracking(void) {
    D_mission_overlay_8010D1C8 = 0;
    D_mission_overlay_8010D1CC = 0;
    D_mission_overlay_8010D1D0 = 0;
    D_mission_overlay_8010D1D4 = 0;
    D_mission_overlay_8010D1D8 = 0;
    D_mission_overlay_8010D1DC = 0;
    D_mission_overlay_8010D1C0 = 0;
    D_mission_overlay_8010D1C4 = 0;
    return 0;
}

s32 lvg_80108B7C(void) {
    return 0;
}

s32 lvg_calculateFriendliesSaved(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/level_objective_handling/lv_g", fake_func_80108B8C);
