#include "sdk/libgultra_inferred/802AE260_5.H"
#include "COMMON/RESPONSE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/S1_4.H"
#include "COMMON/EXTERNS_19.H"
#include "COMMON/LLDIVRESULT.H"
#include "TYPES.H"
#include "sdk/libgultra.h"
#include "TYPES.H"
#include "sdk/OSINT/pigetstatus.H"
#include "sdk/libgultra/libasm_802BBC68_20.h"
#include "sdk/libgultra/libasm_802BD1A8_3.h"
#include "sdk/libgultra_inferred/libultra_exchangedebuglinkwords.H"

#if defined(VERSION_US_REV1)



extern void Libultra_InitDebugLink(void);

extern s32 Libultra_ReadDebugLinkByte(u8 *);


extern void Libultra_ReadDebugLinkHalfword(void);

extern void Libultra_ReadDebugLinkWord(void);

extern void func_802BD010_de(u32, u32);

extern void Libultra_WriteDebugLinkHalfword(void);

extern void Libultra_WriteDebugLinkWord(void);

extern void Libultra_ReceiveDebugLinkImage(void);

extern void Libultra_DispatchDebugLinkCallback(void);

/* Sends a 0x80 command followed by two NUL-terminated strings over the handshake port and reads back a big-endian 32-bit word, returning it (zero on failure). Adapted from Libultra_ExchangeDebugLinkWord with the command 0x85 changed to 0x80, the 32-bit argument replaced by the two strings and the read retry loop removed. */





extern void Libultra_ReadDebugLinkBlock(s32, s32, void *);

extern void Libultra_WriteDebugLinkBlock(void *, s32);

extern s32 D_800D364C;

void Libultra_RunDebugLinkCommands(void) {
    CommandState state;
    u8 *command;
    u8 *address;
    u8 *callback;
    u8 *output;
    u32 word;
    u8 enabledControl;

    Libultra_InitDebugLink();
    enabledControl = D_8014D3E2 | 0x40;
    D_8014D3E2 = enabledControl;
    while (osPiGetStatus() & 3) {
    }
    D_B2000008 = enabledControl;

    command = &state.command;
    address = &state.address.byte;
    callback = &state.callback.byte;
    output = &state.output.byte;

    while (Libultra_ReadDebugLinkByte(command) != 0) {
        if (state.command != 0x10) {
            continue;
        }
        if (Libultra_WriteDebugLinkByte(0x11) == 0) {
            continue;
        }
        if (Libultra_ReadDebugLinkByte(command) == 0) {
            continue;
        }
        switch (state.command) {
        case 0x20:
            Libultra_SendDebugLinkIdentification();
            break;
        case 0x43:
            Libultra_ReceiveDebugLinkMemory();
            break;
        case 0x47:
            Libultra_SendDebugLinkMemory();
            break;
        case 0x44:
            Libultra_ReadDebugLinkByte(address);
            if (D_8014D3E8 != 0) break;
            word = state.address.byte << 8;
            Libultra_ReadDebugLinkByte(address);
            if (D_8014D3E8 != 0) break;
            word |= state.address.byte;
            Libultra_ReadDebugLinkByte(address);
            word <<= 8;
            if (D_8014D3E8 != 0) break;
            word |= state.address.byte;
            Libultra_ReadDebugLinkByte(address);
            word <<= 8;
            if (D_8014D3E8 != 0) break;
            word |= state.address.byte;
            state.address.word = word;
            Libultra_WriteDebugLinkByte(*(u8 *)word);
            break;
        case 0x45:
            Libultra_ReadDebugLinkHalfword();
            break;
        case 0x46:
            Libultra_ReadDebugLinkWord();
            break;
        case 0x22:
            Libultra_ReadDebugLinkByte(callback);
            if (D_8014D3E8 != 0) break;
            word = state.callback.byte << 8;
            Libultra_ReadDebugLinkByte(callback);
            if (D_8014D3E8 != 0) break;
            word |= state.callback.byte;
            Libultra_ReadDebugLinkByte(callback);
            word <<= 8;
            if (D_8014D3E8 != 0) break;
            word |= state.callback.byte;
            Libultra_ReadDebugLinkByte(callback);
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
            Libultra_ReadDebugLinkByte(output);
            if (D_8014D3E8 != 0) break;
            word = state.output.byte << 8;
            Libultra_ReadDebugLinkByte(output);
            if (D_8014D3E8 != 0) break;
            word |= state.output.byte;
            Libultra_ReadDebugLinkByte(output);
            word <<= 8;
            if (D_8014D3E8 != 0) break;
            word |= state.output.byte;
            Libultra_ReadDebugLinkByte(output);
            word <<= 8;
            if (D_8014D3E8 != 0) break;
            word |= state.output.byte;
            state.output.word = word;
            Libultra_ReadDebugLinkByte(&state.output.value);
            if (D_8014D3E8 == 0) {
                *(u8 *)state.output.word = state.output.value;
            }
            break;
        case 0x41:
            Libultra_WriteDebugLinkHalfword();
            break;
        case 0x42:
            Libultra_WriteDebugLinkWord();
            break;
        case 0x18:
            Libultra_ReceiveDebugLinkImage();
            break;
        case 0x23:
            Libultra_DispatchDebugLinkCallback();
            break;
        }
    }
}

