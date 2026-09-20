#include "common.h"

#include "mission_overlay/0B4EC0.h"

u32 D_mission_overlay_8010BC80[4];
f32 D_mission_overlay_8010BC90[4];

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0B4EC0", D_mission_overlay_800A5820);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0B4EC0", D_mission_overlay_800A5828);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0B4EC0", D_mission_overlay_800A5830);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0B4EC0", D_mission_overlay_800A5838);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0B4EC0", D_mission_overlay_800A5840);

INCLUDE_RODATA("asm/nonmatchings/mission_overlay/0B4EC0", D_mission_overlay_800A5848);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0B4EC0", playerXwingInit);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0B4EC0", playWeaponFireSound);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0B4EC0", playerXwingFireBlaster);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0B4EC0", playXwingEngineSound);

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0B4EC0", playerXwingUpdate);

u8 isWeaponSlotReady(u8 arg0) {
    u8 ret;
    ret = 0;
    if ((D_mission_overlay_8010BC80[arg0] != 1) || !(0.95f < D_mission_overlay_8010BC90[arg0])) {
        ret = 1;
    }
    return ret;
}

INCLUDE_ASM("asm/nonmatchings/mission_overlay/0B4EC0", fake_func_800B58B4);

// DO NOT DELTE ME I AM REQUIRED FOR MATCHING
const u32 rodat_pad_0B4EC0 = 0x24640001;
