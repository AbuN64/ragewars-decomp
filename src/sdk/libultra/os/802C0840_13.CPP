#include "include_asm.h"
#include "COMMON/LONE/D_800D5268_de.H"
#include "COMMON/NODERECAT1C.H"
#include "COMMON/CTX.H"
#include "TYPES.H"
#include "COMMON/VERSION_CALLS.H"
#include "COMMON/EXTERNS_5.H"
#include "sdk/os.h"

extern ThreadNode *D_800D5270;
extern void __osEnqueueThread(ThreadNode **queue, ThreadNode *node);
extern ThreadNode *__osPopThread(ThreadNode **queue);

extern void func_802BC36C_de(ThreadNode **queue, ThreadNode *node);
void func_802BB750_de(ThreadNode *arg0) {
    ThreadNode **sentinel;
    u32 token;
    token = func_802BCF30_de();
    if (arg0->state == 1) {
        goto state_one;
    }
    if (arg0->state != 8) {
        goto state_done;
    }
    arg0->state = 2;
    __osEnqueueThread((ThreadNode **)&D_800D5268_de, arg0);
    goto state_done;
state_one:
    if (arg0->queue == 0) {
        goto insert_arg;
    }
    sentinel = (ThreadNode **)&D_800D5268_de;
    if (arg0->queue == sentinel) {
insert_arg:
        arg0->state = 2;
        __osEnqueueThread((ThreadNode **)&D_800D5268_de, arg0);
    } else {
        arg0->state = 8;
        __osEnqueueThread(arg0->queue, arg0);
        __osEnqueueThread(sentinel, __osPopThread(arg0->queue));
    }
state_done:
    if (D_800D5270 == 0) {
        func_802BC850_eu_x();
    } else if (D_800D5270->priority < (*(ThreadNode **)&D_800D5268_de)->priority) {
        D_800D5270->state = 2;
        func_802BC36C_de((ThreadNode **)&D_800D5268_de, D_800D5270);
    }
    __osRestoreInt(token);
}

#if defined(VERSION_US)
char rodata_unresolved_802BB794[12] =
    "eamTriangleM";
#endif
