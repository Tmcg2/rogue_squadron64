#include "common.h"

#include "main/02420.h"
#include "main/84830.h"
#include "main/8F970.h"

u8  gMusyXActiveFlag  = 0;
u32 D_main_800A0F54   = 1;
u16 D_main_800A0F58[] = {
    0x0000, 0x0006, 0x000C, 0x0012, 0x0019, 0x001F, 0x0025, 0x002B, 0x0032, 0x0038, 0x003E, 0x0045, 0x004B, 0x0051, 0x0057, 0x005E,
    0x0064, 0x006A, 0x0071, 0x0077, 0x007D, 0x0083, 0x008A, 0x0090, 0x0096, 0x009D, 0x00A3, 0x00A9, 0x00AF, 0x00B6, 0x00BC, 0x00C2,
    0x00C8, 0x00CF, 0x00D5, 0x00DB, 0x00E2, 0x00E8, 0x00EE, 0x00F4, 0x00FB, 0x0101, 0x0107, 0x010D, 0x0114, 0x011A, 0x0120, 0x0127,
    0x012D, 0x0133, 0x0139, 0x0140, 0x0146, 0x014C, 0x0152, 0x0159, 0x015F, 0x0165, 0x016B, 0x0172, 0x0178, 0x017E, 0x0184, 0x018B,
    0x0191, 0x0197, 0x019D, 0x01A4, 0x01AA, 0x01B0, 0x01B6, 0x01BD, 0x01C3, 0x01C9, 0x01CF, 0x01D6, 0x01DC, 0x01E2, 0x01E8, 0x01EF,
    0x01F5, 0x01FB, 0x0201, 0x0208, 0x020E, 0x0214, 0x021A, 0x0221, 0x0227, 0x022D, 0x0233, 0x0239, 0x0240, 0x0246, 0x024C, 0x0252,
    0x0259, 0x025F, 0x0265, 0x026B, 0x0271, 0x0278, 0x027E, 0x0284, 0x028A, 0x0290, 0x0297, 0x029D, 0x02A3, 0x02A9, 0x02AF, 0x02B6,
    0x02BC, 0x02C2, 0x02C8, 0x02CE, 0x02D5, 0x02DB, 0x02E1, 0x02E7, 0x02ED, 0x02F3, 0x02FA, 0x0300, 0x0306, 0x030C, 0x0312, 0x0318,
    0x031F, 0x0325, 0x032B, 0x0331, 0x0337, 0x033D, 0x0344, 0x034A, 0x0350, 0x0356, 0x035C, 0x0362, 0x0368, 0x036F, 0x0375, 0x037B,
    0x0381, 0x0387, 0x038D, 0x0393, 0x0399, 0x03A0, 0x03A6, 0x03AC, 0x03B2, 0x03B8, 0x03BE, 0x03C4, 0x03CA, 0x03D0, 0x03D7, 0x03DD,
    0x03E3, 0x03E9, 0x03EF, 0x03F5, 0x03FB, 0x0401, 0x0407, 0x040D, 0x0413, 0x041A, 0x0420, 0x0426, 0x042C, 0x0432, 0x0438, 0x043E,
    0x0444, 0x044A, 0x0450, 0x0456, 0x045C, 0x0462, 0x0468, 0x046E, 0x0474, 0x047A, 0x0480, 0x0486, 0x048C, 0x0492, 0x0498, 0x049E,
    0x04A5, 0x04AB, 0x04B1, 0x04B7, 0x04BD, 0x04C3, 0x04C9, 0x04CF, 0x04D5, 0x04DB, 0x04E0, 0x04E6, 0x04EC, 0x04F2, 0x04F8, 0x04FE,
    0x0504, 0x050A, 0x0510, 0x0516, 0x051C, 0x0522, 0x0528, 0x052E, 0x0534, 0x053A, 0x0540, 0x0546, 0x054C, 0x0552, 0x0558, 0x055D,
    0x0563, 0x0569, 0x056F, 0x0575, 0x057B, 0x0581, 0x0587, 0x058D, 0x0593, 0x0599, 0x059E, 0x05A4, 0x05AA, 0x05B0, 0x05B6, 0x05BC,
    0x05C2, 0x05C7, 0x05CD, 0x05D3, 0x05D9, 0x05DF, 0x05E5, 0x05EB, 0x05F0, 0x05F6, 0x05FC, 0x0602, 0x0608, 0x060E, 0x0613, 0x0619,
    0x061F, 0x0625, 0x062B, 0x0630, 0x0636, 0x063C, 0x0642, 0x0648, 0x064D, 0x0653, 0x0659, 0x065F, 0x0664, 0x066A, 0x0670, 0x0676,
    0x067B, 0x0681, 0x0687, 0x068D, 0x0692, 0x0698, 0x069E, 0x06A3, 0x06A9, 0x06AF, 0x06B5, 0x06BA, 0x06C0, 0x06C6, 0x06CB, 0x06D1,
    0x06D7, 0x06DC, 0x06E2, 0x06E8, 0x06ED, 0x06F3, 0x06F9, 0x06FE, 0x0704, 0x070A, 0x070F, 0x0715, 0x071B, 0x0720, 0x0726, 0x072B,
    0x0731, 0x0737, 0x073C, 0x0742, 0x0748, 0x074D, 0x0753, 0x0758, 0x075E, 0x0763, 0x0769, 0x076F, 0x0774, 0x077A, 0x077F, 0x0785,
    0x078A, 0x0790, 0x0795, 0x079B, 0x07A0, 0x07A6, 0x07AC, 0x07B1, 0x07B7, 0x07BC, 0x07C2, 0x07C7, 0x07CD, 0x07D2, 0x07D7, 0x07DD,
    0x07E2, 0x07E8, 0x07ED, 0x07F3, 0x07F8, 0x07FE, 0x0803, 0x0809, 0x080E, 0x0813, 0x0819, 0x081E, 0x0824, 0x0829, 0x082E, 0x0834,
    0x0839, 0x083F, 0x0844, 0x0849, 0x084F, 0x0854, 0x085A, 0x085F, 0x0864, 0x086A, 0x086F, 0x0874, 0x087A, 0x087F, 0x0884, 0x088A,
    0x088F, 0x0894, 0x0899, 0x089F, 0x08A4, 0x08A9, 0x08AF, 0x08B4, 0x08B9, 0x08BE, 0x08C4, 0x08C9, 0x08CE, 0x08D3, 0x08D9, 0x08DE,
    0x08E3, 0x08E8, 0x08EE, 0x08F3, 0x08F8, 0x08FD, 0x0902, 0x0908, 0x090D, 0x0912, 0x0917, 0x091C, 0x0921, 0x0927, 0x092C, 0x0931,
    0x0936, 0x093B, 0x0940, 0x0945, 0x094B, 0x0950, 0x0955, 0x095A, 0x095F, 0x0964, 0x0969, 0x096E, 0x0973, 0x0978, 0x097D, 0x0982,
    0x0987, 0x098D, 0x0992, 0x0997, 0x099C, 0x09A1, 0x09A6, 0x09AB, 0x09B0, 0x09B5, 0x09BA, 0x09BF, 0x09C4, 0x09C9, 0x09CE, 0x09D3,
    0x09D7, 0x09DC, 0x09E1, 0x09E6, 0x09EB, 0x09F0, 0x09F5, 0x09FA, 0x09FF, 0x0A04, 0x0A09, 0x0A0E, 0x0A12, 0x0A17, 0x0A1C, 0x0A21,
    0x0A26, 0x0A2B, 0x0A30, 0x0A35, 0x0A39, 0x0A3E, 0x0A43, 0x0A48, 0x0A4D, 0x0A51, 0x0A56, 0x0A5B, 0x0A60, 0x0A65, 0x0A69, 0x0A6E,
    0x0A73, 0x0A78, 0x0A7C, 0x0A81, 0x0A86, 0x0A8B, 0x0A8F, 0x0A94, 0x0A99, 0x0A9D, 0x0AA2, 0x0AA7, 0x0AAC, 0x0AB0, 0x0AB5, 0x0ABA,
    0x0ABE, 0x0AC3, 0x0AC8, 0x0ACC, 0x0AD1, 0x0AD5, 0x0ADA, 0x0ADF, 0x0AE3, 0x0AE8, 0x0AEC, 0x0AF1, 0x0AF6, 0x0AFA, 0x0AFF, 0x0B03,
    0x0B08, 0x0B0C, 0x0B11, 0x0B15, 0x0B1A, 0x0B1F, 0x0B23, 0x0B28, 0x0B2C, 0x0B31, 0x0B35, 0x0B3A, 0x0B3E, 0x0B42, 0x0B47, 0x0B4B,
    0x0B50, 0x0B54, 0x0B59, 0x0B5D, 0x0B62, 0x0B66, 0x0B6A, 0x0B6F, 0x0B73, 0x0B78, 0x0B7C, 0x0B80, 0x0B85, 0x0B89, 0x0B8D, 0x0B92,
    0x0B96, 0x0B9A, 0x0B9F, 0x0BA3, 0x0BA7, 0x0BAC, 0x0BB0, 0x0BB4, 0x0BB8, 0x0BBD, 0x0BC1, 0x0BC5, 0x0BCA, 0x0BCE, 0x0BD2, 0x0BD6,
    0x0BDA, 0x0BDF, 0x0BE3, 0x0BE7, 0x0BEB, 0x0BEF, 0x0BF4, 0x0BF8, 0x0BFC, 0x0C00, 0x0C04, 0x0C08, 0x0C0D, 0x0C11, 0x0C15, 0x0C19,
    0x0C1D, 0x0C21, 0x0C25, 0x0C29, 0x0C2D, 0x0C31, 0x0C36, 0x0C3A, 0x0C3E, 0x0C42, 0x0C46, 0x0C4A, 0x0C4E, 0x0C52, 0x0C56, 0x0C5A,
    0x0C5E, 0x0C62, 0x0C66, 0x0C6A, 0x0C6E, 0x0C72, 0x0C76, 0x0C79, 0x0C7D, 0x0C81, 0x0C85, 0x0C89, 0x0C8D, 0x0C91, 0x0C95, 0x0C99,
    0x0C9D, 0x0CA0, 0x0CA4, 0x0CA8, 0x0CAC, 0x0CB0, 0x0CB4, 0x0CB7, 0x0CBB, 0x0CBF, 0x0CC3, 0x0CC7, 0x0CCA, 0x0CCE, 0x0CD2, 0x0CD6,
    0x0CD9, 0x0CDD, 0x0CE1, 0x0CE5, 0x0CE8, 0x0CEC, 0x0CF0, 0x0CF3, 0x0CF7, 0x0CFB, 0x0CFE, 0x0D02, 0x0D06, 0x0D09, 0x0D0D, 0x0D11,
    0x0D14, 0x0D18, 0x0D1C, 0x0D1F, 0x0D23, 0x0D26, 0x0D2A, 0x0D2D, 0x0D31, 0x0D35, 0x0D38, 0x0D3C, 0x0D3F, 0x0D43, 0x0D46, 0x0D4A,
    0x0D4D, 0x0D51, 0x0D54, 0x0D58, 0x0D5B, 0x0D5F, 0x0D62, 0x0D65, 0x0D69, 0x0D6C, 0x0D70, 0x0D73, 0x0D77, 0x0D7A, 0x0D7D, 0x0D81,
    0x0D84, 0x0D87, 0x0D8B, 0x0D8E, 0x0D91, 0x0D95, 0x0D98, 0x0D9B, 0x0D9F, 0x0DA2, 0x0DA5, 0x0DA9, 0x0DAC, 0x0DAF, 0x0DB2, 0x0DB6,
    0x0DB9, 0x0DBC, 0x0DBF, 0x0DC2, 0x0DC6, 0x0DC9, 0x0DCC, 0x0DCF, 0x0DD2, 0x0DD5, 0x0DD9, 0x0DDC, 0x0DDF, 0x0DE2, 0x0DE5, 0x0DE8,
    0x0DEB, 0x0DEE, 0x0DF2, 0x0DF5, 0x0DF8, 0x0DFB, 0x0DFE, 0x0E01, 0x0E04, 0x0E07, 0x0E0A, 0x0E0D, 0x0E10, 0x0E13, 0x0E16, 0x0E19,
    0x0E1C, 0x0E1F, 0x0E22, 0x0E25, 0x0E28, 0x0E2B, 0x0E2D, 0x0E30, 0x0E33, 0x0E36, 0x0E39, 0x0E3C, 0x0E3F, 0x0E42, 0x0E44, 0x0E47,
    0x0E4A, 0x0E4D, 0x0E50, 0x0E53, 0x0E55, 0x0E58, 0x0E5B, 0x0E5E, 0x0E60, 0x0E63, 0x0E66, 0x0E69, 0x0E6B, 0x0E6E, 0x0E71, 0x0E74,
    0x0E76, 0x0E79, 0x0E7C, 0x0E7E, 0x0E81, 0x0E84, 0x0E86, 0x0E89, 0x0E8B, 0x0E8E, 0x0E91, 0x0E93, 0x0E96, 0x0E98, 0x0E9B, 0x0E9E,
    0x0EA0, 0x0EA3, 0x0EA5, 0x0EA8, 0x0EAA, 0x0EAD, 0x0EAF, 0x0EB2, 0x0EB4, 0x0EB7, 0x0EB9, 0x0EBC, 0x0EBE, 0x0EC0, 0x0EC3, 0x0EC5,
    0x0EC8, 0x0ECA, 0x0ECD, 0x0ECF, 0x0ED1, 0x0ED4, 0x0ED6, 0x0ED8, 0x0EDB, 0x0EDD, 0x0EDF, 0x0EE2, 0x0EE4, 0x0EE6, 0x0EE8, 0x0EEB,
    0x0EED, 0x0EEF, 0x0EF2, 0x0EF4, 0x0EF6, 0x0EF8, 0x0EFA, 0x0EFD, 0x0EFF, 0x0F01, 0x0F03, 0x0F05, 0x0F08, 0x0F0A, 0x0F0C, 0x0F0E,
    0x0F10, 0x0F12, 0x0F14, 0x0F16, 0x0F18, 0x0F1B, 0x0F1D, 0x0F1F, 0x0F21, 0x0F23, 0x0F25, 0x0F27, 0x0F29, 0x0F2B, 0x0F2D, 0x0F2F,
    0x0F31, 0x0F33, 0x0F35, 0x0F37, 0x0F39, 0x0F3B, 0x0F3C, 0x0F3E, 0x0F40, 0x0F42, 0x0F44, 0x0F46, 0x0F48, 0x0F4A, 0x0F4B, 0x0F4D,
    0x0F4F, 0x0F51, 0x0F53, 0x0F55, 0x0F56, 0x0F58, 0x0F5A, 0x0F5C, 0x0F5D, 0x0F5F, 0x0F61, 0x0F63, 0x0F64, 0x0F66, 0x0F68, 0x0F69,
    0x0F6B, 0x0F6D, 0x0F6E, 0x0F70, 0x0F72, 0x0F73, 0x0F75, 0x0F77, 0x0F78, 0x0F7A, 0x0F7B, 0x0F7D, 0x0F7F, 0x0F80, 0x0F82, 0x0F83,
    0x0F85, 0x0F86, 0x0F88, 0x0F89, 0x0F8B, 0x0F8C, 0x0F8E, 0x0F8F, 0x0F91, 0x0F92, 0x0F94, 0x0F95, 0x0F96, 0x0F98, 0x0F99, 0x0F9B,
    0x0F9C, 0x0F9D, 0x0F9F, 0x0FA0, 0x0FA1, 0x0FA3, 0x0FA4, 0x0FA5, 0x0FA7, 0x0FA8, 0x0FA9, 0x0FAB, 0x0FAC, 0x0FAD, 0x0FAE, 0x0FB0,
    0x0FB1, 0x0FB2, 0x0FB3, 0x0FB4, 0x0FB6, 0x0FB7, 0x0FB8, 0x0FB9, 0x0FBA, 0x0FBB, 0x0FBD, 0x0FBE, 0x0FBF, 0x0FC0, 0x0FC1, 0x0FC2,
    0x0FC3, 0x0FC4, 0x0FC5, 0x0FC6, 0x0FC7, 0x0FC8, 0x0FC9, 0x0FCA, 0x0FCB, 0x0FCC, 0x0FCD, 0x0FCE, 0x0FCF, 0x0FD0, 0x0FD1, 0x0FD2,
    0x0FD3, 0x0FD4, 0x0FD5, 0x0FD6, 0x0FD7, 0x0FD8, 0x0FD9, 0x0FD9, 0x0FDA, 0x0FDB, 0x0FDC, 0x0FDD, 0x0FDE, 0x0FDE, 0x0FDF, 0x0FE0,
    0x0FE1, 0x0FE1, 0x0FE2, 0x0FE3, 0x0FE4, 0x0FE4, 0x0FE5, 0x0FE6, 0x0FE7, 0x0FE7, 0x0FE8, 0x0FE9, 0x0FE9, 0x0FEA, 0x0FEB, 0x0FEB,
    0x0FEC, 0x0FEC, 0x0FED, 0x0FEE, 0x0FEE, 0x0FEF, 0x0FEF, 0x0FF0, 0x0FF0, 0x0FF1, 0x0FF1, 0x0FF2, 0x0FF2, 0x0FF3, 0x0FF3, 0x0FF4,
    0x0FF4, 0x0FF5, 0x0FF5, 0x0FF6, 0x0FF6, 0x0FF7, 0x0FF7, 0x0FF7, 0x0FF8, 0x0FF8, 0x0FF9, 0x0FF9, 0x0FF9, 0x0FFA, 0x0FFA, 0x0FFA,
    0x0FFB, 0x0FFB, 0x0FFB, 0x0FFB, 0x0FFC, 0x0FFC, 0x0FFC, 0x0FFC, 0x0FFD, 0x0FFD, 0x0FFD, 0x0FFD, 0x0FFE, 0x0FFE, 0x0FFE, 0x0FFE,
    0x0FFE, 0x0FFE, 0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF,
};
// DO NOT DELETE ME I AM REQURIED FOR MATCHING
u32 data_pad_84830[] ={
    0x46000306,
    0x46001386,
};

