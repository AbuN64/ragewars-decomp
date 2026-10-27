#include "sdk/libgultra.h"
#include "COMMON/CONTREADFORMAT.H"

/* 802B7488_9.CPP */
#if defined(VERSION_DE)
unsigned char D_auto_func_802B7C2C_de_padding_B882C[4] = { 0x30, 0x42, 0x01, 0x00 };
#endif

/* dp.c */
int __osDpDeviceBusy(void) {
    int flag = *(volatile int *)0xA410000C & 0x100;
    return flag != 0;
}
