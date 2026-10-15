#include "span_1000/code_80277444.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "types.h"

/* Sums the size field of the record func_8028FDB4_de returns for each entry of the D_8011FE88 table and returns the total.
   Adapted from func_802AFFC0_de with the loop over the global entry table and the accumulated return changed. */





extern char D_8011FE88[];

/* Adds packed per-axis byte offsets to each entry of a vertex list. */







s32 func_80278ABC_de(void) {
    extern struct Shape_typemap_13 *func_8028FDB4_de(s32, s32);
    s32 total = 0;
    s32 i;
    char *base = D_8011FE88;

    for (i = 0; i < ((IntegerState1504 *)(base))->unk_1500; i++) {
        total += func_8028FDB4_de(*((struct ObjectLinks150C *) (base + (i * 0xC)))->unk_1508, 2)->field_4;
    }
    return total;
}

void func_80278B3C_de(s32 arg0, s32 count, Vec3 *vtx) {
    extern Table *func_8028FDB4_de(s32, s32);
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
