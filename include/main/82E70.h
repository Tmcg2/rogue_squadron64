#ifndef MAIN_82E70_H
#define MAIN_82E70_H

#include "PR/ultratypes.h"

u8   isCheatCodeIndexAllowed(u8);
u32 *make_crc32_lut(void);
u32  rs_crc32(u32*, u8*, u32);

#endif
