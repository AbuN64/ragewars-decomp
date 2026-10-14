#include "span_1000/code_802A1264.h"
extern float D_800CD970_de;
extern float D_800CD97C;
extern float D_800CD988;

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
