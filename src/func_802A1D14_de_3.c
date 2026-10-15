#include "span_1000/code_802A208C.h"
#include "span_1000/code_802A0AC4.h"

extern int D_800CD944_de[2];

int func_802A1230_de(void) {
    return D_800CD944_de[0] == D_800CD944_de[1];
}

/** Store two values in the paired global words. */
void func_802A124C_de(int first, int second) {
    D_800CD91C = first;
    D_800CD920_de = second;
}
