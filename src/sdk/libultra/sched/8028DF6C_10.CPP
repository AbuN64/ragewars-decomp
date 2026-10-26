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
#include "sdk/AUDIO_2/802BF400.H"
#include "sdk/SCHED/8028DF6C_7.H"
#include "sdk/libgultra/libasm_802BD1A8_3.h"
#include "sdk/libgultra/sptaskyield.h"
#include "sdk/os.h"
extern s32 D_80142C30;
extern s32 D_80142C38;
void __scAppendList(OSSched *scheduler, void *task) {
    void *previousTail;

    if ((((struct OSScTask_s *)task)->list.type) == 2) {
        previousTail = scheduler->audioListTail;
        if (previousTail != 0) {
            ((struct OSScTask_s *)previousTail)->next = task;
        } else {
            scheduler->audioListHead = task;
        }
        scheduler->audioListTail = task;
        scheduler->doAudio = 1;
    } else {
        previousTail = scheduler->gfxListTail;
        if (previousTail != 0) {
            ((struct OSScTask_s *)previousTail)->next = task;
        } else {
            scheduler->gfxListHead = task;
        }
        scheduler->gfxListTail = task;
    }
    ((struct OSScTask_s *)task)->next = 0;
    ((struct OSScTask_s *)task)->state = (((struct OSScTask_s *)task)->flags) & 3;
}

void *Sched_GetTaskWithAvailableFramebuffer(struct OSScTask_s *arg0) {
    s32 f1a;
    s32 f1b;
    void *v2;

    if (arg0 == 0) {
        return 0;
    }
    f1a = (s32)arg0->framebuffer;
    if (f1a == D_80142C38) {
        return 0;
    }
    v2 = osViGetCurrentFramebuffer();
    f1b = (s32)arg0->framebuffer;
    if (f1b == (s32)v2) {
        return 0;
    }
    if (f1b != D_80142C30) {
        return arg0;
    }
    return 0;
}

s32 Sched_CompleteTaskAndSwapBuffer(void *arg0, void *arg1) {
    if ((((s32)((struct OSScTask_s *)arg1)->state)) & 3) {
        return 0;
    }
    if ((((struct OSScTask_s *)arg1)->list.type) != 1) {
        return 1;
    }
    if (((((s32)((struct OSScTask_s *)arg1)->flags)) & 0x60) != 0x60) {
        return 1;
    }
    osViSwapBuffer(((s32)((struct OSScTask_s *)arg1)->framebuffer));
    return 1;
}


#if defined(VERSION_US)
unsigned int rodata_unresolved_800C52B4[3] = {
    0x63616C65, 0x52000088, 0x00000008,
};
#endif

#if defined(VERSION_EU_X)
char rodata_unresolved_800C5674[12] =
    "LILLY\000\000\000JIM ";
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C5384[3] = {
    0x4123D70A, 0x3F800000, 0x42A3D70A,
};
#endif
