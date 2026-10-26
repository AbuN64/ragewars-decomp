#include "COMMON/WORLDRECAT1B6A4.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "ENGINE/SCENE_7.H"
#include "COMMON/EXTERNS_8.H"
#include "COMMON/WORLD.H"
#include "COMMON/COLORENTRY.H"
#include "TYPES.H"
#include "RENDER_4/8028FD2C_6.H"

extern void func_8028FDF8_de(s32 arg0, s32 arg1);

void func_8028DA74_de(Shared_World *world) {
    void *handle;

    handle = world->resourceHandle;
    if (handle != 0) {
        Cache_ReleaseResource(0, handle);
        world->resourceHandle = 0;
        world->resourceKey = -1;
    }
}

void func_8028DAB4_de(struct World_func_8028787C_de *arg0, s32 arg1, s32 index, s32 arg3) {
    void *base;
    void *table;

    if (arg1 != 0) {
        base = arg0->levels;
    } else {
        base = arg0->secondaryLevels;
    }
    table = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(base, 0), arg3), index);
    SetN64_GetPackSection(table, 0);
    func_8028FDF8_de((s32) table, 1);
    SetN64_GetPackSection(table, 1);
}

void func_8028DB3C_de(struct World_func_8028787C_de *arg0, s32 arg1, s32 index, s32 arg3, s32 arg4, s32 arg5) {
    void *base;
    void *table;
    u8 *base1;
    u8 *base2;
    s32 mask;
    s32 idx;
    s32 idx2;

    if (arg1 != 0) {
        base = arg0->levels;
    } else {
        base = arg0->secondaryLevels;
    }
    table = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(base, 0), arg3), index);
    SetN64_GetPackSection(table, 0);
    func_8028FDF8_de((s32) table, 1);
    base1 = (u8 *) SetN64_GetPackSection(table, 1);
    base2 = base1;
    mask = 1 << (arg4 & 7);
    if (arg5 != 0) {
        idx = arg4;
        if (arg4 < 0) {
            idx = arg4 + 7;
        }
        base1[idx >> 3] |= mask;
        return;
    }
    idx2 = arg4;
    if (idx2 < 0) {
        idx2 += 7;
    }
    base2[idx2 >> 3] &= ~mask;
}

s32 func_8028DC3C_de(struct World_func_8028787C_de *arg0, s32 arg1, s32 index, s32 arg3, s32 arg4) {
    void *base;
    void *table;
    u8 *temp_a0;
    s32 mask;
    s32 i;

    if (arg1 != 0) {
        base = arg0->levels;
    } else {
        base = arg0->secondaryLevels;
    }
    table = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(base, 0), arg3), index);
    SetN64_GetPackSection(table, 0);
    func_8028FDF8_de((s32)table, 1);
    temp_a0 = (u8 *)SetN64_GetPackSection(table, 1);
    mask = 1 << (arg4 & 7);
    i = arg4;
    if (i < 0) {
        i += 7;
    }
    return (temp_a0[i >> 3] & mask) != 0;
}

s32 func_8028DD00_de(void *arg0, s32 index, s32 arg2) {
    Shared_World *world = arg0;
    void *table;
    u8 *temp_a0;
    s32 mask;
    s32 i;

    table = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(world->secondaryLevels, 0), index), 0);
    SetN64_GetPackSection(table, 0);
    func_8028FDF8_de((s32)table, 1);
    temp_a0 = (u8 *)SetN64_GetPackSection(table, 1);
    mask = 1 << (arg2 & 7);
    i = arg2;
    if (i < 0) {
        i += 7;
    }
    return (temp_a0[i >> 3] & mask) != 0;
}

s32 func_8028DDA4_de(Field_void_80 *arg0, s32 index, s32 arg2) {
    void *table;
    u8 *temp_a0;
    s32 mask;
    s32 i;

    table = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(arg0->value, 0), index), 0);
    SetN64_GetPackSection(table, 0);
    func_8028FDF8_de((s32)table, 1);
    temp_a0 = (u8 *)SetN64_GetPackSection(table, 1);
    mask = 1 << (arg2 & 7);
    i = arg2;
    if (i < 0) {
        i += 7;
    }
    return (temp_a0[i >> 3] & mask) != 0;
}

s32 func_8028DE48_de(Field_void_80 *arg0, s32 index, s32 arg2) {
    void *table;
    u8 *temp_a0;
    s32 mask;
    s32 i;

    table = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(arg0->value, 0), index), 1);
    SetN64_GetPackSection(table, 0);
    func_8028FDF8_de((s32)table, 1);
    temp_a0 = (u8 *)SetN64_GetPackSection(table, 1);
    mask = 1 << (arg2 & 7);
    i = arg2;
    if (i < 0) {
        i += 7;
    }
    return (temp_a0[i >> 3] & mask) != 0;
}

s32 func_8028DEEC_de(Field_void_80 *arg0, s32 index, s32 arg2) {
    void *table;
    u8 *temp_a0;
    s32 mask;
    s32 i;

    table = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(arg0->value, 0), index), 2);
    SetN64_GetPackSection(table, 0);
    func_8028FDF8_de((s32)table, 1);
    temp_a0 = (u8 *)SetN64_GetPackSection(table, 1);
    mask = 1 << (arg2 & 7);
    i = arg2;
    if (i < 0) {
        i += 7;
    }
    return (temp_a0[i >> 3] & mask) != 0;
}
