#include "span_1000/code_802BB15C.h"
#include "span_1000/code_802B7488.h"
#include "span_1000/code_802B9BB4.h"
#include "types.h"



extern s32 func_802B9CB0_de(s32, s32);
extern void func_802B7A20_de(s32 arg0);
extern void func_802B7AD8_de(s32 *arg0, s32 arg1);


extern u8 D_8014D4B0;
extern char D_8014D470;

s32 func_802B7740_de(s32 arg0, s32 arg1) {
    s32 output;
    s32 result;
    u8 *state;
    s32 sentinel;

    func_802B9C14_de();
    state = &D_8014D4B0;
    sentinel = 0xFF;
    if (*state != sentinel) {
        char *data;

        func_802B784C_de();
        data = &D_8014D470;
        func_802B9CB0_de(1, data);
        func_802BB2A0_de(arg0, 0, 1);
        func_802B9CB0_de(0, data);
        func_802BB2A0_de(arg0, 0, 1);
        func_802B7A20_de(sentinel);
        func_802B9CB0_de(1, data);
        func_802BB2A0_de(arg0, 0, 1);
        *state = sentinel;
    }
    result = func_802B9CB0_de(0, &D_8014D470);
    func_802BB2A0_de(arg0, 0, 1);
    func_802B7AD8_de(&output, arg1);
    func_802B9C80_de();
    return result;
}
