#include "include_asm.h"
#include "COMMON/LONE/D_80106248.H"
#include "COMMON/EXTERNS_18.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PAKQUEUESTATE.H"
#include "COMMON/WORLDSORTENTRY.H"
#include "TYPES.H"
#include "sdk/SCHED/8028DF6C_7.H"
#include "sdk/os.h"

#if defined(VERSION_EU)
#include "COMMON/OSVISCALE.H"
#include "sdk/os.h"
extern s32 D_800CD708, D_800CD70C, D_800E28D8;
extern f32 D_800C5350_de;
extern OSViMode D_800D47B0, D_800D4530;
extern void osViSetYScale(f32);
extern void osViSetMode(OSViMode *);
extern void osViBlack(s32);
extern void func_802BA700_de(s32);
extern void func_8028EACC_de(OSSched *);
extern void Frontend_UpdateScreenMode(void);
extern void func_8028EDA0_de(void *);
extern void func_8028F278_de(OSSched *);
extern void func_8025E318_de(void);
extern void func_8025E214_de(s32);
extern void *func_8025CC6C_de(void);
extern void func_8025CBEC_de(void *);
extern void func_8028FC10_de(OSSched *);

void func_8028EA40_eu(OSSched *sc) {
    void *msg;
    OSScClientWork *client;
    OSViMode *mode;
    for (;;) {
        osRecvMesg(&sc->interruptQueue, &msg, 1);
        switch ((s32)msg) {
        case 0x29A:
            if (D_800CD708 && --D_800CD70C <= 0) {
                osViSetYScale(D_800C5350_de);
                mode = &D_800D47B0;
                if (D_800E28D8 == 0) mode = &D_800D4530;
                osViSetMode(mode);
                osViBlack(1);
                func_802BA700_de(2);
                for (;;) {}
            }
            func_8028EACC_de(sc);
            Frontend_UpdateScreenMode();
            break;
        case 0x29B: func_8028EDA0_de(sc); break;
        case 0x29C: func_8028F278_de(sc); break;
        case 0x29D:
            func_8025E318_de();
            func_8025E214_de(-1);
            func_8025CBEC_de(func_8025CC6C_de());
            client = sc->clientList;
            D_800CD708 = 1;
            D_800CD70C = 20;
            while (client) {
                osSendMesg(client->queue, &sc->retraceMessage, 0);
                client = client->next;
            }
            break;
        case 6: func_8028FC10_de(sc); break;
        }
    }
}
#endif

extern void func_802BB5F0_de(void *, s32);








extern s32 D_800CD700, D_800CD704, D_800CD8AC_de, D_800DE850;
extern s32 D_8011B9F4, D_80142920, D_80142C30, D_80142C38, D_80146CC8, D_80146CD0;
#include "COMMON/DISPLAY.H"




/** Handle one scheduler retrace, recover a lost yielded-task completion, and notify clients. */
void func_8028EACC_de(OSSched *sc) {
    OSScTask_s *event = 0;
    s32 value1 = 0;
    s32 value2 = 0;
    s32 flags;
    OSScTask_s *pending;
    OSScClientWork *work;
    Frame *schedule;

    if (D_800CD704 != 0) {
        D_800CD704--;
        if (D_800CD704 == 0) func_802BB5F0_de(&D_80106248, D_800CD8AC_de);
    }
    sc->frameCount++;
    while (osRecvMesg(&sc->commandQueue, &event, 0) != -1) __scAppendList(sc, event);
    D_80142920++;
    if (D_80146CC8 != 0) {
        D_80142920 = 0;
        D_80146CC8 = 0;
        D_80142C38 = D_80142C30;
        D_80142C30 = 0;
    }
    if (D_80146CD0 != 0) {
        schedule = D_801428B0[D_8011B9F4];
        if ((u32)(D_80142920 + 1) >= schedule->ticks) {
            D_80142C30 = (s32)schedule->colorImage;
            osViSwapBuffer((s32)schedule->colorImage);
            D_80146CD0--;
            D_80146CC8++;
            D_8011B9F4++;
            if ((u32)D_8011B9F4 >= (u32)D_800DE850) D_8011B9F4 = 0;
        }
    }
    if (sc->curRSPTask == 0 && sc->curRDPTask == 0) {
        pending = sc->gfxListHead;
        if (pending != 0 && pending->list.type == 1 && pending->state == 0x32) {
            pending->state = 2;
            sc->curRSPTask = sc->gfxListHead;
            sc->gfxListHead = sc->gfxListHead->next;
            if (sc->gfxListHead == 0) sc->gfxListTail = 0;
            func_8028EDA0_de(sc);
        }
    }
    D_800CD700++;
    if (D_800CD700 == 0x4B0) *(char *)0 = 0;
    if (sc->doAudio != 0 && sc->curRSPTask != 0) __scYield(sc);
    else {
        flags = (sc->curRSPTask == 0) * 2 | (sc->curRDPTask == 0);
        if (((s32 (*)(void *, s32 *, s32 *, s32))func_8028F544_de)(sc, &value1, &value2, flags) != flags) ((void (*)(void *, s32, s32))func_8028FA60_de)(sc, value1, value2);
    }
    work = sc->clientList;
    while (work != 0) {
        if (work->queue->validCount < 2) osSendMesg(work->queue, sc, 0);
        work = work->next;
    }
    Render_PollControllerPaks();
}
