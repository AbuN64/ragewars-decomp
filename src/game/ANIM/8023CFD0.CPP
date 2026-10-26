#include "COMMON/MOTION_STEP.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OWNERRECAT8V2.H"
#include "COMMON/RENDERSORTRECORD.H"
#include "TYPES.H"
#include "COMMON/DESCRIPTORRECAT29.H"
#include "ANIM/8023EEF0_16.H"
#include "ANIM/8023F740.H"

extern void Particle_SubtractVectors(CVector3 *, CVector3 *, CVector3 *);
extern f32 Math_Sqrtf(f32);
extern void Particle_ScaleVector(void *, void *, f32);
extern void func_8023F43C_de(void *arg0);
extern void func_80242BF0_de(void *arg0);
extern void func_80243920_de(void *arg0);









s32 func_8023D158_de(ActorMotion *object) {
    s32 *flags = &object->surface->flags;
    f32 magnitude;
    f32 minimumX;
    f32 maximumX;
    f32 minimumY;
    f32 maximumY;
    f32 minimumZ;
    f32 maximumZ;

    func_80240C8C_de(&object->collisionState);
    Particle_SubtractVectors(&object->velocity,
                  &object->end,
                  &object->start);
    magnitude = Math_Sqrtf(
        (object->velocity.x * object->velocity.x) +
        (object->velocity.y * object->velocity.y) +
        (object->velocity.z * object->velocity.z));
    object->distance = magnitude;
    if ((magnitude == 0.0f) && (object->actorFlags == 0)) {
        return 0;
    }

    if (object->distance != 0.0f) {
        Particle_ScaleVector(&object->direction,
                      &object->velocity,
                      D_800C3630_de / object->distance);
    } else {
        object->direction = object->velocity;
    }

    minimumX = object->end.x;
    if (!(minimumX <= object->start.x)) {
        minimumX = object->start.x;
    }
    object->boundsMin.x = minimumX;
    maximumX = object->end.x;
    if (!(object->start.x <= maximumX)) {
        maximumX = object->start.x;
    }
    object->boundsMax.x = maximumX;

    minimumY = object->end.y;
    if (!(minimumY <= object->start.y)) {
        minimumY = object->start.y;
    }
    object->boundsMin.y = minimumY;
    maximumY = object->end.y;
    if (!(object->start.y <= maximumY)) {
        maximumY = object->start.y;
    }
    object->boundsMax.y = maximumY;

    minimumZ = object->end.z;
    if (!(minimumZ <= object->start.z)) {
        minimumZ = object->start.z;
    }
    object->boundsMin.z = minimumZ;
    maximumZ = object->end.z;
    if (!(object->start.z <= maximumZ)) {
        maximumZ = object->start.z;
    }
    object->boundsMax.z = maximumZ;

    object->horizontalBounds[0] = object->boundsMin.x;
    object->horizontalBounds[2] = object->boundsMax.x;
    object->horizontalBounds[3] = object->boundsMax.z;
    object->horizontalBounds[1] = object->boundsMin.z;

    if (*flags & 0x200000) {
        func_8023F43C_de(object);
    }
    if (object->distance != 0.0f) {
        if (*flags & 0x10000) {
            Anim_ProcessEntityContacts(object);
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
