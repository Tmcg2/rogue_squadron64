#ifndef MAIN_47220_H
#define MAIN_47220_H

#include "common_types.h"

#include "dat.h"

void  freeLevelDatBuffers(void);
void  getLevelDatItemByName(char*);
void *getDatItemByName(struct dat_file_header*, char*);
s32   isPointXzWithinRangeOfRef(Vec3f, Vec3f);

#endif
