#ifndef MAIN_48A50_H
#define MAIN_48A50_H

#include "PR/ultratypes.h"

void allocAndInitGridCellArray(s32);
void loadLevelTextureCache(s32);
void recycleGridCellToFreeList(void);
void freeGridCellBuffers(void);
void teardownGridLayerWorker(void);

#endif
