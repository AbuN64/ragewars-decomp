#include "include_asm.h"
#include "COMMON/LONE/D_80106248.H"
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
#include "sdk/AUDIO/OSVIGETCURRENTFRAMEBUFFER.H"
#include "sdk/SCHED/osscremoveclient.H"
#include "sdk/libgultra/OSWRITEBACKDCACHEALL.H"
#include "sdk/libgultra/sptaskyield.h"
#include "sdk/os.h"

extern s32 D_800CD704;
extern void Scene_SetThreadPriority(void *arg0, s32 pri);
void __scYield(void *scheduler) {
    void *currentRspTask;
    currentRspTask = (((struct ObjectLinks2F8 *) ((s8 *) scheduler))->unk_2F4);
    if ((((struct IntegerState14 *) ((s8 *) currentRspTask))->unk_10) == 1) {
        (((struct IntegerState14 *) ((s8 *) currentRspTask))->unk_4) = (s32) ((((struct IntegerState14 *) ((s8 *) currentRspTask))->unk_4) | 0x10);
        osSpTaskYield();
    }
}

void Sched_HandleTaskCommands(void *scheduler) {
    NodeSchedHandleTaskCommands *node = 0;
    s32 value1 = 0;
    s32 value2 = 0;
    s32 flags;

    while (osRecvMesg(&((OSSched *)scheduler)->commandQueue, &node, 0) != -1) {
        if (node->type == 1 && (node->flags & 0x20) && D_800CD704 == 0) {
            D_800CD704 = 2;
            Scene_SetThreadPriority(&D_80106248, D_800CD8B8_de);
        }
        __scAppendList(scheduler, node);
    }

    if (((OSSched *)scheduler)->doAudio != 0 &&
        ((OSSched *)scheduler)->curRSPTask != 0) {
        __scYield(scheduler);
        return;
    }

    flags = (((OSSched *)scheduler)->curRSPTask == 0) * 2 |
            (((OSSched *)scheduler)->curRDPTask == 0);
    if (((s32 (*)(void *, s32 *, s32 *, s32))Sched_SelectRunnableTasks)(scheduler, &value1, &value2, flags) != flags) {
        ((void (*)(void *, s32, s32))Sched_StartSelectedTasks)(scheduler, value1, value2);
    }
}

int Sched_GetInterruptQueueAddress(int arg0) {
    return arg0 + 0x40;
}