void audioSeqMallocZero(void *arg0) {
    rs_malloc(arg0, 0U);
}

INCLUDE_ASM("asm/nonmatchings/main/84830", audioSeqFree);

INCLUDE_ASM("asm/nonmatchings/main/84830", inlinedRand);

s16 lookupSineFromAngleTable(s32 arg0) {
    u32 temp_v1;

    temp_v1 = arg0 & 0xFFF;
    if (temp_v1 < 0x400U) {
        return D_main_800A0F58[temp_v1];
    }
    if (temp_v1 < 0x800U) {
        return D_main_800A0F58[~arg0 & 0x3FF];
    }
    if (temp_v1 < 0xC00U) {
        return D_main_800A0F58[arg0 & 0x3FF] * -1;
    } else {
        return D_main_800A0F58[~arg0 & 0x3FF] * -1;
    }
}

INCLUDE_ASM("asm/nonmatchings/main/84830", setTrackVoiceTickBudget);

INCLUDE_ASM("asm/nonmatchings/main/84830", getTrackVoiceTickBudget);

INCLUDE_ASM("asm/nonmatchings/main/84830", setChannelNoteCell);

INCLUDE_ASM("asm/nonmatchings/main/84830", setChannelByteParam);

INCLUDE_ASM("asm/nonmatchings/main/84830", getChannelByteParam);

