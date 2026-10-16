#include "span_1000/code_8028B64C.h"
#include "common/types_1dc8418c21db.h"
#include "shared/world.h"
#include "TYPES.H"
#include "common/unused.h"

extern char *func_8028FDB4_de(s32 *, s32);

extern s32 func_802654E8_de(void *arg0, s32 arg1, s32 arg2);

extern s32 func_8028FE3C_de(void *arg0, s32 arg1, s32 arg2, s32 *arg3);

extern void *func_8025193C_de(s32, s32, s32, s32, s32, s32, void *, void *, s32);

extern s32 D_00285160;


s32 func_8028BDAC_de(void *arg0, s32 arg1) {
    void *temp_v0;
    u8 *result;

    temp_v0 = func_8028FDB4_de((((struct Field_void_80 *) ((s8 *) arg0))->value), 1);
    func_8028FDB4_de(temp_v0, 0);
    result = (u8 *)func_8028FDB4_de(temp_v0, 1) + arg1;
    return *result == 0;
}

void *func_8028BE08_de(Shared_World *world, s32 arg1, s32 arg2, s32 arg3) {
    StridedTable *table;
    s32 idx;
    s32 sp28;
    s32 result;

    table = world->lookupTable;
    idx = func_802654E8_de(table->data, table->count, arg1);
    if (idx == -1) {
        return 0;
    }
    result = func_8028FE3C_de(world->lookupDirectory, world->lookupBank, idx, &sp28);
    return func_8025193C_de(0, result, result, sp28, arg2, 0, &D_00285160, &D_800C51D8, arg3);
}
