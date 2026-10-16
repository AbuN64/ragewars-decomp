#include "TYPES.H"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "stddef.h"
#include "shared/gameplay_reactions.h"
extern s32 func_802661DC_de(void *, void *);
extern void func_8026641C_de(void *, void *, s32, Vec3, Vec3, s32, Shield *, s32);
extern void func_80271FC8_de(Vec3 *, f32, Vec3 *, Vec3 *);
extern f32 func_8024BEDC_de(void *);
extern f32 func_8024D284_de(void *);
extern f32 func_8024D398_de(void *);
extern s32 func_8024B06C_de(void *, Vec3, Shield *);
extern f32 func_802726F8_de(Vec3 *, Vec3 *);
extern f32 func_802672D0_de(void *);
extern void func_80271F68_de(Vec3 *, Vec3 *, Vec3 *);
extern f32 func_802B72B0_de(f32);
extern void func_8027207C_de(Vec3 *);
extern void func_80271F9C_de(Vec3 *, Vec3 *, f32);
extern void func_80216488_de(Shared_DamageEvent *, void *, s32, f32, s32, Shield *);
extern s32 func_8022AC00_de(void *);
struct CallbackState114;
extern void func_802171FC_de(void *, struct CallbackState114 *, Shared_DamageEvent *);
extern s32 func_80282C8C_de(Shared_ReactionObjectKind *);
extern s32 func_80282D38_de(Shared_ReactionObjectKind *);
extern s32 func_80282DEC_de(Shared_ReactionObjectKind *);
/* Published contiguous pool of sixteen damage scaling constants. */
extern const f32 D_800C43E0_de[16];
extern u8 D_801462E5;
extern void *D_801041F0;
extern s32 D_80100204;
extern Shield D_80100208, D_80110570;

static inline void storeActorHealth(Shared_ReactionActor *actor, s32 value) { actor->unk174 = value; }
static inline void storePlayerHealth(Shared_ReactionPlayer *player, s32 value) {
    player->unk5E4 = value;
    player->unk174 = player->unk5E4;
    storeActorHealth(&player->actor2E8, player->unk5E4);
}
static inline void buildDamage(Shared_DamageEvent *event, Shared_ReactionActor *target, f32 damage, f32 radius, s32 flags, Shield *shield) {
    func_80216488_de(event, target, (s32)damage, radius, flags, shield);
}
static inline void reflectedProjectile(Shared_ReactionPlayer *player, Shared_ReactionActor *target, f32 damage, f32 radius, s32 flags, Shield *shield) {
    Shared_DamageEvent event;
    Shared_DamageEvent *p = &event;
    buildDamage(p, target, damage * 2.0f, radius, flags, shield);
    if (damage * D_800C43E0_de[9] > 0.0f) func_802171FC_de(player, &player->unk170, p);
}
static inline void reflectedActor(Shared_ReactionPlayer *player, Shared_ReactionActor *target, f32 damage, f32 radius, s32 flags, Shield *shield) {
    Shared_DamageEvent event;
    Shared_DamageEvent *p = &event;
    f32 value = damage * D_800C43E0_de[13];
    buildDamage(p, target, value, radius, flags, shield);
    if (value > 0.0f) func_802171FC_de(player, &player->unk170, p);
}
static inline s32 adjustHit(Shared_ReactionActor *arg1, Vec3 *position) {
    s32 var_a2;
    s16 temp_v1;
    Shared_ReactionPlayer *temp_s0;
    Vec3 body, origin;
        var_a2 = 0;
        if ((arg1->category == 1) && (arg1->flags & 0x300000)) {
            temp_s0 = arg1->unk1D8;
            if (((void *)arg1 == (void *)&temp_s0->actor2E8) && ((temp_v1 = temp_s0->unk62E, (temp_v1 == 0)) || (temp_v1 == 0x11) || (temp_v1 == 0x10))) {
                body = (*position);
                origin = temp_s0->position;
                func_80271FC8_de(&(*position), 0.75f, &body, &origin);
                (*position).y += func_8024D284_de(temp_s0) * D_800C43E0_de[0];
                var_a2 = 1;
            }
        }
        return var_a2;
}
static inline f32 hitSize(Shared_ReactionActor *target) {
    if (target->category == 1) return func_8024BEDC_de(target);
    else return D_800C43E0_de[2];
}
static inline void hitImpulse(Shared_ReactionActor *source, Shared_ReactionActor *target, Shared_DamageParameters copied, Vec3 *out) {
    Vec3 direction;
    f32 radius, distance;
    radius = (f32)copied.radius * D_800C43E0_de[6];
    radius *= func_802672D0_de(target);
    out->z = 0.0f;
    out->y = 0.0f;
    out->x = 0.0f;
    if (target->category == 2) {
        func_80271F68_de(&direction, &source->position, &target->position);
        distance = func_802B72B0_de(direction.x * direction.x + direction.y * direction.y + direction.z * direction.z);
        func_8027207C_de(&direction);
        if (!(radius <= distance)) {
            func_80271F9C_de(out, &direction, (f32)copied.impulse * (((radius - distance) / radius) * D_800C43E0_de[7]));
        }
    }
}
static inline f32 scaleHit(Shared_ReactionActor *self, Shared_ReactionActor *target, Vec3 position, f32 radius, s32 falloff, s32 flags, Shield **found) {
    Shared_ReactionPlayer *player;
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
    scale = D_800C43E0_de[3];
    scaled = 1;
    if (self->flags & 0x300000) {
        player = self->unk1D8;
    }
    if (D_801462E5 != 0 && (flags & 0x200)) {
        shielded = 0;
    }
    if (target->category == 2) {
        if (target->type == 0x404 || target->type == 0x402) {
            special = 1;
        }
        if (target->category == 2 && D_801041F0 == (void *)self && D_80100204 != -1 && !special) {
            shield = &D_80100208;
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
        if (player != 0 && (player->unk122C & 2) && scale == D_800C43E0_de[4] && (flags & 0x200)) {
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
                scale *= D_800C43E0_de[5] - distance / reach;
            }
        }
    }
    return scale;
}

