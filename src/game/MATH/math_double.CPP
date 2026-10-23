#include "include_asm.h"
#include "COMMON/OBJRECAT3CV2.H"
#include "TYPES.H"
#include "MATH/math_double.H"
#include "MATH/8029BBA0_5.H"

#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/OBJRECAT3CV2.H"
#include "MATH/DOUBLEBITS.H"

extern const f64 D_800C56C0_de;
extern const f64 D_800C56C8_de;
extern const f64 D_800C56D0_de;

f64 func_8029ABA0_de(f64 value, s32 shift) {
    DoubleBits_8029ECB0 *bits = (DoubleBits_8029ECB0 *)&value;
    u32 high = bits->w.hi;
    s32 exponent = (high >> 20) & 0x7FF;
    u32 sign;
    if (exponent != 0) {
        if ((u32)exponent < 0x7FF) {
            exponent = (s32)((u32)exponent + (u32)shift);
            if (exponent != 0) {
                if ((u32)exponent < 0x7FF) {
                    bits->w.hi = (high & 0x800FFFFF) | ((exponent & 0x7FF) << 20);
                    return value;
                }
                if (shift >= 0) {
                    high = bits->w.hi;
                    sign = high >> 31;
                    value = D_800C56C0_de;
                    bits->w.hi = (high & 0x7FFFFFFF) | (sign << 31);
                    return value;
                }
                if ((u32)exponent < (u32)-53) {
                    sign = high >> 31;
                    value = 0.0;
                    bits->w.hi = (bits->w.hi & 0x7FFFFFFF) | (sign << 31);
                    return value;
                }
            }
            bits->w.hi = (bits->w.hi & 0x800FFFFF) | 0x100000;
            value *= func_8029ABA0_de(D_800C56C8_de, exponent - 1);
            return value;
        }
        if ((high & 0xFFFFF) != 0 || bits->w.lo != 0) {
            return value;
        }
        if (shift >= 0) {
            high = bits->w.hi;
            sign = high >> 31;
            value = D_800C56C0_de;
            bits->w.hi = (high & 0x7FFFFFFF) | (sign << 31);
        } else {
            bits->w.hi = (high & 0x7FFFFFFF) | ((high >> 31) << 31);
        }
        return value;
    }
    if ((high & 0xFFFFF) == 0 && bits->w.lo == 0) {
        return value;
    }
    return func_8029ABA0_de(value * func_8029ABA0_de(D_800C56D0_de, 53), shift - 53);
}
#else
INCLUDE_ASM("span_1000", func_8029ABA0_de);
#endif

#ifdef NON_MATCHING
#include "TYPES.H"
extern f64 D_800C56D8_de,D_800C56E0_de,D_800C56E8_de,D_800C56F0_de,D_800C56F8_de;
extern f64 D_800C5700_de,D_800C5708_de,D_800C5710_de,D_800C5718_de,D_800C5720_de,D_800C5728_de,D_800C5730_de,D_800C5738_de;
static inline f64 Frexp(f64 value, s32 *exponent)
{
  union
  {
    f64 value;
    struct
    {
      u32 high;
      u32 low;
    } words;
  } bits;
  if (value != D_800C56E0_de)
  {
    bits.value = value;
    *exponent = ((bits.words.high >> 20) & 0x7ff) - 0x3fe;
    bits.words.high = (bits.words.high & 0x800fffff) | 0x3fe00000;
    return bits.value;
  }
  *exponent = 0;
  return D_800C56E0_de;
}
f64 func_8029AD38_de(f64 value)
{
  s32 exponent;
  f64 x;
  f64 denominator;
  f64 square;
  f64 numerator;
  f64 correction;
  if (value <= D_800C56E0_de)
  {
    return D_800C56D8_de;
  }
  x = Frexp(value, &exponent);
 do { if (D_800C56E8_de < x) { denominator = x * D_800C56F0_de; x = x - D_800C56F0_de; x = x - D_800C56F0_de; denominator += D_800C56F0_de; } else { x = x - D_800C56F8_de; denominator = x * D_800C56F8_de; exponent--; denominator += D_800C56F8_de; } x = x / denominator; square = x * x; numerator = ((square * D_800C5700_de) + D_800C5708_de) * square; denominator = (((square - D_800C5710_de) * square) + D_800C5718_de) * square; numerator = square * (numerator - D_800C5720_de); denominator = denominator - D_800C5728_de; } while (0);
  correction = x * (numerator / denominator);
  return ((exponent * D_800C5730_de) + (x + correction)) + (exponent * D_800C5738_de);
}
#else
INCLUDE_ASM("span_1000", func_8029AD38_de);
#endif

