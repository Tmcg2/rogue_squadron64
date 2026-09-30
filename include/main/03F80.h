#ifndef MAIN_03F80_H
#define MAIN_03F80_H

#include "common_types.h"

#include "main/01720.h"

void setVideoReadyFlag(void);
s32  clearDmaReadyFlag(void);
s32  processOverlayDmaStruct(struct overlay_dma*);

#endif
