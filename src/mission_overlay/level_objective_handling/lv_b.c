#include "common.h"

#include "mission_overlay/0C7EB0.h"
#include "mission_overlay/0C84A0.h"
#include "mission_overlay/level_objective_handling/lv_b.h"

s32 D_mission_overlay_8010D0F0;
s32 D_mission_overlay_8010D0F4;
s32 D_mission_overlay_8010D0F8;
s32 D_mission_overlay_8010D0FC;
f32 D_mission_overlay_8010D100;
s32 D_mission_overlay_8010D104;
s32 D_mission_overlay_8010D108;
s32 D_mission_overlay_8010D10C;
s32 D_mission_overlay_8010D110;
s32 D_mission_overlay_8010D114;
s32 D_mission_overlay_8010D118;
s32 D_mission_overlay_8010D11C;
s32 D_mission_overlay_8010D120;
s32 D_mission_overlay_8010D124;
s32 D_mission_overlay_8010D128;
s32 D_mission_overlay_8010D12C;
s32 D_mission_overlay_8010D130;
s32 D_mission_overlay_8010D134;

s32 lvb_initializeObjectTracking(void) {
    D_mission_overlay_8010D104 = 0;
    D_mission_overlay_8010D108 = 0;
    D_mission_overlay_8010D10C = 0;
    D_mission_overlay_8010D110 = 0;
    D_mission_overlay_8010D114 = 0;
    D_mission_overlay_8010D118 = 0;
    D_mission_overlay_8010D11C = 0;
    D_mission_overlay_8010D120 = 0;
    D_mission_overlay_8010D124 = 0;
    D_mission_overlay_8010D128 = 0;
    D_mission_overlay_8010D12C = 0;
    D_mission_overlay_8010D130 = 0;
    D_mission_overlay_8010D134 = 0;
    D_mission_overlay_8010D0F0 = 0;
    D_mission_overlay_8010D0F4 = 0;
    D_mission_overlay_8010D0F8 = 3;
    D_mission_overlay_8010D0FC = 3;
    D_mission_overlay_8010D100 = 0;
    setObjectiveHiddenFlag(1, 2);
    func_mission_overlay_800C7648(0, 0U);
    func_mission_overlay_800C7648(1, 0U);
    setObjectiveBoolean(0xC, 1U);
    func_mission_overlay_800C7CEC(7.5f);
    addBooleanCountHandleWrapper(func_mission_overlay_80106B08, 0x37, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_80106B40, 0, 0, 0xB, 4);
    addBooleanCountHandleWrapper(func_mission_overlay_80106B78, 0x5C, 1, 0, 0);
    return 0;
}

