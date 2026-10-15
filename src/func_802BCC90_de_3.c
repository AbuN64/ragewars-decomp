#include "span_1000/code_802B7058.h"
#include "types.h"
/* guPerspectiveF, drafted from ultralib src/gu/perspective.c. This library evaluates it in single
   precision against the cartridge's constants: pi/180 and 0.5 at D_800CCB08, -1 and 2 at
   D_800CCB10, 2 * 65536 and 2^31 at D_800CCB18; the float-to-u16 conversion of the perspective
   normalisation is written out in GCC's order. */
extern const float D_800CCB08; /* pi/180 */
extern const float D_800C78BC_de; /* 0.5 */
extern const float D_800CCB10; /* -1, followed by 2 */
extern const float D_800CCB18; /* 2 * 65536, followed by 2^31 */
extern void func_802B6C6C_de(float mf[4][4]);


void func_802B6F9C_de(float mf[4][4], u16 *perspNorm, float fovy, float aspect, float near, float far, float scale)
{
    float cot;
    int i, j;
    float norm;
    unsigned int value;
    func_802B6C6C_de(mf);
    fovy *= D_800CCB08;
    fovy *= D_800C78BC_de;
    cot = func_802B6560_de(fovy) / func_802B7130_de(fovy);
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
