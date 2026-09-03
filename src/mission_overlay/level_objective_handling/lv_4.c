#include "common.h"

#include "mission_overlay/0C7EB0.h"
#include "mission_overlay/0C84A0.h"
#include "mission_overlay/level_objective_handling/lv_4.h"

s32 D_mission_overlay_8010D060;
s32 D_mission_overlay_8010D064;
s32 D_mission_overlay_8010D068;
s32 D_mission_overlay_8010D06C;
s32 D_mission_overlay_8010D070;
s32 D_mission_overlay_8010D074;
s32 D_mission_overlay_8010D078;
s32 D_mission_overlay_8010D07C;

s32 lv4_initializeObjectTracking(void) {
    D_mission_overlay_8010D060 = 0;
    D_mission_overlay_8010D064 = 0;
    D_mission_overlay_8010D068 = 0;
    D_mission_overlay_8010D06C = 0;
    D_mission_overlay_8010D070 = 0;
    D_mission_overlay_8010D074 = 0;
    D_mission_overlay_8010D078 = 0;
    D_mission_overlay_8010D07C = 0;
    addBooleanCountHandleWrapper(func_mission_overlay_80103994, 0xA, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_80103A90, 0x1E, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_80103C10, 2, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_80103AB0, 0xC, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_801039B0, 0, 0, 0xF, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_80103A00, 0, 0, 0xF, 2);
    addBooleanCountHandleWrapper(func_mission_overlay_80103A50, 0, 0, 0xF, 3);
    addBooleanCountHandleWrapper(func_mission_overlay_80103A70, 0, 0, 0x1D, 2);
    addBooleanCountHandleWrapper(func_mission_overlay_80103BBC, 3, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_80103BF0, 4, 1, 0, 0);
    addTimerHandleWrapper(func_mission_overlay_80103C40, 7.0f);
    playObjectiveVoiceLine2(0x2A2U, 2.0f);
    return 0;
}

s32 lv4_checkComplexObjectives(void) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;

    if (getObjectiveCount(0x10) >= 3) {
        setHudEnableBit4();
    }
    if (getObjectiveCount(0xF) >= 3) {
        setHudEnableBit4();
    }
    if ((getObjectiveCount(0x1C) > 0) && (D_mission_overlay_8010D060 == 1)) {
        setHudEnableBit8();
        activateObjectiveCompleteFlag(1);
        activateObjectiveCompleteFlag(2);
    }
    temp_v0 = getObjectiveBoolean(0xC);
    if (temp_v0 == 1) {
        temp_v0_2 = getObjectiveBoolean(0x20);
        if ((temp_v0_2 == temp_v0) && (D_mission_overlay_8010D064 == 0)) {
            D_mission_overlay_8010D064 = temp_v0_2;
            playObjectiveVoiceLine2(0x31U, 2.0f);
            playObjectiveVoiceLine2(0x143U, 0.5f);
        }
    }
    if ((getObjectiveCount(0x1D) >= 3) && (getObjectiveCount(0x1E) >= 3) && (D_mission_overlay_8010D068 == 0)) {
        D_mission_overlay_8010D068 = 1;
        playObjectiveVoiceLine1(7U);
    }
    temp_v0_3 = getObjectiveBoolean(0x1A);
    if ((temp_v0_3 == 1) && (D_mission_overlay_8010D074 == 0)) {
        D_mission_overlay_8010D074 = temp_v0_3;
        setHudEnableBit4();
        playObjectiveVoiceLine1(0xCU);
    }
    if (getObjectiveBoolean(0xC) == 0) {
        temp_v0_4 = getObjectiveCount(0x1F);
        if ((temp_v0_4 == 1) && (D_mission_overlay_8010D06C == temp_v0_4)) {
            playObjectiveVoiceLine2(0xBU, 1.0f);
            addTimerHandleWrapper(func_mission_overlay_80103C30, 5.0f);
            D_mission_overlay_8010D06C = 0;
        }
    }
    if ((getObjectiveBoolean(0xC) == 0) && (getObjectiveCount(0x1F) == 2) && (D_mission_overlay_8010D070 == 1)) {
        D_mission_overlay_8010D070 = 0;
        addTimerHandleWrapper(func_mission_overlay_80103C50, 2.0f);
    }
    if ((getObjectiveBoolean(0xC) == 0) && (getObjectiveCount(0x1F) == 3) && (D_mission_overlay_8010D078 == 0)) {
        D_mission_overlay_8010D078 = 1;
        addTimerHandleWrapper(func_mission_overlay_80103C74, 2.0f);
    }
    if ((getObjectiveBoolean(0xC) == 0) && (getObjectiveCount(0x1F) == 5) && (D_mission_overlay_8010D07C == 0)) {
        D_mission_overlay_8010D07C = 1;
        addTimerHandleWrapper(func_mission_overlay_80103C98, 2.0f);
    }
    return 0;
}

