#include "shared/world.h"
#include "shared/level_actor.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_8028B64C.h"
#include "types.h"

extern s32 func_80265550_de(u32 *, s32, u32, s32 *, s32 *);






void func_8028C26C_de(char *arg0, void *arg1, s32 *arg2, s32 *arg3) {
    s32 sp18;
    s32 sp1C;
    s32 index;
    u32 first;
    s32 lastOffset;
    s32 temp_v0;
    s32 field_c8;
    s32 field_c0;

    if (!(((Actor_func_8024A7A0_de *)arg1)->flags & 0x80000)) {
        first = (u32)((Shared_World *)arg0)->actors;
        index = -1;
        if ((u32)arg1 >= first) {
            lastOffset = ((Shared_World *)arg0)->actorCount * 0x2E8;
            lastOffset -= 0x2E8;
            if (first + lastOffset >= (u32)arg1) {
                index = ((u32)arg1 - first) / 0x2E8;
            }
        }
    } else {
        index = -1;
    }
    if (index == -1) {
        *arg3 = 0;
        return;
    }
    temp_v0 = func_80265550_de(field_c8, field_c0, index,
        (field_c8 = (s32)((Shared_World *)arg0)->recordIndex,
         field_c0 = ((Shared_World *)arg0)->recordCount, &sp18), &sp1C);
    if (temp_v0 != 0) {
        *arg2 = (s32)((Shared_World *)arg0)->recordArray + (sp18 * 0x14);
        *arg3 = (sp1C - sp18) + 1;
    } else {
        *arg2 = 0;
        *arg3 = 0;
    }
}
