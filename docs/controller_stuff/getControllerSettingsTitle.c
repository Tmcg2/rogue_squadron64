struct _m2c_stack_getControllerSettingsTitle {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */

? sprintf(s8 *, ? *, s8 *, s8 *);                   /* extern */
extern ? D_800A74F0;

void getControllerSettingsTitle(s8 *title) {
    s32 var_a0;
    s8 *var_s0;

    if (D_80130B40.languageSelect == 2) {
        var_s0 = getGameOrFrontText(0x000000B1);
        var_a0 = D_80130B40.controllerSetting + 0x7F;
    } else {
        var_a0 = 0x000000B1;
        var_s0 = getGameOrFrontText(D_80130B40.controllerSetting + 0x7F);
    }
    sprintf(title, &D_800A74F0, var_s0, getGameOrFrontText(var_a0));
}
