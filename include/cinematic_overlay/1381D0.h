#ifndef CINEMATIC_1381D0_H
#define CINEMATIC_1381D0_H

#include "PR/ultratypes.h"
#include "common_types.h"

struct cuts_0058_type {
    u32 sub_type; /* 0x00 */
    u32 unk04;    /* 0x04 */
    u32 unk08;    /* 0x08 */
    u32 unk0C;    /* 0x0C */
    u32 unk10;    /* 0x10 */
    u32 unk14;    /* 0x14 */
}; // size = 0x18

struct cuts_1318_type {
    u32 unk00[8]; /* 0x00 */
}; // size = 0x20

struct cuts_13D8_type {
    char unk00[28]; /* 0x00 */
    u32 flags;      /* 0x1C */
    u32 unk20[11];  /* 0x20 */
}; // size = 0x4C

struct cuts_file_constant {
    char filename[64];                  /* 0x0000 */
    u32 unk0040;                        /* 0x0040 */
    u32 unk0044;                        /* 0x0044 */
    u16 unk0048;                        /* 0x0048 */
    u16 unk13D8_active_count;           /* 0x004A */
    u16 unk004C;                        /* 0x004C */
    u16 unk0058_active_count;           /* 0x004E */
    f32 unk0050;                        /* 0x0050 */
    f32 unk0054;                        /* 0x0054 */
    struct cuts_0058_type unk0058[200]; /* 0x0058 */
    struct cuts_1318_type unk1318[6];   /* 0x1318 */
    struct cuts_13D8_type unk13D8[60];  /* 0x13D8 */
    u32 vec3f_count; /* 0x25A8 */
}; // size = 0x25AC

enum CutsceneType {
    CUTSCENE_INTRO     /* 0x0 */,
    CUTSCENE_EXTRO     /* 0x1 */,
    CUTSCENE_SPECIAL   /* 0x2 */,
    NUM_CUTSCENE_TYPES /* 0x3 */,
};

void   func_cinematic_overlay_800AC75C(u8, u8, Vec3f, Vec3f);
u8     shouldShowCutsceneForLevelStage(u8, u8);
char  *getAssetNameForNpcType(u8);
Vec3f *func_cinematic_overlay_800AEA18(void);
void   cuts_0058_bubble_sort(struct cuts_file_constant*);
void   noopHandler_800AEB30(void);
u16    lookupCutsceneIdMapping(s32);
void   cinematicShutdownAudioAndAssets(void);
s32    bytesDiffer(u8 *arg0, u8 *arg1, u32 arg2);

#endif