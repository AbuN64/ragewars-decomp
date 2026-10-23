#include "COMMON/WORLDRECAT1B6A4.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "ENGINE/SCENE_7.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/WORLD.H"
#include "COMMON/OBJECTLINKS150C.H"
#include "COMMON/WORLDSORTENTRY.H"
#include "COMMON/ENTRYRECAT8V4.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "TYPES.H"
#include "RENDER_4/8028FD2C_6.H"

extern void func_8028FDF8_de(s32 arg0, s32 arg1);

void func_8028B670_de(void *arg0, s32 index, s32 arg2, s32 arg3) {
    void *entry;
    struct Def *cond;
    void *field80;
    void *table;
    u8 *base1;
    u8 *base2;
    s32 mask;
    s32 idx;
    s32 idx2;

    if (((Shared_World *)arg0)->mode == 2) {
        return;
    }
    if (((Shared_World *)arg0)->level == index) {
        entry = (char *)((SceneRecAt140 *)arg0)->actors + (s32) arg2 * 0x2E8;
        cond = (struct Def *)((LevelActor *)entry)->definition;
        if ((u32) (cond->type - 9) < 2) {
            if (cond->flags & 0x200) {
                return;
            }
        }
    }
    field80 = ((Shared_World *)arg0)->bitSections;
    table = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(field80, 0), (s32) index), 0);
    func_8028FDB4_de(table, 0);
    func_8028FDF8_de((s32) table, 1);
    base1 = (u8 *) func_8028FDB4_de(table, 1);
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

void func_8028B7B4_de(Field_void_80 *arg0, s32 index, s32 arg2, s32 arg3) {
    void *table;
    u8 *base1;
    u8 *base2;
    s32 mask;
    s32 idx;
    s32 idx2;

    table = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(arg0->value, 0), index), 1);
    func_8028FDB4_de(table, 0);
    func_8028FDF8_de((s32) table, 1);
    base1 = (u8 *) func_8028FDB4_de(table, 1);
    base2 = base1;
    mask = 1 << (arg2 & 7);
    if (arg3 != 0) {
        idx = arg2;
        if (arg2 < 0) {
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

void func_8028B898_de(void *arg0, struct LevelBitRecord *levelBitRecord, s32 arg2) {
    s32 bitIndex;
    void *field80;
    s32 field1B40C;
    void *table;
    u8 *base1;
    u8 *base2;
    s32 mask;
    s32 idx;
    s32 idx2;

    bitIndex = levelBitRecord->bitIndex;
    field80 = ((World_func_8028787C_de *)(arg0))->levels;
    field1B40C = ((World_func_8028787C_de *)(arg0))->level;
    table = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(field80, 0), field1B40C), 1);
    func_8028FDB4_de(table, 0);
    func_8028FDF8_de((s32) table, 1);
    base1 = (u8 *) func_8028FDB4_de(table, 1);
    base2 = base1;
    mask = 1 << (bitIndex & 7);
    if (arg2 != 0) {
        idx = bitIndex;
        if (bitIndex < 0) {
            idx = bitIndex + 7;
        }
        base1[idx >> 3] |= mask;
        return;
    }
    idx2 = bitIndex;
    if (idx2 < 0) {
        idx2 += 7;
    }
    base2[idx2 >> 3] &= ~mask;
}

s32 func_8028B988_de(void *arg0, struct LevelBitRecord *levelBitRecord) {
    s32 bitIndex;
    void *field80;
    s32 field1B40C;
    void *table;
    u8 *temp_a0;
    s32 mask;

    bitIndex = levelBitRecord->bitIndex;
    field80 = ((World_func_8028787C_de *)(arg0))->levels;
    field1B40C = ((World_func_8028787C_de *)(arg0))->level;
    table = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(field80, 0), field1B40C), 1);
    func_8028FDB4_de(table, 0);
    func_8028FDF8_de((s32) table, 1);
    temp_a0 = (u8 *) func_8028FDB4_de(table, 1);
    mask = 1 << (bitIndex & 7);
    if (bitIndex < 0) {
        bitIndex += 7;
    }
    return (temp_a0[bitIndex >> 3] & mask) != 0;
}

void func_8028BA38_de(Field_void_80 *arg0, s32 index, s32 arg2, s32 arg3) {
    void *table;
    u8 *base1;
    u8 *base2;
    s32 mask;
    s32 idx;
    s32 idx2;

    table = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(arg0->value, 0), index), 2);
    func_8028FDB4_de(table, 0);
    func_8028FDF8_de((s32) table, 1);
    base1 = (u8 *) func_8028FDB4_de(table, 1);
    base2 = base1;
    mask = 1 << (arg2 & 7);
    if (arg3 != 0) {
        idx = arg2;
        if (arg2 < 0) {
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

void func_8028BB1C_de(void *world, void *trigger, s32 arg2) {
    struct ItemRecAt12 *item = trigger;
    s32 bitIndex;
    void *field80;
    s32 field1B40C;
    void *table;
    u8 *base1;
    u8 *base2;
    s32 mask;
    s32 idx;
    s32 idx2;

    bitIndex = item->bitIndex;
    field80 = ((World_func_8028787C_de *)(world))->levels;
    field1B40C = ((World_func_8028787C_de *)(world))->level;
    table = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(field80, 0), field1B40C), 2);
    func_8028FDB4_de(table, 0);
    func_8028FDF8_de((s32) table, 1);
    base1 = (u8 *) func_8028FDB4_de(table, 1);
    base2 = base1;
    mask = 1 << (bitIndex & 7);
    if (arg2 != 0) {
        idx = bitIndex;
        if (bitIndex < 0) {
            idx = bitIndex + 7;
        }
        base1[idx >> 3] |= mask;
        return;
    }
    idx2 = bitIndex;
    if (idx2 < 0) {
        idx2 += 7;
    }
    base2[idx2 >> 3] &= ~mask;
}

s32 func_8028BC0C_de(Shared_World *world, void *trigger) {
    s32 bitIndex;
    void *field80;
    s32 field1B40C;
    void *table;
    u8 *temp_a0;
    s32 mask;

    bitIndex = ((Record14 *)trigger)->reserved13;
    field80 = world->bitSections;
    field1B40C = world->level;
    table = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(field80, 0), field1B40C), 2);
    func_8028FDB4_de(table, 0);
    func_8028FDF8_de((s32) table, 1);
    temp_a0 = (u8 *) func_8028FDB4_de(table, 1);
    mask = 1 << (bitIndex & 7);
    if (bitIndex < 0) {
        bitIndex += 7;
    }
    return (temp_a0[bitIndex >> 3] & mask) != 0;
}

/* Finds an identifier in the object's list and returns its mapped byte from the resource record, or -1 when absent. */
s32 func_8028BCBC_de(ObjectRecAtB0 *arg0, s32 arg1) {
    s32 i;
    void *record;
    Table *list = arg0->list;
    s32 count = list->unk4;
    s32 *ids = list->deltas;

    for (i = 0; i < count; i++) {
        if (ids[i] == arg1) {
            record = func_8028FDB4_de(arg0->resource, 1);
            func_8028FDB4_de(record, 0);
            return ((u8 *)func_8028FDB4_de(record, 1))[i];
        }
    }
    return -1;
}
