#include "shared/world.h"

extern s32 func_802654E8_de(void *arg0, s32 arg1, s32 arg2);
extern s32 func_8028FE3C_de(void *arg0, s32 arg1, s32 arg2, s32 *arg3);
extern void *func_8025193C_de(s32, s32, s32, s32, s32, s32, void *, void *, s32);

extern s32 D_00285160;
extern s32 D_800C51D8;

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
