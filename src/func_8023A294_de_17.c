#include "shared/motion_step.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8023B9A0.h"
#include "span_1000/code_8023EEF0.h"
#include "types.h"
#include "span_1000/code_8023A284.h"





extern void func_80271F68_de(Vec3 *, Vec3 *, Vec3 *);
extern f32 func_802B72B0_de(f32);
extern void func_80271F9C_de(void *, void *, f32);
extern void func_8023F43C_de(void *arg0);
extern void func_80242BF0_de(void *arg0);
extern void func_80243920_de(void *arg0);









s32 func_8023D158_de(ActorMotion *object) {
    s32 *flags = &object->surface->flags;
    f32 magnitude;
    f32 var_f0;
    f32 var_f1;
    f32 var_f0_2;
    f32 var_f1_2;
    f32 var_f2;
    f32 var_f0_3;

    func_80240C8C_de(&object->collisionState);
    func_80271F68_de(&object->velocity,
                  &object->end,
                  &object->start);
    magnitude = func_802B72B0_de(
        (object->velocity.x * object->velocity.x) +
        (object->velocity.y * object->velocity.y) +
        (object->velocity.z * object->velocity.z));
    object->distance = magnitude;
    if ((magnitude == 0.0f) && (object->actorFlags == 0)) {
        return 0;
    }

    if (object->distance != 0.0f) {
        func_80271F9C_de(&object->direction,
                      &object->velocity,
                      D_800C3630_de / object->distance);
    } else {
        object->direction = object->velocity;
    }

    var_f0 = object->end.x;
    if (!(var_f0 <= object->start.x)) {
        var_f0 = object->start.x;
    }
    object->boundsMin.x = var_f0;
    var_f1 = object->end.x;
    if (!(object->start.x <= var_f1)) {
        var_f1 = object->start.x;
    }
    object->boundsMax.x = var_f1;

    var_f0_2 = object->end.y;
    if (!(var_f0_2 <= object->start.y)) {
        var_f0_2 = object->start.y;
    }
    object->boundsMin.y = var_f0_2;
    var_f1_2 = object->end.y;
    if (!(object->start.y <= var_f1_2)) {
        var_f1_2 = object->start.y;
    }
    object->boundsMax.y = var_f1_2;

    var_f2 = object->end.z;
    if (!(var_f2 <= object->start.z)) {
        var_f2 = object->start.z;
    }
    object->boundsMin.z = var_f2;
    var_f0_3 = object->end.z;
    if (!(object->start.z <= var_f0_3)) {
        var_f0_3 = object->start.z;
    }
    object->boundsMax.z = var_f0_3;

    object->horizontalBounds[0] = object->boundsMin.x;
    object->horizontalBounds[2] = object->boundsMax.x;
    object->horizontalBounds[3] = object->boundsMax.z;
    object->horizontalBounds[1] = object->boundsMin.z;

    if (*flags & 0x200000) {
        func_8023F43C_de(object);
    }
    if (object->distance != 0.0f) {
        if (*flags & 0x10000) {
            func_80240260_de(object);
        }
        if (*flags & 0x4000) {
            func_80242BF0_de(object);
        }
        if (*flags & 0x80000) {
            func_80243920_de(object);
        }
    }
    return object->collisionState != 0;
}
