#include "span_1000/code_802B7058.h"
#include "types.h"

/* sinf, drafted from ultralib src/gu/sinf.c in the single-precision form this library carries: x,
   its square, the polynomial, the quotient and the result are floats, only the polynomial is
   evaluated in double, and anything beyond 2^28 returns zero. P, rpi, pihi, pilo and zero are the
   cartridge's tables, and the two 0.5 literals of ROUND are its own constants. */


extern const f64 D_800C78D0_de[5]; /* P */
extern const f64 D_800C78F8_de;    /* rpi */
extern const f64 D_800C7900_de;    /* pihi */
extern const f64 D_800C7908_de;    /* pilo */
extern const f32 D_800C7910_de;    /* zero */
extern const float D_800C7914_de; /* 0.5 */
extern const float D_800C7918_de; /* 0.5 */

float func_802B7130_de(float x)
{
    float dx, xsq, poly;
    float dn;
    int n;
    float result;
    int ix, xpt;

    ix = *(int *)&x;
    xpt = (ix >> 22);
    xpt &= 0x1ff;

    if (xpt < 0xff) {
        dx = x;

        if (xpt >= 0xe6) {
            const f64 *P = D_800C78D0_de;

            xsq = dx * dx;

            poly = ((P[4] * xsq + P[3]) * xsq + P[2]) * xsq + P[1];

            result = dx + (dx * xsq) * poly;

            return result;
        }

        return x;
    }

    if (xpt < 0x136) {
        dx = x;

        dn = dx * D_800C78F8_de;

        n = (dn >= 0.0f) ? (int)(dn + D_800C7914_de) : (int)(dn - D_800C7918_de);
        dn = n;

        dx = dx - dn * D_800C7900_de;
        dx = dx - dn * D_800C7908_de;

        xsq = dx * dx;

        {
            const f64 *P = D_800C78D0_de;

            poly = ((P[4] * xsq + P[3]) * xsq + P[2]) * xsq + P[1];
        }

        result = dx + (dx * xsq) * poly;

        if ((n & 1) == 0) {
            return result;
        }

        return -result;
    }

    return D_800C7910_de;
}

