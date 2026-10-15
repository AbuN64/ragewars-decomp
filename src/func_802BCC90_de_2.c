#include "types.h"

extern void func_802B6C6C_de(u8 *mf);          /* guMtxIdentF */
extern void func_802B6CBC_de(f32 *mf, s32 *m);  /* guMtxF2L */
                     /* cosf */
                     /* sinf */
extern f32 D_800C78A0_de; /* pi/180 */
extern f32 D_800C78A4_de; /* half */
extern f32 D_800C78A8_de; /* -1 */
extern f32 D_800C78AC_de; /* 2 */
extern f32 D_800C78B0_de; /* 2 * 65536 */
extern f32 D_800C78B4_de; /* 2^31 */

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
    cot = func_802B6560_de(fovy) / func_802B7130_de(fovy);

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
