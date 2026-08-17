#ifndef MAIN_07800_H
#define MAIN_07800_H

#include "PR/os.h"

struct D_801128D0_type {
    OSId theadId;                 /* 0x000 */
    u8 threadPrio;                /* 0x004 */
    u8 unk005;                    /* 0x005 */
    u16 mesgCount;                /* 0x006 */
    u32 *threadStackPointer;      /* 0x008 */
    u32 *threadStackEnd;          /* 0x00C */
    u32 threadStackSize;          /* 0x010 */
    void (*entry)(void*);         /* 0x014 */
    struct D_801128D0_type *next; /* 0x018 */
    OSMesg *mesg;                 /* 0x01C */
    OSThread thread;              /* 0x020 */
    OSMesgQueue mq;               /* 0x1D0 */
    OSMesg mesg2[2];              /* 0x1E8 */
}; // size = 0x1F0

s32    initServiceRegistry(void);
s32    returnTrueServiceStub(void);
s32    startServiceWorker(OSId);
s32   checkServiceWorkerStackGuard(OSId);
s32    peekServiceMessage(OSId);
OSMesg tryRecvServiceMessage(OSId);
OSMesg recvServiceMessage(OSId);
s32    postMessageToServiceWorker(OSId, OSMesg);
s32    unregisterServiceWorker(OSId);
s32    setServiceWorkerPriority(OSId, u8);
s32    yieldThreadRet1(s32);
s32    stopServiceWorker(OSId);
s32    restartServiceWorker(OSId);

#endif
