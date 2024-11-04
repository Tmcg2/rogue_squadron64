struct _m2c_stack_func_80005938 {};                 /* size 0x0 */

extern s32 D_80111254;

s32 func_80005938(s32 arg0) {
    s32 temp_v0;
    s32 var_a0;

    var_a0 = (arg0 + 0xF) & ~0xF;
    temp_v0 = D_80111254;
    if (var_a0 == 0) {
        var_a0 = 0x00000010;
    }
    D_80111254 = var_a0;
    return temp_v0;
}
