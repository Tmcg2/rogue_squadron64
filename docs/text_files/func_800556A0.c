struct _m2c_stack_func_800556A0 {
    /* 0x00 */ char pad0[0x38];
};                                                  /* size = 0x38 */

s32 func_80004AAC(s32, ?, s32, s32, s32);           /* extern */
? func_80004C70(s32, s32);                          /* extern */
? func_80004E70(s32, ?, s32, s32, s32, ? *);        /* extern */
extern ? D_80130B40;
extern s32 D_80137CFC;
extern s32 D_80138920;
extern ? D_80138E60;
extern u16 D_80138E7C;
extern s32 D_80138E80;
static ? *D_8009ECA0 = NULL;                        /* const */
static s32 D_8009ECA4 = 0xFFFFFFFF;                 /* const */
static ? *D_8009ECA8[2] = { NULL, (? *)0x00431021 }; /* const */

s32 func_800556A0(s32 arg0, s32 arg1) {
    ? *temp_v0_2;
    ? *temp_v0_5;
    s32 temp_s1;
    s32 temp_s1_2;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 var_a0;
    s32 var_s1;
    u8 *var_v1;
    u8 temp_v0_4;

    temp_v0 = func_80004AAC(D_80138920, 0, D_80137CFC, arg0, 1);
    func_80004E70(D_80138920, 0, temp_v0, 0, 0x0000001C, &D_80138E60);
    D_80138E7C = D_80138E60.unk2;
    if ((u8) D_80130B40.unk6 >= (u16) D_80138E60.unk0) {
        D_80130B40.unk6 = 0U;
    }
    if (!(arg1 & 0xFF)) {
        temp_s1 = (((D_80130B40.unk6 + 1) * 4) + &D_80138E60)->unk4 - ((D_80130B40.unk6 * 4) + &D_80138E60)->unk4;
        temp_v0_2 = rs_malloc(temp_s1, 0U);
        D_8009ECA0 = temp_v0_2;
        func_80004E70(D_80138920, 0, temp_v0, ((D_80130B40.unk6 * 4) + &D_80138E60)->unk4, temp_s1, temp_v0_2);
        func_80004C70(D_80138920, temp_v0);
        var_a0 = 0xF5;
        temp_v0_3 = D_80138E7C * 2;
        var_s1 = temp_s1 - temp_v0_3;
        var_v1 = D_8009ECA0 + temp_v0_3;
        if (var_s1 != 0) {
            do {
                var_s1 -= 1;
                temp_v0_4 = *var_v1 ^ var_a0;
                var_a0 ^= temp_v0_4;
                *var_v1 = temp_v0_4;
                var_v1 += 1;
            } while (var_s1 != 0);
        }
    } else {
        D_8009ECA4 = temp_v0;
        temp_s1_2 = D_80138E60.unk2 * 2;
        temp_v0_5 = rs_malloc(temp_s1_2, 0U);
        *D_8009ECA8 = temp_v0_5;
        func_80004E70(D_80138920, 0, temp_v0, ((D_80130B40.unk6 * 4) + &D_80138E60)->unk4, temp_s1_2, temp_v0_5);
        D_80138E80 = ((D_80130B40.unk6 * 4) + &D_80138E60)->unk4;
    }
    return 1;
}
