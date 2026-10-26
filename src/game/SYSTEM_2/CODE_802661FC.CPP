#include "include_asm.h"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/WORLD.H"
#include "COMMON/TARGET.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/OBJECTLINKS4_2.H"
#include "TYPES.H"
#include "COMMON/ANIMATIONTRIGGERDEFINITION.H"
#include "SYSTEM_2/CODE_802661FC.H"
extern void GraphU64_NormalizeVec3(f32 *arg0);

typedef struct DamageDefinition { s32 kind; } DamageDefinition;
typedef struct DamageActor {
    u8 category; char pad01[3]; u16 kind; char pad06[0x12];
    DamageDefinition *definition;
    char pad1C[0xC8]; u16 team; char padE6[0x1A]; u32 flags;
    char pad104[0x14]; u32 *properties;
    char pad11C[0x10]; struct DamageActor *owner;
    char pad130[0xA8]; struct ReactionPlayer *player;
} DamageActor;

#include "TYPES.H"
#include "FX_2/80271B18.H"


extern s32 func_8024D160_de(void *);

/* Whether source may hurt target: never itself, nor when source is a player whose hit func_8024D160_de refuses;
 * a stand-in (category 2) is safe when its owner is a player canDamage protects, when source owns it and it has
 * property 0x40, or for source kind 1 on team 0xCA against kind 0x14; players (category 1) go through canDamage. */
static inline s32 canDamage(DamageActor *source, DamageActor *actor) {
    if (D_801462C8.local) {
        return 1;
    }
    if (actor->team == source->team) {
        return 0;
    }
    if (!(source->flags & 0x310000)) {
        return 0;
    }
    if (g_world.visibilityEnabled && !(actor->flags & 0x300000) && !(source->flags & 0x300000)) {
        return 0;
    }
    switch (source->definition->kind) {
    case 1:
    case 4:
    case 7:
    case 11:
        return 1;
    }
    return 0;
}
s32 Events_CanDamageActor(DamageActor *source, DamageActor *target) {
    DamageActor *owner;
    DamageActor *standIn;
    if (source == target) {
        return 0;
    }
    if ((source->flags & 0x300000) && !func_8024D160_de(source)) {
        return 0;
    }
    if (target->category != 1) {
        if (target->category == 2) {
            standIn = target;
            owner = standIn->owner;
            if (owner) {
                if (owner->category == 1 && !canDamage(source, owner)) {
                    return 0;
                }
                if (source == standIn->owner && (*standIn->properties & 0x40)) {
                    return 0;
                }
            }
            if (standIn->kind == 0x14 && source->definition->kind == 1 && source->team == 0xCA) {
                return 0;
            }
        }
    } else if (!canDamage(source, target)) {
        return 0;
    }
    return 1;
}

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
extern float D_800C43D4_de;
extern float D_800C43DC_de;

void func_8022B09C_de(s32, f32 *);
void func_8028CE94_de(Shared_World *, s32, s32, CVector3, f32, f32);
extern s32 D_8011D8D0;
extern float D_800C43D8_de;

#include "particle/8027A0F4_8.H"
typedef struct ReactionDisplay {
    char pad000[0x128];
    CVector3 origin;
} ReactionDisplay;
typedef struct ReactionPlayer {
    char pad000[0x5DC];
    ReactionDisplay *display;
    char pad5E0[0xB8];
    s32 sound;
} ReactionPlayer;
typedef struct ReactionActor {
    u8 category; char pad01[7];
    CVector3 position;
    char pad14[4];
    DamageDefinition *definition;
    CVector3 velocity;
    char pad28[0x44];
    f32 turn;
    char pad70[0x90];
    u32 flags;
    char pad104[0x6C];
    u32 eventFlags;
    char pad174[0x38];
    u32 effectFlags;
    char pad1B0[0x28];
    ReactionPlayer *player;
} ReactionActor;

typedef struct ReactionShield {
    char pad00[0x66];
    u8 effectKind; /* 0x66: impact response variant (4 or 5) */
} ReactionShield;

