#include "include_asm.h"
#include "COMMON/TARGET.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/OBJECTLINKS4_2.H"
#include "TYPES.H"
#include "COMMON/ANIMATIONTRIGGERDEFINITION.H"
#include "SYSTEM_2/CODE_802661FC.H"
extern void func_8027207C_de(f32 *arg0);

#ifdef NON_MATCHING
#include "TYPES.H"
#include "FX_2/80271B18.H"

typedef struct DamageDefinition { s32 kind; } DamageDefinition;
typedef struct DamageActor {
    u8 category; char pad01[3]; u16 kind; char pad06[0x12];
    DamageDefinition *definition;
    char pad1C[0xC8]; u16 team; char padE6[0x1A]; u32 flags;
    char pad104[0x14]; u32 *properties;
    char pad11C[0x10]; struct DamageActor *owner;
} DamageActor;
extern u8 D_801462E5;
extern s32 D_8013B290;
extern s32 func_8024D160_de(void *);

s32 func_802661DC_de(DamageActor *source, DamageActor *target) {
    DamageActor *owner;
    s32 allowed, kind;
    if (source == target) return 0;
    if ((source->flags & 0x300000) && !func_8024D160_de(source)) return 0;
    if (target->category == 1) {
        allowed = 1;
        if (!D_801462E5) {
            allowed = 0;
            if (target->team != source->team && (source->flags & 0x310000) &&
                (!D_8013B290 || (target->flags & 0x300000) || (source->flags & 0x300000))) {
                kind = source->definition->kind;
                if (kind == 4 || kind == 1 || kind == 7 || kind == 11) allowed = 1;
            }
        }
        return allowed;
    }
    if (target->category != 2) return 1;
    owner = target->owner;
    if (owner) {
        if (owner->category == 1) {
            allowed = 1;
            if (!D_801462E5) {
                allowed = 0;
                if (owner->team != source->team && (source->flags & 0x310000) &&
                    (!D_8013B290 || (owner->flags & 0x300000) || (source->flags & 0x300000))) {
                    kind = source->definition->kind;
                    if (kind == 4 || kind == 1 || kind == 7 || kind == 11) allowed = 1;
                }
            }
            if (!allowed) return 0;
        }
        if (source == target->owner && (*target->properties & 0x40)) return 0;
    }
    if (target->kind != 0x14) return 1;
    if (source->definition->kind == 1 && source->team == 0xCA) return 0;
    return 1;
}
#else
INCLUDE_ASM("span_1000", func_802661DC_de);
#endif

#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/APPROACHLOCATION.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/WORLD.H"
#include "COMMON/ANIMATIONTRIGGERDEFINITION.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
extern float D_800C43C0_de;
extern float D_800C43C4_de;
extern float D_800C43C8_de;
extern float D_800C43CC_de;
extern float D_800C43D0_de;
extern struct NodeCode8028469C * * D_800C43D4_de;
extern float D_800C43DC_de;

void func_8022B09C_de(s32, f32 *);
void func_802800C0_de(s32 *, void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                      f32, f32, f32, s32, s32, s32);
void func_8028CE94_de(Shared_World *, s32, s32, s32, s32, s32, struct NodeCode8028469C **,
                      f32);
extern s32 D_8011D8D0;
extern float D_800C43D8_de;

