#include "span_1000/code_802A1264.h"
#include "types.h"
#include "common/unused.h"









extern s32 func_8025305C_de(s32 arg0);





extern void func_802547E4_de(void *);




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

void func_802A16F8_de(s32 arg0) {
    extern void func_802A1270_de(void);
    s32 size;

    size = (arg0 + 7) & ~7;
    D_800CD964[0] = func_8025305C_de(size);
    D_800CD964[1] = func_8025305C_de(size);
    D_80147054 = size;
    D_80147050_de = 0;
    func_802A1270_de();
    D_800CD960_de = 1;
}

void func_802A176C_de(void) {
    if (D_800CD960_de != 0) {
        func_802547E4_de(D_800CD964[0]);
        func_802547E4_de(D_800CD964[1]);
        D_800CD964[0] = 0;
        D_800CD964[1] = 0;
        D_800CD960_de = 0;
    }
}

void func_802A17C4_de(void) {
    s32 func_802A1270_de();
    D_80147050_de = 1 - D_80147050_de;
    func_802A1270_de();
}

void func_802A17F8_de(void) {
    D_80147060[++D_801470A0] = D_801470A8;
}

/** Propagate each array's boundary sample into its two wrap-around slots. */
void func_802A182C_de(void) {
    float *p0 = &D_800CD970_de;
    float *p1 = &D_800CD97C;
    float *p2 = &D_800CD988;
    float a = p0[-1];
    float b = p1[-1];
    float c = p2[-1];
    p0[0] = a;
    p0[1] = a;
    p1[0] = b;
    p1[1] = b;
    p2[0] = c;
    p2[1] = c;
}
