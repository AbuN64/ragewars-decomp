#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_16E000/code_80400000.h"
#include "TYPES.H"
/* Evaluates the position keyframe track 1 of the current record's resource at time t: holds the
   first or last key's position outside the track, is zero when the track is empty, and otherwise
   blends the surrounding keys' positions linearly with the vector scale and add helpers. Vector
   counterpart of func_8040170C_de. */







extern func_80203E78_S1 *D_800E2830;

extern s32 *func_8028FDB4_de(s32 resource, s32 index);
extern void func_80271F9C_de(Vec3 *out, Vec3 *in, f32 scale);
extern void func_80271F34_de(Vec3 *out, Vec3 *a, Vec3 *b);

Vec3 func_80401564_de(f32 t) {
    s32 *track;
    PositionKey *key;
    s32 count;
    f32 u;
    Vec3 result;
    Vec3 a;
    Vec3 b;

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
