#include "include_asm.h"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/FIELD_VEC_B0.H"
#include "TYPES.H"
#include "stddef.h"

/* Picks an actor's target (the tracked enemy when the aim point is chosen, else the nearest permitted target from func_802149C0_de), classifies it into one of eight kinds, and fills the target record with the kind, target, height difference, position, direction and distance, both in full and flattened to the horizontal plane. */
extern s32 D_8011CD20,D_8013B290;
extern void *func_802149C0_de(void *,void *,s32,s32), *func_80219408_de(void *);
extern f32 func_80216F44_de(void *,f32,f32,f32),func_802B72B0_de(f32);
extern void func_80271F68_de(CVector3 *, CVector3 *, CVector3 *);
static inline s32 func_80215410_kind(Actor_func_80214DD4_de *self, Tracker *ctx, Actor_func_80214DD4_de *target) {
    if (ctx->active == 0) {
        return 6;
    }
    if (target == NULL) {
        if (ctx->slot != 0) {
            return 4;
        }
        return 3;
    }
    if (target == ctx->self) {
        return 2;
    }
    if (*target->kind == 5) {
        return 5;
    }
    if (target->id == 0x64F) {
        return 7;
    }
    if (D_8013B290 == 0) {
        if ((target->flags100 & 0x300000) && target->controller->owner == self
            && target->controller->state == 2) {
            return 1;
        }
        if ((self->flags2E0 & 2) && self->id != 0xCA) {
            return 1;
        }
    }
    return 0;
}
void func_80215410_de(Actor_func_80214DD4_de *arg0, Tracker *arg1, s32 unused, TrackResult *arg3) {
    CVector3 pos;
    CVector3 delta;
    f32 height;
    s32 kind;
    Actor_func_80214DD4_de *target;
    Location *point;
    if ((arg1->team == D_8011CD20) && !(arg0->kind[1] & 0x400) && (!(arg1->flags & 0x80000) || (arg1->unk78 != 0))) {
        arg1->anchor = func_802149C0_de(arg0, arg1, 1, 0);
    }
    if ((*arg0->kind == 1) && (arg1->mode == 0xB)
        && func_80215410_kind(arg0, arg1, arg1->target) == 4) {
        target = arg1->target;
        kind = 4;
    } else {
        target = arg1->anchor;
        kind = func_80215410_kind(arg0, arg1, target);
    }
    if (target != NULL) {
        pos = target->pos;
        height = func_80216F44_de(arg0, pos.x, pos.y, pos.z);
    } else {
        switch (kind) {
            case 4:
                point = func_80219408_de(&arg1->slot);
                pos = point->pos;
                if (point->flags & 1) {
                    height = point->heading * 0.0174532942f - arg0->heading;
                } else {
                    height = func_80216F44_de(arg0, pos.x, pos.y, pos.z);
                }
                break;
            case 3:
                pos = arg1->homePos;
                height = arg1->homeYaw - arg0->heading;
                break;
            case 6:
                pos = arg0->pos;
                height = 0.0f;
                break;
        }
    }
    func_80274020_de(&height);
    func_80271F68_de(&delta, &pos, &arg0->pos);
    arg3->range = height;
    arg3->kind = kind;
    arg3->target = target;
    arg3->pos = pos;
    arg3->delta = delta;
    arg3->dist = func_802B72B0_de((delta.x * delta.x) + (delta.y * delta.y) + (delta.z * delta.z));
    delta.y = 0.0f;
    pos.y = 0;
    arg3->flatPos = pos;
    arg3->flatDelta = delta;
    arg3->flatDist = func_802B72B0_de((delta.x * delta.x) + (delta.y * delta.y) + (delta.z * delta.z));
}

#ifdef NON_MATCHING
#include "COMMON/PROBE.H"
extern f32 D_800C2180_de, D_800C2184_de, D_800C2188_de, D_800C218C, D_800C2190_de, D_800C2194, D_800C21C0_de[];
extern s32 D_801041F0;
extern s32 func_802462E8_de(Actor_u1 *, CVector3, char **);

/* Aim toward a point; when obstructed, try progressively wider left/right
 * directions and choose the first clear probe. */
f32 func_80215868_de(Actor_u1 *actor, CVector3 point, s32 target, f32 distance) {
    CVector3 probe;
    char *hit;
    f32 dx = point.x - actor->position.x;
    f32 dz = point.z - actor->position.z;
    f32 length = func_802B72B0_de(dx * dx + dz * dz);
    f32 heading, cosine, sine, dot, offset, angle, bias;
    s32 step, side;
    if (length == 0.0f) {
        heading = 0.0f;
    } else {
        cosine = func_802B7130_de(actor->yaw);
        sine = -func_802B6560_de(actor->yaw);
        dot = (dx * -cosine + dz * sine) / length;
        if (dot < D_800C2184_de) dot = D_800C2184_de;
        else if (D_800C2180_de < dot) dot = D_800C2180_de;
        heading = func_802745D0_de(dot);
        if (!(dx * sine + dz * cosine > 0.0f)) heading = -heading;
    }
    if ((actor->flags & 0x200) && func_802462E8_de(actor, point, &hit)) {
        if (target != 0 && D_801041F0 == target) return heading;
        probe.y = actor->position.y;
        for (step = 1; step < 6; step++) {
            offset = (f32)step * D_800C2188_de;
            for (side = 0; side < 2; side++) {
                if (side != (((s32)actor % 744) & 1)) {
                    angle = heading + offset;
                    bias = D_800C2190_de;
                } else {
                    angle = heading - offset;
                    bias = D_800C2194;
                }
                cosine = func_802B7130_de(actor->yaw + D_800C218C + angle);
                probe.x = actor->position.x + cosine * (distance * func_8024D398_de(actor));
                sine = func_802B6560_de(actor->yaw + D_800C218C + angle);
                probe.z = actor->position.z + sine * (distance * func_8024D398_de(actor));
                if (!func_802462E8_de(actor, probe, 0)) {
                    angle += bias;
                    func_80274020_de(&angle);
                    return angle;
                }
            }
        }
    }
    return heading;
}
#else
INCLUDE_ASM("span_1000", func_80215868_de);
#endif

