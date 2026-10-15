#include "span_1000/code_802BB15C.h"
#include "span_1000/code_8025E280.h"
#include "span_1000/code_8028DF6C.h"
#include "span_1000/code_802BA23C.h"
#include "span_16E000/code_8040B45C.h"
#include "types.h"



extern void func_802BB420_de(void *arg0, void *arg1, s32 arg2);
extern void func_8028EACC_de(void *arg0);

extern void func_8028F278_de(void *arg0);
extern void func_8028FC10_de(void *arg0);


extern void *func_8025CC6C_de(void);
extern void func_8025CBEC_de(void *arg0);

extern void func_802BA6B0_de(void *arg0);
extern void osViBlack(s32 arg0);




extern s32 D_800CD70C;

extern s32 D_800E28D8;
extern char D_800D47B0;
extern char D_800D4530;




void func_8028E930_de(void *arg0) {
    OSSched *scheduler = arg0;
    s32 event;
    OSScClientWork *node;
    void *resource;

loop_1:
loop_2:
    func_802BB2A0_de(&scheduler->interruptQueue, &event, 1);
    if (event == 0x29B) {
        goto event_29b;
    }
    if (event < 0x29C) {
        if (event == 6) {
            goto event_6;
        }
        if (event == 0x29A) {
            goto event_29a;
        }
        goto loop_2;
    }
    if (event == 0x29C) {
        goto event_29c;
    }
    if (event == 0x29D) {
        goto event_29d;
    }
    goto loop_2;

event_29a:
    if (D_800CD708 != 0) {
        D_800CD70C--;
        if (D_800CD70C <= 0) {
            osViSetYScale(D_800C5350_de);
            resource = &D_800D47B0;
            if (D_800E28D8 == 0) {
                resource = &D_800D4530;
            }
            func_802BA6B0_de(resource);
            osViBlack(1);
            func_802BA700_de(2);
            for (;;) {
            }
        }
    }
    func_8028EACC_de(scheduler);
    func_8040C318_de();
    goto loop_1;

event_29b:
    func_8028EDA0_de(scheduler);
    goto loop_1;

event_29c:
    func_8028F278_de(scheduler);
    goto loop_1;

event_29d:
    func_8025E318_de();
    func_8025E214_de(-1);
    func_8025CBEC_de(func_8025CC6C_de());
    node = scheduler->clientList;
    D_800CD708 = 1;
    D_800CD70C = 0x14;
    if (node != 0) {
        do {
            func_802BB420_de(node->queue, &scheduler->retraceMessage, 0);
            node = node->next;
        } while (node != 0);
    }
    goto loop_1;

event_6:
    func_8028FC10_de(scheduler);
    goto loop_1;
}
