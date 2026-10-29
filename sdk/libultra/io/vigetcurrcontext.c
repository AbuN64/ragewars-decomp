#include "include_asm.h"
#include "COMMON/OSVISCALE.H"
#include "SYSTEM/VIDEO_CONTEXT_VIEWS.H"
#include "TYPES.H"
#include "../../include/os.h"

/** Returns __osViCurr. */
extern void *__osViCurr;

void *__osViGetCurrentContext(void) {
    return __osViCurr;
}

extern void *__osViNext;

void osViSetEvent(s32 messageQueue, s32 retraceMessage, s16 retraceInterval) {
    u32 savedInterruptMask;
    VideoContextEventView *rec;

    savedInterruptMask = __osDisableInt();
    rec = __osViNext;
    rec->f10 = messageQueue;
    rec->f14 = retraceMessage;
    rec->f2 = retraceInterval;
    __osRestoreInt(savedInterruptMask);
}

#if defined(VERSION_US)
char s_onEnemyMemberNameFragment[8] =
    "m_OnEnem";
#endif
