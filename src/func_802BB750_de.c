#include "span_1000/code_802BB67C.h"
#include "span_1000/code_802BBC68.h"
#include "types.h"
#include "version_calls.h"
extern s32 D_800D5268_de;
extern ThreadNode *D_800D5270;
extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32 token);
extern void func_802BC508_de(ThreadNode **queue, ThreadNode *node);
extern ThreadNode *func_802BC558_de(ThreadNode **queue);

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
    func_802BC508_de((ThreadNode **)&D_800D5268_de, arg0);
    goto state_done;
state_one:
    if (arg0->queue == 0) {
        goto insert_arg;
    }
    sentinel = (ThreadNode **)&D_800D5268_de;
    if (arg0->queue == sentinel) {
insert_arg:
        arg0->state = 2;
        func_802BC508_de((ThreadNode **)&D_800D5268_de, arg0);
    } else {
        arg0->state = 8;
        func_802BC508_de(arg0->queue, arg0);
        func_802BC508_de(sentinel, func_802BC558_de(arg0->queue));
    }
state_done:
    if (D_800D5270 == 0) {
        func_802BC850_eu_x();
    } else if (D_800D5270->priority < (*(ThreadNode **)&D_800D5268_de)->priority) {
        D_800D5270->state = 2;
        func_802BC36C_de((ThreadNode **)&D_800D5268_de, D_800D5270);
    }
    func_802BCF50_de(token);
}