INCLUDE_ASM("asm/nonmatchings/main/84830", setChannelByteParamAlt);

INCLUDE_ASM("asm/nonmatchings/main/84830", getChannelByteParamAlt);

INCLUDE_ASM("asm/nonmatchings/main/84830", resetChannelStateRecord);

INCLUDE_ASM("asm/nonmatchings/main/84830", getChannelControllerValue);

INCLUDE_ASM("asm/nonmatchings/main/84830", initVoiceModulatorRecords);

INCLUDE_ASM("asm/nonmatchings/main/84830", evaluateVoiceModulatorRecord);

INCLUDE_ASM("asm/nonmatchings/main/84830", evaluateVoiceModulatorRecordZero);

INCLUDE_ASM("asm/nonmatchings/main/84830", evaluateVoiceModulatorRecordOne);

INCLUDE_ASM("asm/nonmatchings/main/84830", evaluateVoiceModulatorRecordTwo);

INCLUDE_ASM("asm/nonmatchings/main/84830", evaluateVoiceModulatorRecordThree);

INCLUDE_ASM("asm/nonmatchings/main/84830", evaluateVoiceModulatorRecordFour);

INCLUDE_ASM("asm/nonmatchings/main/84830", evaluateVoiceModulatorRecordFive);

INCLUDE_ASM("asm/nonmatchings/main/84830", evaluateVoiceModulatorRecordSix);

