#include "common.h"

#include "cheat_codes.h"
#include "game_settings.h"

#include "main/bss_80130BD0.h"

#include "main/02420.h"
#include "main/07800.h"
#include "main/192E0.h"
#include "main/562A0.h"
#include "main/61FC0.h"
#include "main/64EA0.h"
#include "main/66FB0.h"
#include "main/6E500.h"
#include "main/84830.h"
#include "main/82E70.h"
#include "menu_overlay/1197D0.h"
#include "menu_overlay/11B970.h"

// Interim BSS externs
extern struct some_ui_list_root *D_menu_overlay_800CF078;
extern struct some_ui_list_root *D_menu_overlay_800CF07C;
extern struct some_texture_context *D_menu_overlay_800CF104;
extern struct some_texture_context *D_menu_overlay_800CF110;
extern struct ui_element D_menu_overlay_800CF120;
extern s8 D_menu_overlay_800CF150;
extern struct ui_element *D_menu_overlay_800CFE2C;
extern struct ui_element *D_menu_overlay_800CFE30;
extern struct some_texture_context *D_menu_overlay_800CFE38;

// Interim Data externs
extern struct rgba mainMenuBlackColor;
extern struct rgba mainMenuGreyColor;
extern struct rgba mainMenuBrightYellowColor;
extern struct some_biography_thing D_menu_overlay_800CC89C[6];
extern OSId D_menu_overlay_800CCE18;

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuBKasan);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuBJanson);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuBZev);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuBHobbie);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuBDack);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuBWedge);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A5E08);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuTopTr2);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuSTARWARSROGUESQUADRON);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuExpansionPakEnhanced);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A5E94);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuPresentedInMOsysSurround);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A5EB8);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuUsedUnderAuthorizationN);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A5F04);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuUsedUnderAuthorization);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A5F64);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A5F90);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A5FB8);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A5FD4);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuCREDITS);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuGlwa);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuSANDCRAWLERSHORTCUT);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuBEGGARSCANYONRACE);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuMISSIONSUCCESSFUL);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuANEWTHREAT2);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuANEWTHREAT1);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuROGUEJINGLE);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuPRISONERSAVEDJINGLE);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6084);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuALLCLEARJINGLE);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuTHELOSTLIFEJINGLE);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuGAMEOVERJINGLE);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuTrl);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuBLASTIT);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuSNOWBATTLEREMIX);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuTHETRENCHRUN);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuFIGHTFORTHEGALAXY);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuROGUETHEMEREPRISE);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuTHEWORLDDEVASTATOR);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuIMPERIALMARCH);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuSAVETHEBACTA);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuVOLCANOBATTLE);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuKoelsch);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuSNOWSPEEDERTHEME);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuTHEFUTURESEQ);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuTATOOINEMORNINGSEQ);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuC3L2);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuC2L3);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuUPCOMINGSEQ);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuSTANDINGBYSEQ);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuTALORAANSKYSEQ);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuMISSIONAHEADSEQ);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuCITYINTHECLOUDS);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuSUSPENSE);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuOvOvFalcon);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuOvOvSpdr);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuASSAULTRUN);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuHITRUN);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuWALKERFACTORY);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuKASANMOORTHEME);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuClust);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuSHADOWSOVERJADEMOON);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuINTOTHETRAP2);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuINTOTHETRAP1);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuSAVETHECITY);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuCRIXMADINE);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuUPANDAWAY);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuWHEREISTHESHIP);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuBARKHESHCARGODELIVERY);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuTIEFIGHTERATTACK);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuSILENCE);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuLUKESKYWALKER);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuPROBEDROIDS);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuTATOOINEWASTELANDS);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuMAYTHEFORCEBEWITHYOU);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuCkpN1);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuTHEBRIEFINGROOM);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuGnrcStuffRLogoRef);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuLOGOS);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuRLogoRef);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuTieFighter);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuImpStuffTiefighter);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuVTccHi);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuGnrcStuffCloudcar);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuImpShuttle);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuImpStuffShuttle);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6484);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuPlCraftsYwing);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuProbeDroid);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuImpStuffPrbdroid);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuTieInter);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuImpStuffTieinter);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuAssaultBoat);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuImpStuffAssboat);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6500);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuPlCraftsXwing);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuTieD);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuImpStuffTieD);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuRaptor);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuImpStuffRaptor);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A654C);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuPlCraftsAwing);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuRebTransport);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuRebStuffRTransp);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6588);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuPlCraftsT16);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuRCombat);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuRebStuffRCombat);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A65BC);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuPlCraftsFalcon);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuWaveskimmer);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuImpStuffWskimmer);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A65F8);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuPlCraftsVwing);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuSnowspeeder);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuPlCraftsSnowspeeder);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", menuControllerInput);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6644);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A664C);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6654);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6658);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6664);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6670);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6678);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6680);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6684);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6688);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A668C);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6690);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6694);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6698);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A669C);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A66A0);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", jtbl_menu_overlay_800A66A8);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A66F0);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A66F4);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", jtbl_menu_overlay_800A66F8);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6760);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6764);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6768);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", jtbl_menu_overlay_800A6770);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6794);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6798);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A679C);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A67A0);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A67A4);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", jtbl_menu_overlay_800A67A8);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A67BC);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A67C0);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A67C4);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A67C8);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A67CC);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A67D0);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A67D4);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A67D8);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A67DC);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A67E0);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A67E4);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A67E8);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A67EC);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A67F0);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A67F4);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", jtbl_menu_overlay_800A67F8);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A680C);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6810);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6814);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6818);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A681C);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6820);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6824);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6828);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A682C);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6830);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6834);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6838);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A683C);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6840);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6844);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6848);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A684C);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6850);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6854);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", updateShipPartAnimation);

