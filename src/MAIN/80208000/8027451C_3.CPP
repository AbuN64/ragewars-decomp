#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8027451C.h"
#include "TYPES.H"

/* Returns whether a polygon counts as a wall: without flag 0x2000 it returns its flag 8, and otherwise it takes the polygon's unit normal (recomputed from its edges into D_80115E10 and normalised into D_80115E20 whenever the polygon differs from the last one) and returns whether the normal's upward component is at most D_800C9AD8. */







extern Triangle *D_800CD3E8;
extern Triangle *D_800CD3EC;
extern Vec3 D_80115E10;
extern f32 D_80111D54;
extern s32 D_80111D58;
extern Vec3 D_80115E20;
extern void func_80271F68_de(Vec3 *out, Vec3 *a, Vec3 *b);
extern void func_80272018_de(Vec3 *out, Vec3 *a, Vec3 *b);
extern void func_8027207C_de(Vec3 *v);

static inline void edge(Vec3 *out, Vec3 *a, Vec3 *b) {
    func_80271F68_de(out, a, b);
}

static inline void normalize_copy(Vec3 *out, Vec3 *in) {
    *out = *in;
    func_8027207C_de(out);
}

s32 func_802757E4_de(Triangle *polygon) {
    Vec3 up;
    Vec3 normal;
    Vec3 edge0;
    Vec3 edge1;

    if (polygon == 0) {
        return 0;
    }
    if (!(polygon->flags & 0x2000)) {
        return polygon->flags & 8;
    }
    up.x = 0.0f;
    up.y = *(&D_800C49E0_de + 1);
    up.z = 0.0f;
    if (polygon != D_800CD3EC) {
        if (polygon == 0) {
            *(s32 *)&D_80115E10 = 0;
            D_80111D54 = *(&D_800C49E0_de + 1);
            D_80111D58 = 0;
        } else if (polygon != D_800CD3E8) {
            edge(&edge0, polygon->vertices[1], polygon->vertices[0]);
            edge(&edge1, polygon->vertices[2], polygon->vertices[1]);
            func_80272018_de(&D_80115E10, &edge0, &edge1);
        }
        D_800CD3E8 = polygon;
        normalize_copy(&D_80115E20, &D_80115E10);
    }
    normal = D_80115E20;
    D_800CD3EC = polygon;
    if (normal.x * up.x + normal.y * up.y + normal.z * up.z <= D_800C9AD8) {
        return 1;
    }
    return 0;
}

void func_80275954_de(f32 *arg0, s32 arg1, Vec3 *arg2)
{
    s32 i;

    i = 0;
    if (arg1 != 0) {
        arg0[0] = arg2->x;
        arg0[1] = arg2->y;
        arg0[2] = arg2->z;
        arg0[3] = arg2->x;
        arg0[4] = arg2->y;
        arg1 -= 1;
        arg0[5] = arg2->z;
        arg2 += 1;

        if (arg1 > 0) {
bounds_loop:
                {
                    f32 value = arg2->x;
                    f32 bound = arg0[0];
                    if (!(value <= bound)) {
                        value = bound;
                    }
                    arg0[0] = value;
                }

                {
                    f32 value = arg2->y;
                    f32 bound = arg0[1];
                    if (!(value <= bound)) {
                        value = bound;
                    }
                    arg0[1] = value;
                }

                {
                    f32 value = arg2->z;
                    f32 bound = arg0[2];
                    if (!(value <= bound)) {
                        value = bound;
                    }
                    arg0[2] = value;
                }

                {
                    f32 value = arg2->x;
                    f32 bound = arg0[3];
                    if (!(bound <= value)) {
                        value = bound;
                    }
                    arg0[3] = value;
                }

                {
                    f32 value = arg2->y;
                    f32 bound = arg0[4];
                    if (!(bound <= value)) {
                        value = bound;
                    }
                    arg0[4] = value;
                }

                {
                    f32 value = arg2->z;
                    f32 bound = arg0[5];
                    if (!(bound <= value)) {
                        value = bound;
                    }
                    arg0[5] = value;
                }

                i += 1;
                arg2 += 1;
            if (i < arg1) goto bounds_loop;
        }
    }
}
