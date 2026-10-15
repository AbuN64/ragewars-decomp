#include "span_1000/code_802BB15C.h"
#include "types.h"
/* osSetThreadPri, drafted from ultralib src/os/setthreadpri.c (2.0I-L, non-debug). */



extern OSThread_s *D_800D5268_de;
extern OSThread_s *D_800D5270;
extern u32 func_802BCF30_de(void);
extern void __osRestoreInt(u32 mask);
extern void func_802BB870_de(OSThread_s **queue, OSThread_s *t);
extern void func_802BC508_de(OSThread_s **queue, OSThread_s *t);
extern void func_802BC36C_de(OSThread_s **queue);

void func_802BB5F0_de(OSThread_s *t, s32 pri)
{
    register u32 saveMask;
    OSThread_s **runQueue;

    saveMask = func_802BCF30_de();

    if (t == 0) {
        t = D_800D5270;
    }

    if (t->priority != pri) {
        t->priority = pri;

        if (t != D_800D5270 && t->state != 1) {
            func_802BB870_de(t->queue, t);
            func_802BC508_de(t->queue, t);
        }

        runQueue = &D_800D5268_de;
        if (D_800D5270->priority < (*runQueue)->priority) {
            D_800D5270->state = 2;
            func_802BC36C_de(runQueue);
        }
    }

    __osRestoreInt(saveMask);
}