void func_8026641C_de(void *object, char *param_2, s32 param_3, CVector3 position, CVector3 impulse,
                      s32 param_10, void *shield, u32 param_12) {
    s32 param_1 = (s32)object;
    char cVar1;
    s32 iVar2;
    f32 uVar3;
    s32 iVar4;
    f32 fVar5;
    f32 uVar6;
    f32 uVar7;
    f32 local_68;
    f32 local_64;
    f32 local_60;
    f32 local_58;
    f32 local_54;
    f32 local_50;
    f32 local_48;
    f32 local_44;
    f32 local_40;
    f32 local_38;
    f32 local_34;
    f32 local_30;
    f32 local_2c;
    s32 auStack_28[2];
    s32 doCall;
    CVector3 vec;

    iVar4 = (s32)shield;
    iVar2 = param_10;
    if (*param_2 == '\x01') {
        *(u32 *)(param_2 + 0x170) = *(u32 *)(param_2 + 0x170) | 0x8000;
        if (((*(u32 *)(param_1 + 0x100) & 0x300000) != 0) &&
            (*(s32 *)(*(s32 *)(param_1 + 0x1d8) + 0x5dc) != 0)) {
            doCall = 0;
            uVar3 = 0.0f;
            uVar6 = 0.0f;
            uVar7 = 0.0f;
            if ((*(u32 *)(param_2 + 0x1ac) & 0x4000) == 0) {
                if ((*(u32 *)(param_2 + 0x1ac) & 0x2000) != 0) {
                    uVar3 = 50.0f;
                    uVar7 = D_800C43CC_de;
                    uVar6 = D_800C43C8_de;
                    doCall = 1;
                }
            } else {
                uVar3 = 100.0f;
                uVar7 = D_800C43C4_de;
                uVar6 = D_800C43C0_de;
                doCall = 1;
            }
            if (doCall) {
                vec.x = position.x;
                vec.y = position.y;
                vec.z = position.z;
                func_80239324_de(*(char **)(*(s32 *)(param_1 + 0x1d8) + 0x5dc), uVar7, uVar3, uVar7,
                                 uVar6, 1, vec);
            }
        }
        if (param_3 != 0) {
            if (((iVar4 != 0) && ((*(u32 *)(param_2 + 0x100) & 0x300000) != 0)) &&
    /* FAKEMATCH: Fuzzy draft keeps native byte reads from opaque actor storage. */
                (((u32)(u8)*(char *)(iVar4 + 0x66) - 4) < 2)) {
    /* FAKEMATCH: Fuzzy draft keeps native byte reads from opaque actor storage. */
                cVar1 = *(char *)(iVar4 + 0x66);
                if (*(s32 *)(*(s32 *)(param_2 + 0x1d8) + 0x5dc) != 0) {
                    iVar4 = *(s32 *)(param_2 + 0x1d8);
                    local_68 = -impulse.x;
                    local_64 = impulse.y;
                    local_60 = impulse.z;
                    func_8022B09C_de(iVar4, &local_68);
                    local_68 = local_68 - *(f32 *)(*(s32 *)(iVar4 + 0x5dc) + 0x128);
                    local_64 = local_64 - *(f32 *)(*(s32 *)(iVar4 + 0x5dc) + 0x12c);
                    local_60 = local_60 - *(f32 *)(*(s32 *)(iVar4 + 0x5dc) + 0x130);
                    func_80271818_de(&local_38, &local_68);
                    vec.x = position.x;
                    vec.y = position.y;
                    vec.z = position.z;
                    func_8024E79C_de((Actor_func_80214624_de *)param_2, vec, &local_58, auStack_28,
                                     0, 1);
                    local_50 = position.z;
                    local_48 = 0.0f;
                    local_54 = position.y + D_800C43D0_de;
                    local_44 = 0.0f;
                    local_40 = 0.0f;
                    if (cVar1 == '\x05') {
                        uVar7 = 3;
                    } else {
                        uVar7 = 1;
                    }
                    local_58 = position.x;
                    func_802800C0_de(&D_8011D8D0, param_2, param_2, 0, 0, 0xe9, 0, 0, 0, local_38,
                                     local_34, local_30, local_2c, position.x, local_54, position.z, 0,
                                     -1, uVar7);
                    local_58 = 0.0f;
                    local_54 = 0.0f;
                    local_50 = 0.0f;
                    func_8028CE94_de(&D_8011FE88, *(s32 *)(iVar4 + 0x698) + 0x140, 3, 0, 0, 0,
                                     D_800C43D4_de, D_800C43D8_de);
                }
            }
            impulse.x = 0.0f;
            impulse.y = 0.0f;
            impulse.z = 0.0f;
        }
        if (((*(u32 *)(param_2 + 0x100) & 0x300000) != 0) && ((param_12 & 0x200) != 0)) {
            func_80278D78_de((void *)param_1, 0x10, param_2);
        }
    }
    if (((**(s32 **)(param_1 + 0x18) == 1) || (**(s32 **)(param_1 + 0x18) == 0xb)) &&
        (func_80271F34_de((void *)(param_1 + 0x1c), (void *)(param_1 + 0x1c), &impulse),
         iVar2 != 0)) {
        vec.x = *(f32 *)(param_2 + 8);
        vec.y = *(f32 *)(param_2 + 0xc);
        vec.z = *(f32 *)(param_2 + 0x10);
        fVar5 = func_80216F44_de((Actor_func_80214624_de *)param_1, vec);
        *(f32 *)(param_1 + 0x6c) = *(f32 *)(param_1 + 0x6c) + fVar5 * D_800C43DC_de;
    }
}
#else
INCLUDE_ASM("span_1000", func_8026641C_de);
#endif

