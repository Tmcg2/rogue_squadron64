struct _m2c_stack_func_80079F50 {};                 /* size 0x0 */

extern ? D_8013A960;

// Related to controller inputs in some way
s32 func_80079F50(s32 arg0) {
    return *(((arg0 & 0xFF) * 4) + &D_8013A960);
}
