#include "common.h"

#include "mission_overlay/0C7EB0.h"
#include "mission_overlay/0C84A0.h"
#include "mission_overlay/level_objective_handling/lv_a.h"

s32 lva_initializeObjectTracking(void) {
    setLevelObjectTrackingScalar(7.5f);
    addBooleanCountHandleWrapper(func_mission_overlay_80105ED0, 0, 0, 0x32, 9);
    addBooleanCountHandleWrapper(func_mission_overlay_80105EF8, 0, 0, 0x31, 7);
    addBooleanCountHandleWrapper(func_mission_overlay_80105F20, 0, 0, 0x35, 0xA);
    addBooleanCountHandleWrapper(func_mission_overlay_80105F48, 0, 0, 0x36, 0xC);
    addBooleanCountHandleWrapper(func_mission_overlay_80105F70, 0, 0, 0x37, 9);
    addBooleanCountHandleWrapper(func_mission_overlay_80105F98, 0, 0, 0x38, 6);
    addBooleanCountHandleWrapper(func_mission_overlay_80105FC0, 0, 0, 0x32, 3);
    addBooleanCountHandleWrapper(func_mission_overlay_80105FDC, 0, 0, 0x37, 0x18);
    addBooleanCountHandleWrapper(func_mission_overlay_80105FF8, 0, 0, 0x33, 4);
    addBooleanCountHandleWrapper(func_mission_overlay_80106050, 0, 0, 0x33, 7);
    addBooleanCountHandleWrapper(func_mission_overlay_80106034, 0, 0, 0x33, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_80106088, 0, 0, 0x28, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_8010606C, 0, 0, 0x29, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_801060B4, 0, 0, 0x2D, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_80106014, 0, 0, 0x36, 0xC);
    addBooleanCountHandleWrapper(func_mission_overlay_80105E28, 0, 0, 0x64, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_80105E44, 0, 0, 0x65, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_80105E60, 0, 0, 0x66, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_80105E7C, 0, 0, 0x67, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_80105E98, 0, 0, 0x68, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_80105EB4, 0, 0, 0x69, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_801060E0, 0, 0, 0x74, 1);
    return 0;
}

void func_mission_overlay_80105E28(void) {
    playObjectiveVoiceLine1(0x11FU);
}

void func_mission_overlay_80105E44(void) {
    playObjectiveVoiceLine1(0x217U);
}

void func_mission_overlay_80105E60(void) {
    playObjectiveVoiceLine1(0xAAU);
}

void func_mission_overlay_80105E7C(void) {
    playObjectiveVoiceLine1(0xB6U);
}

void func_mission_overlay_80105E98(void) {
    playObjectiveVoiceLine1(0xC4U);
}

void func_mission_overlay_80105EB4(void) {
    playObjectiveVoiceLine1(0xAAU);
}

void func_mission_overlay_80105ED0(void) {
    playObjectiveVoiceLine1(0x21EU);
    increaseObjectiveCount(0x63, 1);
}

void func_mission_overlay_80105EF8(void) {
    playObjectiveVoiceLine1(0x21DU);
    increaseObjectiveCount(0x63, 1);
}

void func_mission_overlay_80105F20(void) {
    playObjectiveVoiceLine1(0xE5U);
    increaseObjectiveCount(0x63, 1);
}

void func_mission_overlay_80105F48(void) {
    playObjectiveVoiceLine1(0x21EU);
    increaseObjectiveCount(0x63, 1);
}

void func_mission_overlay_80105F70(void) {
    playObjectiveVoiceLine1(0xB1U);
    increaseObjectiveCount(0x63, 1);
}

void func_mission_overlay_80105F98(void) {
    playObjectiveVoiceLine1(0x21DU);
    increaseObjectiveCount(0x63, 1);
}

void func_mission_overlay_80105FC0(void) {
    playObjectiveVoiceLine1(0x21CU);
}

void func_mission_overlay_80105FDC(void) {
    playObjectiveVoiceLine1(0x259U);
}

void func_mission_overlay_80105FF8(void) {
    playObjectiveVoiceLine1(0xECU);
}

void func_mission_overlay_80106014(void) {
    playObjectiveVoiceLine2(0xEEU, 1.5f);
}

void func_mission_overlay_80106034(void) {
    playObjectiveVoiceLine1(0x167U);
}

void func_mission_overlay_80106050(void) {
    playObjectiveVoiceLine1(0xC4U);
}

void func_mission_overlay_8010606C(void) {
    playObjectiveVoiceLine1(0xEAU);
}

void func_mission_overlay_80106088(void) {
    playObjectiveVoiceLine2(0x244U, 0.0f);
    playObjectiveVoiceLine2(0xEBU, 0.5f);
}

void func_mission_overlay_801060B4(void) {
    playObjectiveVoiceLine2(0x246U, 0.0f);
    playObjectiveVoiceLine2(0xEDU, 0.5f);
}

void func_mission_overlay_801060E0(void) {
    playObjectiveVoiceLine2(0x159U, 0.0f);
}

s32 lva_80106100(void) {
    return 0;
}

s32 lva_calculateFriendliesSaved(void) {
    setFriendliesSaved(1 - getObjectiveCount(0x73));
    return 0;
}

s32 lva_checkComplexObjectives(void) {
    if (getObjectiveCount(0x63) >= 6) {
        setHudEnableBit8();
        playObjectiveVoiceLine2(0x21DU, 0.0f);
    }
    if (getObjectiveCount(0x33) >= 0xA) {
        setHudEnableBit4();
        playObjectiveVoiceLine2(0x55U, 0.0f);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/level_objective_handling/lv_a", fake_func_8010619C);

// DO NOT DELETE ME I AM REQUIRED FOR MATCHING
const u32 rodata_pad_lv_a[] = {
    0x00000000,
    0x45000009,
    0x00000000,
};