#include "stddef.h"
#include "COMMON/GAMEPLAY_REACTIONS.H"
/* Published contiguous pool of damage scaling constants, read by index. */
extern const f32 D_800C43E0_de[16];
/* Forwards the actor, event value and three-component input with a zero final flag. */
extern void func_80271FC8_de(CVector3 *, f32, CVector3 *, CVector3 *);
extern f32 func_8024BEDC_de(void *);
extern f32 Particle_GetActorHeight(void *);
#ifndef NON_MATCHING
extern f32 func_8024D398_de(void *);
#endif
extern s32 func_8024B06C_de(void *, CVector3, Shield *);
extern f32 func_802726F8_de(CVector3 *, CVector3 *);
extern f32 func_802672D0_de(u8 *);
extern f32 func_802B72B0_de(f32);
#ifndef NON_MATCHING
extern void func_80271F9C_de(void *, void *, f32);
#endif
extern void func_80216488_de(CDamageInfo *, void *, s32, f32, s32, Shield *);
extern s32 func_8022AC00_de(void *);
struct CallbackState114;
extern void func_802171FC_de(void *, struct CallbackState114 *, CDamageInfo *);
extern s32 func_80282C8C_de(Shared_ReactionObjectKind *);
extern s32 func_80282D38_de(Shared_ReactionObjectKind *);
extern s32 func_80282DEC_de(Shared_ReactionObjectKind *);
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
static inline void buildDamage(CDamageInfo *event, Shared_ReactionActor *target, f32 damage, f32 radius, s32 flags, Shield **shield) {
    func_80216488_de(event, target, (s32)damage, radius, flags, *shield);
}
static inline void reflectedProjectile(Shared_ReactionPlayer *player, Shared_ReactionActor *target, f32 damage, f32 radius, s32 flags, Shield **shield) {
    CDamageInfo event;
    CDamageInfo *p = &event;
    buildDamage(p, target, damage * 2.0f, radius, flags, shield);
    if (damage * D_800C43E0_de[9] > 0.0f) func_802171FC_de(player, &player->unk170, p);
}
static inline void reflectedActor(Shared_ReactionPlayer *player, Shared_ReactionActor *target, f32 damage, f32 radius, s32 flags, Shield **shield) {
    CDamageInfo event;
    CDamageInfo *p = &event;
    f32 value = damage * D_800C43E0_de[13];
    buildDamage(p, target, value, radius, flags, shield);
    if (value > 0.0f) func_802171FC_de(player, &player->unk170, p);
}
static inline s32 adjustHit(Shared_ReactionActor *target, CVector3 *position) {
    s32 adjusted;
    s16 ownerState;
    Shared_ReactionPlayer *owner;
    CVector3 body, origin;
        adjusted = 0;
        if ((target->category == 1) && (target->flags & 0x300000)) {
            owner = target->unk1D8;
            if (((void *)target == (void *)&owner->actor2E8) && ((ownerState = owner->unk62E, (ownerState == 0)) || (ownerState == 0x11) || (ownerState == 0x10))) {
                body = (*position);
                origin = owner->position;
                func_80271FC8_de(&(*position), 0.75f, &body, &origin);
                (*position).y += Particle_GetActorHeight(owner) * D_800C43E0_de[0];
                adjusted = 1;
            }
        }
        return adjusted;
}
static inline f32 hitSize(Shared_ReactionActor *target) {
    if (target->category == 1) return func_8024BEDC_de(target);
    else return D_800C43E0_de[2];
}
static inline void hitImpulse(Shared_ReactionActor *source, Shared_ReactionActor *target, Shared_DamageParameters copied, CVector3 *out) {
    CVector3 delta;
    CVector3 direction;
    CVector3 push;
    f32 orientation[4][4];
    f32 radius, distance;
    radius = (f32)copied.radius * D_800C43E0_de[6];
    radius *= func_802672D0_de(&target->category);
    out->z = 0.0f;
    out->y = 0.0f;
    out->x = 0.0f;
    /* The de release skips the push when the source has no health left. */
    if (
#ifdef VERSION_DE
        source->unk174 != 0 &&
#endif
        target->category == 2) {
        func_80271F68_de(&direction, &source->position, &target->position);
        distance = func_802B72B0_de(direction.x * direction.x + direction.y * direction.y + direction.z * direction.z);
        func_8027207C_de(&direction);
        if (!(radius <= distance)) {
            func_80271F9C_de(out, &direction, (f32)copied.impulse * (((radius - distance) / radius) * D_800C43E0_de[7]));
        }
    }
}
static inline f32 scaleHit(Shared_ReactionActor *self, Shared_ReactionActor *target, CVector3 position, f32 radius, s32 falloff, s32 flags, Shield **found) {
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
    CVector3 body;

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
            top = bottom + Particle_GetActorHeight(self);
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

void func_80266810_de(Shared_ReactionActor *source, Shared_ReactionActor *target, s32 kind, CVector3 position, Shared_DamageParameters params, s32 falloff, s32 knockback, s32 flags) {
    s32 restored2;
    s32 restored;
    f32 damage;
    CVector3 impulse;
    s32 adjusted;
    Shared_ReactionActor *owner;
    Shared_ReactionPlayer *ownerPlayer;
    s32 restored3;
    Shared_ReactionPlayer *carrier;
    s32 maximum;
    s32 maximum2;
    u8 category;
    Shield *shield;
    Shared_ReactionObjectKind *projectile;
    CDamageInfo hit;
    CDamageInfo *event;
    f32 radius;
    s32 maximum3;
    Shared_ReactionPlayer *attacker;
    Shared_ReactionPlayer *victim;

    attacker = NULL;
    if (source->flags & 0x300000) {
        attacker = source->unk1D8;
    }
    if (func_802661DC_de(source, target) != 0) {
        adjusted = adjustHit(target, &position);
        radius = (f32) params.radius * D_800C43E0_de[1];
        radius *= hitSize(target);
        damage = (f32)params.damage;
        damage *= scaleHit(source, target, position, radius, falloff, flags, &shield);
        if (!(damage <= 0.0f)) {
            hitImpulse(source, target, params, &impulse);
            event = &hit;
            func_80216488_de(event, target, (s32)damage, radius, flags, shield);
            category = target->category;
            if (category == 2) {
                projectile = &target->objectKind;
                owner = target->owner;
                if ((owner != NULL) && (owner->category == 1)) {
                    if (owner->flags & 0x300000) {
                        ownerPlayer = owner->unk1D8;
                        if (attacker != NULL) {
                            if (ownerPlayer->unk122C & 0x40) {
                                restored = ownerPlayer->unk5E4 + (s32) (damage * D_800C43E0_de[8]);
                                maximum = func_8022AC00_de(ownerPlayer);
                                if (restored < maximum) {
                                    maximum = restored;
                                }
                                storePlayerHealth(ownerPlayer, maximum);
                            }
                        }
                        if (attacker != NULL) {
                            {
                                if (attacker->unk122C & 0x10) {
                                    reflectedProjectile(ownerPlayer, target, damage, radius, flags, &shield);
                                }
                                if ((attacker != NULL) && (attacker->unk122C & 0x1000) && (func_80282C8C_de(projectile) != 0)) {
                                    restored2 = attacker->unk5E4 + (s32) damage;
                                    maximum2 = func_8022AC00_de(ownerPlayer);
                                    if (restored2 < maximum2) {
                                        maximum2 = restored2;
                                    }
                                    damage = 0.0f;
                                    storePlayerHealth(attacker, maximum2);
                                }
                            }
                        }
                        if ((damage > 0.0f) && (attacker != NULL) && (ownerPlayer->unk122C & 8) && (ownerPlayer != attacker)) {
                            attacker->unk122C = (s32) (attacker->unk122C | 0x4000);
                            attacker->unk11D8 = (f32) D_800C43E0_de[10];
                        }
                        if (ownerPlayer->unk122C & 0x200) {
                            damage *= D_800C43E0_de[11];
                            func_80216488_de(&hit, target, (s32)damage, radius, flags, shield);
                        }
                    } else if (target->type == 0x427) {
                        carrier = NULL;
                        if (owner->team == 0x40C) {
                            carrier = owner->unk1D8;
                        }
                        if ((carrier != NULL) && (carrier->unk122C & 0x200)) {
                            damage *= D_800C43E0_de[11];
                            func_80216488_de(event, target, (s32)damage, radius, flags, shield);
                        }
                    }
                    if (attacker != NULL) {
                        if ((attacker->unk122C & 0x800) && ((func_80282D38_de(projectile) != 0) || (func_80282DEC_de(projectile) != 0))) {
                            damage = 0.0f;
                        }
                        if ((attacker != NULL) && (attacker->unk122C & 0x400)) {
                            damage = 0.0f;
                        }
                    }
                }
            } else if (category == 1) {
                if (target->flags & 0x300000) {
                    victim = target->unk1D8;
                    if (attacker != NULL) {
                        if (victim->unk122C & 0x40) {
                            restored3 = victim->unk5E4 + (s32) (damage * D_800C43E0_de[12]);
                            maximum3 = func_8022AC00_de(victim);
                            if (restored3 < maximum3) {
                                maximum3 = restored3;
                            }
                            storePlayerHealth(victim, maximum3);
                        }
                    }
                    if (attacker != NULL) {
                        {
                            if (attacker->unk122C & 0x10) {
                                reflectedActor(victim, target, damage, radius, flags, &shield);
                            }
                        }
                    }
                    if ((damage > 0.0f) && (attacker != NULL) && (attacker != victim) && (victim->unk122C & 8)) {
                        attacker->unk122C = (s32) (attacker->unk122C | 0x4000);
                        attacker->unk11D8 = (f32) D_800C43E0_de[14];
                    }
                    if (victim->unk122C & 0x200) {
                        damage *= D_800C43E0_de[15];
                        func_80216488_de(&hit, target, (s32)damage, radius, flags, shield);
                    }
                }
                if ((attacker != NULL) && (attacker->unk122C & 0x400)) {
                    damage = 0.0f;
                }
                if ((damage > 0.0f) && (attacker != NULL)) {
                    attacker->unk1218 = (s32) (attacker->unk1218 == 0);
                }
            }
            if (damage != 0.0f) {
                func_802171FC_de(source, &source->unk170, &hit);
                func_8026641C_de(source, target, adjusted, position, impulse, knockback, shield, flags);
            }
        }
    }
}


extern f32 func_8024BEDC_de(void *arg0);

extern s32 D_80146894;


/* Forwards the actor, event value and three-component input with a zero final flag. */



extern f32 Particle_GetActorHeight(void *arg0);

/* Decides whether one actor may affect another: always when the override D_801462E5 is set; never for actors of the same kind or a target lacking flags 0x310000, nor, while D_8013B290 is set, when neither actor carries 0x300000; otherwise only when the target is in state 1, 4, 7 or 11. */

extern u8 D_801462E5;

extern s32 D_8013B290;

extern CallbackEntryRecAt4V1 D_800CC130[];
void func_80267198_de(void *arg0, void *arg1, s32 arg2, CVector3 arg3, ResourceManagerState arg6) {
    if (D_800CC130[arg2].callback != 0) {
        D_800CC130[arg2].callback(arg0, arg1, arg2, arg3, arg6);
    }
}

void func_802671FC_de(void *arg0, void *arg1, s32 arg2, CVector3 arg3, ResourceManagerState arg6) {
    if (D_800CC130[arg2].callback != 0) {
        D_800CC130[arg2].callback(arg0, arg1, arg2, arg3, arg6);
    }
}

void func_80267260_de(void *arg0, CVector3 input, s32 arg4) {
    CVector3 output;
    s32 value;

    func_8024E79C_de(arg0, input, &output, &value, 0, 0);
    if (arg4 != 0) {
        func_80276184_de((void *)value);
    } else {
        func_802761B8_de((void *)value);
    }
}

f32 func_802672D0_de(u8 *arg0) {
    if (*arg0 == 1) {
        return func_8024BEDC_de(arg0);
    } else {
        return D_800C4420_de;
    }
}

void func_8026730C_de(s32 arg0, ObjectRecAtD0 *arg1, s32 arg2, CVector3 arg3,
                   Clip arg6) {
    s32 *global = &D_80146894;
    s32 selected;
    f32 scale;

    scale = D_800C4424_de;
    selected = -1;
    if (global[0] != 0) {
        return;
    }

    if (arg1 != 0) {
        switch (arg1->type) {
        case 1:
            if (*arg1->kind == arg1->type) {
                if (global[-371] & 0x40) {
                    scale = D_800C4428_de;
                } else if (global[-371] & 0x20) {
                    scale = D_800C442C_de;
                }
            }
            selected = (s32)arg1;
            break;
        case 0:
            selected = arg1->value;
            break;
        case 2:
            selected = (s32)arg1;
            break;
        }
    }

    func_8025DEC0_de(arg6.frames, arg3, 0, selected, scale);
}

void func_802673EC_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 *p = &arg3;
    func_8025E11C_de(p[3]);
}

