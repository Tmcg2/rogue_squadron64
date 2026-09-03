#include "common.h"

#include "mission_overlay/0C7EB0.h"
#include "mission_overlay/0C84A0.h"
#include "mission_overlay/level_objective_handling/lv_3.h"

s32 D_mission_overlay_8010D050;
s32 D_mission_overlay_8010D054;

s32 lv3_initializeObjectTracking(void) {
    D_mission_overlay_8010D050 = 0;
    D_mission_overlay_8010D054 = 0;
    setLevelObjectTrackingScalar(7.5f);
    addBooleanCountHandleWrapper(func_mission_overlay_80103360, 0, 0, 0x19, 2);
    addBooleanCountHandleWrapper(func_mission_overlay_80103424, 0x1A, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_80103464, 0x1C, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_80103340, 0, 0, 0x12, 2);
    addBooleanCountHandleWrapper(func_mission_overlay_80103110, 0, 0, 5, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_80102F34, 0, 0, 0x1D, 6);
    addBooleanCountHandleWrapper(func_mission_overlay_80103010, 0, 0, 3, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_801030B8, 0, 0, 4, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_801030F0, 0, 0, 0xA, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_801032B4, 0, 0, 0xE, 4);
    addBooleanCountHandleWrapper(func_mission_overlay_801032F0, 0x11, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_8010313C, 0, 0, 0x13, 8);
    addBooleanCountHandleWrapper(func_mission_overlay_801033EC, 0, 0, 0x15, 2);
    addBooleanCountHandleWrapper(func_mission_overlay_8010349C, 0x24, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_801034C0, 0x25, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_801034E4, 0x26, 1, 0, 0);
    setObjectiveHiddenFlag(1, 1);
    setObjectiveHiddenFlag(1, 2);
    setObjectiveHiddenFlag(1, 3);
    setObjectiveHiddenFlag(1, 4);
    addBooleanCountHandleWrapper(func_mission_overlay_80103508, 0, 0, 0x6F, 3);
    return 0;
}

s32 lv3_checkComplexObjectives(void) {
    if ((getObjectiveBoolean(4) > 0) && (D_mission_overlay_8010D050 == 0)) {
        D_mission_overlay_8010D050 = 1;
        setHudEnableBit4();
        dealDamagetoDatItem("Han_Solo_Stationary", 0x1869F);
        dealDamagetoDatItem("Rieekan_Shuttle_Stationary", 0x1869F);
        playObjectiveVoiceLine2(0x140U, 0.0f);
        playObjectiveVoiceLine2(0x14BU, 0.5f);
    }
    if ((getObjectiveBoolean(0x12) > 0) && (D_mission_overlay_8010D050 == 0)) {
        D_mission_overlay_8010D050 = 1;
        setHudEnableBit4();
        playObjectiveVoiceLine2(0x237U, 0.0f);
        playObjectiveVoiceLine2(6U, 0.0f);
        playObjectiveVoiceLine2(0x5DU, 0.5f);
    }
    if (getObjectiveCount(0x16) > 0) {
        activateObjectiveCompleteFlag(2);
        activateObjectiveCompleteFlag(3);
        activateObjectiveCompleteFlag(4);
        setHudEnableBit8();
        playObjectiveVoiceLine2(7U, 0.0f);
    }
    if ((getObjectiveBoolean(0x15) > 0) && (D_mission_overlay_8010D050 == 0)) {
        D_mission_overlay_8010D050 = 1;
        setHudEnableBit4();
        playObjectiveVoiceLine2(0x56U, 0.0f);
        playObjectiveVoiceLine2(0x5DU, 0.5f);
    }
    return 0;
}

// All this futzing about with these strings is to tickle the compiler
// into putting them in the correct order. I can only speculate 2 reasons for this being necessary:
// 1) I'm using the wrong compiler and/or flags
// 2) The compiler orders string constants like this based on the name/hash of the function they belong too

const u8 camera_gvt_bldg[] = {
    "Camera_Gvt_Bldg"
};

