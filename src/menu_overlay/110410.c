#include "common.h"

#include "PR/ultratypes.h"

#include "menu_overlay/12CA40.h"

// Interim BSS externs
extern u8 D_menu_overlay_800CD520[0x20];

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", loadCutsceneAssetsByIndex);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", D_menu_overlay_800A5130);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuEDread);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", D_menu_overlay_800A514C);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuECalamari);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuEBacta);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuEVolcano);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuEChandrila);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuEResearch);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuETaloraan);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuEKessel);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuEKile);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuECon);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuEJade);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuEKasan);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuECorellia);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuEChorax);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuEBarkesh);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", strMenuETatooine);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", hangarInitialize);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", runHangarSelectionFrame);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", composeNpcOrientationMatrix);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", updateHangarBayScene);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", hangarTickCameraOrbit);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/110410", D_menu_overlay_800A5804);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", hangarInitializeShipShadowHob);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", craftSelectionVoiceLineHelper);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", tickEasedCameraKeyframeBlend);

const u16 bridgeSecondaryWeaponTextIds[] = {
    0x0000, 0x004E, 0x0050, 0x0051, 0x0052, 0x0053, 0x004F, 0x0054, 0x0055, 0x0056
};

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", hangarGenerateSecondaryWeaponString);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", gracefulMenuShutdown);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", extractTextBeforeFmtChar);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", composeInterpolatedNodeMatrices);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", hangarLoadShadows);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", setByteAcrossEntryList);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", initCraftSelectVectors);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", hangarSetSecondaryWeaponDisplay);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", hangarUpdateSecWeaponIfChanged);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/110410", fake_func_800AEC54);
