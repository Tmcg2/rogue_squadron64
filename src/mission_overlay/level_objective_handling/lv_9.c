#include "common.h"

#include "mission_overlay/0C7EB0.h"
#include "mission_overlay/0C84A0.h"
#include "mission_overlay/level_objective_handling/lv_9.h"

s32 D_mission_overlay_8010D0D0;
s32 D_mission_overlay_8010D0D4;
s32 D_mission_overlay_8010D0D8;
s32 D_mission_overlay_8010D0DC;
s32 D_mission_overlay_8010D0E0;

s32 lv9_initializeObjectTracking(void) {
    D_mission_overlay_8010D0D0 = 0;
    D_mission_overlay_8010D0D4 = 0;
    D_mission_overlay_8010D0D8 = 0;
    D_mission_overlay_8010D0DC = 0;
    D_mission_overlay_8010D0E0 = 0;
    setLevelObjectTrackingScalar(7.5f);
    addBooleanCountHandleWrapper(func_mission_overlay_80105304, 0, 0, 1, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_8010539C, 0, 0, 2, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_801053C8, 0, 0, 3, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_8010549C, 0, 0, 4, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_8010552C, 7, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_8010556C, 8, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_801055AC, 9, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_801055E0, 0xA, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_80105600, 0xB, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_80105660, 0, 0, 8, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_80105634, 0, 0, 7, 3);
    addBooleanCountHandleWrapper(func_mission_overlay_8010568C, 0, 0, 7, 3);
    addBooleanCountHandleWrapper(func_mission_overlay_80105790, 0, 0, 0x20, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_801058A0, 0, 0, 0xB, 3);
    addBooleanCountHandleWrapper(func_mission_overlay_801059B0, 0, 0, 0xE, 3);
    addBooleanCountHandleWrapper(func_mission_overlay_80105AC0, 0x23, 1, 0, 0);
    setObjectiveHiddenFlag(1, 2);
    addBooleanCountHandleWrapper(func_mission_overlay_80105AE0, 2, 1, 0, 0);
    return 0;
}

s32 lv9_checkComplexObjectives(void) {
    if ((D_mission_overlay_8010D0D0 == 0) && (getObjectiveCount(5) > 0)) {
        D_mission_overlay_8010D0D0 = 1;
        setHudEnableBit4();
        playObjectiveVoiceLine2(0x164U, 0.0f);
    }
    if (getObjectiveBoolean(0xD) > 0) {
        setHudEnableBit8();
        activateObjectiveCompleteFlag(1);
    }
    if ((getDatItemHealthPercentage("Evac_Shuttle") < 35.0f) && (D_mission_overlay_8010D0D4 == 0)) {
        D_mission_overlay_8010D0D4 = 1;
        playObjectiveVoiceLine2(0xBU, 0.0f);
    }
    if ((getDatItemHealthPercentage("Evac_Shuttle") < 15.0f) && (D_mission_overlay_8010D0D8 == 0)) {
        D_mission_overlay_8010D0D8 = 1;
        playObjectiveVoiceLine2(0x1AU, 0.0f);
    }
    if ((getDatItemHealthPercentage("Evac_Shuttle") < 2.0f) && (D_mission_overlay_8010D0DC == 0)) {
        D_mission_overlay_8010D0DC = 1;
        playObjectiveVoiceLine2(0x1CU, 0.0f);
    }
    return 0;
}

void func_mission_overlay_80105304(void) {
    playObjectiveVoiceLine2(0x10EU, 0.0f);
    setObjectiveBoolean(0xF, 1U);
    setObjectiveBoolean(0x18, 1U);
    setObjectiveBoolean(0x19, 1U);
    setObjectiveBoolean(0x1A, 1U);
    setObjectiveBoolean(0x1B, 1U);
    setObjectiveBoolean(0x1C, 1U);
    setObjectiveBoolean(0x1D, 1U);
    setObjectiveBoolean(0x1E, 1U);
    setObjectiveBoolean(0x1F, 1U);
    setObjectiveBoolean(0x21, 1U);
}

