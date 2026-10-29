#include "../../sdk/include/thread_queue.h"
#include "include_asm.h"
#include "COMMON/BOOT_MEMORY_AND_THREAD_BOUNDARIES.H"
#include "TYPES.H"
#include "../../sdk/include/os.h"

/* osSetThreadPri, drafted from ultralib src/os/setthreadpri.c (2.0I-L, non-debug). */



extern OSThread_s *g_osRunnableThreadQueue;
extern OSThread_s *g_osRunningThread;
extern void Audio_DequeueThread(OSThread_s **queue, OSThread_s *t);
extern void __osEnqueueAndYield(OSThread_s **queue);

void Scene_SetThreadPriority(OSThread_s *t, s32 pri)
{
    register u32 saveMask;
    OSThread_s **runQueue;

    saveMask = __osDisableInt();

    if (t == 0) {
        t = g_osRunningThread;
    }

    if (t->priority != pri) {
        t->priority = pri;

        if (t != g_osRunningThread && t->state != 1) {
            Audio_DequeueThread(t->queue, t);
            __osEnqueueThread(t->queue, t);
        }

        runQueue = &g_osRunnableThreadQueue;
        if (g_osRunningThread->priority < (*runQueue)->priority) {
            g_osRunningThread->state = 2;
            __osEnqueueAndYield(runQueue);
        }
    }

    __osRestoreInt(saveMask);
}

#if defined(VERSION_US)
char s_SetthreadpriStBotTBoText[12] =
    "stBot_t\005m_Bo";
#endif
