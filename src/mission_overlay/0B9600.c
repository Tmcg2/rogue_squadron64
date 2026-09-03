#include "common.h"

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0B9600", D_mission_overlay_800A5C20);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0B9600", D_mission_overlay_800A5C28);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0B9600", playerVwingInit);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0B9600", updateVwingEngineEffect);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0B9600", orientVwingSubmodelByQuat);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0B9600", tickVwingEngineAudio);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0B9600", playerVwingUpdate);
