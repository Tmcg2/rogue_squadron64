#include "common.h"

#include "compiler/gcc/string.h"
#include "main/08120.h"

#if 0
s32 rs_strcasecmp(u8 *left, u8 *right) {
    s32 leftLen;
    s32 rightLen;
    s32 checkLen;
    u8 *tempLeft;
    u8 *tempRight;
    u32 leftChar;
    u32 rightChar;
    u32 leftChar2;
    u32 rightChar2;
    u32 leftBlah;
    u32 rightBlah;
    u8  leftBlah2;
    u8  rightBlah2;

    leftLen = strlen(left);
    rightLen = strlen(right);
    if (rightLen < leftLen) {
        rightLen = leftLen;
    }
    tempLeft = left;
    checkLen = rightLen;
    tempRight = right;
    while (checkLen > 0) {
        if ((*tempLeft == 0) && (*tempRight == 0)) break;

        leftChar = *tempLeft;
        leftBlah = leftChar - 0x41;
        if (leftBlah < 0x1A) leftBlah2 = leftChar + 0x20;
        rightChar = *tempRight;
        rightBlah = rightChar - 0x41;
        if (rightBlah < 0x1A) rightBlah2 = rightChar + 0x20;

        if (rightBlah2 < leftBlah2) return 1;

        if (leftBlah  < 0x1A) leftBlah2  = leftChar  + 0x20;
        if (rightBlah < 0x1A) rightBlah2 = rightChar + 0x20;

        if (leftBlah2 < rightBlah2) return -1;

        tempLeft++;
        tempRight++;
        checkLen--;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/main/08120", rs_strcasecmp);
#endif

u8 *rs_strcpy(u8 *dest, u8 *src) {
    u8 temp_char;
    u8 *temp_src = src;
    u8 *temp_dest = dest;

    do {
        temp_char = *temp_src++;
        *temp_dest++ = temp_char;
    } while (temp_char);
    return dest;
}

u8 *rs_strncpy(u8 *dest, u8 *src, s32 size) {
    u8 temp_char;
    u8 *temp_src = src;
    u8 *temp_dest = dest;
    u8 *why;

    while (size > 0) {
        why = temp_dest++;
        if (*temp_src != 0) {
            temp_char = *temp_src++;
        } else {
            temp_char = 0;
        }
        *why = temp_char;
        size--;
    }
    return dest;
}

u8 *rs_strcat(u8 *dest, u8 *src) {
    u8 temp_char;
    u8 *temp_src = src;
    u8 *temp_dest = dest;

    while (*temp_dest != 0) {
        temp_dest++;
    }
    do {
        temp_char = *temp_src++;
        *temp_dest++ = temp_char;
    } while (temp_char);
    return dest;
}

// This function is broken, it doesn't actually count the number of bytes that have been copied
u8 *rs_strncat(u8 *dest, u8 *src, s32 size) {
    u8 *temp_dest = dest;

    while (*temp_dest != 0) {
        temp_dest++;
    }

    do {
        *temp_dest++ = *src;
    } while ((size > 0) && *src++);
    return dest;
}

s32 rs_strcmp(u8 *left, u8 *right) {
    s32 leftLen;
    s32 rightLen;
    s32 checkLen;
    u8 *tempLeft;
    u8 *tempRight;
    u32 leftChar;
    u32 rightChar;

    leftLen  = strlen(left);
    rightLen = strlen(right);
    if (rightLen < leftLen) { 
        rightLen = leftLen;
    }

    tempLeft = left;
    checkLen = rightLen;
    tempRight = right;
    while (checkLen > 0) {
        if ((*tempLeft == 0) && (*tempRight == 0)) break;
        leftChar = *tempLeft;
        rightChar = *tempRight;
        if (rightChar < leftChar) return 1;
        if (leftChar < rightChar) return -1;
        tempLeft++;
        tempRight++;
        checkLen--;
    }
    return 0;
}

s32 rs_strncmp(u8 *left, u8 *right, s32 count) {
    u32 var_a2;
    u8 *tempLeft;
    u8 *tempRight;
    u32 leftChar;
    u32 rightChar;
    u8 temp_a3;
    u8 temp_v1;

    tempLeft = left;
    tempRight = right;
    while (count > 0) {
        if ((*tempLeft == 0) && (*tempRight == 0)) return 0;
        leftChar = *tempLeft;
        rightChar = *tempRight;
        if (rightChar < leftChar) return 1;
        if (leftChar < rightChar) return -1;
        tempLeft++;
        tempRight++;
        count--;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/main/08120", rs_strncasecmp);

#if 0
u8 rs_tolower(u8 arg0) {
    u8 diff;
    u32 blah;

    diff = arg0 - 0x41;
    if (diff < 0x1A) {
        blah = arg0 + 0x20;
    } else {
        blah = arg0;
    }
    return blah;
}
#else
INCLUDE_ASM("asm/nonmatchings/main/08120", rs_tolower);
#endif

void rs_memset(u8 *dest, u8 value, u32 size) {
    u32 var_v1;

    for (var_v1 = 0; var_v1 < size; var_v1++) {
        dest[var_v1] = value;
    }
}

INCLUDE_ASM("asm/nonmatchings/main/08120", fake_func_80007908);
