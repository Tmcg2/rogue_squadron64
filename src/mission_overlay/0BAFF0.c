#include "common.h"

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0BAFF0", playerFalconInit);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0BAFF0", computeFalconFlightTransform);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0BAFF0", D_mission_overlay_800A5E00);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0BAFF0", D_mission_overlay_800A5E04);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0BAFF0", triggerFalconEngineEffect);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0BAFF0", bindFalconSubmodelMaterials);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0BAFF0", playerFalconMainUpdate);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0BAFF0", spawnFalconEngineParticles);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0BAFF0", playerFalconUpdate);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0BAFF0", integrateFalconFlightPhysics);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0BAFF0", D_mission_overlay_800A5ED4);
