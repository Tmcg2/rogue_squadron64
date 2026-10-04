#ifndef MAIN_67690_H
#define MAIN_67690_H

#include "PR/ultratypes.h"

u8   initSpeechSubsystem(u8, u8);
void resetSpeechSubsystem(void);
void finalizeCurrentSpeechBuffer(void);
void beginSpeechTimingWindow(void);
void endSpeechTimingWindow(void);

#endif
