struct _m2c_stack_func_80079CE0 {
    /* 0x00 */ char pad0[0x28];
};                                                  /* size = 0x28 */

s32 func_80079F20(s32);                             /* static */
extern s32 D_8013A950;
extern s32 D_8013A960;

void func_80079CE0(void) {
    s32 *var_s0;
    s32 *var_s1;
    s32 temp_v0;
    u32 var_s2;

    var_s2 = 0;
    var_s0 = &D_8013A950;
    var_s1 = &D_8013A960;
    do {
        temp_v0 = func_80079F20(var_s2 & 0xFF);
        *var_s1 = temp_v0;
        var_s2 += 1;
        *var_s1 = temp_v0 & ~*var_s0;
        *var_s0 = temp_v0;
        var_s0 += 4;
        var_s1 += 4;
    } while (var_s2 < 4U);
}
