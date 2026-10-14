#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802536F4.h"
#include "types.h"
/* Allocates a four-byte probe from func_8025193C_de to read a count, frees it under the D_8010515C lock, then allocates count*4+15 rounded to eight bytes and stores its first word through arg1, returning the allocation. Adapted from func_802540F4_de with the null checks removed, tag 0x1B and flag 1 passed as the fifth and ninth arguments, and the constant 1 held in a local changed. */



extern void **func_8025193C_de(s32, s32, s32, s32, s32, s32, void *, void *, s32);
extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32);
extern void func_802BB2A0_de(s32, s32, s32);
extern void func_80254990_de(void *, void *);
extern s32 func_802BB420_de(Queue_func_802517B4_de *, s32, s32);

extern char D_800C3EA0_de;
extern Queue_func_802517B4_de D_80101140;


s32 func_80254284_de(s32 arg0, void **arg1, s32 arg2, void *arg3) {
    void **resource;
    s32 size;
    s32 counter;
    s32 counter2;
    u32 token;
    u32 token2;
    s32 one = 1;

    resource = func_8025193C_de(0, arg2, arg2, 4, 0x1B, 0, 0, &D_800C3EA0_de, one);
    size = **(s32 **)resource;
    token = func_802BCF30_de();
    counter = D_8010515C + one;
    D_8010515C = counter;
    if (counter != one) {
        func_802BCF50_de(token);
        func_802BB2A0_de((s32)&D_80101140, 0, one);
    } else {
        func_802BCF50_de(token);
    }
    func_80254990_de(0, resource);
    token2 = func_802BCF30_de();
    counter2 = D_8010515C - 1;
    D_8010515C = counter2;
    if (counter2 != 0) {
        func_802BCF50_de(token2);
        func_802BB420_de(&D_80101140, 0, 1);
    } else {
        func_802BCF50_de(token2);
    }
    resource = func_8025193C_de(0, arg2, arg2, ((size * 4) + 0xF) & ~7, 0x1B, 0, 0, arg3, 1);
    *arg1 = *resource;
    return (s32)resource;
}