static inline s32 isReflectShield(ReactionShield *shield) {
    if (shield->effectKind == 4 || shield->effectKind == 5) {
        return 1;
    }
    return 0;
}
static inline void applyShieldReaction(ReactionActor *target, ReactionPlayer *player, CVector3 position, CVector3 impulse, s32 effectKind) {
    CVector3 localImpulse;
    CVector3 effectPosition;
    CVector3 zero;
    CQuatern rotation;
    s32 hit[2];
    if (player->display) {
        player = target->player;
        localImpulse.x = -impulse.x;
        localImpulse.y = impulse.y;
        localImpulse.z = impulse.z;
        func_8022B09C_de((s32)player, &localImpulse.x);
        localImpulse.x -= player->display->origin.x;
        localImpulse.y -= player->display->origin.y;
        localImpulse.z -= player->display->origin.z;
        rotation = GraphU64_BuildDirectionQuaternion(&localImpulse.x);
        InstHdr_CopyActorPositionAndModel((Actor_func_80214624_de *)target, position,
                         &effectPosition, hit, 0, 1);
        effectPosition = position;
        effectPosition.y += D_800C43D0_de;
        zero.x = 0.0f; zero.y = 0.0f; zero.z = 0.0f;
        func_802800C0_de((struct EffectSystem *)&D_8011D8D0,
                         (struct EffectActor *)target, (struct EffectActor *)target,
                         0, 0, 0xE9, zero, rotation, effectPosition, 0, -1,
                         effectKind == 5 ? 3 : 1);
        effectPosition.x = 0.0f; effectPosition.y = 0.0f; effectPosition.z = 0.0f;
        func_8028CE94_de(&g_world, player->sound + 0x140, 3,
                         effectPosition, D_800C43D4_de, D_800C43D8_de);
    }
}

/* Applies a hit's reaction: a player victim gets its hit flag, the attacker's screen shake, and (when the hit is
 * absorbed) a reflect-shield spark plus sound with the impulse cancelled; walking/flying attackers then take the
 * impulse and optionally turn toward the target. */
void Events_ApplyDamageReaction(void *sourceObject, char *targetObject, s32 absorbImpulse, CVector3 position, CVector3 impulse,
                      s32 applyTurn, ReactionShield *shield, u32 hitFlags) {
    ReactionActor *source = (ReactionActor *)sourceObject;
    ReactionActor *target = (ReactionActor *)targetObject;
    s32 absorb = absorbImpulse;
    f32 angle;
    if (target->category == 1) {
        DamageActor *victim = (DamageActor *)target;
        target->eventFlags |= 0x8000;
        if ((source->flags & 0x300000) && source->player->display) {
            if (target->effectFlags & 0x4000) {
                Sky_StartScaledShake((char *)source->player->display, D_800C43C4_de,
                                 100.0f, D_800C43C4_de, D_800C43C0_de, 1, position);
            } else if (target->effectFlags & 0x2000) {
                Sky_StartScaledShake((char *)source->player->display, D_800C43CC_de,
                                 50.0f, D_800C43CC_de, D_800C43C8_de, 1, position);
            }
        }
        if (absorb) {
            if (shield && (victim->flags & 0x300000) &&
                isReflectShield(shield)) {
                applyShieldReaction(target, victim->player, position, impulse, shield->effectKind);
            }
            impulse.x = 0.0f; impulse.y = 0.0f; impulse.z = 0.0f;
        }
        if ((victim->flags & 0x300000) && (hitFlags & 0x200)) {
            Link_DispatchActorLinks((struct Shared_Actor *)source, 0x10, victim);
        }
    }
    if (source->definition->kind == 1 || source->definition->kind == 11) {
        GraphU64_AddVec3(&source->velocity, &source->velocity, &impulse);
        if (applyTurn) {
            angle = Barrel_GetSignedAngleToPoint((Actor_func_80214624_de *)source, target->position);
            source->turn += angle * D_800C43DC_de;
        }
    }
}

