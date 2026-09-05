#ifndef MAIN_61FC0_H
#define MAIN_61FC0_H

#include "PR/ultratypes.h"
#include "common_types.h"

struct ui_element *getPlayerSlotFieldAt34(u16, u16);
void setPlayerSlotEntryRGB(u16, u16, struct rgba*);
u16  findCharEntryValueByKey(u16, u8);
u8   findCharEntryByteByKey(u16, u8);
s16  getPlayerSlotEntryBaseShort(u16);
s16  samplePlayerSlotChannelScaledShort(u16, u16);
s16  getPlayerSlotSpanShort(u16);
void setPlayerSlotEnabledFlag(u16, u8);

#endif
