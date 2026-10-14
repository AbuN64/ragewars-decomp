#include "span_1000/code_802B7488.h"
#include "types.h"

extern u64 func_802BADC0_de(void);
extern void func_802BAC60_de(void *, s32, s32);
extern void func_802BB6C0_de(void *arg0, u64 arg1, u64 arg2, void *arg3, void *arg4);
extern void func_802BB2A0_de(s32, s32, s32);
extern void func_802B7A20_de(s32 arg0);
extern s32 func_802B9CB0_de(s32, s32);
extern void func_802B7AD8_de(s32 *arg0, s32 arg1);
extern void func_802B9BC0_de();


extern s8 D_8014D46C;
extern u8 D_8014D4B0;
extern s32 D_801471C0;
extern s32 D_801471D8;
extern char D_8014D470;

s32 func_802B7880_de(s32 arg0, s32 *arg1, s32 arg2) {
    s32 sp20[8];
    s32 sp40[6];
    s32 sp58[2];
    u64 value;
    s32 result;
    s32 *initialized = &D_800D4340;

    if (*initialized != 0) {
        return 0;
    }
    *initialized = 1;
    value = func_802BADC0_de();
    if (value <= 0x0165A0BBULL) {
        func_802BAC60_de(sp40, (s32)sp58, 1);
        func_802BB6C0_de(sp20, 0x0165A0BCULL - value, 0, sp40, sp58);
        func_802BB2A0_de((s32)sp40, (s32)sp58, 1);
    }
    D_8014D46C = 4;
    func_802B7A20_de(0);
    func_802B9CB0_de(1, &D_8014D470);
    func_802BB2A0_de(arg0, (s32)sp58, 1);
    result = func_802B9CB0_de(0, &D_8014D470);
    func_802BB2A0_de(arg0, (s32)sp58, 1);
    func_802B7AD8_de(arg1, arg2);
    D_8014D4B0 = 0;
    func_802B9BC0_de();
    func_802BAC60_de(&D_801471C0, (s32)&D_801471D8, 1);
    return result;
}