void buildHudAmmoReadout(void) {
    char sp10[0x10];
    u16 var_a3;
    u16 var_a2;
    s32 var_a2_2;
    struct ui_element *temp_v0_2;

    D_menu_overlay_800CF104 = loadNamedTextureDescriptor("logo", 0x40U, 0x20U, 0U);
    temp_v0_2 = getStructField0xC(D_menu_overlay_800CF104);
    temp_v0_2->flags |= 3;
    temp_v0_2->width_scale = temp_v0_2->height_scale = 1.075f;
    setChildPosFromI16Pair(D_menu_overlay_800CF104, -0xD0, -0xC5);
    insertLookupEntry(D_menu_overlay_800CF078, temp_v0_2, 0x23U);
    zmemcpy(&D_menu_overlay_800CF120, temp_v0_2, sizeof(struct ui_element));
    D_menu_overlay_800CF120.xpos = temp_v0_2->xpos + 5.0f;
    D_menu_overlay_800CF120.ypos = temp_v0_2->ypos + 5.0f;
    D_menu_overlay_800CF120.rgba.r = 0;
    D_menu_overlay_800CF120.rgba.g = 0;
    D_menu_overlay_800CF120.rgba.b = 0;
    D_menu_overlay_800CF120.rgba.a = 0;
    D_menu_overlay_800CF120.texture_id_pointer = rs_malloc(temp_v0_2->texture_count * 2 * temp_v0_2->unknown0A, 0U);
    zmemcpy(D_menu_overlay_800CF120.texture_id_pointer, temp_v0_2->texture_id_pointer, temp_v0_2->texture_count * 2 * temp_v0_2->unknown0A);
    for (var_a3 = 0; var_a3 < temp_v0_2->unknown0A - 1; var_a3++) {
        for (var_a2 = 0; var_a2 < temp_v0_2->texture_count - 1; var_a2++) {
            D_menu_overlay_800CF120.texture_id_pointer[(var_a3 * temp_v0_2->texture_count) + var_a2] = 0xFFFF;
        }
    }
    insertLookupEntry(D_menu_overlay_800CF078, &D_menu_overlay_800CF120, 0x25U);
    // I wish it was written like this
    // var_a2_2 = 0;
    // if (gGameSettings.cheatCodeFlags[0] & CHEAT_MASK_ICHHELD) {
    //     var_a2_2 = 1;
    // }
    var_a2_2 = (gGameSettings.cheatCodeFlags[0] >> 7) & 1;
    if (gGameSettings.cheatCodeFlags[0] & CHEAT_MASK_PSYLOCK) {
        var_a2_2 = 2;
    }
    if (gGameSettings.cheatCodeFlags[0] & CHEAT_MASK_WUTZI) {
        var_a2_2 = 3;
    }
    if (gGameSettings.cheatCodeFlags[0] & CHEAT_MASK_BERGLOWE) {
        var_a2_2 = 4;
    }
    if (gGameSettings.cheatCodeFlags[0] & CHEAT_MASK_TIECK) {
        var_a2_2 = 5;
    }
    if (gGameSettings.cheatCodeFlags[0] & CHEAT_MASK_RUDIBUBI) {
        var_a2_2 = 6;
    }
    if (gGameSettings.cheatCodeFlags[0] & CHEAT_MASK_CHIPPIE) {
        var_a2_2 = 7;
    }
    if (gGameSettings.cheatCodeFlags[0] & CHEAT_MASK_TOBIASS) {
        var_a2_2 = 8;
    }
    if (gGameSettings.cheatCodeFlags[0] & CHEAT_MASK_SIRHISS) {
        var_a2_2 = 9;
    }
    if (gGameSettings.cheatCodeFlags[0] & CHEAT_MASK_HARDROCK) {
        var_a2_2 = 0xA;
    }
    if (gGameSettings.cheatCodeFlags[0] & CHEAT_MASK_THBPILOT) {
        var_a2_2 = 0xB;
    }
    if (gGameSettings.cheatCodeFlags[0] & CHEAT_MASK_FLYDODGE) {
        var_a2_2 = 0xC;
    }
    sprintf(&sp10, "the_head%d", var_a2_2);
    D_menu_overlay_800CF110 = loadNamedTextureDescriptor(&sp10, 0x20U, 0x20U, 0U);
    temp_v0_2 = getStructField0xC(D_menu_overlay_800CF110);
    temp_v0_2->flags |= 3;
    temp_v0_2->width_scale = 0.8f;
    setChildPosFromI16Pair(D_menu_overlay_800CF110, 0x83, -0x86);
    insertLookupEntry(D_menu_overlay_800CF078, temp_v0_2, 0x22U);
}

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", readAccountForSelectionScreen);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", resetMaterialTextureEffectSlots);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", setMaterialTextureByName);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", easeAnimationKeyframe);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", cycleAccountLabelText);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", animateBannerOscillation);

