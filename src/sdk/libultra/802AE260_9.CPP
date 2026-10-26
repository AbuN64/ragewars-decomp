#include "COMMON/ITEMRECAT20V1.H"
#include "sdk/OBJECTSTATE2.H"
#include "COMMON/S1_4.H"
#include "COMMON/EXTERNS_19.H"
#include "COMMON/LLDIVRESULT.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "sdk/libgultra.h"
#include "TYPES.H"
#include "sdk/OSINT/802BDEA0_2.H"
#include "sdk/libgultra/libasm_802BBC68_20.h"
#include "sdk/libgultra/libasm_802BD1A8_3.h"
#include "sdk/libgultra_inferred/802AE260_5.H"
#include "sdk/libgultra_inferred/802AE260_9.H"

#if defined(VERSION_US_REV1)
s32 Libultra_SendDebugLinkString(u8 *arg0) {
    s32 result;
    u8 value;

    result = 0;
    while (1) {
        value = *arg0++;
        Libultra_WriteDebugLinkByte(value);
        if (D_8014D3E8 != 0) {
            break;
        }
        if (value != 0) {
            continue;
        }
        result = 1;
        break;
    }
    return result;
}

u8 Libultra_ReadPortStatusByte(void *arg0) {
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    return (((struct ObjectState2 *) ((s8 *) arg0))->unk_1);
}

void Libultra_WritePortByteValue(s16 *arg0, s32 arg1) {
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    *arg0 = arg1 & 0xFF;
}

/* Waits for the masked byte at offset 1 of a status block to equal a given value, polling only while the low two status bits func_802BDEA0_us_rev1 reports are clear, returning 1 on a match and, after D_800D3650 retries of the given poll count each, setting D_8014D3E8 and returning 0. Adapted from Libultra_CheckDebugLinkAcknowledgement with the status address, mask, expected value and timeout reload taken from the arguments. */





s32 Libultra_WaitPortStatus(u8 *status, u8 mask, u32 arg2, s32 reload) {
    s32 retries;
    s32 result;
    s32 timeout;
    s32 value;
    s32 expected;

    retries = D_800D3650;
    result = 0;
    timeout = reload;
    expected = arg2 & 0xFF;
    do {
        do {
        } while (func_802BDEA0_us_rev1() & 3);
        value = mask & status[1];
        if (value == expected) {
            result = 1;
            goto done;
        }
        if (timeout-- == 0) {
            retries--;
            timeout = reload;
        }
    } while (retries > 0);
    D_8014D3E8 = 1;
done:
    return result;
}




s32 Libultra_WaitDebugLinkAcknowledgement(u32 arg0) {
    s32 retries;
    s32 result;
    s32 timeout;
    s32 mask;
    s32 value;
    s32 expected;

    retries = D_800D3650;
    mask = 1;
    result = 0;
    timeout = 0x4E20;
    expected = arg0 & 0xFF;
    do {
        do {
        } while (func_802BDEA0_us_rev1() & 3);
        value = D_B2000015 & mask;
        if (value == expected) {
            result = 1;
            goto done;
        }
        if (timeout-- == 0) {
            retries--;
            timeout = 0x4E20;
        }
    } while (retries > 0);
    D_8014D3E8 = 1;
done:
    return result;
}

/* Waits for bit 0 of the cartridge-domain status byte D_B2000015 to equal arg0, polling only while the low two status bits func_802BDEA0_us_rev1 reports are clear, returning 1 on a match and, after D_800D3650 retries of two polls each, setting D_8014D3E8 and returning 0. Adapted from Libultra_WaitDebugLinkAcknowledgement with the timeout reload 0x4E20 changed to 1 and the mask held as a byte. */





s32 Libultra_CheckDebugLinkAcknowledgement(u32 arg0) {
    s32 retries;
    s32 result;
    s32 timeout;
    u8 mask;
    s32 value;
    s32 expected;

    retries = D_800D3650;
    mask = 1;
    result = 0;
    timeout = 1;
    expected = arg0 & 0xFF;
    do {
        do {
        } while (func_802BDEA0_us_rev1() & 3);
        value = D_B2000015 & mask;
        if (value == expected) {
            result = 1;
            goto done;
        }
        if (timeout-- == 0) {
            retries--;
            timeout = 1;
        }
    } while (retries > 0);
    D_8014D3E8 = 1;
done:
    return result;
}

/* Waits for bit 6 of the cartridge-domain status byte D_B2000015 to equal arg0, polling only while the low two status bits func_802BDEA0_us_rev1 reports are clear, returning 1 on a match and, after D_800D3650 retries of 0x4E21 polls each, setting D_8014D3E8 and returning 0. Adapted from Libultra_WaitDebugLinkAcknowledgement with the mask bit 6 and the expected value held as a byte. */





