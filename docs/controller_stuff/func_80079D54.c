struct _m2c_stack_func_80079D54 {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */

f32 func_8007A068(s32, OSContPad *);                /* static */
f32 func_8007A0A8(s32);                             /* static */
extern u8 D_80130B56;

u16 func_80079D54(s32 arg0) {
    OSContPad *temp_a1;
    f32 var_fv1;
    f32 var_fv1_2;
    f32 var_fv1_3;
    f32 var_fv1_4;
    s32 temp_a0;
    u16 var_s0;

    temp_a0 = arg0 & 0xFF;
    temp_a1 = &D_80130B88[temp_a0];
    var_s0 = 0;
    if (temp_a1->errno == 1) {
        var_s0 = temp_a1->button;
    }
    if (D_80130B56 == 0) {
        var_fv1 = func_8007A068(temp_a0, temp_a1);
    } else {
        var_fv1 = 0.0f;
    }
    if (var_fv1 < -0.53f) {
        var_s0 |= 0x800000;
    }
    if (D_80130B56 == 0) {
        var_fv1_2 = func_8007A068(arg0 & 0xFF);
    } else {
        var_fv1_2 = 0.0f;
    }
    if (var_fv1_2 > 0.53f) {
        var_s0 |= 0x400000;
    }
    if (D_80130B56 == 0) {
        var_fv1_3 = func_8007A0A8(arg0 & 0xFF);
    } else {
        var_fv1_3 = 0.0f;
    }
    if (var_fv1_3 < -0.53f) {
        var_s0 |= 0x100000;
    }
    if (D_80130B56 == 0) {
        var_fv1_4 = func_8007A0A8(arg0 & 0xFF);
    } else {
        var_fv1_4 = 0.0f;
    }
    if (var_fv1_4 > 0.53f) {
        var_s0 |= 0x200000;
    }
    return var_s0;
}