void setupCraftAnimationFlagSet(u8 *arg0) {
    char sp18[0x40];
    u8 sp58[4];
    u8 var_a1;

    sp58[0] = sp58[1] = sp58[2] = sp58[3] = 0;
    if (arg0 != NULL) {
        for (var_a1 = 0; var_a1 < 0x13; var_a1++) {
            sp58[arg0[var_a1]]++;
        }
    }
    sprintf(&sp18, "~%d\n\n~~~~~~~~~%d\n\n~~~~~~~~%d", sp58[3], sp58[2], sp58[1]);
    // wtf is up with this string?
    setPlayerSlotAnimationFlag(8U, "\04\n\n\n\03\n\n\n\02", 1U, -0x74, -0x7F);
    setPlayerSlotAnimationFlag(8U, sp18, 2U, -0x7C, -0x7F);
    setPlayerSlotAnimationFlag(8U, sp18, 3U, -0x7B, -0x7D);
    relocateLookupEntryToNewKey(D_menu_overlay_800CF078, getPlayerSlotFieldAt34(8U, 1U), 0xFU);
    relocateLookupEntryToNewKey(D_menu_overlay_800CF078, getPlayerSlotFieldAt34(8U, 2U), 0xAU);
    relocateLookupEntryToNewKey(D_menu_overlay_800CF078, getPlayerSlotFieldAt34(8U, 3U), 0xCU);
    setPlayerSlotEntryRGB(8U, 1U, &mainMenuGreyColor);
    setPlayerSlotEntryRGB(8U, 2U, &mainMenuGreyColor);
    setPlayerSlotEntryRGB(8U, 3U, &mainMenuBlackColor);
    samplePlayerAnimChannel(8U, 1U, 1.0f);
    samplePlayerAnimChannel(8U, 2U, 1.2f);
    samplePlayerAnimChannel(8U, 3U, 1.2f);
    applyCraftSlotAnimations(0.0f);
}

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", initVwingHudAndSlotState);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A699C);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A69BC);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", loadVwingMeshAssets);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A69F4);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6A0C);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6A14);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6A1C);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", buildVwingRenderMatrices);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", animateVwingThrusterMaterial);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", updateVwingTrailGeometry);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", playerVwingMainUpdate);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", setupMenuData);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", handleGameSettingsMenu);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", updateMenuPerFrame);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", driveFalconAnimationKeyframes);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", applyTieInterceptorAnimState);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", copyTieInterceptorAnimBuffer);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", applyTieInterceptorSlotAnim);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", updateTieInterceptorAnimFlag);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", integrateTieInterceptorPhysics);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", spawnTieInterceptorParticles);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", playerTieInterceptorMainUpdate);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", initControllerSettingsStructs);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", controllerSettingsScreen);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", easeT16AnimationKeyframe);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", allocT16EffectContext);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", computeNabooBankingOrientation);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", handleNabooFlightInput);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", handleNabooActionButtons);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6DC0);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6DCC);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", eliteRoguesMenuHandler);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6DF8);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E24);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E28);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E2C);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E30);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E34);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E38);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E3C);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E40);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E44);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E48);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E4C);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E50);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E54);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E58);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E5C);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E60);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E64);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E68);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E6C);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E70);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E74);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E78);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E7C);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E80);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E84);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E88);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E8C);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E90);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E94);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E98);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6E9C);

