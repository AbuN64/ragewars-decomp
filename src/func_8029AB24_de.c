#include "span_1000/code_80299DB4.h"
#include "types.h"



extern void func_8029A558_de(s16 *arg0);

void func_8029AB24_de(s16 arg0, s32 arg1, s32 arg2) {
    Msg m;

    m.f0 = 4;
    m.f4 = 3;
    m.f6 = 0x162;
    m.fE = arg1 * 0x64;
    m.f2 = arg0;
    m.f8 = 0;
    m.fC = 0;
    m.f10 = arg2 * 0x64;
    m.f12 = 0;
    func_8029A558_de((s16 *) &m);
}