s32 lvb_checkComplexObjectives(f32 arg0) {
    s32 temp_s0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 temp_v0_8;
    s32 temp_v0_9;

    if (getObjectiveCount(0x56) >= 3) {
        func_mission_overlay_800C7738();
        playObjectiveVoiceLine2(0x16BU, 1.0f);
        return 0;
    }
    if (getObjectiveCount(0x57) == 1) {
        func_mission_overlay_800C7738();
        playObjectiveVoiceLine2(0x5DU, 1.0f);
        playObjectiveVoiceLine2(0x55U, 0.3f);
        return 0;
    }
    temp_v0 = getObjectiveBoolean(0x16);
    if ((temp_v0 == 1) && (D_mission_overlay_8010D10C == temp_v0)) {
        temp_s0 = D_mission_overlay_8010D108;
        if (temp_s0 == D_mission_overlay_8010D10C) {
            func_mission_overlay_800C776C();
            func_mission_overlay_800C7D98(0);
            D_mission_overlay_8010D0F4 = temp_s0;
            activateObjectiveCompleteFlag(1);
            activateObjectiveCompleteFlag(4);
            setObjectiveHiddenFlag(0, 2);
            func_mission_overlay_800C7884("HeavyLifterShuttleCamera");
            playObjectiveVoiceLine2(0x24AU, 1.0f);
            return 0;
        }
    }
    temp_v0_2 = getObjectiveBoolean(0x7C);
    if ((temp_v0_2 == 1) && (D_mission_overlay_8010D10C == temp_v0_2) && (D_mission_overlay_8010D104 == D_mission_overlay_8010D10C)) {
        func_mission_overlay_800C776C();
        setObjectiveHiddenFlag(0, 2);
        activateObjectiveCompleteFlag(2);
        playObjectiveVoiceLine2(0x21EU, 1.0f);
        return 0;
    }
    if ((getObjectiveBoolean(0x16) == 1) && (getObjectiveBoolean(0x46) == 0)) {
        setObjectiveBoolean(0x46, 1U);
        setObjectiveBoolean(0x57, 1U);
        setObjectiveBoolean(0x58, 1U);
        setObjectiveBoolean(0x59, 1U);
    }
    if (getObjectiveBoolean(0x3D) == 0) {
        setObjectiveBoolean(0x3E, 0U);
    }
    temp_v0_3 = getObjectiveBoolean(0x7B);
    if ((temp_v0_3 == 1) && (D_mission_overlay_8010D12C == 0)) {
        D_mission_overlay_8010D12C = temp_v0_3;
        func_mission_overlay_800C7648(0, 1U);
    }
    temp_v0_4 = getObjectiveBoolean(0x7D);
    if (temp_v0_4 == 1) {
        if (D_mission_overlay_8010D130 == 0) {
            D_mission_overlay_8010D130 = temp_v0_4;
            func_mission_overlay_800C7648(1, 1U);
        }
    }
    if ((calculateDatItemDistanceToPlayer("AT_PT_01") <= 16.0f) || (calculateDatItemDistanceToPlayer("AT_PT_02") <= 16.0f) || (calculateDatItemDistanceToPlayer("AT_PT_03") <= 16.0f)) {
        if (D_mission_overlay_8010D128 == 0) {
            D_mission_overlay_8010D128 = 1;
            activateObjectiveCompleteFlag(1);
        }
    }
    if (D_mission_overlay_8010D134 == 1) {
        if (getObjectiveTimer(7) >= 12.0f) {
            D_mission_overlay_8010D134 = 0;
        }
    }
    if (D_mission_overlay_8010D134 == 0) {
        temp_v0_5 = getObjectiveBoolean(0x16);
        if ((temp_v0_5 == 1) && (D_mission_overlay_8010D10C == 0)) {
            D_mission_overlay_8010D10C = temp_v0_5;
            D_mission_overlay_8010D104 = temp_v0_5;
            D_mission_overlay_8010D134 = temp_v0_5;
            func_mission_overlay_800C7D98(0);
            D_mission_overlay_8010D0F4 = temp_v0_5;
            activateObjectiveCompleteFlag(1);
            activateObjectiveCompleteFlag(4);
            setObjectiveHiddenFlag(0, 2);
            func_mission_overlay_800C7884("HeavyLifterShuttleCamera");
            setObjectiveTimer(7, 0.0f);
            playObjectiveVoiceLine2(0x24AU, 1.0f);
            playObjectiveVoiceLine2(0x16CU, 0.3f);
            setObjectiveBoolean(0x74, 1U);
            return 0;
        }
        temp_v0_6 = getObjectiveBoolean(0x7C);
        if ((temp_v0_6 == 1) && (D_mission_overlay_8010D10C == 0)) {
            D_mission_overlay_8010D108 = temp_v0_6;
            D_mission_overlay_8010D10C = temp_v0_6;
            D_mission_overlay_8010D134 = temp_v0_6;
            setObjectiveHiddenFlag(0, 2);
            activateObjectiveCompleteFlag(2);
            setObjectiveTimer(7, 9.0f);
            playObjectiveVoiceLine2(0x21EU, 1.0f);
            return 0;
        }
        temp_v0_7 = getObjectiveBoolean(0x7D);
        if ((temp_v0_7 == 1)  && (D_mission_overlay_8010D110 == 0)) {
            D_mission_overlay_8010D110 = temp_v0_7;
            D_mission_overlay_8010D134 = temp_v0_7;
            func_mission_overlay_800C7D98(3);
            setObjectiveTimer(7, 9.0f);
            func_mission_overlay_800C7884("FacilityCamera");
            func_mission_overlay_800C7D44();
            playObjectiveVoiceLine2(0x21DU, 1.0f);
            return 0;
        } else {
            if (D_mission_overlay_8010D114 == 0) {
                D_mission_overlay_8010D114 = 1;
                D_mission_overlay_8010D134 = 1;
                setObjectiveTimer(7, 6.0f);
                playObjectiveVoiceLine2(0x108U, 0.3f);
                playObjectiveVoiceLine2(0x42U, 0.3f);
                playObjectiveVoiceLine2(0x9BU, 0.3f);
                playObjectiveVoiceLine2(0x25DU, 0.3f);
                playObjectiveVoiceLine2(0x2DU, 0.3f);
                return 0;
            }
            if (getObjectiveBoolean(1) == 0) {
                temp_v0_8 = getObjectiveBoolean(2);
                if ((temp_v0_8 == 1) && (D_mission_overlay_8010D118 == 0)) {
                    D_mission_overlay_8010D118 = temp_v0_8;
                    D_mission_overlay_8010D134 = temp_v0_8;
                    activateObjectiveCompleteFlag(1);
                    setObjectiveTimer(7, 3.0f);
                    playObjectiveVoiceLine2(0x169U, 1.0f);
                    return 0;
                }
            }
            temp_v0_9 = getObjectiveBoolean(1);
            if ((temp_v0_9 == 1) && (D_mission_overlay_8010D11C == 0)) {
                D_mission_overlay_8010D11C = temp_v0_9;
                D_mission_overlay_8010D134 = temp_v0_9;
                activateObjectiveCompleteFlag(3);
                setObjectiveTimer(7, 8.0f);
                playObjectiveVoiceLine2(0x248U, 0.5f);
                increaseObjectiveCount(0x2C, 2);
                return 0;
            }
            if ((getObjectiveCount(0x2C) == 2) && (D_mission_overlay_8010D120 == 0)) {
                D_mission_overlay_8010D120 = 1;
                D_mission_overlay_8010D134 = 1;
                setObjectiveTimer(7, 7.0f);
                playObjectiveVoiceLine2(0x16AU, 0.0f);
                return 0;
            }
            if ((D_mission_overlay_8010D118 == 1) && (D_mission_overlay_8010D124 == 0)) {
                D_mission_overlay_8010D124 = D_mission_overlay_8010D118;
                D_mission_overlay_8010D134 = D_mission_overlay_8010D118;
                setObjectiveTimer(7, 0.0f);
                playObjectiveVoiceLine2(0x92U, 7.0f);
                playObjectiveVoiceLine2(0x247U, 1.0f);
                return 0;
            }
        }
    }
    func_mission_overlay_8010695C(arg0);
    return 0;
}

