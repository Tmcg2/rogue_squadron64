#include "common.h"

#include "game_settings.h"

#include "main/bss_80130B10.h"
#include "main/bss_80139010.h"
#include "main/033C0.h"
#include "main/7A8E0.h"

#if 0
void setNewAndPreviousButtonsPressed(void) {
    u32 var_a0;
    u32 temp_v0;
    u32 why;

    for (var_a0 = 0;  var_a0 < 4; var_a0++) {
        temp_v0 = readControllerInputs(var_a0);
        gNewButtonsPressed[var_a0] = temp_v0;
        gNewButtonsPressed[var_a0] &= ~gPreviousButtonsPressed[var_a0];
        gPreviousButtonsPressed[var_a0] = temp_v0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/main/7A8E0", setNewAndPreviousButtonsPressed);
#endif

u32 getControllerButtonAndStick(u8 arg0) {
    f32 var_fv1;
    u32 var_s0;

    var_s0 = 0;
    if (D_main_bss_80130B88[arg0].errno == 1) {
        var_s0 = D_main_bss_80130B88[arg0].button;
    }
    if (gGameSettings.unk16 == 0) {
        var_fv1 = getControllerStickXPercentage(arg0);
    } else {
        var_fv1 = 0.0f;
    }
    if (var_fv1 < -0.53f) {
        var_s0 |= 0x800000;
    }
    if (gGameSettings.unk16 == 0) {
        var_fv1 = getControllerStickXPercentage(arg0);
    } else {
        var_fv1 = 0.0f;
    }
    if (var_fv1 > 0.53f) {
        var_s0 |= 0x400000;
    }
    if (gGameSettings.unk16 == 0) {
        var_fv1 = getControllerStickYPercentage(arg0);
    } else {
        var_fv1 = 0.0f;
    }
    if (var_fv1 < -0.53f) {
        var_s0 |= 0x100000;
    }
    if (gGameSettings.unk16 == 0) {
        var_fv1 = getControllerStickYPercentage(arg0);
    } else {
        var_fv1 = 0.0f;
    }
    if (var_fv1 > 0.53f) {
        var_s0 |= 0x200000;
    }
    return var_s0;
}

void initNewAndPreviousButtonsPressed(void) {
    u8 var_a0;

    for (var_a0 = 0;  var_a0 < 4; var_a0++) {
        gNewButtonsPressed[var_a0] = 0;
        gPreviousButtonsPressed[var_a0] = 0;
    }
}

s32 isControllerStickReady(u8 arg0) {
    return D_main_bss_80130B88[arg0].errno == 1;
}

u32 readControllerInputs(u8 arg0) {
    if (gGameSettings.unk16 == 0) {
        return getControllerButtonAndStick(arg0);
    } else {
        return 0;
    }
}

u32 getControllerNewButtonsPressed(u8 arg0) {
    return gNewButtonsPressed[arg0];
}

void pollControllerUntilButtonsLatched(u8 arg0) {
    u16 var_v0;

    while(1) {
        if (gGameSettings.unk16 == 0) {
            var_v0 = getControllerButtonAndStick(arg0);
        } else {
            var_v0 = 0;
        }
        if (var_v0 == 0) break;
        pollControllerInputs();
    }
}

void unsetControllerNewButtonsPressed(u8 arg0, u32 arg1) {
    gNewButtonsPressed[arg0] &= ~arg1;
}

f32 getControllerStickXPercentageGated(u8 arg0) {
    if (gGameSettings.unk16 == 0) {
        return getControllerStickXPercentage(arg0);
    } else {
        return 0.0f;
    }
}

f32 getControllerStickYPercentageGated(u8 arg0) {
    if (gGameSettings.unk16 == 0) {
        return getControllerStickYPercentage(arg0);
    } else {
        return 0.0f;
    }
}

f32 getControllerStickXPercentage(u8 arg0) {
    return (f32)D_main_bss_80130B88[arg0].stick_x / 128.0;
}

f32 getControllerStickYPercentage(u8 arg0) {
    return (f32)D_main_bss_80130B88[arg0].stick_y / 128.0;
}

INCLUDE_ASM("asm/nonmatchings/main/7A8E0", fake_func_8007A0E8);
