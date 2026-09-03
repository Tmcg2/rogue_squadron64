#include "common.h"

#include "mission_overlay/0C7EB0.h"
#include "mission_overlay/0C84A0.h"
#include "mission_overlay/level_objective_handling/lv_c.h"

f32 D_mission_overlay_8010D140;
s32 D_mission_overlay_8010D144;
s32 D_mission_overlay_8010D148;

s32 lvc_initializeObjectTracking(void) {
    D_mission_overlay_8010D140 = 0;
    D_mission_overlay_8010D144 = 0;
    D_mission_overlay_8010D148 = 1;
    setLevelObjectTrackingScalar(7.5f);
    addBooleanCountHandleWrapper(func_mission_overlay_80106F80, 0xB, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_80106FC4, 0, 0, 0xA, 2);
    addBooleanCountHandleWrapper(func_mission_overlay_80106FF4, 0x3D, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_8010715C, 0x61, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_80107124, 0xC, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_801070C8, 0, 0, 0x20, 1);
    addBooleanCountHandleWrapper(func_mission_overlay_80107070, 0, 0, 0x28, 3);
    addBooleanCountHandleWrapper(func_mission_overlay_80107190, 0x4D, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_801071C8, 0x5C, 1, 0, 0);
    return 0;
}

s32 lvc_checkComplexObjectives(f32 arg0) {
    if (getObjectiveBoolean(0x51) == 1) {
        setHudEnableBit4();
        playObjectiveVoiceLine2(0x5DU, 0.0f);
        playObjectiveVoiceLine2(0x14BU, 0.0f);
    }
    if (getObjectiveCount(0x14) >= 7) {
        setHudEnableBit4();
        playObjectiveVoiceLine2(0x5DU, 0.0f);
        playObjectiveVoiceLine2(0x14BU, 0.0f);
    }
    if (getObjectiveCount(0x1F) >= 3) {
        setHudEnableBit4();
        playObjectiveVoiceLine2(0x5DU, 0.0f);
        playObjectiveVoiceLine2(0x14BU, 0.0f);
    }
    if (getObjectiveCount(0xA) >= 4) {
        setHudEnableBit4();
        playObjectiveVoiceLine2(0x1D0U, 0.0f);
    }
    if ((getObjectiveCount(0x20) > 0) && (getObjectiveCount(0x1E) >= 3) && (getObjectiveBoolean(0x61) == 1)) {
        setHudEnableBit8();
    }
    if (D_mission_overlay_8010D148 != 0) {
        func_mission_overlay_80106E94(arg0);
    }
    return 0;
}

const u8 lv_c_city_cam_01[] = {
    "City_Cam_01"
};

const u8 lv_c_musicrng_levelsettings[] = {
    "MUSICRNG_LevelSettings"
};

const u8 lv_8_camera_at_st[] = {
    "Camera_AT_ST"
};

const u8 lv_8_city_cam_02[] = {
    "City_Cam_02"
};

const u8 lv_8_train_engine[] = {
    "Train_Engine"
};

const u8 lv_8_train_cargo_02[] = {
    "Train_Cargo_02"
};

const u8 lv_8_train_cargo_01[] = {
    "Train_Cargo_01"
};

void func_mission_overlay_80106E94(f32 arg0) {
    f32 temp_fv0;

    if (getObjectiveCount(0x78) == 0) {
        temp_fv0 = calculateDatItemDistanceToPlayer(lv_8_train_cargo_02);
    } else if (getObjectiveCount(0x79) == 0) {
        temp_fv0 = calculateDatItemDistanceToPlayer(lv_8_train_cargo_01);
    } else {
        temp_fv0 = calculateDatItemDistanceToPlayer(lv_8_train_engine);
    }
    if (temp_fv0 < 20.0f) {
        if (D_mission_overlay_8010D144 == 0) {
            D_mission_overlay_8010D144 = 1;
            delegateToLevelStageTick(lv_c_musicrng_levelsettings, 1);
        }
        D_mission_overlay_8010D140 = 10.0f;
    } else if (D_mission_overlay_8010D144 != 0) {
        D_mission_overlay_8010D140 -= arg0;
        if (D_mission_overlay_8010D140 <= 0.0f) {
            D_mission_overlay_8010D144 = 0;
            delegateToLevelStageTick(lv_c_musicrng_levelsettings, 0);
        }
    }
}

void func_mission_overlay_80106F80(void) {
    playObjectiveVoiceLine2(0x37U, 0.0f);
    playObjectiveVoiceLine2(0x11AU, 0.0f);
    playObjectiveVoiceLine2(0xBFU, 1.5f);
}

void func_mission_overlay_80106FC4(void) {
    playObjectiveVoiceLine2(0x38U, 0.0f);
    playObjectiveVoiceLine2(0x11AU, 0.2f);
}

void func_mission_overlay_80106FF4(void) {
    addTimerHandleWrapper(func_mission_overlay_80107018, 1.5f);
}

void func_mission_overlay_80107018(void) {
    setHudFlagBit40AndStoreArg(lv_c_city_cam_01);
    playObjectiveVoiceLine2(0x1D1U, 0.0f);
    triggerSoundCueByType(4);
    setObjectiveBoolean(0x78, 1U);
    D_mission_overlay_8010D148 = 0;
    delegateToLevelStageTick(lv_c_musicrng_levelsettings, 0);
}

void func_mission_overlay_80107070(void) {
    addTimerHandleWrapper(func_mission_overlay_80107094, 1.5f);
}

void func_mission_overlay_80107094(void) {
    setHudFlagBit40AndStoreArg(lv_8_camera_at_st);
    playObjectiveVoiceLine2(0x2CAU, 5.0f);
    triggerSoundCueByType(3);
}

void func_mission_overlay_801070C8(void) {
    addTimerHandleWrapper(func_mission_overlay_801070F0, 0.2f);
}

void func_mission_overlay_801070F0(void) {
    setHudFlagBit40AndStoreArg(lv_8_city_cam_02);
    playObjectiveVoiceLine2(0x2A5U, 0.0f);
    triggerSoundCueByType(4);
}

void func_mission_overlay_80107124(void) {
    playObjectiveVoiceLine2(0x1E6U, 0.0f);
    playObjectiveVoiceLine2(0x256U, 0.0f);
}

void func_mission_overlay_8010715C(void) {
    spawnEffectOnNamedDatItem(lv_8_train_engine, 0.0f, 0, 2.0f);
    activateObjectiveCompleteFlag(1);
}

void func_mission_overlay_80107190(void) {
    playObjectiveVoiceLine2(0xABU, 0.0f);
    playObjectiveVoiceLine2(0x11BU, 0.0f);
}

void func_mission_overlay_801071C8(void) {
    playObjectiveVoiceLine2(0x296U, 0.0f);
}

s32 lvc_801071E8(void) {
    return 0;
}

s32 lvc_calculateFriendliesSaved(void) {
    setFriendliesSaved(4 - getObjectiveCount(0xA));
    return 0;
}

// DO NOT DELTE ME I AM REQUIRED FOR MATCHING
const u32 rodata_pad_lv_c = 0x9064002F;

INCLUDE_ASM("asm/nonmatchings/mission_overlay/level_objective_handling/lv_c", fake_func_8010721C);
