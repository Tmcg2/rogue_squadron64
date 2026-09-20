#include "common.h"

#include "main/832A0.h"
#include "main/94F50.h"

// Interim BSS externs

extern struct D_main_bss_801511C0_type D_main_bss_801511C0[0x100];
extern u32 D_main_bss_801499F0;
extern u32 D_main_bss_801499FC;
extern struct D_main_bss_80149A00_type  D_main_bss_80149A00[8];
extern struct D_main_bss_80149A00_type *D_main_bss_801529C0;
extern struct D_main_bss_801511C0_type *D_main_bss_801529C4;

INCLUDE_ASM("asm/nonmatchings/main/94F50", startSongSequence);

INCLUDE_ASM("asm/nonmatchings/main/94F50", stepActiveSongTracks);

#if 0
// https://decomp.me/scratch/9HNev
s32 tickScheduledSongEvents(void) {
    s32 temp_v0_3;
    struct D_main_bss_801511C0_type *temp_s1;
    struct D_main_bss_801511C0_type *temp_v0;
    struct D_main_bss_801511C0_type *var_s0;

    temp_v0 = D_main_bss_801529C0->unkE78[0];
    if (temp_v0 == NULL) return 0;
    while (temp_v0 != NULL) {
        D_main_bss_801499FC += 1;
        temp_s1 = temp_v0->unk00;
        if ((temp_v0->unk14 + D_main_bss_801529C0->unk110[4]) >= temp_v0->unk0C) {
            flagVoiceChainForStop(temp_v0->unk08);
            if (temp_v0->unk00 != NULL) {
                temp_v0->unk00->unk04 = temp_v0->unk04;
            }
            if (temp_v0->unk04 != NULL) {
                temp_v0->unk04->unk00 = temp_v0->unk00;
            } else {
                D_main_bss_801529C0->unkE78[0] = temp_v0->unk00;
            }
            temp_v0->unk00 = D_main_bss_801529C0->unkE78[1];
            if (temp_v0->unk00 != NULL) {
                D_main_bss_801529C0->unkE78[1]->unk04 = temp_v0;
            }
            temp_v0->unk04 = NULL;
            D_main_bss_801529C0->unkE78[1] = temp_v0;
        } else {
            temp_v0_3 = temp_v0->unk10 + D_main_bss_801529C0->unk110[2];
            temp_v0->unk10 = temp_v0_3 & 0xFFFF;
            temp_v0->unk14 += (temp_v0_3 >> 0x10) + D_main_bss_801529C0->unk110[3];
        }
        temp_v0 = temp_s1;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/main/94F50", tickScheduledSongEvents);
#endif

INCLUDE_ASM("asm/nonmatchings/main/94F50", stepSongPitchBendLanes);

INCLUDE_ASM("asm/nonmatchings/main/94F50", stepSongModulationLanes);

INCLUDE_ASM("asm/nonmatchings/main/94F50", advanceSongRegion);

INCLUDE_ASM("asm/nonmatchings/main/94F50", updateSongTempoTickRate);

INCLUDE_ASM("asm/nonmatchings/main/94F50", getSongParamByHandle);

INCLUDE_ASM("asm/nonmatchings/main/94F50", isSongHandleActive);

INCLUDE_ASM("asm/nonmatchings/main/94F50", stopSongByHandle);

INCLUDE_ASM("asm/nonmatchings/main/94F50", stopSongByHandleLocked);

INCLUDE_ASM("asm/nonmatchings/main/94F50", tickSongSequence);

INCLUDE_ASM("asm/nonmatchings/main/94F50", tickSongSequenceLocked);

#if 0
void tickActiveSongs(void) {
    u32 var_s0;

    for (var_s0 = 0; var_s0 < 8; var_s0++) {
        tickSongSequence(D_main_bss_80149A00[var_s0].unk000);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/main/94F50", tickActiveSongs);
#endif

INCLUDE_ASM("asm/nonmatchings/main/94F50", setSongPauseStateByHandle);

INCLUDE_ASM("asm/nonmatchings/main/94F50", applySongU16ParamCmd);

INCLUDE_ASM("asm/nonmatchings/main/94F50", applySongU16ParamCmdLocked);

INCLUDE_ASM("asm/nonmatchings/main/94F50", quiesceSongSlotCmd);

INCLUDE_ASM("asm/nonmatchings/main/94F50", quiesceSongSlotCmdLocked);

INCLUDE_ASM("asm/nonmatchings/main/94F50", setSongParamPairCmd);

INCLUDE_ASM("asm/nonmatchings/main/94F50", setSongParamPairCmdLocked);

INCLUDE_ASM("asm/nonmatchings/main/94F50", queueAudioVoiceCmdLocked);

INCLUDE_ASM("asm/nonmatchings/main/94F50", queueAudioVoiceCmd);

INCLUDE_ASM("asm/nonmatchings/main/94F50", getSongStateByteByHandle);

INCLUDE_ASM("asm/nonmatchings/main/94F50", setSongChannelParamByHandle);

INCLUDE_ASM("asm/nonmatchings/main/94F50", processSongByHandle);

INCLUDE_ASM("asm/nonmatchings/main/94F50", playSongIfMusyXActive);

INCLUDE_ASM("asm/nonmatchings/main/94F50", isSongHandleFree);

INCLUDE_ASM("asm/nonmatchings/main/94F50", tickAllActiveSongs);

void initSongSequencerPools(void) {
    struct D_main_bss_801511C0_type *var_v1_2;
    u32 var_a0;
    s32 var_a1;

    for (var_a0 = 0; var_a0 < 8; var_a0++) {
        D_main_bss_80149A00[var_a0].unkEC0 = 0;
        D_main_bss_80149A00[var_a0].unkEC1 = 1; 
    }
    var_v1_2 = NULL;
    D_main_bss_801529C4 = &D_main_bss_801511C0;
    for (var_a1 = 0; var_a1 < 0x100; var_a1++) {
        D_main_bss_801511C0[var_a1].unk04 = var_v1_2;
        if (var_v1_2 != NULL) {
            var_v1_2->unk00 = &D_main_bss_801511C0[var_a1];
        }
        var_v1_2 = &D_main_bss_801511C0[var_a1];
    }
    var_v1_2->unk00 = NULL;
    D_main_bss_801499F0 = 0;
}

INCLUDE_ASM("asm/nonmatchings/main/94F50", fake_func_8009711C);
