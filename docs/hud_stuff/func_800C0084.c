struct _m2c_stack_func_800C0084 {
    /* 0x00 */ char pad0[0x18];
    /* 0x18 */ u8 sp18;                             /* inferred */
    /* 0x19 */ char pad19[0x17];                    /* maybe part of sp18[0x18]? */
    /* 0x30 */ s32 sp30;                            /* inferred */
    /* 0x34 */ s32 sp34;                            /* inferred */
    /* 0x38 */ char pad38[0x48];
};                                                  /* size = 0x80 */

s32 func_80003430(void *, s32);                     /* extern */
s32 func_80005080(s32, u8 *);                       /* extern */
? func_8001CA90(s32, ?, ?, ?);                      /* extern */
? func_8001CB64(s32, f32, f32, ?);                  /* extern */
? func_8003E684(u16, void *);                       /* extern */
? func_80054EF0(u8 *, ?, struct func_800C0084_type *, ?, s32); /* extern */
? func_800551D8(u8 *, ? *, ?, u16 *, s32, s32);     /* extern */
u16 func_800554D8(u8 *, ?, ?);                      /* extern */
? load_hmt_and_hob(? *, ?, ?, ?);                      /* extern */
u32 func_80056EB0(? *);                             /* extern */
? func_8005779C(u32, s32);                          /* extern */
u32 func_800594F8(u32, ? *);                        /* extern */
? func_8005955C(u32, ?, ?, ?);                      /* extern */
s32 func_8006B3D0(struct hud_sub_struct *);         /* extern */
s32 func_8006B3E0();                                /* extern */
s32 func_8006C940(?);                               /* extern */
? func_800BF790(struct func_800C0084_type *, u32);  /* extern */
s32 func_800FEEF4();                                /* extern */
? sprintf(u8 *, ? *, s32);                          /* extern */
? func_800BFDC4(struct func_800C0084_type *);       /* static */
? func_800BFEA0(struct func_800C0084_d84_type *, s32, ?); /* static */
u32 func_800C44D0(u32 *, s32 *);                    /* static */
? func_800C5F90(u32, s32);                          /* static */
? func_800C6468(u32, u32);                          /* static */
s32 func_800C6498(u32);                             /* static */
s32 func_800C723C(? *, ?);                          /* static */
extern u8 D_800A6378;
extern u8 D_800A6384;
extern u8 D_800A6394;
extern ? D_800A63A0;
extern ? D_800A63A8;
extern ? D_800A63B4;
extern ? D_800A63C4;
extern ? D_800A63CC;
extern ? D_800A63D4;
extern ? D_800A63DC;
extern ? D_800A63E4;
extern ? D_800A63EC;
extern ? D_800A63F4;
extern ? D_800A63FC;
extern ? D_800A6414;
extern ? D_800A6434;
extern u8 D_800A643C;
extern u8 D_800A6448;
extern f32 D_800A6488;
extern f32 D_800A648C;
extern f32 D_800A6490;
extern f32 D_800A6494;
extern f32 D_800A6498;
extern f32 D_800A649C;
extern f32 D_800A64A0;
extern f32 D_800A64A4;
extern f32 D_800A64A8;
extern f32 D_800A64AC;
extern f32 D_800A64B0;
extern f32 D_800A64B4;
extern f32 D_800A64B8;
extern f32 D_800A64BC;
extern f32 D_800A64C0;
extern f32 D_800A64C4;
extern f32 D_800A64C8;
extern f32 D_800A64CC;
extern f32 D_800A64D0;
extern f32 D_800A64D4;
extern f32 D_800A64D8;
extern f32 D_800A64DC;
extern f32 D_800A64E0;
extern f32 D_800A64E4;
extern f32 D_800A64E8;
extern f32 D_800A64EC;
extern f32 D_800A64F0;
extern f32 D_800A64F4;
extern f32 D_800A64F8;
extern f32 D_800A64FC;
extern f32 D_800A6500;
extern f32 D_800A6504;
extern f32 D_800A6508;
extern f32 D_800A650C;
extern f32 D_800A6510;
extern f32 D_800A6514;
extern f32 D_800A6518;
extern f32 D_800A651C;
extern f32 D_800A6520;
extern f32 D_800A6524;
extern f32 D_800A6528;
extern f32 D_800A652C;
extern f32 D_800A6530;
extern u32 D_800A6534;
extern f32 D_800A6538;
extern u32 D_800A653C;
extern f32 D_800A6540;
extern f32 D_800A6544;
extern f32 D_800A6548;
extern f32 D_800A654C;
extern f32 D_800A6550;
extern f32 D_800A6554;
extern f32 D_800A6558;
extern u32 D_800A655C;
extern f32 D_800A6584;
extern f32 D_800A65A0;
extern f32 D_800A65A4;
extern f32 D_800A65A8;
extern ? D_80109CD4;
extern ? D_80109CE4;
extern ? D_80109CF0;
extern ? D_8010BFD8;
extern u8 D_8010BFDB;
extern f32 D_8010BFDC;
extern s32 D_8010CA1C;
extern s32 D_80130B4C;
extern s32 D_80130B50;
extern s32 D_80137CFC;
extern s16 D_80137D00;
extern void *D_80138D1C;
extern u16 D_80139576;

