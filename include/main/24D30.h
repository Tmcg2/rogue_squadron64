#ifndef MAIN_24D30_H
#define MAIN_24D30_H

#include "PR/mbi.h"

#include "common_types.h"

Gfx *flushDebugTextOverlay(Gfx*);
void queueDebugTextGlyph(u16, u16, s8);
void setDebugTextCursor(s32, s32);
void drawDebugTextString(u8*);
void loadDebugAssets(OSId);

#endif