#include "stddef.h"
#include "COMMON/GAMEPLAY_REACTIONS.H"
/* Published contiguous pool of damage scaling constants, read by index. */
extern const f32 D_800C43E0_de[16];
/* Forwards the actor, event value and three-component input with a zero final flag. */
extern void GraphU64_InterpolateVector(CVector3 *, f32, CVector3 *, CVector3 *);
extern f32 func_8024BEDC_de(void *);
extern s32 func_8024B06C_de(void *, CVector3, Shield *);
extern f32 GraphU64_GetPointDistance(CVector3 *, CVector3 *);
extern f32 Events_GetActorSizeScale(u8 *);
extern void Barrel_FillDamagePacket(CDamageInfo *, void *, s32, f32, s32, Shield *);
extern s32 Player_GetMaxHealth(void *);
struct CallbackState114;
extern void Barrel_RunDamageHook(void *, struct CallbackState114 *, CDamageInfo *);
extern s32 Particle_HasKindOneEntry(Shared_ReactionObjectKind *);
extern s32 Particle_HasKindZeroEntry(Shared_ReactionObjectKind *);
extern s32 Particle_HasKindTwoEntry(Shared_ReactionObjectKind *);
extern void *D_801041F0;
extern s32 D_80100204;
extern Shield D_80100208;
static inline void storeActorHealth(Shared_ReactionActor *actor, s32 value) { actor->unk174 = value; }
static inline void storePlayerHealth(Shared_ReactionPlayer *player, s32 value) {
    player->unk5E4 = value;
    player->unk174 = player->unk5E4;
    storeActorHealth(&player->actor2E8, player->unk5E4);
}
static inline void buildDamage(CDamageInfo *event, Shared_ReactionActor *target, f32 damage, f32 radius, s32 flags, Shield **shield) {
    Barrel_FillDamagePacket(event, target, (s32)damage, radius, flags, *shield);
}
static inline void reflectedProjectile(Shared_ReactionPlayer *player, Shared_ReactionActor *target, f32 damage, f32 radius, s32 flags, Shield **shield) {
    CDamageInfo event;
    CDamageInfo *p = &event;
    buildDamage(p, target, damage * 2.0f, radius, flags, shield);
    if (damage * D_800C43E0_de[9] > 0.0f) Barrel_RunDamageHook(player, &player->unk170, p);
}
static inline void reflectedActor(Shared_ReactionPlayer *player, Shared_ReactionActor *target, f32 damage, f32 radius, s32 flags, Shield **shield) {
    CDamageInfo event;
    CDamageInfo *p = &event;
    f32 value = damage * D_800C43E0_de[13];
    buildDamage(p, target, value, radius, flags, shield);
    if (value > 0.0f) Barrel_RunDamageHook(player, &player->unk170, p);
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
                GraphU64_InterpolateVector(&(*position), 0.75f, &body, &origin);
                (*position).y += GameObject_GetActorHeight(owner) * D_800C43E0_de[0];
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
    radius *= Events_GetActorSizeScale(&target->category);
    out->z = 0.0f;
    out->y = 0.0f;
    out->x = 0.0f;
    /* The de release skips the push when the source has no health left. */
    if (
#ifdef VERSION_DE
        source->unk174 != 0 &&
#endif
        target->category == 2) {
        GraphU64_SubtractVectors(&direction, &source->position, &target->position);
        distance = Math_Sqrtf(direction.x * direction.x + direction.y * direction.y + direction.z * direction.z);
        GraphU64_NormalizeVec3(&direction);
        if (!(radius <= distance)) {
            GraphU64_ScaleVector(out, &direction, (f32)copied.impulse * (((radius - distance) / radius) * D_800C43E0_de[7]));
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
    if (D_801462C8.local != 0 && (flags & 0x200)) {
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
            top = bottom + GameObject_GetActorHeight(self);
            if (top < position.y) {
                body.y = top;
            } else if (position.y < bottom) {
                body.y = bottom;
            } else {
                body.y = position.y;
            }
            reach = radius + GameObject_GetActorRadius(self);
            distance = GraphU64_GetPointDistance(&position, &body);
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

void Events_ApplyDamageEvent(Shared_ReactionActor *source, Shared_ReactionActor *target, s32 kind, CVector3 position, Shared_DamageParameters params, s32 falloff, s32 knockback, s32 flags) {
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
    if (Events_CanDamageActor(source, target) != 0) {
        adjusted = adjustHit(target, &position);
        radius = (f32) params.radius * D_800C43E0_de[1];
        radius *= hitSize(target);
        damage = (f32)params.damage;
        damage *= scaleHit(source, target, position, radius, falloff, flags, &shield);
        if (!(damage <= 0.0f)) {
            hitImpulse(source, target, params, &impulse);
            event = &hit;
            Barrel_FillDamagePacket(event, target, (s32)damage, radius, flags, shield);
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
                                maximum = Player_GetMaxHealth(ownerPlayer);
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
                                if ((attacker != NULL) && (attacker->unk122C & 0x1000) && (Particle_HasKindOneEntry(projectile) != 0)) {
                                    restored2 = attacker->unk5E4 + (s32) damage;
                                    maximum2 = Player_GetMaxHealth(ownerPlayer);
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
                            Barrel_FillDamagePacket(&hit, target, (s32)damage, radius, flags, shield);
                        }
                    } else if (target->type == 0x427) {
                        carrier = NULL;
                        if (owner->team == 0x40C) {
                            carrier = owner->unk1D8;
                        }
                        if ((carrier != NULL) && (carrier->unk122C & 0x200)) {
                            damage *= D_800C43E0_de[11];
                            Barrel_FillDamagePacket(event, target, (s32)damage, radius, flags, shield);
                        }
                    }
                    if (attacker != NULL) {
                        if ((attacker->unk122C & 0x800) && ((Particle_HasKindZeroEntry(projectile) != 0) || (Particle_HasKindTwoEntry(projectile) != 0))) {
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
                            maximum3 = Player_GetMaxHealth(victim);
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
                        Barrel_FillDamagePacket(&hit, target, (s32)damage, radius, flags, shield);
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
                Barrel_RunDamageHook(source, &source->unk170, &hit);
                Events_ApplyDamageReaction(source, target, adjusted, position, impulse, knockback, shield, flags);
            }
        }
    }
}


extern f32 func_8024BEDC_de(void *arg0);



/* Forwards the actor, event value and three-component input with a zero final flag. */




/* Decides whether one actor may affect another: always when the override D_801462E5 is set; never for actors of the same kind or a target lacking flags 0x310000, nor, while D_8013B290 is set, when neither actor carries 0x300000; otherwise only when the target is in state 1, 4, 7 or 11. */



extern CallbackEntryRecAt4V1 D_800CC130[];
void Events_DispatchCallback(void *arg0, void *arg1, s32 arg2, CVector3 arg3, ResourceManagerState arg6) {
    if (D_800CC130[arg2].callback != 0) {
        D_800CC130[arg2].callback(arg0, arg1, arg2, arg3, arg6);
    }
}

void Events_ForwardCallback(void *arg0, void *arg1, s32 arg2, CVector3 arg3, ResourceManagerState arg6) {
    if (D_800CC130[arg2].callback != 0) {
        D_800CC130[arg2].callback(arg0, arg1, arg2, arg3, arg6);
    }
}

void Events_UpdateNodeAtPosition(void *actor, CVector3 input, s32 arg4) {
    CVector3 output;
    s32 value;

    InstHdr_CopyActorPositionAndModel(actor, input, &output, &value, 0, 0);
    if (arg4 != 0) {
        Region_SetNodeGroupFlag((void *)value);
    } else {
        Region_ClearNodeGroupFlag((void *)value);
    }
}

f32 Events_GetActorSizeScale(u8 *other) {
    if (*other == 1) {
        return func_8024BEDC_de(other);
    } else {
        return D_800C4420_de;
    }
}

void Events_PlayClipEvent(s32 arg0, ObjectRecAtD0 *arg1, s32 arg2, CVector3 arg3,
                   Clip arg6) {
    s32 *global = &D_8011FAC0.clockPaused;
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

void Events_StopClipEvent(s32 unused0, s32 unused1, s32 unused2, s32 arg3, s32 unused4, s32 unused5, s32 unused6) {
    s32 *p = &arg3;
    func_8025E11C_de(p[3]);
}

void Events_SpawnActorEffect(void *actor,int unused1,int unused2,Triple input,int event) {
 Barrel_SpawnActorEffect(actor,event,input,0);
}

s32 Events_AdjustWeaponHitPosition(void *levelActor, CVector3 *arg1) {
    CVector3 first;
    CVector3 second;
    LevelActor *object = levelActor;
    Shared_ActorView *actor;
    s16 state;
    s32 result;

    result = 0;
    if ((object->kind == 1) &&
        ((object->flags & 0x300000) != 0)) {
        actor = object->controller;
        if (levelActor == &actor->weapon) {
            state = actor->selectedAction;
            if ((state == 0) || (state == 0x11) || (state == 0x10)) {
                first = *arg1;
                second = ((LevelActor *)actor)->position0;
                GraphU64_InterpolateVector(arg1, 0.75f, &first, &second);
                arg1->y += GameObject_GetActorHeight(actor) * D_800C4430_de;
                result = 1;
            }
        }
    }
    return result;
}

s32 Events_CanAffectActor(char *actor, char *target)
{
    LevelActor *source = (LevelActor *)actor;
    LevelActor *destination = (LevelActor *)target;
    s32 flags;

    if (D_801462C8.local != 0) {
        return 1;
    }
    if (source->type == destination->type) {
        return 0;
    }
    flags = destination->flags;
    if (!(flags & 0x310000)) {
        return 0;
    }
    if (g_world.visibilityEnabled != 0 && !(source->flags & 0x300000) && !(flags & 0x300000)) {
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
    radius *= Events_GetActorSizeScale(other);
    out->x = out->y = out->z = 0.0f;
#ifdef VERSION_DE
    if (*(s32 *)((u8 *)actor + 0x174) != 0 && *other == 2) {
#else
    if (*other == 2) {
#endif
        GraphU64_SubtractVectors(&offset, &actor->pos, &((struct Player *)other)->pos);
        distance = Math_Sqrtf(offset.x * offset.x + offset.y * offset.y + offset.z * offset.z);
        GraphU64_NormalizeVec3(&offset.x);
        if (!(radius <= distance)) {
            GraphU64_ScaleVector(out, &offset, (f32)scale.value * (((radius - distance) / radius) * D_800C46E8_eu));
        }
    }
}
