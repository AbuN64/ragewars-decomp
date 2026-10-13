#include "span_1000/code_8029BBA0.h"
#include "span_C76B0/data.h"
#include "types.h"
extern f64 D_800E1118;
extern f64 D_800E1130;
extern f64 D_800E1148;
extern f64 D_800E11F0;

s32 func_80414400_de(u8 *buf, f64 value, s32 ch, s32 width, s32 precision) {
    u8 fraction[128];
    u8 integer[128];
    u8 exponent[16];
    f64 whole, digit, mantissa, mantissa_digit;
    u8 format;
    s32 prec = precision;
    s32 negative;
    u8 *fp = fraction;
    u8 *ip = &integer[127];
    u8 *ep = &exponent[15];
    u8 *iend = ip;
    s32 nf, ni, ne;
    s32 fixed;
    s32 i, n, e, carry, trim, padding, point;
    u8 *p, *q, *out;
    u8 c, exp_negative;
    f64 scale, round, base, power;
    f64 fixed_ten, fixed_base, fixed_bias, fixed_limit;
    f64 sci_ten, sci_base, sci_bias, sci_limit;

    *ip = 0;
    *ep = 0;
    format = ch;
    negative = value < D_800E1118;
    if (negative) value = -value;
    if (prec >= 127) prec = 126;
    fixed = 0;
    if (prec == 6) {
        scale = D_800DD0F0;
    } else {
        base = D_800DD0F8_de;
        n = prec;
        if (n == 0) {
            scale = D_800E1130;
        } else {
            if (n < 0) {
                n = -n;
                base = D_800DD108_de;
            }
            power = D_800DD110_de;
            for (;;) {
                if (n & 1) power *= base;
                n >>= 1;
                if (!n) break;
                base *= base;
            }
            scale = power;
        }
    }
    round = D_800E1148 / scale;
    if (format == 'f' || (format == 'g' &&
        (value == D_800DD120_de || (value >= D_800DD128_de && value < scale)))) {
        fixed = 1;
    }
    ni = nf = ne = 0;
    if (fixed) {
        value = func_8029DAA0_de(value, &whole);
        if (value >= round || format != 'g') {
            value += round;
            if (value >= D_800DD130_de) {
                whole += D_800DD130_de;
                value -= D_800DD130_de;
            }
            fixed_ten = D_800DD138_de;
            for (i = 0; i < prec; i++) {
                nf++;
                value = func_8029DAA0_de(value * fixed_ten, &digit);
                *fp++ = (s32)digit + '0';
            }
            if (format == 'g') {
                for (p = fp - 1; p >= fraction && *p == '0'; p--) {
                    *p = 0;
                    nf--;
                }
            }
        }
        if (whole == D_800DD140_de) {
            if (format != 'g' || nf < prec || nf < width) {
                *--ip = '0';
                ni++;
            }
        } else if (whole <= D_800DD148_de) {
            n = (s32)whole;
            while (n != 0) {
                *--ip = n % 10 + '0';
                ni++;
                n /= 10;
            }
        } else {
            fixed_limit = D_800DD150_de;
            if (whole > fixed_limit) {
                fixed_base = D_800DD158_de;
                fixed_bias = D_800DD160_de;
                fixed_ten = D_800DD168_de;
                do {
                    *--ip = (s32)((func_8029DAA0_de(whole * fixed_base, &whole) + fixed_bias) * fixed_ten) + '0';
                    ni++;
                } while (whole > fixed_limit);
            }
        }
        if (format == 'g') {
            n = prec;
            if (n < width) n = width;
            trim = ni + nf - n;
            if (nf < trim) trim = nf;
            if (trim > 0) {
                for (p = &fraction[nf - 1]; p >= fraction && trim > 0; p--, trim--) {
                    nf--;
                    c = *p;
                    *p = 0;
                    if ((c & 0xff) >= '6') {
                        carry = 1;
                        for (q = p - 1; q >= fraction && carry; q--) {
                            c = ++*q;
                            if ((c & 0xff) < ':') carry = 0;
                            else *q = '0';
                        }
                        if (carry) {
                            for (q = iend - 1; q >= ip && carry; q--) {
                                c = ++*q;
                                if ((c & 0xff) < ':') carry = 0;
                                else *q = '0';
                            }
                            if (carry) {
                                *--ip = '1';
                                ni++;
                                trim--;
                            }
                        }
                    }
                }
            }
        }
    } else {
        e = 0;
        sci_ten = D_800DD170_de;
        sci_base = D_800DD178_de;
        while (value >= sci_ten) {
            value *= sci_base;
            e++;
        }
        sci_limit = D_800DD180_de;
        sci_bias = D_800DD188_de - round;
        sci_ten = D_800DD190_de;
        while (value > sci_limit && value < sci_bias) {
            value *= sci_ten;
            e--;
        }
        value = func_8029DAA0_de(value, &mantissa);
        if (format == 'g') {
            prec--;
            scale *= D_800DD198_de;
            round = D_800DD1A0 / scale;
        }
        if (value >= round || format != 'g') {
            value += round;
            if (value >= D_800DD1A8_de) {
                value -= D_800DD1A8_de;
                mantissa += D_800DD1A8_de;
                if (mantissa >= D_800DD1B0) {
                    e++;
                    mantissa *= D_800DD1B8;
                    value *= D_800DD1B8;
                }
            }
            sci_ten = D_800E11F0;
            for (i = 0; i < prec; i++) {
                nf++;
                value = func_8029DAA0_de(value * sci_ten, &mantissa_digit);
                *fp++ = (s32)mantissa_digit + '0';
            }
            if (format == 'g') {
                for (p = fp - 1; p >= fraction && *p == '0'; p--) {
                    *p = 0;
                    nf--;
                }
            }
        }
        exp_negative = e < 0;
        if (e < 0) e = -e;
        while (e > 0) {
            *--ep = e % 10 + '0';
            ne++;
            e /= 10;
        }
        while (ne < 2) {
            *--ep = '0';
            ne++;
        }
        *--ep = exp_negative ? '-' : '+';
        *--ep = 'e';
        ne += 2;
        *--ip = (s32)mantissa + '0';
        ni = 1;
    }
    point = 0;
    if (format != 'g' || nf > 0) point = 1;
    padding = width - (negative + ni + point + nf + ne);
    if (padding < 0) padding = 0;
    out = buf;
    for (i = 0; i < padding; i++) *out++ = ' ';
    if (negative) *out++ = '-';
    for (i = 0; i < ni; i++) *out++ = *ip++;
    if (point) {
        *out++ = '.';
        fp = fraction;
        for (i = 0; i < nf; i++) *out++ = *fp++;
    }
    for (i = 0; i < ne; i++) *out++ = *ep++;
    *out = 0;
    return out - buf;
}
