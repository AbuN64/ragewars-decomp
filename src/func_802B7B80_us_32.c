#include "span_1000/code_802B8CCC.h"
/** Read the PI status register at 0xA4600010. */
unsigned int func_802BDEA0_us_rev1(void) {
    return *(volatile unsigned int *)0xA4600010;
}