INCLUDE_ASM("asm/nonmatchings/main/84830", evaluateVoiceModulatorRecordSeven);

INCLUDE_ASM("asm/nonmatchings/main/84830", evaluateVoiceModulatorRecordEight);

INCLUDE_ASM("asm/nonmatchings/main/84830", factor5SortedTableInsertValue);

INCLUDE_ASM("asm/nonmatchings/main/84830", factor5SortedTableRemoveValue);

INCLUDE_ASM("asm/nonmatchings/main/84830", factor5SortedTableInsertTaggedValue);

INCLUDE_ASM("asm/nonmatchings/main/84830", factor5SortedTableRemoveTaggedValue);

INCLUDE_ASM("asm/nonmatchings/main/84830", factor5SecondSortedTableInsertValue);

INCLUDE_ASM("asm/nonmatchings/main/84830", factor5SecondSortedTableRemoveValue);

INCLUDE_ASM("asm/nonmatchings/main/84830", factor5SortedTableInsertWidePair);

INCLUDE_ASM("asm/nonmatchings/main/84830", factor5SortedTableRemoveWidePair);

INCLUDE_ASM("asm/nonmatchings/main/84830", factor5SortedTableInsertVoiceRecord);

INCLUDE_ASM("asm/nonmatchings/main/84830", factor5SortedTableRemoveVoiceRecord);

