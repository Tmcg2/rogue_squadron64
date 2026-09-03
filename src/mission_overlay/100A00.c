#include "common.h"

INCLUDE_ASM("asm/nonmatchings/mission_overlay/100A00", resolveCraftAnimationNodeHandles);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/100A00", applyCraftAnimationKeyframePose);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/100A00", despawnCraftAnimationSlotNpcs);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/100A00", despawnCraftAnimationSlotNpcsAndMarkStopping);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/100A00", allocateCraftAnimationStateForSlot);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/100A00", tickCraftAnimationSlot);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/100A00", freePlayerAuxBuffersIfActive);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/100A00", resetCraftAnimationStateForSlot);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/100A00", setCraftAnimationSlotParams);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/100A00", getCraftAnimationSlotFlag);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/100A00", getCraftAnimationSlotValue);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/100A00", D_mission_overlay_800A9548);
