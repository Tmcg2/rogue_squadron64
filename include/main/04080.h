#ifndef MAIN_04080_H
#define MAIN_04080_H

#include "common_types.h"
#include "PR/ultratypes.h"

struct manifest_entry *find_manifest_entry(s32, u8*, u32);
void  noopHandler_80004FC8(void);
void  noopHandler_80004FD0(void);
s32   setManifestEntryName(s32, u8*);
s32   get_manifest_entry_type(u32, u8*);
s32   zlibReturnZeroStub(void);
void *mallocWithFallbackStrategy(s32);
void  rs_zcfree(void*);
void *rs_zcalloc(u32, u32);
s32   returnNegativeOneStub(void);
s32   returnZeroStubZlib(void);

#endif
