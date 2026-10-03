#include "common.h"

#include "controller_settings.h"
#include "demo.h"
#include "game_settings.h"
#include "mission_state.h"
#include "player.h"

#include "main/data_9E9D0.h"
#include "main/bss_80130B10.h"
#include "main/bss_80130BD0.h"
#include "main/04030.h"
#include "main/64EA0.h"
#include "main/6E500.h"
#include "mission_overlay/0BF800.h"
#include "mission_overlay/0FAE50.h"

union ControllerSettings *D_mission_overlay_80109AD0[CONTROLLER_SETTING_NUM] = {
    &LukesControllerSettings,
    &WedgesControllerSettings,
    &JansonsControllerSettings,
    &HobbiesControllerSettings,
};
s32 demoStep = 0;
char *D_mission_overlay_80109AE4[] = {
    "c1_l1",
    "c2_l1",
    "c2_l3",
    "c3_l1",
    "c3_l2",
    "c5_l2",
};
// DO NOT DELETE ME I AM REQUIRED FOR MATCHING
u32 data_0BF800_pad = 0xC7C0007C;

struct demoInput *demoInputs;
u32 D_mission_overlay_8010BCA4;
u32 D_mission_overlay_8010BCA8;
u8  D_mission_overlay_8010BCAC;
u8  D_mission_overlay_8010BCB0[0x128]; // why is it so big???
f32 D_mission_overlay_8010BDD8[4][2];
f32 D_mission_overlay_8010BDF8[4][2];
union ControllerSettings D_mission_overlay_8010BE18[4];
f32 D_mission_overlay_8010BEA8[4][0x10];
u16 D_mission_overlay_8010BFA8[4];
OSContPad D_mission_overlay_8010BFB0[4];

void func_mission_overlay_800BEC00(void) {
    D_mission_overlay_8010BCA4 = gGameSettings.unlockAndSettingsFlags[0];
    gGameSettings.unlockAndSettingsFlags[0] = GAME_SETTING_MASK(GAME_SETTINGS_BIT_8)
        | GAME_SETTING_MASK(GAME_SETTINGS_COCKPIT)
        | GAME_SETTING_MASK(GAME_SETTINGS_HUD)
        | GAME_SETTING_MASK(GAME_SETTINGS_AUTO_ROLL)
        | GAME_SETTING_MASK(GAME_SETTINGS_AUTO_LEVEL);
    D_mission_overlay_8010BCB0[0] = gGameSettings.musicVolume;
    D_mission_overlay_8010BCB0[1] = gGameSettings.soundFxVolume;
    D_mission_overlay_8010BCB0[2] = gGameSettings.speechVolume;
    if ((D_mission_overlay_8010BCA4 & GAME_SETTING_MASK(GAME_SETTINGS_BIT_24)) != 0) {
        gGameSettings.unlockAndSettingsFlags[0] = GAME_SETTING_MASK(GAME_SETTINGS_BIT_24)
            | GAME_SETTING_MASK(GAME_SETTINGS_BIT_8)
            | GAME_SETTING_MASK(GAME_SETTINGS_COCKPIT)
            | GAME_SETTING_MASK(GAME_SETTINGS_HUD)
            | GAME_SETTING_MASK(GAME_SETTINGS_AUTO_ROLL)
            | GAME_SETTING_MASK(GAME_SETTINGS_AUTO_LEVEL);
    }
    gGameSettings.unlockAndSettingsFlags[1] = GAME_SETTING_MASK(GAME_SETTINGS_DISABLE_SUBTITLES);
    if (gGameSettings.unk23 != 0) {
        gGameSettings.unlockAndSettingsFlags[1] = GAME_SETTING_MASK(GAME_SETTINGS_DISABLE_SUBTITLES)
            | GAME_SETTING_MASK(GAME_SETTINGS_HIGH_RESOLUTION);
    }
    gGameSettings.musicVolume = 0x7F;
    gGameSettings.soundFxVolume = 0x7F;
    gGameSettings.speechVolume = 0x7F;
    applyVolumeSettingsToMixer();
    setRngSeed(1);
    demoStep = 0;
    D_main_bss_80130B88->stick_x = 0;
    D_main_bss_80130B88->stick_y = 0;
    D_main_bss_80130B88->button = 0;
    demoInputs->stick_x = 0;
    demoInputs->stick_y = 0;
    demoInputs->button = 0;
    demoInputs->unk0 = 1.0f/30.0f;
}

