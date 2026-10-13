#include "types.h"
#include "gbi.h"
extern f32 D_800C7870_de, D_800C7874_de;
extern void func_802B6C6C_de(f32 [4][4]), func_802B6CBC_de(f32 [4][4], void *);
extern f32 func_802B72B0_de(f32);
void func_802B6670_de(void *out, f32 ex, f32 ey, f32 ez, f32 ax, f32 ay, f32 az, f32 ux, f32 uy, f32 uz)
{
    f32 matrix[4][4];
    f32 (*matrixPointer)[4] = matrix;
    f32 x, y, z, rx, ry, rz, vx, vy, vz, scale, one;
    func_802B6C6C_de(matrixPointer);
    x = ax - ex; y = ay - ey; z = az - ez;
    scale = D_800C7870_de / func_802B72B0_de((x*x + y*y) + z*z);
    x *= scale; z *= scale; y *= scale;
    rx = uy*z - uz*y;
    ry = uz*x - ux*z;
    rz = ux*y - uy*x;
    one = D_800C7874_de;
    scale = one / func_802B72B0_de((rx*rx + ry*ry) + rz*rz);
    rx *= scale; rz *= scale; ry *= scale;
    vx = y*rz - z*ry;
    vy = z*rx - x*rz;
    vz = x*ry - y*rx;
    scale = one / func_802B72B0_de((vx*vx + vy*vy) + vz*vz);
    vx *= scale; vy *= scale; vz *= scale;
    matrix[0][0] = rx; matrix[1][0] = ry; matrix[2][0] = rz;
    matrix[0][1] = vx; matrix[1][1] = vy; matrix[2][1] = vz;
    matrix[0][2] = x; matrix[1][2] = y; matrix[2][2] = z;
    matrix[0][3] = 0.0f; matrix[1][3] = 0.0f; matrix[2][3] = 0.0f;
    matrix[3][0] = -((ex*rx + ey*ry) + ez*rz);
    matrix[3][1] = -((ex*vx + ey*vy) + ez*vz);
    matrix[3][2] = -((ex*x + ey*y) + ez*z);
    matrix[3][3] = one;
    func_802B6CBC_de(matrixPointer, out);
}
