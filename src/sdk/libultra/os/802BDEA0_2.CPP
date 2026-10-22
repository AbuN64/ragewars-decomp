#include "COMMON/S1_4.H"
#include "SDK/OSINT/802BDEA0_2.H"

#if defined(VERSION_US_REV1)
/** Read the PI status register at 0xA4600010. */
unsigned int func_802BDEA0_us_rev1(void) {
    return *(volatile unsigned int *)0xA4600010;
}
#endif
