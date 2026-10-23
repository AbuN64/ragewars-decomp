#include "include_asm.h"
#include "sdk/OBJECTSTATE2.H"
#include "TYPES.H"

#if !(defined(VERSION_DE))
s32 func_802B2378(s32 arg0) {
    if ((arg0 == 0x7CF) || (arg0 == 0xBB7) || (arg0 == 0xF9F) ||
        (arg0 == 0x1387) || (arg0 == 0x176F) || (arg0 == 0x1B57) ||
        (arg0 == 0x63)) {
        return 0;
    }
    if ((u32)(arg0 - 0x3E8) < 0x3E8) {
        return 1;
    }
    if ((u32)(arg0 - 0x7D0) < 0x3E8) {
        return 2;
    }
    if ((u32)(arg0 - 0xBB8) < 0x3E8) {
        return 3;
    }
    if ((u32)(arg0 - 0xFA0) < 0x3E8) {
        return 4;
    }
    if ((u32)(arg0 - 0x1388) < 0x3E8) {
        return 5;
    }
    if ((u32)(arg0 - 0x1770) < 0x3E8) {
        return 6;
    }
    return -1;
}
#endif

#if defined(VERSION_US)
char rodata_unresolved_802AD298[8] =
    "MRegionS";
#endif
