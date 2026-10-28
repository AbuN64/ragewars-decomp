#include "COMMON/S1_4.H"
#include "sdk/OSINT/802BDEA0_2.H"

#if defined(VERSION_US_REV1)
/** Read the PI status register at 0xA4600010. */
unsigned int osPiGetStatus(void) {
    return *(volatile unsigned int *)0xA4600010;
}
#endif
