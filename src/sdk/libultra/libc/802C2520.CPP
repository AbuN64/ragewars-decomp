#include "include_asm.h"
#include "SDK/EXTERNS.H"
#include "COMMON/UNUSED.H"
#include "COMMON/LLDIVRESULT.H"
#include <stdarg.h>
#include "TYPES.H"
#include "SDK/PRINTF/802C31B0.H"

#if defined(VERSION_US_REV1)
/* _Printf core of the SDK: scans the format, parses flags, width, precision and size qualifier, and emits each field through prout. */
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


/* va_arg(ap, int) as this SDK expands it: load at the aligned cursor, then advance it. */
#define PRINTF_VA_INT(ap) ({ int _v = *(int *)((((unsigned int)(ap) + 3) & -4)); ap = (va_list)((((unsigned int)(ap) + 3) & -4) + 4); _v; })
#define PRINTF_PUT(s, n) \
    if (0 < (n)) { \
        arg = (*prout)(arg, (const char *)(s), (n)); \
        if (arg != 0) { \
            x.nchar += (n); \
        } else { \
            return x.nchar; \
        } \
    }
#define PRINTF_PAD(m, s, n) \
    if (0 < (n)) { \
        int i, j = (n); \
        for (; 0 < j; j -= i) { \
            i = ((unsigned int)j <= (m)) ? j : (m); \
            PRINTF_PUT(s, i); \
        } \
    }
extern unsigned int D_auto_data_unresolved_800CCD48[];
s32 Libc_FormatToCallback(void *(*prout)(void *, const char *, s32), void *arg, const char *fmt, va_list ap) {
    _Pft x;
    x.nchar = 0;
    for (;;) {
        const unsigned char *s = (const unsigned char *)fmt;
        unsigned char c;
        int n;
        unsigned char *t;
        unsigned char *fchar;
        unsigned int *fbit;
        unsigned char ac[32];
        while ((c = *s) != 0 && c != 0x25) ++s;
        n = s - (const unsigned char *)fmt;
        PRINTF_PUT(fmt, n);
        if (c == 0) {
            return x.nchar;
        }
        ++s;
        for (x.flags = 0, fchar = &D_800C7AF0_de, fbit = D_auto_data_unresolved_800CCD48; (t = func_802BD3C8_de(fchar, *s)) != 0; ++s) {
            x.flags |= fbit[t - fchar];
        }
        if (*s == 0x2A) {
            x.width = PRINTF_VA_INT(ap);
            if (x.width < 0) {
                x.width = -x.width;
                x.flags |= 4;
            }
            ++s;
        } else {
            for (x.width = 0; (*s >= 0x30 && *s <= 0x39); ++s) {
                if (x.width < 999) {
                    x.width = x.width * 10 + *s - 0x30;
                }
            }
        }
        if (*s != 0x2E) {
            x.prec = -1;
        } else if (*++s == 0x2A) {
            x.prec = PRINTF_VA_INT(ap);
            ++s;
        } else {
            for (x.prec = 0; (*s >= 0x30 && *s <= 0x39); ++s) {
                if (x.prec < 999) {
                    x.prec = x.prec * 10 + *s - 0x30;
                }
            }
        }
        x.qual = func_802BD3C8_de(&D_800C7B10_de, *s) ? *s++ : 0;
        if (x.qual == 0x6C && *s == 0x6C) {
            x.qual = 0x4C;
            ++s;
        }
        func_802BD974_de(&x, &ap, *s, ac);
        x.width -= x.n0 + x.nz0 + x.n1 + x.nz1 + x.n2 + x.nz2;
        if (!(x.flags & 4)) {
            PRINTF_PAD(32, D_800D52B0, x.width);
        }
        PRINTF_PUT(ac, x.n0);
        PRINTF_PAD(32, D_800D52D4, x.nz0);
        PRINTF_PUT(x.s, x.n1);
        PRINTF_PAD(32, D_800D52D4, x.nz1);
        PRINTF_PUT(x.s + x.n1, x.n2);
        PRINTF_PAD(32, D_800D52D4, x.nz2);
        if (x.flags & 4) {
            PRINTF_PAD(32, D_800D52B0, x.width);
        }
        fmt = (const char *)s + 1;
    }
}

#else
INCLUDE_ASM("span_1000", Libc_FormatToCallback);
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
#include "TYPES.H"


extern u8 D_800D5300[];
extern u8 D_800D5314[];

extern u64 func_802C1330_de(u64 numerator, u64 divisor);
extern u64 func_802C0DA0_de(u64 numerator, u64 divisor);
extern s64 func_802C0230_de(s64 numerator, s64 denominator);
extern s64 func_802C0820_de(s64 numerator, s64 denominator);
extern void *func_802BD3A0_de(void *destination, const void *source, int count);

static inline void lldivInline(LldivResult *result, s64 numerator, s64 denominator) {
    result->quot = func_802C0230_de(numerator, denominator);
    result->rem = func_802C0820_de(numerator, denominator);
}
/* Formats px->v.ll into px->s in the radix selected by code (o/x/X/d/i/u), zero-padding to the precision.
 * 145/148 words; remaining: the first digit is looked up through v1 instead of v0 (register choice only). */
void func_802BDDE0_de(_Pft *px, unsigned char code) {
    char buffer[0x18];
    const u8 *table;
     LldivResult qr;
    s32 base;
    s32 i;
    u64 value;
    s64 num, den;
    char *p;
    table = D_800D5300;
    if (code == 0x58) {
        table = D_800D5314;
    }
    base = (code == 0x6F) ? 8 : ((code != 0x78 && code != 0x58) ? 10 : 16);
    i = 0x18;
    value = px->v.ll;
    if ((code == 0x64 || code == 0x69) && px->v.ll < 0) {
        value = -value;
    }
    if (value != 0 || px->prec != 0) {
        p = &buffer[--i];
        *p = table[func_802C1330_de(value, base)];
    }
    px->v.ll = func_802C0DA0_de(value, base);
    while (px->v.ll > 0 && i > 0) {
        num = px->v.ll;
        den = base;
        lldivInline(&qr, num, den);
        px->v.ll = qr.quot;
        buffer[--i] = table[qr.rem];
    }
    px->n1 = 0x18 - i;
    func_802BD3A0_de(px->s, &buffer[i], px->n1);
    if (px->n1 < px->prec) {
        px->nz0 = px->prec - px->n1;
    }
    if (px->prec < 0 && (px->flags & 0x14) == 0x10) {
        i = (px->width - px->n0) - px->nz0 - px->n1;
        if (i > 0) {
            px->nz0 = px->nz0 + i;
        }
    }
}
#else
INCLUDE_ASM("span_1000", func_802BDDE0_de);
#endif
