#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8028CCB8.h"
#include "types.h"



extern void *func_8028FDB4_de(void *arg0, s32 arg1);
extern void func_80271F68_de(Vec3 *out, void *arg1, void *arg2);









s32 func_8028D28C_de(void *arg0, s32 arg1, void *arg2) {
    Vec3 position;
    AnimationPoseFrameSet *list;
    Shared_World *world = arg0;
    AnimationPoseFrame *item;
    f32 distSq;
    f32 bestDist;
    f32 bestIndex;
    s32 count;
    s32 index;

    bestIndex = D_800C5300_de;
    bestDist = 0.0f;
    index = 0;
    list = func_8028FDB4_de(func_8028FDB4_de(world->routeCount, arg1), 1);
    count = list->count;
    item = list->frames;
    if (count > 0) {
        do {
            func_80271F68_de(&position, arg2, item);
            distSq = (position.x * position.x) +
                     (position.y * position.y) +
                     (position.z * position.z);
            if ((bestIndex < 0.0f) || (distSq < bestDist)) {
                bestIndex = (f32)index;
                bestDist = distSq;
            }
            index += 1;
            item++;
        } while (index < count);
    }
    return (s32)bestIndex;
}
