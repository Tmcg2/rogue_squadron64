#include "common.h"

#include "font.h"
#include "main/61FC0.h"

INCLUDE_ASM("asm/nonmatchings/main/61FC0", loadCharTextureSet);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", loadFontAsset);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", activateAnimationKeyframe);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", samplePlayerAnimChannel);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", measurePlayerSlotTextLayout);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", startPlayerSlotAnimationChannelExt);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", startPlayerSlotAnimationChannel);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", advancePlayerAnimationPhase);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", initPlayerSlotAnimationChannelFull);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", startPlayerSlotAnimationChannelFlagged);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", startPlayerSlotAnimationChannelLooping);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", buildPlayerCraftAssetTemplate);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", resolvePlayerAnimChannelKeyValue);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", initAllPlayerSlots);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", resetPlayerSlotChannelTransform);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", getPlayerSlotLookupBase);

struct ui_element *getPlayerSlotFieldAt34(u16 arg0, u16 arg1) {
    return D_main_8009FC10[arg0]->unk034[arg1];
}

INCLUDE_ASM("asm/nonmatchings/main/61FC0", resetPlayerSlotAllChannels);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", setPlayerSlotAnimationFlag);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", setMenuOverlayHeaderState);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", setMenuOverlayHeaderCallback);

void setPlayerSlotEntryRGB(u16 arg0, u16 arg1, struct rgba *arg2) {
    struct ui_element *temp_v1;

    temp_v1 = D_main_8009FC10[arg0]->unk034[arg1];
    temp_v1->rgba.r = arg2->r;
    temp_v1->rgba.g = arg2->g;
    temp_v1->rgba.b = arg2->b;
}

INCLUDE_ASM("asm/nonmatchings/main/61FC0", setPlayerSlotPointerAndFlag);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", clearPlayerSlotPointerAndFlag);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", isAnimInstanceActive);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", getPlayerAnimChannelEntryByIds);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", getPlayerAnimChannelEntryReversed);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", identityReturnArg);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", getPlayerSlotAnimChannelCount);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", markStructInitializedOnce);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", isStructUninitialized);

u16 findCharEntryValueByKey(u16 arg0, u8 arg1) {
    s32 var_a2;
    u16 var_v1;
    struct someFontThing *temp_a0;

    temp_a0 = D_main_8009FC10[arg0];
    for (var_v1 = 0; var_v1 < temp_a0->symbolCount; var_v1++) {
        if (temp_a0->symbolList[var_v1] == arg1) return temp_a0->unk028[var_v1];
    }
    return 0xFFFF;
}

INCLUDE_ASM("asm/nonmatchings/main/61FC0", findCharEntryAltValueByKey);

u8 findCharEntryByteByKey(u16 arg0, u8 arg1) {
    s32 var_a2;
    u16 var_v1;
    struct someFontThing *temp_a0;

    temp_a0 = D_main_8009FC10[arg0];
    for (var_v1 = 0; var_v1 < temp_a0->symbolCount; var_v1++) {
        if (temp_a0->symbolList[var_v1] == arg1) return temp_a0->unk018[var_v1];
    }
    return 0;
}

s16 getPlayerSlotEntryBaseShort(u16 arg0) {
    return D_main_8009FC10[arg0]->unk006;
}

s16 samplePlayerSlotChannelScaledShort(u16 arg0, u16 arg1) {
    struct someFontThing *temp_a2;
    struct ui_element *temp_a1;
    struct xy_offset *temp_a0;
    s16 temp;

    temp_a2 = D_main_8009FC10[arg0];
    temp_a1 = temp_a2->unk034[arg1];
    temp_a0 = temp_a1->xy_offset_pointer;
    temp = temp_a2->unk006 + (temp_a0[temp_a1->texture_count - 1].y - temp_a0[0].y);
    return temp * temp_a1->height_scale;
}

s16 getPlayerSlotSpanShort(u16 arg0) {
    struct someFontThing *temp_v1;

    temp_v1 = D_main_8009FC10[arg0];
    return temp_v1->unk004 + temp_v1->unk00A;
}

void setPlayerSlotEnabledFlag(u16 arg0, u8 arg1) {
    D_main_8009FC10[arg0]->unk102 = arg1 == 0;
}

INCLUDE_ASM("asm/nonmatchings/main/61FC0", invokeMenuOverlayHeaderCallback);

INCLUDE_ASM("asm/nonmatchings/main/61FC0", fake_func_80064294);
