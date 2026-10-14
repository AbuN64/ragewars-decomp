#include "span_1000/code_80297CD0.h"
#include "types.h"
extern ScreenManager *D_8014D080;
s32 func_80298368_de(s32);
s32 func_802999A0_de(s32);
void func_802998A8_de(void) {
    if (D_8014D080->current > 0) {
        func_80298368_de(func_802999A0_de(0));
    }
}
