#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802AE254.h"
#include "span_1000/code_802B8CCC.h"
#include "types.h"

/* Sends the 0xC1 command followed by a NUL-terminated string, terminator included, over the handshake port after a 0x10/0x11 greeting, then waits for the port to go idle and releases it, returning 0. Adapted from func_802B1088_us_rev1 with the command byte 0xC0 changed to 0xC1 and the four address bytes changed to a loop over the string bytes. */


extern u8 D_8014D3E1;
extern s32 D_8014D3E8;
extern s16 D_B2000004;
extern u8 D_B2000015;


extern s32 func_802AE5AC_us_rev1(s32);
extern s32 func_802AE380_us_rev1(u8 *);



s32 func_802B1308_us_rev1(u8 *arg0) {
    u8 *p;
    u8 c;
    TransferScratch scratch;
    s32 timeout;
    s32 retries;
    u8 initial_control;
    s32 expected;
    u8 mask;
    u8 final_control;
    u8 cleanup_control;
    s32 final_expected;
    u8 final_mask;
    s32 valid;

    D_8014D3E8 = 0;
    D_800D3650 = 100;
    initial_control = D_8014D3E1 | 4;
    D_8014D3E1 = initial_control;
    do {
    } while (func_802BDEA0_us_rev1() & 3);

    mask = 2;
    timeout = 0x4E20;
    retries = D_800D3650;
    expected = 2;
    D_B2000004 = initial_control;
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
        goto cleanup;
    }
    func_802AE5AC_us_rev1(0x10);
    valid = 0;
    if (D_8014D3E8 == 0) {
        func_802AE380_us_rev1(&scratch.response);
        if (D_8014D3E8 == 0) {
            valid = scratch.response == 0x11;
        }
    }
    if (valid == 0) {
        goto cleanup;
    }
    func_802AE5AC_us_rev1(0xC1);
    if (D_8014D3E8 != 0) goto cleanup;
    p = arg0;
    do {
        c = *p++;
        func_802AE5AC_us_rev1(c);
        if (D_8014D3E8 != 0) goto cleanup;
    } while (c != 0);

    final_control = D_8014D3E1 & 0xFB;
    D_8014D3E1 = final_control;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    final_mask = 0;
    final_expected = 2;
    timeout = 0x4E20;
    retries = D_800D3650;
    D_B2000004 = final_control;
    do {
        do {
        } while (func_802BDEA0_us_rev1() & 3);
        if ((D_B2000015 & final_expected) == final_mask) {
            goto cleanup;
        }
        if (timeout-- == 0) {
            retries--;
            timeout = 0x4E20;
        }
    } while (retries > 0);
    D_8014D3E8 = 1;

cleanup:
    cleanup_control = D_8014D3E1 & 0xFB;
    D_8014D3E1 = cleanup_control;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000004 = cleanup_control;
    D_800D3650 = 1;
    return 0;
}

void func_802B1554_us_rev1(void) {
}

extern s32 D_800D364C;
void func_802B155C_us_rev1(int arg0) {
    D_800D364C = arg0;
}

extern s32 func_802AE380_us_rev1(u8 *);
extern s32 D_8014D3E8;

s32 func_802B156C_us_rev1(u16 *arg0) {
    u8 sp10;
    s32 result;
    u16 high;

    func_802AE380_us_rev1(&sp10);
    result = 0;
    if (D_8014D3E8 == 0) {
        high = sp10 << 8;
        func_802AE380_us_rev1(&sp10);
        if (D_8014D3E8 == 0) {
            result = 1;
            *arg0 = high | sp10;
        }
    }
    return result;
}

extern s32 func_802AE380_us_rev1(u8 *);
extern s32 D_8014D3E8;

s32 func_802B15EC_us_rev1(s32 *arg0) {
    u8 sp10;
    s32 result;
    s32 word;

    func_802AE380_us_rev1(&sp10);
    result = 0;
    if (D_8014D3E8 == 0) {
        word = sp10 << 8;
        func_802AE380_us_rev1(&sp10);
        if (D_8014D3E8 == 0) {
            word |= sp10;
            func_802AE380_us_rev1(&sp10);
            word <<= 8;
            if (D_8014D3E8 == 0) {
                word |= sp10;
                func_802AE380_us_rev1(&sp10);
                word <<= 8;
                if (D_8014D3E8 == 0) {
                    result = 1;
                    word |= sp10;
                    *arg0 = word;
                }
            }
        }
    }
    return result;
}

extern s32 func_802AE380_us_rev1(u8 *);
extern s32 D_8014D3E8;

s32 func_802B16B4_us_rev1(u8 *arg0, s32 arg1) {
    s32 result;
    s32 i;
    u8 value;

    result = 0;
    i = 0;
    while (1) {
        func_802AE380_us_rev1(&value);
        if (D_8014D3E8 != 0) {
            break;
        }
        if (i < arg1) {
            arg0[i] = value;
        }
        i += 1;
        if (value != 0) {
            continue;
        }
        result = 1;
        break;
    }
    return result;
}

extern s32 func_802AE5AC_us_rev1(s32);
extern s32 D_8014D3E8;
s32 func_802B1734_us_rev1(u32 arg0)
{
  s32 result;
  result = 0;
  func_802AE5AC_us_rev1((arg0 >> 8) & 0xFF);
  if (D_8014D3E8 == 0)
  {
    func_802AE5AC_us_rev1(arg0 & 0xFF);
    result = D_8014D3E8 == 0;
  }
  return result;
}

extern s32 func_802AE5AC_us_rev1(s32);
extern s32 D_8014D3E8;

s32 func_802B1790_us_rev1(u32 arg0) {
    s32 result;

    result = 0;
    func_802AE5AC_us_rev1(arg0 >> 0x18);
    if (D_8014D3E8 == 0) {
        func_802AE5AC_us_rev1((arg0 >> 0x10) & 0xFF);
        if (D_8014D3E8 == 0) {
            func_802AE5AC_us_rev1((arg0 >> 8) & 0xFF);
            if (D_8014D3E8 == 0) {
                func_802AE5AC_us_rev1(arg0 & 0xFF);
                result = D_8014D3E8 == 0;
            }
        }
    }
    return result;
}