INCLUDE_ASM("asm/nonmatchings/main/84830", factor5BucketedTableInsertEntry);

INCLUDE_ASM("asm/nonmatchings/main/84830", factor5BucketedTableRemoveEntry);

INCLUDE_ASM("asm/nonmatchings/main/84830", binarySearchWithComparator);

INCLUDE_ASM("asm/nonmatchings/main/84830", func_main_80085CD8);

INCLUDE_ASM("asm/nonmatchings/main/84830", factor5BucketedTableLookupValue);

INCLUDE_ASM("asm/nonmatchings/main/84830", compareHalfwordAtOffset8);

INCLUDE_ASM("asm/nonmatchings/main/84830", factor5SortedTableLookupWidePairRecord);

INCLUDE_ASM("asm/nonmatchings/main/84830", compareHalfwordAtOffset4_v2);

INCLUDE_ASM("asm/nonmatchings/main/84830", factor5SecondSortedTableLookupValue);

INCLUDE_ASM("asm/nonmatchings/main/84830", factor5SortedTableLookupValue);

INCLUDE_ASM("asm/nonmatchings/main/84830", compareHalfwordAtOffset4_v3);

INCLUDE_ASM("asm/nonmatchings/main/84830", factor5SortedTableLookupTaggedValue);

INCLUDE_ASM("asm/nonmatchings/main/84830", cmpU16ByValue);

