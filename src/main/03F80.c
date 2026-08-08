#include "common.h"

INCLUDE_ASM("asm/nonmatchings/main/03F80", setVideoReadyFlag);

INCLUDE_ASM("asm/nonmatchings/main/03F80", clearDmaReadyFlag);

INCLUDE_ASM("asm/nonmatchings/main/03F80", processOverlayDmaStruct);

INCLUDE_ASM("asm/nonmatchings/main/03F80", fake_func_80003424);
