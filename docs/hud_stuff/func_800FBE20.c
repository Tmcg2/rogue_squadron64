struct _m2c_stack_func_800FBE20 {
    /* 0x00 */ char pad0[0x28];
};                                                  /* size = 0x28 */

u16 func_800554D8(s32, ?, ?);                       /* extern */
s32 func_8006C940(?, s32, ?, ?);                    /* extern */
s32 func_800B585C(?);                               /* extern */
extern f32 D_800A9158;
extern s32 D_8010B424;
extern u32 D_8010CA1C;
extern u32 D_80130B4C;

u8 func_800FBE20(s32 arg0, u8 arg1, u8 arg2, u8 arg3) {
    s32 *var_s2;
    s32 temp_a0;
    s32 var_a0_3;
    s32 var_a1;
    struct hud_struct *temp_s0;
    struct hud_struct *var_s3;
    struct hud_struct *var_v1_4;
    struct hud_sub_struct *temp_a1;
    struct hud_sub_struct *temp_a1_2;
    struct hud_sub_struct *var_a0;
    struct hud_sub_struct *var_a0_2;
    struct hud_sub_struct *var_v0;
    struct hud_sub_struct *var_v1;
    struct hud_sub_struct *var_v1_2;
    struct hud_sub_struct *var_v1_3;
    u32 var_s1;
    u32 var_s1_2;
    u32 var_s1_3;
    u8 temp_v0_2;
    void *temp_v0;
    void *temp_v1;

    var_s1 = 0;
    temp_s0 = &D_8010CA30[arg0 & 0xFF];
    var_s3 = temp_s0;
    temp_s0->secondaryWeapon = arg1;
    temp_s0->secondaryWeaponCount = arg2;
    temp_s0->secondaryWeaponReset = arg2;
    temp_s0->secondaryWeaponIsAdvanced = arg3;
    temp_s0->crosshairOnOff = ((u32) D_80130B4C >> 7) & 1;
    var_s2 = &D_8010B424;
    temp_s0->unknown006 = ((u32) D_8010CA1C >> 0xA) & 1;
    do {
        temp_a0 = *var_s2;
        var_s2 += 4;
        var_s1 += 1;
        var_s3->texture_ids[0] = func_800554D8(temp_a0, 0, 0x2000);
        var_s3 += 2;
    } while (var_s1 < 0xAU);
    var_a0 = &temp_s0->hud_elements[1];
    var_v1 = temp_s0->hud_elements;
    temp_a1 = var_a0;
    temp_s0->hud_elements[0].texture_count = 1;
    temp_s0->hud_elements[0].unknown0A = 1;
    temp_s0->hud_elements[0].flags = 3;
    temp_s0->hud_elements[0].zero = 0.0f;
    temp_s0->hud_elements[0].texture_id_pointer = temp_s0->texture_ids;
    do {
        var_a0->next = var_v1->next;
        var_a0->prev = var_v1->prev;
        var_a0->unk8 = (s32) var_v1->unk8;
        var_a0->texture_id_pointer = var_v1->texture_id_pointer;
        var_v1 += 0x10;
        var_a0 += 0x10;
    } while (var_v1 != temp_a1);
    temp_s0->hud_elements[1].texture_id_pointer = &temp_s0->texture_ids[1];
    var_v1_2 = &temp_s0->hud_elements[8];
    var_v0 = temp_s0->hud_elements;
    do {
        var_v1_2->next = var_v0->next;
        var_v1_2->prev = var_v0->prev;
        var_v1_2->unk8 = (s32) var_v0->unk8;
        var_v1_2->texture_id_pointer = var_v0->texture_id_pointer;
        var_v0 += 0x10;
        var_v1_2 += 0x10;
    } while (var_v0 != &temp_s0->hud_elements[1]);
    var_a0_2 = &temp_s0->hud_elements[9];
    var_v1_3 = &temp_s0->hud_elements[8];
    temp_a1_2 = var_a0_2;
    temp_s0->hud_elements[8].texture_id_pointer = &temp_s0->texture_ids[8];
    temp_s0->hud_elements[8].rgba.red = 0xFF;
    temp_s0->hud_elements[8].rgba.green = 0xD2;
    temp_s0->hud_elements[8].rgba.blue = 0;
    do {
        var_a0_2->next = var_v1_3->next;
        var_a0_2->prev = var_v1_3->prev;
        var_a0_2->unk8 = (s32) var_v1_3->unk8;
        var_a0_2->texture_id_pointer = var_v1_3->texture_id_pointer;
        var_v1_3 += 0x10;
        var_a0_2 += 0x10;
    } while (var_v1_3 != temp_a1_2);
    var_s1_2 = 0;
    var_a1 = 0x10;
    var_a0_3 = 0x90;
    temp_s0->hud_elements[9].texture_id_pointer = &temp_s0->texture_ids[9];
    temp_s0->hud_elements[2].texture_count = 1;
    temp_s0->hud_elements[2].unknown0A = 1;
    temp_s0->hud_elements[2].flags = 3;
    temp_s0->hud_elements[2].rgba.red = 0xFF;
    temp_s0->hud_elements[2].rgba.green = 0xD2;
    temp_s0->hud_elements[2].zero = 0.0f;
    temp_s0->hud_elements[2].rgba.blue = 0;
    temp_s0->hud_elements[2].texture_id_pointer = &temp_s0->texture_ids[2];
    do {
        temp_v1 = temp_s0 + var_a1;
        var_a1 += 2;
        temp_v0 = temp_s0 + var_a0_3;
        var_s1_2 += 1;
        temp_v0->unk30 = 1;
        temp_v0->unk32 = 1;
        temp_v0->unk48 = 0;
        temp_v0->unk3C = 3;
        temp_v0->unk54 = 0xFF;
        temp_v0->unk55 = 0;
        temp_v0->unk56 = 0;
        temp_v0->unk57 = 0xBE;
        temp_v0->unk34 = temp_v1;
        var_a0_3 += 0x30;
    } while (var_s1_2 < 5U);
    temp_v0_2 = temp_s0->secondaryWeapon;
    switch (temp_v0_2) {
    case 3:
    case 8:
        temp_s0->unknown001 = 0;
        temp_s0->unk210 = 0;
        temp_s0->unk211 = 0;
        break;
    case 1:
    case 2:
    case 4:
    case 5:
        temp_s0->unknown001 = 0;
        break;
    }
    if ((func_8006C940(0, var_a1, 1, 0xBE) == 0) && !(func_800B585C(0) & 0xFF)) {
        temp_s0->alpha_scaling = 0.0f;
    } else {
        temp_s0->alpha_scaling = D_800A9158;
    }
    var_s1_3 = 0;
    var_v1_4 = D_8010CA30;
    do {
        var_v1_4->unk274 = 0;
        var_s1_3 += 1;
        var_v1_4 += 0x278;
    } while (var_s1_3 < 2U);
    return temp_s0->secondaryWeapon;
}