void tickMenuOptionEntry(u8 arg0) {
    u8 var_a1;
    u8 var_v1;
    f32 var_fs0;
    f32 var_fs1;
    struct ui_element_mk2 *temp_s3;

    if (arg0 != 0) {
        var_v1 = 9;
    } else {
        var_v1 = 8;
    }
    if (arg0 != 0) {
        var_a1 = 0xA;
    } else {
        var_a1 = 0x10;
    }
    if (arg0 != 0) {
        var_fs1 = 0.48f;
    } else {
        var_fs1 = 1.0f;
    }
    if (arg0 != 0) {
        var_fs0 = 212.0f;
    } else {
        var_fs0 = 160.0f;
    }
    if (gGameSettings.unk16 != 0) {
        temp_s3 = getPlayerSlotFieldAt34(var_v1, var_a1);
        setMenuOverlayHeaderState(2, 0x200, 0);
        setPlayerSlotAnimationFlag(var_v1, getGameOrFrontText(0xBE), var_a1, (var_fs0 + -256.0f), 0xBE);
        setPlayerSlotEntryRGB(var_v1, var_a1, &mainMenuBrightYellowColor);
        samplePlayerAnimChannel(var_v1, var_a1, var_fs1);
        if (arg0 != 0) {
            temp_s3->height_scale *= 1.2f;
        }
        activateAnimationKeyframe(var_v1, var_a1, 0xFE);
    } else {
        activateAnimationKeyframe(var_v1, var_a1, 0);
    }
}

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6EB8);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", runMenuRandomBackdropScreen);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", loadMenuSceneModelAndMaterials);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", animateMenuSceneTransform);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", setMenuObjectColorPreset);

