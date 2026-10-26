#include "COMMON/RESPONSE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "sdk/libgultra.h"

#if defined(VERSION_US_REV1)

extern s32 (*D_800D364C)(s32 arg0);

extern s32 func_802AE5AC_us_rev1(s32);
extern s32 func_802AE380_us_rev1(u8 *);

extern u8 D_800CB480;

extern void func_802AEAB4_us_rev1(s32, s32);

extern s32 func_802BD400_de(u8 *arg0);

extern void func_802AE834_us_rev1(s32, s32, void *);

s32 func_802AEE48_us_rev1(void) {
    ReadWord first;
    s32 word;
    u32 value;

    first.word = 0;
    func_802AE380_us_rev1(&first.byte);
    value = 0;
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
                    if (D_800D364C != 0) {
                        value = D_800D364C(first.word);
                    }
                    func_802AE5AC_us_rev1(value >> 24);
                    if (D_8014D3E8 == 0) {
                        func_802AE5AC_us_rev1((value >> 16) & 0xFF);
                        if (D_8014D3E8 == 0) {
                            func_802AE5AC_us_rev1((value >> 8) & 0xFF);
                            if (D_8014D3E8 == 0) {
                                func_802AE5AC_us_rev1(value & 0xFF);
                            }
                        }
                    }
                    if (D_8014D3E8 == 0) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

s32 func_802AEF84_us_rev1(void) {
    ReadWordRecAt4 first;
    u32 word;
    s32 result;
    u32 transferLength;
    u8 *data;

    result = 0;
    func_802AE380_us_rev1(&first.byte);
    data = &D_800CB480;
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
                    if (first.word >= (u32)func_802BD400_de(data)) {
                        transferLength = func_802BD400_de(data);
                    } else {
                        transferLength = first.word;
                    }
                    first.word = transferLength;
                    func_802AE5AC_us_rev1(transferLength >> 24);
                    if (D_8014D3E8 == 0) {
                        func_802AE5AC_us_rev1((transferLength >> 16) & 0xFF);
                        if (D_8014D3E8 == 0) {
                            func_802AE5AC_us_rev1((transferLength >> 8) & 0xFF);
                            if (D_8014D3E8 == 0) {
                                func_802AE5AC_us_rev1(transferLength & 0xFF);
                            }
                        }
                    }
                    func_802AEAB4_us_rev1(data, first.word);
                    if (D_8014D3E8 == 0) {
                        result = 1;
                    }
                }
            }
        }
    }
    return result;
}

s32 func_802AF0E4_us_rev1(void) {
    ReadHalfword first;
    s32 word;
    s32 result;
    u16 value;

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
                    func_802AE380_us_rev1(&first.next_byte);
                    if (D_8014D3E8 == 0) {
                        value = first.next_byte << 8;
                        func_802AE380_us_rev1(&first.next_byte);
                        if (D_8014D3E8 == 0) {
                            first.value = value | first.next_byte;
                            result = 1;
                            *(u16 *)first.word = first.value;
                        }
                    }
                }
            }
        }
    }
    return result;
}

s32 func_802AF1F0_us_rev1(void) {
    ReadWord first;
    ReadWord second;
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
                    func_802AE380_us_rev1(&second.byte);
                    if (D_8014D3E8 == 0) {
                        word = second.byte << 8;
                        func_802AE380_us_rev1(&second.byte);
                        if (D_8014D3E8 == 0) {
                            word |= second.byte;
                            func_802AE380_us_rev1(&second.byte);
                            word <<= 8;
                            if (D_8014D3E8 == 0) {
                                word |= second.byte;
                                func_802AE380_us_rev1(&second.byte);
                                word <<= 8;
                                if (D_8014D3E8 == 0) {
                                    word |= second.byte;
                                    second.word = word;
                                    result = 1;
                                    *(s32 *)first.word = second.word;
                                }
                            }
                            goto block_9;
                        }
                    }
                } else {
                    goto block_9;
                }
            }
block_9:
            ;
        }
    }
    return result;
}

s32 func_802AF33C_us_rev1(void) {
    ReadWord first;
    s32 word;
    s32 result;
    u16 value;

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
                    value = *(u16 *)first.word;
                    func_802AE5AC_us_rev1(value >> 8);
                    if (D_8014D3E8 == 0) {
                        func_802AE5AC_us_rev1(value & 0xFF);
                        result = D_8014D3E8 == 0;
                    }
                }
            }
        }
    }
    return result;
}

