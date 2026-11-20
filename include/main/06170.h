#ifndef MAIN_06170_H
#define MAIN_06170_H

#include "PR/ultratypes.h"

s32  initPiDmaWorker(void);
u8   dispatchPendingPiDmaToWorker(s32);
u8  *getAssetRamAddress(s32);
s32  setDmaSlotMaxTxStepSize(s32);

#endif
