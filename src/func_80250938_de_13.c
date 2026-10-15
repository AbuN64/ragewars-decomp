#include "span_1000/code_802508E0.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802536F4.h"
#include "span_1000/code_802BB15C.h"
#include "types.h"

extern OSMesgQueue D_80101140;

extern u32 func_802BCF30_de(void);

extern void func_802BCF50_de(u32);

extern void func_80254990_de(void *, void *);

extern s32 func_802BB420_de(OSMesgQueue *, s32, s32);

extern struct Shape_typemap_165 *func_802514A8_de(s32 arg0, u32 arg1);

extern void func_80254C70_de(s32 unused, void *object);

extern void func_80254AD0_de(s32 arg0, s32 arg1);

void func_802547E4_de(void *arg0) {
    s32 temp_v1;
    s32 temp_v1_2;
    u32 temp_a0;
    u32 temp_v0;
    void *temp_s0;

    temp_s0 = ((void **)arg0)[-4];
    temp_a0 = func_802BCF30_de();
    temp_v1 = D_8010515C + 1;
    D_8010515C = temp_v1;
    if (temp_v1 != 1) {
        func_802BCF50_de(temp_a0);
        func_802BB2A0_de(&D_80101140, 0, 1);
    } else {
        func_802BCF50_de(temp_a0);
    }
    func_80254990_de(0, temp_s0);
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

struct Shape_typemap_165 *func_802548B8_de(s32 arg0_unused, s32 arg1, u32 arg2) {
    struct Shape_typemap_165 *node;
    s32 result;

    node = func_802514A8_de(0, arg2);
    if (node != 0) {
        node->field_8++;
        node->field_C |= 0x100;
        result = ((s32 (*)(s32, s32, s32, u32))func_80254B8C_de)(0, arg1, (arg2 >> 5) & 1, arg2);
        node->field_0 = result;
        if (result != 0) {
            node->field_4 = arg1;
            node->field_C |= arg2;
            func_80254C70_de(0, node);
            return node;
        }
        node->field_8--;
        if (node->field_8 == 0) {
            node->field_C &= ~0x100;
        }
        func_80254AD0_de(0, node);
        node = 0;
    }
    return node;
}
