struct _m2c_stack_func_800BFEA0 {};                 /* size 0x0 */

void func_800BFEA0(struct func_800C0084_d84_type *arg0, void **arg1, s32 arg2) {
    s32 temp_t1;
    u16 var_a0;
    u16 var_a0_2;
    u16 var_a0_3;
    u16 var_a0_4;
    u16 var_t0;
    u16 var_t0_2;
    u16 var_t0_3;
    u16 var_t0_4;
    u32 temp_v1;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_a1_3;
    void *temp_a1_4;
    void *var_a3;
    void *var_a3_2;
    void *var_a3_3;
    void *var_a3_4;

    temp_a0 = *arg1;
    temp_a0->unkC = (s32) (temp_a0->unkC & ~8);
    temp_a0_2 = *arg1;
    temp_a0_2->unkC = (s32) (temp_a0_2->unkC | 0x20000);
    arg0->unk20 = 0x0000000C;
    arg0->unk24 = 0x0A0C9005;
    arg0->unk28 = 0;
    var_t0 = 0;
    temp_t1 = (*arg1)->unk24;
    var_a0 = 1;
    var_a3 = temp_t1 + 8;
    do {
        temp_a1 = (var_t0 * 8) + temp_t1;
        if ((temp_a1->unk0 >= var_a3->unk0) && (temp_a1->unk2 >= var_a3->unk2)) {
            var_t0 = var_a0;
        }
        var_a0 += 1;
        var_a3 += 8;
    } while (var_a0 < 4U);
    arg0->unk2C = var_t0;
    var_t0_2 = 0;
    var_a0_2 = 1;
    var_a3_2 = temp_t1 + 8;
    do {
        temp_a1_2 = (var_t0_2 * 8) + temp_t1;
        if ((var_a3_2->unk0 >= temp_a1_2->unk0) && (temp_a1_2->unk2 >= var_a3_2->unk2)) {
            var_t0_2 = var_a0_2;
        }
        var_a0_2 += 1;
        var_a3_2 += 8;
    } while (var_a0_2 < 4U);
    arg0->unk2E = var_t0_2;
    var_t0_3 = 0;
    var_a0_3 = 1;
    var_a3_3 = temp_t1 + 8;
    do {
        temp_a1_3 = (var_t0_3 * 8) + temp_t1;
        if ((var_a3_3->unk0 >= temp_a1_3->unk0) && (var_a3_3->unk2 >= temp_a1_3->unk2)) {
            var_t0_3 = var_a0_3;
        }
        var_a0_3 += 1;
        var_a3_3 += 8;
    } while (var_a0_3 < 4U);
    arg0->unk30 = var_t0_3;
    var_t0_4 = 0;
    var_a0_4 = 1;
    var_a3_4 = temp_t1 + 8;
    do {
        temp_a1_4 = (var_t0_4 * 8) + temp_t1;
        if ((temp_a1_4->unk0 >= var_a3_4->unk0) && (var_a3_4->unk2 >= temp_a1_4->unk2)) {
            var_t0_4 = var_a0_4;
        }
        var_a0_4 += 1;
        var_a3_4 += 8;
    } while (var_a0_4 < 4U);
    temp_v1 = arg0->unk20;
    arg0->unk32 = var_t0_4;
    arg0->unk34 = 0;
    arg0->unk36 = 0;
    arg0->unk38 = 0x1000;
    arg0->unk3A = 0;
    arg0->unk3C = 0x1000;
    arg0->unk3E = 0x1000;
    arg0->unk40 = 0;
    arg0->unk42 = 0x1000;
    arg0->unk20 = temp_v1 | 0x180;
    if (arg2 & 0xFF) {
        arg0->unk20 = temp_v1 | 0x182;
    }
    (*arg1)->unk20->unk8 = &arg0->unk20;
}
