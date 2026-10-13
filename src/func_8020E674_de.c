#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8020D370.h"
#include "types.h"
#include "common/unused.h"
typedef struct World World;












extern char D_80103FD0;
extern World *D_80103FCC;



extern s32 func_802444A4_de(InstanceHdr *arg0, Vec3 current, Vec3 desired,
                          void *collisionInfo);





s32 func_8020E674_de(Actor_func_8020E674_de *actor, f32 scale, f32 lateral) {
    Vec3 current;
    Vec3 desired;
    Vec3 delta;
    Vec3 acceleration;
    f32 invDuration;
    f32 total;
    f32 segment;
    f32 elapsed;
    f32 accelScale;
    f32 accelX;
    f32 accelY;
    f32 accelZ;
    s32 count;
    s32 i;

    if (actor == 0 || actor->field264 == 0.0f) {
        return 0;
    }

    invDuration = D_800C1E40_de / actor->field264;
    delta.x = (actor->field258 - ((Actor_func_8024A7A0_de *)actor->instance)->position0.x) * invDuration;
    delta.x *= scale * func_802B6560_de(actor->field278);
    delta.z = (actor->field260 - ((Actor_func_8024A7A0_de *)actor->instance)->position0.z) * invDuration;
    delta.z *= scale * func_802B6560_de(actor->field278);
    delta.y = scale * func_802B7130_de(actor->field278);

    acceleration.x = 0.0f;
    acceleration.y = lateral;
    acceleration.z = 0.0f;

    total = (scale * func_802B6560_de(actor->field278)) / actor->field264;
    if (total == 0.0f) {
        return 0;
    }
    count = (s32)(total * D_800C1E44_de);
    if (count == 0) {
        return 0;
    }

    segment = total / (f32)count;
    current = ((Actor_func_8024A7A0_de *)actor->instance)->position0;
    accelScale = segment * segment * D_800C1E48_de;
    accelX = acceleration.x * accelScale;
    accelY = acceleration.y * accelScale;
    accelZ = acceleration.z * accelScale;

    desired.x = current.x + delta.x * segment + accelX;
    desired.y = current.y + delta.y * segment + accelY;
    desired.z = current.z + delta.z * segment + accelZ;

    elapsed = segment;

    if (func_802444A4_de(actor->instance, current, desired, &D_80103FD0) != 0 &&
        (unsigned)(D_80103FCC->state - 7) >= 2) {
        return 1;
    }

    i = 0;
    delta.x += acceleration.x * elapsed;
    delta.y += acceleration.x * elapsed;
    delta.z += acceleration.x * elapsed;
    elapsed += segment;

    while (i < count) {
        current = desired;
        desired.x = current.x + delta.x * elapsed + accelX;
        desired.y = current.y + delta.y * elapsed + accelY;
        desired.z = current.z + delta.z * elapsed + accelZ;

        if (func_802444A4_de(actor->instance, current, desired, &D_80103FD0) != 0 &&
            (unsigned)(D_80103FCC->state - 7) >= 2) {
            return 1;
        }

        delta.x += acceleration.x * elapsed;
        delta.y += acceleration.x * elapsed;
        delta.z += acceleration.x * elapsed;
        elapsed += segment;
        i++;
    }
    return 0;
}
