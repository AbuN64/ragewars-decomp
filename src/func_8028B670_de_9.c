#include "span_1000/code_8028B64C.h"
#include "common/types_1dc8418c21db.h"
#include "shared/func_80245BC0_de_closed.h"
#include "shared/world.h"
#include "span_1000/code_8028CCB8.h"
#include "types.h"


extern void func_8028FDF8_de(s32 arg0, s32 arg1);

void func_8028DA74_de(Shared_World *world) {
    void *handle;

    handle = world->resourceHandle;
    if (handle != 0) {
        func_80253838_de(0, handle);
        world->resourceHandle = 0;
        world->resourceKey = -1;
    }
}

void func_8028DAB4_de(struct World_func_8028787C_de *arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern void *func_8028FDB4_de(void *, s32);
    void *base;
    void *temp_v0;

    if (arg1 != 0) {
        base = arg0->levels;
    } else {
        base = arg0->secondaryLevels;
    }
    temp_v0 = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(base, 0), arg3), arg2);
    func_8028FDB4_de(temp_v0, 0);
    func_8028FDF8_de((s32) temp_v0, 1);
    func_8028FDB4_de(temp_v0, 1);
}

void func_8028DB3C_de(struct World_func_8028787C_de *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    extern void *func_8028FDB4_de(void *, s32);
    void *base;
    void *temp_v0;
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
    temp_v0 = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(base, 0), arg3), arg2);
    func_8028FDB4_de(temp_v0, 0);
    func_8028FDF8_de((s32) temp_v0, 1);
    base1 = (u8 *) func_8028FDB4_de(temp_v0, 1);
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

s32 func_8028DC3C_de(struct World_func_8028787C_de *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    extern void *func_8028FDB4_de(void *, s32);
    void *base;
    void *temp_v0;
    u8 *temp_a0;
    s32 mask;
    s32 i;

    if (arg1 != 0) {
        base = arg0->levels;
    } else {
        base = arg0->secondaryLevels;
    }
    temp_v0 = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(base, 0), arg3), arg2);
    func_8028FDB4_de(temp_v0, 0);
    func_8028FDF8_de((s32)temp_v0, 1);
    temp_a0 = (u8 *)func_8028FDB4_de(temp_v0, 1);
    mask = 1 << (arg4 & 7);
    i = arg4;
    if (i < 0) {
        i += 7;
    }
    return (temp_a0[i >> 3] & mask) != 0;
}

s32 func_8028DD00_de(void *arg0, s32 arg1, s32 arg2) {
    extern char *func_8028FDB4_de(s32 *, s32);
    Shared_World *world = arg0;
    void *temp_v0;
    u8 *temp_a0;
    s32 mask;
    s32 i;

    temp_v0 = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(world->secondaryLevels, 0), arg1), 0);
    func_8028FDB4_de(temp_v0, 0);
    func_8028FDF8_de((s32)temp_v0, 1);
    temp_a0 = (u8 *)func_8028FDB4_de(temp_v0, 1);
    mask = 1 << (arg2 & 7);
    i = arg2;
    if (i < 0) {
        i += 7;
    }
    return (temp_a0[i >> 3] & mask) != 0;
}

s32 func_8028DDA4_de(Field_void_80 *arg0, s32 arg1, s32 arg2) {
    extern char *func_8028FDB4_de(s32 *, s32);
    void *temp_v0;
    u8 *temp_a0;
    s32 mask;
    s32 i;

    temp_v0 = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(arg0->value, 0), arg1), 0);
    func_8028FDB4_de(temp_v0, 0);
    func_8028FDF8_de((s32)temp_v0, 1);
    temp_a0 = (u8 *)func_8028FDB4_de(temp_v0, 1);
    mask = 1 << (arg2 & 7);
    i = arg2;
    if (i < 0) {
        i += 7;
    }
    return (temp_a0[i >> 3] & mask) != 0;
}

s32 func_8028DE48_de(Field_void_80 *arg0, s32 arg1, s32 arg2) {
    extern char *func_8028FDB4_de(s32 *, s32);
    void *temp_v0;
    u8 *temp_a0;
    s32 mask;
    s32 i;

    temp_v0 = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(arg0->value, 0), arg1), 1);
    func_8028FDB4_de(temp_v0, 0);
    func_8028FDF8_de((s32)temp_v0, 1);
    temp_a0 = (u8 *)func_8028FDB4_de(temp_v0, 1);
    mask = 1 << (arg2 & 7);
    i = arg2;
    if (i < 0) {
        i += 7;
    }
    return (temp_a0[i >> 3] & mask) != 0;
}

s32 func_8028DEEC_de(Field_void_80 *arg0, s32 arg1, s32 arg2) {
    extern char *func_8028FDB4_de(s32 *, s32);
    void *temp_v0;
    u8 *temp_a0;
    s32 mask;
    s32 i;

    temp_v0 = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(arg0->value, 0), arg1), 2);
    func_8028FDB4_de(temp_v0, 0);
    func_8028FDF8_de((s32)temp_v0, 1);
    temp_a0 = (u8 *)func_8028FDB4_de(temp_v0, 1);
    mask = 1 << (arg2 & 7);
    i = arg2;
    if (i < 0) {
        i += 7;
    }
    return (temp_a0[i >> 3] & mask) != 0;
}