#ifdef NON_MATCHING
#ifndef FIELD
#define FIELD(type, base, off) (*(type *)((char *)(base) + (off)))
#endif
extern f32 D_800C2198, D_800C219C_de, D_800C21A0_de, D_800C21A4_de, D_800C21A8_de, D_800C21AC_de, D_800C21B0_de;
extern f32 D_800C21B4_de, D_800C21B8_de, D_800C21BC_de;
extern s32 Weapons_HasAmmoForMode(void *, s32);
extern void func_8024BC94_de(CVector3 *, void *, f32, f32, f32);
/* Signed angle between an actor's facing and the direction to a point on the ground plane, clamped by the
 * given limits before the arccosine (the constants differ per use). */
static f32 headingToward(Actor_u1 *actor, CVector3 point, f32 high, f32 low) {
    f32 dx = point.x - actor->position.x;
    f32 dz = point.z - actor->position.z;
    f32 length = func_802B72B0_de(dx * dx + dz * dz);
    f32 heading;
    f32 cosine;
    f32 sine;
    f32 dot;
    if (length == 0.0f) {
        return 0.0f;
    }
    cosine = func_802B7130_de(actor->yaw);
    sine = -func_802B6560_de(actor->yaw);
    dot = (dx * -cosine + dz * sine) / length;
    if (high < dot) {
        dot = high;
    } else if (dot < low) {
        dot = low;
    }
    heading = func_802745D0_de(dot);
    if (!(dx * sine + dz * cosine > 0.0f)) {
        heading = -heading;
    }
    return heading;
}
/* Tells whether an actor can aim at a target within the given tolerance: the target must be a shooting player
 * with ammo and the aim button (0x2000), or a prop of kind 1 / 4 in the right state; the vertical aim point is
 * clamped to the actor's height range, the horizontal turn must lie outside the dead zone, and the angle
 * between the aim direction and the target's forward vector must be within tolerance. Returns 0 when not,
 * else -1 or 1 for the side the target faces. */
s32 func_80215B90_de(Actor_u1 *actor, s32 unused, void *target, f32 tolerance) {
    CVector3 aim;
    CVector3 from;
    CVector3 direction;
    CVector3 forward;
    f32 low;
    f32 high;
    f32 turn;
    f32 angle;
    if (target == 0) {
        return 0;
    }
    if (FIELD(u32, target, 0x100) & 0x300000) {
        void *player = FIELD(void *, target, 0x1D8);
        if (Weapons_HasAmmoForMode(player, FIELD(s16, player, 0x62E)) <= 0) {
            return 0;
        }
        if ((FIELD(u32, player, 0x6AC) & 0x2000) == 0) {
            return 0;
        }
    } else {
        s32 kind = FIELD(s32, FIELD(void *, target, 0x18), 0);
        if (kind == 1) {
            if (FIELD(s16, target, 0x238) < 0x10CC) {
                return 0;
            }
        } else if (kind == 4) {
            if (FIELD(s8, target, 0x1A4) != 0x3F) {
                return 0;
            }
        } else {
            return 0;
        }
    }
    low = actor->position.y + FIELD(f32, actor, 0x70);
    high = low + Particle_GetActorHeight((Actor_func_80214310_de *)actor);
    aim.x = FIELD(f32, target, 0x8);
    aim.y = FIELD(f32, target, 0xC) + FIELD(f32, target, 0x70) +
            Particle_GetActorHeight((Actor_func_80214310_de *)target) * D_800C2198;
    aim.z = FIELD(f32, target, 0x10);
    from.x = actor->position.x;
    from.z = actor->position.z;
    if (high < aim.y) {
        from.y = high;
    } else if (aim.y < low) {
        from.y = low;
    } else {
        from.y = aim.y;
    }
    angle = headingToward(actor, aim, D_800C219C_de, D_800C21A0_de);
    if (angle < 0.0f) {
        turn = -headingToward(actor, aim, D_800C21A4_de, D_800C21A8_de);
    } else {
        turn = headingToward(actor, aim, D_800C21AC_de, D_800C21B0_de);
    }
    if (D_800C21B4_de < turn && turn < D_800C21B8_de) {
        return 0;
    }
    func_80271F68_de(&direction, &from, &aim);
    func_8027207C_de(&direction);
    func_8024BC94_de(&forward, target, 0.0f, 0.0f, D_800C21BC_de);
    angle = func_802745D0_de(direction.x * forward.x + direction.y * forward.y + direction.z * forward.z);
    if (!(angle < tolerance * D_800C21C0_de[0])) {
        return 0;
    }
    if (-forward.z * direction.x + direction.z * forward.x < 0.0f) {
        return -1;
    }
    return 1;
}
#else
INCLUDE_ASM("span_1000", func_80215B90_de);
#endif
