#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802536F4.h"
#include "types.h"
/* Under the queue lock, takes the table entry indexed by the current slot, marks the slot empty with -1, and returns that entry. Adapted from func_802539EC_de, with the slot read and cleared instead of set, and the entry returned; the table is indexed through a byte offset so the read stays ahead of the clear. */

extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32);
extern void func_802BB2A0_de(s32, s32, s32);
extern void func_802BB420_de(void *arg0, s32 arg1, s32 arg2);





s32 func_80253AD4_de(void) {
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
        func_802BB2A0_de((s32)((char *)&D_801005A8 + 0xB98), 0, 1);
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
