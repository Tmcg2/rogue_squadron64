struct _m2c_stack_func_80079FD8 {};                 /* size 0x0 */

extern ? D_8013A960;

void func_80079FD8(s32 arg0, ? arg1) {
    s32 *temp_a0;

    temp_a0 = ((arg0 & 0xFF) * 4) + &D_8013A960;
    *temp_a0 &= ~arg1;
}
