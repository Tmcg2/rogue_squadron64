struct _m2c_stack_func_8006EB48 {};                 /* size 0x0 */

void func_8006EB48(struct account_data *arg0, s32 arg1) {
    s32 temp_v1;
    s32 var_a2;
    u32 var_v0;

    var_a2 = 0;
    var_v0 = 0 & 0xFF;
    do {
        temp_v1 = var_a2 & 3;
        var_a2 += 1;
        // Collecting the medals for each level
        // There's 4 levels per byte don't know how many bytes are provisioned for all of them but its at least 5
        *(arg1 + var_v0) = ((s32) arg0->name[var_v0 >> 2].unk6 >> (temp_v1 * 2)) & 3;
        var_v0 = var_a2 & 0xFF;
    } while ((u32) (var_a2 & 0xFF) < 0x13U);
}
