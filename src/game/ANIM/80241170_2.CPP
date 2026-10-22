#include "TYPES.H"
#include "ANIM/MEASUREDRECAT8V3.H"
#include "ANIM/MEASUREDRECAT8V4.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OUTPUT.H"
#include "ANIM/RAY180.H"
#include "stddef.h"

s32 func_80271FC8_de(CVector3 *, u32, void *, void *);

/* Tests a point against every edge plane of a polygon. */


 /* extern */
void func_80272018_de(f32 *, void *, f32 *);

s32 func_802412D0_de(void *arg0, void *arg1, void *arg2, f32 *arg3) {
    extern void func_80271F68_de(f32 *, void *, void *);
    f32 sp10[3];
    f32 sp20[3];
    f32 temp_f20;
    f32 var_f0;
    s32 var_v0;

    if (((struct MeasuredRecAt8V3 *)(arg0))->value == 0) {
        return 0;
    }
    func_80271F68_de(sp10, arg2, arg1);
    temp_f20 = (((struct MeasuredRecAt48V1 *)(arg0))->value * sp10[0]) + (((struct Measured *)(arg0))->value * sp10[1]) + (((struct Measured_func_802412D0_de_48a8d17d95e2 *)(arg0))->value * sp10[2]);
    var_v0 = 0;
    if (!(temp_f20 >= (f32)0)) {
        func_80271F68_de(sp20, arg1, arg0 + 0x18);
        var_v0 = 1;
        var_f0 = -((((struct MeasuredRecAt48V1 *)(arg0))->value * sp20[0]) + (((struct Measured *)(arg0))->value * sp20[1]) + (((struct Measured_func_802412D0_de_48a8d17d95e2 *)(arg0))->value * sp20[2])) / temp_f20;
    } else {
        var_f0 = D_800C3740_de;
    }
    *arg3 = var_f0;
    return var_v0;
}

s32 func_802413C8_de(void *arg0, void *arg1, void *arg2, void *arg3) {
    extern void func_80271F68_de(f32 *, void *, void *);
    f32 sp10[3];
    f32 sp20[3];
    f32 sp30;
    f32 temp_f20;
    s32 var_v0;

    if (((struct MeasuredRecAt8V4 *)(arg0))->value == 0) {
        var_v0 = 0;
    } else {
        func_80271F68_de(sp10, arg2, arg1);
        temp_f20 = (((struct MeasuredRecAt48V2 *)(arg0))->value * sp10[0]) + (((struct Measured *)(arg0))->value * sp10[1]) + (((struct Measured_func_802413C8_de_48a8d17d95e2 *)(arg0))->value * sp10[2]);
        var_v0 = 0;
        if (temp_f20 >= (f32)0) {
            sp30 = D_800C3744_de;
        } else {
            func_80271F68_de(sp20, arg1, arg0 + 0x18);
            var_v0 = 1;
            sp30 = -((((struct MeasuredRecAt48V2 *)(arg0))->value * sp20[0]) + (((struct Measured *)(arg0))->value * sp20[1]) + (((struct Measured_func_802413C8_de_48a8d17d95e2 *)(arg0))->value * sp20[2])) / temp_f20;
        }
    }
    if (var_v0 != 0) {
        func_80271FC8_de(arg3, *(u32 *)&sp30, arg1, arg2);
        return 1;
    }
    return 0;
}

/* extern */
s32 func_802414F4_de(func_80204468_S3 *arg0, void *arg1) {
    void func_80271F68_de(f32 *, void *, void *);
    f32 sp10[3];
    f32 sp20[3];
    f32 sp30[3];
    s32 temp_v1;
    void *var_s1;
    s32 var_s0;
    void *var_s2;
    temp_v1 = ((Polygon_func_8023E8D4_de *)arg0)->vertexCount;
    if (temp_v1 == 1) {
        return 1;
    }
    var_s2 = (char *)arg0 + ((temp_v1 * 0xC) + 0xC);
    var_s1 = ((Polygon_func_8023E8D4_de *)arg0)->vertices;
    var_s0 = temp_v1;
    var_s0 = var_s0 - 1;
    for (; var_s0 != -1; var_s1 += 0xC, var_s0--) {
        func_80271F68_de(sp20, var_s1, var_s2);
        func_80272018_de(sp10, &((Polygon_func_8023E8D4_de *)arg0)->normal, sp20);
        func_80271F68_de(sp30, arg1, var_s2);
        var_s2 = var_s1;
        if (sp10[0]*sp30[0]+sp10[1]*sp30[1]+sp10[2]*sp30[2] > 0.0f) return 0;
    }
    return 1;
}

s32 func_80241614_de(void *arg0, void *arg1, f32 arg2, void *arg3) {
    CVector3 *first = arg1;
    CVector3 *second = arg3;
    f32 dx = first->x - second->x;
    f32 dz = first->z - second->z;
    s32 result = 1;
    if (!((dx * dx + dz * dz) <= (arg2 * arg2))) {
        result = 0;
    }
    return result;
}

/* Tests whether a point lies inside an object's four-sided footprint: for each edge of the corners at 0x18 it checks the side the point falls on in the x-z plane, walking the edges in reverse when the winding value at 0x4C is negative. */





s32 func_80241668_de(Footprint *fp, CVector3 *p)
{
    s32 i;
    CVector3 *a;
    CVector3 *b;
    f32 ax;

    for (i = 0; i < 4; i++) {
        if (fp->winding < 0.0f) {
            b = &fp->corner[i];
            a = &fp->corner[(i + 1) & 3];
        } else {
            a = &fp->corner[i];
            b = &fp->corner[(i + 1) & 3];
        }
        ax = a->x;
        if (0.0f < (b->z - a->z) * (p->x - ax) + (ax - b->x) * (p->z - a->z)) {
            return 0;
        }
    }
    return 1;
}

f32 func_80241728_de(void *arg0, f32 arg1, f32 arg2) {
    CVector3 normal;
    CVector3 point;

    normal = ((SurfaceHit *)arg0)->normal;
    if (normal.y == 0.0f) {
        return ((SurfaceHit *)arg0)->point.y;
    }
    point = ((SurfaceHit *)arg0)->point;
    return (((point.z - arg2) * normal.z) + ((point.x - arg1) * normal.x) + (point.y * normal.y)) / normal.y;
}
