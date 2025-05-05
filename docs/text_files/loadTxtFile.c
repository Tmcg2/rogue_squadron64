/*
Skipping .incbin directive for assets/main/gspF3DEXMainData.databin.bin, pass --incbin-dir to set a search directory
*/
/*
Skipping .incbin directive for assets/main/aspMainData.databin.bin, pass --incbin-dir to set a search directory
*/
struct _m2c_stack_loadTxtFile {
    /* 0x00 */ char pad0[0x38];
};                                                  /* size = 0x38 */

void *func_80004AAC(s32, ?, s32, s32, s32);         /* static */
? func_80004C70(s32, void *);                       /* static */
extern s32 D_80137CFC;
extern s32 D_80138920;
extern u16 D_80138E7C;
extern u32 D_80138E80;
static void *language_data = NULL;                  /* const */
static void *D_8009ECA4 = (void *)0xFFFFFFFF;       /* const */
static void *language_string_offsets = NULL;        /* const */

s32 loadTxtFile(s32 arg0, s32 arg1) {
    s32 temp_s1;
    s32 temp_s1_2;
    s32 temp_v0_3;
    s32 var_a0;
    s32 var_s1;
    u8 *var_v1;
    u8 temp_v0_4;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_5;

    temp_v0 = func_80004AAC(D_80138920, 0, D_80137CFC, arg0, 1);
    func_80004E70(D_80138920, NULL, temp_v0, 0, 0x0000001C, &D_80138E60);
    D_80138E7C = D_80138E60.string_count;
    if ((u8) D_80130B40.languageSelect >= (u16) D_80138E60.language_count) {
        D_80130B40.languageSelect = 0;
    }
    if (!(arg1 & 0xFF)) {
        temp_s1 = D_80138E60.language_offsets[D_80130B40.languageSelect + 1] - D_80138E60.language_offsets[D_80130B40.languageSelect];
        temp_v0_2 = rs_malloc(temp_s1, 0U);
        language_data = temp_v0_2;
        func_80004E70(D_80138920, NULL, temp_v0, (s32) D_80138E60.language_offsets[D_80130B40.languageSelect], temp_s1, temp_v0_2);
        func_80004C70(D_80138920, temp_v0);
        var_a0 = 0xF5;
        temp_v0_3 = D_80138E7C * 2;
        var_s1 = temp_s1 - temp_v0_3;
        var_v1 = language_data + temp_v0_3;
        if (var_s1 != 0) {
            do {
                var_s1 -= 1;
                temp_v0_4 = *var_v1 ^ var_a0;
                var_a0 ^= temp_v0_4;
                *var_v1 = temp_v0_4;
                var_v1 += 1;
            } while (var_s1 != 0);
        }
    } else {
        D_8009ECA4 = temp_v0;
        temp_s1_2 = D_80138E60.string_count * 2;
        temp_v0_5 = rs_malloc(temp_s1_2, 0U);
        language_string_offsets = temp_v0_5;
        func_80004E70(D_80138920, NULL, temp_v0, (s32) D_80138E60.language_offsets[D_80130B40.languageSelect], temp_s1_2, temp_v0_5);
        D_80138E80 = D_80138E60.language_offsets[D_80130B40.languageSelect];
    }
    return 1;
}
