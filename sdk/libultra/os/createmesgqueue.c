#include "include_asm.h"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "../../include/libgultra.h"
#include "COMMON/OSTHREAD_S.H"
#include "TYPES.H"
#include <ultra64.h>
#include <PR/os_internal_reg.h>
#include <PR/os_internal_si.h>

/* 802BFD80_2.CPP */

/* createmesgqueue.c */
void osCreateMesgQueue(OSMesgQueue *mq, OSMesg *msg, s32 msgCount) {
    mq->mtqueue = (void **)&__osThreadTail;
    mq->fullqueue = (void **)&__osThreadTail;
    mq->validCount = 0;
    mq->first = 0;
    mq->msgCount = msgCount;
    mq->msg = msg;
}

