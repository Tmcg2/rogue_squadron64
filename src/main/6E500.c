#include "common.h"

#include "main/6E500.h"
#include "common_types.h"
#include "common_variables.h"

s32 D_main_800A0A60 = -1;

INCLUDE_ASM("asm/nonmatchings/main/6E500", runIdleFramesAndLoadSaveData);

INCLUDE_ASM("asm/nonmatchings/main/6E500", applySaveSlotToMissionState);

void loadDefaultHighScores(void) {
    s8 var_a3;

    for (var_a3 = 0; var_a3 < 10; var_a3++) {
        gSaveDataBody.highscores[var_a3].name[0] = defaultHighscoreNames[var_a3][0];
        gSaveDataBody.highscores[var_a3].name[1] = defaultHighscoreNames[var_a3][1];
        gSaveDataBody.highscores[var_a3].name[2] = defaultHighscoreNames[var_a3][2];
        gSaveDataBody.highscores[var_a3].medals.as_short = 9 - var_a3;
        gSaveDataBody.highscores[var_a3].current_level = 9 - var_a3;
    }
}

// The placement of this array is EXTERMELY precise
// The short story is that, seemingly, the pointers of this array end up in the .text
// section of the output, even though small .data has (ostensibly) disabled via -G0
char *defaultHighscoreNames[0xA] = { "FLO", "HOL", "TOM", "JUE", "THG", "SIR", "MAR", "BST", "RFH", "CHR" };

INCLUDE_ASM("asm/nonmatchings/main/6E500", highScoreBubbleSort);

INCLUDE_ASM("asm/nonmatchings/main/6E500", applyAccountUnlocksToSettings);

INCLUDE_ASM("asm/nonmatchings/main/6E500", serializeSettingsToSaveAndPersist);

INCLUDE_ASM("asm/nonmatchings/main/6E500", setUnlockBitAndPersist);

INCLUDE_ASM("asm/nonmatchings/main/6E500", applyVolumeSettingsToMixer);

INCLUDE_ASM("asm/nonmatchings/main/6E500", resetGameSettingsAndMissionStats);

INCLUDE_ASM("asm/nonmatchings/main/6E500", generateUnlockString);

INCLUDE_ASM("asm/nonmatchings/main/6E500", getActiveAccountsBitmask);

INCLUDE_ASM("asm/nonmatchings/main/6E500", getAccountUnk51);

INCLUDE_ASM("asm/nonmatchings/main/6E500", createAccountProfile);

INCLUDE_ASM("asm/nonmatchings/main/6E500", initPlayerMissionStateFromSettings);

void initializeNumLives(void) {
    u8 var_v1;

    for (var_v1 = 0; var_v1 < 1; var_v1++) {
        gMissionState.numLives[var_v1] = 3;
    }
}

INCLUDE_ASM("asm/nonmatchings/main/6E500", loadAccountDataIntoStruct);

INCLUDE_ASM("asm/nonmatchings/main/6E500", parseAccountDataBytes);

INCLUDE_ASM("asm/nonmatchings/main/6E500", packAccountProgressBits);

INCLUDE_ASM("asm/nonmatchings/main/6E500", getSaveScratchBufferPtr);

INCLUDE_ASM("asm/nonmatchings/main/6E500", findUnusedAccountId);

INCLUDE_ASM("asm/nonmatchings/main/6E500", resetSettingsClearSaveAndReload);

INCLUDE_ASM("asm/nonmatchings/main/6E500", initIdleDemoTimersAndSave);

INCLUDE_ASM("asm/nonmatchings/main/6E500", resetMixerVolumesAndFlags);

INCLUDE_ASM("asm/nonmatchings/main/6E500", isUnlockBitSet);

INCLUDE_ASM("asm/nonmatchings/main/6E500", gatherActiveUnlockFlags);

INCLUDE_ASM("asm/nonmatchings/main/6E500", syncMissionUnlockBitsToSettings);

void unlockMissleUpgradeOnLevelCompletion(u8 levelId) {
    if (levelId == GERRARDV_LEVEL) {
        gGameSettings.unlockAndSettingsFlags[0] |= 0x1000;
    }
    if (levelId == KESSEL_PRISON_LEVEL) {
        gGameSettings.unlockAndSettingsFlags[0] |= 0x400;
    }
}

INCLUDE_ASM("asm/nonmatchings/main/6E500", getAccountDataPtr);

INCLUDE_ASM("asm/nonmatchings/main/6E500", copyAccountRecordAndMarkActive);

INCLUDE_ASM("asm/nonmatchings/main/6E500", clearAccountRecordAndMarkInactive);

INCLUDE_ASM("asm/nonmatchings/main/6E500", registerSaveService);

INCLUDE_ASM("asm/nonmatchings/main/6E500", stopSaveServiceWorker);

INCLUDE_ASM("asm/nonmatchings/main/6E500", isViModeTypePal);

INCLUDE_ASM("asm/nonmatchings/main/6E500", cycleIdleDemoId);

INCLUDE_ASM("asm/nonmatchings/main/6E500", classifySaveStateFromInput);

INCLUDE_ASM("asm/nonmatchings/main/6E500", loadSaveDataIfNotLoaded);

INCLUDE_ASM("asm/nonmatchings/main/6E500", persistSaveDataBody);

INCLUDE_ASM("asm/nonmatchings/main/6E500", triggerSaveMessage);

INCLUDE_ASM("asm/nonmatchings/main/6E500", saveServiceWorker);

INCLUDE_ASM("asm/nonmatchings/main/6E500", isSaveStateNotPending);

void setAccountHighscore(u8 arg0, u16 arg1, u8 levelId) {
    gSaveDataBody.highscores[arg0].name[0] = gGameSettings.name[0];
    gSaveDataBody.highscores[arg0].name[1] = gGameSettings.name[1];
    gSaveDataBody.highscores[arg0].name[2] = gGameSettings.name[2];
    gSaveDataBody.highscores[arg0].current_level = levelId;
    gSaveDataBody.highscores[arg0].medals.as_short = arg1;
    gSaveDataBody.highscores[arg0].accountNumber = gMissionState.accountNumber;
}

INCLUDE_ASM("asm/nonmatchings/main/6E500", getAccountHighscore);

s32 getSecondaryWeaponCount(u8 craftId, u8 arg1) {
    s32 count;

    count = 0;
    switch (craftId) {
    case XWING_CRAFT:
        count = 6;
        if (arg1 == ION_CANNON) {
            count = 0xFF;
        }
        break;
    case YWING_CRAFT:
        count = 0x14;
        break;
    case VWING_CRAFT:
    case SNOWSPEEDER_CRAFT:
        count = 6;
        break;
    case FALCON_CRAFT:
        count = 0xF;
        break;
    case AWING_CRAFT:
    case TIEINTER_CRAFT:
        count = 8;
        break;
    case T16_CRAFT:
        count = 0xFF;
        break;
    case KOELSCH_CRAFT:
        count = 0xA;
        break;
    }
    return count;
}

INCLUDE_ASM("asm/nonmatchings/main/6E500", fake_func_8006F4AC);

// DO NOT DELTE ME, I'M REQUIRED FOR MATCHING
u32 data_junk = 0x03A0F021;
