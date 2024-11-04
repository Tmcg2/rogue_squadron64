struct _m2c_stack_func_80079EB0 {};                 /* size 0x0 */

extern ? D_8013A950;
extern ? D_8013A960;

void func_80079EB0(void) {
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a0;

    var_a0 = 0;
    do {
        temp_v1 = var_a0 & 0xFF;
        var_a0 += 1;
        temp_v1_2 = temp_v1 * 4;
        *(temp_v1_2 + &D_8013A960) = 0;
        *(temp_v1_2 + &D_8013A950) = 0;
    } while ((u32) (var_a0 & 0xFF) < 4U);
}
