#include "include_asm.h"

/* 802ABDBC_10.CPP */
#if defined(VERSION_DE)
unsigned char g_PickupTrailingBytesBlock1[8] = { 0x8F, 0xB9, 0x00, 0x14, 0x20, 0x0F, 0xFF, 0xFF };
#endif

/* Pickup_NoOp_de.CPP */
#if defined(VERSION_DE)
void Pickup_NoOp_de(void) {}
#endif

#if defined(VERSION_DE)
#include "TYPES.H"

s32 Pickup_ClassifyMenuCode(s32 menuCode) {
    if ((menuCode == 0x7CF) || (menuCode == 0xBB7) || (menuCode == 0xF9F) ||
        (menuCode == 0x1387) || (menuCode == 0x176F) || (menuCode == 0x1B57) ||
        (menuCode == 0x63)) {
        return 0;
    }
    if ((u32)(menuCode - 0x3E8) < 0x3E8) {
        return 1;
    }
    if ((u32)(menuCode - 0x7D0) < 0x3E8) {
        return 2;
    }
    if ((u32)(menuCode - 0xBB8) < 0x3E8) {
        return 3;
    }
    if ((u32)(menuCode - 0xFA0) < 0x3E8) {
        return 4;
    }
    if ((u32)(menuCode - 0x1388) < 0x3E8) {
        return 5;
    }
    if ((u32)(menuCode - 0x1770) < 0x3E8) {
        return 6;
    }
    return -1;
}
#endif
