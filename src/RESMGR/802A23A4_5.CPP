#include "COMMON/RECORD.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "RESMGR/802A23A4_5.H"

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
