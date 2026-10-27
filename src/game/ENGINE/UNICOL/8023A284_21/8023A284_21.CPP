#include "include_asm.h"

#include "TYPES.H"
#include "COMMON/MOTION_STEP.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/TRIPLE.H"

void func_8023CFE0_de(ActorMotion *motion) {
    CVector3 acceleration;
    f32 limit;
    f32 drag;
    f32 gravity;
    f32 dt;
    f32 halfDt;
    CCollisionInfo2_t *surface;

    if (motion->orientationActive != 0) {
        dt = D_800D2988 * D_800C3620_de;
        surface = motion->surface;
        if (dt != 0.0f) {
            drag = surface->AirFriction;
            drag *= D_800C3624_de;
            limit = D_800C3628_de / dt;
            if (!(drag <= limit)) {
                drag = limit;
            }
            gravity = 0.0f;
            if (motion->candidateIndex != 0) {
                gravity = surface->GravityAcceleration;
            }
            if (drag == 0.0f) {
                acceleration.x = 0.0f;
                acceleration.y = gravity;
                acceleration.z = 0.0f;
            } else {
                acceleration.x = -motion->orientation.x * drag;
                acceleration.y = -motion->orientation.y * drag + gravity;
                acceleration.z = -motion->orientation.z * drag;
            }
            halfDt = dt * D_800C362C_de;
            motion->end.x += (motion->orientation.x + acceleration.x * halfDt) * dt;
            motion->end.y += (motion->orientation.y + acceleration.y * halfDt) * dt;
            motion->end.z += (motion->orientation.z + acceleration.z * halfDt) * dt;
            motion->orientation.x += acceleration.x * dt;
            motion->orientation.y += acceleration.y * dt;
            motion->orientation.z += acceleration.z * dt;
        }
    }
}