void func_mission_overlay_80103994(void) {
    playObjectiveVoiceLine1(0xAU);
}

void func_mission_overlay_801039B0(void) {
    if (getObjectiveCount(0x1E) >= 3) {
        playObjectiveVoiceLine2(0xB, 1.0f);
    } else {
        playObjectiveVoiceLine2(0xBU, 1.0f);
        playObjectiveVoiceLine2(0x2A1, 0.0f);
    }
}

void func_mission_overlay_80103A00(void) {
    if (getObjectiveCount(0x1E) >= 3) {
        playObjectiveVoiceLine2(0x33, 0.5f);
    } else {
        playObjectiveVoiceLine2(0x33U, 0.5f);
        playObjectiveVoiceLine2(0x2A1, 0.0f);
    }
}

void func_mission_overlay_80103A50(void) {
    playObjectiveVoiceLine2(0x34U, 1.0f);
}

void func_mission_overlay_80103A70(void) {
    playObjectiveVoiceLine2(0x28U, 0.75f);
}

void func_mission_overlay_80103A90(void) {
    playObjectiveVoiceLine2(0x27U, 1.0f);
}

void func_mission_overlay_80103AB0(void) {
    setHudFlagBit40AndStoreArg("Cut_Camera");
    playObjectiveVoiceLine2(0x238U, 0.0f);
    playObjectiveVoiceLine2(0x30U, 0.0f);
    playObjectiveVoiceLine2(0x142U, 0.0f);
    addTimerHandleWrapper(func_mission_overlay_80103B34, 2.0f);
    addTimerHandleWrapper(func_mission_overlay_80103B88, 7.0f);
    triggerSoundCueByType(3);
    setObjectiveBoolean(0x6F, 1U);
}

void func_mission_overlay_80103B34(void) {
    initAnchoredActorTowardNamedDatItem("Y_Wing_uno", "y_wing_intercity");
    initAnchoredActorTowardNamedDatItem("Y_Wing_dos", "y_wing_intercity");
    initAnchoredActorTowardNamedDatItem("Y_Wing_tres", "y_wing_intercity");
}

void func_mission_overlay_80103B88(void) {
    dealDamagetoDatItem("cut_tie_int1", 2U);
    dealDamagetoDatItem("cut_tie_int2", 2U);
}

// DO NOT DELETE ME I AM REQUIRED FOR MATCHING
const u32 rodata_pad_lv_4[] = {
    0x8FC20024,
    0x24030080,
    0xA043000A,
};

void func_mission_overlay_80103BBC(void) {
    D_mission_overlay_8010D060 = 1;
    playObjectiveVoiceLine2(0x27U, 2.0f);
    activateObjectiveCompleteFlag(3);
}

void func_mission_overlay_80103BF0(void) {
    playObjectiveVoiceLine2(0x32U, 2.0f);
}

void func_mission_overlay_80103C10(void) {
    playObjectiveVoiceLine2(0xFEU, 1.0f);
}

void func_mission_overlay_80103C30(void) {
    D_mission_overlay_8010D070 = 1;
}

void func_mission_overlay_80103C40(void) {
    D_mission_overlay_8010D06C = 1;
}

void func_mission_overlay_80103C50(void) {
    dealDamagetoDatItem("Y_Wing_uno", 0xD3U);
}

void func_mission_overlay_80103C74(void) {
    dealDamagetoDatItem("Y_Wing_dos", 0xD3U);
}

void func_mission_overlay_80103C98(void) {
    dealDamagetoDatItem("Y_Wing_tres", 0xD3U);
}

s32 lv4_80103CBC(void) {
    return 0;
}

s32 lv4_calculateFriendliesSaved(void) {
    setFriendliesSaved(6 - (getObjectiveCount(0x28) + getObjectiveCount(0xF)));
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/level_objective_handling/lv_4", fake_func_80103D08);