void func_8026740C_de(void *actor,int unused1,int unused2,Triple input,int event) {
 func_80216288_de(actor,event,input,0);
}

s32 func_80267444_de(void *arg0, CVector3 *arg1) {
    CVector3 first;
    CVector3 second;
    LevelActor *object = arg0;
    Shared_ActorView *actor;
    s16 state;
    s32 result;

    result = 0;
    if ((object->kind == 1) &&
        ((object->flags & 0x300000) != 0)) {
        actor = object->controller;
        if (arg0 == &actor->weapon) {
            state = actor->selectedAction;
            if ((state == 0) || (state == 0x11) || (state == 0x10)) {
                first = *arg1;
                second = ((LevelActor *)actor)->position0;
                func_80271FC8_de(arg1, 0.75f, &first, &second);
                arg1->y += Particle_GetActorHeight(actor) * D_800C4430_de;
                result = 1;
            }
        }
    }
    return result;
}

s32 func_80267528_de(char *actor, char *target)
{
    LevelActor *source = (LevelActor *)actor;
    LevelActor *destination = (LevelActor *)target;
    s32 flags;

    if (D_801462E5 != 0) {
        return 1;
    }
    if (source->type == destination->type) {
        return 0;
    }
    flags = destination->flags;
    if (!(flags & 0x310000)) {
        return 0;
    }
    if (D_8013B290 != 0 && !(source->flags & 0x300000) && !(flags & 0x300000)) {
        return 0;
    }
    switch (destination->definition->kind) {
    case 1:
    case 4:
    case 7:
    case 11:
        return 1;
    }
    return 0;
}

