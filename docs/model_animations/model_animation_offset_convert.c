struct _m2c_stack_model_animation_offset_convert {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */

void model_animation_offset_convert(void *arg0) {
    s32 var_a1;
    s32 var_a2;
    u32 var_a3;
    u32 var_t0;
    void **temp_v1;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v0_7;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_4;
    void *temp_v1_5;
    void *temp_v1_6;

    temp_v0 = arg0->unk4;
    if (temp_v0 != NULL) {
        var_t0 = 0;
        arg0->unk4 = (void *) (temp_v0 + arg0);
        if (arg0->unk0 != 0) {
            var_a2 = 0;
            do {
                temp_v1 = var_a2 + arg0->unk4;
                temp_v0_2 = *temp_v1;
                if (temp_v0_2 != NULL) {
                    *temp_v1 = temp_v0_2 + arg0;
                    var_a3 = 0;
                    if ((var_a2 + arg0->unk4)->unkE != 0) {
                        var_a1 = 0;
                        do {
                            temp_v1_2 = var_a1 + *(var_a2 + arg0->unk4);
                            temp_v0_3 = temp_v1_2->unk8;
                            if (temp_v0_3 != NULL) {
                                temp_v1_2->unk8 = (void *) (temp_v0_3 + arg0);
                            }
                            temp_v1_3 = var_a1 + *(var_a2 + arg0->unk4);
                            temp_v0_4 = temp_v1_3->unkC;
                            if (temp_v0_4 != NULL) {
                                temp_v1_3->unkC = (void *) (temp_v0_4 + arg0);
                            }
                            temp_v1_4 = var_a1 + *(var_a2 + arg0->unk4);
                            temp_v0_5 = temp_v1_4->unk10;
                            if (temp_v0_5 != NULL) {
                                temp_v1_4->unk10 = (void *) (temp_v0_5 + arg0);
                            }
                            temp_v1_5 = var_a1 + *(var_a2 + arg0->unk4);
                            temp_v0_6 = temp_v1_5->unk14;
                            if (temp_v0_6 != NULL) {
                                temp_v1_5->unk14 = (void *) (temp_v0_6 + arg0);
                            }
                            temp_v1_6 = var_a1 + *(var_a2 + arg0->unk4);
                            temp_v0_7 = temp_v1_6->unk18;
                            if (temp_v0_7 != NULL) {
                                temp_v1_6->unk18 = (void *) (temp_v0_7 + arg0);
                            }
                            var_a3 += 1;
                            var_a1 += 0x1C;
                        } while (var_a3 < (u16) (var_a2 + arg0->unk4)->unkE);
                    }
                }
                var_t0 += 1;
                var_a2 += 0x10;
            } while (var_t0 < (u32) arg0->unk0);
        }
    }
}
