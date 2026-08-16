#include "common.h"

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

INCLUDE_ASM("asm/nonmatchings/main/562A0", loadTxtFile);

INCLUDE_ASM("asm/nonmatchings/main/562A0", loadGameOrFrontTxtFile);

s8 *getGameOrFrontText(s32 textId) {
    if ((textId >= 0) && (textId < languageStringcount)) {
        return &languageData.data[languageData.offsets[textId]];
    }
    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/main/562A0", freeTxtFile);

INCLUDE_ASM("asm/nonmatchings/main/562A0", loadVoiceTxtFile);

INCLUDE_ASM("asm/nonmatchings/main/562A0", getVoiceText);

INCLUDE_ASM("asm/nonmatchings/main/562A0", getVoiceTxtStringPtr);

INCLUDE_ASM("asm/nonmatchings/main/562A0", fake_func_80055A2C);
