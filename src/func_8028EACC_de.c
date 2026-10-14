#include "span_1000/code_802BB15C.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802636D0.h"
#include "span_1000/code_8028DF6C.h"
#include "types.h"











extern void func_802BB5F0_de(void *, s32);






extern s32 func_802BB420_de(Queue_func_802517B4_de *, s32, s32);


extern s32 D_800CD700, D_800CD704, D_800CD8AC_de, D_800DE850, D_80106248;
extern s32 D_8011B9F4, D_80142920, D_80142C30, D_80142C38, D_80146CC8, D_80146CD0;
extern FrameSchedule *D_801428B0[];




/** Handle one scheduler retrace, recover a lost yielded-task completion, and notify clients. */
void func_8028EACC_de(OSSched *sc) {
    OSScTask_s *event = 0;
    s32 value1 = 0;
    s32 value2 = 0;
    s32 flags;
    OSScTask_s *pending;
    OSScClientWork *work;
    FrameSchedule *schedule;

    if (D_800CD704 != 0) {
        D_800CD704--;
        if (D_800CD704 == 0) func_802BB5F0_de(&D_80106248, D_800CD8AC_de);
    }
    sc->frameCount++;
    while (func_802BB2A0_de(&sc->commandQueue, &event, 0) != -1) func_8028F954_de(sc, event);
    D_80142920++;
    if (D_80146CC8 != 0) {
        D_80142920 = 0;
        D_80146CC8 = 0;
        D_80142C38 = D_80142C30;
        D_80142C30 = 0;
    }
    if (D_80146CD0 != 0) {
        schedule = D_801428B0[D_8011B9F4];
        if ((u32)(D_80142920 + 1) >= schedule->duration) {
            D_80142C30 = schedule->task;
            func_802BA8C0_de(schedule->task);
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
    if (sc->doAudio != 0 && sc->curRSPTask != 0) func_8028FBD8_de(sc);
    else {
        flags = (sc->curRSPTask == 0) * 2 | (sc->curRDPTask == 0);
        if (((s32 (*)(void *, s32 *, s32 *, s32))func_8028F544_de)(sc, &value1, &value2, flags) != flags) ((void (*)(void *, s32, s32))func_8028FA60_de)(sc, value1, value2);
    }
    work = sc->clientList;
    while (work != 0) {
        if (work->queue->count < 2) func_802BB420_de(work->queue, (s32)sc, 0);
        work = work->next;
    }
    func_80263AF4_de();
}
