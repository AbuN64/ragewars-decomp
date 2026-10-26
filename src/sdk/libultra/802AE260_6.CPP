#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESPONSE.H"
#include "COMMON/S1_4.H"
#include "TYPES.H"
#include "sdk/OSINT/802BDEA0_2.H"

#if defined(VERSION_US_REV1)
/* Reads count bytes from the cartridge-domain port D_B2000021 into a buffer, waiting for bit 0x40 of D_B2000015 before each byte with D_800D3650 retries, accumulating a rotate-and-add checksum stored through the third argument and returning 1 on success. Adapted from Libultra_ReadDebugLinkByte with the single-byte read changed to a counted loop with a checksum and the strobe registers D_B2000004 and D_B2000008 raised and lowered around it. */





s32 Libultra_ReadDebugLinkBlock(u8 *dst, s32 count, u32 *checksum) {
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
#endif

#if defined(VERSION_US_REV1)
extern s16 D_auto_B2000014;
extern s16 D_auto_B2000020;
static inline void waitPort(u8 *port, u8 mask, u8 expected)
{
    s32 retries = D_800D3650;
    s32 timeout = 0x4E20;
    do {
        do {
        } while (func_802BDEA0_us_rev1() & 3);
        if ((*port & mask) == expected)
            return;
        if (timeout-- == 0) {
            retries--;
            timeout = 0x4E20;
        }
    } while (retries > 0);
    D_8014D3E8 = 1;
}

s32 Libultra_WriteDebugLinkBlock(u8 *stream, s32 count)
{
    s32 result = 0;
    u8 control;
    u8 data;

    waitPort(&D_B2000011, 0x40, 0x40);
    if (D_8014D3E8 == 0) {
        control = (D_8014D3E3 & 0xF8) | 1;
        D_8014D3E3 = control;
        do {} while (func_802BDEA0_us_rev1() & 3);
        D_B200000C = control;
        control = D_8014D3E2 | 2;
        D_8014D3E2 = control;
        do {} while (func_802BDEA0_us_rev1() & 3);
        D_B2000008 = control;
        control = D_8014D3E1 | 1;
        D_8014D3E1 = control;
        do {} while (func_802BDEA0_us_rev1() & 3);
        D_B2000004 = control;
        do {} while (func_802BDEA0_us_rev1() & 3);
        D_auto_B2000014 = 0;
        while (count-- != 0) {
            waitPort(&D_B2000015, 0x40, 0x40);
            if (D_8014D3E8 != 0)
                goto cleanup;
            data = *stream++;
            do {} while (func_802BDEA0_us_rev1() & 3);
            D_auto_B2000020 = data;
        }
        waitPort(&D_B2000015, 0x40, 0x40);
        if (D_8014D3E8 == 0) {
            s32 timeout = 0x4E20;
            u8 mask = 0x40;
            s32 retries = D_800D3650;
            s32 expected = 0;
            do {
                do {} while (func_802BDEA0_us_rev1() & 3);
                if ((D_B2000011 & mask) == expected)
                    goto close_ready;
                if (timeout-- == 0) {
                    retries--;
                    timeout = 0x4E20;
                }
            } while (retries > 0);
            D_8014D3E8 = 1;
close_ready:

            if (D_8014D3E8 == 0)
                result = 1;
        }
    }
cleanup:
    control = D_8014D3E1 & 0xFE;
    D_8014D3E1 = control;
    do {} while (func_802BDEA0_us_rev1() & 3);
    D_B2000004 = control;
    control = D_8014D3E2 & 0xFD;
    D_8014D3E2 = control;
    do {} while (func_802BDEA0_us_rev1() & 3);
    D_B2000008 = control;
    control = D_8014D3E3 & 0xF8;
    D_8014D3E3 = control;
    do {} while (func_802BDEA0_us_rev1() & 3);
    D_B200000C = control;
    return result;
}
#endif
