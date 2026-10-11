#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802AE254.h"
#include "span_1000/code_802B8CCC.h"
#include "types.h"
/* Walks the arg0 byte stream arg1 times through the cartridge-domain port at D_B2000000, raising the control register mirrors D_B200000C, D_B2000008 and D_B2000004 from the D_8014D3E3/D_8014D3E2/D_8014D3E1 control bytes one strobe step at a time, then handing each stream byte to the port after the D_B2000015 ready bit has been confirmed with D_800D3650 retries each. A final D_B2000011 handshake decides the result: reaching it without a D_8014D3E8 timeout returns 0, a timeout in that last handshake returns 1, and any earlier timeout skips straight to lowering the three control mirrors again. Adapted from func_802AE5AC_us_rev1 with the byte stream loop and the mirrored D_auto_B2000014 clear and D_auto_B2000020 data write added. */



extern u8 D_8014D3E1;
extern u8 D_8014D3E2;
extern u8 D_8014D3E3;
extern s32 D_8014D3E8;
extern s16 D_B2000004;
extern s16 D_B2000008;
extern s16 D_B200000C;
extern u8 D_B2000011;
extern u8 D_B2000015;
extern s16 D_auto_B2000014;
extern s16 D_auto_B2000020;



s32 func_802AEAB4_us_rev1(u8 *stream, s32 count) {
    s32 result;
    s32 timeout;
    s32 retries;
    s32 expected;
    u8 mask;
    u8 control;
    u8 data;

    result = 0;
    retries = D_800D3650;
    mask = 0x40;
    timeout = 0x4E20;
    expected = 0x40;
    do {
        do {
        } while (func_802BDEA0_us_rev1() & 3);
        if ((D_B2000011 & mask) == expected) {
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
        control = (D_8014D3E3 & 0xF8) | 1;
        D_8014D3E3 = control;
        do {
        } while (func_802BDEA0_us_rev1() & 3);
        D_B200000C = control;
        control = D_8014D3E2 | 2;
        D_8014D3E2 = control;
        do {
        } while (func_802BDEA0_us_rev1() & 3);
        D_B2000008 = control;
        control = D_8014D3E1 | 1;
        D_8014D3E1 = control;
        do {
        } while (func_802BDEA0_us_rev1() & 3);
        D_B2000004 = control;
        do {
        } while (func_802BDEA0_us_rev1() & 3);
        D_auto_B2000014 = 0;
        while (count-- != 0) {
            mask = 0x40;
            expected = 0x40;
            retries = D_800D3650;
            timeout = 0x4E20;
            do {
                do {
                } while (func_802BDEA0_us_rev1() & 3);
                if ((D_B2000015 & mask) == expected) {
                    goto second_done;
                }
                if (timeout-- == 0) {
                    retries--;
                    timeout = 0x4E20;
                }
            } while (retries > 0);
            D_8014D3E8 = 1;
        second_done:

            if (D_8014D3E8 != 0) {
                goto cleanup;
            }
            data = *stream;
            stream++;
            do {
            } while (func_802BDEA0_us_rev1() & 3);
            D_auto_B2000020 = data;
        }
        mask = 0x40;
        expected = 0x40;
        retries = D_800D3650;
        timeout = 0x4E20;
        do {
            do {
            } while (func_802BDEA0_us_rev1() & 3);
            if ((D_B2000015 & mask) == expected) {
                goto third_done;
            }
            if (timeout-- == 0) {
                retries--;
                timeout = 0x4E20;
            }
        } while (retries > 0);
        D_8014D3E8 = 1;
    third_done:

        timeout = 0x4E20;
        mask = 0x40;
        retries = D_800D3650;
        expected = 0;
        if (D_8014D3E8 == 0) {
            do {
                do {
                } while (func_802BDEA0_us_rev1() & 3);
                if ((D_B2000011 & mask) == expected) {
                    goto fourth_done;
                }
                if (timeout-- == 0) {
                    retries--;
                    timeout = 0x4E20;
                }
            } while (retries > 0);
            D_8014D3E8 = 1;
        fourth_done:

            if (D_8014D3E8 != 0) {
                result = 1;
            }
        }
    }
cleanup:

    control = D_8014D3E1 & 0xFE;
    D_8014D3E1 = control;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000004 = control;
    control = D_8014D3E2 & 0xFD;
    D_8014D3E2 = control;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000008 = control;
    control = D_8014D3E3 & 0xF8;
    D_8014D3E3 = control;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B200000C = control;
    return result;
}
