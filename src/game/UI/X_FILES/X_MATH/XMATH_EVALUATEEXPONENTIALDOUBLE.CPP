#include "COMMON/OBJRECAT3CV2.H"
#include "MATH/DOUBLEBITS.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "MATH/math_double.H"
#include "MATH/8029BBA0_5.H"
#include "RSP/8026E1F8_5.H"

/* Rounds a double up to the next integer by the 2^52 add-and-subtract trick, handling negative values through an inlined round-down that recurses back into this function. Adapted from XMath_FloorDouble with the rounding direction reversed, the negative case routed through an inline copy of the round-down and the constants changed. */





static inline f64 round_down(f64 arg0) {
    f64 temp;
    f64 integral;
    f64 limit;

    limit = D_800C5B28_de;
    if (limit <= arg0) {
        return arg0;
    }
    if (arg0 < D_800C5B30_de) {
        return -XMath_CeilDouble(-arg0);
    }
    temp = arg0;
    temp += limit;
    temp -= limit;
    if (arg0 < temp) {
        integral = temp - D_800C5B38_de;
    } else {
        integral = temp;
    }
    return integral;
}




extern f64 NaturalLogDouble(f64 value);

/* Returns e raised to a double: 1 for arguments of negligible magnitude, and otherwise splits the argument into k ln 2 plus a remainder r, evaluates the rational approximation 1/2 + p(r)/(q(r) - p(r)) and scales it by two to the power k + 1 through func_8029ABA0_de. */














/* Returns the arcsine of a value clamped to [-1, 1] using the polynomial approximation pi/2 - sqrt(1 - x) * p(x) on its magnitude and restoring the sign afterwards. */








/* Returns the arccosine of a value clamped to [-1, 1] as pi/2 minus the arcsine, which is computed by the polynomial approximation pi/2 - sqrt(1 - x) * p(x) on the magnitude with the sign restored. Adapted from XMath_EvaluateArcSine with the constants moved to D_800CADB4 through D_800CADD4 and the final subtraction from pi/2 added. */








/** Perform the pair of adjacent no-op hooks at VRAM 0x8029E8A0. */
void XMath_InitializeMath(void) {
}

void XMath_ShutdownMath(void) {
}

f32 XMath_SquareFloat(f32 arg0) {
    return arg0 * arg0;
}

void XMath_EvaluatePositiveSquareRoot(f32 arg0) {
    if (!(arg0 <= 0.0f)) {
        Gu_Sqrtf(arg0);
    }
}

f32 XMath_EvaluateReciprocalSquareRoot(f32 arg0) {
    f32 var_f0;

    if (arg0 <= 0.0f) {
        var_f0 = 0.0f;
    } else {
        var_f0 = Gu_Sqrtf(arg0);
    }
    return D_800C5B0C_de / var_f0;
}

f32 XMath_OffsetFloatRemainder(f32 arg0, f32 arg1) {
    f32 result;
    result = (f32) FloatModulo((f64) arg0, (f64) arg1);
    if (result < arg1) {
        result += arg1;
    }
    return result;
}

f64 XMath_FloorDouble(f64 arg0) {
    f64 temp;
    f64 integral;
    f64 limit;

    limit = D_800C5B10_de;
    if (limit <= arg0) {
        return arg0;
    }
    if (arg0 < D_800C5B18_de) {
        return -XMath_CeilDouble(-arg0);
    }
    temp = arg0;
    temp += limit;
    temp -= limit;
    if (arg0 < temp) {
        integral = temp - D_800C5B20_de;
    } else {
        integral = temp;
    }
    return integral;
}

f64 XMath_CeilDouble(f64 arg0) {
    f64 temp;
    f64 integral;
    f64 limit;

    limit = D_800C5B28_de;
    if (limit <= arg0) {
        return arg0;
    }
    if (arg0 < D_800C5B30_de) {
        return -round_down(-arg0);
    }
    temp = arg0;
    temp += limit;
    temp -= limit;
    if (temp < arg0) {
        integral = temp + D_800C5B40_de;
    } else {
        integral = temp;
    }
    return integral;
}

f64 XMath_SplitDoubleFraction(f64 arg0, f64 *whole) {
    f64 temp;
    f64 integral;
    f64 limit;

    limit = D_800C5B48_de;
    if (limit <= arg0) {
        integral = arg0;
    } else {
        if (arg0 < D_800C5B50_de) {
            integral = -XMath_CeilDouble(-arg0);
        } else {
            temp = arg0;
            temp += limit;
            temp -= limit;
            if (arg0 < temp) {
                integral = temp - D_800C5B58_de;
            } else {
                integral = temp;
            }
        }
    }
    *whole = integral;
    return arg0 - integral;
}

f32 XMath_AbsoluteFloat(f32 arg0) {
    if (arg0 >= 0.0f) {
        return arg0;
    }
    return -arg0;
}

s32 XMath_AbsoluteInteger(s32 fifth) {
    if (fifth < 0) {
        if (fifth) {
            return -fifth;
        } else {
            return -fifth;
        }
    }
    return fifth;
}

