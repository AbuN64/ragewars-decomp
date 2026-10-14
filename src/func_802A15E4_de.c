#include "span_1000/code_802A1264.h"
#include "types.h"

extern f32 D_800C5D88_de;
extern f32 D_800CD96C[3];
extern f32 D_800CD984[3];
extern s32 D_801470A4;

s32 func_802A15E4_de(s32 arg0) {
    s32 amount;
    s32 result;

    amount = (arg0 + 7) & -8;
    D_800CD984[0] += (f32)amount;
    result = D_801470A4 - amount;
    D_801470A4 = result;
    if (D_800CD984[0] < D_800C5D88_de) {
        D_800CD984[0] = D_800C5D88_de;
    }
    if (D_800CD984[0] > *(&D_800C5D88_de + 1)) {
        D_800CD984[0] = *(&D_800C5D88_de + 1);
    }
    if (D_800CD984[0] < D_800CD984[1]) {
        D_800CD984[1] = D_800CD984[0];
    }
    if (D_800CD984[2] < D_800CD984[0]) {
        D_800CD984[2] = D_800CD984[0];
    }

    D_800CD96C[0] += (f32)-amount;
    if (D_800CD96C[0] < D_800C5D88_de) {
        D_800CD96C[0] = D_800C5D88_de;
    }
    if (*(&D_800C5D88_de + 1) < D_800CD96C[0]) {
        D_800CD96C[0] = *(&D_800C5D88_de + 1);
    }
    if (D_800CD96C[0] < D_800CD96C[1]) {
        D_800CD96C[1] = D_800CD96C[0];
    }
    if (D_800CD96C[2] < D_800CD96C[0]) {
        D_800CD96C[2] = D_800CD96C[0];
    }
    return result;
}
