#include "shared/world.h"
#include "shared/level_actor.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_8028567C.h"
#include "types.h"

extern char *func_8028FDB4_de(s32 *, s32);
extern void func_8028FDF8_de(s32 arg0, s32 arg1);






s32 func_80285F58_de(void *arg0, void *arg1) {
    Shared_World *world = arg0;
    Actor_func_8024A7A0_de *actor = arg1;
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
