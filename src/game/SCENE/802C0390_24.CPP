#include "include_asm.h"
#include "COMMON/EXTERNS_18.H"
#include "TYPES.H"
#include "sdk/os.h"

#if defined(VERSION_DE)
INCLUDE_ASM("span_1000", func_802BB5B0_de);
#endif

#if defined(VERSION_DE)
INCLUDE_ASM("span_1000", func_802BB5E0_de);
#endif

/* osSetThreadPri, drafted from ultralib src/os/setthreadpri.c (2.0I-L, non-debug). */



extern OSThread_s *D_800D5268_de;
extern OSThread_s *D_800D5270;
extern void func_802BB870_de(OSThread_s **queue, OSThread_s *t);
extern void __osEnqueueThread(OSThread_s **queue, OSThread_s *t);
extern void func_802BC36C_de(OSThread_s **queue);

void func_802BB5F0_de(OSThread_s *t, s32 pri)
{
    register u32 saveMask;
    OSThread_s **runQueue;

    saveMask = __osDisableInt();

    if (t == 0) {
        t = D_800D5270;
    }

    if (t->priority != pri) {
        t->priority = pri;

        if (t != D_800D5270 && t->state != 1) {
            func_802BB870_de(t->queue, t);
            __osEnqueueThread(t->queue, t);
        }

        runQueue = &D_800D5268_de;
        if (D_800D5270->priority < (*runQueue)->priority) {
            D_800D5270->state = 2;
            func_802BC36C_de(runQueue);
        }
    }

    __osRestoreInt(saveMask);
}

#if defined(VERSION_US)
char rodata_unresolved_802BB5E4[12] =
    "stBot_t\005m_Bo";
#endif
