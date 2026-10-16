#include "TYPES.H"
#include "gfx.h"
#include "span_1000/code_80291054.h"
#include "common/unused.h"
#include "shared/func_80286080_de_closed.h"
#include "shared/func_80404D84_de_closed.h"
#include "shared/func_80425674_de_layout.h"
#include "span_1000/code_80243A80.h"
#include "span_1000/code_8025D948.h"
#include "span_1000/code_802646F4.h"
#include "span_1000/code_8028DF6C.h"
#include "span_1000/code_80290980.h"
#include "span_16E000/code_8044E2B8.h"


void func_80291208_de(RenderState *state) {
    u32 i, count, previous, next;
    RenderCounters *counters;
    RenderView *view;
    osCreateMesgQueue(D_801428C0, (s32)D_80142CB8, 0x1000);
    func_802A001C_de(D_800EFC80_de, 7, 0x2000);
    func_8028F754_de((void *)&D_80142928, (s32)(D_800EFC80_de + 0x2000), D_800CD8C8_de, 0, 1);
    osScAddClient(&D_80142928, D_80146CC0, (s32)D_801428C0);
    state->handle = -1;
    func_80293590_de(state);
    D_80110634 = 0;
    func_802B6B80_de((void *)&D_80142C60);
    if (D_801470B0) {
        func_80264B44_de();
        func_80445074_eu(&D_801462C8);
    }
    i = 0;
    func_80244D70_de();
    func_8044DCC0_de();
    func_8044DC60_de(state->settings);
    count = D_800DE850;
    state->field26DD0 = 0;
    state->enabled = 1;
    state->field26DCC = 0;
    state->field26DD4 = 0;
    counters = &D_801468A0;
    counters->first = 0;
    counters->second = 0;
    view = state->ring.views;
    if (count) do {
        previous = count - 1;
        previous = (i + previous) % count;
        next = count + 1;
        next = (i + next) % count;
        view->kind = 2;
        view->buffer = D_8014D468_de[i];

        view->previous = &state->ring.views[previous];
        view->next = &state->ring.views[next];
        func_80290A00_de(view++);
        ++i;
        count = D_800DE850;

    } while (i < count);
    func_80293054_de(&state->ring.display);
    func_8025DE30_de();
}
