struct _m2c_stack_func_80005134 {
    /* 0x00 */ char pad0[0x28];
};                                                  /* size = 0x28 */

u32 func_80005134(u32 arg0, u8 *arg1) {
    struct D_80110A80_entry *var_s1;
    struct manifest_entry *var_v0_2;
    struct manifest_entry *var_v1;
    u32 var_s0;
    u32 var_v0;

    if (arg0 == -1U) {
        var_s0 = 0;
        var_s1 = D_80110A80;
loop_2:
        if (var_s1->one != 0) {
            var_v0_2 = find_manifest_entry(var_s0, arg1);
            if (var_v0_2 != NULL) {
                arg0 = var_s0;
                goto block_9;
            }
            goto block_6;
        }
block_6:
        var_s0 += 1;
        var_s1 += 0x50;
        if (var_s0 >= 4U) {
            var_v1 = NULL;
        } else {
            goto loop_2;
        }
    } else {
        var_v0_2 = find_manifest_entry(arg0, arg1);
block_9:
        var_v1 = var_v0_2;
    }
    var_v0 = 0;
    if (var_v1 != NULL) {
        if (var_v1->flags & 4) {
            return var_v1->compressed_size;
        }
        var_v0 = var_v1->decompressed_size;
        /* Duplicate return node #14. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