void func_mission_overlay_8010695C(f32 arg0) {
    f32 temp_fv0;
    s32 temp_a1;
    s32 temp_v0;

    if (D_mission_overlay_8010D0F0 == 0) {
        temp_v0 = getObjectiveBoolean(1);
        if (temp_v0 == 1) {
            if ((getObjectiveBoolean(0x64) == 0) || (getObjectiveBoolean(0x7D) == temp_v0)) {
                D_mission_overlay_8010D0F8 = 0;
                D_mission_overlay_8010D0F0 = temp_v0;
                if (D_mission_overlay_8010D0FC != 2) {
                    D_mission_overlay_8010D0FC = 0;
                    func_mission_overlay_800C7D60("MUSICRNG_LevelSettings", 0);
                }
            }
        }
    }
    temp_a1 = D_mission_overlay_8010D0F4;
    if (temp_a1 == 1) {
        D_mission_overlay_8010D0F4 = 2;
        D_mission_overlay_8010D0F8 = temp_a1;
        if (D_mission_overlay_8010D0FC != 2) {
            D_mission_overlay_8010D0FC = temp_a1;
            func_mission_overlay_800C7D60("MUSICRNG_LevelSettings", 1);
        }
    }
    if ((getObjectiveBoolean(0x7C) == 0) && (getObjectiveBoolean(0x7D) == 1)) {
        if (getObjectiveBoolean(0x6F) != 0) {
            if (D_mission_overlay_8010D0FC != 2) {
                D_mission_overlay_8010D0FC = 2;
                func_mission_overlay_800C7D60("MUSICRNG_LevelSettings", 2);
            }
            D_mission_overlay_8010D100 = 6.0f;
            return;
        }
        if (D_mission_overlay_8010D0FC == 2) {
            D_mission_overlay_8010D100 -= arg0;
            if (D_mission_overlay_8010D100 <= 0.0f) {
                D_mission_overlay_8010D0FC = D_mission_overlay_8010D0F8;
                func_mission_overlay_800C7D60("MUSICRNG_LevelSettings", D_mission_overlay_8010D0F8);
            }
        }
    } else if (D_mission_overlay_8010D0FC == 2) {
        D_mission_overlay_8010D0FC = D_mission_overlay_8010D0F8;
        func_mission_overlay_800C7D60("MUSICRNG_LevelSettings", D_mission_overlay_8010D0F8);
    }
}

void func_mission_overlay_80106B08(void) {
    playObjectiveVoiceLine2(0xADU, 0.0f);
    playObjectiveVoiceLine2(0x11AU, 0.0f);
}

void func_mission_overlay_80106B40(void) {
    playObjectiveVoiceLine2(0x1F8U, 0.0f);
    playObjectiveVoiceLine2(0x11BU, 0.0f);
}

void func_mission_overlay_80106B78(void) {
    playObjectiveVoiceLine2(0x2F2U, 2.0f);
}

s32 lvb_80106B98(void) {
    return 0;
}

s32 lvb_calculateFriendliesSaved(void) {
    setFriendliesSaved(7 - (getObjectiveCount(0x56) + getObjectiveCount(0x58)));
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/level_objective_handling/lv_b", fake_func_80106BE4);
