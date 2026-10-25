#include "COMMON/PACKED.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "TYPES.H"
#include "FX_2/80271B18.H"

/* Returns the rotation quaternion that tilts the up axis onto a polygon's unit normal (recomputed from its edges into D_80115E10 and normalised into D_80115E20 whenever the polygon differs from the last one, straight up for no polygon), recording the half-angle sine in D_80115DEC and giving the identity when the normal is vertical. Adapted from func_80275688_de with the cached polygon normal of func_802757E4_de replacing func_802750B0_de and the default normals written through their separate cells. */







extern Triangle *D_800CD3E8;

extern Triangle *D_800CD3EC;

extern CVector3 D_80115E10;

extern f32 D_80111D54;

extern s32 D_80111D58;

extern CVector3 D_80115E20;

extern f32 D_80111D64;

extern s32 D_80111D68;

extern f32 D_80115DEC;

extern void Particle_SubtractVectors(CVector3 *out, CVector3 *a, CVector3 *b);

extern void Particle_CrossVectors(CVector3 *out, CVector3 *a, CVector3 *b);


extern void Particle_ScaleVector(CVector3 *out, CVector3 *in, f32 scale);

extern f32 Math_Sqrtf(f32);

static inline void edge(CVector3 *out, CVector3 *a, CVector3 *b) {
    Particle_SubtractVectors(out, a, b);
}

static inline void normalize_copy(CVector3 *out, CVector3 *in) {
    *out = *in;
    Particle_NormalizeVec3(out);
}

extern float D_800C49D8_de[];

extern float D_80115DEC;

extern void func_802750B0_de(CVector3 *);

extern void Particle_CrossVectors(CVector3 *, CVector3 *, CVector3 *);

extern void Particle_ScaleVector(CVector3 *, CVector3 *, float);

CQuatern *Nav_GetPolygonUpQuat(CQuatern *out, Triangle *polygon) {
    CVector3 normal;
    CVector3 up;
    CVector3 axis;
    CQuatern result;
    CVector3 edge0;
    CVector3 edge1;
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
            Particle_CrossVectors(&D_80115E10, &edge0, &edge1);
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
    Particle_CrossVectors(&axis, &up, &normal);
    len = Math_Sqrtf(axis.x * axis.x + axis.y * axis.y + axis.z * axis.z);
    if (len == 0.0f) {
        result.z = 0.0f;
        result.y = 0.0f;
        result.x = 0.0f;
        result.w = one;
    } else {
        Particle_ScaleVector(&axis, &axis, one / len);
        angle = Nav_ArcCos(up.x * normal.x + up.y * normal.y + up.z * normal.z);
        angle *= 0.5f;
        scale = Math_Sinf(angle);
        result.x = axis.x * scale;
        result.y = axis.y * scale;
        result.z = axis.z * scale;
        D_80115DEC = scale;
        result.w = Math_Cosf(angle);
    }
    *out = result;
    return out;
}

CQuatern *Nav_GetCachedUpQuat(CQuatern *out, Triangle *polygon) {
    CVector3 a;
    CVector3 up;
    CVector3 axis;
    CQuatern result;
    float len;
    float angle;
    float scale;
    float one;

    func_802750B0_de(&a);
    one = D_800C49D8_de[1];
    up.x = 0;
    up.y = one;
    up.z = 0;
    Particle_CrossVectors(&axis, &up, &a);
    len = Math_Sqrtf(axis.x * axis.x + axis.y * axis.y + axis.z * axis.z);
    if (len == 0) {
        result.z = 0;
        result.y = 0;
        result.x = 0;
        result.w = one;
    } else {
        Particle_ScaleVector(&axis, &axis, one / len);
        angle = Nav_ArcCos(up.x * a.x + up.y * a.y + up.z * a.z);
        angle *= D_800C49E0_de;
        scale = Math_Sinf(angle);
        result.x = axis.x * scale;
        result.y = axis.y * scale;
        result.z = axis.z * scale;
        D_80115DEC = scale;
        result.w = Math_Cosf(angle);
    }
    *out = result;
    return out;
}
