#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80277444.h"
#include "types.h"
/* Adds packed per-axis byte offsets to each entry of a vertex list. */





extern Table *func_8028FDB4_de(s32, s32);

void func_80278B3C_de(s32 arg0, s32 count, Vec3 *vtx) {
    Table *t;
    s32 zero;
    s32 i;
    s32 *d;
    s32 w;
    s32 dx;
    s32 dy;
    s32 dz;

    t = func_8028FDB4_de(arg0, 1);
    if (t->unk4 != 0) {
        zero = 0;
        i = zero;
        d = t->deltas;
        if (count > zero) {
            do {
                w = d[i];
                dx = ((w & 0xFF0000) << 8) >> 23;
                dy = ((w << 16) >> 24) * 2;
                dz = (w << 24) >> 23;
                vtx[i].x += (f32)dx;
                vtx[i].y += (f32)dy;
                vtx[i].z += (f32)dz;
                i++;
            } while (i < count);
        }
    }
}
