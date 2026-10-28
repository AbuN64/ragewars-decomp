#include "COMMON/OBJRECAT3CV2.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "COMMON/TEXTURE.H"
#include "COMMON/EXTERNS_4.H"
#include "MATH/8029BBA0_5.H"
#include "MENU/GFX/80414480_8.H"

s32 Gfx_FormatFloatingPoint(u8 *buf, f64 input, s32 ch, s32 width, s32 precision) {
    u8 fraction[128];
    u8 integer[128];
    u8 exponent[16];
    f64 value;
    f64 whole, digit, mantissa, mantissa_digit;
    u8 format = ch;
    s32 prec;
    s32 negative;
    u8 *fp = fraction;
    u8 *ip = &integer[127];
    u8 *ep = &exponent[15];
    u8 *iend = ip;
    s32 nf, ni, ne;
    s32 fixed;
    s32 pow_n, maxdigits, k;
    s32 i, n, e, carry, trim, padding, point;
    u8 *p, *q, *out;
    u8 *integer_carry;
    u8 *fp_trim, *exp_trim;
    u8 c, exp_negative;
    f64 scale, round, base, power, frac, sci_frac;
    f64 fixed_ten, fixed_base, fixed_limit;
    f64 norm_ten, sci_ten, sci_base, sci_bias, sci_limit;

    prec = precision;
    *ip = 0;
    *ep = 0;
    value = input;
    negative = value < D_800E1118;
    if (negative) value = -value;
    if (prec >= 127) prec = 126;
    if (prec == 6) {
        scale = D_800DD0F0;
    } else {
        base = D_800DD0F8_de;
        pow_n = prec;
        if (pow_n == 0) {
            scale = D_800E1130;
        } else {
            if (pow_n < 0) {
                pow_n = -pow_n;
                base = D_800DD108_de;
            }
            power = D_800DD110_de;
            for (;;) {
                if (pow_n & 1) power *= base;
                pow_n >>= 1;
                if (!pow_n) break;
                base *= base;
            }
            scale = power;
        }
    }
    fixed = 0;
    round = D_800E1148 / scale;
    if (format == 'f' || (format == 'g' &&
        (value == D_800DD120_de || (value >= D_800DD128_de && value < scale)))) {
        fixed = 1;
    }
    ni = 0;
    nf = ni;
    ne = ni;
    if (fixed) {
        value = XMath_SplitDoubleFraction(value, &whole);
        if (value >= round || format != 'g') {
            value += round;
            if (value >= D_800DD130_de) {
                whole += D_800DD130_de;
                value -= D_800DD130_de;
            }
            frac = value;
            i = 0;
            if (i < prec) {
                fixed_ten = D_800DD138_de;
                do {
                    frac = XMath_SplitDoubleFraction(frac * fixed_ten, &digit);
                    nf++;
                    *fp++ = (s32)digit + '0';
                    i++;
                } while (i < prec);
            }
            if (format == 'g') {
                for (fp_trim = fp - 1; fp_trim >= fraction && *fp_trim == '0'; fp_trim--) {
                    *fp_trim = 0;
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
            if (whole > D_800DD150_de) {
                fixed_limit = D_800DD150_de;
                fixed_base = D_800DD158_de;
                round = D_800DD160_de;
                fixed_ten = D_800DD168_de;
                do {
                    *--ip = (s32)((XMath_SplitDoubleFraction(whole * fixed_base, &whole) + round) * fixed_ten) + '0';
                    ni++;
                } while (whole > fixed_limit);
            }
        }
        if (format == 'g') {
            maxdigits = prec;
            if (maxdigits < width) maxdigits = width;
            trim = ni + nf - maxdigits;
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
                            if ((c & 0xff) >= ':') *q = '0';
                            else carry = 0;
                        }
                        if (carry) {
                            for (integer_carry = iend - 1; integer_carry >= ip && carry; integer_carry--) {
                                c = ++*integer_carry;
                                if ((c & 0xff) >= ':') *integer_carry = '0';
                                else carry = 0;
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
        norm_ten = D_800DD170_de;
        if (value >= norm_ten) {
        sci_base = D_800DD178_de;
        do {
            value *= sci_base;
            e++;
        } while (value >= norm_ten);
        }
        sci_limit = D_800DD180_de;
        sci_bias = D_800DD188_de - round;
        while (value > sci_limit) {
            if (value < sci_bias) {
                value *= D_800DD190_de;
                e--;
            } else break;
        }
        value = XMath_SplitDoubleFraction(value, &mantissa);
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
            sci_frac = value;
            i = 0;
            if (i < prec) {
                scale = D_800E11F0;
                do {
                    sci_frac = XMath_SplitDoubleFraction(sci_frac * scale, &mantissa_digit);
                    nf++;
                    *fp++ = (s32)mantissa_digit + '0';
                    i++;
                } while (i < prec);
            }
            if (format == 'g') {
                for (exp_trim = fp - 1; exp_trim >= fraction && *exp_trim == '0'; exp_trim--) {
                    *exp_trim = 0;
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
        ni++;
    }
    point = 0;
    if (format != 'g' || nf > 0) point = 1;
    padding = width - (negative + ni + point + nf + ne);
    if (padding < 0) padding = 0;
    out = buf;
    for (k = 0; k < padding; k++) *out++ = ' ';
    if (negative) *out++ = '-';
    for (k = 0; k < ni; k++) *out++ = *ip++;
    if (point) {
        *out++ = '.';
        fp = fraction;
        for (k = 0; k < nf; k++) *out++ = *fp++;
    }
    for (k = 0; k < ne; k++) *out++ = *ep++;
    *out = 0;
    return out - buf;
}
