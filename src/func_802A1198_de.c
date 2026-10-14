#include "span_1000/code_802A0AC4.h"
#include "types.h"


extern s32 func_802A0724_de(s32, s32, s32);

s32 func_802A1198_de(s32 arg0, s32 arg1, s32 arg2) {
    s32 *p;

    p = D_800CD940_de;
    func_802A0724_de(arg1, p[0] + p[1], arg2);
    p[1] = p[1] + arg2;
    return 1;
}
