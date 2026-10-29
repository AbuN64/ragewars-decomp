#include "include_asm.h"
#include "COMMON/OSVISCALE.H"
#include "SYSTEM/VIDEO_CONTEXT_VIEWS.H"
#include "TYPES.H"
#include "sdk/os.h"

/** Returns g_currentVideoInterfaceContext. */
extern void *g_currentVideoInterfaceContext;

void *System_GetCurrentVideoContext(void) {
    return g_currentVideoInterfaceContext;
}

extern void *g_nextVideoInterfaceContext;

void System_SetVideoEvent(s32 messageQueue, s32 retraceMessage, s16 retraceInterval) {
    u32 savedInterruptMask;
    VideoContextEventView *rec;

    savedInterruptMask = __osDisableInt();
    rec = g_nextVideoInterfaceContext;
    rec->f10 = messageQueue;
    rec->f14 = retraceMessage;
    rec->f2 = retraceInterval;
    __osRestoreInt(savedInterruptMask);
}

#if defined(VERSION_US)
char s_onEnemyMemberNameFragment[8] =
    "m_OnEnem";
#endif
