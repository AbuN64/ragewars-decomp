#include "include_asm.h"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/ENTRYRECAT8V4.H"
#include "TYPES.H"
#include "MENU_2/80400000_5.H"
#include "RENDER_4/8028FD2C_6.H"

/* Evaluates the position keyframe track 1 of the current record's resource at time t: holds the
   first or last key's position outside the track, is zero when the track is empty, and otherwise
   blends the surrounding keys' positions linearly with the vector scale and add helpers. Vector
   counterpart of func_8040170C_de. */







extern func_80203E78_S1 *D_800E2830;

extern void func_80271F9C_de(CVector3 *out, CVector3 *in, f32 scale);
extern void func_80271F34_de(CVector3 *out, CVector3 *a, CVector3 *b);

CVector3 func_80401564_de(f32 t) {
    s32 *track;
    PositionKey *key;
    s32 count;
    f32 u;
    CVector3 result;
    CVector3 a;
    CVector3 b;

    track = func_8028FDB4_de(D_800E2830->unk4, 1);
    count = track[1];
    key = (PositionKey *)(track + 2);
    if (count == 0) {
        result.x = 0.0f;
        result.y = 0.0f;
        result.z = 0.0f;
        return result;
    } else if (t <= key[0].time) {
        result.x = key[0].x;
        result.y = key[0].y;
        result.z = key[0].z;
        return result;
    } else if (key[count - 1].time <= t) {
        result.x = key[count - 1].x;
        result.y = key[count - 1].y;
        result.z = key[count - 1].z;
        return result;
    } else {
        while (key->time < t) {
            key++;
        }
        u = (t - key[-1].time) / (key->time - key[-1].time);
        a.x = key[-1].x;
        a.y = key[-1].y;
        a.z = key[-1].z;
        b.x = key->x;
        b.y = key->y;
        b.z = key->z;
        func_80271F9C_de(&a, &a, (1.0f) - u);
        func_80271F9C_de(&b, &b, u);
        func_80271F34_de(&result, &a, &b);
    }
    return result;
}

#if defined(VERSION_US)
const unsigned int rodata_func_8040170C_de_800DB7DC[2] = {
    0x3F800000, 0x3F800000,
};
#endif

#if defined(VERSION_EU_X)
const unsigned int rodata_func_8040170C_de_800E836C[2] = {
    0x3F800000, 0x3F800000,
};
#endif

#if defined(VERSION_EU)
const unsigned int rodata_func_8040170C_de_800ED1AC[2] = {
    0x3F800000, 0x3F800000,
};
#endif

#if defined(VERSION_DE)
const unsigned int rodata_func_8040170C_de_800DCB2C[2] = {
    0x3F800000, 0x3F800000,
};
#endif
