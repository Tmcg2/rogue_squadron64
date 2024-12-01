struct _m2c_stack_func_8006DCCC {};                 /* size 0x0 */

extern ? D_8013A5C0;
static void *D_800A0A64[0xB] = {
    (void *)0x8003CB34,
    (void *)0x8003CB30,
    (void *)0x8003CB2C,
    (void *)0x8003CB28,
    (void *)0x8003CB24,
    (void *)0x8003CB20,
    (void *)0x8003CB1C,
    (void *)0x8003CB18,
    (void *)0x8003CB14,
    (void *)0x8003CB10,
    (void *)0x03A0F021,
}; /* const */

void func_8006DCCC(void) {
    s16 temp_a1;
    s8 temp_a2;
    s8 temp_v0;
    s8 var_a3;
    void **temp_a0;
    void *temp_v1;

    var_a3 = 0;
    do {
        temp_a0 = &D_800A0A64[var_a3];
        temp_v1 = (var_a3 * 8) + &D_8013A5C0;
        temp_v1->unk52 = (u8) (*temp_a0)->unk0;
        temp_a2 = 9 - var_a3;
        temp_a1 = 9 - var_a3;
        temp_v1->unk53 = (u8) (*temp_a0)->unk1;
        temp_v0 = var_a3 + 1;
        var_a3 = temp_v0;
        temp_v1->unk56 = temp_a1;
        temp_v1->unk55 = temp_a2;
        temp_v1->unk54 = (u8) (*temp_a0)->unk2;
    } while (temp_v0 < 0xA);
}
