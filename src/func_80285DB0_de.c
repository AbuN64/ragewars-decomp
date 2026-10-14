#include "shared/world.h"
#include "shared/level_actor.h"
#include "span_1000/code_8028DF6C.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8028567C.h"
#include "types.h"

extern char *func_8028FDB4_de(s32 *, s32);
extern void func_8028FDF8_de(s32 arg0, s32 arg1);











void func_80285DB0_de(void *arg0, void *arg1, s32 arg2) {
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
        first = (u32)((Shared_World *)arg0)->actors;
        index = -1;
        if ((u32) arg1 >= first) {
            lastOffset = ((Shared_World *)arg0)->actorCount * 0x2E8;
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
    field1B40C = ((Shared_World *)arg0)->level;
    if (((Shared_World *)arg0)->mode == 2) {
        return;
    }
    entry = &((Shared_World *)arg0)->actors[index];
    cond = entry->def;
    if ((u32) (cond->type - 9) < 2) {
        if (cond->flags & 0x200) {
            return;
        }
    }
    field80 = ((Shared_World *)arg0)->bitSections;
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
