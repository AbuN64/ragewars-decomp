#include "include_asm.h"

#if defined(VERSION_DE)
void func_802AD2A0_de(void) {}
#endif

#if defined(VERSION_DE)
#include "TYPES.H"

s32 func_802AD2A8_de(s32 arg0) {
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