const u8 camera_cm_1[] = {
    "Camera_CM_1"
};

const u8 camera_solo_new[] = {
    "Camera_Solo_New"
};

const u8 camera_hl_shuttle[] = {
    "Camera_HL_Shuttle"
};

const u8 gvt_bldg_main[] = {
    "GVT_BLDG_main"
};

const u8 tech_center_main[] = {
    "Tech_Center_Main"
};

void func_mission_overlay_80102E50(void) {
    setObjectiveBoolean(0xB, 1U);
    setObjectiveBoolean(0xC, 1U);
    setHudFlagBit40AndStoreArg(camera_solo_new);
    playObjectiveVoiceLine2(0x1E8U, 0.0f);
    playObjectiveVoiceLine2(0x1E6U, 0.0f);
    playObjectiveVoiceLine2(0x156U, 0.0f);
    playObjectiveVoiceLine2(0x8DU, 1.0f);
    playObjectiveVoiceLine2(1U, 0.0f);
    playObjectiveVoiceLine2(0x13DU, 0.0f);
    playObjectiveVoiceLine2(0x8EU, 0.0f);
    addTimerHandleWrapper(func_mission_overlay_80103268, 15.0f);
    addTimerHandleWrapper(func_mission_overlay_80103248, 16.0f);
    addTimerHandleWrapper(func_mission_overlay_80103444, 20.0f);
    setObjectiveBoolean(0x6F, 0U);
    addTimerHandleWrapper(func_mission_overlay_8010322C, 6.0f);
}

void func_mission_overlay_80102F34(void) {
    addTimerHandleWrapper(func_mission_overlay_80102F58, 3.0f);
}

void func_mission_overlay_80102F58(void) {
    increaseObjectiveCount(1, 6);
    setObjectiveBoolean(6, 1U);
    setObjectiveBoolean(0x27, 1U);
    setHudFlagBit40AndStoreArg(camera_gvt_bldg);
    playObjectiveVoiceLine2(0x5AU, 0.5f);
    playObjectiveVoiceLine2(0x235U, 0.0f);
    increaseObjectiveCount(0xD, 1);
    addTimerHandleWrapper(func_mission_overlay_80102FF0, 2.0f);
    activateObjectiveCompleteFlag(1);
    setObjectiveHiddenFlag(0, 2);
    setObjectiveBoolean(0x6E, 1U);
}

void func_mission_overlay_80102FF0(void) {
    setObjectiveBoolean(6, 0U);
}

void func_mission_overlay_80103010(void) {
    playObjectiveVoiceLine2(0x101U, 0.0f);
    addTimerHandleWrapper(func_mission_overlay_8010304C, 6.0f);
    setObjectiveBoolean(0x21, 1U);
}

void func_mission_overlay_8010304C(void) {
    setObjectiveHiddenFlag(0, 1);
    playObjectiveVoiceLine2(0x28DU, 0.0f);
    playObjectiveVoiceLine2(0x11AU, 0.2f);
    playObjectiveVoiceLine2(0x103U, 0.0f);
    playObjectiveVoiceLine2(0x1EFU, 0.0f);
    increaseObjectiveCount(0xC, 1);
}

void func_mission_overlay_801030B8(void) {
    playObjectiveVoiceLine2(0x275U, 0.0f);
    playObjectiveVoiceLine2(0x234U, 0.0f);
}

void func_mission_overlay_801030F0(void) {
    playObjectiveVoiceLine2(0x233U, 0.0f);
}

void func_mission_overlay_80103110(void) {
    playObjectiveVoiceLine2(0x13CU, 0.0f);
    playObjectiveVoiceLine2(0x5BU, 2.5f);
}

void func_mission_overlay_8010313C(void) {
    addTimerHandleWrapper(func_mission_overlay_80103160, 3.0f);
}

