#ifndef MAIN_61FC0_H
#define MAIN_61FC0_H

#include "PR/ultratypes.h"
#include "common_types.h"
#include "hud.h"

void loadCharTextureSet(u32, u16, u16, u16);
void loadFontAsset(u8);
void activateAnimationKeyframe(u16, u16, u8);
void samplePlayerAnimChannel(u16, u16, f32);
struct ui_element_mk2 *buildPlayerCraftAssetTemplate(s16, s16);
u16  resolvePlayerAnimChannelKeyValue(u16, u16);
void initAllPlayerSlots(void);
void resetPlayerSlotChannelTransform(u16);
char *getPlayerSlotLookupBase(u8);
struct ui_element_mk2 *getPlayerSlotFieldAt34(u16, u16);
void resetPlayerSlotAllChannels(u16, u8);
struct ui_element *setPlayerSlotAnimationFlag(u16, char*, u16, s16, s32);
void setMenuOverlayHeaderState(s8, s16, s16);
void setMenuOverlayHeaderCallback(s16 (*)(s16));
void setPlayerSlotEntryRGB(u16, u16, struct rgba*);
void clearPlayerSlotPointerAndFlag(u16);
u16  findCharEntryValueByKey(u16, u8);
u16  findCharEntryAltValueByKey(u16, u8);
u8   findCharEntryByteByKey(u16, u8);
s16  getPlayerSlotEntryBaseShort(u16);
s16  samplePlayerSlotChannelScaledShort(u16, u16);
s16  getPlayerSlotSpanShort(u16);
void setPlayerSlotEnabledFlag(u16, u8);
s16 invokeMenuOverlayHeaderCallback(s16);

#endif
