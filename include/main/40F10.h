#ifndef MAIN_40F10_H
#define MAIN_40F10_H

#include "PR/ultratypes.h"

void allocAndInitParticlePool(void);
void freeNpcBurstSpawnerTables(void);
void destroyNpcSlotByIndexU16(u16);
void setNpcForwardVectorByIndex(u16, Vec3f);

#endif
