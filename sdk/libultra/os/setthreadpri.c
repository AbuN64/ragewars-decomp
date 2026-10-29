#include "../../include/thread_queue.h"
#include "include_asm.h"
#include "COMMON/BOOT_MEMORY_AND_THREAD_BOUNDARIES.H"
#include "TYPES.H"
#include "../../include/os.h"

/* osSetThreadPri, drafted from ultralib src/os/setthreadpri.c (2.0I-L, non-debug). */



extern OSThread_s *__osRunQueue;
extern OSThread_s *__osRunningThread;
extern void __osDequeueThread(OSThread_s **queue, OSThread_s *t);
extern void __osEnqueueAndYield(OSThread_s **queue);

void osSetThreadPri(OSThread_s *t, s32 pri)
{
    register u32 saveMask;
    OSThread_s **runQueue;

    saveMask = __osDisableInt();

    if (t == 0) {
        t = __osRunningThread;
    }

    if (t->priority != pri) {
        t->priority = pri;

        if (t != __osRunningThread && t->state != 1) {
            __osDequeueThread(t->queue, t);
            __osEnqueueThread(t->queue, t);
        }

        runQueue = &__osRunQueue;
        if (__osRunningThread->priority < (*runQueue)->priority) {
            __osRunningThread->state = 2;
            __osEnqueueAndYield(runQueue);
        }
    }

    __osRestoreInt(saveMask);
}

#if defined(VERSION_US)
char s_SetthreadpriStBotTBoText[12] =
    "stBot_t\005m_Bo";
#endif
