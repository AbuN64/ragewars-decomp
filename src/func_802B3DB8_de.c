#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B369C.h"
#include "types.h"



extern f32 D_800C7590[2];

s32 func_802B3DB8_de(func_8022E694_S1 *arg0, s32 arg1) {
    f32 v;
    int idx;

    v = (f32)arg1 * (f32)arg0->unk44;
    idx = 0;
    v = v * D_800C7590[idx];
    v = v + D_800C7590[1];
    return (s32)v;
}
