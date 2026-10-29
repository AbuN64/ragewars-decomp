#include "COMMON/OSTASK_T.H"
#include "../include/libgultra/sp.h"

int __osSpDeviceBusy(void) {
    int flag = *(volatile int *)0xA4040010 & 0x1C;
    return flag != 0;
}
