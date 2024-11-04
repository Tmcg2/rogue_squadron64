struct _m2c_stack_rs_crc32 {};                      /* size 0x0 */

u32 rs_crc32(u32 *crc32LUT, u8 *input, u32 length) {
    u32 var_a3;
    u32 var_t0;
    u8 *var_v0;

    var_t0 = 0xFAC5FAC5;
    var_a3 = 0;
    if (length != 0) {
        var_v0 = input;
        do {
            var_a3 += 1;
            var_t0 = crc32LUT[(var_t0 ^ *var_v0) & 0xFF] ^ (var_t0 >> 8);
            var_v0 = &input[var_a3];
        } while (var_a3 < length);
    }
    return var_t0;
}
