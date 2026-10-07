#include "common.h"

#include "main/56F50.h"
#include "mission_overlay/0ADF80.h"

// Interim BSS externs
extern struct D_mission_overlay_8010B6E0_type *D_mission_overlay_8010B6E0;
extern struct D_mission_overlay_8010B6E8_type  D_mission_overlay_8010B6E8;

void computeTrackedObjectWorldAnchor(struct D_mission_overlay_8010B6E8_type *arg0) { 
    if (D_mission_overlay_8010B6E0[arg0->unk01].unkF4 != 0) {
        arg0->unk44[0] = D_mission_overlay_8010B6E0[arg0->unk01].unk00[0] + D_mission_overlay_8010B6E0[arg0->unk01].unk10[0][2];
        arg0->unk44[1] = D_mission_overlay_8010B6E0[arg0->unk01].unk00[1] + D_mission_overlay_8010B6E0[arg0->unk01].unk10[1][2];
        arg0->unk44[2] = D_mission_overlay_8010B6E0[arg0->unk01].unk00[2] + D_mission_overlay_8010B6E0[arg0->unk01].unk10[2][2];
    } else {
        arg0->unk44[0] = arg0->unk44[1] = arg0->unk44[2] = 0.0f;
    }
}

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0ADF80", D_mission_overlay_800A53E0);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0ADF80", D_mission_overlay_800A53F8);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0ADF80", updateCinematicCameraStateMachine);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0ADF80", submitCameraTrackedObjectToRender);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0ADF80", emitEffectParticlesAlongPath);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0ADF80", loadEffectModelInstancePool);

void resetEffectSequenceState(void) {
    D_mission_overlay_8010B6E8.unk00 = 0;
}

void freeEffectModelInstancePool(void) {
    s32 var_s0;
    u32 var_s1;

    for (var_s1 = 0; var_s1 < 0x3C; var_s1++) {
        releaseMeshAsset(&D_mission_overlay_8010B6E0[var_s1].unk40);
    }
    rs_free(D_mission_overlay_8010B6E0);
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0ADF80", getEffectModelPoolHandle);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0ADF80", beginCameraViewTransition);

void requestCameraSnapToTrackedAnchor(void) {
    D_mission_overlay_8010B6E8.unk00 = 4;
    computeTrackedObjectWorldAnchor(&D_mission_overlay_8010B6E8);
    D_mission_overlay_8010B6E8.unk50 = 0;
}

void beginCameraTrackedTransition(void) {
    D_mission_overlay_8010B6E8.unk00 = 3;
    computeTrackedObjectWorldAnchor(&D_mission_overlay_8010B6E8);
    D_mission_overlay_8010B6E8.unk50 = 0;
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0ADF80", advanceCameraTransitionOnCue);

s32 isCameraTransitionIdle(void) {
    return ((D_mission_overlay_8010B6E8.unk00 == 0) || (D_mission_overlay_8010B6E8.unk00 == 4));
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0ADF80", fake_func_800AE3E4);
