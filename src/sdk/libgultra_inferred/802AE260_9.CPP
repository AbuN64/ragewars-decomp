#include "span_1000/code_802AE254.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B8CCC.h"
#include "span_1000/code_802BCF1C.h"
#include "MAIN/802BD1A8.H"
#include "TYPES.H"
#include "sdk/libgultra.h"
#include "libasm_802BD1A8.h"

extern u8 D_8014D3E2;

extern s32 D_8014D3E8;

extern s16 D_B2000008;

extern void func_802AE260_us_rev1(void);

extern s32 func_802AE380_us_rev1(u8 *);

extern s32 func_802AE5AC_us_rev1(s32);

extern void func_802AF33C_us_rev1(void);

extern void func_802AF424_us_rev1(void);

extern void func_802BD010_de(u32, u32);

extern void func_802AF0E4_us_rev1(void);

extern void func_802AF1F0_us_rev1(void);

extern void func_802AF7F8_us_rev1(void);

extern void func_802AEE48_us_rev1(void);

/* Sends a 0x80 command followed by two NUL-terminated strings over the handshake port and reads back a big-endian 32-bit word, returning it (zero on failure). Adapted from func_802B0D3C_us_rev1 with the command 0x85 changed to 0x80, the 32-bit argument replaced by the two strings and the read retry loop removed. */


extern u8 D_8014D3E1;

extern s16 D_B2000004;

extern u8 D_B2000015;

extern void func_802AE834_us_rev1(s32, s32, void *);

extern void func_802AEAB4_us_rev1(void *, s32);

extern s32 D_800D364C;

void func_802AF990_us_rev1(void) {
    CommandState state;
    u8 *command;
    u8 *address;
    u8 *callback;
    u8 *output;
    u32 word;
    u8 temp_v0;

    func_802AE260_us_rev1();
    temp_v0 = D_8014D3E2 | 0x40;
    D_8014D3E2 = temp_v0;
    while (func_802BDEA0_us_rev1() & 3) {
    }
    D_B2000008 = temp_v0;

    command = &state.command;
    address = &state.address.byte;
    callback = &state.callback.byte;
    output = &state.output.byte;

    while (func_802AE380_us_rev1(command) != 0) {
        if (state.command != 0x10) {
            continue;
        }
        if (func_802AE5AC_us_rev1(0x11) == 0) {
            continue;
        }
        if (func_802AE380_us_rev1(command) == 0) {
            continue;
        }
        switch (state.command) {
        case 0x20:
            func_802AEF84_us_rev1();
            break;
        case 0x43:
            func_802AF544_us_rev1();
            break;
        case 0x47:
            func_802AF6A0_us_rev1();
            break;
        case 0x44:
            func_802AE380_us_rev1(address);
            if (D_8014D3E8 != 0) break;
            word = state.address.byte << 8;
            func_802AE380_us_rev1(address);
            if (D_8014D3E8 != 0) break;
            word |= state.address.byte;
            func_802AE380_us_rev1(address);
            word <<= 8;
            if (D_8014D3E8 != 0) break;
            word |= state.address.byte;
            func_802AE380_us_rev1(address);
            word <<= 8;
            if (D_8014D3E8 != 0) break;
            word |= state.address.byte;
            state.address.word = word;
            func_802AE5AC_us_rev1(*(u8 *)word);
            break;
        case 0x45:
            func_802AF33C_us_rev1();
            break;
        case 0x46:
            func_802AF424_us_rev1();
            break;
        case 0x22:
            func_802AE380_us_rev1(callback);
            if (D_8014D3E8 != 0) break;
            word = state.callback.byte << 8;
            func_802AE380_us_rev1(callback);
            if (D_8014D3E8 != 0) break;
            word |= state.callback.byte;
            func_802AE380_us_rev1(callback);
            word <<= 8;
            if (D_8014D3E8 != 0) break;
            word |= state.callback.byte;
            func_802AE380_us_rev1(callback);
            word <<= 8;
            if (D_8014D3E8 != 0) break;
            word |= state.callback.byte;
            state.callback.word = word;
            if (word != 0) {
                func_802BD170_de(1);
                osWritebackDCacheAll();
                func_802BD010_de(0x80000000, 0x800000);
                ((void (*)(void))word)();
            }
            break;
        case 0x40:
            func_802AE380_us_rev1(output);
            if (D_8014D3E8 != 0) break;
            word = state.output.byte << 8;
            func_802AE380_us_rev1(output);
            if (D_8014D3E8 != 0) break;
            word |= state.output.byte;
            func_802AE380_us_rev1(output);
            word <<= 8;
            if (D_8014D3E8 != 0) break;
            word |= state.output.byte;
            func_802AE380_us_rev1(output);
            word <<= 8;
            if (D_8014D3E8 != 0) break;
            word |= state.output.byte;
            state.output.word = word;
            func_802AE380_us_rev1(&state.output.value);
            if (D_8014D3E8 == 0) {
                *(u8 *)state.output.word = state.output.value;
            }
            break;
        case 0x41:
            func_802AF0E4_us_rev1();
            break;
        case 0x42:
            func_802AF1F0_us_rev1();
            break;
        case 0x18:
            func_802AF7F8_us_rev1();
            break;
        case 0x23:
            func_802AEE48_us_rev1();
            break;
        }
    }
}

u32 func_802AFCE4_us_rev1(u8 *arg0, u8 *arg1) {
    Response response;
    s32 timeout;
    s32 retries;
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
    u8 *second;
    u8 second_c;
    u8 *first;
    u8 first_c;

    response.output = 0;
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
        func_802AE380_us_rev1(&response.handshake);
        if (D_8014D3E8 == 0) {
            valid = response.handshake == 0x11;
        }
    }
    if (valid == 0) {
        goto cleanup;
    }
    func_802AE5AC_us_rev1(0x80);
    if (D_8014D3E8 != 0) goto cleanup;

    first = arg0;
    do {
        first_c = *first++;
        func_802AE5AC_us_rev1(first_c);
        if (D_8014D3E8 != 0) goto cleanup;
    } while (first_c != 0);

    second = arg1;
    do {
        second_c = *second++;
        func_802AE5AC_us_rev1(second_c);
        if (D_8014D3E8 != 0) goto cleanup;
    } while (second_c != 0);

    byte = &response.byte;
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
                    response.output = word;
                }
            }
        }
    }
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

s32 func_802AFFEC_us_rev1(s32 arg0) {
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
    func_802AE5AC_us_rev1(0x81);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1((u32)arg0 >> 24);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1(((u32)arg0 >> 16) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1(((u32)arg0 >> 8) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1(arg0 & 0xFF);
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
    return 0;
}

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

s32 func_802B05C8_us_rev1(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
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
    func_802AE5AC_us_rev1(0x83);
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
    func_802AEAB4_us_rev1(arg0, product);

    do {
        D_8014D3E8 = 0;
        func_802AE380_us_rev1(&scratch.status);
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
    return arg2;
}

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

u32 func_802B0D3C_us_rev1(u32 arg0) {
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
    func_802AE5AC_us_rev1(0x85);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1(arg0 >> 24);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1((arg0 >> 16) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1((arg0 >> 8) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1(arg0 & 0xFF);
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

s32 func_802B1088_us_rev1(s32 arg0) {
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
    func_802AE5AC_us_rev1(0xC0);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1((u32)arg0 >> 24);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1(((u32)arg0 >> 16) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1(((u32)arg0 >> 8) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    func_802AE5AC_us_rev1(arg0 & 0xFF);
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
    return 0;
}

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

void func_802B155C_us_rev1(int arg0) {
    D_800D364C = arg0;
}

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
