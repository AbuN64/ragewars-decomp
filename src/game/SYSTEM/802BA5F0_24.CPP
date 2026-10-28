#include "include_asm.h"
#include "COMMON/OSVISCALE.H"
#include "SYSTEM/802BA5F0.H"
#include "TYPES.H"
#include "sdk/os.h"

/** Returns D_800D8440. */
extern void *D_800D8440;

void *System_GetCurrentVideoContext(void) {
    return D_800D8440;
}

extern void *D_800D4414;

void System_SetVideoEvent(s32 messageQueue, s32 retraceMessage, s16 retraceInterval) {
    u32 savedInterruptMask;
    RecCode802BA23C *rec;

    savedInterruptMask = __osDisableInt();
    rec = D_800D4414;
    rec->f10 = messageQueue;
    rec->f14 = retraceMessage;
    rec->f2 = retraceInterval;
    __osRestoreInt(savedInterruptMask);
}

#if defined(VERSION_US)
char rodata_unresolved_802BA5D8[8] =
    "m_OnEnem";
#endif
