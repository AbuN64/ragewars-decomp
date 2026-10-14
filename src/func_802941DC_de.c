#include "span_1000/code_80293A04.h"
#include "types.h"

extern void func_80293904_de(s32 arg0, u32 arg1, s32 arg2, s32 arg3);

void func_802941DC_de(s32 arg0) {
    s32 eight;
    u32 bits;

    eight = 8;
    bits = 0x41400000;
    func_80293904_de(arg0, (double)bits, eight, eight);
}
