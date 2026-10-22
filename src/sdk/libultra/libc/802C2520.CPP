#include "include_asm.h"
#include "SDK/EXTERNS.H"
#include "COMMON/UNUSED.H"
#include "COMMON/LLDIVRESULT.H"
#include <stdarg.h>
#include "TYPES.H"
#include "SDK/PRINTF/802C31B0.H"

#ifdef NON_MATCHING
/* 104/337 words; remaining: draft builds 355 words, the original format-spec switch and register allocation differ */
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "stddef.h"
#include "TYPES.H"
#include "stdarg.h"
unsigned char *func_802BD3C8_de(unsigned char *string, unsigned char value);
void func_802BD974_de(_Pft *px, va_list *pap, int code, unsigned char *ac);
extern u8 D_800C7AF0_de;
extern u8 D_800C7B10_de;
extern const char D_800D52B0[];
extern const char D_800D52D4[];


s32 func_802BD430_de(void *(*arg0)(void *, const char *, s32), void *arg1, const char *arg2, va_list arg3) {
    _Pft state;
    u8 buffer[32];
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s0_4;
    s32 var_s0_5;
    s32 var_s0_6;
    s32 var_s1_2;
    s32 var_s1_3;
    s32 var_s1_4;
    s32 var_s1_5;
    s32 var_s1_6;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;
    s32 var_v0_6;
    const char *var_a1;
    const char *var_s2;
    const char *var_s2_2;
    u8 *temp_v0;
    u8 var_s1;
    u8 var_v0;
    void *var_s3;

    var_s3 = arg1;
    var_a1 = arg2;
    state.nchar = 0;
loop_1:
    var_s1 = (u8) *var_a1;
    var_s2 = var_a1;
    if (var_s1 != 0) {
loop_3:
        var_s0 = var_s2 - var_a1;
        if (var_s1 != 0x25) {
            var_s2 += 1;
            var_s1 = (u8) *var_s2;
            if (var_s1 == 0) {
                goto block_5;
            }
            goto loop_3;
        }
    } else {
block_5:
        var_s0 = var_s2 - var_a1;
    }
    if (var_s0 > 0) {
        var_s3 = arg0(var_s3, var_a1, var_s0);
        if (var_s3 != NULL) {
            state.nchar += var_s0;
            goto block_9;
        }
    } else {
block_9:
        var_s2_2 = var_s2 + 1;
        if (var_s1 != 0) {
            state.flags = 0;
loop_11:
            temp_v0 = func_802BD3C8_de(&D_800C7AF0_de, (u8) *var_s2_2);
            if (temp_v0 != NULL) {
                var_s2_2 += 1;
                switch (*temp_v0) {
                case ' ': state.flags |= 1; break;
                case '+': state.flags |= 2; break;
                case '-': state.flags |= 4; break;
                case '#': state.flags |= 8; break;
                case '0': state.flags |= 16; break;
                }
                goto loop_11;
            }
            if ((u8) *var_s2_2 != 0x2A) {
                state.width = 0;
loop_22:
                if ((u32) ((u8) *var_s2_2 - 0x30) < 0xAU) {
                    if (state.width < 0x3E7) {
                        state.width = ((state.width * 0xA) + (u8) *var_s2_2) - 0x30;
                    }
                    var_s2_2 += 1;
                    goto loop_22;
                }
            } else {
                temp_a0 = va_arg(arg3, int);
                state.width = temp_a0;
                if (temp_a0 < 0) {
                    state.width = -temp_a0;
                    state.flags |= 4;
                }
                var_s2_2 += 1;
            }
            if ((u8) *var_s2_2 != 0x2E) {
                state.prec = -1;
            } else {
                var_s2_2 += 1;
                if ((u8) *var_s2_2 != 0x2A) {
                    state.prec = 0;
loop_32:
                    if ((u32) ((u8) *var_s2_2 - 0x30) < 0xAU) {
                        if (state.prec < 0x3E7) {
                            state.prec = ((state.prec * 0xA) + (u8) *var_s2_2) - 0x30;
                        }
                        var_s2_2 += 1;
                        goto loop_32;
                    }
                } else {
                    var_s2_2 += 1;
                    state.prec = va_arg(arg3, int);
                }
            }
            var_v0 = 0;
            if (func_802BD3C8_de(&D_800C7B10_de, (u8) *var_s2_2) != NULL) {
                var_v0 = (u8) *var_s2_2;
                var_s2_2 += 1;
            }
            state.qual = var_v0;
            temp_v1 = var_v0 & 0xFF;
            if (temp_v1 == 0x6C) {
                if ((u8) *var_s2_2 == temp_v1) {
                    state.qual = 0x4C;
                    var_s2_2 += 1;
                }
            }
            func_802BD974_de(&state, &arg3, (s32) (u8) *var_s2_2, buffer);
            temp_a0_2 = state.width - (state.n0 + state.nz0 + state.n1 + state.nz1 + state.n2 + state.nz2);
            state.width = temp_a0_2;
            if (!(state.flags & 4) && (temp_a0_2 > 0)) {
                var_s1_2 = temp_a0_2;
                var_v0_2 = (u32) var_s1_2 < 0x21U;
loop_42:
                var_s0_2 = 0x20;
                if (var_v0_2 != 0) {
                    var_s0_2 = var_s1_2;
                }
                if (var_s0_2 <= 0) {
                    var_s1_2 -= var_s0_2;
                    goto block_49;
                }
                var_s3 = arg0(var_s3, D_800D52B0, var_s0_2);
                var_s1_2 -= var_s0_2;
                if (var_s3 != NULL) {
                    state.nchar += var_s0_2;
block_49:
                    var_v0_2 = (u32) var_s1_2 < 0x21U;
                    if (var_s1_2 <= 0) {
                        goto block_50;
                    }
                    goto loop_42;
                }
            } else {
block_50:
                if (state.n0 > 0) {
                    var_s3 = arg0(var_s3, (const char *) buffer, state.n0);
                    if (var_s3 != NULL) {
                        state.nchar += state.n0;
                        goto block_53;
                    }
                } else {
block_53:
                    if (state.nz0 > 0) {
                        var_s1_3 = state.nz0;
                        var_v0_3 = (u32) var_s1_3 < 0x21U;
loop_55:
                        var_s0_3 = 0x20;
                        if (var_v0_3 != 0) {
                            var_s0_3 = var_s1_3;
                        }
                        if (var_s0_3 <= 0) {
                            var_s1_3 -= var_s0_3;
                            goto block_62;
                        }
                        var_s3 = arg0(var_s3, D_800D52D4, var_s0_3);
                        var_s1_3 -= var_s0_3;
                        if (var_s3 != NULL) {
                            state.nchar += var_s0_3;
block_62:
                            var_v0_3 = (u32) var_s1_3 < 0x21U;
                            if (var_s1_3 <= 0) {
                                goto block_63;
                            }
                            goto loop_55;
                        }
                    } else {
block_63:
                        if (state.n1 > 0) {
                            var_s3 = arg0(var_s3, (const char *)state.s, state.n1);
                            if (var_s3 != NULL) {
                                state.nchar += state.n1;
                                goto block_66;
                            }
                        } else {
block_66:
                            if (state.nz1 > 0) {
                                var_s1_4 = state.nz1;
                                var_v0_4 = (u32) var_s1_4 < 0x21U;
loop_68:
                                var_s0_4 = 0x20;
                                if (var_v0_4 != 0) {
                                    var_s0_4 = var_s1_4;
                                }
                                if (var_s0_4 <= 0) {
                                    var_s1_4 -= var_s0_4;
                                    goto block_75;
                                }
                                var_s3 = arg0(var_s3, D_800D52D4, var_s0_4);
                                var_s1_4 -= var_s0_4;
                                if (var_s3 != NULL) {
                                    state.nchar += var_s0_4;
block_75:
                                    var_v0_4 = (u32) var_s1_4 < 0x21U;
                                    if (var_s1_4 <= 0) {
                                        goto block_76;
                                    }
                                    goto loop_68;
                                }
                            } else {
block_76:
                                if (state.n2 > 0) {
                                    var_s3 = arg0(var_s3, (const char *)&state.s[state.n1], state.n2);
                                    if (var_s3 != NULL) {
                                        state.nchar += state.n2;
                                        goto block_79;
                                    }
                                } else {
block_79:
                                    if (state.nz2 > 0) {
                                        var_s1_5 = state.nz2;
                                        var_v0_5 = (u32) var_s1_5 < 0x21U;
loop_81:
                                        var_s0_5 = 0x20;
                                        if (var_v0_5 != 0) {
                                            var_s0_5 = var_s1_5;
                                        }
                                        if (var_s0_5 <= 0) {
                                            var_s1_5 -= var_s0_5;
                                            goto block_88;
                                        }
                                        var_s3 = arg0(var_s3, D_800D52D4, var_s0_5);
                                        var_s1_5 -= var_s0_5;
                                        if (var_s3 != NULL) {
                                            state.nchar += var_s0_5;
block_88:
                                            var_v0_5 = (u32) var_s1_5 < 0x21U;
                                            if (var_s1_5 <= 0) {
                                                goto block_89;
                                            }
                                            goto loop_81;
                                        }
                                    } else {
block_89:
                                        var_a1 = var_s2_2 + 1;
                                        if ((state.flags & 4) && (var_s1_6 = state.width, (state.width > 0))) {
                                            var_v0_6 = (u32) var_s1_6 < 0x21U;
loop_92:
                                            var_s0_6 = 0x20;
                                            if (var_v0_6 != 0) {
                                                var_s0_6 = var_s1_6;
                                            }
                                            if (var_s0_6 <= 0) {
                                                var_s1_6 -= var_s0_6;
                                                goto block_99;
                                            }
                                            var_s3 = arg0(var_s3, D_800D52B0, var_s0_6);
                                            var_s1_6 -= var_s0_6;
                                            if (var_s3 != NULL) {
                                                state.nchar += var_s0_6;
block_99:
                                                var_v0_6 = (u32) var_s1_6 < 0x21U;
                                                if (var_s1_6 <= 0) {
                                                    var_a1 = var_s2_2 + 1;
                                                    goto loop_1;
                                                }
                                                goto loop_92;
                                            }
                                        } else {
                                            goto loop_1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return state.nchar;
}
#else
INCLUDE_ASM("span_1000", func_802BD430_de);
#endif

extern size_t func_802BD400_de(const unsigned char *s);
extern void func_802BDDE0_de(_Pft *px, unsigned char code);


void func_802BD974_de(_Pft *px, va_list *pap, int code, unsigned char *ac)
{
    px->n0 = px->nz0 = px->n1 = px->nz1 = px->n2 =
        px->nz2 = 0;

    /* Standard printf dispatch reconstructed from the conversion arms;
     * original table identity/entry audit remains pending. */
    switch ((unsigned char)code) {
    case 'c': goto case_c;
    case 'd': case 'i': goto case_d;
    case 'o': case 'u': case 'x': case 'X': goto case_x;
    case 'e': case 'E': case 'f': case 'g': case 'G': goto case_e;
    case 'n': goto case_n;
    case 'p': goto case_p;
    case 's': goto case_s;
    case '%': goto case_percent;
    default: goto case_default;
    }

case_c:
    ac[px->n0++] = va_arg(*pap, int);
    return;
case_d:
    if (px->qual == 'l') {
        px->v.ll = va_arg(*pap, long);
    } else if (px->qual == 'L') {
        px->v.ll = va_arg(*pap, long long);
    } else {
        px->v.ll = va_arg(*pap, int);
    }

    if (px->qual == 'h') {
        px->v.ll = (short)px->v.ll;
    }

    if (px->v.ll < 0) {
        ac[px->n0++] = '-';
    } else if (px->flags & 2) {
        ac[px->n0++] = '+';
    } else if (px->flags & 1) {
        ac[px->n0++] = ' ';
    }

    px->s = (unsigned char *)&ac[px->n0];

    func_802BDDE0_de(px, (unsigned char)code);
    return;
case_x:
    if (px->qual == 'l') {
        px->v.ll = va_arg(*pap, long);
    } else if (px->qual == 'L') {
        px->v.ll = va_arg(*pap, long long);
    } else {
        px->v.ll = va_arg(*pap, int);
    }

    if (px->qual == 'h') {
        px->v.ll = (unsigned short)px->v.ll;
    } else if (px->qual == 0) {
        px->v.ll = (unsigned int)px->v.ll;
    }

    if (px->flags & 8) {
        ac[px->n0++] = '0';

        if ((unsigned char)code == 'x' || (unsigned char)code == 'X') {
            ac[px->n0++] = code;
        }
    }

    px->s = (unsigned char *)&ac[px->n0];
    func_802BDDE0_de(px, (unsigned char)code);
    return;
case_e:
    px->v.ld = px->qual == 'L' ? va_arg(*pap, double) : va_arg(*pap, double);

    if ((((unsigned short *)&(px->v.ld))[0] & 0x8000))
        ac[px->n0++] = '-';
    else if (px->flags & 2)
        ac[px->n0++] = '+';
    else if (px->flags & 1)
        ac[px->n0++] = ' ';

    px->s = (unsigned char *)&ac[px->n0];
    func_802BE0C0_de(px, (unsigned char)code);
    return;
case_n:
    if (px->qual == 'h') {
        *va_arg(*pap, unsigned short *) = px->nchar;
    } else if (px->qual == 'l') {
        *va_arg(*pap, unsigned long *) = px->nchar;
    } else if (px->qual == 'L') {
        *va_arg(*pap, unsigned long long *) = px->nchar;
    } else {
        *va_arg(*pap, unsigned int *) = px->nchar;
    }
    return;
case_p:
    px->v.ll = (long)va_arg(*pap, void *);
    px->s = (unsigned char *)&ac[px->n0];
    func_802BDDE0_de(px, 'x');
    return;
case_s:
    px->s = va_arg(*pap, unsigned char *);
    px->n1 = func_802BD400_de(px->s);

    if (px->prec >= 0 && px->prec < px->n1) {
        px->n1 = px->prec;
    }
    return;
case_percent:
    ac[px->n0++] = '%';
    return;
case_default:
    ac[px->n0++] = code;
}

#ifdef NON_MATCHING
/* 87/148 words; remaining: draft builds 141 words, control flow and register allocation differ from the original */
#include "TYPES.H"


extern u8 D_800D5300[];
extern u8 D_800D5314[];

extern u64 func_802C1330_de(u64 numerator, u64 divisor);
extern u64 func_802C0DA0_de(u64 numerator, u64 divisor);
extern s64 func_802C0230_de(s64 numerator, s64 denominator);
extern s64 func_802C0820_de(s64 numerator, s64 denominator);
extern void *func_802BD3A0_de(void *destination, const void *source, int count);

void func_802BDDE0_de(_Pft *px, unsigned char code) {
    u8 *table;
    s64 quotient;
    s64 remainder;
    s32 base;
    s32 slots;
    u64 value;
    s32 extra;
    char buffer[0x18];

    table = D_800D5300;
    if (code == 'X') {
        table = D_800D5314;
    }
    if (code == 'o') {
        base = 8;
    } else {
        base = 0x10;
        if (code != 'x' && code != 'X') {
            base = 10;
        }
    }
    slots = 0x18;
    value = px->v.ll;
    if ((code == 'd' || code == 'i') && px->v.ll < 0) {
        value = -value;
    }
    if (value != 0 || px->prec != 0) {
        slots--;
        buffer[slots] = table[func_802C1330_de(value, base)];
    }
    px->v.ll = func_802C0DA0_de(value, base);
    while (px->v.ll > 0) {
        if (slots <= 0) {
            break;
        }
        quotient = func_802C0230_de(px->v.ll, base);
        remainder = func_802C0820_de(px->v.ll, base);
        px->v.ll = quotient;
        slots--;
        buffer[slots] = table[remainder];
    }
    px->n1 = 0x18 - slots;
    func_802BD3A0_de(px->s, &buffer[slots], px->n1);
    if (px->n1 < px->prec) {
        px->nz0 = px->prec - px->n1;
    }
    if (px->prec < 0 && (px->flags & 0x14) == 0x10) {
        extra = (px->width - px->n0) - px->nz0 - px->n1;
        if (extra > 0) {
            px->nz0 = px->nz0 + extra;
        }
    }
}
#else
INCLUDE_ASM("span_1000", func_802BDDE0_de);
#endif
