#include "include_asm.h"
#include "COMMON/WORLDSORTENTRY.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/OSTASK_T.H"
#include "COMMON/OSVISCALE.H"
#include "COMMON/EXTERNS_18.H"
#include "COMMON/LLDIVRESULT.H"
#include "TYPES.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_3.H"
#include "sdk/AUDIO/802BF400.H"
#include "sdk/SCHED/8028DF6C_7.H"
#include "sdk/libgultra/libasm_802BD1A8_3.h"
#include "sdk/libgultra/sptaskyield.h"
#include "sdk/os.h"

s32 func_802BD170_de(s32);

void osScAddClient(OSSched *scheduler, OSScClientWork *client, OSMesgQueue *messageQueue) {
    s32 savedInterruptMask;
    savedInterruptMask = func_802BD170_de(1);
    client->queue = messageQueue;
    client->next = scheduler->clientList;
    scheduler->clientList = client;
    func_802BD170_de(savedInterruptMask);
}

void osScRemoveClient(OSSched *arg0, void *arg1) {
    s32 saved;
    OSScClientWork *cur;
    OSScClientWork *prev;

    prev = 0;
    cur = arg0->clientList;
    saved = func_802BD170_de(1);
    while (cur != 0) {
        if (cur == arg1) {
            if (prev != 0) {
                prev->next = cur->next;
            } else {
                arg0->clientList = cur->next;
            }
            break;
        }
        prev = cur;
        cur = cur->next;
    }
    func_802BD170_de(saved);
}