void func_mission_overlay_8010539C(void) {
    playObjectiveVoiceLine2(0x26DU, 1.5f);
    playObjectiveVoiceLine2(0x12U, 0.0f);
}

void func_mission_overlay_801053C8(void) {
    addTimerHandleWrapper(func_mission_overlay_801053EC, 1.0f);
}

void func_mission_overlay_801053EC(void) {
    if ((getObjectiveBoolean(2) == 0) && (getObjectiveBoolean(6) == 1)) {
        playObjectiveVoiceLine2(0x13U, 0.5f);
        playObjectiveVoiceLine2(0x252U, 0.0f);
        addTimerHandleWrapper(func_mission_overlay_80105464, 5.0f);
        setObjectiveBoolean(0x21, 0U);
        setObjectiveHiddenFlag(0, 2);
    }
}

const u8 blah[16] = {
    "Camera_Gen\x00\x20\xC7\xC2\x00\xD8"
};

void func_mission_overlay_80105464(void) {
    setObjectiveBoolean(0x20, 1U);
    setHudFlagBit40AndStoreArg(blah);
    setObjectiveBoolean(0xE, 1U);
}

void func_mission_overlay_8010549C(void) {
    addTimerHandleWrapper(func_mission_overlay_801054C0, 4.0f);
}

void func_mission_overlay_801054C0(void) {
    s32 temp_v0;

    temp_v0 = getObjectiveBoolean(2);
    if ((temp_v0 == 1) && (getObjectiveBoolean(6) == temp_v0)) {
        playObjectiveVoiceLine2(0x14U, 0.0f);
        increaseObjectiveCount(6, 1);
        activateObjectiveCompleteFlag(2);
        setObjectiveBoolean(0x21, 0U);
    }
}

void func_mission_overlay_8010552C(void) {
    playObjectiveVoiceLine2(0x16U, 0.0f);
    playObjectiveVoiceLine2(0x2EBU, 2.0f);
    setObjectiveBoolean(0x79, 1U);
    triggerSoundCueByType(5);
}

void func_mission_overlay_8010556C(void) {
    playObjectiveVoiceLine2(0x16U, 0.0f);
    playObjectiveVoiceLine2(0x2EBU, 2.0f);
    setObjectiveBoolean(0x7A, 1U);
    triggerSoundCueByType(5);
}

void func_mission_overlay_801055AC(void) {
    playObjectiveVoiceLine2(0x16U, 0.0f);
    setObjectiveBoolean(0x7B, 1U);
    triggerSoundCueByType(5);
}

void func_mission_overlay_801055E0(void) {
    playObjectiveVoiceLine2(0x17U, 0.0f);
}

void func_mission_overlay_80105600(void) {
    playObjectiveVoiceLine2(0x18U, 0.0f);
    setObjectiveBoolean(0x7C, 1U);
    triggerSoundCueByType(7);
}

void func_mission_overlay_80105634(void) {
    if (D_mission_overlay_8010D0D0 == 0) {
        playObjectiveVoiceLine2(7U, 0.0f);
    }
}

void func_mission_overlay_80105660(void) {
    playObjectiveVoiceLine2(0xBU, 0.0f);
    playObjectiveVoiceLine2(0x1BU, 1.0f);
}

void func_mission_overlay_8010568C(void) {
    addTimerHandleWrapper(func_mission_overlay_801056B0, 1.0f);
}

void func_mission_overlay_801056B0(void) {
    increaseObjectiveCount(0x10, 1);
    addTimerHandleWrapper(func_mission_overlay_801056E0, 1.0f);
}

void func_mission_overlay_801056E0(void) {
    increaseObjectiveCount(0x13, 1);
    addTimerHandleWrapper(func_mission_overlay_80105710, 13.0f);
}

void func_mission_overlay_80105710(void) {
    increaseObjectiveCount(0x11, 1);
    addTimerHandleWrapper(func_mission_overlay_80105740, 1.0f);
}

