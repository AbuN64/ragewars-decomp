#include "span_1000/code_8027451C.h"
/* Builds a look-at view matrix (ultralib guLookAtF) from an eye, a target and an up vector,
   substituting a fallback x component when the up vector is parallel to the view direction.
   Adapted from ultralib gu/lookat.c with single-precision const extern constants, the degenerate check and the 1.0 held in a temporary. */
extern const float D_800C49A8_de;
extern const float D_800C49B0_de;
extern void func_802B6C6C_de(float mf[4][4]);
extern float func_802B72B0_de(float);

void func_80274DFC_de(float mf[4][4], float xEye, float yEye, float zEye,
                   float xAt, float yAt, float zAt,
                   float xUp, float yUp, float zUp)
{
    float one, len, xLook, yLook, zLook, xRight, yRight, zRight;

    func_802B6C6C_de(mf);

    xLook = xAt - xEye;
    yLook = yAt - yEye;
    zLook = zAt - zEye;

    len = D_800C49A8_de / func_802B72B0_de(xLook * xLook + yLook * yLook + zLook * zLook);
    xLook *= len;
    yLook *= len;
    zLook *= len;

    xRight = yUp * zLook - zUp * yLook;
    yRight = zUp * xLook - xUp * zLook;
    zRight = xUp * yLook - yUp * xLook;
    if (xRight == 0.0f && yRight == 0.0f && zRight == 0.0f) {
        xRight = (&D_800C49A8_de)[1];
    }
    one = D_800C49B0_de;
    len = one / func_802B72B0_de(xRight * xRight + yRight * yRight + zRight * zRight);
    xRight *= len;
    yRight *= len;
    zRight *= len;

    xUp = yLook * zRight - zLook * yRight;
    yUp = zLook * xRight - xLook * zRight;
    zUp = xLook * yRight - yLook * xRight;
    len = one / func_802B72B0_de(xUp * xUp + yUp * yUp + zUp * zUp);
    xUp *= len;
    yUp *= len;
    zUp *= len;

    mf[0][0] = xRight;
    mf[1][0] = yRight;
    mf[2][0] = zRight;
    mf[3][0] = -(xEye * xRight + yEye * yRight + zEye * zRight);

    mf[0][1] = xUp;
    mf[1][1] = yUp;
    mf[2][1] = zUp;
    mf[3][1] = -(xEye * xUp + yEye * yUp + zEye * zUp);

    mf[0][2] = xLook;
    mf[1][2] = yLook;
    mf[2][2] = zLook;
    mf[3][2] = -(xEye * xLook + yEye * yLook + zEye * zLook);

    mf[0][3] = 0;
    mf[1][3] = 0;
    mf[2][3] = 0;
    mf[3][3] = one;
}
