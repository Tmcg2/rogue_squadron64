#ifndef MAIN_24570_H
#define MAIN_24570_H

#include "PR/os.h"

#include "common_types.h"

void setProfilerBarGate(u8);
void recordFrameTimestamp(void);
u32  getTimeLow32(void);
u32  getTimeSinceLastFrame(void);
Gfx *emitProfilerBarSegment(Gfx*, u32, s16, u8, u8, u8);

#endif
