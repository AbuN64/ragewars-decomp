#include "include_asm.h"
#include "COMMON/WORLDRECAT1B6A4.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "ENGINE/SCENE_7.H"
#include "COMMON/WORLD.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "SCENE/802508E0_4.H"
#include "RENDER_4/8028FD2C_6.H"


extern s32 func_802654E8_de(void *arg0, s32 arg1, s32 arg2);

extern s32 func_8028FE3C_de(void *arg0, s32 arg1, s32 arg2, s32 *arg3);


extern s32 D_00285160;


s32 func_8028BDAC_de(void *world, s32 arg1) {
    void *temp_v0;
    u8 *result;

    temp_v0 = func_8028FDB4_de((((struct Field_void_80 *) ((s8 *) world))->value), 1);
    func_8028FDB4_de(temp_v0, 0);
    result = (u8 *)((char *)func_8028FDB4_de(temp_v0, 1)) + arg1;
    return *result == 0;
}

void *func_8028BE08_de(Shared_World *world, s32 arg1, s32 mode, s32 direct) {
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
    return func_8025193C_de(0, result, result, sp28, mode, 0, &D_00285160, &D_800C51D8, direct);
}

/* Starts a sound effect from the world's sound table: looks the id up (0 or unknown returns 0),
 * picks the effect's behaviour table (ids 5 and 7 have their own, everything else the default), sets
 * the loop/priority bits 0x4 or 0x18 from the id's range, and queues it through func_8025193C_de. */
extern s32 D_00285160, D_0028E4A4, D_0028E5D0;
extern s32 D_800C51E8;
s32 Render_StartWorldEffect(Shared_World *world, s32 id, s32 flags, s32 extra) {
    s32 index;
    s32 *behaviour;
    s32 handle;
    s32 out;

    if (id == 0) {
        return 0;
    }
    index = func_802654E8_de(world->resourceKindTable->entries, world->resourceKindTable->count, id);
    if (index == -1) {
        return 0;
    }
    switch (id) {
    case 5:
        behaviour = &D_0028E4A4;
        break;
    case 7:
        behaviour = &D_0028E5D0;
        break;
    default:
        behaviour = &D_00285160;
        break;
    }
    switch (id) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
        flags |= 0x18;
        break;
    default:
        flags |= 4;
        break;
    }
    handle = func_8028FE3C_de(world->resourceKindDirectory, world->resourceKindBank, index, &out);
    return func_8025193C_de(0, handle, handle, out, flags, world, behaviour, &D_800C51E8, extra);
}
