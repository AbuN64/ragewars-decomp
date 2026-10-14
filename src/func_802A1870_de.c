#include "span_1000/code_802A1264.h"
extern unsigned int D_800CD990_de;
extern unsigned int D_800CD994;
extern unsigned int D_800CD998;
extern unsigned int D_800CD99C;

/** Store four arguments in the adjacent global state words. */
void func_802A1870_de(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3) {
    D_800CD990_de = a0;
    D_800CD994 = a1;
    D_800CD998 = a2;
    D_800CD99C = a3;
}