INCLUDE_ASM("asm/nonmatchings/main/84830", musyxSortedInsertByU16);

INCLUDE_ASM("asm/nonmatchings/main/84830", freeSynthVoiceFromActiveList);

INCLUDE_ASM("asm/nonmatchings/main/84830", allocVoiceHandleNode);

INCLUDE_ASM("asm/nonmatchings/main/84830", resolveVoiceSlotByHandle);

INCLUDE_ASM("asm/nonmatchings/main/84830", allocateSynthVoice);

INCLUDE_ASM("asm/nonmatchings/main/84830", stopVoiceByKey);

INCLUDE_ASM("asm/nonmatchings/main/84830", silenceVoiceSlot);

INCLUDE_ASM("asm/nonmatchings/main/84830", computeVoiceGlidePitch);

INCLUDE_ASM("asm/nonmatchings/main/84830", queryVoicePlayPositionByHandle);

INCLUDE_ASM("asm/nonmatchings/main/84830", findActiveVoiceByKeyPair);

INCLUDE_ASM("asm/nonmatchings/main/84830", findVoiceForNote);

INCLUDE_ASM("asm/nonmatchings/main/84830", startNoteOnVoice);

INCLUDE_ASM("asm/nonmatchings/main/84830", applyNoteEventToGroup);

INCLUDE_ASM("asm/nonmatchings/main/84830", dispatchSequencerNoteEvent);

INCLUDE_ASM("asm/nonmatchings/main/84830", musyxNoteEventLockedDispatch);

INCLUDE_ASM("asm/nonmatchings/main/84830", bsearchFactor5TableByU16Key);

