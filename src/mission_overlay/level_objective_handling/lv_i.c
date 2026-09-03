#include "common.h"

#include "mission_overlay/0C7EB0.h"
#include "mission_overlay/0C84A0.h"
#include "mission_overlay/level_objective_handling/lv_i.h"

s32 D_mission_overlay_8010D1E0;
s32 D_mission_overlay_8010D1E4;
s32 D_mission_overlay_8010D1E8;
s32 D_mission_overlay_8010D1EC;

s32 lvi_checkComplexObjectives(void) {
    s32 temp_v0;

    if ((getDatItemHealth("reb_generator") < 0x41) && (D_mission_overlay_8010D1E4 == 0)) {
        setHudEnableBit4();
        D_mission_overlay_8010D1E4 = 1;
        setHudFlagBit40AndStoreArg("camera_fail");
        playObjectiveVoiceLine2(0x11U, 0.0f);
        playObjectiveVoiceLine2(6U, 0.0f);
        addTimerHandleWrapper(func_mission_overlay_801090CC, 5.0f);
    }
    temp_v0 = getObjectiveBoolean(7);
    if ((temp_v0 == 1) && (D_mission_overlay_8010D1E4 == 0)) {
        setHudEnableBit4();
        D_mission_overlay_8010D1E4 = temp_v0;
        setHudFlagBit40AndStoreArg("camera_fail");
        playObjectiveVoiceLine2(0x11U, 0.0f);
        playObjectiveVoiceLine2(6U, 0.0f);
        addTimerHandleWrapper(func_mission_overlay_801090F0, 5.0f);
    }
    if ((getObjectiveCount(4) == 8) && (D_mission_overlay_8010D1EC == 0)) {
        setHudEnableBit8();
        setHudFlagBit40AndStoreArg("camera_win_cut_1");
        playObjectiveVoiceLine2(0x2BEU, 0.0f);
        playObjectiveVoiceLine2(0x2BFU, 1.0f);
        activateObjectiveCompleteFlag(3);
        triggerSoundCueByType(7);
        D_mission_overlay_8010D1EC = 1;
    }
    return 0;
}

void func_mission_overlay_801090CC(void) {
    dealDamagetoDatItem("reb_generator", 0x42U);
}

void func_mission_overlay_801090F0(void) {
    dealDamagetoDatItem("reb_generator", 0x321U);
}

s32 lvi_initializeObjectTracking(void) {
    D_mission_overlay_8010D1E4 = 0;
    D_mission_overlay_8010D1E8 = 0;
    D_mission_overlay_8010D1EC = 0;
    D_mission_overlay_8010D1E0 = 0;
    addBooleanCountHandleWrapper(func_mission_overlay_80109208, 0, 0, 2, 3);
    addBooleanCountHandleWrapper(func_mission_overlay_80109384, 0, 0, 3, 4);
    addBooleanCountHandleWrapper(func_mission_overlay_801092E4, 0, 0, 3, 6);
    addBooleanCountHandleWrapper(func_mission_overlay_801093DC, 6, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_801093B0, 0, 0, 4, 4);
    playObjectiveVoiceLine2(0x2BCU, 0.0f);
    return 0;
}

s32 lvi_801091F8(void) {
    return 0;
}

s32 lvi_calculateFriendliesSaved(void) {
    return 0;
}

void func_mission_overlay_80109208(void) {
    addTimerHandleWrapper(func_mission_overlay_8010922C, 3.0f);
}

void func_mission_overlay_8010922C(void) {
    setHudFlagBit40AndStoreArg("Camera_on_ATAT");
    playObjectiveVoiceLine2(0x126U, 1.5f);
    playObjectiveVoiceLine2(0x127U, 0.0f);
    playObjectiveVoiceLine2(0x137U, 2.0f);
    activateObjectiveCompleteFlag(2);
    initAnchoredActorTowardNamedDatItem("wingman_speeder1", "wingman_to_big_battle");
    initAnchoredActorTowardNamedDatItem("wingman_speeder2", "wingman_to_big_battle");
    D_mission_overlay_8010D1E8 = 1;
    setObjectiveBoolean(0x78, 1U);
    D_mission_overlay_8010D1E0 = 2;
    delegateToLevelStageTick("MUSICRNG_LevelSettings", 2);
    triggerSoundCueByType(4);
}

void func_mission_overlay_801092E4(void) {
    addTimerHandleWrapper(func_mission_overlay_80109324, 5.0f);
    D_mission_overlay_8010D1E0 = 1;
    delegateToLevelStageTick("MUSICRNG_LevelSettings", 1);
}

const u8 lv_i_camera_on_rogue[24] = {
    "Camera_on_Rogue\0\x8c\xc6\0 \x8c\xe7\0$"
};

void func_mission_overlay_80109324(void) {
    setHudFlagBit40AndStoreArg(lv_i_camera_on_rogue);
    playObjectiveVoiceLine2(0x2BDU, 1.0f);
    playObjectiveVoiceLine2(0x11AU, 0.0f);
    playObjectiveVoiceLine2(0x11BU, 0.0f);
    activateObjectiveCompleteFlag(1);
    triggerSoundCueByType(3);
}

void func_mission_overlay_80109384(void) {
    playObjectiveVoiceLine2(0x21CU, 0.5f);
    playObjectiveVoiceLine2(0x13EU, 0.0f);
}

void func_mission_overlay_801093B0(void) {
    playObjectiveVoiceLine2(0x230U, 0.5f);
    playObjectiveVoiceLine2(0x13AU, 0.0f);
}

void func_mission_overlay_801093DC(void) {
    if ((D_mission_overlay_8010D1E8 == 0) && (getObjectiveCount(3) == 6)) {
        D_mission_overlay_8010D1E8 = 1;
        playObjectiveVoiceLine2(0x226U, 0.0f);
    }
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/level_objective_handling/lv_i", fake_func_80109428);
