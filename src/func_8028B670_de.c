#include "shared/world.h"
#include "span_1000/code_8028DF6C.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8028B64C.h"
#include "types.h"

extern char *func_8028FDB4_de(s32 *, s32);
extern void func_8028FDF8_de(s32 arg0, s32 arg1);








void func_8028B670_de(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *entry;
    struct Def *cond;
    void *field80;
    void *temp_v0;
    u8 *base1;
    u8 *base2;
    s32 mask;
    s32 idx;
    s32 idx2;

    if (((Shared_World *)arg0)->mode == 2) {
        return;
    }
    if (((Shared_World *)arg0)->level == arg1) {
        entry = (char *)((Scene_func_8028E284_de *)arg0)->actors + (s32) arg2 * 0x2E8;
        cond = ((Actor_func_8028E284_de *)entry)->def;
        if ((u32) (cond->type - 9) < 2) {
            if (cond->flags & 0x200) {
                return;
            }
        }
    }
    field80 = ((Shared_World *)arg0)->bitSections;
    temp_v0 = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(field80, 0), (s32) arg1), 0);
    func_8028FDB4_de(temp_v0, 0);
    func_8028FDF8_de((s32) temp_v0, 1);
    base1 = (u8 *) func_8028FDB4_de(temp_v0, 1);
    base2 = base1;
    mask = 1 << (arg2 & 7);
    if (arg3 != 0) {
        idx = arg2;
        if ((s32) arg2 < 0) {
            idx = arg2 + 7;
        }
        base1[idx >> 3] |= mask;
        return;
    }
    idx2 = arg2;
    if (idx2 < 0) {
        idx2 += 7;
    }
    base2[idx2 >> 3] &= ~mask;
}
