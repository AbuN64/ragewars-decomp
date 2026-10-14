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
extern void func_802AE834_us_rev1(s32, s32, void *);



s32 func_802B026C_us_rev1(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    TransferScratch scratch;
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
    s32 product;
    s32 valid;

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
        func_802AE380_us_rev1(&scratch.response);
        if (D_8014D3E8 == 0) {
            valid = scratch.response == 0x11;
        }
    }
    if (valid == 0) {
        goto cleanup;
    }
    func_802AE5AC_us_rev1(0x82);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1((u32)arg3 >> 24);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1(((u32)arg3 >> 16) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1(((u32)arg3 >> 8) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1(arg3 & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    product = arg1 * arg2;
    func_802AE5AC_us_rev1((u32)product >> 24);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1(((u32)product >> 16) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1(((u32)product >> 8) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1(product & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;

    do {
        D_8014D3E8 = 0;
        func_802AE380_us_rev1(&scratch.status);
    } while (attempts-- > 0 && D_8014D3E8 != 0);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE834_us_rev1(arg0, arg1 * arg2, &scratch.output);

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
    return arg2;
}