void func_mission_overlay_80105740(void) {
    increaseObjectiveCount(0x12, 1);
    addTimerHandleWrapper(func_mission_overlay_80105770, 15.0f);
}

void func_mission_overlay_80105770(void) {
    setObjectiveBoolean(0x14, 1U);
}

void func_mission_overlay_80105790(void) {
    addTimerHandleWrapper(func_mission_overlay_801057C0, 1.0f);
    playObjectiveVoiceLine2(0x274U, 0.0f);
}

void func_mission_overlay_801057C0(void) {
    increaseObjectiveCount(0x14, 1);
    addTimerHandleWrapper(func_mission_overlay_801057F0, 1.0f);
}

void func_mission_overlay_801057F0(void) {
    increaseObjectiveCount(0x17, 1);
    addTimerHandleWrapper(func_mission_overlay_80105820, 15.0f);
}

void func_mission_overlay_80105820(void) {
    increaseObjectiveCount(0x15, 1);
    addTimerHandleWrapper(func_mission_overlay_80105850, 1.0f);
}

void func_mission_overlay_80105850(void) {
    increaseObjectiveCount(0x16, 1);
    addTimerHandleWrapper(func_mission_overlay_80105880, 22.0f);
}

void func_mission_overlay_80105880(void) {
    setObjectiveBoolean(0x15, 1U);
}

void func_mission_overlay_801058A0(void) {
    addTimerHandleWrapper(func_mission_overlay_801058D0, 1.0f);
    playObjectiveVoiceLine2(7U, 0.0f);
}

void func_mission_overlay_801058D0(void) {
    increaseObjectiveCount(0x18, 1);
    addTimerHandleWrapper(func_mission_overlay_80105900, 1.0f);
}

void func_mission_overlay_80105900(void) {
    increaseObjectiveCount(0x1B, 1);
    addTimerHandleWrapper(func_mission_overlay_80105930, 15.0f);
}

void func_mission_overlay_80105930(void) {
    increaseObjectiveCount(0x19, 1);
    addTimerHandleWrapper(func_mission_overlay_80105960, 1.0f);
}

void func_mission_overlay_80105960(void) {
    increaseObjectiveCount(0x1A, 1);
    addTimerHandleWrapper(func_mission_overlay_80105990, 19.0f);
}

void func_mission_overlay_80105990(void) {
    setObjectiveBoolean(0x16, 1U);
}

void func_mission_overlay_801059B0(void) {
    addTimerHandleWrapper(func_mission_overlay_801059E0, 1.0f);
    playObjectiveVoiceLine2(7U, 0.0f);
}

void func_mission_overlay_801059E0(void) {
    increaseObjectiveCount(0x1C, 1);
    addTimerHandleWrapper(func_mission_overlay_80105A10, 1.0f);
}

void func_mission_overlay_80105A10(void) {
    increaseObjectiveCount(0x1F, 1);
    addTimerHandleWrapper(func_mission_overlay_80105A40, 30.0f);
}

void func_mission_overlay_80105A40(void) {
    increaseObjectiveCount(0x1D, 1);
    addTimerHandleWrapper(func_mission_overlay_80105A70, 1.0f);
}

void func_mission_overlay_80105A70(void) {
    increaseObjectiveCount(0x1E, 1);
    addTimerHandleWrapper(func_mission_overlay_80105AA0, 38.0f);
}

void func_mission_overlay_80105AA0(void) {
    setObjectiveBoolean(0x17, 1U);
}

void func_mission_overlay_80105AC0(void) {
    playObjectiveVoiceLine2(0x299U, 0.0f);
}

void func_mission_overlay_80105AE0(void) {
    setObjectiveBoolean(0x78, 1U);
}

s32 lv9_80105B00(void) {
    return 0;
}

s32 lv9_calculateFriendliesSaved(void) {
    D_mission_overlay_8010D0E0 = getObjectiveCount(0x25) + getObjectiveCount(0x26);
    setFriendliesSaved(0x26 - D_mission_overlay_8010D0E0);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/level_objective_handling/lv_9", fake_func_80105B54);
