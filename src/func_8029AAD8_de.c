#include "span_1000/code_80299DB4.h"
#include "types.h"



extern void func_8029A558_de(s16 *arg0);

void func_8029AAD8_de(s16 arg0, s16 arg1, s32 arg2) {
    Msg m;

    m.f0 = 4;
    m.f2 = arg0;
    m.f4 = 1;
    m.f6 = arg1;
    m.f8 = 0;
    m.fC = arg2 != 0;
    m.fE = 0;
    m.f10 = 0;
    m.f12 = 0;
    func_8029A558_de((s16 *) &m);
}
