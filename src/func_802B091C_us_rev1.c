#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802AE254.h"
#include "span_1000/code_802B8CCC.h"
#include "types.h"


extern u8 D_8014D3E1;
extern s32 D_8014D3E8;
extern s16 D_B2000004;
extern u8 D_B2000015;


extern s32 func_802AE5AC_us_rev1(s32);
extern s32 func_802AE380_us_rev1(u8 *);



u32 func_802B091C_us_rev1(u32 arg0, u32 arg1, u32 arg2) {
    Response response;
    s32 timeout;
    s32 retries;
    s32 attempts;
    u8 initial_control;
    s32 expected;
    u8 mask;
    u8 final_control;
    u8 cleanup_control;
    s32 final_expected;
    u8 final_mask;
    u32 word;
    s32 valid;
    u8 *byte;
    u32 *output;

    response.output = 0;
    D_8014D3E8 = 0;
    attempts = 100;
    D_800D3650 = attempts;
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
        func_802AE380_us_rev1(&response.handshake);
        if (D_8014D3E8 == 0) {
            valid = response.handshake == 0x11;
        }
    }
    if (valid == 0) {
        goto cleanup;
    }
    func_802AE5AC_us_rev1(0x84);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1(arg0 >> 24);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1((arg0 >> 16) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1((arg0 >> 8) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1(arg0 & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1(arg1 >> 24);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1((arg1 >> 16) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1((arg1 >> 8) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1(arg1 & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1(arg2 >> 24);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1((arg2 >> 16) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1((arg2 >> 8) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1(arg2 & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;

    output = &response.output;
    byte = &response.byte;
    do {
        D_8014D3E8 = 0;
        func_802AE380_us_rev1(byte);
        if (D_8014D3E8 == 0) {
            word = response.byte << 8;
            func_802AE380_us_rev1(byte);
            if (D_8014D3E8 == 0) {
                word |= response.byte;
                func_802AE380_us_rev1(byte);
                word <<= 8;
                if (D_8014D3E8 == 0) {
                    word |= response.byte;
                    func_802AE380_us_rev1(byte);
                    word <<= 8;
                    if (D_8014D3E8 == 0) {
                        word |= response.byte;
                        *output = word;
                    }
                }
            }
        }
    } while (attempts-- > 0 && D_8014D3E8 != 0);
    if (D_8014D3E8 != 0) goto cleanup;

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
    return response.output;
}
