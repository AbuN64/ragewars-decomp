#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "sdk/libgultra.h"
#include "COMMON/OSTHREAD_S.H"
#include "TYPES.H"
#include "sdk/os.h"

/* 802BFD80_2.CPP */
#if defined(VERSION_DE)
unsigned char D_auto_func_802BAC84_de_padding_BB884[12] = { 0xAF, 0xB0, 0x00, 0x10, 0x00, 0x80, 0x80, 0x21, 0x00, 0xE0, 0x48, 0x21 };
#endif

/* createmesgqueue.c */
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
