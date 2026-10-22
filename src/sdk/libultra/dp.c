#include "sdk/libgultra.h"
#include "COMMON/CONTREADFORMAT.H"

int __osDpDeviceBusy(void) {
    int flag = *(volatile int *)0xA410000C & 0x100;
    return flag != 0;
}
