#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802AE254.h"
#include "span_1000/code_802B8CCC.h"
#include "types.h"
/* Reads count bytes from the cartridge-domain port D_B2000021 into a buffer, waiting for bit 0x40 of D_B2000015 before each byte with D_800D3650 retries, accumulating a rotate-and-add checksum stored through the third argument and returning 1 on success. Adapted from func_802AE380_us_rev1 with the single-byte read changed to a counted loop with a checksum and the strobe registers D_B2000004 and D_B2000008 raised and lowered around it. */


extern u8 D_8014D3E1;
extern u8 D_8014D3E2;
extern u8 D_8014D3E3;
extern s32 D_8014D3E8;
extern s16 D_B2000004;
extern s16 D_B2000008;
extern s16 D_B200000C;
extern u8 D_B2000015;
extern s16 D_B2000018;
extern u8 D_B2000021;



s32 func_802AE834_us_rev1(u8 *dst, s32 count, u32 *checksum) {
    s32 timeout;
    s32 retries;
    s32 expected;
    u8 mask;
    s32 result;
    u32 sum;
    u8 control;
    u8 value;

    result = 0;
    sum = 0;
    control = D_8014D3E1 | 8;
    D_8014D3E1 = control;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000004 = control;
    control = D_8014D3E3 & 0xF8;
    D_8014D3E3 = control;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B200000C = control;
    control = D_8014D3E2 | 2;
    D_8014D3E2 = control;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000008 = control;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000018 = 0;

    if (count-- != 0) {
        mask = 0x40;
        expected = 0x40;
next:
        retries = D_800D3650;
        timeout = 0x4E20;
        do {
            do {
            } while (func_802BDEA0_us_rev1() & 3);
            if ((D_B2000015 & mask) == expected) {
                goto ready;
            }
            if (timeout-- == 0) {
                retries--;
                timeout = 0x4E20;
            }
        } while (retries > 0);
        D_8014D3E8 = 1;
ready:
        if (D_8014D3E8 != 0) {
            goto release;
        }
        do {
        } while (func_802BDEA0_us_rev1() & 3);
        sum = (sum << 1) | (sum >> 31);
        value = D_B2000021;
        *dst++ = value;
        sum += value;
        if (count-- != 0) {
            goto next;
        }
    }
    *checksum = sum;
    result = 1;
release:
    control = D_8014D3E2 & 0xFD;
    D_8014D3E2 = control;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000008 = control;
    control = D_8014D3E1 & 0xF7;
    D_8014D3E1 = control;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000004 = control;
    control = D_8014D3E3 & 0xF8;
    D_8014D3E3 = control;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B200000C = control;
    return result;
}