/* Raises x to the power y: 1 for a zero exponent, 0 or infinity for a zero base, exp(y log x) through func_8029AD38_de (log) and an inline exponential scaled by func_8029ABA0_de (ldexp) for a positive base, and for a negative base the same magnitude signed by the parity of an integer exponent, or negated when the exponent's reciprocal is odd, otherwise negative infinity. */


extern f64 func_8029AD38_de(f64 value);

static inline f64 exp_inline(f64 x) {
    f64 t;
    f64 r;
    f64 p;
    s32 k;

    if (-2.710504946537621e-20 < x && x < 2.710504946537621e-20) {
        return 1.0;
    }
    t = x * 1.4426950216293335;
    k = t;
    if (k < 0) {
        k--;
    }
    if (0.5 <= t - k) {
        k++;
    }
    r = x - k * 0.693359375 + k * 2.1219444170128557e-4;
    t = r * r;
    p = ((t * 1.652032915444579e-5 + 6.943599786609411e-3) * t + 0.25) * r;
    return func_8029ABA0_de(p / ((t * 4.9586285604164e-4 + 5.55538684129715e-2) * t + 0.5 - p) + 0.5, k + 1);
}

f64 func_8029AEA4_de(f64 x, f64 y) {
    s32 k;
    f64 t;

    if (y == 0.0) {
        return 1.0;
    }
    if (x == 0.0) {
        if (y < 0.0) {
            return 1.0 / 0.0;
        }
        return 0.0;
    }
    if (x < 0.0) {
        k = y;
        if (k == y) {
            t = func_8029AD38_de(-x) * y;
            if (k & 1) {
                return -exp_inline(t);
            }
            return exp_inline(t);
        }
        k = 1.0 / y;
        if (!(-2.710504946537621e-20 < y - k * y && y - k * y < 2.710504946537621e-20 && (k & 1))) {
            return -1.0 / 0.0;
        }
        return -exp_inline(func_8029AD38_de(-x) * y);
    }
    return exp_inline(func_8029AD38_de(x) * y);
}

/* Rounds toward negative infinity by the 2^52 add-and-subtract trick; a negative value goes through
 * func_8029D9DC_de (ceil) as -ceil(-value). */
static inline f64 floor_inline(f64 value) {
    f64 temp;
    f64 integral;
    f64 limit;

    limit = 4503599627370496.0;
    if (limit <= value) {
        return value;
    }
    if (value < 0.0) {
        return -func_8029D9DC_de(-value);
    }
    temp = value;
    temp += limit;
    temp -= limit;
    if (value < temp) {
        integral = temp - 1.0;
    } else {
        integral = temp;
    }
    return integral;
}

/* Rounds toward positive infinity the same way; a negative value goes through the floor as -floor(-value). */
static inline f64 ceil_inline(f64 value) {
    f64 temp;
    f64 integral;
    f64 limit;

    limit = 4503599627370496.0;
    if (limit <= value) {
        return value;
    }
    if (value < 0.0) {
        return -floor_inline(-value);
    }
    temp = value;
    temp += limit;
    temp -= limit;
    if (temp < value) {
        integral = temp + 1.0;
    } else {
        integral = temp;
    }
    return integral;
}

/* Returns the remainder of x / y with the sign of x: x minus y times the quotient rounded toward zero. */
f64 FloatModulo(f64 x, f64 y) {
    f64 quotient = x / y;
    f64 zero = 0.0;

    if (zero > quotient) {
        return x - ceil_inline(quotient) * y;
    }
    return x - floor_inline(quotient) * y;
}
