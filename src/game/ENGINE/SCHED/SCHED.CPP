#include "include_asm.h"
#include "COMMON/LONE/SCHEDULER_ACCUMULATED_GRAPHICS_RSP_DURATION.H"
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
#include "sdk/AUDIO/OSVIGETCURRENTFRAMEBUFFER.H"
#include "sdk/SCHED/osscremoveclient.H"
#include "sdk/libgultra/OSWRITEBACKDCACHEALL.H"
#include "sdk/libgultra/sptaskyield.h"
#include "sdk/os.h"
/* Switches a view to a new current and next scene: stamps the time of a pending next scene, starts the current scene (resetting its timer for mode 2, and stamping its start and, unless flagged 0x10, its first-start time for flag 0x20), clears its flags 0x30, runs its start and update hooks and records it, then when the next scene differs starts its music at its time and records it. */











extern u64 Audio_ReadSystemTime(void);

extern void osSpTaskLoad(s32 *mode);

extern void osSpTaskStartGo(s32 *mode);

extern void osDpSetNextBuffer(s32 music, s64 time);




void Sched_StartSelectedTasks(OSSched *view, OSScTask_s *current, OSScTask_s *next) {
    s64 now;

    if (next != 0 && (next->flags & 0x20) && !(next->state & 0x10)) {
        g_schedulerRdpTaskStartTime = Audio_ReadSystemTime();
    }
    if (current != 0) {
        if (current->list.type == 2) {
            osWritebackDCacheAll();
            g_schedulerAudioTaskStartTime = Audio_ReadSystemTime();
        } else if (current->flags & 0x20) {
            now = Audio_ReadSystemTime();
            g_schedulerGraphicsTaskStartTime = now;
            if (!(current->state & 0x10)) {
                g_schedulerGraphicsFirstStartTime = now;
                g_schedulerAccumulatedGraphicsRspDuration = 0;
            }
        }
        current->state &= ~0x30;
        osSpTaskLoad((s32 *)&current->list.type);
        osSpTaskStartGo((s32 *)&current->list.type);
        view->curRSPTask = current;
        if (current == next) {
            view->curRDPTask = next;
        }
    }
    if (next != 0 && next != current) {
        osDpSetNextBuffer((s32)next->list.output_buff, *next->list.output_buff_size);
        g_schedulerRdpBufferSetFlag = 1;
        g_schedulerRdpBufferSetState = 0;
        view->curRDPTask = next;
    }
}
