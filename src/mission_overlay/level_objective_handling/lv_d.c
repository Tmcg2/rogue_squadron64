#include "common.h"

#include "mission_overlay/0C7EB0.h"
#include "mission_overlay/0C84A0.h"
#include "mission_overlay/level_objective_handling/lv_d.h"

s32 D_mission_overlay_8010D150;

const u8 lv_d_camera_01[] = {
    "Camera_01"
};

const u8 lv_d_musicrng_levelsettings[] = {
    "MUSICRNG_LevelSettings"
};

s32 lvd_initializeObjectTracking(void) {
    D_mission_overlay_8010D150 = 0;
    setLevelObjectTrackingScalar(7.5f);
    addBooleanCountHandleWrapper(func_mission_overlay_80107338, 0, 0, 0x32, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_80107354, 0, 0, 0x64, 1);
    return 0;
}

s32 lvd_80107290(void) {
    return 0;
}

s32 lvd_calculateFriendliesSaved(void) {
    return 0;
}

s32 lvd_checkComplexObjectives(void) {
    if (getObjectiveCount(0x3C) > 0) {
        setHudEnableBit8();
    }
    if ((getObjectiveCount(0x32) == 0xC) && (D_mission_overlay_8010D150 == 0)) {
        D_mission_overlay_8010D150 = 1;
        setHudFlagBit40AndStoreArg(lv_d_camera_01);
        activateObjectiveCompleteFlag(1);
        playObjectiveVoiceLine2(0xF5U, 0.0f);
        playObjectiveVoiceLine2(0x172U, 0.5f);
        delegateToLevelStageTick(lv_d_musicrng_levelsettings, 0);
        triggerSoundCueByType(3);
    }
    return 0;
}

void func_mission_overlay_80107338(void) {
    playObjectiveVoiceLine1(0x171U);
}

void func_mission_overlay_80107354(void) {
    playObjectiveVoiceLine1(0x2F2U);
}

// DO NOT DELTE ME I AM REQUIRED FOR MATCHING
const u32 rodata_pad_lv_d[] = {
    0x4600020D,
    0x44034000,
};
