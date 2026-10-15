#include "span_1000/code_802508E0.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802536F4.h"
#include "span_1000/code_802BB15C.h"
#include "types.h"

extern u32 func_802BCF30_de(void);

extern void func_802BCF50_de(u32);

extern struct Shape_typemap_165 *func_802548B8_de(s32, s32, u32, void *);

extern s8 D_801051A0;

extern struct Shape_typemap_165 *func_802514A8_de(s32, u32);

extern s32 func_80255630_de(s8 *, void *, s32);

extern void func_80254C70_de(s32 unused, void *object);

extern void func_80254AD0_de(s32 arg0, s32 arg1);

extern void func_80254DA4_de(void *, Node80253610 *);

extern void func_80254990_de(void *, void *);

extern void func_802511AC_de(s32);

extern s32 func_80254B58_de(s32, s32, s32);

extern void func_802515F0_de(s32, s32);

extern void func_802BCF50_de(u32 arg0);

extern s32 D_80101134[];

struct Shape_typemap_165 *func_8025343C_de(s32 arg0, s32 arg1, u32 arg2, void *arg3) {
    extern s32 func_802BB420_de(OSMesgQueue *, s32, s32);
    extern OSMesgQueue D_80101140;
    struct Shape_typemap_165 *var_s0;
    s32 temp_v1;
    s32 temp_v1_2;
    u32 temp_a0;
    u32 temp_v0;
    s32 temp_s0;
    u32 temp_s1;
    void *temp_s2;

    temp_s0 = arg1;
    temp_s1 = arg2;
    temp_s2 = arg3;
    temp_a0 = func_802BCF30_de();
    temp_v1 = D_8010515C + 1;
    D_8010515C = temp_v1;
    if (temp_v1 != 1) {
        func_802BCF50_de(temp_a0);
        func_802BB2A0_de(&D_80101140, 0, 1);
    } else {
        func_802BCF50_de(temp_a0);
    }
    var_s0 = func_802548B8_de(0, temp_s0, temp_s1, temp_s2);
    temp_v0 = func_802BCF30_de();
    temp_v1_2 = D_8010515C - 1;
    D_8010515C = temp_v1_2;
    if (temp_v1_2 != 0) {
        func_802BCF50_de(temp_v0);
        func_802BB420_de(&D_80101140, 0, 1);
    } else {
        func_802BCF50_de(temp_v0);
    }
    return var_s0;
}

struct Shape_typemap_165 *func_80253530_de(void *arg0, void *arg1, s32 arg2) {
    extern s32 func_802BB420_de(OSMesgQueue *, s32, s32);
    extern OSMesgQueue D_80101140;
    struct Shape_typemap_165 *var_s0;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v1_2;
    u32 temp_a0;
    u32 temp_v0_2;

    temp_a0 = func_802BCF30_de();
    temp_v1 = D_8010515C + 1;
    D_8010515C = temp_v1;
    if (temp_v1 != 1) {
        func_802BCF50_de(temp_a0);
        func_802BB2A0_de(&D_80101140, 0, 1);
    } else {
        func_802BCF50_de(temp_a0);
    }
    var_s0 = func_802514A8_de(0, 0U);
    if (var_s0 != 0) {
        temp_v0 = func_80255630_de(&D_801051A0, arg1, arg2);
        var_s0->field_0 = temp_v0;
        if (temp_v0 != 0) {
            var_s0->field_4 = arg2;
            var_s0->field_C |= 3;
            func_80254C70_de(0, var_s0);
        } else {
            func_80254AD0_de(0, var_s0);
            var_s0 = 0;
        }
    }
    temp_v0_2 = func_802BCF30_de();
    temp_v1_2 = D_8010515C - 1;
    D_8010515C = temp_v1_2;
    if (temp_v1_2 != 0) {
        func_802BCF50_de(temp_v0_2);
        func_802BB420_de(&D_80101140, 0, 1);
    } else {
        func_802BCF50_de(temp_v0_2);
    }
    return var_s0;
}