/* Returns the base-10 logarithm of a double: NaturalLogDouble(value) times 1/ln 10. */
f64 Log10Double(f64 value) {
    return NaturalLogDouble(value) * D_800C5B60_de;
}

f64 XMath_EvaluateExponentialDouble(f64 x) {
    f64 r;
    f64 t;
    f64 p;
    f64 q;
    s32 k;

    if (D_800C5B68_de < x) {
        f64 result = D_800C5B78_de;
        if (x < D_800C5B70_de) return result;
    }
    t = x * D_800C5B80_de;
    k = t;
    if (k < 0) {
        k--;
    }
    if (D_800C5B88_de <= t - k) {
        k++;
    }
    r = x - k * D_800C5B90_de + k * D_800C5B98_de;
    t = r * r;
    p = ((t * D_800C5BA0_de + D_800C5BA8_de) * t + D_800C5BC0_de) * r;
    q = (t * D_800C5BB0_de + D_800C5BB8_de) * t + D_800C5B88_de;
    return ScaleDoubleExponent(p / (q - p) + D_800C5B88_de, k + 1);
}

f64 XMath_SplitDoubleExponent(f64 arg0, s32 *arg1) {
    DoubleBits_8029ECB0 u;
    f64 special;

    special = D_800C5BC8_de;
    if (arg0 != special) {
        if (D_800C5BC8_de || arg1) {
            goto normal;
        } else {
            goto normal;
        }
    }
    *arg1 = 0;
    return special;
normal:
    u.d = arg0;

    *arg1 = ((u.w.hi >> 20) & 0x7FF) - 0x3FE;
    u.w.hi = (u.w.hi & 0x800FFFFF) | 0x3FE00000;
    return u.d;
}

void XMath_EvaluateCosine(f32 arg0) {
    ((s32 (*)(f32))XMath_EvaluateSine)(arg0 + D_800C5BD0_de);
}

f32 XMath_EvaluateTangent(f32 arg0) {
    f32 r1 = XMath_EvaluateSine(arg0);
    f32 r2 = XMath_EvaluateSine(arg0 + D_800C5BD4_de);
    return r1 / r2;
}

f32 XMath_EvaluateArcTangent(f32 arg0) {
    f32 temp_f2;
    f32 temp_f3;
    f32 result;
    f32 var_f1;

    var_f1 = arg0;
    if (arg0 < 0.0f) {
        var_f1 = -arg0;
    }
    temp_f3 = (var_f1 - D_800C5BD8_de) / (var_f1 + D_800C5BD8_de);
    temp_f2 = temp_f3 * temp_f3;
    result = (((((((((((((((temp_f2 * D_800C5BDC_de) + D_800C5BE0_de) * temp_f2) - *(&D_800C5BE0_de + 1)) * temp_f2) + D_800C5BE8_de) * temp_f2) - *(&D_800C5BE8_de + 1)) * temp_f2) + D_800C5BF0_de) * temp_f2) - *(&D_800C5BF0_de + 1)) * temp_f2) + D_800C5BF8_de) * temp_f3) + *(&D_800C5BF8_de + 1);
    if (arg0 < 0.0f) {
        result = -result;
    }
    return result;
}

f32 XMath_EvaluateArcSine(f32 x) {
    s32 negative;
    f32 poly;
    f32 root;
    f32 result;

    if (D_800C5C00_de < x) {
        x = D_800C5C00_de;
    }
    do {
        if (x < *(&D_800C5C00_de + 1)) {
            x = *(&D_800C5C00_de + 1);
        }
        negative = 0;
        if (x < 0.0f) {
            negative = 1;
            x = -x;
        }
        poly = (((((x * D_800C5C08_de + *(&D_800C5C08_de + 1)) * x - D_800C5C10_de) * x + *(&D_800C5C10_de + 1)) * x
                 - D_800C5C18_de) * x) + *(&D_800C5C18_de + 1);
        x = D_800C5C00_de - x;
        if (x <= 0.0f) {
            root = 0.0f;
        } else {
            root = Gu_Sqrtf(x);
        }
    } while (0);
    result = D_800C5C20_de - root * poly;
    if (negative) {
        result = -result;
    }
    return result;
}

f32 XMath_EvaluateArcCosine(f32 x) {
    s32 negative;
    f32 poly;
    f32 root;
    f32 result;

    if (*(&D_800C5C20_de + 1) < x) {
        x = *(&D_800C5C20_de + 1);
    }
    do {
        if (x < D_800C5C28_de) {
            x = D_800C5C28_de;
        }
        negative = 0;
        if (x < 0.0f) {
            negative = 1;
            x = -x;
        }
        poly = (((((x * (-0.011680527590215206f) + D_800C5C30_de) * x - *(&D_800C5C30_de + 1)) * x + D_800C5C38_de) * x
                 - *(&D_800C5C38_de + 1)) * x) + D_800C5C40_de;
        x = *(&D_800C5C20_de + 1) - x;
        if (x <= 0.0f) {
            root = 0.0f;
        } else {
            root = Gu_Sqrtf(x);
        }
    } while (0);
    result = *(&D_800C5C40_de + 1) - root * poly;
    if (negative) {
        result = -result;
    }
    return *(&D_800C5C40_de + 1) - result;
}
