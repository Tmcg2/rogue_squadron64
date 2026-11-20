#ifndef MENU_1197D0_H
#define MENU_1197D0_H

#include "PR/ultratypes.h"
#include "PR/os.h"

#include "textures.h"

struct some_texture_context *allocFormatTextElement(struct some_texture_context*, u16, u16, s32, s16, s16);
struct some_texture_context *loadNamedTextureDescriptor(char*, u16, u16, u8);
struct some_texture_context *allocTextRenderTarget(s16, s16);
void  tickFormatMessageWorker(OSId*);
void  buildLevelSelectTextTextures(f32);
void  decrementTextTextureRefcount(void);
void  setChildPosFromI16Pair(struct some_texture_context*, s16, s16);
struct ui_element *getStructField0xC(struct some_texture_context*);
void  initFormatMessageWorker(u8);
void  shutdownFormatMessageWorker(void);
void  initTextTextureTarget(void);
s32   accumulateShipThrottleCharge(struct some_ui_list_root*, UNIDENTIFIED_TYPE*, f32);
f32   computeThrottleChargeFraction(void);
s32   isPlayerShipActive(void);
void  destroyPlayerShipRecord(struct some_ui_list_root*);
struct some_texture_context *spawnProjectileObject(u16, u16, u16, u32);
void  copyMorphTargetVertices(struct some_texture_context*, struct some_texture_context*, u16);
char *buildPrefixedAssetName(char*);

#endif