s32 func_800C0084(void *arg0, s32 arg1, void *arg2) {
    u8 sp18;
    s32 sp30;
    s32 sp34;
    ? var_a2;
    f32 *var_s0_6;
    f32 temp_fs0;
    f32 temp_fs0_10;
    f32 temp_fs0_2;
    f32 temp_fs0_3;
    f32 temp_fs0_4;
    f32 temp_fs0_5;
    f32 temp_fs0_6;
    f32 temp_fs0_7;
    f32 temp_fs0_8;
    f32 temp_fs0_9;
    f32 temp_fs1;
    f32 temp_fs1_2;
    f32 temp_fs2;
    f32 temp_fs2_2;
    f32 temp_fs3;
    f32 temp_ft0;
    f32 temp_ft0_2;
    f32 temp_ft0_3;
    f32 temp_ft0_4;
    f32 temp_ft0_5;
    f32 temp_ft0_6;
    f32 temp_ft0_7;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv1;
    f32 temp_fv1_2;
    f32 temp_fv1_3;
    f32 temp_fv1_4;
    f32 temp_fv1_5;
    f32 temp_fv1_6;
    f32 temp_fv1_7;
    f32 var_fv0;
    f32 var_fv1;
    s16 temp_s4;
    s16 temp_s4_2;
    s32 temp_a0_2;
    s32 temp_a1;
    s32 temp_s0_4;
    s32 temp_s1_2;
    s32 temp_s3_2;
    s32 temp_s5;
    s32 temp_s6_2;
    s32 temp_s7;
    s32 temp_v0_10;
    s32 temp_v0_11;
    s32 temp_v0_12;
    s32 temp_v0_13;
    s32 temp_v0_25;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_6;
    s32 temp_v0_8;
    s32 var_a0;
    s32 var_a0_3;
    s32 var_a0_4;
    s32 var_a0_5;
    s32 var_a0_6;
    s32 var_condition_bit;
    s32 var_s1;
    s32 var_s3;
    s32 var_s3_2;
    s32 var_s3_3;
    s32 var_s3_4;
    s32 var_s3_5;
    s32 var_s4;
    s32 var_v0_12;
    s32 var_v0_13;
    s32 var_v0_5;
    s32 var_v0_7;
    s32 var_v0_8;
    s32 var_v0_9;
    s32 var_v1_7;
    s32 var_v1_8;
    struct func_800C0084_d84_type *temp_a0_3;
    struct func_800C0084_d84_type *temp_a0_4;
    struct func_800C0084_d84_type *temp_fp;
    struct func_800C0084_d84_type *temp_s6_3;
    struct func_800C0084_d84_type *temp_s7_2;
    struct func_800C0084_d84_type *var_a0_8;
    struct func_800C0084_d84_type *var_v1_9;
    struct func_800C0084_type *temp_s2;
    struct func_800C0084_type *temp_v0;
    struct func_800C0084_type *var_v1_2;
    struct hud_sub_struct *temp_s0;
    struct hud_sub_struct *temp_s0_2;
    struct hud_sub_struct *temp_s0_5;
    struct hud_sub_struct *temp_s1_3;
    struct hud_sub_struct *temp_v1;
    struct hud_sub_struct *temp_v1_10;
    struct hud_sub_struct *temp_v1_17;
    struct hud_sub_struct *temp_v1_18;
    struct hud_sub_struct *temp_v1_4;
    struct hud_sub_struct *temp_v1_6;
    struct hud_sub_struct *temp_v1_9;
    struct hud_sub_struct *var_a0_2;
    u16 *temp_s0_3;
    u16 *temp_s0_6;
    u16 *temp_s3_4;
    u16 *temp_s6;
    u16 *temp_v0_5;
    u16 *temp_v0_7;
    u16 *temp_v0_9;
    u16 *temp_v1_11;
    u16 *temp_v1_2;
    u16 *temp_v1_3;
    u16 *temp_v1_5;
    u16 *temp_v1_7;
    u16 *temp_v1_8;
    u16 *var_s5;
    u16 *var_v0_10;
    u16 *var_v0_14;
    u16 temp_v0_15;
    u16 temp_v0_18;
    u16 temp_v0_19;
    u16 temp_v0_20;
    u16 temp_v0_21;
    u16 temp_v0_22;
    u16 temp_v0_23;
    u16 temp_v0_24;
    u16 temp_v1_12;
    u16 temp_v1_13;
    u16 var_v0_11;
    u32 temp_a0;
    u32 temp_ft0_8;
    u32 temp_v0_14;
    u32 temp_v1_14;
    u32 temp_v1_15;
    u32 temp_v1_16;
    u32 var_a0_7;
    u32 var_fv0_2;
    u32 var_fv0_3;
    u32 var_s3_6;
    u8 *var_s0;
    u8 *var_s0_2;
    u8 *var_s0_3;
    u8 *var_s0_4;
    u8 *var_s0_5;
    u8 *var_v1;
    u8 *var_v1_3;
    u8 *var_v1_4;
    u8 *var_v1_5;
    u8 *var_v1_6;
    u8 temp_s1;
    u8 temp_s1_4;
    u8 temp_s1_5;
    u8 temp_s3;
    u8 temp_s3_3;
    u8 var_v0;
    u8 var_v0_2;
    u8 var_v0_3;
    u8 var_v0_4;
    u8 var_v0_6;
    void *temp_a1_2;
    void *temp_a1_3;
    void *temp_v0_16;
    void *temp_v0_17;
    void *var_a1;

    temp_s2 = arg0->unk4;
    temp_a1 = arg1 & 0xFFFF;
    switch (temp_a1) {                              /* switch 1 */
    case 1:                                         /* switch 1 */
        temp_v0 = rs_malloc(0x00000F80, 0U);
        arg0->unk4 = temp_v0;
        temp_fs0 = (f32) (func_8006B3D0() & 0xFFFF) / D_800A6488;
        temp_v1 = temp_v0->hud_elements;
        temp_fv1 = (f32) (func_8006B3E0() & 0xFFFF);
        temp_v1->prev = NULL;
        temp_v0->hud_elements[0].next = NULL;
        temp_v1->unknown0A = 1;
        temp_v1->texture_count = 1;
        temp_v1->texture_id_pointer = &temp_v0->hud_texture_ids[0x1D];
        temp_v1->xpos = 0.0f;
        temp_v1->height_scale = D_800A648C;
        temp_fv1_2 = temp_fv1 / D_800A6490;
        temp_v1->xy_offset_pointer = NULL;
        temp_v1->flags = 0;
        temp_v1->ypos = 0.0f;
        temp_v1->width_scale = temp_fs0;
        temp_v1->zero = 0.0f;
        temp_v1->xpos = 0.0f * temp_fs0;
        temp_v1->height_scale *= temp_fv1_2;
        temp_v1->ypos = 0.0f * temp_fv1_2;
        temp_v0->hud_element_colors[0].alpha = 0xFF;
        temp_v0->hud_element_colors[0].blue = 0xFF;
        temp_v0->hud_element_colors[0].green = 0xFF;
        temp_v0->hud_element_colors[0].red = 0xFF;
        temp_v0->hud_elements[0].flags |= 0x02400003;
        D_8010BFD8.unk3 = 0U;
        D_8010BFD8.unk2 = 0;
        D_8010BFD8.unk1 = 0;
        D_8010BFD8.unk0 = 0;
        temp_s4 = D_80137D00;
        temp_v0->rest01[9] = 0;
        temp_v0->rest01[8] = 0;
        if (&D_800A6378 != NULL) {
            rs_strcpy(&sp18, &D_800A6378);
        }
        var_a0 = 0;
        var_s0 = &sp18;
        if (sp18 != 0) {
            var_v1 = var_s0;
            var_v0 = *var_v1;
            do {
                var_v1 += 1;
                if (var_v0 == 0x2F) {
                    var_s0 = &(&sp18)[var_a0].unk1;
                }
                var_v0 = *var_v1;
                var_a0 += 1;
            } while (var_v0 != 0);
        }
        temp_s3 = *var_s0;
        *var_s0 = temp_s4 + 0x30;
        if (func_80005080(D_80137CFC, &sp18) == 1) {
            var_s3 = 1;
        } else {
            *var_s0 = temp_s3;
            var_s3 = 0;
        }
        func_80054EF0(&sp18, 0, temp_v0, 0, 0);
        if (var_s3 != 0) {
            var_s3_2 = 0;
            temp_fs0_2 = (f32) (func_8006B3D0() & 0xFFFF) / D_800A6494;
            temp_v0_2 = func_8006B3E0();
            var_a0_2 = &temp_v0->hud_elements[7];
            var_a0_2->prev = NULL;
            temp_v0->hud_elements[7].next = NULL;
            var_a0_2->unknown0A = 1;
            var_a0_2->texture_count = 1;
            temp_v1_2 = temp_v0->hud_xy_offsets[2];
            var_a0_2->xy_offset_pointer = (struct xy_offset *) temp_v1_2;
            var_a0_2->flags = (temp_v1_2 != NULL) * 0x10;
            var_a0_2->xpos = D_800A6498;
            var_a0_2->ypos = D_800A649C;
            temp_v1_3 = &temp_v0->hud_texture_ids[0xE];
            var_a0_2->texture_id_pointer = temp_v0->hud_texture_ids;
            var_a0_2->zero = 0.0f;
            var_a0_2->height_scale = D_800A64A0;
            var_a0_2->width_scale = D_800A64A0;
            var_a0_2->xpos = D_800A6498 * temp_fs0_2;
            var_a0_2->ypos *= (f32) (temp_v0_2 & 0xFFFF) / D_800A64A4;
            temp_v1_3->unk207 = 0xFF;
            temp_v1_3->unk206 = 0xFF;
            temp_v1_3->unk205 = 0xFF;
            temp_v1_3->unk204 = 0xFF;
            temp_v0->hud_elements[7].unknown0A = 4;
        } else {
            var_s3_2 = 0;
            temp_fs0_3 = (f32) (func_8006B3D0() & 0xFFFF) / D_800A64A8;
            temp_v1_4 = &temp_v0->hud_elements[7];
            var_a0_2 = (struct hud_sub_struct *)1;
            temp_ft0 = (f32) (func_8006B3E0() & 0xFFFF);
            temp_v1_4->prev = NULL;
            temp_v0->hud_elements[7].next = NULL;
            temp_v1_4->unknown0A = 1;
            temp_v1_4->height_scale = D_800A64AC;
            temp_ft0_2 = temp_ft0 / D_800A64B4;
            temp_v1_4->xpos = D_800A64B0;
            temp_v1_4->ypos = D_800A64B8;
            temp_v1_4->texture_count = 1;
            temp_v1_4->texture_id_pointer = temp_v0->hud_texture_ids;
            temp_v1_4->xy_offset_pointer = NULL;
            temp_v1_4->flags = 0;
            temp_v1_4->zero = 0.0f;
            temp_v1_4->width_scale = temp_fs0_3;
            temp_v1_4->height_scale *= temp_ft0_2;
            temp_v1_4->xpos = D_800A64B0 * temp_fs0_3;
            temp_v1_4->ypos *= temp_ft0_2;
            temp_v1_5 = &temp_v0->hud_texture_ids[0xE];
            temp_v1_5->unk207 = 0xFF;
            temp_v1_5->unk206 = 0xFF;
            temp_v1_5->unk205 = 0xFF;
            temp_v1_5->unk204 = 0xFF;
        }
        var_v1_2 = temp_v0;
        do {
            var_v1_2->hud_xy_offsets[2][0] = 0;
            var_v1_2->hud_xy_offsets[2][1] = var_s3_2 << 5;
            var_s3_2 += 1;
            var_v1_2 += 4;
        } while (var_s3_2 < 4);
        temp_v0->hud_element_colors[7].red = 0xBE;
        temp_v0->hud_element_colors[7].green = 5;
        temp_v0->hud_element_colors[7].blue = 0;
        temp_v0->hud_elements[7].flags |= 0x02400003;
        temp_fs0_4 = (f32) (func_8006B3D0(var_a0_2) & 0xFFFF) / D_800A64BC;
        temp_v1_6 = &temp_v0->hud_elements[8];
        temp_v0_3 = func_8006B3E0() & 0xFFFF;
        temp_v1_6->prev = NULL;
        temp_v0->hud_elements[8].next = NULL;
        temp_v1_6->xy_offset_pointer = NULL;
        temp_v1_6->flags = 0;
        temp_v1_6->zero = 0.0f;
        temp_v1_6->height_scale = D_800A64C4;
        temp_v1_6->xpos = D_800A64C0;
        temp_fv1_3 = (f32) temp_v0_3 / D_800A64C8;
        temp_v1_6->width_scale = temp_fs0_4;
        temp_v1_6->unknown0A = 1;
        temp_v1_6->texture_count = 1;
        temp_v1_6->ypos = D_800A64CC;
        temp_v1_6->texture_id_pointer = &temp_v0->hud_texture_ids[4];
        temp_v1_6->height_scale *= temp_fv1_3;
        temp_v1_6->xpos *= temp_fs0_4;
        temp_v1_6->ypos = D_800A64CC * temp_fv1_3;
        temp_v1_7 = &temp_v0->hud_texture_ids[0x10];
        temp_v1_7->unk207 = 0xFF;
        temp_v1_7->unk206 = 0xFF;
        temp_v1_7->unk205 = 0xFF;
        temp_v1_7->unk204 = 0xFF;
        if (D_80130B50 & 1) {
            temp_v0->hud_elements[8].xpos = D_800A64D0;
        }
        temp_v0->hud_texture_ids[4] = func_800554D8(&D_800A6384, 0, 0);
        temp_v0->hud_element_colors[8].red = 0x1F;
        temp_v0->hud_element_colors[8].green = 0xA5;
        temp_v0->hud_element_colors[8].blue = 0x0C;
        temp_v0->hud_elements[8].flags |= 0x02400003;
        temp_v0->rest01[2] = func_800C44D0(&temp_v0->rest01[1], &sp30);
        func_8001CB64(sp30, D_800A64D4, D_800A64D4, 0x3E4CCCCD);
        func_8001CA90(sp30, 0x3F0CCCCD, 0xBEBE76C9, 0x3F666666);
        rs_strcpy(&sp18, (u8 *) D_80109CB0[func_8006C940(0)]);
        var_a0_3 = 0;
        var_s0_2 = &sp18;
        if (sp18 != 0) {
            var_v1_3 = var_s0_2;
            var_v0_2 = *var_v1_3;
            do {
                var_v1_3 += 1;
                if (var_v0_2 == 0x2F) {
                    var_s0_2 = &(&sp18)[var_a0_3].unk1;
                }
                var_v0_2 = *var_v1_3;
                var_a0_3 += 1;
            } while (var_v0_2 != 0);
        }
        temp_s1 = *var_s0_2;
        *var_s0_2 = D_80137D00 + 0x30;
        var_s3_3 = 0;
        if (func_80005080(D_80137CFC, &sp18) != 1) {
            *var_s0_2 = temp_s1;
        } else {
            var_s3_3 = 1;
        }
        temp_v0->hud_texture_ids[7] = func_800554D8(&sp18, 0, 0);
        temp_fs2 = D_800A64D8;
        temp_fs0_5 = (f32) (func_8006B3D0() & 0xFFFF) / temp_fs2;
        temp_s0 = &temp_v0->hud_elements[2];
        temp_s6 = &temp_v0->hud_texture_ids[7];
        temp_s1_2 = var_s3_3 != 0;
        temp_v0_4 = func_8006B3E0() & 0xFFFF;
        temp_fs1 = D_800A64E8;
        temp_s3_2 = temp_s1_2 & 1;
        temp_s0->prev = NULL;
        temp_v0->hud_elements[2].next = NULL;
        temp_s0->unknown0A = 1;
        temp_s0->texture_count = 1;
        temp_s0->texture_id_pointer = temp_s6;
        temp_s0->xy_offset_pointer = NULL;
        temp_s0->flags = 0;
        temp_s0->zero = 0.0f;
        temp_s0->height_scale = D_800A64E4;
        temp_s0->width_scale = D_800A64E4;
        temp_s0->ypos = D_800A64E0;
        temp_ft0_3 = (f32) temp_v0_4 / temp_fs1;
        temp_s0->xpos = D_800A64DC;
        if (temp_s3_2 == 0) {
            temp_s0->width_scale = temp_fs0_5;
            temp_s0->height_scale *= temp_ft0_3;
        }
        temp_s5 = temp_s1_2 & 2;
        if (temp_s5 == 0) {
            temp_s0->xpos *= temp_fs0_5;
            temp_s0->ypos *= temp_ft0_3;
        }
        temp_v0_5 = &temp_v0->hud_texture_ids[4];
        temp_v0_5->unk207 = 0xFF;
        temp_v0_5->unk206 = 0xFF;
        temp_v0_5->unk205 = 0xFF;
        temp_v0_5->unk204 = 0xFF;
        temp_v0->hud_elements[2].flags |= 0x02400003;
        temp_fs0_6 = (f32) (func_8006B3D0() & 0xFFFF) / temp_fs2;
        temp_s0_2 = &temp_v0->hud_elements[3];
        temp_v0_6 = func_8006B3E0() & 0xFFFF;
        temp_s0_2->prev = NULL;
        temp_v0->hud_elements[3].next = NULL;
        temp_s0_2->unknown0A = 1;
        temp_s0_2->texture_count = 1;
        temp_s0_2->texture_id_pointer = temp_s6;
        temp_s0_2->xy_offset_pointer = NULL;
        temp_s0_2->flags = 0;
        temp_s0_2->zero = 0.0f;
        temp_s0_2->xpos = D_800A64EC;
        temp_ft0_4 = (f32) temp_v0_6 / temp_fs1;
        temp_s0_2->ypos = D_800A64F0;
        temp_s0_2->height_scale = D_800A64F4;
        temp_s0_2->width_scale = D_800A64F4;
        if (temp_s3_2 == 0) {
            temp_s0_2->width_scale = temp_fs0_6 * D_800A64F4;
            temp_s0_2->height_scale = D_800A64F4 * temp_ft0_4;
        }
        temp_v0_7 = &temp_v0->hud_texture_ids[6];
        if (temp_s5 == 0) {
            temp_s0_2->xpos *= temp_fs0_6;
            temp_s0_2->ypos *= temp_ft0_4;
        }
        temp_v0_7->unk207 = 0xFF;
        temp_v0_7->unk206 = 0xFF;
        temp_v0_7->unk205 = 0xFF;
        temp_v0_7->unk204 = 0xFF;
        temp_s4_2 = D_80137D00;
        temp_v0->hud_elements[3].flags |= 0x02400003;
        if (&D_800A6394 != NULL) {
            rs_strcpy(&sp18, &D_800A6394);
        }
        var_a0_4 = 0;
        var_s0_3 = &sp18;
        if (sp18 != 0) {
            var_v1_4 = var_s0_3;
            var_v0_3 = *var_v1_4;
            do {
                var_v1_4 += 1;
                if (var_v0_3 == 0x2F) {
                    var_s0_3 = &(&sp18)[var_a0_4].unk1;
                }
                var_v0_3 = *var_v1_4;
                var_a0_4 += 1;
            } while (var_v0_3 != 0);
        }
        temp_s3_3 = *var_s0_3;
        *var_s0_3 = temp_s4_2 + 0x30;
        if (func_80005080(D_80137CFC, &sp18) == 1) {
            var_s3_4 = 1;
        } else {
            *var_s0_3 = temp_s3_3;
            var_s3_4 = 0;
        }
        var_a2 = 0xA;
        if (var_s3_4 != 0) {
            var_a2 = 0x14;
        }
        temp_s0_3 = &temp_v0->hud_texture_ids[0xC];
        func_800551D8(&sp18, &D_800A63A0, var_a2, temp_s0_3, 0x3E8, 0);
        temp_s1_3 = &temp_v0->hud_elements[1];
        temp_fs3 = D_800A64F8;
        temp_fs0_7 = (f32) (func_8006B3D0() & 0xFFFF) / temp_fs3;
        temp_v0_8 = func_8006B3E0();
        temp_s1_3->prev = NULL;
        temp_v0->hud_elements[1].next = NULL;
        temp_s1_3->texture_id_pointer = temp_s0_3;
        temp_s0_4 = var_s3_4 != 0;
        temp_fs1_2 = D_800A6504;
        temp_fs2_2 = D_800A6508;
        temp_s7 = temp_s0_4 & 1;
        temp_s1_3->unknown0A = 1;
        temp_s1_3->texture_count = 1;
        temp_s1_3->xy_offset_pointer = NULL;
        temp_s1_3->flags = 0;
        temp_s1_3->zero = 0.0f;
        temp_s1_3->xpos = D_800A64FC;
        temp_ft0_5 = (f32) (temp_v0_8 & 0xFFFF) / temp_fs2_2;
        temp_s1_3->height_scale = temp_fs1_2;
        temp_s1_3->width_scale = temp_fs1_2;
        temp_s1_3->ypos = D_800A6500;
        if (temp_s7 == 0) {
            temp_s1_3->width_scale = temp_fs0_7;
            temp_s1_3->height_scale = temp_fs1_2 * temp_ft0_5;
        }
        temp_s6_2 = temp_s0_4 & 2;
        if (temp_s6_2 == 0) {
            temp_s1_3->xpos *= temp_fs0_7;
            temp_s1_3->ypos *= temp_ft0_5;
        }
        var_s4 = 0x51;
        temp_v0_9 = &temp_v0->hud_texture_ids[2];
        temp_v0_9->unk207 = 0xFF;
        temp_v0_9->unk206 = 0xFF;
        temp_v0_9->unk205 = 0xFF;
        temp_v0_9->unk204 = 0xFF;
        temp_v0->hud_element_colors[1].alpha = 0x64;
        temp_v0->hud_elements[1].flags |= 0x02400003;
        if (var_s3_4 != 0) {
            var_s4 = 0x50;
        }
        temp_s0_5 = &temp_v0->hud_elements[4];
        temp_fs0_8 = (f32) (func_8006B3D0() & 0xFFFF) / temp_fs3;
        temp_v0_10 = func_8006B3E0();
        temp_s3_4 = &temp_v0->hud_texture_ids[0xA];
        temp_v1_8 = temp_v0->hud_xy_offsets[0];
        temp_s0_5->prev = NULL;
        temp_v0->hud_elements[4].next = NULL;
        temp_s0_5->xy_offset_pointer = (struct xy_offset *) temp_v1_8;
        temp_s0_5->ypos = (f32) var_s4;
        temp_ft0_6 = (f32) (temp_v0_10 & 0xFFFF) / temp_fs2_2;
        temp_s0_5->unknown0A = 1;
        temp_s0_5->texture_count = 1;
        temp_s0_5->texture_id_pointer = temp_s3_4;
        temp_s0_5->flags = (temp_v1_8 != NULL) * 0x10;
        temp_s0_5->zero = 0.0f;
        temp_s0_5->height_scale = temp_fs1_2;
        temp_s0_5->width_scale = temp_fs1_2;
        temp_s0_5->xpos = D_800A650C;
        if (temp_s7 == 0) {
            temp_s0_5->width_scale = temp_fs0_8;
            temp_s0_5->height_scale = temp_fs1_2 * temp_ft0_6;
        }
        if (temp_s6_2 == 0) {
            temp_s0_5->xpos *= temp_fs0_8;
            temp_s0_5->ypos *= temp_ft0_6;
        }
        temp_s0_6 = &temp_v0->hud_texture_ids[8];
        temp_s0_6->unk207 = 0xFF;
        temp_s0_6->unk206 = 0xFF;
        temp_s0_6->unk205 = 0xFF;
        temp_s0_6->unk204 = 0xFF;
        temp_v0->hud_xy_offsets[0][0] = 0;
        temp_v0->hud_xy_offsets[1][0] = 8;
        temp_v0->hud_xy_offsets[1][1] = 0;
        temp_v0->hud_xy_offsets[0][1] = 0;
        temp_v0->hud_elements[4].flags |= 0x02400003;
        temp_fs0_9 = (f32) (func_8006B3D0() & 0xFFFF) / temp_fs3;
        temp_v1_9 = &temp_v0->hud_elements[5];
        temp_ft0_7 = (f32) (func_8006B3E0() & 0xFFFF) / temp_fs2_2;
        temp_v1_9->prev = NULL;
        temp_v0->hud_elements[5].next = NULL;
        temp_v1_9->height_scale = temp_fs1_2;
        temp_v1_9->unknown0A = 1;
        temp_v1_9->xpos = D_800A6510;
        temp_v1_9->ypos = D_800A6514;
        temp_v1_9->texture_count = 1;
        temp_v1_9->texture_id_pointer = temp_s0_6;
        temp_v1_9->xy_offset_pointer = NULL;
        temp_v1_9->flags = 0;
        temp_v1_9->zero = 0.0f;
        temp_v1_9->width_scale = temp_fs0_9;
        temp_v1_9->height_scale = temp_fs1_2 * temp_ft0_7;
        temp_v1_9->xpos = D_800A6510 * temp_fs0_9;
        temp_v1_9->ypos *= temp_ft0_7;
        temp_s3_4->unk207 = 0xFF;
        temp_s3_4->unk206 = 0xFF;
        temp_s3_4->unk205 = 0xFF;
        temp_s3_4->unk204 = 0xFF;
        func_800BFDC4(temp_v0);
        sprintf(&sp18, &D_800A63A8, *((temp_v0->unkF7D * 4) + &D_80109CD4));
        var_a0_5 = 0;
        var_s0_4 = &sp18;
        if (sp18 != 0) {
            var_v1_5 = var_s0_4;
            var_v0_4 = *var_v1_5;
            do {
                var_v1_5 += 1;
                if (var_v0_4 == 0x2F) {
                    var_s0_4 = &(&sp18)[var_a0_5].unk1;
                }
                var_v0_4 = *var_v1_5;
                var_a0_5 += 1;
            } while (var_v0_4 != 0);
        }
        temp_s1_4 = *var_s0_4;
        *var_s0_4 = D_80137D00 + 0x30;
        var_v0_5 = 0;
        if (func_80005080(D_80137CFC, &sp18) != 1) {
            *var_s0_4 = temp_s1_4;
        } else {
            var_v0_5 = 1;
        }
        if (var_v0_5 != 0) {
            temp_v0->hud_elements[5].height_scale = D_800A6518;
            temp_v0->hud_elements[5].width_scale = D_800A6518;
        }
        temp_v0->hud_texture_ids[8] = func_800554D8(&sp18, 0, 0);
        temp_v0->hud_elements[5].flags |= 0x02400003;
        temp_v0->hud_element_colors[5].red = (unaligned s32) *((temp_v0->unkF7E * 4) + &D_80109CF0);
        temp_fs0_10 = (f32) (func_8006B3D0((struct hud_sub_struct *)0x02400003) & 0xFFFF) / D_800A651C;
        temp_v1_10 = &temp_v0->hud_elements[6];
        temp_v0_11 = func_8006B3E0() & 0xFFFF;
        temp_v1_10->prev = NULL;
        temp_v0->hud_elements[6].next = NULL;
        temp_v1_10->xy_offset_pointer = NULL;
        temp_v1_10->flags = 0;
        temp_v1_10->zero = 0.0f;
        temp_v1_10->height_scale = D_800A6524;
        temp_v1_10->xpos = D_800A6520;
        temp_fv1_4 = (f32) temp_v0_11 / D_800A6528;
        temp_v1_10->width_scale = temp_fs0_10;
        temp_v1_10->unknown0A = 1;
        temp_v1_10->texture_count = 1;
        temp_v1_10->ypos = D_800A652C;
        temp_v1_10->texture_id_pointer = &temp_v0->hud_texture_ids[9];
        temp_v1_10->height_scale *= temp_fv1_4;
        temp_v1_10->xpos *= temp_fs0_10;
        temp_v1_10->ypos = D_800A652C * temp_fv1_4;
        temp_v1_11 = &temp_v0->hud_texture_ids[0xC];
        temp_v1_11->unk207 = 0xFF;
        temp_v1_11->unk206 = 0xFF;
        temp_v1_11->unk205 = 0xFF;
        temp_v1_11->unk204 = 0xFF;
        sprintf(&sp18, &D_800A63B4, temp_v0->unkF7E + 0x31);
        var_a0_6 = 0;
        var_s0_5 = &sp18;
        if (sp18 != 0) {
            var_v1_6 = var_s0_5;
            var_v0_6 = *var_v1_6;
            do {
                var_v1_6 += 1;
                if (var_v0_6 == 0x2F) {
                    var_s0_5 = &(&sp18)[var_a0_6].unk1;
                }
                var_v0_6 = *var_v1_6;
                var_a0_6 += 1;
            } while (var_v0_6 != 0);
        }
        temp_s1_5 = *var_s0_5;
        *var_s0_5 = D_80137D00 + 0x30;
        var_v0_7 = 0;
        if (func_80005080(D_80137CFC, &sp18) != 1) {
            *var_s0_5 = temp_s1_5;
        } else {
            var_v0_7 = 1;
        }
        if (var_v0_7 != 0) {
            temp_v0->hud_elements[6].height_scale = D_800A6530;
            temp_v0->hud_elements[6].width_scale = D_800A6530;
        }
        temp_v0->hud_texture_ids[9] = func_800554D8(&sp18, 0, 0);
        temp_v0->hud_elements[6].flags |= 0x02400003;
        temp_v0->hud_element_colors[6].red = (unaligned s32) *((temp_v0->unkF7E * 4) + &D_80109CE4);
        temp_v0->unk228 = 0;
        temp_v0->rest01[4] = 0;
        temp_v0->rest01[7] = D_800A6534;
        temp_v0_12 = func_800C723C(&D_800A63C4, 0x02400003);
        if (temp_v0_12 != 0) {
            func_800BFEA0(temp_v0->unkD84, temp_v0_12, 1);
            temp_v0_13 = func_800C723C(&D_800A63CC);
            if (temp_v0_13 != 0) {
                func_800BFEA0(&temp_v0->unkD84[6], temp_v0_13, 1);
                func_800BFEA0(&temp_v0->unkD84[1], func_800C723C(&D_800A63D4), 1);
                func_800BFEA0(&temp_v0->unkD84[2], func_800C723C(&D_800A63DC), 1);
                func_800BFEA0(&temp_v0->unkD84[3], func_800C723C(&D_800A63E4), 1);
                func_800BFEA0(&temp_v0->unkD84[4], func_800C723C(&D_800A63EC), 1);
                func_800BFEA0(&temp_v0->unkD84[5], func_800C723C(&D_800A63F4), 1);
                temp_v0->unkF7C = 1;
            }
        } else {
            temp_v0->unkF7C = 0;
        }
        load_hmt_and_hob(&D_800A63FC, 0, 0, 0);
        temp_v0_14 = func_80056EB0(&D_800A6414);
        temp_v0->rest01[0xA] = temp_v0_14;
        func_8005955C(temp_v0_14, 0, 0x30440000, 0x100008);
        if (D_80130B50 & 1) {
            func_8005955C(temp_v0->rest01[0xA], 0, 0x10420000, 0x31C00000);
        }
        temp_v0->rest01[0xB] = func_800594F8(temp_v0->rest01[0xA], &D_800A6434);
        temp_v0->unk258 = 0;
        temp_v0->hud_texture_ids[0x1C] = func_800554D8(&D_800A643C, 0, 0);
        temp_v0->hud_texture_ids[0x1D] = func_800554D8(&D_800A6448, 0, 0);
        D_8010BFDC = D_800A6538;
        func_8003E684(D_80139576, arg0);
        temp_v0->rest01[3] = 0;
        break;
    case 12:                                        /* switch 1 */
        temp_s2->unk228 = 0U;
        temp_s2->rest01[4] = 0;
        temp_s2->rest01[5] = 0;
        temp_s2->rest01[6] = 0;
        temp_s2->hud_elements[1].texture_id_pointer = temp_s2 + (((s8) D_80130B10.unk0 * 2) + 0x18);
        break;
    case 5:                                         /* switch 1 */
        temp_s2->rest01[9] = D_800A653C;
        temp_s2->rest01[8] = arg2->unk0;
        temp_s2->unkF7F = func_80003430(arg2, temp_a1) & 1;
        break;
    case 2:                                         /* switch 1 */
        func_8005779C(temp_s2->rest01[0xA], temp_a1);
        rs_free((void *) temp_s2->rest01[2]);
        break;
    case 3:                                         /* switch 1 */
        temp_fv0 = (bitwise f32) arg2->unk0 * D_800A6540;
        if (!(D_800A6544 <= temp_fv0)) {
            var_v1_7 = (s32) temp_fv0;
        } else {
            var_v1_7 = (s32) (temp_fv0 - D_800A6544) | 0x80000000;
        }
        if (D_8010CA1C & 0x180) {
            temp_fv1_5 = D_8010BFDC - (2.0f * (bitwise f32) arg2->unk0);
            var_fv0 = 0.0f;
            var_condition_bit = temp_fv1_5 < 0.0f;
            D_8010BFDC = temp_fv1_5;
        } else {
            temp_fv1_6 = D_8010BFDC + (2.0f * (bitwise f32) arg2->unk0);
            var_fv0 = D_800A6548;
            D_8010BFDC = temp_fv1_6;
            var_condition_bit = var_fv0 < temp_fv1_6;
        }
        if (var_condition_bit) {
            D_8010BFDC = var_fv0;
        }
        temp_v1_12 = temp_s2->unk228;
        temp_v1_13 = temp_v1_12 + var_v1_7;
        if (temp_v1_12 <= 0xFFFEU) {
            temp_a0 = temp_v1_13 & 0xFFFF;
            temp_s2->unk228 = temp_v1_13;
            if (temp_a0 < 0x100U) {
                temp_s2->hud_element_colors[1].alpha = 0;
            } else {
                temp_v0_15 = temp_v1_13 + var_v1_7;
                if (temp_a0 < 0x180U) {
                    var_v0_8 = (temp_s2->unk228 - 0x100) * 0xFF;
                    if (var_v0_8 < 0) {
                        var_v0_8 += 0x7F;
                    }
                    temp_s2->hud_element_colors[1].alpha = (u8) (var_v0_8 >> 7);
                } else {
                    temp_s2->unk228 = temp_v0_15;
                    temp_v1_14 = temp_v0_15 & 0xFFFF;
                    if (temp_v1_14 < 0x680U) {
                        temp_s2->hud_element_colors[1].alpha = 0xFF;
                    } else if (temp_v1_14 < 0x780U) {
                        var_v0_9 = (0x780 - temp_s2->unk228) * 0xFF;
                        if (var_v0_9 < 0) {
                            var_v0_9 += 0xFF;
                        }
                        temp_s2->hud_element_colors[1].alpha = (u8) (var_v0_9 >> 8);
                    } else {
                        temp_s2->hud_element_colors[1].alpha = 0;
                        temp_s2->unk228 = 0xFFFFU;
                    }
                }
            }
        }
        func_800BF790(temp_s2, arg2->unk0);
        func_800C1D3C(temp_s2, (bitwise f32) arg2->unk0);
        var_s3_5 = func_800FEEF4() & 0xFF;
        if (var_s3_5 >= 0x64) {
            var_s3_5 = 0x63;
        }
        temp_s2->hud_texture_ids[0xA] = temp_s2->hud_texture_ids[var_s3_5 / 10].unk18;
        temp_s2->hud_texture_ids[0xB] = temp_s2->hud_texture_ids[var_s3_5 % 10].unk18;
        var_v0_10 = &temp_s2->hud_texture_ids[0xB];
        if (var_s3_5 >= 0xA) {
            var_v0_10 = &temp_s2->hud_texture_ids[0xA];
        }
        temp_s2->hud_elements[4].texture_id_pointer = var_v0_10;
        var_v0_11 = 1;
        if (var_s3_5 >= 0xA) {
            var_v0_11 = 2;
        }
        temp_s2->hud_elements[4].texture_count = var_v0_11;
        if ((temp_s2->hud_elements[4].texture_count & 0xFFFF) == 1) {
            var_fv1 = D_800A654C;
            var_v0_12 = func_8006B3D0() & 0xFFFF;
        } else if (D_80130B50 & 1) {
            var_fv1 = D_800A6550;
            var_v0_12 = func_8006B3D0() & 0xFFFF;
        } else {
            var_v0_12 = func_8006B3D0() & 0xFFFF;
            var_fv1 = D_800A6554;
        }
        temp_s2->hud_elements[4].xpos = ((f32) var_v0_12 * var_fv1) / D_800A6558;
        func_800C6468(temp_s2->rest01[2], arg2->unk0);
        temp_ft0_8 = temp_s2->rest01[9];
        if ((bitwise f32) temp_ft0_8 > 0.0f) {
            temp_fv0_2 = (bitwise f32) temp_ft0_8 - ((bitwise f32) temp_s2->rest01[8] * (bitwise f32) arg2->unk0);
            temp_s2->rest01[9] = (bitwise u32) temp_fv0_2;
            if (temp_fv0_2 <= 0.0f) {
                var_fv0_2 = 0;
                if (D_8010BFDB != 0) {
                    var_fv0_2 = D_800A655C;
                }
                temp_s2->rest01[9] = var_fv0_2;
            }
        }
        break;
    case 4:                                         /* switch 1 */
        sp34 = 0;
        if (gCurrentLevel != ATST_LEVEL) {
            func_800C5F90(temp_s2->rest01[2], temp_a1);
            if ((D_80138D1C->unk4 == 3) && (D_80130B4C & 0x10) && (func_800C6498(temp_s2->rest01[2]) & 0xFF)) {
                temp_v1_15 = temp_s2->rest01[1];
                temp_v0_16 = *arg2->unkC;
                temp_v1_15->unk0 = temp_v0_16;
                if (temp_v0_16 != NULL) {
                    temp_v0_16->unk4 = temp_v1_15;
                }
                temp_v1_15->unk4 = 0;
                sp34 = 1;
                *arg2->unkC = (void *) temp_v1_15;
            }
            if (!(D_8010CA1C & 0x180) || !(D_8010BFDC <= 0.0f) || (D_80138D1C->unk4 == 3)) {
                var_s3_6 = 8;
                if (sp34 == 0) {
                    temp_v1_16 = temp_s2->rest01[1];
                    temp_v0_17 = *arg2->unk10;
                    temp_v1_16->unk0 = temp_v0_17;
                    if (temp_v0_17 != NULL) {
                        temp_v0_17->unk4 = temp_v1_16;
                    }
                    temp_v1_16->unk4 = 0;
                    *arg2->unk10 = (void *) temp_v1_16;
                    var_s3_6 = 8;
                }
                temp_fp = &temp_s2->unkD84[3];
                temp_s7_2 = &temp_s2->unkD84[1];
                temp_s6_3 = &temp_s2->unkD84[2];
                var_s1 = 0x20;
                var_s0_6 = &temp_s2->hud_elements[6].width_scale;
                var_s5 = &temp_s2->hud_texture_ids[0x10];
                do {
                    if (var_s3_6 < 9U) {
                        switch (*(var_s1 + &jtbl_800A6560)) { /* switch 2; unable to parse jump table */
                        case 1:                     /* switch 2 */
                            var_a0_7 = -1U;
                            if ((sp34 == 0) && ((u16) temp_s2->unk228 <= 0xFFFEU)) {
                                var_a0_7 = var_s3_6;
                            }
                            break;
                        case 4:                     /* switch 2 */
                        case 5:                     /* switch 2 */
                        case 6:                     /* switch 2 */
                            if ((func_8006C940(0) != 0) || (var_a0_7 = -1U, (D_80130B10.secondaryWeaponType != 1))) {
                                if (func_8006C940(0) != 4) {
                                    var_a0_7 = -1U;
                                    if (D_80130B10.secondaryWeaponType != 0xFF) {
                                        var_a0_7 = var_s3_6;
                                        if (sp34 != 0) {
                                            var_a0_7 = -1U;
                                        }
                                    }
                                } else {
                                case 0:             /* switch 2 */
                                    var_a0_7 = -1U;
                                }
                            }
                            break;
                        case 2:                     /* switch 2 */
                        case 3:                     /* switch 2 */
                        case 7:                     /* switch 2 */
                        case 8:                     /* switch 2 */
                            var_a0_7 = -1U;
                            if (sp34 == 0) {
                                var_a0_7 = var_s3_6;
                            }
                            break;
                        }
                    } else {
                        var_a0_7 = var_s3_6;
                    }
                    if ((s32) var_a0_7 >= 0) {
                        var_s0_6->unk68 = (u8) var_s5->unk204;
                        var_s0_6->unk69 = (u8) var_s5->unk205;
                        var_s0_6->unk6A = (u8) var_s5->unk206;
                        temp_fv0_3 = (f32) var_s5->unk207 * D_8010BFDC;
                        if (!(D_800A6584 <= temp_fv0_3)) {
                            var_v1_8 = (s32) temp_fv0_3;
                            var_v0_13 = var_a0_7 * 2;
                        } else {
                            var_v1_8 = (s32) (temp_fv0_3 - D_800A6584) | 0x80000000;
                            var_v0_13 = var_a0_7 * 2;
                        }
                        var_s0_6->unk6B = (s8) var_v1_8;
                        temp_a0_2 = (var_v0_13 + var_a0_7) * 0x10;
                        temp_v1_17 = arg2->unk0->unk8;
                        temp_a1_2 = temp_s2 + temp_a0_2;
                        temp_a1_2->unk3C = temp_v1_17;
                        if (temp_v1_17 != NULL) {
                            temp_v1_17->prev = temp_s2 + (temp_a0_2 + 0x3C);
                        }
                        temp_a1_2->unk40 = 0;
                        arg2->unk0->unk8 = (struct hud_sub_struct *) (temp_s2 + (temp_a0_2 + 0x3C));
                    }
                    if ((temp_s2->unkF7C != 0) && (D_80138D1C->unk4 == 3)) {
                        switch (var_s3_6) {         /* switch 3 */
                        case 5:                     /* switch 3 */
                            if ((func_8006C940(0) != 4) && (D_80130B10.secondaryWeaponType != 0xFF)) {
                                temp_v0_18 = var_s0_6->unk48->unk0;
                                var_a0_8 = temp_s2->unkD84;
                                if (temp_v0_18 != 0xFFFF) {
                                    var_a0_8->unk28 = temp_v0_18 << 0x10;
                                    var_a0_8->unk20 &= ~0x100;
                                    temp_s2->unkDC8 = (unaligned s32) *(var_s1 + temp_s2 + 0x204);
                                    var_s1 -= 4;
                                } else {
block_196:
                                    var_a0_8->unk20 |= 0x100;
                                    goto block_197;
                                }
                            } else {
                                var_v1_9 = temp_s2->unkD84;
block_191:
                                var_v1_9->unk20 |= 0x100;
                                goto block_197;
                            }
                            break;
                        case 4:                     /* switch 3 */
                            if ((func_8006C940(0) != 4) && (D_80130B10.secondaryWeaponType != 0xFF)) {
                                temp_a1_3 = var_s1 + temp_s2;
                                if ((u16) var_s0_6->unk44 >= 2U) {
                                    temp_v0_19 = var_s0_6->unk48->unk0;
                                    temp_a0_3 = &temp_s2->unkD84[1];
                                    if (temp_v0_19 != 0xFFFF) {
                                        temp_a0_3->unk28 = temp_v0_19 << 0x10;
                                        temp_a0_3->unk20 &= ~0x100;
                                        temp_s2->unkE10 = (unaligned s32) *(temp_a1_3 + 0x204);
                                        var_a1 = var_s1 + temp_s2;
                                    } else {
                                        temp_a0_3->unk20 |= 0x100;
                                        var_a1 = var_s1 + temp_s2;
                                    }
                                    temp_v0_20 = var_s0_6->unk48->unk2;
                                    temp_a0_4 = &temp_s2->unkD84[2];
                                    if (temp_v0_20 != 0xFFFF) {
                                        temp_a0_4->unk28 = temp_v0_20 << 0x10;
                                        temp_a0_4->unk20 &= ~0x100;
                                        temp_s2->unkE58 = (unaligned s32) *(var_a1 + 0x204);
                                    } else {
                                        temp_a0_4->unk20 |= 0x100;
                                    }
                                    goto block_185;
                                }
                                temp_s7_2->unk20 |= 0x100;
                                temp_s6_3->unk20 |= 0x100;
                                temp_v0_21 = var_s0_6->unk48->unk0;
                                var_a0_8 = &temp_s2->unkD84[3];
                                if (temp_v0_21 != 0xFFFF) {
                                    var_a0_8->unk28 = temp_v0_21 << 0x10;
                                    var_a0_8->unk20 &= ~0x100;
                                    temp_s2->unkEA0 = (unaligned s32) *(temp_a1_3 + 0x204);
                                    var_s1 -= 4;
                                } else {
                                    goto block_196;
                                }
                            } else {
                                temp_s7_2->unk20 |= 0x100;
                                temp_s6_3->unk20 |= 0x100;
block_185:
                                temp_fp->unk20 |= 0x100;
                                goto block_197;
                            }
                            break;
                        case 6:                     /* switch 3 */
                            if ((func_8006C940(0) != 4) && (D_80130B10.secondaryWeaponType != 0xFF)) {
                                temp_v0_22 = var_s0_6->unk48->unk0;
                                var_a0_8 = &temp_s2->unkD84[6];
                                if (temp_v0_22 != 0xFFFF) {
                                    var_a0_8->unk28 = temp_v0_22 << 0x10;
                                    var_a0_8->unk20 &= ~0x100;
                                    temp_s2->unkF78 = (unaligned s32) *(var_s1 + temp_s2 + 0x204);
                                    var_s1 -= 4;
                                } else {
                                    goto block_196;
                                }
                            } else {
                                var_v1_9 = &temp_s2->unkD84[6];
                                goto block_191;
                            }
                            break;
                        case 1:                     /* switch 3 */
                            temp_v0_23 = var_s0_6->unk48->unk0;
                            var_a0_8 = &temp_s2->unkD84[4];
                            if (temp_v0_23 != 0xFFFF) {
                                var_a0_8->unk28 = temp_v0_23 << 0x10;
                                var_a0_8->unk20 &= ~0x100;
                                temp_s2->unkEE8 = (unaligned s32) *(var_s1 + temp_s2 + 0x204);
                                var_s1 -= 4;
                            } else {
                                goto block_196;
                            }
                            break;
                        case 2:                     /* switch 3 */
                            temp_v0_24 = var_s0_6->unk48->unk0;
                            var_a0_8 = &temp_s2->unkD84[5];
                            if (temp_v0_24 != 0xFFFF) {
                                var_a0_8->unk28 = temp_v0_24 << 0x10;
                                var_a0_8->unk20 &= ~0x100;
                                temp_s2->unkF30 = (unaligned s32) *(var_s1 + temp_s2 + 0x204);
                                var_s1 -= 4;
                            } else {
                                goto block_196;
                            }
                            break;
                        }
                    } else {
                    default:                        /* switch 3 */
block_197:
                        var_s1 -= 4;
                    }
                    var_s0_6 -= 0x30;
                    var_s3_6 -= 1;
                    var_s5 -= 4;
                } while ((s32) var_s3_6 >= 0);
            }
        }
        if (temp_s2->unk258 != 0) {
            func_800C298C(arg2, temp_s2);
        }
        if ((bitwise f32) temp_s2->rest01[9] > 0.0f) {
            temp_s2->hud_elements[0].rgba.red = (unaligned s32) D_8010BFD8.unk0;
            temp_s2->hud_elements[0].rgba.alpha = 0xFF;
            temp_s2->hud_elements[0].xpos = (f32) ((s32) -arg2->unk0->unk10 / 2);
            temp_s2->hud_elements[0].ypos = (f32) ((s32) -arg2->unk0->unk14 / 2);
            temp_v0_25 = arg2->unk0->unk10;
            if (D_8010BFD8.unk3 == 0) {
                var_fv0_3 = temp_s2->rest01[9];
            } else {
                var_fv0_3 = (bitwise u32) (D_800A65A0 - (bitwise f32) temp_s2->rest01[9]);
            }
            temp_fv1_7 = (f32) (temp_v0_25 / 2) - ((f32) temp_v0_25 * (bitwise f32) var_fv0_3);
            temp_s2->hud_elements[0].xpos = temp_fv1_7;
            var_v0_14 = &temp_s2->hud_texture_ids[0x1C];
            if (!(temp_fv1_7 <= (f32) (((s32) -arg2->unk0->unk10 / 2) + 1))) {
                var_v0_14 = &temp_s2->hud_texture_ids[0x1D];
            }
            temp_s2->hud_elements[0].texture_id_pointer = var_v0_14;
            temp_s2->hud_elements[0].width_scale = (f32) arg2->unk0->unk10 / D_800A65A4;
            temp_s2->hud_elements[0].height_scale = (f32) arg2->unk0->unk14 / D_800A65A8;
            temp_v1_18 = arg2->unk0->unk8;
            temp_s2->hud_elements[0].next = temp_v1_18;
            if (temp_v1_18 != NULL) {
                temp_v1_18->prev = temp_s2->hud_elements;
            }
            temp_s2->hud_elements[0].prev = NULL;
            arg2->unk0->unk8 = temp_s2->hud_elements;
        }
        break;
    }
    return 1;
}
