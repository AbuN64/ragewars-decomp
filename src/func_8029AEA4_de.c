#include "span_1000/code_8029BBA0.h"
#include "types.h"
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
