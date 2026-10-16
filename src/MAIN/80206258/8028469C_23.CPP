#include "span_1000/code_8028469C.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8fd754e1e915.h"
#include "shared/level_actor.h"
#include "shared/world.h"
#include "span_1000/code_8028567C.h"
#include "span_1000/code_8028DF6C.h"
#include "TYPES.H"

extern char *func_8028FDB4_de(s32 *, s32);

extern void func_8028FDF8_de(s32 arg0, s32 arg1);

void func_80285DB0_de(Shared_World *arg0, void *arg1, s32 arg2) {
    Actor_func_8028E284_de *entry;
    struct Def *cond;
    void *field80;
    void *temp_v0;
    u8 *base1;
    u8 *base2;
    s32 field1B40C;
    s32 mask;
    s32 index;
    s32 idx;
    s32 idx2;
    s32 lastOffset;
    u32 first;

    if (!(((LevelActor *)arg1)->flags & 0x80000)) {
        first = (u32)arg0->actors;
        index = -1;
        if ((u32) arg1 >= first) {
            lastOffset = arg0->actorCount * 0x2E8;
            lastOffset -= 0x2E8;
            if (first + lastOffset >= (u32) arg1) {
                index = ((u32) arg1 - first) / 0x2E8;
            }
        }
    } else {
        index = -1;
    }
    if (index == -1) {
        return;
    }
    field1B40C = arg0->level;
    if (arg0->mode == 2) {
        return;
    }
    entry = &arg0->actors[index];
    cond = entry->def;
    if ((u32) (cond->type - 9) < 2) {
        if (cond->flags & 0x200) {
            return;
        }
    }
    field80 = arg0->bitSections;
    temp_v0 = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(field80, 0), field1B40C), 0);
    func_8028FDB4_de(temp_v0, 0);
    func_8028FDF8_de((s32) temp_v0, 1);
    base1 = (u8 *) func_8028FDB4_de(temp_v0, 1);
    base2 = base1;
    mask = 1 << (index & 7);
    if (arg2 != 0) {
        idx = index;
        if (index < 0) {
            idx = index + 7;
        }
        base1[idx >> 3] |= mask;
        return;
    }
    idx2 = index;
    if (idx2 < 0) {
        idx2 += 7;
    }
    base2[idx2 >> 3] &= ~mask;
}

s32 func_80285F58_de(void *arg0, void *arg1) {
    Shared_World *world = arg0;
    LevelActor *actor = arg1;
    void *field80;
    void *temp_v0;
    u8 *base;
    s32 field1B40C;
    s32 mask;
    s32 index;
    s32 i;
    s32 lastOffset;
    u32 first;

    if (!(actor->flags & 0x80000)) {
        first = ((u32)world->actors);
        index = -1;
        if ((u32) arg1 >= first) {
            lastOffset = world->actorCount * 0x2E8;
            lastOffset -= 0x2E8;
            if (first + lastOffset >= (u32) arg1) {
                index = ((u32) arg1 - first) / 0x2E8;
            }
        }
    } else {
        index = -1;
    }
    if (index == -1) {
        return 0;
    }
    field80 = world->bitSections;
    field1B40C = world->level;
    temp_v0 = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(field80, 0), field1B40C), 0);
    func_8028FDB4_de(temp_v0, 0);
    func_8028FDF8_de((s32) temp_v0, 1);
    base = (u8 *) func_8028FDB4_de(temp_v0, 1);
    mask = 1 << (index & 7);
    i = index;
    if (i < 0) {
        i += 7;
    }
    return (base[i >> 3] & mask) != 0;
}
