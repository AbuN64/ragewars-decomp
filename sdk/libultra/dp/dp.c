#include "../../include/libgultra.h"
#include "COMMON/CONTREADFORMAT.H"

/* 802B7488_9.CPP */
#if defined(VERSION_DE)
unsigned char g_DpTrailingBytes[4] = { 0x30, 0x42, 0x01, 0x00 };
#endif

/* dp.c */
int __osDpDeviceBusy(void) {
    int flag = *(volatile int *)0xA410000C & 0x100;
    return flag != 0;
}
