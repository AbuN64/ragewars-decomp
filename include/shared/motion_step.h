#ifndef RW_MOTION_STEP_H
#define RW_MOTION_STEP_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
/* Contact positions and interpolation outputs used by the movement solver. */
typedef struct MotionSurface { s32 flags; s8 enabled; s8 slopeKind; s8 materialKind; u8 reserved7[5]; f32 response; f32 friction; u8 reserved14[4]; f32 materialResponse; } MotionSurface;
/* Contact result beginning at ActorMotion.collisionState; also passed separately
 * by the actor collision resolver to the contact flag helpers. */
typedef struct MotionContactResult {
    s32 state;
    f32 damping;
    s32 mode;
    s32 material;
    s32 flags;
} MotionContactResult;
typedef struct ActorMotion {
    void *actor; /* 0x00 */
    s32 actorFlags; /* 0x04 */
    f32 field08; /* 0x08 */
    f32 radius; /* 0x0C */
    f32 height; /* 0x10 */
    f32 bottom; /* 0x14 */
    f32 field18; /* 0x18 */
    s32 iteration; /* 0x1C */
    s32 candidate; /* 0x20 */
    s32 grounded;
    s32 candidateIndex; /* 0x28 */
    s32 orientationActive;
    s32 horizontalTicks;
    s32 verticalTicks;
    s32 transitionActive;
    u32 flags;
    MotionSurface *surface;
    Vec3 start;
    Vec3 end;
    Vec3 velocity;
    Vec3 direction;
    Vec3 orientation;
    f32 distance;
    Vec3 boundsMin;
    Vec3 boundsMax;
    f32 horizontalBounds[4];
    s32 queryFlags; /* 0xAC */
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
