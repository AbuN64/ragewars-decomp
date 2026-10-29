#include "include_asm.h"
#include "COMMON/WORLDSORTENTRY.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/OSTASK_T.H"
#include "COMMON/OSVISCALE.H"
#include "COMMON/BOOT_MEMORY_AND_THREAD_BOUNDARIES.H"
#include "COMMON/LLDIVRESULT.H"
#include "TYPES.H"
#include "TYPES.H"
#include "COMMON/BOOT_TV_TYPE.H"
#include "../../include/AUDIO/OSVIGETCURRENTFRAMEBUFFER.H"
#include "../../include/SCHED/osscremoveclient.H"
#include "../../include/libgultra/OSWRITEBACKDCACHEALL.H"
#include "../../include/libgultra/sptaskyield.h"
#include "../../include/os.h"

s32 osSetIntMask(s32);

void osScAddClient(OSSched *scheduler, OSScClientWork *client, OSMesgQueue *messageQueue) {
    s32 savedInterruptMask;
    savedInterruptMask = osSetIntMask(1);
    client->queue = messageQueue;
    client->next = scheduler->clientList;
    scheduler->clientList = client;
    osSetIntMask(savedInterruptMask);
}

void osScRemoveClient(OSSched *scheduler, void *client) {
    s32 saved;
    OSScClientWork *cur;
    OSScClientWork *prev;

    prev = 0;
    cur = scheduler->clientList;
    saved = osSetIntMask(1);
    while (cur != 0) {
        if (cur == client) {
            if (prev != 0) {
                prev->next = cur->next;
            } else {
                scheduler->clientList = cur->next;
            }
            break;
        }
        prev = cur;
        cur = cur->next;
    }
    osSetIntMask(saved);
}
