#include "COMMON/MATRIXRECORD.H"
#include "COMMON/OBJRECAT3CV2.H"
#include "TYPES.H"
#include "MATH/math_double.H"
#include "MATH/802A0470.H"

/* Copies n bytes between possibly overlapping buffers and returns the destination: forwards when the destination is below the source and backwards otherwise, aligning to a word boundary with single bytes when both pointers share alignment, then copying whole words and the remaining bytes. */

char *XPlus_MoveMemory(char *dst, const char *src, s32 n) {
    char *d;
    s32 count;

    d = dst;
    if (n == 0 || dst == src) {
        return dst;
    }
    if (dst < src) {
        count = (s32)src;
        if ((count | (s32)dst) & 3) {
            if ((count ^ (s32)dst) & 3) {
                count = n;
            } else if (n < 4) {
                count = n;
            } else {
                count = 4 - (count & 3);
            }
            n -= count;
            do {
                *d++ = *src++;
            } while (--count != 0);
        }
        count = (u32)n >> 2;
        if (count != 0) {
            do {
                *(s32 *)d = *(const s32 *)src;
                src += 4;
                d += 4;
            } while (--count != 0);
        }
        count = n & 3;
        if (count != 0) {
            do {
                *d++ = *src++;
            } while (--count != 0);
        }
    } else {
        src += n;
        d = dst + n;
        count = (s32)src;
        if ((count | (s32)d) & 3) {
            if ((count ^ (s32)d) & 3) {
                count = n;
            } else if (n < 5) {
                count = n;
            } else {
                count &= 3;
            }
            n -= count;
            do {
                *--d = *--src;
            } while (--count != 0);
        }
        count = (u32)n >> 2;
        if (count != 0) {
            do {
                src -= 4;
                d -= 4;
                *(s32 *)d = *(const s32 *)src;
            } while (--count != 0);
        }
        count = n & 3;
        if (count != 0) {
            do {
                *--d = *--src;
            } while (--count != 0);
        }
    }
    return dst;
}

f64 XPlus_ParseDecimalDouble(u8 *arg0) {
    f64 sign;
    f64 divisor;
    f64 value;
    f64 fraction;
    f64 exponentSign;
    f64 exponent;
    f64 scale;
    f64 threshold;

    sign = D_800C5CD0_de;
    fraction = D_800C5CD8_de;
    divisor = sign;
    if (*arg0 == 0x20) {
        do {
            arg0++;
        } while (*arg0 == 0x20);
    }
    if (*arg0 == 0x2D) {
        arg0++;
        sign = D_800C5CE0_de;
    }
    if (*arg0 == 0x2B) {
        arg0++;
    }

    value = D_800C5CE8_de;
    if ((u32)(*arg0 - 0x30) < 10) {
        do {
            value = value * D_800C5CF0_de + (f64)(*arg0 - 0x30);
            arg0++;
        } while ((u32)(*arg0 - 0x30) < 10);
    }

    if (*arg0 == 0x2E) {
        arg0++;
        fraction = D_800C5CF8_de;
        if ((u32)(*arg0 - 0x30) < 10) {
            do {
                divisor *= D_800C5D00_de;
                fraction = fraction * D_800C5D00_de + (f64)(*arg0 - 0x30);
                arg0++;
            } while ((u32)(*arg0 - 0x30) < 10);
        }
    }

    if (*arg0 == 0x65 || *arg0 == 0x45) {
        arg0++;
        exponentSign = D_800C5D08_de;
        if (*arg0 == 0x2D) {
            arg0++;
            exponentSign = D_800C5D10_de;
        }
        if (*arg0 == 0x2B) {
            arg0++;
        }
        exponent = D_800C5D18_de;
        if ((u32)(*arg0 - 0x30) < 10) {
            do {
                exponent = exponent * D_800C5D20_de + (f64)(*arg0 - 0x30);
                arg0++;
            } while ((u32)(*arg0 - 0x30) < 10);
        }
        if (exponent < D_800C5D28_de) {
            threshold = D_800C5D30_de;
            scale = D_800C5D38_de;
            if (exponent == threshold) {
                goto compare_sign;
            } else {
                do {
                    scale *= D_800C5D40_de;
                    exponent -= D_800C5D38_de;
                } while (exponent != threshold);
            }
            goto set_threshold;
        } else {
            scale = XMath_PowerDouble(D_800C5D48_de, exponent);
        }
set_threshold:
        threshold = D_800C5D50_de;
compare_sign:
        if (exponentSign < threshold) {
            return sign * (value + fraction / divisor) / scale;
        }
        return sign * (value + fraction / divisor) * scale;
    }
    return sign * (value + fraction / divisor);
}
