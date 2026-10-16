#include "TYPES.H"
extern f32 D_800C7878_de, D_800C787C_de;
extern void func_802B6C6C_de(f32 matrix[4][4]);
extern f32 func_802B72B0_de(f32);

/* Floating-point look-at matrix, with an orthonormal camera basis. */
void func_802B6900_de(f32 matrix[4][4], f32 eyeX, f32 eyeY, f32 eyeZ,
                      f32 atX, f32 atY, f32 atZ, f32 upX, f32 upY, f32 upZ) {
    f32 lookX, lookY, lookZ;
    f32 rightX, rightY, rightZ;
    f32 scale;
    func_802B6C6C_de(matrix);
    lookX = atX - eyeX;
    lookY = atY - eyeY;
    lookZ = atZ - eyeZ;
    scale = D_800C7878_de / func_802B72B0_de(lookX * lookX + lookY * lookY + lookZ * lookZ);
    lookX *= scale;
    lookY *= scale;
    lookZ *= scale;
    rightX = upY * lookZ - upZ * lookY;
    rightY = upZ * lookX - upX * lookZ;
    rightZ = upX * lookY - upY * lookX;
    scale = D_800C787C_de / func_802B72B0_de(rightX * rightX + rightY * rightY + rightZ * rightZ);
    rightX *= scale;
    rightY *= scale;
    rightZ *= scale;
    upX = lookY * rightZ - lookZ * rightY;
    upY = lookZ * rightX - lookX * rightZ;
    upZ = lookX * rightY - lookY * rightX;
    scale = D_800C787C_de / func_802B72B0_de(upX * upX + upY * upY + upZ * upZ);
    upX *= scale;
    upY *= scale;
    upZ *= scale;
    matrix[0][0] = rightX;
    matrix[1][0] = rightY;
    matrix[2][0] = rightZ;
    matrix[0][1] = upX;
    matrix[1][1] = upY;
    matrix[2][1] = upZ;
    matrix[0][2] = lookX;
    matrix[1][2] = lookY;
    matrix[2][2] = lookZ;
    matrix[3][0] = -(eyeX * rightX + eyeY * rightY + eyeZ * rightZ);
    matrix[3][1] = -(eyeX * upX + eyeY * upY + eyeZ * upZ);
    matrix[3][2] = -(eyeX * lookX + eyeY * lookY + eyeZ * lookZ);
    matrix[0][3] = matrix[1][3] = matrix[2][3] = 0.0f;
    matrix[3][3] = D_800C787C_de;
}
