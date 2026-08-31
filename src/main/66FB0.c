#include "common.h"

#include "main/66FB0.h"

struct D_main_8009FCD4_type {
    u32 songId;
    char *songName;
};

void *D_main_8009FCD0 = NULL;

struct D_main_8009FCD4_type D_main_8009FCD4[] = {
    {0x00000006, "c1l1_theme"},
    {0x00000007, "c1l1_spc01"},
    {0x00000008, "c1l1_spc02"},
    {0x00000009, "c1l1_prob1"},
    {0x0000000A, "c1l1_prob2"},
    {0x0000000B, "c1l2_theme"},
    {0x0000000C, "c1l2_spc01"},
    {0x0000000D, "c1l3_theme"},
    {0x0000000E, "c1l3_spc01"},
    {0x0000000F, "c1l4_theme"},
    {0x00000010, "c1l4_spc01"},
    {0x00000011, "c1l5_theme"},
    {0x00000012, "c1l5_spc01"},
    {0x00000013, "c1l5_act01"},
    {0x00000014, "c1l5_act02"},
    {0x00000015, "c2l1_theme"},
    {0x00000016, "c2l1_spc01"},
    {0x00000018, "c2l2_theme"},
    {0x00000019, "c2l2_spc01"},
    {0x0000001A, "c2l3_theme"},
    {0x0000001B, "c2l3_spc01"},
    {0x0000001C, "c2l5_theme"},
    {0x0000001E, "c3l1_theme"},
    {0x0000001F, "c3l2_theme"},
    {0x00000020, "c3l4_theme"},
    {0x00000021, "c3l4_spc01"},
    {0x00000022, "c3l5_theme"},
    {0x00000023, "c3l5_spc01"},
    {0x00000024, "c4l1_theme"},
    {0x00000025, "c5l1_start"},
    {0x00000026, "c5l1_1"},
    {0x00000027, "c5l1_2"},
    {0x00000028, "c5l1_3"},
    {0x00000029, "c5l2_theme"},
    {0x0000002A, "c5l2_spc01"},
    {0x0000002B, "c5l3_theme"},
    {0x0000002F, "action01b"},
    {0x0000002E, "action01"},
    {0x00000030, "action02"},
    {0x00000031, "action04"},
    {0x00000032, "action05"},
    {0x00000033, "action06"},
    {0x00000034, "action07"},
    {0x0000002C, "silent01"},
    {0x0000002D, "silent02"},
    {0x00000060, "addtl"},
    {0x00000035, "jingle01"},
    {0x00000036, "jingle02"},
    {0x00000037, "jingle03"},
    {0x00000038, "jingle04"},
    {0x00000039, "jingle05"},
    {0x0000003A, "jingle06"},
    {0x0000003B, "jingle07"},
    {0x0000003C, "jingle08"},
    {0x00000061, "empty"},
    {0x0000003D, "c1l1_cut1"},
    {0x0000003E, "c1l2_cut1"},
    {0x0000003F, "c1l3_cut1"},
    {0x00000040, "c1l4_cut1"},
    {0x00000041, "c1l5_cut1"},
    {0x00000042, "c2l1_cut1"},
    {0x00000043, "c2l2_cut1"},
    {0x00000044, "c2l3_cut1"},
    {0x00000045, "c2l5_cut1"},
    {0x00000046, "c2l6_cut1"},
    {0x00000047, "c3l1_cut1"},
    {0x00000048, "c3l2_cut1"},
    {0x00000049, "c3l3_cut1"},
    {0x0000004A, "c3l4_cut1"},
    {0x0000004B, "c3l5_cut1"},
    {0x0000004C, "c4l1_cut1"},
    {0x0000004D, "c5l1_cut1"},
    {0x0000004E, "c5l2_cut1"},
    {0x0000004F, "c5l3_cut1"},
    {0x00000050, "extr_cut1"},
    {0x00000051, "cut_seq1"},
    {0x00000052, "cut_seq2"},
    {0x00000053, "cut_seq3"},
    {0x00000054, "cut_seq4"},
    {0x00000055, "cut_seq5"},
    {0x00000056, "cut_seq6"},
    {0x00000057, "cut_seq7"},
    {0x00000058, "cut_seq8"},
    {0x00000059, "cut_jing1"},
    {0x0000005A, "cut_jing2"},
    {0x0000005C, "roguetheme"},
    {0x00000001, "roguetitle"},
    {0x0000005F, "imperial"},
    {0x00000002, "title"},
    {0x00000003, "hangar1"},
    {0x00000004, "hangar2"},
    {0x00000005, "hangar3"},
    {0x00000000, "logo1"},
    {0x0000005E, "credits"},
    {0x0000005D, "outro"},
    {0x0000005B, "kasan1"},
    {0xFFFFFFFF, 0x00000000},
};

// DO NOT DELETE ME I AM REQUIRED FOR MATCHING
u32 data_pad_66FB0 = 0x8FC20040;

INCLUDE_ASM("asm/nonmatchings/main/66FB0", loadSndFiles);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", initAudioListenerFromCamera);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", loadSongAssetByName);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", updateAudioListenerVelocity);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", teardownAudioListenerNode);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", waitForAnyAudioSlot);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", parseLoadedSndSection);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", freeAudioCacheEntry);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", findAudioChannelById);

INCLUDE_ASM("asm/nonmatchings/main/66FB0", updateAudioListenerPosFromPlayer);
