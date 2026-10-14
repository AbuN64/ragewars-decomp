#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802AE254.h"
#include "span_1000/code_802B8CCC.h"
#include "types.h"
/* Writes one byte through the cartridge-domain port at D_B2000000 with the control register D_B200000C and strobe register D_B2000004, waiting for the ready bit of D_B2000015 to set and then clear with D_800D3650 retries each, setting D_8014D3E8 on a timeout and returning 1 on success. Adapted from func_802AE380_us_rev1 with the read of D_B2000001 changed to a write of the argument through D_B2000000 and the strobe at D_B2000004 raised and lowered around the handshake, and the argument copied into a second local for the port write. */


extern u8 D_8014D3E0;
extern u8 D_8014D3E1;
extern u8 D_8014D3E3;
extern s32 D_8014D3E8;
extern s16 D_B2000000;
extern s16 D_B2000004;
extern s16 D_B200000C;
extern u8 D_B2000015;



s32 func_802AE5AC_us_rev1(s32 arg0) {
    s32 timeout;
    s32 data;
    s32 retries;
    s32 expected;
    u8 mask;
    s32 result;
    u8 initial_control;
    u8 control;
    u8 final_control;
    u8 strobe;
    u8 status;

    initial_control = (D_8014D3E3 & 0xF8) | 3;
    result = 0;
    D_8014D3E3 = initial_control;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B200000C = initial_control;
    D_8014D3E0 = arg0;
    data = arg0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000000 = (u8)data;
    strobe = D_8014D3E1 | 1;
    D_8014D3E1 = strobe;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000004 = strobe;
    control = D_8014D3E3 | 8;
    D_8014D3E3 = control;
    do {
    } while (func_802BDEA0_us_rev1() & 3);

    mask = 1;
    timeout = 0x4E20;
    retries = D_800D3650;
    expected = 1;
    D_B200000C = control;
    do {
        do {
        } while (func_802BDEA0_us_rev1() & 3);
        if ((D_B2000015 & mask) == expected) {
            goto first_done;
        }
        if (timeout-- == 0) {
            retries--;
            timeout = 0x4E20;
        }
    } while (retries > 0);
    D_8014D3E8 = 1;
first_done:

    if (D_8014D3E8 == 0) {
        control = D_8014D3E3 & 0xF7;
        D_8014D3E3 = control;
        do {
        } while (func_802BDEA0_us_rev1() & 3);

        expected = 1;
        retries = D_800D3650;
        timeout = 0x4E20;
        D_B200000C = control;
        do {
            do {
            } while (func_802BDEA0_us_rev1() & 3);
            status = D_B2000015 & expected;
            if (status == 0) {
                goto second_done;
            }
            if (timeout-- == 0) {
                retries--;
                timeout = 0x4E20;
            }
        } while (retries > 0);
        D_8014D3E8 = 1;
second_done:

        if (D_8014D3E8 == 0) {
            strobe = D_8014D3E1 & 0xFE;
            D_8014D3E1 = strobe;
            do {
            } while (func_802BDEA0_us_rev1() & 3);
            D_B2000004 = strobe;
            final_control = D_8014D3E3 & 0xF8;
            D_8014D3E3 = final_control;
            do {
            } while (func_802BDEA0_us_rev1() & 3);
            D_B200000C = final_control;
            result = 1;
        }
    }
    return result;
}
