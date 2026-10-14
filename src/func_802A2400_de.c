#include "span_1000/code_802A208C.h"

extern float D_800CDA30_de;
extern unsigned int D_801427B0;

/** Store a scalar and clear its associated global state word. */
void func_802A2400_de(float value) {
    D_800CDA30_de = value;
    D_801427B0 = 0;
}