INCLUDE_ASM("asm/nonmatchings/main/84830", validateVoiceHandle);

INCLUDE_ASM("asm/nonmatchings/main/84830", musyxSetSequenceParamLocked);

INCLUDE_ASM("asm/nonmatchings/main/84830", musyxQuerySequenceLocked);

INCLUDE_ASM("asm/nonmatchings/main/84830", setVoiceParamByHandle);

INCLUDE_ASM("asm/nonmatchings/main/84830", setVoiceParamByHandleLocked);

INCLUDE_ASM("asm/nonmatchings/main/84830", applyVoiceCmdByHandle);

s32 applyVoiceCmdByHandleLocked(s32 arg0, u8 arg1) {
    s32 var_s0;

    var_s0 = -1;
    if (gMusyXActiveFlag != 0) {
        factor5MutexAcquire();
        var_s0 = applyVoiceCmdByHandle(arg0, arg1);
        factor5MutexRelease();
    }
    return var_s0;
}

INCLUDE_ASM("asm/nonmatchings/main/84830", spreadVoiceKeyTransposeAcrossChain);

INCLUDE_ASM("asm/nonmatchings/main/84830", spreadVoiceKeyTransposeLocked);

INCLUDE_ASM("asm/nonmatchings/main/84830", spreadVoicePanVolumeAcrossChain);

INCLUDE_ASM("asm/nonmatchings/main/84830", safeLookup3DSoundEntry);

INCLUDE_ASM("asm/nonmatchings/main/84830", spreadVoiceParamPairLocked);

INCLUDE_ASM("asm/nonmatchings/main/84830", spreadVoiceByteParamAcrossChain);

INCLUDE_ASM("asm/nonmatchings/main/84830", spreadVoiceByteParamLocked);

INCLUDE_ASM("asm/nonmatchings/main/84830", spreadVoiceParamLockedVariant);

INCLUDE_ASM("asm/nonmatchings/main/84830", flagVoiceChainForStop);

INCLUDE_ASM("asm/nonmatchings/main/84830", stopVoiceByHandleLocked);

INCLUDE_ASM("asm/nonmatchings/main/84830", shiftChannelStreamLeft8);

INCLUDE_ASM("asm/nonmatchings/main/84830", computeChannelTempoStepFromTable);

INCLUDE_ASM("asm/nonmatchings/main/84830", computeChannelWaitDuration);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroOpWaitTicks);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroOpStopVoice);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroOpReturnFromGosub);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroOpGosubLoopCounterFiftyFour);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroOpGosubLoopCounterThirty);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroOpGosubModulatorLoop);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroOpGosubRandomLoop);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroOpGosub);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroOpGosubAltReturnFrame);

INCLUDE_ASM("asm/nonmatchings/main/84830", clearChannelFieldsAt1Cand20);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroOpLoopRandomCount);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroOpKeyOnNote);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroOpKeyOffByNote);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroOpAddPitchBend);

INCLUDE_ASM("asm/nonmatchings/main/84830", setChannelProgHalfwordAt28);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroOpSetPitchBendGlide);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroOpAddKeyByte);

INCLUDE_ASM("asm/nonmatchings/main/84830", setChannelProgByteAt2E);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroOpStoreGlobalRegister);

INCLUDE_ASM("asm/nonmatchings/main/84830", setChannelKeyOffsetAt6E);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroOpPortamentoStartWait);

INCLUDE_ASM("asm/nonmatchings/main/84830", computeChannelPitchSweepStep);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroOpStartNoteAbsoluteSweep);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroOpStartNoteRelativeSweep);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroOpStartNoteTransposedSweep);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroOpPlaySampleKeymap);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroOpKeyOff);

INCLUDE_ASM("asm/nonmatchings/main/84830", setChannelFlag24Bit80);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroOpSetPanSweep);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroOpSetProgramTableValue);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroOpStartPitchEnvelope);

INCLUDE_ASM("asm/nonmatchings/main/84830", musyxSetVoiceAdsrFromTable);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroOpStartVibrato);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroOpSetVolumeRamp);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroOpSetPitchRelativeToNote);

