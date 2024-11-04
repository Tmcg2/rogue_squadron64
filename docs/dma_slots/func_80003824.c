struct _m2c_stack_func_80003824 {
    /* 0x00 */ char pad0[0x48];
};                                                  /* size = 0x48 */

? osPiStartDma(OSIoMesg *, ?, ?, u8 *, u8 *, s32, OSMesgQueue *); /* extern */
? osYieldThread();                                  /* extern */
s32 func_800058C0(?);                               /* static */
? func_800072AC(s32);                               /* static */
extern s32 D_80110D54;

s32 func_80003824(s32 arg0) {
    s32 *temp_s1;
    s32 *temp_s3;
    s32 *temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 var_s0;
    s32 var_v0;
    u8 **temp_s7;
    u8 *temp_s1_2;
    u8 *temp_s2;

    var_v0 = 0;
    if (osRecvMesg(&D_801108C0[arg0], NULL, 1) != -1) {
        osYieldThread();
        temp_s7 = &D_801109B0[arg0];
        temp_s3 = &D_80110A10[arg0];
        temp_s1 = &D_80110A50[arg0];
        osInvalDCache(&(*temp_s7)[*temp_s3], *temp_s1);
        temp_v1 = &D_80110A30[arg0];
        *temp_v1 -= *temp_s1;
        *temp_s3 += *temp_s1;
        temp_v1_2 = *temp_v1;
        D_80110A70 = 0;
        if (temp_v1_2 == 0) {
            D_801109AC += 1;
            func_800058C0(1);
            var_v0 = 1;
            /* Duplicate return node #11. Try simplifying control flow for better match */
            return var_v0;
        }
        var_s0 = D_80111254;
        if ((u32) var_s0 >= (u32) temp_v1_2) {
            var_s0 = temp_v1_2;
        }
        *temp_s1 = var_s0;
        temp_v1_3 = *temp_s3;
        temp_s1_2 = &(*temp_s7)[temp_v1_3];
        temp_s2 = &D_801109F0[arg0][temp_v1_3];
loop_7:
        if ((func_800058C0(0) & 0xFF) == 1) {
            func_800072AC(D_80110D54);
            goto loop_7;
        }
        osWritebackDCache(temp_s1_2, var_s0);
        osPiStartDma(&D_801107E0[arg0], 0, 0, temp_s2, temp_s1_2, var_s0, &D_801108C0[arg0]);
        D_80110A70 = 1;
        return 0;
    }
    return var_v0;
}
