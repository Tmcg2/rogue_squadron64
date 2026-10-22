#include "common.h"

#include "main/031B0.h"
#include "main/08120.h"

s32 getResetVectorRegion(s32 **arg0, s32 *arg1) {
    *arg0 = osAppNMIBuffer;
    *arg1 = 0x80000400 - (u32)osAppNMIBuffer;
    return 1;
}

// This string is funny because it has to contain the leftover linker junk
// If 100% matching isn't a concern, make "%s\n%d\n%s\n" a string literal
// in the `sprintf` call in `fatalErrorHalt`
const char error_format[16] = {
    "%s\n%d\n%s\n\0\x32\x8C\x80\0\x32\xB4"
};

void fatalErrorHalt(char *arg0, char* arg1, s32 arg2) {
    s32 some_size;
    s32 *some_address;
    char sp18[0x200];
    u32 temp_s0;
    u32 temp_v1;
    u32 var_a2;

    temp_s0 = sprintf(sp18, error_format, arg0, arg2, arg1) + 1;
    getResetVectorRegion(&some_address, &some_size);
    if (some_size < temp_s0) {
        var_a2 = some_size;
    } else {
        var_a2 = temp_s0;
    }
    rs_memset(some_address, 0U, var_a2);
    rs_strncpy(some_address, sp18, temp_s0);
    while(1);
}

INCLUDE_ASM("asm/nonmatchings/main/031B0", getUsableRdramSize);

INCLUDE_ASM("asm/nonmatchings/main/031B0", fake_func_8000268C);