s32 Libultra_WaitDebugLinkReceiveReady(u32 arg0) {
    s32 retries;
    s32 result;
    s32 timeout;
    s32 mask;
    s32 value;
    u8 expected;

    mask = 0x40;
    retries = D_800D3650;
    expected = (arg0 << 6) & 0xFF;
    result = 0;
    timeout = 0x4E20;
    do {
        do {
        } while (func_802BDEA0_us_rev1() & 3);
        value = D_B2000015 & mask;
        if (value == expected) {
            result = 1;
            goto done;
        }
        if (timeout-- == 0) {
            retries--;
            timeout = 0x4E20;
        }
    } while (retries > 0);
    D_8014D3E8 = 1;
done:
    return result;
}

/* Waits for bit 6 of the cartridge-domain status byte D_B2000011 to equal arg0, polling only while the low two status bits func_802BDEA0_us_rev1 reports are clear, returning 1 on a match and, after D_800D3650 retries of 0x4E21 polls each, setting D_8014D3E8 and returning 0. Adapted from Libultra_WaitDebugLinkAcknowledgement with the mask bit 6 and the expected value held as a byte. */





s32 Libultra_WaitDebugLinkTransmitReady(u32 arg0) {
    s32 retries;
    s32 result;
    s32 timeout;
    s32 mask;
    s32 value;
    u8 expected;

    mask = 0x40;
    retries = D_800D3650;
    expected = (arg0 << 6) & 0xFF;
    result = 0;
    timeout = 0x4E20;
    do {
        do {
        } while (func_802BDEA0_us_rev1() & 3);
        value = D_B2000011 & mask;
        if (value == expected) {
            result = 1;
            goto done;
        }
        if (timeout-- == 0) {
            retries--;
            timeout = 0x4E20;
        }
    } while (retries > 0);
    D_8014D3E8 = 1;
done:
    return result;
}

/* Waits for bit 1 of the cartridge-domain status byte D_B2000015 to equal arg0, polling only while the low two status bits func_802BDEA0_us_rev1 reports are clear, returning 1 on a match and, after D_800D3650 retries of 0x4E21 polls each, setting D_8014D3E8 and returning 0. Adapted from Libultra_WaitDebugLinkAcknowledgement with the mask bit 1 and the expected value held as a byte. */





s32 Libultra_WaitDebugLinkRequestAcknowledgement(u32 arg0) {
    s32 retries;
    s32 result;
    s32 timeout;
    s32 mask;
    s32 value;
    u8 expected;

    mask = 0x2;
    retries = D_800D3650;
    expected = (arg0 << 1) & 0xFF;
    result = 0;
    timeout = 0x4E20;
    do {
        do {
        } while (func_802BDEA0_us_rev1() & 3);
        value = D_B2000015 & mask;
        if (value == expected) {
            result = 1;
            goto done;
        }
        if (timeout-- == 0) {
            retries--;
            timeout = 0x4E20;
        }
    } while (retries > 0);
    D_8014D3E8 = 1;
done:
    return result;
}



void Libultra_SetDebugLinkEnable(s32 arg0) {
    u8 temp_v0;

    temp_v0 = (D_8014D3E2 & 0xBF) | (arg0 << 6);
    D_8014D3E2 = temp_v0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000008 = temp_v0 & 0xFF;
}

void Libultra_SetDebugLinkMode(s32 arg0) {
    u8 temp_a0;
    temp_a0 = arg0 | (D_8014D3E3 & 0xF8);
    D_8014D3E3 = temp_a0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B200000C = temp_a0 & 0xFF;
}



void Libultra_SetDebugLinkByteRequest(s32 arg0) {
    u8 temp_v0;

    temp_v0 = (D_8014D3E3 & 0xF7) | (arg0 << 3);
    D_8014D3E3 = temp_v0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B200000C = temp_v0 & 0xFF;
}



void Libultra_SetDebugLinkReceiveEnable(s32 arg0) {
    u8 temp_v0;

    temp_v0 = (D_8014D3E1 & 0xF7) | (arg0 << 3);
    D_8014D3E1 = temp_v0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000004 = temp_v0 & 0xFF;
}



void Libultra_SetDebugLinkHostRequest(s32 arg0) {
    u8 temp_v0;

    temp_v0 = (D_8014D3E1 & 0xFB) | (arg0 << 2);
    D_8014D3E1 = temp_v0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000004 = temp_v0 & 0xFF;
}



