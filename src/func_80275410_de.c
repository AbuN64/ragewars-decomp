#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8027451C.h"
#include "types.h"

/* Returns the rotation quaternion that tilts the up axis onto a polygon's unit normal (recomputed from its edges into D_80115E10 and normalised into D_80115E20 whenever the polygon differs from the last one, straight up for no polygon), recording the half-angle sine in D_80115DEC and giving the identity when the normal is vertical. Adapted from func_80275688_de with the cached polygon normal of func_802757E4_de replacing func_802750B0_de and the default normals written through their separate cells. */







extern Polygon_func_80275410_de *D_800CD3E8;
extern Polygon_func_80275410_de *D_800CD3EC;
extern Vec3 D_80115E10;
extern f32 D_80111D54;
extern s32 D_80111D58;
extern Vec3 D_80115E20;
extern f32 D_80111D64;
extern s32 D_80111D68;
extern f32 D_80115DEC;
extern void func_80271F68_de(Vec3 *out, Vec3 *a, Vec3 *b);
extern void func_80272018_de(Vec3 *out, Vec3 *a, Vec3 *b);
extern void func_8027207C_de(Vec3 *v);
extern void func_80271F9C_de(Vec3 *out, Vec3 *in, f32 scale);
extern f32 func_802B72B0_de(f32);




static inline void edge(Vec3 *out, Vec3 *a, Vec3 *b) {
    func_80271F68_de(out, a, b);
}

static inline void normalize_copy(Vec3 *out, Vec3 *in) {
    *out = *in;
    func_8027207C_de(out);
}

Vector4f *func_80275410_de(Vector4f *out, Polygon_func_80275410_de *polygon) {
    Vec3 normal;
    Vec3 up;
    Vec3 axis;
    Vector4f result;
    Vec3 edge0;
    Vec3 edge1;
    f32 one;
    f32 len;
    f32 angle;
    f32 scale;

    if (polygon == 0) {
        *(s32 *)&D_80115E20 = 0;
        D_80111D68 = 0;
        D_80111D64 = 1.0f;
    } else if (polygon != D_800CD3EC) {
        if (polygon == 0) {
            *(s32 *)&D_80115E10 = 0;
            D_80111D58 = 0;
            D_80111D54 = 1.0f;
        } else if (polygon != D_800CD3E8) {
            edge(&edge0, polygon->vertices[1], polygon->vertices[0]);
            edge(&edge1, polygon->vertices[2], polygon->vertices[1]);
            func_80272018_de(&D_80115E10, &edge0, &edge1);
        }
        D_800CD3E8 = polygon;
        normalize_copy(&D_80115E20, &D_80115E10);
    }
    one = 1.0f;
    D_800CD3EC = polygon;
    normal = D_80115E20;
    up.x = 0.0f;
    up.y = one;
    up.z = 0.0f;
    func_80272018_de(&axis, &up, &normal);
    len = func_802B72B0_de(axis.x * axis.x + axis.y * axis.y + axis.z * axis.z);
    if (len == 0.0f) {
        result.z = 0.0f;
        result.y = 0.0f;
        result.x = 0.0f;
        result.w = one;
    } else {
        func_80271F9C_de(&axis, &axis, one / len);
        angle = func_802745D0_de(up.x * normal.x + up.y * normal.y + up.z * normal.z);
        angle *= 0.5f;
        scale = func_802B7130_de(angle);
        result.x = axis.x * scale;
        result.y = axis.y * scale;
        result.z = axis.z * scale;
        D_80115DEC = scale;
        result.w = func_802B6560_de(angle);
    }
    *out = result;
    return out;
}
