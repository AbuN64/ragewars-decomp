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
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
void *func_8020993C_de(void *arg0);
extern f32 D_800C88A8_de;

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x30, 0x34, 0x38, 0x3c, 0x40, 0x44, 0x50, 0x54], gap at: 0x48. */
void func_80210C20_de(void **arg0) {
    f32 sp10;
    f32 sp14;
    f32 sp18;
    s32 sp20;
    f32 sp24;
    s32 sp28;
    f32 *var_s1;
    f32 *var_s2;
    f32 temp_fs0;
    f32 temp_fs0f;
    f32 temp_fv1f;
    f32 var_fv0f;
    s32 var_s3;
    void **var_s0;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;

    var_fv0f = (*((f32 *) ((u8 *) (*arg0) + 108)) - D_800C1FB0_de) + D_800C1FB4_de;
    if (D_800C1FB8_de <= var_fv0f) {
        do {
            var_fv0f -= D_800C1FB8_de;
        } while (D_800C1FB8_de <= var_fv0f);
    }
    if (var_fv0f < 0.0f) {
        do {
            var_fv0f += D_800C1FBC_de;
        } while (var_fv0f < 0.0f);
    }
    if (D_800C1FC0_de < var_fv0f) {
        var_fv0f = D_800C1FC0_de;
    }
    if (var_fv0f < D_800C1FC4_de) {
        var_fv0f = D_800C1FC4_de;
    }
    if ((var_fv0f * D_800C1FC8_de * D_800C1FCC_de) < 0.0f) {

    }
    var_s3 = 0;
    var_s1 = &D_800C88A8_de;
    var_s2 = (f32 *)((u8 *)&D_800C88A8_de - 8);
    var_s0 = arg0;
    temp_fs0f = D_800C1FD0_de;
    temp_fs0 = D_800C1FD4_de;
    do {
        temp_v0 = func_8020993C_de(arg0);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        sp10 = *((f32 *) ((u8 *) (temp_v0) + 0));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        sp14 = *((f32 *) ((u8 *) (temp_v0) + 4));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        sp18 = *((f32 *) ((u8 *) (temp_v0) + 8));
        temp_v0_2 = func_8020993C_de(arg0);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        sp20 = *((s32 *) ((u8 *) (temp_v0_2) + 0));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        sp24 = *((f32 *) ((u8 *) (temp_v0_2) + 4));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        sp28 = *((s32 *) ((u8 *) (temp_v0_2) + 8));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        sp10 += *var_s2 * *((f32 *) ((u8 *) (var_s0) + 464));
        sp14 += temp_fs0f;
        sp24 += temp_fs0f;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        sp18 += *var_s1 * *((f32 *) ((u8 *) (var_s0) + 464));
        temp_v0_3 = func_8020993C_de(arg0);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        sp10 = *((f32 *) ((u8 *) (temp_v0_3) + 0));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        sp14 = *((f32 *) ((u8 *) (temp_v0_3) + 4));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        sp18 = *((f32 *) ((u8 *) (temp_v0_3) + 8));
        temp_v0_4 = func_8020993C_de(arg0);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        sp20 = *((s32 *) ((u8 *) (temp_v0_4) + 0));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        sp24 = *((f32 *) ((u8 *) (temp_v0_4) + 4));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        sp28 = *((s32 *) ((u8 *) (temp_v0_4) + 8));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        sp10 += *var_s2 * *((f32 *) ((u8 *) (var_s0) + 496));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        temp_fv1f = *var_s1 * *((f32 *) ((u8 *) (var_s0) + 496));
        var_s3 += 1;
        var_s2 += 3;
        var_s1 += 3;
        var_s0 += 1;
        sp14 += temp_fs0;
        sp24 += temp_fs0;
        sp18 += temp_fv1f;
    } while (var_s3 < 8);
}
#else
INCLUDE_ASM("span_1000", func_80210C20_de);
#endif
