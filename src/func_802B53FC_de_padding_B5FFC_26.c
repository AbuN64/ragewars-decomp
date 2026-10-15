#include "span_1000/code_802B53FC.h"
#include "types.h"

/* cosf, drafted from ultralib src/gu/cosf.c: reduce |x| by multiples of pi around pi/2 in double
   precision and evaluate the odd polynomial, negating for an odd multiple; anything beyond 2^28
   returns zero. This library carries no NaN test and takes |x| with abs.s (__builtin_fabs, where
   the reference's ABS macro compiles to a compare and branch); P, rpi, pihi, pilo and zero are the
   cartridge's tables, and the 0.5 of the reduction and ROUND, ROUND's 0.0 and the 0.5 subtracted
   from n are its own constants. */


extern const f64 D_800C7810_de[5];  /* P */
extern const f64 D_800C7838_de;     /* rpi */
extern const f64 D_800C7840_de;     /* pihi */
extern const f64 D_800C7848_de;     /* pilo */
extern const f32 D_800C7850_de;     /* zero */
extern const double D_800C7858_de; /* 0.5 */
extern const double D_800C7860_de; /* 0.0 */
extern const double D_800C7868_de; /* 0.5 */

float func_802B6560_de(float x)
{
    float absx;
    double dx, xsq, poly;
    double dn;
    int n;
    double result;
    int ix, xpt;

    ix = *(int *)&x;
    xpt = (ix >> 22);
    xpt &= 0x1ff;

    if (xpt < 0x136) {
        absx = __builtin_fabs(x);

        dx = absx;

        dn = dx * D_800C7838_de + D_800C7858_de;
        n = (dn >= D_800C7860_de) ? (int)(dn + D_800C7858_de) : (int)(dn - D_800C7858_de);
        dn = n;

        dn -= D_800C7868_de;

        dx = dx - dn * D_800C7840_de;
        dx = dx - dn * D_800C7848_de;

        xsq = dx * dx;

        {
            const f64 *P = D_800C7810_de;

            poly = ((P[4] * xsq + P[3]) * xsq + P[2]) * xsq + P[1];
        }

        result = dx + (dx * xsq) * poly;

        if ((n & 1) == 0)
            return (float)result;

        return -(float)result;
    }

    return D_800C7850_de;
}