void applyDemoRecordedHudEvents(s32 controllerId, struct demoInput *demoInput) {
    if ((demoStep == 0x348) || ((D_main_bss_80130B88[controllerId].button != 0) && (D_main_bss_80130B88[controllerId].errno == 1))) {
        D_mission_overlay_8010C9E0 |= 1;
        if (D_main_bss_80130B88[controllerId].button != 0) {
            gMissionState.unk4 = 5;
        } else {
            gMissionState.unk4 = 4;
        }
    }
    if (demoStep < 0x384) {
        D_main_bss_80130B88[controllerId].stick_x = demoInput[demoStep].stick_x;
        D_main_bss_80130B88[controllerId].stick_y = demoInput[demoStep].stick_y;
        D_main_bss_80130B88[controllerId].button  = demoInput[demoStep].button;
        demoStep += 1;
    } else {
        D_main_bss_80130B88[controllerId].stick_x = 0;
        D_main_bss_80130B88[controllerId].stick_y = 0;
        D_main_bss_80130B88[controllerId].button  = 0;
    }
    D_main_bss_80130B88[controllerId].errno = 1;
}

void clearPlayerSlotHudTracking(s32 arg0) {
    s32 var_a3;

    D_main_bss_80130B88[arg0].stick_x = 0;
    D_main_bss_80130B88[arg0].stick_y = 0;
    D_main_bss_80130B88[arg0].button = 0;
    D_mission_overlay_8010BFB0[arg0].button = D_mission_overlay_8010BFA8[arg0];
    D_mission_overlay_8010BFB0[arg0].stick_x = 0;
    D_mission_overlay_8010BFB0[arg0].stick_y = 0;
    for (var_a3 = 0; var_a3 < 0x10; var_a3++) {
        D_mission_overlay_8010BEA8[arg0][var_a3] = 0.0f;
    }
    D_mission_overlay_8010BDF8[arg0][0] = 0.0f;
    D_mission_overlay_8010BDF8[arg0][1] = 0.0f;
}

void initAllPlayersHudTracking(void) {
    u32 temp_s0;
    s32 var_a1;
    s32 var_s1;
    u16 *var_s0;

    if (gGameSettings.unlockAndSettingsFlags[1] & 0x60) {
        D_mission_overlay_8010BCAC = gGameSettings.controllerSetting;
        gGameSettings.controllerSetting = 0;
    }
    for (var_s1 = 0; var_s1 < 4; var_s1++) {
        temp_s0 = gGameSettings.controllerSetting;
        D_mission_overlay_8010BFA8[var_s1] = 0;
        clearPlayerSlotHudTracking(var_s1);
        var_s0 = &D_mission_overlay_80109AD0[temp_s0]->asArray;
        for (var_a1 = 0; var_a1 < CONTROLLER_INPUT_NUM; var_a1++) {
            D_mission_overlay_8010BE18[var_s1].asArray[var_a1] = var_s0[var_a1];
        }
    }
    for (var_s1 = 0; var_s1 < 1; var_s1++) {
        gPlayers[var_s1].inner.unk294 = 0;
        gPlayers[var_s1].inner.unk298 = 0x1D;
    }
}

// The funny placement of this is likely an indicator that either the wrong compiler is being used
// or that string interning order is sensitive to things like function names
const u8 demo_format[] = "demo/%s_DEM";

#if 0
// There's some dumb floating point register allocation issues near the fabsf calls
// Permuter hasn't turned up anything yet :(
// https://decomp.me/scratch/6pt2m
void tickPlayerHudIndicators(f32 arg0) {
    s32 var_a0;
    s32 var_s3;
    u16 temp_v1;

    if ((gGameSettings.unk16 != 0) || (D_mission_overlay_8010CA20 == 7)) {
        D_main_bss_80130B88[0].stick_x = 0;
        D_main_bss_80130B88[0].stick_y = 0;
        D_main_bss_80130B88[0].button = 0;
    }

    if (DEMO_ACTIVE) {
        applyDemoRecordedHudEvents(0, demoInputs);
    }

    for (var_s3 = 0; var_s3 < 4; var_s3++) {
        if (D_main_bss_80130B88[var_s3].errno == CONT_ERR_NO_CONTROLLER) {
            temp_v1 = D_main_bss_80130B88[var_s3].button;
            D_main_bss_80130B88[var_s3].button &= ~(D_mission_overlay_8010BFB0[var_s3].button & D_mission_overlay_8010BFA8[var_s3]);
            D_mission_overlay_8010BFB0[var_s3].button  = temp_v1;
            D_mission_overlay_8010BFB0[var_s3].stick_x = D_main_bss_80130B88[var_s3].stick_x;
            D_mission_overlay_8010BFB0[var_s3].stick_y = D_main_bss_80130B88[var_s3].stick_y;

            D_mission_overlay_8010BDD8[var_s3][0] = D_main_bss_80130B88[var_s3].stick_x / 75.0f;
            if (D_mission_overlay_8010BDD8[var_s3][0] > 1.0f) {
                D_mission_overlay_8010BDD8[var_s3][0] = 1.0f;
            }
            if (D_mission_overlay_8010BDD8[var_s3][0] < -1.0f) {
                D_mission_overlay_8010BDD8[var_s3][0] = -1.0f;
            }
            if (fabsf(D_mission_overlay_8010BDD8[var_s3][0]) < 0.015f) {
                D_mission_overlay_8010BDD8[var_s3][0] = 0.0f;
            }

            D_mission_overlay_8010BDD8[var_s3][1] = D_main_bss_80130B88[var_s3].stick_y / 80.0f;
            if (D_mission_overlay_8010BDD8[var_s3][1] > 1.0f) {
                D_mission_overlay_8010BDD8[var_s3][1] = 1.0f;
            }
            if (D_mission_overlay_8010BDD8[var_s3][1] < -1.0f) {
                D_mission_overlay_8010BDD8[var_s3][1] = -1.0f;
            }
            if (fabsf(D_mission_overlay_8010BDD8[var_s3][1]) < 0.015f) {
                D_mission_overlay_8010BDD8[var_s3][1] = 0.0f;
            }

            if (D_mission_overlay_8010BDF8[var_s3][0] > 0.0f) {
                D_mission_overlay_8010BDF8[var_s3][0] -= arg0;
            }
            if (D_mission_overlay_8010BDF8[var_s3][1] > 0.0f) {
                D_mission_overlay_8010BDF8[var_s3][1] -= arg0;
            }

            for (var_a0 = 0; var_a0 < 0x10; var_a0++) {
                if ((temp_v1 >> var_a0) & 1) {
                    D_mission_overlay_8010BEA8[var_s3][var_a0] += arg0;
                } else {
                    D_mission_overlay_8010BEA8[var_s3][var_a0] = 0.0f;
                }
            }
        } else {
            clearPlayerSlotHudTracking(var_s3);
        }
        D_main_bss_80130B88[var_s3];
    }
}

