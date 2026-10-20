#include "common.h"

#include "mission_stats.h"

#include "main/bss_80130B10.h"
#include "main/84830.h"
#include "mission_overlay/0BF800.h"
#include "mission_overlay/0EDD50.h"
#include "mission_overlay/0FAE50.h"

// BSS stuff, for when its matchable
// f32 D_mission_overlay_8010C9EC;
// s32 D_mission_overlay_8010CA20;

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FAE50", func_mission_overlay_800FA250);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FAE50", func_mission_overlay_800FA6A4);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FAE50", flashMissionAlertObjectsAndPrint);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FAE50", beginMissionEndTransition);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FAE50", endMissionEndTransition);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FAE50", requestMissionTransitionMode);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FAE50", setupMissionTransitionScreenOverlay);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FAE50", tickMissionTransitionAndTeardown);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0FAE50", D_mission_overlay_800A8FE4);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0FAE50", D_mission_overlay_800A8FEC);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0FAE50", D_mission_overlay_800A8FF0);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0FAE50", D_mission_overlay_800A8FFC);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0FAE50", D_mission_overlay_800A9004);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0FAE50", D_mission_overlay_800A9010);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0FAE50", D_mission_overlay_800A9018);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0FAE50", D_mission_overlay_800A9020);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0FAE50", D_mission_overlay_800A9028);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FAE50", choosePlayerCraftAssets);

void endMissionCleanup(void) {
    missionStats.completion_time = D_main_bss_80130BA4;
    stopAllMusicWithFade(0.8f);
    resetSpeechSubsystem();
    finalizeCurrentSpeechBuffer();
    freeSubtitleOverlay();
    freeEffectAssetBuffers();
    missionCleanupNoopHook();
    freeTxtFile();
    destroyNpcContextArrays();
    freeNpcBurstSpawnerTables();
    teardownAudioListenerNode();
    waitForAnyAudioSlot();
    freeAnimationPhasePool();
    freeAllHobFiles();
    freeNpcSlotArray();
    freeLevelDatBuffers();
    teardownAnimatedMapGridLayer();
    stopMusicAndResetAudio();
    reset_and_free_model_animations();
    calculateFriendliesSaved();
    freeAllObjectContextPoolNodes();
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FAE50", requestSpeechResponseMode2);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FAE50", requestSpeechResponseMode1);

void func_mission_overlay_800FBBA0(void) {
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FAE50", func_mission_overlay_800FBBA8);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FAE50", func_mission_overlay_800FBC4C);

s32 clearMissionObjectiveFlagsAndEnterPhaseSix(void) {
    s32 var_a2;
    union ControllerSettings *var_a1;

    for (var_a2 = 0; var_a2 < 1; var_a2++) {
        D_mission_overlay_8010BFA8[var_a2] &= ~D_mission_overlay_8010BE18[var_a2].asStruct.fire_blasters;
    }
    if (D_mission_overlay_8010CA20 != 6) {
        D_mission_overlay_8010CA20 = 6;
        playSimpleAudioCmd(0U, 0x3E8U, 0xFFU);
        D_mission_overlay_8010C9EC = 1.1f;
    }
    return 1;
}

s32 advanceMissionObjectiveStageWhenModeOne(void) {
    if (D_mission_overlay_8010CA20 == 1) {
        stopAllMusicWithFade(0.75f);
        D_mission_overlay_8010C9F0 += 1;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FAE50", fake_func_800FBE14);

// DO NOT DELETE ME I AM REQUIRED FOR MATCHING
const u32 rodata_pad_0FAE50[] = {
    0x3C018005,
    0xC420FED0,
};
