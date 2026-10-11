#ifndef MAIN_98660_H
#define MAIN_98660_H

#include "PR/ultratypes.h"
#include "factor5_list.h"

void clearStreamedVoiceFlags(void);
s32  factor5RemoveListNode(struct factor5_list_node*);
void tickAndReap3DAudioVoices(void);
void reset3DAudioLists(void);
void noopHandler_80099C44(void);

#endif
