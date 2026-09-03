#include "common.h"

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0ADF80", computeTrackedObjectWorldAnchor);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0ADF80", D_mission_overlay_800A53E0);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0ADF80", D_mission_overlay_800A53F8);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0ADF80", updateCinematicCameraStateMachine);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0ADF80", submitCameraTrackedObjectToRender);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0ADF80", emitEffectParticlesAlongPath);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0ADF80", loadEffectModelInstancePool);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0ADF80", resetEffectSequenceState);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0ADF80", freeEffectModelInstancePool);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0ADF80", getEffectModelPoolHandle);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0ADF80", beginCameraViewTransition);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0ADF80", requestCameraSnapToTrackedAnchor);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0ADF80", beginCameraTrackedTransition);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0ADF80", advanceCameraTransitionOnCue);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0ADF80", isCameraTransitionIdle);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0ADF80", fake_func_800AE3E4);
