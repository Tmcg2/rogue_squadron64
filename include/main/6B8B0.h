#ifndef MAIN_66FB0_H
#define MAIN_66FB0_H

#include "PR/ultratypes.h"
#include "common_types.h"

void decrypt_ns_hmt(u8*, s32, u32);
s32  isCraftAvailableByIdx(s32);
s32  getLevelCutsceneActorCallbackPrimary(void);
s32 getLevelCutsceneActorCallbackSecondary(void);
s32  getLevelExpansionMemoryBudget(void);
s32  getLevelTimeLimit(void);

struct D_main_800A05D0_type {
    s32 craftAvailabiltyFlags; /* 0x00 */
    u16 unk04; /* 0x04 */
    u16 unk06; /* 0x04 */
    u16 unk08; /* 0x08 */
    u16 unk0A; /* 0x0A */
    s32 unk0C; /* 0x0C */
    s32 unk10; /* 0x10 */
    s32 unk14; /* 0x14 */
    s32 unk18; /* 0x18 */
    f32 unk1C; /* 0x1C */
    f32 unk20; /* 0x20 */
    struct rgba unk24; /* 0x24 */
    struct rgba unk28; /* 0x28 */
    s16 unk2C; /* 0x2C */
    s16 unk2E; /* 0x2E */
}; // size 0x30

#endif