#include "TYPES.H"
#include "COMMON/AIPROFILE.H"
extern f32 func_802B72B0_de(f32);
extern f32 D_800C46E8_eu;
extern void func_80271F68_de(void *, void *, void *);
typedef struct PushStrength { u16 value; u16 pad; } PushStrength;
typedef struct PushScale { s8 value; u8 pad[3]; } PushScale;
extern f32 D_800C4434_de;
void func_802675C8_de(struct Player *actor, u8 *other, PushStrength strength, PushScale scale, CVector3 *out) {
    char frame[0x10];
    CVector3 offset;
    char scratch[0x50];
    f32 radius;
    f32 distance;
    radius = (f32)strength.value * D_800C4434_de;
    radius *= func_802672D0_de(other);
    out->x = out->y = out->z = 0.0f;
#ifdef VERSION_DE
    if (*(s32 *)((u8 *)actor + 0x174) != 0 && *other == 2) {
#else
    if (*other == 2) {
#endif
        func_80271F68_de(&offset, &actor->pos, &((struct Player *)other)->pos);
        distance = func_802B72B0_de(offset.x * offset.x + offset.y * offset.y + offset.z * offset.z);
        func_8027207C_de(&offset.x);
        if (!(radius <= distance)) {
            func_80271F9C_de(out, &offset, (f32)scale.value * (((radius - distance) / radius) * D_800C46E8_eu));
        }
    }
}