void func_80253670_de(void *arg0, Node80253610 *arg1) {
    extern s32 func_802BB420_de(OSMesgQueue *, s32, s32);
    extern OSMesgQueue D_80101140;
    s32 temp_v1;
    s32 temp_v1_2;
    u32 temp_a0;
    u32 temp_v0;
    Node80253610 *temp_s0;

    temp_s0 = arg1;
    temp_a0 = func_802BCF30_de();
    temp_v1 = D_8010515C + 1;
    D_8010515C = temp_v1;
    if (temp_v1 != 1) {
        func_802BCF50_de(temp_a0);
        func_802BB2A0_de(&D_80101140, 0, 1);
    } else {
        func_802BCF50_de(temp_a0);
    }
    func_80254DA4_de(0, temp_s0);
    temp_s0->references += 1;
    temp_s0->flags |= 0x100;
    temp_v0 = func_802BCF30_de();
    temp_v1_2 = D_8010515C - 1;
    D_8010515C = temp_v1_2;
    if (temp_v1_2 != 0) {
        func_802BCF50_de(temp_v0);
        func_802BB420_de(&D_80101140, 0, 1);
        return;
    }
    func_802BCF50_de(temp_v0);
}

void func_80253754_de(void *arg0, Node80253610 *arg1) {
    extern s32 func_802BB420_de(OSMesgQueue *, s32, s32);
    extern OSMesgQueue D_80101140;
    s32 temp_v1;
    s32 temp_v1_2;
    u32 temp_a0;
    u32 temp_v0;
    Node80253610 *temp_s0;

    temp_s0 = arg1;
    temp_a0 = func_802BCF30_de();
    temp_v1 = D_8010515C + 1;
    D_8010515C = temp_v1;
    if (temp_v1 != 1) {
        func_802BCF50_de(temp_a0);
        func_802BB2A0_de(&D_80101140, 0, 1);
    } else {
        func_802BCF50_de(temp_a0);
    }
    temp_s0->references -= 1;
    if (temp_s0->references == 0) {
        temp_s0->flags &= ~0x100;
    }
    temp_v0 = func_802BCF30_de();
    temp_v1_2 = D_8010515C - 1;
    D_8010515C = temp_v1_2;
    if (temp_v1_2 != 0) {
        func_802BCF50_de(temp_v0);
        func_802BB420_de(&D_80101140, 0, 1);
        return;
    }
    func_802BCF50_de(temp_v0);
}

void func_80253838_de(void *arg0, void *arg1) {
    extern s32 func_802BB420_de(OSMesgQueue *, s32, s32);
    extern OSMesgQueue D_80101140;
    s32 temp_v1;
    s32 temp_v1_2;
    u32 temp_a0;
    u32 temp_v0;

    temp_a0 = func_802BCF30_de();
    temp_v1 = D_8010515C + 1;
    D_8010515C = temp_v1;
    if (temp_v1 != 1) {
        func_802BCF50_de(temp_a0);
        func_802BB2A0_de(&D_80101140, 0, 1);
    } else {
        func_802BCF50_de(temp_a0);
    }
    func_80254990_de(0, arg1);
    temp_v0 = func_802BCF30_de();
    temp_v1_2 = D_8010515C - 1;
    D_8010515C = temp_v1_2;
    if (temp_v1_2 != 0) {
        func_802BCF50_de(temp_v0);
        func_802BB420_de(&D_80101140, 0, 1);
        return;
    }
    func_802BCF50_de(temp_v0);
}

void func_80253908_de(s32 unusedHeap) {
    extern s32 func_802BB420_de(OSMesgQueue *, s32, s32);
    extern OSMesgQueue D_80101140;
    s32 temp_v1;
    s32 temp_v1_2;
    u32 temp_a0;
    u32 temp_v0;

    temp_a0 = func_802BCF30_de();
    temp_v1 = D_8010515C + 1;
    D_8010515C = temp_v1;
    if (temp_v1 != 1) {
        func_802BCF50_de(temp_a0);
        func_802BB2A0_de(&D_80101140, 0, 1);
    } else {
        func_802BCF50_de(temp_a0);
    }
    func_802511AC_de(0);
    while (func_80254B58_de(0, 0, 0) != 0) {
    }
    func_802515F0_de(0, 1);
    temp_v0 = func_802BCF30_de();
    temp_v1_2 = D_8010515C - 1;
    D_8010515C = temp_v1_2;
    if (temp_v1_2 != 0) {
        func_802BCF50_de(temp_v0);
        func_802BB420_de(&D_80101140, 0, 1);
        return;
    }
    func_802BCF50_de(temp_v0);
}

