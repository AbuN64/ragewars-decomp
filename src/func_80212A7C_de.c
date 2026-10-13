#include "shared/navigation_graph.h"
#include "span_1000/code_80208000.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802106E0.h"
#include "types.h"

extern char D_8013B364;
extern f32 D_800C20CC_de;

extern void func_8020D014_de(void *arg0);
extern void func_8020D1FC_de(s32);
extern void *func_8020C994_de(void *arg0, s32 arg1);
extern f32 func_802726BC_de(f32 *arg0, f32 *arg1);
extern void func_8020D220_de(void *, s32);
extern void func_8020D0CC_de(void *arg0, s32 arg1);
extern void func_8020D114_de(void *arg0, void *arg1, s32 arg2);
extern void func_80211020_de(void *arg0);
extern void func_80208410_de(void *);
extern void func_80208AAC_de(void *arg0);
extern void func_8020FA10_de(void *arg0);














static inline u32 navigation_attributes(NavigationPoint *point) {
    u32 value;
    __builtin_memcpy(&value, &point->flags, sizeof(value));
    return value;
}

void func_80212A7C_de(void *arg0)
{
    AiController *state;
    NavigationGraph *table;
    NavigationPoint *entry;
    f32 threshold;
    s32 index;
    s32 value;
    u32 flags;

    state = ((Player *)((Shared_Actor *)arg0)->entity)->controller;
    table = (NavigationGraph *)&D_8013B364;
    if (state->mode == -1) {
        func_8020D014_de(table);
        func_8020D1FC_de((s32)table);
        threshold = D_800C20CC_de;
        index = 0;
        if (table->pointCount > 0) {
            do {
                entry = func_8020C994_de(table, index);
                if (func_802726BC_de(&state->player->pos.x, entry) < threshold &&
                    !(navigation_attributes(entry) & 0x04300000)) {
                    func_8020D220_de(table, index);
                }
                index++;
            } while (index < table->pointCount);
        }
        func_8020D0CC_de(table, state->current);
        func_8020D114_de(table, &state->queue, 4);
        value = table->result;
        state->mode = value;
        state->routeGoal = value;
    }
    func_80211020_de(state);
    func_80208410_de(state);
    func_80208AAC_de(state);
    flags = (state->player->movementFlags & 0x3000) != 0;
    if (state->current == state->mode &&
        !flags) {
        func_8020FA10_de(state);
    }
}
