#include "shared/level_actor.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8028CCB8.h"
#include "types.h"






s32 func_8028D74C_de(void *arg0, void *arg1) {
    Container *scene = arg0;
    Actor_func_8024A7A0_de *actor = arg1;
    void *base;

    if (actor->flags & 0x80000) {
        return -1;
    }
    base = scene->unk138;
    if (arg1 >= base &&
        (char *)arg1 <= (char *)base + ((u32)scene->unk140 * 0x2E8 - 0x2E8)) {
        return ((u32)arg1 - (u32)base) / 0x2E8;
    }
    return -1;
}