void Libultra_SetDebugLinkHandshakeBit(s32 arg0) {
    u8 temp_v0;

    temp_v0 = (D_8014D3E1 & 0xFD) | (arg0 << 1);
    D_8014D3E1 = temp_v0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000004 = temp_v0 & 0xFF;
}

void Libultra_SetDebugLinkTransmitStrobe(s32 arg0) {
    u8 temp_a0;
    temp_a0 = arg0 | (D_8014D3E1 & 0xFE);
    D_8014D3E1 = temp_a0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000004 = temp_a0 & 0xFF;
}



void Libultra_SetDebugLinkBlockTransfer(s32 arg0) {
    u8 temp_v0;

    temp_v0 = (D_8014D3E2 & 0xFD) | (arg0 << 1);
    D_8014D3E2 = temp_v0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000008 = temp_v0 & 0xFF;
}

extern s8 D_8014D3E0;
void Libultra_WriteDebugLinkDataPort(s8 arg0) {
    D_8014D3E0 = arg0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000000 = arg0 & 0xFF;
}

s32 Libultra_GetDebugLinkRequestAcknowledgement(void) {
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    return ((u8) D_B2000015 >> 1) & 1;
}

/** Return the true result used by callers at VRAM 0x802B2048. */
int func_802B2048_us_rev1(void) {
    return 1;
}

extern s32 Libultra_ReadDebugLinkByte(u8 *);


extern void func_802BD010_de(u32, u32);



s32 Libultra_ExecuteDebugLinkAddress(void) {
    ReadWord first;
    s32 word;
    s32 result;

    Libultra_ReadDebugLinkByte(&first.byte);
    result = 0;
    if (D_8014D3E8 == 0) {
        word = first.byte << 8;
        Libultra_ReadDebugLinkByte(&first.byte);
        if (D_8014D3E8 == 0) {
            word |= first.byte;
            Libultra_ReadDebugLinkByte(&first.byte);
            word <<= 8;
            if (D_8014D3E8 == 0) {
                word |= first.byte;
                Libultra_ReadDebugLinkByte(&first.byte);
                word <<= 8;
                if (D_8014D3E8 == 0) {
                    word |= first.byte;
                    first.word = word;
                    if (word != 0) {
                        func_802BD170_de(1);
                        osWritebackDCacheAll();
                        func_802BD010_de(0x80000000, 0x800000);
                        ((void (*)(void))word)();
                    }
                    result = 1;
                }
            }
        }
    }
    return result;
}




s32 Libultra_WriteDebugLinkMemoryByte(void) {
    ReadWordByte first;
    s32 word;
    s32 result;

    Libultra_ReadDebugLinkByte(&first.byte);
    result = 0;
    if (D_8014D3E8 == 0) {
        word = first.byte << 8;
        Libultra_ReadDebugLinkByte(&first.byte);
        if (D_8014D3E8 == 0) {
            word |= first.byte;
            Libultra_ReadDebugLinkByte(&first.byte);
            word <<= 8;
            if (D_8014D3E8 == 0) {
                word |= first.byte;
                Libultra_ReadDebugLinkByte(&first.byte);
                word <<= 8;
                if (D_8014D3E8 == 0) {
                    word |= first.byte;
                    first.word = word;
                    Libultra_ReadDebugLinkByte(&first.value);
                    if (D_8014D3E8 == 0) {
                        result = 1;
                        *(u8 *)first.word = first.value;
                    }
                }
            }
        }
    }
    return result;
}




s32 Libultra_ReadDebugLinkMemoryByte(void) {
    ReadWord first;
    s32 word;
    s32 result;

    Libultra_ReadDebugLinkByte(&first.byte);
    result = 0;
    if (D_8014D3E8 == 0) {
        word = first.byte << 8;
        Libultra_ReadDebugLinkByte(&first.byte);
        if (D_8014D3E8 == 0) {
            word |= first.byte;
            Libultra_ReadDebugLinkByte(&first.byte);
            word <<= 8;
            if (D_8014D3E8 == 0) {
                word |= first.byte;
                Libultra_ReadDebugLinkByte(&first.byte);
                word <<= 8;
                if (D_8014D3E8 == 0) {
                    word |= first.byte;
                    first.word = word;
                    Libultra_WriteDebugLinkByte(*(u8 *)first.word);
                    result = D_8014D3E8 == 0;
                }
            }
        }
    }
    return result;
}


s32 Libultra_HandshakeDebugLink(void) {
    u8 sp10;
    s32 result;

    Libultra_WriteDebugLinkByte(0x10);
    result = 0;
    if (D_8014D3E8 == 0) {
        Libultra_ReadDebugLinkByte(&sp10);
        if (D_8014D3E8 == 0) {
            result = sp10 == 0x11;
        }
    }
    return result;
}
#endif
