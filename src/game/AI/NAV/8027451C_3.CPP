#include "COMMON/PACKED.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "FX_2/80271B18.H"

/* Returns whether a polygon counts as a wall: without flag 0x2000 it returns its flag 8, and otherwise it takes the polygon's unit normal (recomputed from its edges into D_80115E10 and normalised into D_80115E20 whenever the polygon differs from the last one) and returns whether the normal's upward component is at most D_800C9AD8. */







extern Triangle *D_800CD3E8;

extern Triangle *D_800CD3EC;





extern void Particle_SubtractVectors(CVector3 *out, CVector3 *a, CVector3 *b);

extern void Particle_CrossVectors(CVector3 *out, CVector3 *a, CVector3 *b);


static inline void edge(CVector3 *out, CVector3 *a, CVector3 *b) {
    Particle_SubtractVectors(out, a, b);
}

static inline void normalize_copy(CVector3 *out, CVector3 *in) {
    *out = *in;
    Particle_NormalizeVec3(out);
}

s32 func_802757E4_de(Triangle *polygon) {
    CVector3 up;
    CVector3 normal;
    CVector3 edge0;
    CVector3 edge1;

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
            Particle_CrossVectors(&D_80115E10, &edge0, &edge1);
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

void Nav_ComputePointBounds(f32 *arg0, s32 arg1, CVector3 *arg2)
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