const u32 rodata_0BF800_pad[] = {
    0x00000000,
    0x27BDFFB0,
    0xAFBF0048,
};
#else
INCLUDE_ASM("asm/nonmatchings/mission_overlay/0BF800", tickPlayerHudIndicators);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0BF800", D_mission_overlay_800A6230);
#endif

void loadPlayerSlotHudPreset(s32 arg0, s32 arg1) {
    s32 var_a1;
    union ControllerSettings *temp;

    D_mission_overlay_8010BFA8[arg0] = 0;
    clearPlayerSlotHudTracking(arg0);
    temp = D_mission_overlay_80109AD0[arg1];
    for (var_a1 = 0; var_a1 < CONTROLLER_INPUT_NUM; var_a1++) {
        D_mission_overlay_8010BE18[arg0].asArray[var_a1] = temp->asArray[var_a1];
    }
}

s32 countTrailingZeros16(u16 arg0) {
    s32 var_v1;

    if (arg0 & 0xFF) {
        var_v1 = 0;
        while (!(arg0 & 1)) {
            arg0 >>= 1;
            var_v1 += 1;
        }
    } else {
        var_v1 = 0xF;
        while (!(arg0 & 0x8000)) {
            arg0 <<= 1;
            var_v1 -= 1;
        }
    }
    return var_v1;
}

void func_mission_overlay_800BF358(void) {
    u32 why;
    if (gGameSettings.unlockAndSettingsFlags[1] & 0x60) {
        D_mission_overlay_8010BCA8 = gGameSettings.unlockAndSettingsFlags[1];
        if (gGameSettings.unk23 != 0) {
            GAME_SETTING_SET(1, GAME_SETTINGS_HIGH_RESOLUTION);
        }
        why = gGameSettings.unlockAndSettingsFlags[1] & 1;
        D_main_bss_80137D00 = why;
        D_main_bss_8013805C = why;
    }
}

void func_mission_overlay_800BF3A4(void) {
    gGameSettings.unlockAndSettingsFlags[0] = D_mission_overlay_8010BCA4;
    gGameSettings.unlockAndSettingsFlags[1] = D_mission_overlay_8010BCA8;
    gGameSettings.controllerSetting = D_mission_overlay_8010BCAC;
    gGameSettings.musicVolume   = D_mission_overlay_8010BCB0[0];
    gGameSettings.soundFxVolume = D_mission_overlay_8010BCB0[1];
    gGameSettings.speechVolume  = D_mission_overlay_8010BCB0[2];
    applyVolumeSettingsToMixer();
}

void func_mission_overlay_800BF408(s32 arg0) {
    char sp10[0x20];

    sprintf(sp10, demo_format, D_mission_overlay_80109AE4[arg0]);
    demoInputs = load_asset(sp10);
    func_mission_overlay_800BEC00();
    gGameSettings.unlockAndSettingsFlags[1] |= 0x20;
}

f32 getDemoRecordedTimestep(f32 arg0) {
    f32 var_fv0;

    var_fv0 = arg0;
    if (demoStep < 0x384) {
        var_fv0 = demoInputs[demoStep].unk0;
    }
    return var_fv0;
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0BF800", fake_func_800BF498);