u32 Libultra_ExchangeDebugLinkStrings(u8 *arg0, u8 *arg1) {
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
    } while (osPiGetStatus() & 3);

    mask = 2;
    timeout = 0x4E20;
    retries = D_800D3650;
    expected = 2;
    D_B2000004 = initial_control;
    do {
        do {
        } while (osPiGetStatus() & 3);
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
    Libultra_WriteDebugLinkByte(0x10);
    valid = 0;
    if (D_8014D3E8 == 0) {
        Libultra_ReadDebugLinkByte(&response.handshake);
        if (D_8014D3E8 == 0) {
            valid = response.handshake == 0x11;
        }
    }
    if (valid == 0) {
        goto cleanup;
    }
    Libultra_WriteDebugLinkByte(0x80);
    if (D_8014D3E8 != 0) goto cleanup;

    first = arg0;
    do {
        first_c = *first++;
        Libultra_WriteDebugLinkByte(first_c);
        if (D_8014D3E8 != 0) goto cleanup;
    } while (first_c != 0);

    second = arg1;
    do {
        second_c = *second++;
        Libultra_WriteDebugLinkByte(second_c);
        if (D_8014D3E8 != 0) goto cleanup;
    } while (second_c != 0);

    byte = &response.byte;
    Libultra_ReadDebugLinkByte(byte);
    if (D_8014D3E8 == 0) {
        word = response.byte << 8;
        Libultra_ReadDebugLinkByte(byte);
        if (D_8014D3E8 == 0) {
            word |= response.byte;
            Libultra_ReadDebugLinkByte(byte);
            word <<= 8;
            if (D_8014D3E8 == 0) {
                word |= response.byte;
                Libultra_ReadDebugLinkByte(byte);
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
    } while (osPiGetStatus() & 3);
    final_mask = 0;
    final_expected = 2;
    timeout = 0x4E20;
    retries = D_800D3650;
    D_B2000004 = final_control;
    do {
        do {
        } while (osPiGetStatus() & 3);
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
    } while (osPiGetStatus() & 3);
    D_B2000004 = cleanup_control;
    D_800D3650 = 1;
    return response.output;
}

s32 Libultra_SendDebugLinkCommand81(s32 arg0) {
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
    } while (osPiGetStatus() & 3);

    mask = 2;
    timeout = 0x4E20;
    retries = D_800D3650;
    expected = 2;
    D_B2000004 = initial_control;
    do {
        do {
        } while (osPiGetStatus() & 3);
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
    Libultra_WriteDebugLinkByte(0x10);
    valid = 0;
    if (D_8014D3E8 == 0) {
        Libultra_ReadDebugLinkByte(&scratch.response);
        if (D_8014D3E8 == 0) {
            valid = scratch.response == 0x11;
        }
    }
    if (valid == 0) {
        goto cleanup;
    }
    Libultra_WriteDebugLinkByte(0x81);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte((u32)arg0 >> 24);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte(((u32)arg0 >> 16) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte(((u32)arg0 >> 8) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte(arg0 & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;

    final_control = D_8014D3E1 & 0xFB;
    D_8014D3E1 = final_control;
    do {
    } while (osPiGetStatus() & 3);
    final_mask = 0;
    final_expected = 2;
    timeout = 0x4E20;
    retries = D_800D3650;
    D_B2000004 = final_control;
    do {
        do {
        } while (osPiGetStatus() & 3);
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
    } while (osPiGetStatus() & 3);
    D_B2000004 = cleanup_control;
    D_800D3650 = 1;
    return 0;
}

s32 Libultra_RequestDebugLinkBlock(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
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
    } while (osPiGetStatus() & 3);

    mask = 2;
    timeout = 0x4E20;
    retries = D_800D3650;
    expected = 2;
    D_B2000004 = initial_control;
    do {
        do {
        } while (osPiGetStatus() & 3);
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
    Libultra_WriteDebugLinkByte(0x10);
    valid = 0;
    if (D_8014D3E8 == 0) {
        Libultra_ReadDebugLinkByte(&scratch.response);
        if (D_8014D3E8 == 0) {
            valid = scratch.response == 0x11;
        }
    }
    if (valid == 0) {
        goto cleanup;
    }
    Libultra_WriteDebugLinkByte(0x82);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte((u32)arg3 >> 24);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte(((u32)arg3 >> 16) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte(((u32)arg3 >> 8) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte(arg3 & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    product = arg1 * arg2;
    Libultra_WriteDebugLinkByte((u32)product >> 24);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte(((u32)product >> 16) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte(((u32)product >> 8) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte(product & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;

    do {
        D_8014D3E8 = 0;
        Libultra_ReadDebugLinkByte(&scratch.status);
    } while (attempts-- > 0 && D_8014D3E8 != 0);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_ReadDebugLinkBlock(arg0, arg1 * arg2, &scratch.output);

    final_control = D_8014D3E1 & 0xFB;
    D_8014D3E1 = final_control;
    do {
    } while (osPiGetStatus() & 3);
    final_mask = 0;
    final_expected = 2;
    timeout = 0x4E20;
    retries = D_800D3650;
    D_B2000004 = final_control;
    do {
        do {
        } while (osPiGetStatus() & 3);
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
    } while (osPiGetStatus() & 3);
    D_B2000004 = cleanup_control;
    D_800D3650 = 1;
    return arg2;
}

s32 Libultra_SubmitDebugLinkBlock(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
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
    } while (osPiGetStatus() & 3);

    mask = 2;
    timeout = 0x4E20;
    retries = D_800D3650;
    expected = 2;
    D_B2000004 = initial_control;
    do {
        do {
        } while (osPiGetStatus() & 3);
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
    Libultra_WriteDebugLinkByte(0x10);
    valid = 0;
    if (D_8014D3E8 == 0) {
        Libultra_ReadDebugLinkByte(&scratch.response);
        if (D_8014D3E8 == 0) {
            valid = scratch.response == 0x11;
        }
    }
    if (valid == 0) {
        goto cleanup;
    }
    Libultra_WriteDebugLinkByte(0x83);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte((u32)arg3 >> 24);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte(((u32)arg3 >> 16) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte(((u32)arg3 >> 8) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte(arg3 & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    product = arg1 * arg2;
    Libultra_WriteDebugLinkByte((u32)product >> 24);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte(((u32)product >> 16) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte(((u32)product >> 8) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte(product & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkBlock(arg0, product);

    do {
        D_8014D3E8 = 0;
        Libultra_ReadDebugLinkByte(&scratch.status);
    } while (attempts-- > 0 && D_8014D3E8 != 0);
    if (D_8014D3E8 != 0) goto cleanup;

    final_control = D_8014D3E1 & 0xFB;
    D_8014D3E1 = final_control;
    do {
    } while (osPiGetStatus() & 3);
    final_mask = 0;
    final_expected = 2;
    timeout = 0x4E20;
    retries = D_800D3650;
    D_B2000004 = final_control;
    do {
        do {
        } while (osPiGetStatus() & 3);
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
    } while (osPiGetStatus() & 3);
    D_B2000004 = cleanup_control;
    D_800D3650 = 1;
    return arg2;
}

u32 Libultra_ExchangeDebugLinkWords(u32 arg0, u32 arg1, u32 arg2) {
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
    } while (osPiGetStatus() & 3);

    mask = 2;
    timeout = 0x4E20;
    retries = D_800D3650;
    expected = 2;
    D_B2000004 = initial_control;
    do {
        do {
        } while (osPiGetStatus() & 3);
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
    Libultra_WriteDebugLinkByte(0x10);
    valid = 0;
    if (D_8014D3E8 == 0) {
        Libultra_ReadDebugLinkByte(&response.handshake);
        if (D_8014D3E8 == 0) {
            valid = response.handshake == 0x11;
        }
    }
    if (valid == 0) {
        goto cleanup;
    }
    Libultra_WriteDebugLinkByte(0x84);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte(arg0 >> 24);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte((arg0 >> 16) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte((arg0 >> 8) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte(arg0 & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte(arg1 >> 24);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte((arg1 >> 16) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte((arg1 >> 8) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte(arg1 & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte(arg2 >> 24);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte((arg2 >> 16) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte((arg2 >> 8) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte(arg2 & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;

    output = &response.output;
    byte = &response.byte;
    do {
        D_8014D3E8 = 0;
        Libultra_ReadDebugLinkByte(byte);
        if (D_8014D3E8 == 0) {
            word = response.byte << 8;
            Libultra_ReadDebugLinkByte(byte);
            if (D_8014D3E8 == 0) {
                word |= response.byte;
                Libultra_ReadDebugLinkByte(byte);
                word <<= 8;
                if (D_8014D3E8 == 0) {
                    word |= response.byte;
                    Libultra_ReadDebugLinkByte(byte);
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
    } while (osPiGetStatus() & 3);
    final_mask = 0;
    final_expected = 2;
    timeout = 0x4E20;
    retries = D_800D3650;
    D_B2000004 = final_control;
    do {
        do {
        } while (osPiGetStatus() & 3);
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
    } while (osPiGetStatus() & 3);
    D_B2000004 = cleanup_control;
    D_800D3650 = 1;
    return response.output;
}

u32 Libultra_ExchangeDebugLinkWord(u32 arg0) {
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
    } while (osPiGetStatus() & 3);

    mask = 2;
    timeout = 0x4E20;
    retries = D_800D3650;
    expected = 2;
    D_B2000004 = initial_control;
    do {
        do {
        } while (osPiGetStatus() & 3);
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
    Libultra_WriteDebugLinkByte(0x10);
    valid = 0;
    if (D_8014D3E8 == 0) {
        Libultra_ReadDebugLinkByte(&response.handshake);
        if (D_8014D3E8 == 0) {
            valid = response.handshake == 0x11;
        }
    }
    if (valid == 0) {
        goto cleanup;
    }
    Libultra_WriteDebugLinkByte(0x85);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte(arg0 >> 24);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte((arg0 >> 16) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte((arg0 >> 8) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte(arg0 & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;

    output = &response.output;
    byte = &response.byte;
    do {
        D_8014D3E8 = 0;
        Libultra_ReadDebugLinkByte(byte);
        if (D_8014D3E8 == 0) {
            word = response.byte << 8;
            Libultra_ReadDebugLinkByte(byte);
            if (D_8014D3E8 == 0) {
                word |= response.byte;
                Libultra_ReadDebugLinkByte(byte);
                word <<= 8;
                if (D_8014D3E8 == 0) {
                    word |= response.byte;
                    Libultra_ReadDebugLinkByte(byte);
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
    } while (osPiGetStatus() & 3);
    final_mask = 0;
    final_expected = 2;
    timeout = 0x4E20;
    retries = D_800D3650;
    D_B2000004 = final_control;
    do {
        do {
        } while (osPiGetStatus() & 3);
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
    } while (osPiGetStatus() & 3);
    D_B2000004 = cleanup_control;
    D_800D3650 = 1;
    return response.output;
}

s32 Libultra_SendDebugLinkControlWord(s32 arg0) {
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
    } while (osPiGetStatus() & 3);

    mask = 2;
    timeout = 0x4E20;
    retries = D_800D3650;
    expected = 2;
    D_B2000004 = initial_control;
    do {
        do {
        } while (osPiGetStatus() & 3);
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
    Libultra_WriteDebugLinkByte(0x10);
    valid = 0;
    if (D_8014D3E8 == 0) {
        Libultra_ReadDebugLinkByte(&scratch.response);
        if (D_8014D3E8 == 0) {
            valid = scratch.response == 0x11;
        }
    }
    if (valid == 0) {
        goto cleanup;
    }
    Libultra_WriteDebugLinkByte(0xC0);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte((u32)arg0 >> 24);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte(((u32)arg0 >> 16) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte(((u32)arg0 >> 8) & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;
    Libultra_WriteDebugLinkByte(arg0 & 0xFF);
    if (D_8014D3E8 != 0) goto cleanup;

    final_control = D_8014D3E1 & 0xFB;
    D_8014D3E1 = final_control;
    do {
    } while (osPiGetStatus() & 3);
    final_mask = 0;
    final_expected = 2;
    timeout = 0x4E20;
    retries = D_800D3650;
    D_B2000004 = final_control;
    do {
        do {
        } while (osPiGetStatus() & 3);
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
    } while (osPiGetStatus() & 3);
    D_B2000004 = cleanup_control;
    D_800D3650 = 1;
    return 0;
}

s32 Libultra_SendDebugLinkControlString(u8 *arg0) {
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
    } while (osPiGetStatus() & 3);

    mask = 2;
    timeout = 0x4E20;
    retries = D_800D3650;
    expected = 2;
    D_B2000004 = initial_control;
    do {
        do {
        } while (osPiGetStatus() & 3);
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
    Libultra_WriteDebugLinkByte(0x10);
    valid = 0;
    if (D_8014D3E8 == 0) {
        Libultra_ReadDebugLinkByte(&scratch.response);
        if (D_8014D3E8 == 0) {
            valid = scratch.response == 0x11;
        }
    }
    if (valid == 0) {
        goto cleanup;
    }
    Libultra_WriteDebugLinkByte(0xC1);
    if (D_8014D3E8 != 0) goto cleanup;
    p = arg0;
    do {
        c = *p++;
        Libultra_WriteDebugLinkByte(c);
        if (D_8014D3E8 != 0) goto cleanup;
    } while (c != 0);

    final_control = D_8014D3E1 & 0xFB;
    D_8014D3E1 = final_control;
    do {
    } while (osPiGetStatus() & 3);
    final_mask = 0;
    final_expected = 2;
    timeout = 0x4E20;
    retries = D_800D3650;
    D_B2000004 = final_control;
    do {
        do {
        } while (osPiGetStatus() & 3);
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
    } while (osPiGetStatus() & 3);
    D_B2000004 = cleanup_control;
    D_800D3650 = 1;
    return 0;
}

void func_802B1554_us_rev1(void) {
}

void Libultra_SetDebugLinkCallback(int arg0) {
    D_800D364C = arg0;
}

s32 Libultra_ReceiveDebugLinkHalfword(u16 *arg0) {
    u8 sp10;
    s32 result;
    u16 high;

    Libultra_ReadDebugLinkByte(&sp10);
    result = 0;
    if (D_8014D3E8 == 0) {
        high = sp10 << 8;
        Libultra_ReadDebugLinkByte(&sp10);
        if (D_8014D3E8 == 0) {
            result = 1;
            *arg0 = high | sp10;
        }
    }
    return result;
}

s32 Libultra_ReceiveDebugLinkWord(s32 *arg0) {
    u8 sp10;
    s32 result;
    s32 word;

    Libultra_ReadDebugLinkByte(&sp10);
    result = 0;
    if (D_8014D3E8 == 0) {
        word = sp10 << 8;
        Libultra_ReadDebugLinkByte(&sp10);
        if (D_8014D3E8 == 0) {
            word |= sp10;
            Libultra_ReadDebugLinkByte(&sp10);
            word <<= 8;
            if (D_8014D3E8 == 0) {
                word |= sp10;
                Libultra_ReadDebugLinkByte(&sp10);
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

s32 Libultra_ReceiveDebugLinkString(u8 *arg0, s32 arg1) {
    s32 result;
    s32 i;
    u8 value;

    result = 0;
    i = 0;
    while (1) {
        Libultra_ReadDebugLinkByte(&value);
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

s32 Libultra_SendDebugLinkHalfword(u32 arg0)
{
  s32 result;
  result = 0;
  Libultra_WriteDebugLinkByte((arg0 >> 8) & 0xFF);
  if (D_8014D3E8 == 0)
  {
    Libultra_WriteDebugLinkByte(arg0 & 0xFF);
    result = D_8014D3E8 == 0;
  }
  return result;
}

s32 Libultra_SendDebugLinkWord(u32 arg0) {
    s32 result;

    result = 0;
    Libultra_WriteDebugLinkByte(arg0 >> 0x18);
    if (D_8014D3E8 == 0) {
        Libultra_WriteDebugLinkByte((arg0 >> 0x10) & 0xFF);
        if (D_8014D3E8 == 0) {
            Libultra_WriteDebugLinkByte((arg0 >> 8) & 0xFF);
            if (D_8014D3E8 == 0) {
                Libultra_WriteDebugLinkByte(arg0 & 0xFF);
                result = D_8014D3E8 == 0;
            }
        }
    }
    return result;
}
#endif
