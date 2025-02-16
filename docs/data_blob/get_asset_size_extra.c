struct _m2c_stack_get_asset_size_extra {
    /* 0x00 */ char pad0[0x28];
};                                                  /* size = 0x28 */

s32 get_asset_size_extra(u32 arg0, u8 *arg1) {
    s32 var_a0;
    struct D_80110A80_entry *var_s1;
    struct manifest_entry *var_a1;
    struct manifest_entry *var_v0;
    u32 var_s0;

    if (arg0 == -1U) {
        var_s0 = 0;
        var_s1 = D_80110A80;
loop_2:
        if (var_s1->one != 0) {
            var_v0 = find_manifest_entry(var_s0, arg1);
            if (var_v0 != NULL) {
                arg0 = var_s0;
                goto block_9;
            }
            goto block_6;
        }
block_6:
        var_s0 += 1;
        var_s1 += 0x50;
        if (var_s0 >= 4U) {
            var_a1 = NULL;
        } else {
            goto loop_2;
        }
    } else {
        var_v0 = find_manifest_entry(arg0, arg1);
block_9:
        var_a1 = var_v0;
    }
    if (var_a1 == NULL) {
        return 0;
    }
    var_a0 = 0;
    if ((D_80110A80[arg0].unk4C != 0) && (var_a1->compressed_size != -1U)) {
        var_a0 = ((var_a1->flags & 0x44) == 0) << 6;
    }
    if (var_a1->flags & 4) {
        return var_a1->compressed_size + var_a0;
    }
    return var_a1->decompressed_size + var_a0;
}
