#include "span_1000/code_80297CD0.h"
#include "types.h"
extern Ui_func_80297FA0_de *D_8014D080;
s32 func_802999A0_de(s32 arg0) {
    s32 idx;
    s32 countMinus1;
    countMinus1 = D_8014D080->current - 1;
    idx = countMinus1 - arg0;
    if (idx >= 0) {
        return D_8014D080->screens[idx].owner;
    }
    return -1;
}
