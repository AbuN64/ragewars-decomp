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
extern f32 func_8024E420_de(Vehicle *);
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
    if (func_8024491C_de(vehicle, from, to, D_80103FD0, a, b, c, func_8024E420_de(vehicle))) {
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

#ifdef NON_MATCHING
/* 4/172 aligned edits left: loop.c still hoists wheel * 4 + 0x1F0 out of the probe loop (the ROM adds the
 * clearance offset in the store). The three early outs are separate (jump2 cross-jumps them), which keeps
 * &surface in the loop like the ROM. */
#include "COMMON/MOTION_STEP.H"
extern f32 D_800C1F98_de, D_800C1F9C_de, D_800C1FA0_de, D_800C1FA4_de, D_800C1FA8_de, D_800C1FAC_de;
static inline void storeClearance(Vehicle *vehicle, s32 wheel, s32 i, f32 reach) {
    f32 *out = &vehicle->wheels->clearance[wheel];
    s32 last = i - 1;
    if (last < 0) {
        last = 0;
    }
    *out = last * reach;
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
    vehicle->wheels->clearance[wheel] = D_800C1F98_de;
    reach = Sound_GetActorReach(vehicle);
    length = vehicle->wheels->clearance[wheel];
    if (length < reach) {
        return;
    }
    step = D_800C88A0_de[wheel];
    steps = length / (reach * D_800C1F9C_de) + D_800C1FA0_de;
    step.x = step.x * D_800C1F9C_de * reach;
    step.z = step.z * D_800C1F9C_de * reach;
    i = 0;
    radius = func_8024D398_de(vehicle);
    height = Particle_GetActorHeight(vehicle);
    base = func_8024E420_de(vehicle);
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
    position.y += D_800C1FA4_de;
    for (; i < steps; i++) {
        position.x += step.x;
        position.z += step.z;
        below = position;
        below.y -= D_800C1FA8_de;
        if (!func_8024491C_de(vehicle, position, below, &surface, reach, radius, height, base)) {
            storeClearance(vehicle, wheel, i, reach);
            return;
        }
        if ((u32)(D_80103FCC->kind - 5) < 2) {
            storeClearance(vehicle, wheel, i, reach);
            return;
        }
        if (D_80103FCC->pos.y <= below.y - D_800C1FAC_de) {
            storeClearance(vehicle, wheel, i, reach);
            return;
        }
    }
}
#else
INCLUDE_ASM("span_1000", Nav_MeasureWheelClearance);
#endif

#ifdef NON_MATCHING
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "TYPES.H"
extern float D_800C1FB0_de;
extern float D_800C1FB4_de;
extern float D_800C1FB8_de;
extern float D_800C1FBC_de;
extern float D_800C1FC0_de;
extern float D_800C1FC4_de;
extern float D_800C1FC8_de;
extern float D_800C1FCC_de;
extern float D_800C1FD0_de;
extern float D_800C1FD4_de;
void *func_8020993C_de(void *arg0);
extern f32 D_800C88A8_de[];
#include "COMMON/AIPROFILE.H"
typedef struct NavProbeController {
    Player *player;
    u8 pad4[0x1CC];
    f32 reach[8];
    f32 clearance[8];
} NavProbeController;
/* Prepares radial probe segments at two heights from the player position.
 * The original keeps these vectors only on the stack; no draw call remains.
 * 7/157 aligned edits: final sector float register and clamp loop differ. */
void Nav_PrepareProbeSegments(NavProbeController *controller) {
    CVector3 a, b;
    f32 angle, zero, yA, yB;
    s32 i;
    angle = controller->player->heading;
    angle -= D_800C1FB0_de;
    angle += D_800C1FB4_de;
    while (D_800C1FB8_de <= angle) angle -= D_800C1FB8_de;
    zero = 0.0f;
    while (angle < zero) angle += D_800C1FBC_de;
    if (D_800C1FC0_de < angle) angle = D_800C1FC0_de;
    if (angle < D_800C1FC4_de) angle = D_800C1FC4_de;
    angle *= D_800C1FC8_de;
    angle *= D_800C1FCC_de;
    zero = 0.0f;
    while (angle < zero) angle = zero;
    yA = D_800C1FD0_de;
    yB = D_800C1FD4_de;
    for (i = 0; i < 8; i++) {
        a = *(CVector3 *)func_8020993C_de(controller);
        b = *(CVector3 *)func_8020993C_de(controller);
        a.x += D_800C88A0_de[i].x * controller->reach[i];
        a.z += D_800C88A0_de[i].z * controller->reach[i];
        a.y += yA;
        b.y += yA;
        a = *(CVector3 *)func_8020993C_de(controller);
        b = *(CVector3 *)func_8020993C_de(controller);
        a.x += D_800C88A0_de[i].x * controller->clearance[i];
        a.z += D_800C88A0_de[i].z * controller->clearance[i];
        a.y += yB;
        b.y += yB;
    }
}
#else
INCLUDE_ASM("span_1000", Nav_PrepareProbeSegments);
#endif
