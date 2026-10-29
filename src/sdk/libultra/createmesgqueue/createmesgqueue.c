#include "include_asm.h"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "sdk/libgultra.h"
#include "COMMON/OSTHREAD_S.H"
#include "TYPES.H"
#include "sdk/os.h"

/* 802BFD80_2.CPP */
#if defined(VERSION_DE)
unsigned char g_CreatemesgqueueTrailingBytes[12] = { 0xAF, 0xB0, 0x00, 0x10, 0x00, 0x80, 0x80, 0x21, 0x00, 0xE0, 0x48, 0x21 };
#endif

/* createmesgqueue.c */
void osCreateMesgQueue(OSMesgQueue *mq, OSMesg *msg, s32 msgCount) {
    mq->mtqueue = (void **)&g_emptyThreadQueue;
    mq->fullqueue = (void **)&g_emptyThreadQueue;
    mq->validCount = 0;
    mq->first = 0;
    mq->msgCount = msgCount;
    mq->msg = msg;
}

#if defined(VERSION_US)
char s_CreatemesgqueueGameRumbleTText[12] =
    "GameRumble_t";
#endif