#if 0
// Text is matching (for reasons), rodata won't match because "medal_sh" is used by multiple functions
void createMenuTextLabels(u8 arg0) {
    char *var_a0;
    struct some_texture_context *temp_v0;
    struct ui_element *temp_v0_2;
    struct ui_element *temp_v0_3;
    struct ui_element *why;
    u8 why2_son_of_why;
    s8 var_v0;

    if (arg0) {
        var_a0 = "rebel_sh";
    } else {
        var_a0 = "medal_sh";
    }
    D_menu_overlay_800CFE38 = loadNamedTextureDescriptor(var_a0, 0x40U, 0x40U, 1U);
    D_menu_overlay_800CFE2C = getStructField0xC(D_menu_overlay_800CFE38);
    D_menu_overlay_800CFE2C->flags |= 0x08C00003;
    D_menu_overlay_800CFE2C->rgba.r = 0xA;
    D_menu_overlay_800CFE2C->rgba.g = 0;
    D_menu_overlay_800CFE2C->rgba.b = 0;
    why = D_menu_overlay_800CFE2C;
    if (!arg0) {
        var_v0 = -0x38U;
    } else {
        // I don't get how this matches and I hate it
        why2_son_of_why = 0x40;
        var_v0 = -1U;
    }
    why->rgba.a = var_v0;
    insertLookupEntry(D_menu_overlay_800CF07C, D_menu_overlay_800CFE2C, 0xFU);
    D_menu_overlay_800CFE30 = getStructField0xC(loadNamedTextureDescriptor("medal_sh", why2_son_of_why, why2_son_of_why, 1U));
    D_menu_overlay_800CFE30->flags |= 0x02400003;
    D_menu_overlay_800CFE30->rgba.r = 0;
    D_menu_overlay_800CFE30->rgba.g = 0;
    D_menu_overlay_800CFE30->rgba.b = 0;
    D_menu_overlay_800CFE30->rgba.a = 0xFF;
    insertLookupEntry(D_menu_overlay_800CF078, D_menu_overlay_800CFE30, 0xFU);
}
#else
INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", createMenuTextLabels);
#endif

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuMedalSh);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuTyComplete);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuTyFailed);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", strMenuTyOver);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A6FF8);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A7008);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", postLevelSaveInit);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A7038);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A7040);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", postLevelStatScreen);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", runMenuShipSelectScreen);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", initMenuScreenRenderContext);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", runMenuContentStateMachine);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A70F4);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", tickMenuSelectionEnterState);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", tickMenuSelectionActiveState);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", transformSceneMeshVertices);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", runMenuModelViewerScreen);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", initMenuScreenCameraViewport);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", updateMenuItemAnimationState);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A7354);

INCLUDE_RODATA("asm/nonmatchings/menu_overlay/11B970", D_menu_overlay_800A737C);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", menuSubtype02Handler);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", initInteractiveSceneContext);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", setupCraftPreviewModel);

char *getPlayerRankString(s32 arg0) {
    return getGameOrFrontText(arg0 + 0x92);
}

void shutdownMenuMessagingAndSpeech(u8 arg0) {
    shutdownFormatMessageWorker();
    if (arg0) {
        finalizeCurrentSpeechBuffer();
    }
}

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", cueMenuScreenAudioA);

void preloadMenuMusicSetA(void) {
    parseLoadedSndSection(0xCU);
    parseLoadedSndSection(0x1DU);
    loadSongAssetByName(D_main_bss_80138920, 0x1C);
    loadSongAssetByName(D_main_bss_80138920, 0x35);
    loadSongAssetByName(D_main_bss_80138920, 0x36);
    loadSongAssetByName(D_main_bss_80138920, 0x37);
    playSimpleAudioCmd(0x7FU, 0x32U, 0xFEU);
    playSimpleAudioCmd(0x78U, 0x32U, 0xFDU);
}

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", cueMenuScreenAudioB);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", cueMenuScreenAudioC);

void getControllerSettingsTitle(char *title) {
    if (gGameSettings.languageSelect == LANGUAGE_FR) {
        sprintf(title, "%s %s", getGameOrFrontText(0xB1), getGameOrFrontText(gGameSettings.controllerSetting + 0x7F));
    } else {
        sprintf(title, "%s %s", getGameOrFrontText(gGameSettings.controllerSetting + 0x7F), getGameOrFrontText(0xB1));
    }
}

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", playMenuElementTransitionAnim);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", loadControllerModel);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", loadHelmetModel);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", resetMenuElementInputState);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", animateCraftSelectFlags);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", allocCraftPreviewEffectObject);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", initCraftPreviewEffectWithRandom);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", initMenuElementScrollAnimParams);

void applyMenuCheatCode(char *arg0) {
    u8 sp10;

    sp10 = 0;
    switch (applyCheatCodeFromInput(arg0, 0U, &sp10)) {
        case 0:
            bsearchFactor5TableByU16Key(0x67, 0x6E, 0x40);
            break;
        case 1:
            bsearchFactor5TableByU16Key(0x18, 0x5F, 0x40);
            break;
        default:
            break;
    }
    if (sp10 != 0) {
        serializeSettingsToSaveAndPersist();
    }
}

