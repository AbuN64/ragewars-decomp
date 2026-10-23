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
#define NV_FIELD(base, type, offset) (*(type *)((u8 *)(base) + (offset)))
typedef struct WheelProbe { f32 x; f32 y; f32 z; } WheelProbe;
extern f32 D_800C1F98_de, D_800C1F9C_de, D_800C1FA0_de, D_800C1FA4_de, D_800C1FA8_de, D_800C1FAC_de;
void func_80210964_de(u8 *self, s32 wheel) {
    u8 *wheels = NV_FIELD(self, u8 *, 0x1454);
    f32 *reach = (f32 *)(wheels + 0x1F0) + wheel;
    WheelProbe offset;
    WheelProbe position;
    WheelProbe below;
    u8 flags[0x1C];
    f32 length;
    f32 range;
    f32 radius;
    f32 height;
    f32 base;
    f32 stepX;
    f32 stepZ;
    s32 steps;
    s32 i = 0;
    s32 last;
    *reach = D_800C1F98_de;
    range = Sound_GetActorReach(self);
    length = *(f32 *)(NV_FIELD(self, u8 *, 0x1454) + 0x1F0 + wheel * 4);
    if (length < range) {
        return;
    }
    offset = *(WheelProbe *)&D_800C88A0_de[wheel];
    stepX = offset.x * D_800C1F9C_de * range;
    stepZ = offset.z * D_800C1F9C_de * range;
    steps = (s32)(length / (range * D_800C1F9C_de) + D_800C1FA0_de);
    radius = func_8024D398_de((Vehicle *)self);
    height = Particle_GetActorHeight(self);
    base = func_8024E420_de(self);
    position = NV_FIELD(self, WheelProbe, 8);
    NV_FIELD(flags, s32, 0) = 0xC008;
    NV_FIELD(flags, u8, 4) = 1;
    NV_FIELD(flags, u8, 5) = 1;
    NV_FIELD(flags, u8, 6) = 1;
    NV_FIELD(flags, s32, 8) = 0;
    NV_FIELD(flags, s32, 0xC) = 0;
    NV_FIELD(flags, s32, 0x10) = 0;
    NV_FIELD(flags, s32, 0x14) = 0;
    NV_FIELD(flags, s32, 0x18) = 0;
    position.y += D_800C1FA4_de;
    while (i < steps) {
        position.x += stepX;
        position.z += stepZ;
        below = position;
        below.y -= D_800C1FA8_de;
        if (func_8024491C_de((Vehicle *)self, *(CVector3 *)&position, *(CVector3 *)&below, (struct MotionSurface *)flags, range, radius, height, base) != 0 &&
            (NV_FIELD((u8 *)D_80103FCC, s32, 0xFC) - 5) >= 2U &&
            !(NV_FIELD((u8 *)D_80103FCC, f32, 0xE8) <= below.y - D_800C1FAC_de)) {
            i++;
            continue;
        }
        last = i - 1;
        if (last < 0) {
            last = 0;
        }
        *(f32 *)(NV_FIELD(self, u8 *, 0x1454) + wheel * 4 + 0x1F0) = (f32)last * range;
        return;
    }
}
#else
INCLUDE_ASM("span_1000", func_80210964_de);
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
