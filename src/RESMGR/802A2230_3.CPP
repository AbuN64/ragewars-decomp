#include "include_asm.h"
#include "COMMON/STATEPAIR.H"
#include "COMMON/INTEGERSTATE14_2.H"
#include "RESMGR/802A2230_3.H"

extern int D_800CD944_de[2];

int func_802A1230_de(void) {
    return D_800CD944_de[0] == D_800CD944_de[1];
}

/** Store two values in the paired global words. */
void func_802A124C_de(int first, int second) {
    D_800CD91C = first;
    D_800CD920_de = second;
}

#if defined(VERSION_US)
INCLUDE_DATA("span_1000", rodata_unresolved_802A11A4);
#endif
