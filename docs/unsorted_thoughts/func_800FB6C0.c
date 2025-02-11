struct _m2c_stack_func_800FB6C0 {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s32 sp10;                            /* inferred */
    /* 0x14 */ s32 sp14;                            /* inferred */
    /* 0x18 */ s32 sp18;                            /* inferred */
    /* 0x1C */ s32 sp1C;                            /* inferred */
    /* 0x20 */ s8 sp20;                             /* inferred */
    /* 0x21 */ char pad21[0x3F];                    /* maybe part of sp20[0x40]? */
    /* 0x60 */ f32 sp60;                            /* inferred */
    /* 0x64 */ char pad64[0x44];
};                                                  /* size = 0xA8 */

u16 func_8003FFEC(? (*)(), f32 *, ?, ?);            /* extern */
? load_hmt_and_hob(s32 *, s32, ?, ?);                  /* extern */
s32 func_80056DA4(? *);                             /* extern */
? sprintf(s32 *, ? *, ? *, s32);                    /* extern */
? D_800C68A0();                                     /* static */
? D_800D2208();                                     /* static */
extern ? D_800A9030;
extern ? D_800A9044;
extern ? D_800A9054;
extern ? D_800A905C;
extern ? D_800A9068;
extern ? D_800A9074;
extern f32 D_800A9088;
extern ? *D_8010A0FC;
extern ? D_8010B3A0;
extern ? D_8010B3C4;
extern ? D_80130B40;
extern s32 D_80130B70;
extern ? D_80136DC0;
extern ? D_80137CE8;

void func_800FB6C0(enum PlayerCraft *arg0) {
    f32 sp60;
    s8 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    ? *var_a2;
    ? var_a2_2;
    enum PlayerCraft *var_s2;
    enum PlayerCraft temp_v0;
    enum PlayerCraft temp_v0_2;
    s32 var_a1;
    s32 var_s1;
    struct player_struct *var_s0;

    D_80137CE8.unk4 = 0;
    D_80137CE8.unk0 = (f32) (D_80136DC0.unk20 + ((D_80136DC0.unk24 - D_80136DC0.unk20) * D_800A9088));
    D_80137CE8.unk8 = (f32) (D_80136DC0.unk2C + ((D_80136DC0.unk30 - D_80136DC0.unk2C) * D_800A9088));
    var_s1 = 0;
    // Probably checking if we're in the chicken level?
    if (D_80130B70 == 0x00000014) {
        D_80137DB8->inner.vehicleId = XWING;
        // imp_stuff/atst_hi
        sprintf(&sp10, &D_800A9030);
        load_hmt_and_hob(&sp10, 0, 0, 0);
        sp60 = 0.0f;
        func_8003FFEC(D_800D2208, &sp60, 2, 0x64);
        // pl_crafts/%, c_xwng
        sprintf(&sp10, &D_800A9044, D_8010A0FC);
        load_hmt_and_hob(&sp10, 0, 0, 0);
        D_80137DB8->inner.unk28A = func_8003FFEC(D_800C68A0, &sp60, 4, 0x64);
        return;
    }
    var_s2 = arg0;
    var_s0 = D_80137DB8;
    do {
        if (var_s0->unk000 != 0) {
            temp_v0 = *var_s2;
            var_s0->inner.vehicleId = temp_v0;
            // craft name, look at enum PlayerCraft
            if (!(func_80056DA4(*((temp_v0 * 4) + &D_8010B3A0)) & 0xFF)) {
                if (var_s0->inner.vehicleId != TIEINTER) {
                    // pl_craft
                    var_a2 = &D_800A905C;
                } else {
                    // imp_stuff
                    var_a2 = &D_800A9068;
                }
                // %s/%s, (pl_craft|imp_stuff), craft name
                sprintf(&sp10, &D_800A9054, var_a2, *((var_s0->inner.vehicleId * 4) + &D_8010B3A0));
                // if the Buick Electra cheat is active
                if ((var_s0->inner.vehicleId == VWING) && (D_80130B40.unk18 & 2)) {
                    // pl_craft/rmobil
                    sp10 = D_800A9074.unk0;
                    sp14 = D_800A9074.unk4;
                    sp18 = D_800A9074.unk8;
                    sp1C = D_800A9074.unkC;
                    sp20 = D_800A9074.unk10;
                }
                temp_v0_2 = var_s0->inner.vehicleId;
                var_a1 = 0;
                if (temp_v0_2 == KOELSCH) {
                    var_a1 = D_80130B40.unk28;
                }
                var_a2_2 = 1;
                if (temp_v0_2 == KOELSCH) {
                    var_a2_2 = -0x7FFF;
                }
                load_hmt_and_hob(&sp10, var_a1, var_a2_2, 0x10000);
            }
            sp60 = (f32) var_s1;
            func_8003FFEC(*((var_s0->inner.vehicleId * 4) + &D_8010B3C4), &sp60, 4, 0x64);
            if (!(func_80056DA4((&D_8010A0FC)[var_s0->inner.vehicleId]) & 0xFF)) {
                // pl_crafts/%s, c_<craft_shortname>
                // i.e. c_xwng, c_spdr, c_tie
                sprintf(&sp10, &D_800A9044, (&D_8010A0FC)[var_s0->inner.vehicleId]);
                load_hmt_and_hob(&sp10, 0, 1, 0x10000);
            }
            var_s0->inner.unk28A = func_8003FFEC(D_800C68A0, &sp60, 4, 0x64);
        }
        var_s2 += 4;
        var_s1 += 1;
        var_s0 += 0x2A0;
    } while (var_s1 <= 0);
}
