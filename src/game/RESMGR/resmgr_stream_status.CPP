#include "include_asm.h"
#include "COMMON/STATEPAIR.H"
#include "COMMON/INTEGERSTATE14_2.H"
#include "RESMGR/resmgr_stream_status.H"

int Resmgr_IsMemoryStreamAtEnd(void) {
    return D_800CD940_de.cursor == D_800CD940_de.size;
}

/** Store two values in the paired global words. */
void func_802A124C_de(int first, int second) {
    D_800CD91C = first;
    D_800CD920_de = second;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_802A11A4[3] = {
    0x43000000, 0x10000B00, 0x00000000,
};
#endif
