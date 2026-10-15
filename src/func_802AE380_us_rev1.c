#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802AE254.h"
#include "span_1000/code_802B8CCC.h"
#include "types.h"


extern u8 D_8014D3E3;
extern s32 D_8014D3E8;

extern s16 D_B200000C;
extern u8 D_B2000015;



s32 func_802AE380_us_rev1(u8 *arg0) {
    s32 timeout;
    s32 retries;
    s32 expected;
    u8 mask;
    s32 result;
    u8 initial_control;
    u8 control;
    u8 final_control;
    u8 status;

    initial_control = (D_8014D3E3 & 0xF8) | 2;
    result = 0;
    D_8014D3E3 = initial_control;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B200000C = initial_control;
    control = D_8014D3E3 | 8;
    D_8014D3E3 = control;
    do {
    } while (func_802BDEA0_us_rev1() & 3);

    mask = 1;
    timeout = 0x4E20;
    retries = D_800D3650;
    expected = 1;
    D_B200000C = control;
    D_8014D3E8 = 0;
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
        do {
        } while (func_802BDEA0_us_rev1() & 3);
        *arg0 = D_B2000001;
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
