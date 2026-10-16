#include "TYPES.H"

extern f32 D_800C5A90_de, D_800C5A94, D_800C5A98_de, D_800C5A9C, D_800C5AA0_de;
extern void func_802A0748_de(void *, s32, s32);

void func_8029C6A8_de(f32 *matrix, f32 *angles) {
    u32 mask = 0;
    f32 sy, cy, sx, cx, sz, cz, one;
    if (angles[0] != 0.0f) mask = 4;
    if (angles[1] != 0.0f) mask |= 2;
    if (angles[2] != 0.0f) mask |= 1;
    switch (mask) {
    case 0:
        func_802A0748_de(matrix, 0, 64);
        one = D_800C5A90_de;
        matrix[0] = one; matrix[5] = one; matrix[10] = one; matrix[15] = one;
        return;
    case 2:
        func_802A0748_de(matrix, 0, 64);
        one = D_800C5A94;
        matrix[0] = one; matrix[5] = one; matrix[10] = one; matrix[15] = one;
        func_8029BBB0_de(angles[1], &sy, &cy);
        matrix[8] = sy; matrix[0] = cy; matrix[2] = -sy; matrix[10] = cy;
        return;
    case 4:
        func_802A0748_de(matrix, 0, 64);
        one = D_800C5A98_de;
        matrix[0] = one; matrix[5] = one; matrix[10] = one; matrix[15] = one;
        func_8029BBB0_de(angles[0], &sx, &cx);
        matrix[5] = cx; matrix[9] = -sx; matrix[6] = sx; matrix[10] = cx;
        return;
    case 1:
        func_802A0748_de(matrix, 0, 64);
        one = D_800C5A9C;
        matrix[0] = one; matrix[5] = one; matrix[10] = one; matrix[15] = one;
        func_8029BBB0_de(angles[2], &sz, &cz);
        matrix[0] = cz; matrix[4] = -sz; matrix[1] = sz; matrix[5] = cz;
        return;
    }
    func_8029BBB0_de(angles[0], &sx, &cx);
    func_8029BBB0_de(angles[1], &sy, &cy);
    func_8029BBB0_de(angles[2], &sz, &cz);
    matrix[2] = -sy;
    matrix[0] = cy * cz;
    matrix[1] = cy * sz;
    matrix[10] = cx * cy;
    matrix[14] = 0.0f; matrix[13] = 0.0f; matrix[12] = 0.0f;
    matrix[11] = 0.0f; matrix[7] = 0.0f; matrix[3] = 0.0f;
    matrix[15] = D_800C5AA0_de;
    matrix[6] = sx * cy;
    matrix[4] = sx * sy * cz - cx * sz;
    matrix[8] = cx * cz * sy + sx * sz;
    matrix[5] = sx * sy * sz + cx * cz;
    matrix[9] = cx * sz * sy - sx * cz;
}
