struct _m2c_stack_decrypt_ns_hmt {};                 /* size 0x0 */

void decrypt_ns_hmt(u8 *arg0, s32 arg1, u32 arg2) {
    s32 var_t1;
    u32 var_t2;
    u8 *var_t0;
    u8 temp_t3;

    var_t0 = arg0;
    var_t1 = arg1;
    var_t2 = arg2;
    do {
        temp_t3 = *var_t0;
        *var_t0 = temp_t3 ^ (var_t2 & 0xFF);
        var_t2 = ((var_t2 << 0x18) | (var_t2 >> 8)) + temp_t3;
        var_t1 -= 1;
        var_t0 += 1;
    } while (var_t1 != 0);
}
