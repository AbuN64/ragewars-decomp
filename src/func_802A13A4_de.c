#include "span_1000/code_802A1264.h"
#include "types.h"

extern f32 D_800C5D78_de;
extern f32 D_800CD96C[3];
extern f32 D_800CD978[3];


s32 func_802A13A4_de(s32 arg0) {
    s32 amount;
    s32 result;
    f32 value;

    amount = (arg0 + 7) & -8;
    value = D_800CD978[0] + (f32)amount;
    result = D_801470A8;
    D_801470A8 = result + amount;
    D_800CD978[0] = value;
    if (value < D_800C5D78_de) {
        D_800CD978[0] = D_800C5D78_de;
    }
    if (D_800CD978[0] > *(&D_800C5D78_de + 1)) {
        D_800CD978[0] = *(&D_800C5D78_de + 1);
    }
    if (D_800CD978[0] < D_800CD978[1]) {
        D_800CD978[1] = D_800CD978[0];
    }
    if (D_800CD978[2] < D_800CD978[0]) {
        D_800CD978[2] = D_800CD978[0];
    }

    D_800CD96C[0] += (f32)-amount;
    value = D_800CD96C[0];
    if (value < D_800C5D78_de) {
        D_800CD96C[0] = D_800C5D78_de;
    }
    if (*(&D_800C5D78_de + 1) < D_800CD96C[0]) {
        D_800CD96C[0] = *(&D_800C5D78_de + 1);
    }
    if (D_800CD96C[0] < D_800CD96C[1]) {
        D_800CD96C[1] = D_800CD96C[0];
    }
    if (D_800CD96C[2] < D_800CD96C[0]) {
        D_800CD96C[2] = D_800CD96C[0];
    }
    return result;
}