INCLUDE_ASM("asm/nonmatchings/main/84830", evaluateSoundMacroCurveTable);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroSetVoiceVolume);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroSetupVolumeRamp);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroPlayRandomKeyNote);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroSetFlagBitVibrato);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroSetFlagBitTremolo);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroPushEffectEvent);

INCLUDE_ASM("asm/nonmatchings/main/84830", seqCmdHandler40);

INCLUDE_ASM("asm/nonmatchings/main/84830", seqCmdHandler41);

INCLUDE_ASM("asm/nonmatchings/main/84830", seqCmdHandler42);

INCLUDE_ASM("asm/nonmatchings/main/84830", seqCmdHandler43);

INCLUDE_ASM("asm/nonmatchings/main/84830", seqCmdHandler44);

INCLUDE_ASM("asm/nonmatchings/main/84830", seqCmdHandler45);

INCLUDE_ASM("asm/nonmatchings/main/84830", seqCmdHandler46);

INCLUDE_ASM("asm/nonmatchings/main/84830", refreshVoicePlaybackRate);

INCLUDE_ASM("asm/nonmatchings/main/84830", soundMacroSetPitchTarget);

INCLUDE_ASM("asm/nonmatchings/main/84830", tickAudioChannel);

INCLUDE_ASM("asm/nonmatchings/main/84830", tickAllAudioChannels);

INCLUDE_ASM("asm/nonmatchings/main/84830", tickAudioSequencerFrame);

INCLUDE_ASM("asm/nonmatchings/main/84830", tickMusyXIfActive);

INCLUDE_ASM("asm/nonmatchings/main/84830", releaseSynthVoice);

INCLUDE_ASM("asm/nonmatchings/main/84830", stopVoicesByHandle);

INCLUDE_ASM("asm/nonmatchings/main/84830", stopAllSynthVoices);

INCLUDE_ASM("asm/nonmatchings/main/84830", getMusyXChannelSlotByte);

INCLUDE_ASM("asm/nonmatchings/main/84830", setMusyXChannelSlotByte);

INCLUDE_ASM("asm/nonmatchings/main/84830", setMusyXVoiceTickGate);

INCLUDE_ASM("asm/nonmatchings/main/84830", dispatchAudioCommand);

INCLUDE_ASM("asm/nonmatchings/main/84830", playSimpleAudioCmd);

void applyMusicOrSfxVolume(u8 arg0, u16 arg1, u8 arg2, u8 arg3) {
    if (gMusyXActiveFlag != 0) {
        factor5MutexAcquire();
        if (arg2) {
            dispatchAudioCommand(arg0, arg1, 0x15U, 0U, 0U);
        }
        if (arg3) {
            dispatchAudioCommand(arg0, arg1, 0x16U, 0U, 0U);
        }
        factor5MutexRelease();
    }
}

INCLUDE_ASM("asm/nonmatchings/main/84830", isAudioFaderRampActive);

INCLUDE_ASM("asm/nonmatchings/main/84830", setupAudioFaderRamp);

INCLUDE_ASM("asm/nonmatchings/main/84830", setAudioFaderRampLocked);

INCLUDE_ASM("asm/nonmatchings/main/84830", setAudioFaderState);

INCLUDE_ASM("asm/nonmatchings/main/84830", anyAudioSlotActive);

INCLUDE_ASM("asm/nonmatchings/main/84830", resetMusyXEngineState);

INCLUDE_ASM("asm/nonmatchings/main/84830", clearMusyXSequencerState);

INCLUDE_ASM("asm/nonmatchings/main/84830", getMusyXStateTableIfActive);

INCLUDE_ASM("asm/nonmatchings/main/84830", syncMusyXIfActive);

INCLUDE_ASM("asm/nonmatchings/main/84830", runMusyXTaskLocked);

INCLUDE_ASM("asm/nonmatchings/main/84830", initMusyXEngine);

INCLUDE_ASM("asm/nonmatchings/main/84830", setDisplayMode);

INCLUDE_ASM("asm/nonmatchings/main/84830", reapplyDisplayMode);

INCLUDE_ASM("asm/nonmatchings/main/84830", shutdownMusyXEngine);

INCLUDE_ASM("asm/nonmatchings/main/84830", musyxNoopStub);

u8 isMusyXActive(void) {
    return gMusyXActiveFlag;
}

INCLUDE_ASM("asm/nonmatchings/main/84830", fake_func_8008ED6C);
