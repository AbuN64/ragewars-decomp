#include "COMMON/RESPONSE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/S1_4.H"
#include "TYPES.H"
#include "sdk/OSINT/802BDEA0_2.H"

#if defined(VERSION_US_REV1)
extern s8 D_8014D3E0;



s32 Libultra_InitDebugLink(void) {
    u8 enabledControl;

    D_8014D3E0 = 0;
    D_8014D3E1 = 0;
    D_8014D3E2 = 0;
    D_8014D3E3 = 0;
    D_8014D3E4 = 0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000000 = 0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000004 = 0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000008 = 0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B200000C = 0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000010 = 0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    enabledControl = D_8014D3E2 | 0x40;
    D_8014D3E2 = enabledControl;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000008 = enabledControl;
    D_8014D3E8 = 0;
    return 1;
}
#endif
