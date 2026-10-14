#include "span_1000/code_8029EB74.h"
#include "types.h"

/* Returns e raised to a double: 1 for arguments of negligible magnitude, and otherwise splits the argument into k ln 2 plus a remainder r, evaluates the rational approximation 1/2 + p(r)/(q(r) - p(r)) and scales it by two to the power k + 1 through func_8029ABA0_de. */













extern f64 func_8029ABA0_de(f64 value, s32 exponent);

f64 func_8029DB9C_de(f64 x) {
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
    return func_8029ABA0_de(p / (q - p) + D_800C5B88_de, k + 1);
}
