#include "include_asm.h"
#include "COMMON/EXTERNS_2.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_16.H"
#include "COMMON/TRIPLE.H"
#include "sdk/lib_802BB630/802BBC50.H"

#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
const unsigned int D_802B6DEC_CD6F0[5] = {
    0x3C8EFA35, 0x3F000000, 0xBF800000, 0x40000000, 0x48000000,
};
#endif

#if defined(VERSION_US_REV1)
const unsigned int D_auto_src_rw_constants_802B6DEC_CD6F0_us_rev1[5] = {
    0x3C8EFA35, 0x3F000000, 0xBF800000, 0x40000000, 0x48000000,
};
#endif

          /* guMtxIdentF */
extern void func_802B6CBC_de(f32 *mf, s32 *m);

/* guPerspectiveF, drafted from ultralib src/gu/perspective.c. This library evaluates it in single
   precision against the cartridge's constants: pi/180 and 0.5 at D_800CCB08, -1 and 2 at
   D_800CCB10, 2 * 65536 and 2^31 at D_800CCB18; the float-to-u16 conversion of the perspective
   normalisation is written out in GCC's order. */
 /* pi/180 */
 /* 0.5 */
 /* -1, followed by 2 */
 /* 2 * 65536, followed by 2^31 */


  /* guMtxF2L */
                     /* cosf */
                     /* sinf */
 /* pi/180 */
 /* half */
 /* -1 */
 /* 2 */
 /* 2 * 65536 */
 /* 2^31 */

/* guPerspective (libultra gu): builds a perspective projection into a fixed-point matrix and reports its normalisation. */
void func_802B6DF0_de(s32 *m, u16 *perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale) {
    f32 mf[4][4];
    f32 cot;
    f32 norm;
    s32 i, j;
    f32 *row = mf[0];

    func_802B6C6C_de((u8 *)row);
    fovy *= D_800C78A0_de;
    fovy *= D_800C78A4_de;
    cot = Math_Cosf(fovy) / Math_Sinf(fovy);

    mf[0][0] = cot / aspect;
    mf[1][1] = cot;
    mf[2][2] = (near + far) / (near - far);
    mf[2][3] = D_800C78A8_de;
    mf[3][2] = (2 * near * far) / (near - far);
    mf[3][3] = 0;

    for (i = 0; i < 4; i++) {
        f32 *element;
        j = 0;
        element = row;
        for (; j < 4; j++) {
            *element *= scale;
            element++;
        }
        row += 4;
    }

    if (perspNorm != 0) {
        if (near + far <= D_800C78AC_de) {
            *perspNorm = (u16)0xFFFF;
        } else {
            norm = D_800C78B0_de / (near + far);
            *perspNorm = (u16)(u32)norm;
            if (*perspNorm <= 0) {
                *perspNorm = (u16)0x0001;
            }
        }
    }

    func_802B6CBC_de(mf[0], m);
}

void func_802B6F9C_de(float mf[4][4], u16 *perspNorm, float fovy, float aspect, float near, float far, float scale)
{
    float cot;
    int i, j;
    float norm;
    unsigned int value;
    func_802B6C6C_de(mf);
    fovy *= D_800CCB08;
    fovy *= D_800C78BC_de;
    cot = Math_Cosf(fovy) / Math_Sinf(fovy);
    mf[0][0] = cot / aspect;
    mf[1][1] = cot;
    mf[2][2] = (near + far) / (near - far);
    mf[2][3] = D_800CCB10;
    mf[3][2] = (2 * near * far) / (near - far);
    mf[3][3] = 0;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            mf[i][j] *= scale;
    if (perspNorm != (u16 *)0) {
        if (near + far <= (*(&D_800CCB10 + 1))) {
            *perspNorm = (u16)0xFFFF;
        } else {
            norm = D_800CCB18 / (near + far);
            if (norm >= (*(&D_800CCB18 + 1))) {
                goto large;
            }
            value = (int)norm;
            goto converted;
        large:
            value = (int)(norm - (*(&D_800CCB18 + 1)));
            value |= 0x80000000;
        converted:
            *perspNorm = (u16)value;
            if (*perspNorm <= 0)
                *perspNorm = (u16)0x0001;
        }
    }
}

#if !(defined(VERSION_US_REV1))
const unsigned int D_802B6F9C_CD708[6] = {
    0x3C8EFA35, 0x3F000000, 0xBF800000, 0x40000000, 0x48000000, 0x4F000000,
};
#endif

#if defined(VERSION_US_REV1)
const unsigned int D_auto_src_rw_pool_802B6F9C_CD708_us_rev1[6] = {
    0x3C8EFA35, 0x3F000000, 0xBF800000, 0x40000000, 0x48000000, 0x4F000000,
};
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C77B4[8] = {
    0x0B000010, 0x000B0000, 0x00000010, 0x3C8EFA35, 0x3F000000, 0xBF800000, 0x40000000, 0x48000000,
};
#endif

#if defined(NON_MATCHING) && defined(VERSION_US)
unsigned int D_auto_rodata_unresolved_800C77B4[9] = {
    0x0B000010, 0x000B0000, 0x00000010, 0x3C8EFA35, 0x3F000000, 0xBF800000, 0x40000000, 0x48000000,
    0x4F000000,
};
#endif
