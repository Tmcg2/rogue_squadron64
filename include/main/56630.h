#ifndef MAIN_56630_H
#define MAIN_56630_H

#include "PR/ultratypes.h"

void initVoiceSubtitleSystem(void);
void tickVoiceSubtitleDisplay(f32);
void setSubtitleOverlayScreenPos(s16, s16);
void freeSubtitleOverlay(void);
void setActiveVoiceLine(u16, u32);
void clearActiveVoiceLine(void);

#endif
