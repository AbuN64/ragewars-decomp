#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "sdk/libgultra.h"
#include "COMMON/OSTHREAD_S.H"
#include "TYPES.H"
#include "sdk/os.h"

void osCreateMesgQueue(OSMesgQueue *mq, OSMesg *msg, s32 msgCount) {
    mq->mtqueue = (void **)&D_800D5260;
    mq->fullqueue = (void **)&D_800D5260;
    mq->validCount = 0;
    mq->first = 0;
    mq->msgCount = msgCount;
    mq->msg = msg;
}

#if defined(VERSION_US)
char rodata_unresolved_802BABB4[12] =
    "GameRumble_t";
#endif
