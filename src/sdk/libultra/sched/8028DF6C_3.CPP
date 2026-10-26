#include "COMMON/EXTERNS_18.H"
#include "COMMON/UNUSED.H"
#include "COMMON/S1_2.H"
#include "COMMON/WORLDSORTENTRY.H"
#include "COMMON/OSVISCALE.H"
#include "COMMON/NODERECAT2A8.H"
#include "TYPES.H"
#include "sdk/libgultra.h"
#include "COMMON/EXTERNS_3.H"
#include "FRONTEND/8040B45C_22.H"
#include "sdk/AUDIO_2/802BF7F0.H"
#include "SYSTEM_2/8025E280.H"
#include "sdk/os.h"

#if !(defined(VERSION_EU) || defined(VERSION_US))
extern void func_8028EACC_de(void *arg0);

extern void func_8028F278_de(void *arg0);
extern void func_8028FC10_de(void *arg0);


extern void *func_8025CC6C_de(void);
extern void func_8025CBEC_de(void *arg0);

extern void osViSetMode(void *arg0);
extern void osViBlack(s32 arg0);









void func_8028E930_de(void *arg0) {
    OSSched *scheduler = arg0;
    s32 event;
    OSScClientWork *node;
    void *resource;

loop_1:
loop_2:
    osRecvMesg(&scheduler->interruptQueue, &event, 1);
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
            osViSetMode(resource);
            osViBlack(1);
            func_802BA700_de(2);
            for (;;) {
            }
        }
    }
    func_8028EACC_de(scheduler);
    Frontend_UpdateScreenMode();
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
            osSendMesg(node->queue, &scheduler->retraceMessage, 0);
            node = node->next;
        } while (node != 0);
    }
    goto loop_1;

event_6:
    func_8028FC10_de(scheduler);
    goto loop_1;
}
#endif
