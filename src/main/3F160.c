#include "common.h"

INCLUDE_ASM("asm/nonmatchings/main/3F160", initNpcSlotList);

INCLUDE_ASM("asm/nonmatchings/main/3F160", allocateNpcSlot);

INCLUDE_ASM("asm/nonmatchings/main/3F160", popNpcSlotFromTail);

INCLUDE_ASM("asm/nonmatchings/main/3F160", unregisterAndFreeNpcSlot);

INCLUDE_ASM("asm/nonmatchings/main/3F160", slotDispatcherIter);

INCLUDE_ASM("asm/nonmatchings/main/3F160", slotDispatcherInner);

INCLUDE_ASM("asm/nonmatchings/main/3F160", reinsertNpcIntoSortedFreeList);

INCLUDE_ASM("asm/nonmatchings/main/3F160", destroyNpcSlotByIndex);

INCLUDE_ASM("asm/nonmatchings/main/3F160", revalidateNpcSlotIterator);

INCLUDE_ASM("asm/nonmatchings/main/3F160", relinkNpcSlotToNewParentGroup);

INCLUDE_ASM("asm/nonmatchings/main/3F160", destroyNpcSlotChain);

INCLUDE_ASM("asm/nonmatchings/main/3F160", spawnChildNpcWithTransform);

INCLUDE_ASM("asm/nonmatchings/main/3F160", spawnInheritedNpcVariantA);

INCLUDE_ASM("asm/nonmatchings/main/3F160", spawnInheritedNpcVariantB);

INCLUDE_ASM("asm/nonmatchings/main/3F160", spawnInheritedNpcVariantC);

INCLUDE_ASM("asm/nonmatchings/main/3F160", freeNpcSlotArray);

INCLUDE_ASM("asm/nonmatchings/main/3F160", findActiveNpcInSlotChain);

INCLUDE_ASM("asm/nonmatchings/main/3F160", findFirstActiveNpcChildInChain);

INCLUDE_ASM("asm/nonmatchings/main/3F160", allocNpcContextArrays);

INCLUDE_ASM("asm/nonmatchings/main/3F160", destroyNpcContextArrays);

INCLUDE_ASM("asm/nonmatchings/main/3F160", spawnNpcWithSubtype);

INCLUDE_ASM("asm/nonmatchings/main/3F160", spawnNpcOfType);

INCLUDE_ASM("asm/nonmatchings/main/3F160", getNpcContextByIndex);

INCLUDE_ASM("asm/nonmatchings/main/3F160", getNpcContextField8);

INCLUDE_ASM("asm/nonmatchings/main/3F160", findFreeNpcSlotByKey);

INCLUDE_ASM("asm/nonmatchings/main/3F160", getNextSlotNpcTypeId);

INCLUDE_ASM("asm/nonmatchings/main/3F160", getNpcNextSlotIndex);

INCLUDE_ASM("asm/nonmatchings/main/3F160", destroyTransientNpcSlots);

INCLUDE_ASM("asm/nonmatchings/main/3F160", fake_func_80040304);