s32 func_802AF424_us_rev1(void) {
    ReadWord first;
    s32 word;
    s32 result;
    u32 value;

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
                    value = *(u32 *)first.word;
                    func_802AE5AC_us_rev1(value >> 24);
                    if (D_8014D3E8 == 0) {
                        func_802AE5AC_us_rev1((value >> 16) & 0xFF);
                        if (D_8014D3E8 == 0) {
                            func_802AE5AC_us_rev1((value >> 8) & 0xFF);
                            if (D_8014D3E8 == 0) {
                                func_802AE5AC_us_rev1(value & 0xFF);
                                result = D_8014D3E8 == 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return result;
}

s32 func_802AF544_us_rev1(void) {
    ReadWord first;
    ReadWord second;
    s32 word;
    s32 succeeded;
    s32 output;

    func_802AE380_us_rev1(&first.byte);
    succeeded = 0;
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
                    func_802AE380_us_rev1(&second.byte);
                    if (D_8014D3E8 == 0) {
                        word = second.byte << 8;
                        func_802AE380_us_rev1(&second.byte);
                        if (D_8014D3E8 == 0) {
                            word |= second.byte;
                            func_802AE380_us_rev1(&second.byte);
                            word <<= 8;
                            if (D_8014D3E8 == 0) {
                                word |= second.byte;
                                func_802AE380_us_rev1(&second.byte);
                                word <<= 8;
                                if (D_8014D3E8 == 0) {
                                    word |= second.byte;
                                    second.word = word;
                                    func_802AE834_us_rev1(first.word, word, &output);
                                    succeeded = D_8014D3E8 == 0;
                                }
                            }
                            goto block_9;
                        }
                    }
                } else {
                    goto block_9;
                }
            }
block_9:
            ;
        }
    }
    return succeeded;
}

s32 func_802AF6A0_us_rev1(void) {
    ReadWord first;
    ReadWord second;
    s32 word;
    s32 succeeded;

    func_802AE380_us_rev1(&first.byte);
    succeeded = 0;
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
                    func_802AE380_us_rev1(&second.byte);
                    if (D_8014D3E8 == 0) {
                        word = second.byte << 8;
                        func_802AE380_us_rev1(&second.byte);
                        if (D_8014D3E8 == 0) {
                            word |= second.byte;
                            func_802AE380_us_rev1(&second.byte);
                            word <<= 8;
                            if (D_8014D3E8 == 0) {
                                word |= second.byte;
                                func_802AE380_us_rev1(&second.byte);
                                word <<= 8;
                                if (D_8014D3E8 == 0) {
                                    word |= second.byte;
                                    second.word = word;
                                    func_802AEAB4_us_rev1(first.word, word);
                                    succeeded = D_8014D3E8 == 0;
                                }
                            }
                            goto block_9;
                        }
                    }
                } else {
                    goto block_9;
                }
            }
block_9:
            ;
        }
    }
    return succeeded;
}

s32 func_802AF7F8_us_rev1(void) {
    ReadWord first;
    ReadWord second;
    s32 word;
    s32 succeeded;
    s32 output;
    s32 addr;

    func_802AE380_us_rev1(&first.byte);
    succeeded = 0;
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
                    func_802AE380_us_rev1(&second.byte);
                    if (D_8014D3E8 == 0) {
                        word = second.byte << 8;
                        func_802AE380_us_rev1(&second.byte);
                        if (D_8014D3E8 == 0) {
                            word |= second.byte;
                            func_802AE380_us_rev1(&second.byte);
                            word <<= 8;
                            if (D_8014D3E8 == 0) {
                                word |= second.byte;
                                func_802AE380_us_rev1(&second.byte);
                                word <<= 8;
                                if (D_8014D3E8 == 0) {
                                    word |= second.byte;
                                    second.word = word;
                                    addr = 0x80100000;
                                    func_802AE834_us_rev1(addr, first.word, &output);
                                    if (D_8014D3E8 == 0 && second.word == output) {
                                        D_800D3640 = 1;
                                        succeeded = 1;
                                        D_800D3644 = 0x80100000;
                                        D_800D3648 = first.word;
                                    }
                                }
                            }
                            goto block_9;
                        }
                    }
                } else {
                    goto block_9;
                }
            }
block_9:
            ;
        }
    }
    return succeeded;
}
#endif
