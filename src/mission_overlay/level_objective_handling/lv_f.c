#include "common.h"

#include "mission_overlay/0C7EB0.h"
#include "mission_overlay/0C84A0.h"
#include "mission_overlay/level_objective_handling/lv_f.h"

s32 D_mission_overlay_8010D1A0;
f32 D_mission_overlay_8010D1A4;
s32 D_mission_overlay_8010D1A8;
s32 D_mission_overlay_8010D1AC;
s32 D_mission_overlay_8010D1B0;

s32 lvf_initializeObjectTracking(void) {
    D_mission_overlay_8010D1A8 = 0;
    D_mission_overlay_8010D1AC = 0;
    D_mission_overlay_8010D1B0 = 0;
    D_mission_overlay_8010D1A0 = 0;
    D_mission_overlay_8010D1A4 = 0;
    addBooleanCountHandleWrapper(func_mission_overlay_80108388, 0, 0, 2, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_801083B0, 0, 0, 2, 2);
    addBooleanCountHandleWrapper(func_mission_overlay_801083D8, 0, 0, 3, 5);
    addBooleanCountHandleWrapper(func_mission_overlay_801083F4, 0x12, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_8010842C, 0, 0, 1, 8);
    addBooleanCountHandleWrapper(func_mission_overlay_80108448, 0, 0, 1, 5);
    addBooleanCountHandleWrapper(func_mission_overlay_80108468, 0, 0, 1, 2);
    addBooleanCountHandleWrapper(func_mission_overlay_80108488, 0, 0, 0x78, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_80108488, 0, 0, 0x79, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_80108488, 0, 0, 0x7A, 1);
    return 0;
}

s32 lvf_checkComplexObjectives(f32 arg0) {
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s1;
    s32 temp_v0;

    temp_s0_2 = getObjectiveCount(0xA) + getObjectiveCount(0xB) + getObjectiveCount(0xC);
    if (D_mission_overlay_8010D1A8 == 0) {
        if ((getObjectiveCount(1) >= 0x19) && (getSceneStatePtr() == 0)) {
            D_mission_overlay_8010D1A8 = 1;
            setHudEnableBit4();
            playObjectiveVoiceLine1(0x250U);
        }
        if (getObjectiveCount(1) >= 0x12) {
            temp_v0 = getSceneStatePtr();
            if (temp_v0 == 1) {
                D_mission_overlay_8010D1A8 = temp_v0;
                setHudEnableBit4();
                playObjectiveVoiceLine1(0x250U);
            }
        }
        if ((getObjectiveCount(1) >= 0xB) && (getSceneStatePtr() == 2)) {
            D_mission_overlay_8010D1A8 = 1;
            setHudEnableBit4();
            playObjectiveVoiceLine1(0x250U);
        }
        if ((getObjectiveCount(1) >= 9) && (getSceneStatePtr() == 3)) {
            D_mission_overlay_8010D1A8 = 1;
            setHudEnableBit4();
            playObjectiveVoiceLine1(0x250U);
        }
        if ((getObjectiveCount(2) >= 3) && (temp_s0_2 == 0x14)) {
            D_mission_overlay_8010D1A8 = 1;
            setHudEnableBit8();
            activateObjectiveCompleteFlag(2);
        }
        if ((D_mission_overlay_8010D1AC == 0) && (calculateDatItemDistanceToPlayer("Dev_South") <= 15.0f)) {
            D_mission_overlay_8010D1AC = 1;
            playObjectiveVoiceLine2(0x270U, 0.0f);
            playObjectiveVoiceLine2(0x2AEU, 1.0f);
        }
        if ((D_mission_overlay_8010D1B0 == 0) && (temp_s0_2 < 0x14) && (getObjectiveCount(2) == 3)) {
            D_mission_overlay_8010D1B0 = 1;
            playObjectiveVoiceLine2(0x24FU, 2.0f);
            playObjectiveVoiceLine2(0x2ADU, 2.0f);
        }
    }
    func_mission_overlay_80108260(arg0);
    return 0;
}

void func_mission_overlay_80108260(f32 arg0) {
    f32 temp_fv0;

    if (getObjectiveCount(0x78) == 0) {
        temp_fv0 = calculateDatItemDistanceToPlayer("Dev_South");
    } else if (getObjectiveCount(0x79) == 0) {
        temp_fv0 = calculateDatItemDistanceToPlayer("Dev_North");
    } else if (getObjectiveCount(0x7A) == 0) {
        temp_fv0 = calculateDatItemDistanceToPlayer("Dev_East");
    } else {
        if (D_mission_overlay_8010D1A0 != 2) {
            D_mission_overlay_8010D1A0 = 2;
            delegateToLevelStageTick("MUSICRNG_LevelSettings", 2);
        }
        return;
    }
    if (temp_fv0 < 30.0f) {
        if (D_mission_overlay_8010D1A0 != 1) {
            D_mission_overlay_8010D1A0 = 1;
            delegateToLevelStageTick("MUSICRNG_LevelSettings", 1);
        }
        D_mission_overlay_8010D1A4 = 6.0f;
    } else if (D_mission_overlay_8010D1A0 == 1) {
        D_mission_overlay_8010D1A4 -= arg0;
        if (D_mission_overlay_8010D1A4 <= 0.0f) {
            D_mission_overlay_8010D1A0 = 0;
            delegateToLevelStageTick("MUSICRNG_LevelSettings", 0);
        }
    }
}

void func_mission_overlay_80108388(void) {
    playObjectiveVoiceLine1(0x1FCU);
    setObjectiveBoolean(7, 1U);
}

void func_mission_overlay_801083B0(void) {
    playObjectiveVoiceLine1(0x1EBU);
    setObjectiveBoolean(6, 1U);
}

void func_mission_overlay_801083D8(void) {
    playObjectiveVoiceLine1(0x230U);
}

void func_mission_overlay_801083F4(void) {
    playObjectiveVoiceLine2(0x2AFU, 0.0f);
    playObjectiveVoiceLine2(0x2B0U, 0.0f);
}

void func_mission_overlay_8010842C(void) {
    playObjectiveVoiceLine1(0x48U);
}

void func_mission_overlay_80108448(void) {
    playObjectiveVoiceLine2(0x293U, 0.0f);
}

void func_mission_overlay_80108468(void) {
    playObjectiveVoiceLine2(0xBAU, 0.0f);
}

void func_mission_overlay_80108488(void) {
    D_mission_overlay_8010D1A4 = 0;
}

s32 lvf_80108494(void) {
    return 0;
}

s32 lvf_calculateFriendliesSaved(void) {
    setFriendliesSaved(0x5C - (getObjectiveCount(1) + getObjectiveCount(5)));
    return 0;
}

// DO NOT DELETE ME I AM REQUIRED FOR MATCHING
const u32 rodata_pad_lv_f = 0x0802AB35;
