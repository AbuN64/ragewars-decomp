#include "sdk/libgultra.h"
#include "span_1000/code_802B7488.h"
int __osDpDeviceBusy(void) {
    int flag = *(volatile int *)0xA410000C & 0x100;
    return flag != 0;
}
