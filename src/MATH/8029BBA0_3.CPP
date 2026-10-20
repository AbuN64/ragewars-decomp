#include "include_asm.h"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OBJRECAT3CV2.H"
#include "TYPES.H"
#include "MATH/8029BBA0_3.H"
#include "RESMGR/802A0888_4.H"

/* Clips a polygon of n vertices against the plane a*x + b*y + c*z + d >= 0 (Sutherland-Hodgman): walks each edge from the previous vertex, copies inside vertices to the output, and where an edge crosses the plane emits the intersection point (the edge midpoint when the edge is nearly parallel to the plane), storing the output count and returning whether any intersection was emitted. */



s32 func_8029C4A0_de(CVector3 *out, s32 *outCount, CVector3 *in, s32 n, f32 a, f32 b, f32 c, f32 d) {
    CVector3 delta;
    CVector3 *prev;
    CVector3 *point;
    CVector3 *cur;
    s32 count;
    s32 clipped;
    s32 i;
    s32 prevInside;
    s32 inside;
    f32 dot;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dist;
    f32 t;

    count = 0;
    clipped = 0;
    *outCount = 0;
    if (n == 0) {
        return 0;
    }
    prev = &in[n - 1];
    prevInside = prev->x * a + prev->y * b + prev->z * c + d >= 0.0f;
    for (i = 0; i < n; i++) {
        cur = &in[i];
        inside = cur->x * a + cur->y * b + cur->z * c + d >= 0.0f;
        if (prevInside) {
            *out++ = *prev;
            count++;
        }
        if (prevInside != inside) {
            dx = cur->x - prev->x;
            delta.x = dx;
            dx = a * delta.x;
            dy = cur->y - prev->y;
            delta.y = dy;
            dy = b * delta.y;
            dz = cur->z - prev->z;
            delta.z = dz;
            dz = c * delta.z;
            dot = dx + dy + dz;
            dist = a * prev->x + b * prev->y + c * prev->z + d;
            clipped = 1;
            point = out++;
            count++;
            dist = -dist;
            if (dot < 0.001f && (t = 0.5f, -0.001f < dot)) {
            } else {
                t = dist / dot;
            }
            point->x = prev->x + t * delta.x;
            point->y = prev->y + t * delta.y;
            point->z = prev->z + t * delta.z;
        }
        prev = cur;
        prevInside = inside;
    }
    *outCount = count;
    return clipped;
}

#ifdef NON_MATCHING
#include "TYPES.H"

extern f32 D_800C5A90_de, D_800C5A94, D_800C5A98_de, D_800C5A9C, D_800C5AA0_de;

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
#else
INCLUDE_ASM("span_1000", func_8029C6A8_de);
#endif