s16 getCraftStatIfThresholdMet(s16 arg0) {
    s16 var_a2;

    if (D_menu_overlay_800CC89C[D_menu_overlay_800CF150].unk16 > arg0) {
        var_a2 = D_menu_overlay_800CC89C[D_menu_overlay_800CF150].unk14;
    } else {
        var_a2 = 0;
    }
    return var_a2;
}

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", resetMenuSelectionGlobalState);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", spawnMenuListItemSprite);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", createUiSpriteAt);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", updateUiSpriteScrollAndAlpha);

void setMenuAnimGroupFrame(f32 arg0) {
    u8 var_s0;
    u8 var_s1;

    var_s1 = arg0 * 254.0f;
    for (var_s0 = 0; var_s0 < 4; var_s0++) {
        activateAnimationKeyframe(5U, var_s0, var_s1);
    }
    for (var_s0 = 2; var_s0 < 0x10; var_s0++) {
        activateAnimationKeyframe(8U, var_s0, var_s1);
    }
}

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", createMenuTextElement);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", allocMenuScreenState);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", freeMenuScreenState);

#if 0
// Close, something about the `if` statement at the bottom is being picky
void updateMenuElementTimedPosition(f32 arg0, u8 arg1) {
    u8  var_a2;
    f32 why;
    f32 temp_ft0;
    f32 temp_fv1;

    if (arg0 > 0.05f) {
        temp_ft0 = arg0 * 1.675f;
        temp_fv1 = (temp_ft0 * 512.0f) / 640.0f;
        D_menu_overlay_800CFE2C->width_scale = temp_fv1;
        if (arg1 != 0) {
            D_menu_overlay_800CFE2C->width_scale = temp_fv1 * 1.075f;
        }
        D_menu_overlay_800CFE2C->height_scale = temp_ft0;
        if (arg1 != 0) {
            D_menu_overlay_800CFE2C->height_scale = temp_ft0 * 1.075f;
        }
        setChildPosFromI16Pair(D_menu_overlay_800CFE38, ((D_menu_overlay_800CFE2C->width_scale * -128.0f) + 14.0f), ((D_menu_overlay_800CFE2C->height_scale * -128.0f) + 18.0f));
    }
    if (!(arg0 > 0.05f)) {
        var_a2 = 0;
    } else {
        var_a2 = 1;
    }
    setLookupEntryField5ByKey(D_menu_overlay_800CF07C, D_menu_overlay_800CFE2C, var_a2);
}
#else
INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", updateMenuElementTimedPosition);
#endif

void applyCraftSlotAnimations(f32 arg0) {
    f32 temp_fv0;
    s32 var_s0;
    u8 temp_s0;

    temp_s0 = arg0 * 254.0f;
    activateAnimationKeyframe(8U, 1U, temp_s0);
    activateAnimationKeyframe(8U, 2U, temp_s0);
    activateAnimationKeyframe(8U, 3U, temp_s0);
}

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", setMaterialFadeTargetIfIdle);

void setCraftMaterialTextureByName(u8 arg0, char *arg1) {
    setMaterialTextureByName(arg0, arg1, 0.0f);
}

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", initMenuBackdropAndPickRandom);

void initSongAssetLoadWorker(u8 arg0) {
    D_menu_overlay_800CCE18 = registerServiceWorker(4U, 0x800, arg0, tickSongAssetLoadWorker);
    startServiceWorker(D_menu_overlay_800CCE18);
}

void shutdownSongAssetLoadWorker(void) {
    if (D_menu_overlay_800CCE18 != -1) {
        unregisterServiceWorker(D_menu_overlay_800CCE18);
    }
}

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", tickSongAssetLoadWorker);

INCLUDE_ASM("asm/nonmatchings/menu_overlay/11B970", fake_func_800C5898);

const u32 rodata_junk_11B970[] = {
    0xAC680000,
    0xAC690004,
    0xAC6A0008,
};
