struct _m2c_stack_func_80055978 {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */

? func_80004E70(s32, ?, s32, s32, s32, u8 *);       /* extern */
extern s32 D_80138920;
extern s32 D_80138E80;
extern u8 D_80138E90;
static s32 D_8009ECA4 = 0xFFFFFFFF;                 /* const */
static s32 D_8009ECA8[2] = { 0, 0x00431021 };       /* const */

void func_80055978(s32 arg0) {
    s32 var_a1;
    u16 temp_t0;
    u8 *var_s0;
    u8 temp_v1;
    u8 var_a0;
    void *temp_a0;

    var_s0 = &D_80138E90;
    temp_a0 = (arg0 * 2) + *D_8009ECA8;
    temp_t0 = temp_a0->unk0;
    func_80004E70(D_80138920, 0, D_8009ECA4, D_80138E80 + temp_t0, temp_a0->unk2 - temp_t0, &D_80138E90);
    var_a1 = 0xF5;
loop_1:
    temp_v1 = *var_s0 ^ var_a1;
    var_a0 = temp_v1;
    var_a1 ^= temp_v1;
    if ((u32) ((temp_v1 - 0x61) & 0xFF) < 0x1AU) {
        var_a0 = temp_v1 - 0x20;
    }
    *var_s0 = var_a0;
    if (var_a0 & 0xFF) {
        var_s0 += 1;
        goto loop_1;
    }
}
