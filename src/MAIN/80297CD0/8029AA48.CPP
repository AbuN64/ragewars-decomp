#include "span_1000/code_80299DB4.h"
#include "span_1000/code_80297CD0.h"
#include "TYPES.H"

void func_80299A48_de(int arg0, int arg1) {
    extern func_8029AA48_S1 *D_8014D080;
    D_8014D080->unk534 = arg0;
    D_8014D080->unk538 = arg1;
}

void func_80299A5C_de(s32 *arg0, s32 *arg1) {
    extern ScreenManager *D_8014D080;
    *arg0 = D_8014D080->field534;
    *arg1 = D_8014D080->field538;
}
