#ifndef RW_MOTION_STEP_H
#define RW_MOTION_STEP_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
/* Contact positions and interpolation outputs used by the movement solver. */
typedef struct MotionSurface { u8 reserved0[12]; f32 response; } MotionSurface;
typedef struct ActorMotion {
    u8 reserved0[0x24];
    s32 grounded;
    u8 reserved28[4];
    s32 orientationActive;
    s32 horizontalTicks;
    s32 verticalTicks;
    s32 transitionActive;
    u32 flags;
    MotionSurface *surface;
    Vec3 start;
    Vec3 end;
    Vec3 velocity;
    u8 reserved68[12];
    Vec3 orientation;
    f32 distance;
    u8 reserved84[0x2C];
    s32 collisionState;
    f32 damping;
    s32 mode;
    u8 reservedBC[8];
    s32 contactCount;
    Vec3 contacts[4];
    Vec3 normal;
    u8 reserved104[0x78];
    f32 blend;
    Vec3 interpolated;
    u8 reserved18C[12];
    Vec3 position;
    Vec3 projectedOrientation;
} ActorMotion;
#endif