void func_80266810_de(Shared_ReactionActor *arg0, Shared_ReactionActor *arg1, s32 kind, Vec3 position, Shared_DamageParameters params, s32 arg8, s32 arg9, s32 arg10) {
    s32 temp_s1_2;
    s32 temp_s1;
    f32 var_fs1;
Vec3 sp30;
    s32 sp114;
    Shared_ReactionActor *temp_a0;
    Shared_ReactionPlayer *temp_s0_2;
    s32 temp_s1_3;
    Shared_ReactionPlayer *var_a2_2;
    s32 var_v1_2;
    s32 var_v1_3;
    u8 temp_v1_3;
    Shield *sp110;
    Shared_ReactionObjectKind *projectile;
    Shared_DamageEvent sp40;
    Shared_DamageEvent *event;
    f32 temp_fs1f_2;
    s32 var_v1_4;
    Shared_ReactionPlayer *var_s2;
    Shared_ReactionPlayer *temp_s0_3;

    var_s2 = NULL;
    if (arg0->flags & 0x300000) {
        var_s2 = arg0->unk1D8;
    }
    if (func_802661DC_de(arg0, arg1) != 0) {
        sp114 = adjustHit(arg1, &position);
        temp_fs1f_2 = (f32) params.radius * D_800C43E0_de[1];
        temp_fs1f_2 *= hitSize(arg1);
        var_fs1 = (f32)params.damage;
        var_fs1 *= scaleHit(arg0, arg1, position, temp_fs1f_2, arg8, arg10, &sp110);
        if (!(var_fs1 <= 0.0f)) {
            hitImpulse(arg0, arg1, params, &sp30);
            event = &sp40;
            func_80216488_de(event, arg1, (s32)var_fs1, temp_fs1f_2, arg10, sp110);
            temp_v1_3 = arg1->category;
            if (temp_v1_3 == 2) {
                projectile = &arg1->objectKind;
                temp_a0 = arg1->owner;
                if ((temp_a0 != NULL) && (temp_a0->category == 1)) {
                    if (temp_a0->flags & 0x300000) {
                        temp_s0_2 = temp_a0->unk1D8;
                        if (var_s2 != NULL) {
                            if (temp_s0_2->unk122C & 0x40) {
                                temp_s1 = temp_s0_2->unk5E4 + (s32) (var_fs1 * D_800C43E0_de[8]);
                                var_v1_2 = func_8022AC00_de(temp_s0_2);
                                if (temp_s1 < var_v1_2) {
                                    var_v1_2 = temp_s1;
                                }
                                storePlayerHealth(temp_s0_2, var_v1_2);
                            }
                        }
                        if (var_s2 != NULL) {
                            {
                                if (var_s2->unk122C & 0x10) {
                                    reflectedProjectile(temp_s0_2, arg1, var_fs1, temp_fs1f_2, arg10, sp110);
                                }
                                if ((var_s2 != NULL) && (var_s2->unk122C & 0x1000) && (func_80282C8C_de(projectile) != 0)) {
                                    temp_s1_2 = var_s2->unk5E4 + (s32) var_fs1;
                                    var_v1_3 = func_8022AC00_de(temp_s0_2);
                                    if (temp_s1_2 < var_v1_3) {
                                        var_v1_3 = temp_s1_2;
                                    }
                                    var_fs1 = 0.0f;
                                    storePlayerHealth(var_s2, var_v1_3);
                                }
                            }
                        }
                        if ((var_fs1 > 0.0f) && (var_s2 != NULL) && (temp_s0_2->unk122C & 8) && (temp_s0_2 != var_s2)) {
                            var_s2->unk122C = (s32) (var_s2->unk122C | 0x4000);
                            var_s2->unk11D8 = (f32) D_800C43E0_de[10];
                        }
                        if (temp_s0_2->unk122C & 0x200) {
                            var_fs1 *= D_800C43E0_de[11];
                            func_80216488_de(&sp40, arg1, (s32)var_fs1, temp_fs1f_2, arg10, sp110);
                        }
                    } else if (arg1->type == 0x427) {
                        var_a2_2 = NULL;
                        if (temp_a0->team == 0x40C) {
                            var_a2_2 = temp_a0->unk1D8;
                        }
                        if ((var_a2_2 != NULL) && (var_a2_2->unk122C & 0x200)) {
                            var_fs1 *= D_800C43E0_de[11];
                            func_80216488_de(event, arg1, (s32)var_fs1, temp_fs1f_2, arg10, sp110);
                        }
                    }
                    if (var_s2 != NULL) {
                        if ((var_s2->unk122C & 0x800) && ((func_80282D38_de(projectile) != 0) || (func_80282DEC_de(projectile) != 0))) {
                            var_fs1 = 0.0f;
                        }
                        if ((var_s2 != NULL) && (var_s2->unk122C & 0x400)) {
                            var_fs1 = 0.0f;
                        }
                    }
                }
            } else if (temp_v1_3 == 1) {
                if (arg1->flags & 0x300000) {
                    temp_s0_3 = arg1->unk1D8;
                    if (var_s2 != NULL) {
                        if (temp_s0_3->unk122C & 0x40) {
                            temp_s1_3 = temp_s0_3->unk5E4 + (s32) (var_fs1 * D_800C43E0_de[12]);
                            var_v1_4 = func_8022AC00_de(temp_s0_3);
                            if (temp_s1_3 < var_v1_4) {
                                var_v1_4 = temp_s1_3;
                            }
                            storePlayerHealth(temp_s0_3, var_v1_4);
                        }
                    }
                    if (var_s2 != NULL) {
                        {
                            if (var_s2->unk122C & 0x10) {
                                reflectedActor(temp_s0_3, arg1, var_fs1, temp_fs1f_2, arg10, sp110);
                            }
                        }
                    }
                    if ((var_fs1 > 0.0f) && (var_s2 != NULL) && (var_s2 != temp_s0_3) && (temp_s0_3->unk122C & 8)) {
                        var_s2->unk122C = (s32) (var_s2->unk122C | 0x4000);
                        var_s2->unk11D8 = (f32) D_800C43E0_de[14];
                    }
                    if (temp_s0_3->unk122C & 0x200) {
                        var_fs1 *= D_800C43E0_de[15];
                        func_80216488_de(&sp40, arg1, (s32)var_fs1, temp_fs1f_2, arg10, sp110);
                    }
                }
                if ((var_s2 != NULL) && (var_s2->unk122C & 0x400)) {
                    var_fs1 = 0.0f;
                }
                if ((var_fs1 > 0.0f) && (var_s2 != NULL)) {
                    var_s2->unk1218 = (s32) (var_s2->unk1218 == 0);
                }
            }
            if (var_fs1 != 0.0f) {
                func_802171FC_de(arg0, &arg0->unk170, &sp40);
                func_8026641C_de(arg0, arg1, sp114, position, sp30, arg9, sp110, arg10);
            }
        }
    }
}
