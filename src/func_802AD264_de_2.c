#include "span_1000/code_802AE254.h"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "types.h"
#include "sdk/libgultra.h"

extern s32 D_8014D3E8;

extern s32 (*D_800D364C)(s32 arg0);

extern s32 func_802AE5AC_us_rev1(s32);

extern u8 D_800CB480;

extern void func_802AEAB4_us_rev1(s32, s32);

extern s32 func_802BD400_de(u8 *arg0);

extern void func_802AE834_us_rev1(s32, s32, void *);

s32 func_802AEE48_us_rev1(void) {
    extern void func_802AE380_us_rev1(u8 *arg0);
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
    extern s32 func_802AE380_us_rev1(u8 *);
    ReadWordRecAt4 first;
    u32 word;
    s32 result;
    u32 var_s0;
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
                        var_s0 = func_802BD400_de(data);
                    } else {
                        var_s0 = first.word;
                    }
                    first.word = var_s0;
                    func_802AE5AC_us_rev1(var_s0 >> 24);
                    if (D_8014D3E8 == 0) {
                        func_802AE5AC_us_rev1((var_s0 >> 16) & 0xFF);
                        if (D_8014D3E8 == 0) {
                            func_802AE5AC_us_rev1((var_s0 >> 8) & 0xFF);
                            if (D_8014D3E8 == 0) {
                                func_802AE5AC_us_rev1(var_s0 & 0xFF);
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
    extern s32 func_802AE380_us_rev1(u8 *);
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
    extern s32 func_802AE380_us_rev1(u8 *);
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
    extern s32 func_802AE380_us_rev1(u8 *);
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
    extern s32 func_802AE380_us_rev1(u8 *);
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
    extern s32 func_802AE380_us_rev1(u8 *);
    ReadWord first;
    ReadWord second;
    s32 word;
    s32 var_s2;
    s32 output;

    func_802AE380_us_rev1(&first.byte);
    var_s2 = 0;
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
                                    var_s2 = D_8014D3E8 == 0;
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
    return var_s2;
}

s32 func_802AF6A0_us_rev1(void) {
    extern s32 func_802AE380_us_rev1(u8 *);
    ReadWord first;
    ReadWord second;
    s32 word;
    s32 var_s2;

    func_802AE380_us_rev1(&first.byte);
    var_s2 = 0;
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
                                    var_s2 = D_8014D3E8 == 0;
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
    return var_s2;
}

s32 func_802AF7F8_us_rev1(void) {
    extern s32 func_802AE380_us_rev1(u8 *);
    ReadWord first;
    ReadWord second;
    s32 word;
    s32 var_s2;
    s32 output;
    s32 addr;

    func_802AE380_us_rev1(&first.byte);
    var_s2 = 0;
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
                                        var_s2 = 1;
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
    return var_s2;
}
