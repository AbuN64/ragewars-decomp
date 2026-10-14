#include "span_1000/code_802A0AC4.h"
#include "types.h"

extern s32 D_800CD944_de;

s32 func_802A11F4_de(s32 arg0, s32 arg1, s32 arg2) {
    s32 *p;

    if (arg2 == 0) {
        D_800CD944_de = 0;
    }
    p = &D_800CD944_de;
    *p = *p + arg1;
    return 0;
}
