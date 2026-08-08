#ifndef MAIN_08120_H
#define MAIN_08120_H

#include "PR/ultratypes.h"

u8  *rs_strcpy(u8*, u8*);
u8  *rs_strncpy(u8*, u8*, s32);
u8  *rs_strcat(u8*, u8*);
u8  *rs_strncat(u8*, u8*, s32);
s32  rs_strcmp(u8*, u8*);
s32  rs_strncmp(u8*left, u8*, s32);
u8   rs_tolower(u8);
void rs_memset(u8*, u8, u32);

#endif
