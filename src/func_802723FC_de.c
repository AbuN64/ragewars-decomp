#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80271B18.h"

extern f32 func_802B72B0_de(f32);

static __inline__ Vec3 project(Vec3 *arg0, Vec3 *arg1) {
    Vec3 projected;
    f32 dot;

    dot = (arg0->x * arg1->x) + (arg0->y * arg1->y) + (arg0->z * arg1->z);
    projected.x = arg0->x - (dot * arg1->x);
    projected.y = arg0->y - (dot * arg1->y);
    projected.z = arg0->z - (dot * arg1->z);
    return projected;
}

Vec3 func_802723FC_de(Vec3 *arg0, Vec3 *arg1) {
    Vec3 projected;
    f32 projectedMagnitude;
    f32 magnitudeRatio;

    projected = project(arg0, arg1);

    projectedMagnitude = func_802B72B0_de((projected.x * projected.x) +
                                       (projected.y * projected.y) +
                                       (projected.z * projected.z));
    if (projectedMagnitude != 0.0f) {
        magnitudeRatio = func_802B72B0_de((arg0->x * arg0->x) +
                                       (arg0->y * arg0->y) +
                                       (arg0->z * arg0->z)) / projectedMagnitude;

        projected.x *= magnitudeRatio;
        projected.y *= magnitudeRatio;
        projected.z *= magnitudeRatio;
    }

    return projected;
}

extern f32 func_802B72B0_de(f32);

s32 func_8027254C_de(f32 *arg0, f32 arg1) {
    f32 magSq;
    f32 mag;
    f32 scale;

    magSq = (arg0[0] * arg0[0]) + (arg0[1] * arg0[1]) + (arg0[2] * arg0[2]);
    if ((arg1 * arg1) < magSq) {
        mag = func_802B72B0_de(magSq);
        if (mag == 0.0f) {
            return 0;
        }
        scale = arg1 / mag;
        arg0[0] = arg0[0] * scale;
        arg0[1] = arg0[1] * scale;
        arg0[2] = arg0[2] * scale;
        return 1;
    }
    return 0;
}
