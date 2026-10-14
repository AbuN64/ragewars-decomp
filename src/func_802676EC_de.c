#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802661FC.h"
#include "types.h"
/* Returns how strongly a blast at a position with a radius affects an actor: finds the shield covering the position (the held carrier shield D_801041F0 of the actor for an object target other than the two 0x402/0x404 types, otherwise func_8024B06C_de's shield in D_80110570), reports it, scales by the shield factor unless friendly fire is off for team damage, and when falloff is asked returns zero for an invulnerable player's untouched full hit, zero beyond the radius plus the actor's width, or the scale times one minus the distance to the actor's body over that reach. */

















extern u8 D_801462E5;
extern Carrier D_801041F0;
extern Shield D_80110570;

extern s32 func_8024B06C_de(Actor_func_802676EC_de *, Vec3, Shield *);
extern f32 func_8024D284_de(Actor_func_802676EC_de *);
extern f32 func_8024D398_de(Actor_func_802676EC_de *);
extern f32 func_802726F8_de(Vec3 *, Vec3 *);

f32 func_802676EC_de(Actor_func_802676EC_de *self, Target *target, Vec3 position, f32 radius, s32 falloff, s32 flags, Shield **found) {
    PlayerRecAt122C *player;
    s32 shielded;
    s32 scaled;
    s32 special;
    Shield *shield;
    f32 scale;
    f32 bottom;
    f32 top;
    f32 reach;
    f32 distance;
    Vec3 body;

    special = 0;
    shielded = 1;
    player = 0;
    scale = *(&D_800C46E8_eu + 1);
    scaled = 1;
    if (self->flags & 0x300000) {
        player = self->player;
    }
    if (D_801462E5 != 0 && (flags & 0x200)) {
        shielded = 0;
    }
    if (target->kind == 2) {
        if (target->type == 0x404 || target->type == 0x402) {
            special = 1;
        }
        if (target->kind == 2 && D_801041F0.owner == self && D_801041F0.slot != -1 && !special) {
            shield = &D_801041F0.shield;
            falloff = 0;
            goto have;
        }
    }
    shield = func_8024B06C_de(self, position, &D_80110570) ? &D_80110570 : 0;
have:
    *found = shield;
    if (shielded && shield != 0) {
        scale *= shield->factor;
    }
    if (falloff != 0) {
        if (player != 0 && (player->flags & 2) && scale == D_800C4440_de && (flags & 0x200)) {
            scale = 0.0f;
        } else {
            body = self->position;
            bottom = self->position.y + self->height;
            top = bottom + func_8024D284_de(self);
            if (top < position.y) {
                body.y = top;
            } else if (position.y < bottom) {
                body.y = bottom;
            } else {
                body.y = position.y;
            }
            reach = radius + func_8024D398_de(self);
            distance = func_802726F8_de(&position, &body);
            if (reach < distance) {
                return 0.0f;
            }
            if (scaled) {
                scale *= (1.0f) - distance / reach;
            }
        }
    }
    return scale;
}
