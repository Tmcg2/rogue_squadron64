#ifndef CINEMATIC_1381D0_H
#define CINEMATIC_1381D0_H

#include "PR/ultratypes.h"
#include "common_types.h"

#include "hob.h"
#include "hud.h"

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

struct D_cinematic_overlay_800B0D00_type {
    u16   unk00;              /* 0x00 */
    u16   unk02;              /* 0x02 */
    Vec3f unk04;              /* 0x04 */
    Vec3f unk10;              /* 0x10 */
    f32   unk1C;              /* 0x1C */
    f32   unk20;              /* 0x20 */
    f32   unk24;              /* 0x24 */
    f32   unk28;              /* 0x28 */
    UNIDENTIFIED_TYPE *unk2C; /* 0x2C */
}; // size 0x30

struct D_cinematic_overlay_800B1900_type {
    u8  unk000; /* 0x000 */
    u8  unk001; /* 0x001 */
    u8  unk002; /* 0x002 */
    u8  unk003; /* 0x003 */
    u32 unk004; /* 0x004 */
    u32 unk008; /* 0x008 */
    u32 unk00C; /* 0x00C */
    u32 unk010; /* 0x010 */
    u8  unk014[0x20 - 0x14]; /* 0x004 */
    Mat4x3 unk020; /* 0x020 */
    UNIDENTIFIED_TYPE *unk050; /* 0x050 */
    UNIDENTIFIED_TYPE *unk054; /* 0x054 */
    u16 unk058; /* 0x058 */
    u16 unk05A; /* 0x05A */
    u32 unk05C; /* 0x05C */
    UNIDENTIFIED_TYPE *unk060; /* 0x060 */
    f32 unk064; /* 0x064 */
    f32 unk068; /* 0x068 */
    UNIDENTIFIED_TYPE *unk06C; /* 0x06C */
    Vec3f  unk070; /* 0x070 */
    Vec3f  unk07C; /* 0x07C */
    Mat4x3 unk088; /* 0x088 */
    u16 unk0B8; /* 0x0B8 */
    u16 unk0BA; /* 0x0BA */
    u8  unk0BC[0x13C - 0xBC]; /* 0x0BC */
}; // size 0x13C

void   cinematicLoopBody(u16, u8, u8);
struct cuts_file_constant *load_cutscene(u8, u8);
void   spawnCutsceneObjectsFromList(struct cuts_file_constant*, u8, u8);
void   initCutsceneAudioChannels(struct cuts_file_constant*);
void   initCutsceneScene(struct cuts_file_constant*);
void   tickCutsceneActionSlots(f32);
void   func_cinematic_overlay_800AC75C(u8, u8, Vec3f, Vec3f);
void   processCutsceneActions(struct cuts_file_constant*, u8);
f32    computeCutsceneScreenScale(u32);
void   dispatchCinematicFromMainLoop(u8*, u8);
u8     shouldShowCutsceneForLevelStage(u8, u8);
char  *getAssetNameForNpcType(u8);
Vec3f *func_cinematic_overlay_800AEA18(void);
void   cuts_0058_bubble_sort(struct cuts_file_constant*);
void   noopHandler_800AEB30(void);
void   freeCutsceneResources(void);
void   resetCutsceneActionSlots(void);
void   tickCutsceneNpcSlots(struct cuts_file_constant*);
void   initCutsceneSlotTable(void);
void   insertCutsceneSlot(struct D_cinematic_overlay_800B0D00_type*);
u16    lookupCutsceneIdMapping(s32);
void   destroyAllNpcsInSlotChain(s32);
void   maybeLoadYwingCutscene(u8, u8);
void   cinematicShutdownAudioAndAssets(void);
s32    bytesDiffer(u8 *arg0, u8 *arg1, u32 arg2);
f32    cinematicComputeDt(void);
s32    isCinematicActive(void);
void   cinematicDeactivator(struct some_ui_list_root*);
f32    cinematicInterpRatio(void);

#endif