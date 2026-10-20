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
extern f32 func_8024E464_de(Vehicle *);
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
    a = func_8024E464_de(vehicle);
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

INCLUDE_ASM("span_1000", func_80210964_de);

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
void func_80210C14_de(void **arg0) {
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
