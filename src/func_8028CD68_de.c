#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8028CCB8.h"
#include "types.h"
#include "shared/world.h"
#include "span_1000/code_8028DF6C.h"

extern void func_80285DB0_de(void *, void *, s32);






void func_8028CD68_de(void *arg0) {
    Shared_World *object;
    s32 count;
    s32 i;
    s32 offset;
    struct Actor_func_8028E284_de *entry;
    s32 field;
    s32 three;

    object = arg0;
    count = object->actorCount;
    i = 0;
    if (count > 0) {
        three = 3;
        offset = 0;
        do {
            object = arg0;
            entry = (void *)((char *)object->actors + offset);
            field = entry->def->type;
            if (field != three) {
                i += 1;
            } else {
                func_80285DB0_de(arg0, entry, 1);
                i += 1;
            }
            offset += 0x2E8;
        } while (i < count);
    }
}
