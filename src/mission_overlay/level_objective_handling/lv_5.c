#include "common.h"

#include "mission_overlay/0C7EB0.h"
#include "mission_overlay/0C84A0.h"
#include "mission_overlay/level_objective_handling/lv_5.h"

s32 D_mission_overlay_8010D080;
s32 D_mission_overlay_8010D084;

s32 lv5_initializeObjectTracking(void) {
    D_mission_overlay_8010D080 = 0;
    D_mission_overlay_8010D084 = 0;
    addBooleanCountHandleWrapper(func_mission_overlay_80103E5C, 0x23, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_80103F4C, 0, 0, 2, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_80103F68, 0, 0, 2, 2);
    addBooleanCountHandleWrapper(func_mission_overlay_80103F88, 0, 0, 2, 3);
    addBooleanCountHandleWrapper(func_mission_overlay_80103FA8, 0x20, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_80103FC8, 4, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_80104030, 2, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_80104080, 0x28, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_801040B0, 0x1F, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_801040D0, 0x33, 1, 0, 0);
    return 0;
}

void func_mission_overlay_80103E5C(void) {
    setObjectiveBoolean(0x32, 1U);
    activateObjectiveCompleteFlag(2);
    func_mission_overlay_800C7884("Camera1");
    playObjectiveVoiceLine2(0xEU, 1.5f);
    playObjectiveVoiceLine2(0xFU, 1.0f);
    playObjectiveVoiceLine2(0x147U, 0.0f);
    playObjectiveVoiceLine2(0x23EU, 0.0f);
    playObjectiveVoiceLine2(0x148U, 0.0f);
    playObjectiveVoiceLine2(0xDCU, 0.0f);
    playObjectiveVoiceLine2(0x149U, 1.0f);
    playObjectiveVoiceLine2(0x2A3U, 8.0f);
    setObjectiveBoolean(0x6E, 1U);
    func_mission_overlay_800C7D98(0);
    func_mission_overlay_800C7D60("MUSICRNG_LevelDefaults", 0);
    func_mission_overlay_800C7648(0, 0);
    addTimerHandleWrapper(func_mission_overlay_801040F0, 10.0f);
}

void func_mission_overlay_80103F4C(void) {
    playObjectiveVoiceLine1(0xBU);
}

void func_mission_overlay_80103F68(void) {
    playObjectiveVoiceLine2(0xBU, 1.0f);
}

void func_mission_overlay_80103F88(void) {
    playObjectiveVoiceLine2(0x15DU, 1.0f);
}

void func_mission_overlay_80103FA8(void) {
    playObjectiveVoiceLine2(0xAFU, 1.0f);
}

void func_mission_overlay_80103FC8(void) {
    if ((getObjectiveBoolean(0x28) == 1) && (getObjectiveBoolean(0x23) == 0)) {
        playObjectiveVoiceLine2(0xDBU, 0.0f);
        playObjectiveVoiceLine2(0x23BU, 0.0f);
        playObjectiveVoiceLine2(0x146U, 0.0f);
    }
}

void func_mission_overlay_80104030(void) {
    playObjectiveVoiceLine2(0x239U, 0.0f);
    playObjectiveVoiceLine2(0x144U, 1.0f);
    playObjectiveVoiceLine2(0x23AU, 0.0f);
    playObjectiveVoiceLine2(0x145U, 0.0f);
}

void func_mission_overlay_80104080(void) {
    if (getObjectiveBoolean(0x23) == 0) {
        playObjectiveVoiceLine2(0xDU, 1.0f);
    }
}

void func_mission_overlay_801040B0(void) {
    playObjectiveVoiceLine2(0x163U, 1.0f);
}

void func_mission_overlay_801040D0(void) {
    playObjectiveVoiceLine2(0x2A4U, 1.0f);
}

void func_mission_overlay_801040F0(void) {
    func_mission_overlay_800C7648(0, 1);
}

s32 lv5_80104110(void) {
    return 0;
}

s32 lv5_calculateFriendliesSaved(void) {
    setFriendliesSaved(7 - (getObjectiveCount(0x28) + getObjectiveCount(2)));
    return 0;
}

s32 lv5_checkComplexObjectives(void) {
    if ((getObjectiveCount(2) >= 4) && (D_mission_overlay_8010D080 == 0)) {
        D_mission_overlay_8010D080 = 1;
        func_mission_overlay_800C7738();
        playObjectiveVoiceLine2(0x11U, 1.0f);
        playObjectiveVoiceLine2(0xDDU, 1.0f);
        playObjectiveVoiceLine2(0x14BU, 0.5f);
    }
    if ((getObjectiveCount(4) >= 9) && (D_mission_overlay_8010D084 == 0)) {
        D_mission_overlay_8010D084 = 1;
        func_mission_overlay_800C776C();
        activateObjectiveCompleteFlag(1);
        activateObjectiveCompleteFlag(3);
    }
    return 0;
}

// DO NOT DELETE ME I AM REQUIRED FOR MATCHING
const u32 rodata_pad_lv_5[] = {
    0x00000000,
    0x8FC20024,
};

INCLUDE_ASM("asm/nonmatchings/mission_overlay/level_objective_handling/lv_5", fake_func_80104208);
