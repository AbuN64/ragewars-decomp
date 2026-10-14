#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802AD504.h"
#include "span_1000/code_802B8CCC.h"
#include "span_1000/code_802BCF1C.h"
#include "span_1000/code_802BD1A8.h"
#include "types.h"

extern s32 func_802AE5AC_us_rev1(s32);
extern s32 D_8014D3E8;

s32 func_802B1820_us_rev1(u8 *arg0) {
    s32 result;
    u8 value;

    result = 0;
    while (1) {
        value = *arg0++;
        func_802AE5AC_us_rev1(value);
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

u8 func_802B1888_us_rev1(void *arg0) {
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    return (((struct ObjectState2 *) ((s8 *) arg0))->unk_1);
}

void func_802B18C0_us_rev1(s16 *arg0, s32 arg1) {
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    *arg0 = arg1 & 0xFF;
}

/* Waits for the masked byte at offset 1 of a status block to equal a given value, polling only while the low two status bits func_802BDEA0_us_rev1 reports are clear, returning 1 on a match and, after D_800D3650 retries of the given poll count each, setting D_8014D3E8 and returning 0. Adapted from func_802B1A68_us_rev1 with the status address, mask, expected value and timeout reload taken from the arguments. */


extern s32 D_8014D3E8;



s32 func_802B1904_us_rev1(u8 *status, u8 mask, u32 arg2, s32 reload) {
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

extern s32 D_8014D3E8;
extern u8 D_B2000015;



s32 func_802B19C0_us_rev1(u32 arg0) {
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

/* Waits for bit 0 of the cartridge-domain status byte D_B2000015 to equal arg0, polling only while the low two status bits func_802BDEA0_us_rev1 reports are clear, returning 1 on a match and, after D_800D3650 retries of two polls each, setting D_8014D3E8 and returning 0. Adapted from func_802B19C0_us_rev1 with the timeout reload 0x4E20 changed to 1 and the mask held as a byte. */


extern s32 D_8014D3E8;
extern u8 D_B2000015;



s32 func_802B1A68_us_rev1(u32 arg0) {
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

/* Waits for bit 6 of the cartridge-domain status byte D_B2000015 to equal arg0, polling only while the low two status bits func_802BDEA0_us_rev1 reports are clear, returning 1 on a match and, after D_800D3650 retries of 0x4E21 polls each, setting D_8014D3E8 and returning 0. Adapted from func_802B19C0_us_rev1 with the mask bit 6 and the expected value held as a byte. */


extern s32 D_8014D3E8;
extern u8 D_B2000015;



s32 func_802B1B10_us_rev1(u32 arg0) {
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

/* Waits for bit 6 of the cartridge-domain status byte D_B2000011 to equal arg0, polling only while the low two status bits func_802BDEA0_us_rev1 reports are clear, returning 1 on a match and, after D_800D3650 retries of 0x4E21 polls each, setting D_8014D3E8 and returning 0. Adapted from func_802B19C0_us_rev1 with the mask bit 6 and the expected value held as a byte. */


extern s32 D_8014D3E8;
extern u8 D_B2000011;



s32 func_802B1BBC_us_rev1(u32 arg0) {
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

/* Waits for bit 1 of the cartridge-domain status byte D_B2000015 to equal arg0, polling only while the low two status bits func_802BDEA0_us_rev1 reports are clear, returning 1 on a match and, after D_800D3650 retries of 0x4E21 polls each, setting D_8014D3E8 and returning 0. Adapted from func_802B19C0_us_rev1 with the mask bit 1 and the expected value held as a byte. */


extern s32 D_8014D3E8;
extern u8 D_B2000015;



s32 func_802B1C68_us_rev1(u32 arg0) {
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

extern u8 D_8014D3E2;
extern s16 D_B2000008;


void func_802B1D14_us_rev1(s32 arg0) {
    u8 temp_v0;

    temp_v0 = (D_8014D3E2 & 0xBF) | (arg0 << 6);
    D_8014D3E2 = temp_v0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000008 = temp_v0 & 0xFF;
}

extern u8 D_8014D3E3;
extern s16 D_B200000C;
void func_802B1D6C_us_rev1(s32 arg0) {
    u8 temp_a0;
    temp_a0 = arg0 | (D_8014D3E3 & 0xF8);
    D_8014D3E3 = temp_a0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B200000C = temp_a0 & 0xFF;
}

extern u8 D_8014D3E3;
extern s16 D_B200000C;


void func_802B1DC0_us_rev1(s32 arg0) {
    u8 temp_v0;

    temp_v0 = (D_8014D3E3 & 0xF7) | (arg0 << 3);
    D_8014D3E3 = temp_v0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B200000C = temp_v0 & 0xFF;
}

extern u8 D_8014D3E1;
extern s16 D_B2000004;


void func_802B1E18_us_rev1(s32 arg0) {
    u8 temp_v0;

    temp_v0 = (D_8014D3E1 & 0xF7) | (arg0 << 3);
    D_8014D3E1 = temp_v0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000004 = temp_v0 & 0xFF;
}

extern u8 D_8014D3E1;
extern s16 D_B2000004;


void func_802B1E70_us_rev1(s32 arg0) {
    u8 temp_v0;

    temp_v0 = (D_8014D3E1 & 0xFB) | (arg0 << 2);
    D_8014D3E1 = temp_v0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000004 = temp_v0 & 0xFF;
}

extern u8 D_8014D3E1;
extern s16 D_B2000004;


void func_802B1EC8_us_rev1(s32 arg0) {
    u8 temp_v0;

    temp_v0 = (D_8014D3E1 & 0xFD) | (arg0 << 1);
    D_8014D3E1 = temp_v0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000004 = temp_v0 & 0xFF;
}

extern u8 D_8014D3E1;
extern s16 D_B2000004;
void func_802B1F20_us_rev1(s32 arg0) {
    u8 temp_a0;
    temp_a0 = arg0 | (D_8014D3E1 & 0xFE);
    D_8014D3E1 = temp_a0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000004 = temp_a0 & 0xFF;
}

extern u8 D_8014D3E2;
extern s16 D_B2000008;


void func_802B1F74_us_rev1(s32 arg0) {
    u8 temp_v0;

    temp_v0 = (D_8014D3E2 & 0xFD) | (arg0 << 1);
    D_8014D3E2 = temp_v0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000008 = temp_v0 & 0xFF;
}

extern s8 D_8014D3E0;
extern s16 D_B2000000;
void func_802B1FCC_us_rev1(s8 arg0) {
    D_8014D3E0 = arg0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000000 = arg0 & 0xFF;
}

extern u8 D_B2000015;
s32 func_802B2010_us_rev1(void) {
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    return ((u8) D_B2000015 >> 1) & 1;
}

/** Return the true result used by callers at VRAM 0x802B2048. */
int func_802B2048_us_rev1(void) {
    return 1;
}

extern s32 D_8014D3E8;
extern s32 func_802AE380_us_rev1(u8 *);


extern void func_802BD010_de(u32, u32);



s32 func_802B2050_us_rev1(void) {
    ReadWord first;
    s32 word;
    s32 result;

    func_802AE380_us_rev1(&first.byte);
    result = 0;
    if (D_8014D3E8 == 0) {
        word = first.byte << 8;
        func_802AE380_us_rev1(&first.byte);
        if (D_8014D3E8 == 0) {
            word |= first.byte;
            func_802AE380_us_rev1(&first.byte);
            word <<= 8;
            if (D_8014D3E8 == 0) {
                word |= first.byte;
                func_802AE380_us_rev1(&first.byte);
                word <<= 8;
                if (D_8014D3E8 == 0) {
                    word |= first.byte;
                    first.word = word;
                    if (word != 0) {
                        func_802BD170_de(1);
                        func_802BD2F0_de();
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

extern s32 D_8014D3E8;
extern s32 func_802AE380_us_rev1(u8 *);



s32 func_802B2134_us_rev1(void) {
    ReadWordByte first;
    s32 word;
    s32 result;

    func_802AE380_us_rev1(&first.byte);
    result = 0;
    if (D_8014D3E8 == 0) {
        word = first.byte << 8;
        func_802AE380_us_rev1(&first.byte);
        if (D_8014D3E8 == 0) {
            word |= first.byte;
            func_802AE380_us_rev1(&first.byte);
            word <<= 8;
            if (D_8014D3E8 == 0) {
                word |= first.byte;
                func_802AE380_us_rev1(&first.byte);
                word <<= 8;
                if (D_8014D3E8 == 0) {
                    word |= first.byte;
                    first.word = word;
                    func_802AE380_us_rev1(&first.value);
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

extern s32 D_8014D3E8;
extern s32 func_802AE380_us_rev1(u8 *);
extern s32 func_802AE5AC_us_rev1(s32);



s32 func_802B2214_us_rev1(void) {
    ReadWord first;
    s32 word;
    s32 result;

    func_802AE380_us_rev1(&first.byte);
    result = 0;
    if (D_8014D3E8 == 0) {
        word = first.byte << 8;
        func_802AE380_us_rev1(&first.byte);
        if (D_8014D3E8 == 0) {
            word |= first.byte;
            func_802AE380_us_rev1(&first.byte);
            word <<= 8;
            if (D_8014D3E8 == 0) {
                word |= first.byte;
                func_802AE380_us_rev1(&first.byte);
                word <<= 8;
                if (D_8014D3E8 == 0) {
                    word |= first.byte;
                    first.word = word;
                    func_802AE5AC_us_rev1(*(u8 *)first.word);
                    result = D_8014D3E8 == 0;
                }
            }
        }
    }
    return result;
}

extern s32 func_802AE5AC_us_rev1(s32);
extern s32 func_802AE380_us_rev1(u8 *);
extern s32 D_8014D3E8;

s32 func_802B22E4_us_rev1(void) {
    u8 sp10;
    s32 result;

    func_802AE5AC_us_rev1(0x10);
    result = 0;
    if (D_8014D3E8 == 0) {
        func_802AE380_us_rev1(&sp10);
        if (D_8014D3E8 == 0) {
            result = sp10 == 0x11;
        }
    }
    return result;
}