void func_802539EC_de(s32 unused, s32 arg1) {
    extern void func_802BB420_de(void *arg0, s32 arg1, s32 arg2);
    s32 temp_v1;
    s32 temp_v1_2;
    ResourceLockState *base;
    u32 temp_a0;
    u32 temp_v0;

    temp_a0 = func_802BCF30_de();
    temp_v1 = D_8010515C + 1;
    D_8010515C = temp_v1;
    if (temp_v1 != 1) {
        func_802BCF50_de(temp_a0);
        func_802BB2A0_de(&((ResourceLockState *)&D_801005A8)->waitQueue, 0, 1);
    } else {
        func_802BCF50_de(temp_a0);
    }
    base = (ResourceLockState *)&D_801005A8;
    base->slot = arg1;
    D_80100598[arg1] = 1;
    temp_v0 = func_802BCF30_de();
    temp_v1_2 = D_8010515C - 1;
    D_8010515C = temp_v1_2;
    if (temp_v1_2 != 0) {
        func_802BCF50_de(temp_v0);
        func_802BB420_de(&base->waitQueue, 0, 1);
        return;
    }
    func_802BCF50_de(temp_v0);
}

s32 func_80253AD4_de(void) {
    extern void func_802BB420_de(void *arg0, s32 arg1, s32 arg2);
    s32 temp_v1;
    s32 temp_v1_2;
    s32 *base;
    u32 temp_a0;
    u32 temp_v0;
    s32 result;

    temp_a0 = func_802BCF30_de();
    temp_v1 = D_8010515C + 1;
    D_8010515C = temp_v1;
    if (temp_v1 != 1) {
        func_802BCF50_de(temp_a0);
        func_802BB2A0_de(((char *)&D_801005A8 + 0xB98), 0, 1);
    } else {
        func_802BCF50_de(temp_a0);
    }
    base = &D_801005A8;
    result = *(s32 *)((char *)D_80100598 + (*base << 2));
    *base = -1;
    temp_v0 = func_802BCF30_de();
    temp_v1_2 = D_8010515C - 1;
    D_8010515C = temp_v1_2;
    if (temp_v1_2 != 0) {
        func_802BCF50_de(temp_v0);
        func_802BB420_de((char *)base + 0xB98, 0, 1);
    } else {
        func_802BCF50_de(temp_v0);
    }
    return result;
}

void func_80253BBC_de(s32 arg0, func_80205628_S3 *arg1) {
    extern void func_802BB420_de(void *arg0, s32 arg1, s32 arg2);
    extern s32 D_80101140;
    s32 index;
    s32 mask;
    s32 flags;
    s32 counter;
    s32 counter2;
    s32 *base;
    u32 token;
    u32 token2;

    base = &D_801005A8;
    index = *base;
    token = func_802BCF30_de();
    counter = D_8010515C + 1;
    D_8010515C = counter;
    if (counter != 1) {
        func_802BCF50_de(token);
        func_802BB2A0_de(((char *)base + 0xB98), 0, 1);
    } else {
        func_802BCF50_de(token);
    }

    if (D_80100598[index] != 0) {
        mask = 0x200;
        if (index != 0) {
            mask = 0x400;
        }
        flags = arg1->unkC;
        if (!(flags & mask)) {
            arg1->unkC = flags | mask;
            D_80101134[index]++;
        }
    }

    token2 = func_802BCF30_de();
    counter2 = D_8010515C - 1;
    D_8010515C = counter2;
    if (counter2 != 0) {
        func_802BCF50_de(token2);
        func_802BB420_de(&D_80101140, 0, 1);
        return;
    }
    func_802BCF50_de(token2);
}
