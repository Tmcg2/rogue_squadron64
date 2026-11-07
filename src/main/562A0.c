#include "common.h"

#include "game_settings.h"

#include "main/bss_80130BD0.h"

#include "main/02420.h"
#include "main/04080.h"
#include "main/562A0.h"

struct text_header {
    u16 language_count;      /* 0x00 */
    u16 string_count;        /* 0x02 */
    u32 language_offsets[6]; /* 0x04 */
    // u32 filesize;         /* 0x18 The game treats this as part of the language_offsets */
}; // size 0x1C

struct text_header txtFileHeader;
u16 languageStringcount;
u16 bss_pad0_562A0;
u32 voiceTxtLanguageOffset;
u32 bss_pad1_562A0[2];
u8  voiceTxtString[0x180];

// This variable is weird.
// The data it points to is first an array of u16's, then an array of u8's (the actual string data)
// This is relevannt for matching certain functions (namely, `getGameOrFrontText`)
union {
    u16 *offsets;
    u8  *data;
} languageData = {NULL};
s32  D_main_8009ECA4 = -1;
u16 *languageStringOffsets = NULL;
// DO NOT DELETE ME I AM REQURIED FOR MATCHING
u32 data_pad_562A0 = 0x00431021;

#if 0
// Close, all the right instructions are present but they're order is slightly wrong
s32 loadTxtFile(u8 *arg0, u8 arg1) {
    s32 temp_v0_3;
    u8 var_a0;
    s32 var_s1;
    u16 *temp_v0_5;
    u32 temp_s1;
    u32 temp_s1_2;
    u8 *temp_v0_2;
    u8 *var_v1;
    u8 temp_v0_4;
    void *temp_v0;

    temp_v0 = findAssetAcrossSegments(D_main_bss_80138920, NULL, D_main_bss_80137CFC, arg0, 1U);
    setupAssetDma(D_main_bss_80138920, NULL, temp_v0, 0U, sizeof(struct text_header), &txtFileHeader);
    languageStringcount = txtFileHeader.string_count;
    if (gGameSettings.languageSelect >= txtFileHeader.language_count) {
        gGameSettings.languageSelect = 0;
    }
    if (!arg1) {
        temp_s1 = txtFileHeader.language_offsets[gGameSettings.languageSelect + 1] - txtFileHeader.language_offsets[gGameSettings.languageSelect];
        languageData.data = rs_malloc(temp_s1, 0);
        setupAssetDma(D_main_bss_80138920, NULL, temp_v0, txtFileHeader.language_offsets[gGameSettings.languageSelect], temp_s1, languageData.data);
        teardownAssetDma(D_main_bss_80138920, temp_v0);
        var_a0 = 0xF5;
        var_s1 = temp_s1 - (languageStringcount * 2);
        var_v1 = &languageData.data[languageStringcount * 2];
        while (var_s1 != 0) {
            var_s1 -= 1;
            *var_v1 ^= var_a0;
            var_a0 ^= *var_v1;
            var_v1 += 1;
        }
    } else {
        D_main_8009ECA4 = (s32) temp_v0;
        temp_s1 = txtFileHeader.string_count * 2;
        languageStringOffsets = rs_malloc(temp_s1, 0U);
        setupAssetDma(D_main_bss_80138920, NULL, temp_v0, txtFileHeader.language_offsets[gGameSettings.languageSelect], temp_s1, languageStringOffsets);
        voiceTxtLanguageOffset = txtFileHeader.language_offsets[gGameSettings.languageSelect];
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/main/562A0", loadTxtFile);
#endif

void loadGameOrFrontTxtFile(u8 *arg0) {
    loadTxtFile(arg0, 0);
}

char *getGameOrFrontText(s32 textId) {
    if ((textId >= 0) && (textId < languageStringcount)) {
        return &languageData.data[languageData.offsets[textId]];
    }
    return NULL;
}

void freeTxtFile(void) {
    if (languageData.data != NULL) {
        rs_free(languageData.data);
    }
    if (languageStringOffsets != NULL) {
        rs_free(languageStringOffsets);
    }
    if (D_main_8009ECA4 != -1) {
        teardownAssetDma(D_main_bss_80138920, (void *) D_main_8009ECA4);
        D_main_8009ECA4 = -1;
    }
    languageData.data = NULL;
    languageStringOffsets = NULL;
}

void loadVoiceTxtFile(u8 *arg0) {
    loadTxtFile(arg0, 1);
}

void getVoiceText(s32 arg0) {
    u8 var_a1;
    u8 *var_s0;
    u8 temp_v1;
    u8 why;
    u32 size;

    size = languageStringOffsets[arg0 + 1] - languageStringOffsets[arg0];
    setupAssetDma(D_main_bss_80138920, NULL, (void *) D_main_8009ECA4,
        voiceTxtLanguageOffset + languageStringOffsets[arg0],
        size,
        voiceTxtString
    );
    var_a1 = 0xF5;
    var_s0 = voiceTxtString;
    while (1) {
        temp_v1 = *var_s0 ^ var_a1;
        var_a1 ^= temp_v1;
        why = temp_v1 - 0x61;
        if (why < 0x1AU) {
            temp_v1 -= 0x20;
        }
        *var_s0 = temp_v1;
        if (temp_v1 == 0) break;
        var_s0++;
    }
}

char *getVoiceTxtStringPtr(void) {
    return voiceTxtString;
}

INCLUDE_ASM("asm/nonmatchings/main/562A0", fake_func_80055A2C);
