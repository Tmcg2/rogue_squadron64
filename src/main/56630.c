#include "common.h"

#include "hud.h"
#include "game_settings.h"

#include "main/02420.h"
#include "main/562A0.h"
#include "main/56630.h"
#include "main/61FC0.h"
#include "main/6B8B0.h"
#include "main/9BB60.h"

struct active_subtitle {
    u16 textId; /* 0x00 */
    u8  unk02;  /* 0x02 */
    u8  unk03;  /* 0x03 */
    u8  unk04;  /* 0x04 */
    u8  unk05;  /* 0x05 */
    u16 unk06;  /* 0x06 */
    u32 unk08;  /* 0x08 */
    u16 unk0C;  /* 0x0C */
    u16 unk0E;  /* 0x0E */
    u16 unk10;  /* 0x10 */
    s16 unk12;  /* 0x12 */
    s16 unk14;  /* 0x14 */
    s16 unk16;  /* 0x16 */
    f32 unk18;  /* 0x18 */
    f32 unk1C;  /* 0x1C */
};

struct active_subtitle *D_main_bss_80139010;
u16 D_main_bss_80139014;

void initVoiceSubtitleSystem(void) {
    struct rgba sp18 = { 0xE1, 0xAF, 0, 0xFF };
    u32 temp_v0;
    struct ui_element *temp_v0_2;

    loadVoiceTxtFile("voice_TXT");
    D_main_bss_80139010 = rs_malloc(0x20U, 0U);
    D_main_bss_80139010->textId = 0xFFFF;
    setSubtitleOverlayScreenPos(0, 0);
    if (((f32)getBootConfigField14() / getBootConfigField12()) < 0.5f) {
        D_main_bss_80139014 = 0xA;
    } else {
        if (GAME_SETTING_IS_SET(1, GAME_SETTINGS_HIGH_RESOLUTION)) {
            temp_v0 = 0xB;
        } else {
            temp_v0 = 4;
        }
        D_main_bss_80139014 = temp_v0;
    }
    loadCharTextureSet(0, D_main_bss_80139014, 1, 0x12C);
    setMenuOverlayHeaderState(1, 0, 0);
    setPlayerSlotEntryRGB(D_main_bss_80139014, 0U, &sp18);
    setPlayerSlotAnimationFlag(D_main_bss_80139014, "A\nA", 0, -0x64, 0xA);
    temp_v0_2 = getPlayerSlotFieldAt34(D_main_bss_80139014, 0U);
    temp_v0_2->flags |= 0x20;
    D_main_bss_80139010->unk05 = temp_v0_2->xy_offset_pointer[1].y;
}

INCLUDE_ASM("asm/nonmatchings/main/56630", linkHudNodeAndComputeScreenPos);

