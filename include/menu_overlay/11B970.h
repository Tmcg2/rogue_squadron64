#ifndef MENU_11B970_H
#define MENU_11B970_H

#include "PR/ultratypes.h"

struct some_biography_thing {
    u16   unk00;    /* 0x00 */
    u16   unk02;    /* 0x02 */
    char *unk04;    /* 0x04 */
    u16   unk08;    /* 0x08 */
    u16   unk0A;    /* 0x0A */
    u16   unk0C;    /* 0x0C */
    u16   unk0E;    /* 0x0E */
    u16   unk10;    /* 0x10 */
    u16   unk12;    /* 0x12 */
    s16   unk14;    /* 0x14 */
    u16   unk16;    /* 0x16 */
    u16   unk18[6]; /* 0x18 */
}; // size 0x24

void  buildHudAmmoReadout(void);
void  setMaterialTextureByName(u8, char*, f32);
void  animateBannerOscillation(f32);
void  setupCraftAnimationFlagSet(u8*);
void  loadVwingMeshAssets(u8, u8);
void  createMenuTextLabels(u8);
void  tickMenuOptionEntry(u8);
char *getPlayerRankString(s32);
void  shutdownMenuMessagingAndSpeech(u8);
void  preloadMenuMusicSetA(void);
void  getControllerSettingsTitle(char*);
void  loadHelmetModel(void);
void  applyMenuCheatCode(char*);
s16   getCraftStatIfThresholdMet(s16);
void  setMenuAnimGroupFrame(f32);
void  updateMenuElementTimedPosition(f32, u8);
void  applyCraftSlotAnimations(f32);
void  setCraftMaterialTextureByName(u8, char*);
void  shutdownSongAssetLoadWorker(void);
void  initSongAssetLoadWorker(u8);
void  tickSongAssetLoadWorker(OSId*);

#endif