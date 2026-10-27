#include "include_asm.h"
#include "COMMON/EXTERNS_16.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_2.H"
#include "COMMON/CTX.H"

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

float Math_Sinf(float x)
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

#if defined(VERSION_US)
unsigned int rodata_unresolved_802B71DC[1] = {
    0x5F426F73,
};
#endif

#if defined(VERSION_US_REV1)
const unsigned int D_auto_src_rw_constants_802B7130_CD728_us_rev1[17] = {
    0xBFC55554, 0xBC83656D, 0x3F8110ED, 0x3804C2A0, 0xBF29F6FF, 0xEEA56814, 0x3EC5DBDF, 0x0E314BFE,
    0x3FD45F30, 0x6DC9C883, 0x400921FB, 0x50000000, 0x3E6110B4, 0x611A6263, 0x00000000, 0x3F000000,
    0x3F000000,
};
#endif

#if defined(VERSION_EU)
const unsigned int D_auto_rodata_func_802B7130_de_800C84C8[17] = {
    0xBFC55554, 0xBC83656D, 0x3F8110ED, 0x3804C2A0, 0xBF29F6FF, 0xEEA56814, 0x3EC5DBDF, 0x0E314BFE,
    0x3FD45F30, 0x6DC9C883, 0x400921FB, 0x50000000, 0x3E6110B4, 0x611A6263, 0x00000000, 0x3F000000,
    0x3F000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C850C[1] = {
    0x4F000000,
};
#endif

#if defined(VERSION_EU_X)
const unsigned int D_auto_rodata_func_802B7130_de_800C8E98[17] = {
    0xBFC55554, 0xBC83656D, 0x3F8110ED, 0x3804C2A0, 0xBF29F6FF, 0xEEA56814, 0x3EC5DBDF, 0x0E314BFE,
    0x3FD45F30, 0x6DC9C883, 0x400921FB, 0x50000000, 0x3E6110B4, 0x611A6263, 0x00000000, 0x3F000000,
    0x3F000000,
};
#endif

#if defined(VERSION_DE)
const unsigned int D_auto_rodata_func_802B7130_de_800C78D8[17] = {
    0xBFC55554, 0xBC83656D, 0x3F8110ED, 0x3804C2A0, 0xBF29F6FF, 0xEEA56814, 0x3EC5DBDF, 0x0E314BFE,
    0x3FD45F30, 0x6DC9C883, 0x400921FB, 0x50000000, 0x3E6110B4, 0x611A6263, 0x00000000, 0x3F000000,
    0x3F000000,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C791C[1] = {
    0x4F000000,
};
#endif
