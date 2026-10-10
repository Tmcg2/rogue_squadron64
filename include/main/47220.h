#ifndef MAIN_47220_H
#define MAIN_47220_H

#include "common_types.h"

#include "dat.h"

struct dat_file_header *loadDatFile(s32);
void  updateActiveGridCellState(Vec3f);
void  freeLevelDatBuffers(void);
void *getLevelDatItemByName(char*);
void *getDatItemByName(struct dat_file_header*, char*);
void  isNpcWithinActiveReferenceRange(Vec3f);
s32   isPointXzWithinRangeOfRef(Vec3f, Vec3f);

#endif
