struct _m2c_stack_func_80003638 {
    /* 0x00 */ char pad0[0x20];
    /* 0x20 */ u8 **sp20;                           /* inferred */
    /* 0x24 */ OSMesgQueue *sp24;                   /* inferred */
    /* 0x28 */ char pad28[0x28];
};                                                  /* size = 0x50 */

? osPiStartDma(OSIoMesg *, ?, ?, u8 *, u8 *, s32, OSMesgQueue *); /* extern */
? osYieldThread();                                  /* extern */
s32 func_800058C0(?);                               /* static */
? func_800072AC(s32);                               /* static */
extern s32 D_80110D54;

void func_80003638(s32 arg0) {
    OSMesgQueue *sp24;
    u8 **sp20;
    s32 *temp_s3;
    s32 *temp_s4;
    s32 *temp_s5;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_s0;
    u8 *temp_s1;
    u8 *temp_s2;

    sp20 = &D_801109B0[arg0];
    temp_s5 = &D_80110A10[arg0];
    temp_s4 = &D_80110A50[arg0];
    temp_s3 = &D_80110A30[arg0];
    sp24 = &D_801108C0[arg0];
loop_1:
    osRecvMesg(&D_801108C0[arg0], NULL, 1);
    osYieldThread();
    osInvalDCache(&(*sp20)[*temp_s5], *temp_s4);
    *temp_s3 -= *temp_s4;
    *temp_s5 += *temp_s4;
    temp_v1 = *temp_s3;
    D_80110A70 = 0;
    if (temp_v1 != 0) {
        var_s0 = D_80111254;
        if ((u32) var_s0 >= (u32) temp_v1) {
            var_s0 = temp_v1;
        }
        *temp_s4 = var_s0;
        temp_v1_2 = *temp_s5;
        temp_s2 = &D_801109F0[arg0][temp_v1_2];
        temp_s1 = &(*sp20)[temp_v1_2];
loop_5:
        if ((func_800058C0(0) & 0xFF) == 1) {
            func_800072AC(D_80110D54);
            goto loop_5;
        }
        osWritebackDCache(temp_s1, var_s0);
        osPiStartDma(&D_801107E0[arg0], 0, 0, temp_s2, temp_s1, var_s0, sp24);
        D_80110A70 = 1;
        if (*temp_s3 != 0) {
            goto loop_1;
        }
    }
    D_801109AC += 1;
    func_800058C0(1);
}
