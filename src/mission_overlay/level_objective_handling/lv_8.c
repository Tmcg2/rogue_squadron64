#include "common.h"

#include "mission_overlay/0C7EB0.h"
#include "mission_overlay/0C84A0.h"
#include "mission_overlay/level_objective_handling/lv_8.h"

s32 D_mission_overlay_8010D0B0;
s32 D_mission_overlay_8010D0B4;
s32 D_mission_overlay_8010D0B8;
s32 D_mission_overlay_8010D0BC;
s32 D_mission_overlay_8010D0C0;
s32 D_mission_overlay_8010D0C4;
f32 D_mission_overlay_8010D0C8;

const u8 lv_8_musicrng_levelsettings[] = {
    "MUSICRNG_LevelSettings"
};

const u8 lv_8_train_1_engine[] = {
    "train_1_engine"
};

const u8 lv_8_imp_trans2[] = {
    "imp_trans2"
};

const u8 lv_8_camera1[] = {
    "camera1"
};

s32 lv8_checkComplexObjectives(f32 arg0) {
    s32 temp_v0;
    s32 temp_v0_2;

    if ((calculateDatItemDistanceToPlayer(lv_8_train_1_engine) <= 15.0f) && (D_mission_overlay_8010D0B0 == 0)) {
        D_mission_overlay_8010D0B0 = 1;
        setObjectiveBoolean(8, 1U);
        setObjectiveHiddenFlag(0, 1);
        playObjectiveVoiceLine2(0x15AU, 0.0f);
        playObjectiveVoiceLine2(0x266U, 2.0f);
        D_mission_overlay_8010D0C4 = 1;
    }
    if ((calculateDatItemDistanceToPlayer(lv_8_imp_trans2) <= 10.0f) && (D_mission_overlay_8010D0B4 == 0)) {
        D_mission_overlay_8010D0B4 = 1;
        setObjectiveBoolean(6, 1U);
        playObjectiveVoiceLine2(0x158U, 0.0f);
        playObjectiveVoiceLine2(0x265U, 2.0f);
        playObjectiveVoiceLine2(0xE2U, 0.0f);
    }
    temp_v0 = getObjectiveBoolean(5);
    if ((temp_v0 == 1) && (D_mission_overlay_8010D0B8 == 0)) {
        D_mission_overlay_8010D0B8 = temp_v0;
        setHudEnableBit4();
        setHudFlagBit40AndStoreArg(lv_8_camera1);
        playObjectiveVoiceLine2(0x267U, 0.0f);
        spawnEffectOnNamedDatItem(lv_8_train_1_engine, 0.05f, 0, 5.0f);
        triggerSoundCueByType(6);
    }
    temp_v0_2 = getObjectiveCount(3);
    if ((temp_v0_2 == 1) && (D_mission_overlay_8010D0B8 == 0)) {
        D_mission_overlay_8010D0B8 = temp_v0_2;
        setHudEnableBit4();
        playObjectiveVoiceLine2(0x15FU, 0.0f);
        playObjectiveVoiceLine2(0xFDU, 2.0f);
    }
    if ((getObjectiveCount(5) == 7) && (D_mission_overlay_8010D0BC == 0)) {
        D_mission_overlay_8010D0BC = 1;
        setHudEnableBit8();
        activateObjectiveCompleteFlag(1);
        activateObjectiveCompleteFlag(2);
        spawnEffectOnNamedDatItem(lv_8_train_1_engine, 0.025f, 0, 5.0f);
        playObjectiveVoiceLine2(0x11EU, 1.0f);
        playObjectiveVoiceLine2(0x277U, 0.0f);
    }
    func_mission_overlay_80104CCC(arg0);
    return 0;
}

void func_mission_overlay_80104CCC(f32 arg0) {
    f32 temp_fv0;

    if (D_mission_overlay_8010D0C4 != 0) {
        if (calculateDatItemDistanceToPlayer("train_4_cargo") < 17.0f) {
            if (D_mission_overlay_8010D0C0 == 0) {
                D_mission_overlay_8010D0C0 = 1;
                delegateToLevelStageTick(lv_8_musicrng_levelsettings, 1);
            }
            D_mission_overlay_8010D0C8 = 5.0f;
            return;
        }
        if (D_mission_overlay_8010D0C0 != 0) {
            D_mission_overlay_8010D0C8 -= arg0;
            if (D_mission_overlay_8010D0C8 <= 0.0f) {
                D_mission_overlay_8010D0C0 = 0;
                delegateToLevelStageTick(lv_8_musicrng_levelsettings, 0);
            }
        }
    }
}

s32 lv8_initializeObjectTracking(void) {
    D_mission_overlay_8010D0B0 = 0;
    D_mission_overlay_8010D0B4 = 0;
    D_mission_overlay_8010D0B8 = 0;
    D_mission_overlay_8010D0BC = 0;
    D_mission_overlay_8010D0C0 = 0;
    D_mission_overlay_8010D0C4 = 0;
    D_mission_overlay_8010D0C8 = 0;
    addBooleanCountHandleWrapper(func_mission_overlay_80104EC8, 0xA, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_80104EE4, 0xC, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_80104F00, 0xE, 1, 0, 0);
    addBooleanCountHandleWrapper(func_mission_overlay_80104F1C, 0, 0, 5, 2);
    setObjectiveHiddenFlag(1, 1);
    func_mission_overlay_80104F6C();
    return 0;
}

s32 lv8_80104E64(void) {
    D_mission_overlay_8010D0C8 = 0;
    D_mission_overlay_8010D0C0 = 0;
    triggerNamedAssetCue(lv_8_musicrng_levelsettings, 0);
    return 0;
}

s32 lv8_calculateFriendliesSaved(void) {
    setFriendliesSaved(6 - getObjectiveCount(6));
    return 0;
}

void func_mission_overlay_80104EC8(void) {
    playObjectiveVoiceLine1(0x107U);
}

void func_mission_overlay_80104EE4(void) {
    playObjectiveVoiceLine1(0xCCU);
}

void func_mission_overlay_80104F00(void) {
    playObjectiveVoiceLine1(0xE4U);
}

void func_mission_overlay_80104F1C(void) {
    playObjectiveVoiceLine2(0x26CU, 0.0f);
    playObjectiveVoiceLine2(0x15CU, 0.0f);
    spawnEffectOnNamedDatItem(lv_8_train_1_engine, 0.5f, 0, 5.0f);
}

void func_mission_overlay_80104F6C(void) {
    D_mission_overlay_8010D0C0 = 0;
    D_mission_overlay_8010D0C4 = 0;
}

// DO NOT DELETE ME I AM REQUIRED FOR MATCHING
const f32 rodata_pad_lv_8 = 9512.0f;
