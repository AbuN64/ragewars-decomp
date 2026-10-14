#include "common/unused.h"
#include "span_C76B0/data.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_8025A3EC.h"
#include "types.h"












void func_8025B758_de(s32 *arg0, s32 arg1) {
    s32 i;
    s32 idx;
    f32 t;
    f32 p;
    s32 off;
    Record_func_8025B758_de *rec;
    f32 k1;
    f32 k2;
    f32 k3;
    s32 negone;
    s32 one;

    i = 0;
    k1 = D_800C3F7C_de;
    k2 = D_800C3F80_de;
    *arg0 = arg1;
    do {
        t = (f32)i * k1;
        p = t * t * t * t * t * k2;
        idx = 0x5A - i;
        i += 1;
        D_80107FA0[idx] = (s16)(s32)p;
    } while (i < 0x5B);

    negone = -1;
    i = 0;
    k3 = D_800C3F84_de;
    one = 1;
    off = i;
    do {
        rec = (Record_func_8025B758_de *)((u32)off + (u32)arg0);
        rec = &((func_8025B778_S2 *)(rec))->unk4;
        rec->index = i;
        i += 1;
        rec->owner = arg1;
        rec->f0C = negone;
        rec->f08 = negone;
        rec->f3A = (s16)negone;
        rec->f38 = 0;
        rec->f40 = negone;
        rec->f14 = 0;
        rec->f2C = k3;
        rec->f58 = 0;
        rec->f5C = 0;
        rec->f34 = k3;
        rec->fA4 = 0;
        rec->fAC = 0;
        rec->fB4 = negone;
        rec->fB8 = k3;
        rec->fBC = 0;
        rec->fC0 = 0;
        rec->fC4 = one;
        off += 0xCC;
    } while (i < 0x11);
}
