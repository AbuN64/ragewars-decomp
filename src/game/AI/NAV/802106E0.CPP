#include "include_asm.h"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/SELF.H"
#include "TYPES.H"

/* Probes one of a vehicle's eight wheel rays: casts from the vehicle position to its scaled wheel offset
 * through func_8024491C_de and stores the wheel's reach as the XZ distance to whatever was hit (diagonals
 * scaled by 1/sqrt 2, components tested against the zeroed y), or the full ray length on a miss. */
extern CVector3 D_800C88A0_de[8];
extern Hit_func_802106E0_de *D_80103FCC;
extern char D_80103FD0[];
extern f32 Sound_GetActorReach(Vehicle *);
extern f32 func_8024D398_de(Vehicle *);
extern f32 Particle_GetActorHeight(Vehicle *);
extern f32 Sound_GetActorBaseOffset(Vehicle *);
struct MotionSurface;
extern s32 func_8024491C_de(Vehicle *, CVector3, CVector3, struct MotionSurface *, f32, f32, f32, f32);
void func_802106E0_de(Vehicle *vehicle, s32 wheel) {
    CVector3 from;
    CVector3 to;
    CVector3 delta;
    f32 a;
    f32 b;
    f32 c;
    from = vehicle->pos;
    to = D_800C88A0_de[wheel];
    to.x *= vehicle->wheels->length;
    to.y *= vehicle->wheels->length;
    to.z *= vehicle->wheels->length;
    to.x += from.x;
    to.y += from.y;
    to.z += from.z;
    from.y += 61.44f;
    a = Sound_GetActorReach(vehicle);
    b = func_8024D398_de(vehicle);
    c = Particle_GetActorHeight(vehicle);
    if (func_8024491C_de(vehicle, from, to, D_80103FD0, a, b, c, Sound_GetActorBaseOffset(vehicle))) {
        delta = D_80103FCC->pos;
        delta.x -= from.x;
        delta.y = 0.0f;
        delta.z -= from.z;
        if (delta.x != delta.y) {
            if (delta.z == delta.y) {
                vehicle->wheels->reach[wheel] = ((delta.x) < (delta.y) ? -(delta.x) : (delta.x));
            } else {
                vehicle->wheels->reach[wheel] = (((delta.x) < (delta.y) ? -(delta.x) : (delta.x)) + ((delta.z) < (delta.y) ? -(delta.z) : (delta.z))) * 0.70710677f;
            }
        } else if (delta.z != delta.y) {
            vehicle->wheels->reach[wheel] = ((delta.z) < (delta.y) ? -(delta.z) : (delta.z));
        }
    } else {
        vehicle->wheels->reach[wheel] = vehicle->wheels->length;
    }
}

#include "COMMON/MOTION_STEP.H"
/* Stores the clearance reached before step I: (I - 1) x REACH, never below 0. */
static inline void storeClearance(Vehicle *vehicle, s32 wheel, s32 i, f32 reach) {
    vehicle->wheels->clearance[wheel] = (i - 1 >= 0 ? i - 1 : 0) * reach;
}
/* Walks wheel ray WHEEL outward from the vehicle in steps of 2.25 x its reach, probing the ground under
 * each step (func_8024491C_de), and stores in the clearance table the distance covered before a probe
 * misses, lands on a kind 5/6 surface or drops more than 100; it stays 100 when the ray is shorter
 * than the reach. */
void Nav_MeasureWheelClearance(Vehicle *vehicle, s32 wheel) {
    CVector3 position;
    CVector3 below;
    CVector3 step;
    MotionSurface surface;
    f32 reach;
    f32 length;
    f32 radius;
    f32 height;
    f32 base;
    s32 steps;
    s32 i;
    vehicle->wheels->clearance[wheel] = 100.0f;
    reach = Sound_GetActorReach(vehicle);
    length = vehicle->wheels->clearance[wheel];
    if (length < reach) {
        return;
    }
    step = D_800C88A0_de[wheel];
    steps = length / (reach * 2.25f) + 0.5f;
    step.x = step.x * 2.25f * reach;
    step.z = step.z * 2.25f * reach;
    i = 0;
    radius = func_8024D398_de(vehicle);
    height = Particle_GetActorHeight(vehicle);
    base = Sound_GetActorBaseOffset(vehicle);
    position = vehicle->pos;
    surface.flags = 0xC008;
    surface.enabled = 1;
    surface.slopeKind = 1;
    surface.materialKind = 1;
    surface.gravity = 0.0f;
    surface.response = 0.0f;
    surface.friction = 0.0f;
    surface.drag = 0.0f;
    surface.materialResponse = 0.0f;
    position.y += 2.5f * 61.44f;
    for (; i < steps; i++) {
        position.x += step.x;
        position.z += step.z;
        below = position;
        below.y -= 5 * 61.44f;
        if (!func_8024491C_de(vehicle, position, below, &surface, reach, radius, height, base)) {
            storeClearance(vehicle, wheel, i, reach);
            return;
        }
        if (D_80103FCC->kind == 5 || D_80103FCC->kind == 6) {
            storeClearance(vehicle, wheel, i, reach);
            return;
        }
        if (D_80103FCC->pos.y <= below.y - 100.0f) {
            storeClearance(vehicle, wheel, i, reach);
            return;
        }
    }
}

#include "COMMON/AIPROFILE.H"
extern CVector3 *func_8020993C_de(void *controller);
typedef struct NavProbeController {
    Player *player;
    u8 pad4[0x1CC];
    f32 reach[8];
    f32 clearance[8];
} NavProbeController;
/* Builds the eight radial probe segments around the player at two heights (reach at 180, clearance at
 * 140) from its position through func_8020993C_de, after turning its heading into a sector in [0, 8].
 * The segments stay on the stack: the debug draw that used them (and the sector) is compiled out. */
void Nav_PrepareProbeSegments(NavProbeController *controller) {
    CVector3 a, b;
    f32 angle, zero, yA, yB;
    s32 i;
    angle = controller->player->heading;
    angle -= 3.1415927f;
    angle += 0.3926991f;
    while (6.2831855f <= angle) angle -= 6.2831855f;
    zero = 0.0f;
    while (angle < zero) angle += 6.2831855f;
    if (6.1831856f < angle) angle = 6.1831856f;
    if (angle < 0.1f) angle = 0.1f;
    angle *= 0.15915494f;
    angle *= 8.0f;
    zero = 0.0f;
    if (angle < zero) angle = zero;
    if (8.0f < angle) angle = 8.0f;
    yA = 180.0f;
    yB = 140.0f;
    for (i = 0; i < 8; i++) {
        a = *func_8020993C_de(controller);
        b = *func_8020993C_de(controller);
        a.x += D_800C88A0_de[i].x * controller->reach[i];
        a.z += D_800C88A0_de[i].z * controller->reach[i];
        a.y += yA;
        b.y += yA;
        a = *func_8020993C_de(controller);
        b = *func_8020993C_de(controller);
        a.x += D_800C88A0_de[i].x * controller->clearance[i];
        a.z += D_800C88A0_de[i].z * controller->clearance[i];
        a.y += yB;
        b.y += yB;
    }
}
