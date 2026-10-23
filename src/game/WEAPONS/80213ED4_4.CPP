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
void func_80215410_de(Actor_func_80214DD4_de *arg0, Tracker *tracker, s32 unused, TrackResult *arg3) {
    CVector3 pos;
    CVector3 delta;
    f32 height;
    s32 kind;
    Actor_func_80214DD4_de *target;
    Location *point;
    if ((tracker->team == D_8011CD20) && !(arg0->kind[1] & 0x400) && (!(tracker->flags & 0x80000) || (tracker->unk78 != 0))) {
        tracker->anchor = func_802149C0_de(arg0, tracker, 1, 0);
    }
    if ((*arg0->kind == 1) && (tracker->mode == 0xB)
        && func_80215410_kind(arg0, tracker, tracker->target) == 4) {
        target = tracker->target;
        kind = 4;
    } else {
        target = tracker->anchor;
        kind = func_80215410_kind(arg0, tracker, target);
    }
    if (target != NULL) {
        pos = target->pos;
        height = func_80216F44_de(arg0, pos.x, pos.y, pos.z);
    } else {
        switch (kind) {
            case 4:
                point = func_80219408_de(&tracker->slot);
                pos = point->pos;
                if (point->flags & 1) {
                    height = point->heading * 0.0174532942f - arg0->heading;
                } else {
                    height = func_80216F44_de(arg0, pos.x, pos.y, pos.z);
                }
                break;
            case 3:
                pos = tracker->homePos;
                height = tracker->homeYaw - arg0->heading;
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
/* func_80215868_de's float literals (1, -1, pi/6, pi, +-pi/12), placed here until it is matched. */
const unsigned int D_80215868_C7E70[6] = {
    0x3F800000, 0xBF800000, 0x3F060A93, 0x40490FDB, 0x3E860A93, 0xBE860A93,
};

#include "COMMON/MATH_HELPERS.H"
extern void func_8027207C_de(CVector3 *);
extern void func_8024BC94_de(CVector3 *out, void *actor, CVector3 offset);
extern f32 Particle_GetActorHeight(void *);

/* func_80216F44_de's body: the signed angle between the actor's facing and the direction to the point. */
static inline f32 angleTo(Actor_func_80214DD4_de *actor, CVector3 point) {
    f32 dx;
    f32 dz;
    f32 dist;
    f32 s;
    f32 c;
    f32 dot;
    f32 angle;

    dx = point.x - actor->pos.x;
    dz = point.z - actor->pos.z;
    dist = func_802B72B0_de(dx * dx + dz * dz);
    if (dist == 0.0f) {
        return 0.0f;
    }
    do {
        s = func_802B7130_de(actor->heading);
    } while (0);
    c = -func_802B6560_de(actor->heading);
    dot = (dx * -s + dz * c) / dist;
    dot = ((RW_MIN(dot, 1.0f)) < ((-1.0f)) ? ((-1.0f)) : (RW_MIN(dot, 1.0f)));
    angle = func_802745D0_de(dot);
    if (!(dx * c + dz * s > 0.0f)) {
        angle = -angle;
    }
    return angle;
}

#define ABS(x) ((x) < 0.0f ? -(x) : (x))

/* Whether the target faces the actor within a cone, and from which side. The target must be armed: a player with ammo
 * for its current weapon and the fire button held, an AI in anim type 0x10CC or later (kind 1) or in mode 0x3F
 * (kind 4). Targets 70 to 110 degrees off the actor's heading are skipped. The line from the actor (its height
 * clamped to the target's aim point) to the target is compared with the target's forward vector: 0 when the angle
 * between them is not under half the cone, else -1 or 1 for the side. */
s32 Weapons_GetFacingSide(Actor_func_80214DD4_de *self, void *unused, Actor_func_80214DD4_de *target, f32 cone) {
    CVector3 dir;
    CVector3 facing;
    CVector3 forward;
    CVector3 from;
    CVector3 to;
    struct Controller *controller;
    f32 low;
    f32 high;
    f32 angle;

    if (target == NULL) {
        return 0;
    }
    if (target->flags100 & 0x300000) {
        controller = target->controller;
        if (Weapons_HasAmmoForMode(controller, controller->currentWeapon) <= 0) {
            return 0;
        }
        if (!(controller->buttons & 0x2000)) {
            return 0;
        }
    } else {
        switch (*target->kind) {
        case 1:
            if (target->animType < 0x10CC) {
                return 0;
            }
            break;
        case 4:
            if (target->aiMode != 0x3F) {
                return 0;
            }
            break;
        default:
            return 0;
        }
    }
    low = self->pos.y + self->height;
    high = low + Particle_GetActorHeight(self);
    to.x = target->pos.x;
    to.y = target->pos.y + target->height + Particle_GetActorHeight(target) * 0.9f;
    to.z = target->pos.z;
    from.x = self->pos.x;
    from.z = self->pos.z;
    if (high < to.y) {
        from.y = high;
    } else if (to.y < low) {
        from.y = low;
    } else {
        from.y = to.y;
    }
    angle = ABS(angleTo(self, to));
    if (angle > 70.0f * RW_PI_F6 / 180.0f && angle < 110.0f * RW_PI_F6 / 180.0f) {
        return 0;
    }
    func_80271F68_de(&dir, &from, &to);
    func_8027207C_de(&dir);
    forward.x = 0.0f;
    forward.y = 0.0f;
    forward.z = 1.0f;
    func_8024BC94_de(&facing, target, forward);
    if (func_802745D0_de(dir.x * facing.x + dir.y * facing.y + dir.z * facing.z) < cone * 0.5f) {
        if (dir.x * -facing.z + dir.z * facing.x < 0.0f) {
            return -1;
        }
        return 1;
    }
    return 0;
}
