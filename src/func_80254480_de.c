#include "span_1000/code_802BB15C.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802536F4.h"
#include "types.h"
#include "span_1000/code_802508E0.h"






extern OSMesgQueue D_80101140;

extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32);
extern struct Shape_typemap_165 *func_802514A8_de(s32, u32);

extern void func_80254C70_de(s32, struct Shape_typemap_165 *);
extern void func_80254AD0_de(s32 arg0, s32 arg1);
extern s32 func_802BB420_de(OSMesgQueue *, s32, s32);




struct Shape_typemap_165 *func_80254480_de(s32 arg0, void *arg1, s32 arg2) {
    struct Shape_typemap_165 *node;
    s32 result;
    s32 counter;
    s32 counter2;
    u32 token;
    u32 token2;
    u32 flags;

    token = func_802BCF30_de();
    counter = D_8010515C + 1;
    D_8010515C = counter;
    if (counter != 1) {
        func_802BCF50_de(token);
        func_802BB2A0_de(&D_80101140, 0, 1);
    } else {
        func_802BCF50_de(token);
    }
    flags = ((ResourceLoadRequest *)arg1)->mode;
    node = func_802514A8_de(0, flags);
    if (node != 0) {
        node->field_8++;
        node->field_C |= 0x100;
        result = ((s32 (*)(s32, s32, s32, u32))func_80254B8C_de)(0, arg2, (flags >> 5) & 1, flags);
        node->field_0 = result;
        if (result != 0) {
            node->field_4 = arg2;
            node->field_C |= flags;
            func_80254C70_de(0, node);
        } else {
            node->field_8--;
            if (node->field_8 == 0) {
                node->field_C &= ~0x100;
            }
            func_80254AD0_de(0, node);
            node = 0;
        }
    }
    token2 = func_802BCF30_de();
    counter2 = D_8010515C - 1;
    D_8010515C = counter2;
    if (counter2 != 0) {
        func_802BCF50_de(token2);
        func_802BB420_de(&D_80101140, 0, 1);
    } else {
        func_802BCF50_de(token2);
    }
    return node;
}