void func_mission_overlay_80103160(void) {
    addTimerHandleWrapper(func_mission_overlay_801031C4, 5.0f);
    playObjectiveVoiceLine2(4U, 0.5f);
    playObjectiveVoiceLine2(0x236U, 0.5f);
    setObjectiveHiddenFlag(0, 3);
    setObjectiveBoolean(0x28, 1U);
}

void func_mission_overlay_801031C4(void) {
    setHudFlagBit40AndStoreArg(camera_cm_1);
    increaseObjectiveCount(0xF, 1);
    setObjectiveBoolean(8, 1U);
    addTimerHandleWrapper(func_mission_overlay_80103288, 8.0f);
    setObjectiveBoolean(0x6E, 0U);
    setObjectiveBoolean(0x6F, 1U);
    triggerSoundCueByType(3);
}

void func_mission_overlay_8010322C(void) {
    triggerSoundCueByType(5);
}

void func_mission_overlay_80103248(void) {
    setObjectiveBoolean(0x1F, 1U);
}

void func_mission_overlay_80103268(void) {
    setObjectiveBoolean(0x10, 1U);
}

void func_mission_overlay_80103288(void) {
    setObjectiveBoolean(9, 1U);
    setObjectiveBoolean(8, 0U);
}

void func_mission_overlay_801032B4(void) {
    playObjectiveVoiceLine2(0x5CU, 0.0f);
    increaseObjectiveCount(0x11, 1);
    addTimerHandleWrapper(func_mission_overlay_80102E50, 5.0f);
}

void func_mission_overlay_801032F0(void) {
    playObjectiveVoiceLine2(3U, 0.0f);
    playObjectiveVoiceLine2(2U, 0.0f);
    playObjectiveVoiceLine2(0x8FU, 0.0f);
    increaseObjectiveCount(0x14, 1);
}

void func_mission_overlay_80103340(void) {
    setObjectiveBoolean(0x11, 1U);
}

void func_mission_overlay_80103360(void) {
    addTimerHandleWrapper(func_mission_overlay_80103384, 3.0f);
}

void func_mission_overlay_80103384(void) {
    setObjectiveBoolean(0x13, 1U);
    setObjectiveBoolean(0x14, 1U);
    increaseObjectiveCount(0x17, 1);
    setHudFlagBit40AndStoreArg(camera_hl_shuttle);
    playObjectiveVoiceLine2(5U, 0.0f);
    increaseObjectiveCount(6, 1);
    setObjectiveBoolean(0x6F, 1U);
}

void func_mission_overlay_801033EC(void) {
    increaseObjectiveCount(0x18, 1);
    playObjectiveVoiceLine2(0x29EU, 0.0f);
    setObjectiveHiddenFlag(0, 4);
}

void func_mission_overlay_80103424(void) {
    playObjectiveVoiceLine2(0x2F3U, 2.0f);
}

void func_mission_overlay_80103444(void) {
    playObjectiveVoiceLine2(0x29FU, 0.0f);
}

void func_mission_overlay_80103464(void) {
    playObjectiveVoiceLine2(0x126U, 0.0f);
    playObjectiveVoiceLine2(0x127U, 0.0f);
}

void func_mission_overlay_8010349C(void) {
    dealDamagetoDatItem(gvt_bldg_main, 0x3A98);
}

void func_mission_overlay_801034C0(void) {
    dealDamagetoDatItem(tech_center_main, 0x32C8);
}

void func_mission_overlay_801034E4(void) {
    dealDamagetoDatItem(gvt_bldg_main, 0x3A98);
}

void func_mission_overlay_80103508(void) {
    setObjectiveBoolean(0x6F, 0U);
}

s32 lv3_80103528(void) {
    return 0;
}

s32 lv3_calculateFriendliesSaved(void) {
    D_mission_overlay_8010D054 = getObjectiveCount(0x1B) + getObjectiveCount(0x1C);
    setFriendliesSaved(0x64 - D_mission_overlay_8010D054);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/level_objective_handling/lv_3", fake_func_8010357C);

// DO NOT DELTE ME I AM REQUIRED FOR MATCHING
const u32 rodata_pad_lv_3 = 0xE4400018;
