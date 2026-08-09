#include "common.h"

#include "secondary_weapons.h"
#include "mission_overlay/0FCA20.h"

static struct hud_struct D_mission_overlay_8010CA30[2];

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0FCA20", D_mission_overlay_800A90B0);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0FCA20", D_mission_overlay_800A90C0);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0FCA20", D_mission_overlay_800A90D0);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0FCA20", D_mission_overlay_800A90DC);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0FCA20", D_mission_overlay_800A90E8);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0FCA20", D_mission_overlay_800A90F4);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0FCA20", D_mission_overlay_800A9100);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0FCA20", D_mission_overlay_800A910C);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0FCA20", D_mission_overlay_800A9118);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0FCA20", D_mission_overlay_800A9124);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FCA20", func_mission_overlay_800FBE20);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FCA20", func_mission_overlay_800FC108);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FCA20", func_mission_overlay_800FC260);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FCA20", func_mission_overlay_800FC564);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FCA20", func_mission_overlay_800FC720);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FCA20", func_mission_overlay_800FD31C);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FCA20", func_mission_overlay_800FE434);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FCA20", func_mission_overlay_800FE500);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FCA20", func_mission_overlay_800FEC98);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FCA20", func_mission_overlay_800FED40);

void resetSecondaryWeaponCount(void) {
    u8 var_a0;

    for (var_a0 = 0; var_a0 < 2; var_a0++) {
        D_mission_overlay_8010CA30[var_a0].secondaryWeaponCount = D_mission_overlay_8010CA30[var_a0].secondaryWeaponReset;
    }
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FCA20", func_mission_overlay_800FEE74);

s32 func_mission_overlay_800FEECC(void) {
    s32 var_a0;

    var_a0 = 0;
    if (D_mission_overlay_8010CA30[0].secondaryWeapon == SECONDARY_WEAPON_BOMBS) {
        var_a0 = D_mission_overlay_8010CA30[0].secondaryWeaponState > 0U;
    }
    return var_a0;
}

u8 getHudSecondaryWeponCount(void) {
    return D_mission_overlay_8010CA30[0].secondaryWeaponCount;
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0FCA20", fake_func_800FEF04);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0FCA20", D_mission_overlay_800A942C);
