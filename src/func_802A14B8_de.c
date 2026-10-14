#include "span_1000/code_802A1264.h"
#include "types.h"

extern f32 D_800C5D80_de;
extern f32 D_800CD96C[3];
extern f32 D_800CD978[3];

extern s32 D_801470A0;


void func_802A14B8_de(void) {
    s32 index;
    s32 value;
    s32 amount;
    f32 fvalue;

    index = D_801470A0;
    value = D_80147060[index];
    amount = value - D_801470A8;
    fvalue = D_800CD978[0] + (f32)-amount;
    D_801470A0 = index - 1;
    D_801470A8 = value;
    D_800CD978[0] = fvalue;
    if (fvalue < D_800C5D80_de) {
        D_800CD978[0] = D_800C5D80_de;
    }
    if (D_800CD978[0] > *(&D_800C5D80_de + 1)) {
        D_800CD978[0] = *(&D_800C5D80_de + 1);
    }
    if (D_800CD978[0] < D_800CD978[1]) {
        D_800CD978[1] = D_800CD978[0];
    }
    if (D_800CD978[2] < D_800CD978[0]) {
        D_800CD978[2] = D_800CD978[0];
    }

    D_800CD96C[0] += (f32)amount;
    if (D_800CD96C[0] < D_800C5D80_de) {
        D_800CD96C[0] = D_800C5D80_de;
    }
    if (*(&D_800C5D80_de + 1) < D_800CD96C[0]) {
        D_800CD96C[0] = *(&D_800C5D80_de + 1);
    }
    if (D_800CD96C[0] < D_800CD96C[1]) {
        D_800CD96C[1] = D_800CD96C[0];
    }
    if (D_800CD96C[2] < D_800CD96C[0]) {
        D_800CD96C[2] = D_800CD96C[0];
    }
}
