#include "common.h"

INCLUDE_ASM("asm/nonmatchings/main/07800", initServiceRegistry);

INCLUDE_ASM("asm/nonmatchings/main/07800", returnTrueServiceStub);

INCLUDE_ASM("asm/nonmatchings/main/07800", registerServiceWorker);

INCLUDE_ASM("asm/nonmatchings/main/07800", startServiceWorker);

INCLUDE_ASM("asm/nonmatchings/main/07800", checkServiceWorkerStackGuard);

INCLUDE_ASM("asm/nonmatchings/main/07800", peekServiceMessage);

INCLUDE_ASM("asm/nonmatchings/main/07800", tryRecvServiceMessage);

INCLUDE_ASM("asm/nonmatchings/main/07800", recvServiceMessage);

INCLUDE_ASM("asm/nonmatchings/main/07800", sendServiceMessage);

INCLUDE_ASM("asm/nonmatchings/main/07800", signalServiceWorkerStop);

INCLUDE_ASM("asm/nonmatchings/main/07800", func_main_80007064);

INCLUDE_ASM("asm/nonmatchings/main/07800", postMessageToServiceWorker);

INCLUDE_ASM("asm/nonmatchings/main/07800", unregisterServiceWorker);

INCLUDE_ASM("asm/nonmatchings/main/07800", sendServiceMessageAwaitReply);

INCLUDE_ASM("asm/nonmatchings/main/07800", setServiceWorkerPriority);

INCLUDE_ASM("asm/nonmatchings/main/07800", yieldThreadRet1);

INCLUDE_ASM("asm/nonmatchings/main/07800", stopServiceWorker);

INCLUDE_ASM("asm/nonmatchings/main/07800", restartServiceWorker);

INCLUDE_ASM("asm/nonmatchings/main/07800", getServiceMessagePayload);

INCLUDE_ASM("asm/nonmatchings/main/07800", fake_func_8000737C);
