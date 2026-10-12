/* Mechanically ported from github/legacy:src/func_8028F258.c by address. */
#include "types.h"
#include "common/unused.h"
#include "span_1000/code_8028DF6C.h"
#include "span_1000/code_80290980.h"
#include "span_1000/code_80291054.h"
#include "span_C76B0/data.h"

extern FrameSchedule D_8011FAC0[];

extern u32 D_80142920;

extern s32 D_80142C30;

extern s32 D_80146CC8;

extern s32 D_80146CD0;

extern u32 D_80146CCC;

void func_8028F278_de(OSSched *sc)
{
    s32 value1 = 0;
    s32 value2 = 0;
    OSScTask_s *task = sc->curRDPTask;
    void *framebuffer;
    FrameSchedule *schedule;
    FrameSchedule *schedules;
    s32 flags;
    task->state &= ~1;
    if (task->list.type == 1) {
        if ((task->flags & 0x20) != 0) {
            D_800CD754 = (f32)(((func_802BADC0_de() - D_8011B1E8) << 6) / 3) * D_800C5364_de;
        }
        sc->curRDPTask = 0;
        if ((task->flags & 0x20) != 0) {
            schedules = D_8011FAC0;
            framebuffer = task->framebuffer;
            if (framebuffer == (void *)schedules[0].task) {
                schedule = &schedules[0];
            } else if (framebuffer == (void *)schedules[1].task) {
                schedule = &schedules[1];
            } else if (framebuffer == (void *)schedules[2].task) {
                schedule = &schedules[2];
            } else {
                schedule = &schedules[0];
            }
            D_80142C34 = D_801428AC;
            D_801428AC = D_8011B9F8;
            D_8011B9F8 = D_80142CA4;
            D_80142CA4 = D_80142920 + 1;
            if (D_80142CA4 >= schedule->duration && D_80146CD0 == 0 && D_80146CC8 == 0) {
                D_80142C30 = schedule->task;
                func_802BA8C0_de(schedule->task);
                D_80146CC8++;
            } else {
                D_80146CD0++;
                D_801428B0[D_80146CCC] = schedule;
                D_80146CCC++;
                if (D_80146CCC >= D_800DE850) {
                    D_80146CCC = 0;
                }
            }
            func_80290A0C_de(schedule);
        }
    }
    func_8028FA0C_de(sc, task);
    flags = (sc->curRSPTask == 0) * 2 | (sc->curRDPTask == 0);
    if (func_8028F544_de(sc, &value1, &value2, flags) != flags) {
        func_8028FA60_de(sc, value1, value2);
    }
}
