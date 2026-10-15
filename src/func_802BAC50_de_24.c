#include "span_1000/code_802BAC58.h"
#include "types.h"
/* osCreateThread, drafted from ultralib src/os/createthread.c (2.0I-J, no thread profile). */





extern OSThread_s *D_800D526C;
extern void D_002BC76C(void);
extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32 mask);

void func_802BAC90_de(OSThread_s *t, s32 id, void (*entry)(void *), void *arg, void *sp, s32 p)
{
    register u32 saveMask;
    u32 mask;
    OSThread_s **active;

    t->id = id;
    t->priority = p;
    t->next = 0;
    t->queue = 0;
    t->context.pc = (u32)entry;
    t->context.a0 = (s64)(s32)arg;
    t->context.sp = (s64)(s32)sp - 16;
    t->context.ra = (s64)(s32)D_002BC76C;
    mask = 0x3FFF01;
    t->context.sr = (mask & 0xFF01) | 0x04000002;
    t->context.rcp = (mask & 0x3F0000) >> 16;
    t->context.fpcsr = 0x01000800;
    t->fp = 0;
    t->state = 1;
    t->flags = 0;

    saveMask = func_802BCF30_de();
    active = &D_800D526C;
    t->tlnext = *active;
    *active = t;
    func_802BCF50_de(saveMask);
}