#if 0
// Needs a lot of work, ceratin parts are fine but others (mostly the loops) are pretty far off
void tickVoiceSubtitleDisplay(f32 arg0) {
    s32 sp1C;
    f32 sp18;
    f32 temp_fv0;
    s16 temp_v1_2;
    s16 var_s0_2;
    s32 var_a1_2;
    s32 var_a3;
    s32 var_s1;
    s32 var_s4;
    s16 var_s7;
    char *temp_v0;
    s8 *var_s3;
    struct ui_element *temp_s5;
    struct ui_element *temp_v0_2;
    struct xy_offset *temp_a0;
    struct xy_offset *temp_a1;
    struct xy_offset *temp_s6;
    struct xy_offset *var_a0;
    struct xy_offset *var_a0_2;
    struct xy_offset *var_s2;
    u16 temp_a0_2;
    u16 temp_v0_3;
    u16 temp_v1;
    u16 var_a1;
    u32 var_a2;
    u16 var_s0;

    sp1C = (s32) D_main_bss_80139010->unk16;
    
    if (gGameSettings.unk16 != 0) {
        if (D_main_bss_80139010->textId != 0x222) {
            D_main_bss_80139010->textId = 0x222;
            getVoiceText(D_main_bss_80139010->textId);
            D_main_bss_80139010->unk03 = 0;
            D_main_bss_80139010->unk08 = -1U;
            D_main_bss_80139010->unk02 = 0;
        }
    } else if (DEMO_ACTIVE) {
        if (D_main_bss_80139010->textId != 0x223) {
            D_main_bss_80139010->textId = 0x223;
            getVoiceText(D_main_bss_80139010->textId);
            D_main_bss_80139010->unk03 = 0;
            D_main_bss_80139010->unk08 = -1U;
            D_main_bss_80139010->unk02 = 0;
        }
    }
    if ((D_main_bss_80139010->textId != 0xFFFF) && (temp_v0 = getVoiceTxtStringPtr(), (temp_v0 != NULL))) {
        if (D_main_bss_80139010->unk02 == 0) {
            setPlayerSlotAnimationFlag(D_main_bss_80139014, temp_v0, 0U, (-((getBootConfigField12()) * 0x64) / 320), 0xA);
            temp_v0_2 = getPlayerSlotFieldAt34(D_main_bss_80139014, 0U);
            var_s7 = 0;
            if (temp_v0_2->texture_count == 0) {
                D_main_bss_80139010->textId = 0xFFFF;
                return;
            }
            var_s0 = 0;
            var_s4 = 0;
            D_main_bss_80139010->unk02 = 1;
            D_main_bss_80139010->unk0E = 0;
            temp_s6 = temp_v0_2->xy_offset_pointer;
            var_s1 = 0;
            for (var_a2 = 0; temp_v0[var_a2]; var_a2++) {
                if (*temp_v0 == ' ') {
                    var_s4 = var_s1;
                }
                if (getPlayerSlotLookupBase(D_main_bss_80139014)[temp_v0[var_a2]] == 0xFF) continue;

                temp_v0_2->xy_offset_pointer[var_a2].x -= var_s7;
                if (sp1C >= temp_v0_2->xy_offset_pointer[var_a2].x) continue;

                var_s0 += D_main_bss_80139010->unk05;
                var_s7 +=  temp_v0_2->xy_offset_pointer[var_s4].x;
                for (var_a1_2 = var_s1; var_a1_2 >= var_s4; var_a1_2--) {
                    temp_v0_2->xy_offset_pointer[var_a1_2].y = var_s0;
                    temp_v0_2->xy_offset_pointer[var_a1_2].x -= temp_v0_2->xy_offset_pointer[var_s4].x;
                }
                temp_v0_2->xy_offset_pointer[var_a2].y = var_s0;
                var_s1++;
            }
            D_main_bss_80139010->unk04 = ((s32) var_s0 / (s32) D_main_bss_80139010->unk05) + 1;
            D_main_bss_80139010->unk10 = temp_v0_2->texture_count;
            D_main_bss_80139010->unk03 = 0;
        }
        if (D_main_bss_80139010->unk03 == 0) {
            if ((D_main_bss_80139010->textId - 0x222) < 2U) {
                D_main_bss_80139010->unk18 = 0.0f;
                D_main_bss_80139010->unk1C = 2000000.0f;
                D_main_bss_80139010->unk03 = 1;
            } else if (getVoicePlaybackProgressByKey(D_main_bss_80139010->unk08, &sp18) > 0.0f) {
                D_main_bss_80139010->unk18 = 0.0f;
                D_main_bss_80139010->unk1C = sp18;
                D_main_bss_80139010->unk03 = 1;
            }
            if (D_main_bss_80139010->unk03 != 0) {
                goto block_29;
            }
        } else {
block_29:
            D_main_bss_80139010->unk18 -= arg0;
            if (D_main_bss_80139010->unk18 <= 0.0f) {
                temp_s5 = getPlayerSlotFieldAt34(D_main_bss_80139014, 0U);
                if ((u16) D_main_bss_80139010->unk0E >= (u16) D_main_bss_80139010->unk10) {
                    D_main_bss_80139010->textId = 0xFFFF;
                    getPlayerSlotFieldAt34(D_main_bss_80139014, 0U);
                    return;
                }
                if ((u8) D_main_bss_80139010->unk03 >= 2U) {
                    temp_s5->texture_id_pointer = &temp_s5->texture_id_pointer[temp_s5->texture_count];
                    temp_s5->xy_offset_pointer = &temp_s5->xy_offset_pointer[temp_s5->texture_count];
                }
                var_a2 = 1;
                temp_a1 = temp_s5->xy_offset_pointer;
                var_s0_2 = (s16) temp_a1->y;
                temp_v1 = D_main_bss_80139010->unk0E;
                temp_a0_2 = D_main_bss_80139010->unk10;
                var_a3 = 1;
                if ((temp_v1 + 1) < (s32) temp_a0_2) {
                    var_a0_2 = temp_a1 + 4;
loop_36:
                    temp_v1_2 = (s16) var_a0_2->y;
                    if (var_s0_2 < temp_v1_2) {
                        if (var_a3 < 3) {
                            var_s0_2 = temp_v1_2;
                            var_a3 += 1;
                            goto block_39;
                        }
                    } else {
block_39:
                        var_a2 += 1;
                        var_a0_2 += 4;
                        if ((var_a2 + temp_v1) >= (s32) temp_a0_2) {

                        } else {
                            goto loop_36;
                        }
                    }
                }
                D_main_bss_80139010->unk0E += var_a2;
                temp_s5->texture_count = var_a2;
                D_main_bss_80139010->unk0C = (u16) -(D_main_bss_80139010->unk05 + var_s0_2);
                if ((u16) D_main_bss_80139010->unk0E >= (u16) D_main_bss_80139010->unk10) {
                    D_main_bss_80139010->unk18 += 0.5f;
                } else {
                    D_main_bss_80139010->unk03 += 1;
                }
                D_main_bss_80139010->unk18 = (D_main_bss_80139010->unk1C * (f32) var_a3) / (f32) D_main_bss_80139010->unk04;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/main/56630", tickVoiceSubtitleDisplay);
#endif

void setSubtitleOverlayScreenPos(s16 arg0, s16 arg1) {
    D_main_bss_80139010->unk12 = ((arg0 + 0x18) * (getBootConfigField12())) / 320;
    D_main_bss_80139010->unk14 = (arg1 * getBootConfigField14()) / 224;
    D_main_bss_80139010->unk16 = ((getBootConfigField12() * 0x128) / 320) - D_main_bss_80139010->unk12;
}

void freeSubtitleOverlay(void) {
    resetPlayerSlotChannelTransform(D_main_bss_80139014);
    rs_free(D_main_bss_80139010);
}

void setActiveVoiceLine(u16 arg0, u32 arg1) {
    D_main_bss_80139010->textId = arg0;
    getVoiceText(D_main_bss_80139010->textId);
    D_main_bss_80139010->unk08 = arg1;
    D_main_bss_80139010->unk03 = 0;
    D_main_bss_80139010->unk02 = 0;
}

void clearActiveVoiceLine(void) {
    D_main_bss_80139010->textId = 0xFFFF;
}

INCLUDE_ASM("asm/nonmatchings/main/56630", fake_func_80056344);
