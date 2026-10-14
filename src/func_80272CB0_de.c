#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80271B18.h"
#include "types.h"

extern f32 D_800C48D0_de[2];




void func_80272CB0_de(void *arg0, f32 arg1, f32 arg2, f32 arg3) {
    Matrix *o = arg0;
    f32 val = D_800C48D0_de[1];
    f32 zero = 0.0f;

    o->m[0] = arg1;
    o->m[5] = arg2;
    o->m[10] = arg3;
    o->m[15] = val;
    o->m[14] = zero;
    o->m[13] = zero;
    o->m[12] = zero;
    o->m[11] = zero;
    o->m[9] = zero;
    o->m[8] = zero;
    o->m[7] = zero;
    o->m[6] = zero;
    o->m[4] = zero;
    o->m[3] = zero;
    o->m[2] = zero;
    o->m[1] = zero;
}
