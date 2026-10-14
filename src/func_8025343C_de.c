#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802508E0.h"
#include "types.h"

extern Queue_func_802517B4_de D_80101140;

extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32);
extern void func_802BB2A0_de(s32, s32, s32);
extern struct Shape_typemap_165 *func_802548B8_de(s32, s32, u32, void *);
extern s32 func_802BB420_de(Queue_func_802517B4_de *, s32, s32);

struct Shape_typemap_165 *func_8025343C_de(s32 arg0, s32 arg1, u32 arg2, void *arg3) {
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
        func_802BB2A0_de((s32)&D_80101140, 0, 1);
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

extern Queue_func_802517B4_de D_80101140;
extern s8 D_801051A0;

extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32);
extern void func_802BB2A0_de(s32, s32, s32);
extern struct Shape_typemap_165 *func_802514A8_de(s32, u32);
extern s32 func_80255630_de(s8 *, void *, s32);
extern void func_80254C70_de(s32, struct Shape_typemap_165 *);
extern void func_80254AD0_de(s32, struct Shape_typemap_165 *);
extern s32 func_802BB420_de(Queue_func_802517B4_de *, s32, s32);

struct Shape_typemap_165 *func_80253530_de(void *arg0, void *arg1, s32 arg2) {
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
        func_802BB2A0_de((s32)&D_80101140, 0, 1);
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

extern Queue_func_802517B4_de D_80101140;

extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32);
extern void func_802BB2A0_de(s32, s32, s32);
extern void func_80254DA4_de(void *, Node80253610 *);
extern s32 func_802BB420_de(Queue_func_802517B4_de *, s32, s32);

void func_80253670_de(void *arg0, Node80253610 *arg1) {
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
        func_802BB2A0_de((s32)&D_80101140, 0, 1);
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
