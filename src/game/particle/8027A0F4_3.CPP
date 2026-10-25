#include "include_asm.h"
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/MATH_HELPERS.H"
#include "stddef.h"
#include "TYPES.H"
#include "FX_2/80271B18.H"
#include "particle/80271B18_3.H"
#include "FX_2/PARTICLE_ATTACHMENT.H"
#include "SYSTEM_3/CONTACT_EFFECT.H"

/* Updates a particle for one frame: halves the frame step for particles owned by a slowed object, measures its bounding
 * box, kills it or bounces it off its target when its type's rule says so (the German cartridge has a gentler rule
 * table), advances its spin and size (growing towards a capped target size, or dying when a size goes negative), lets
 * nearby players react to it, and when it moves or falls probes the ground through func_80243A90_de, orients itself to the
 * surface it hit and runs the collision responses its descriptor allows. D_800D2988 (the frame step) is restored on
 * every exit after the early time check. */
extern f32 D_800D2988;

extern ParticleAttachmentState *D_80103FCC;

extern ParticleAttachmentState D_801041F0;

extern char D_8011D8D0;

extern SharedPlayer *D_80145060;

s32 func_80243A90_de(Shared_Particle *particle, CVector3 pos, s32 *flags);

f32 Particle_GetActorHeight(SharedPlayer *player);

void func_80271F68_de(CVector3 *normal, CVector3 *pos, void *surface);


f32 func_802726BC_de(CVector3 *a, CVector3 *b);

s32 func_802744D4_de(void);

void func_8027AD4C_de(Shared_Particle *particle);

void func_8027B428_de(Shared_Particle *particle);

void func_8027C274_de(Shared_Particle *particle);

void func_8027C4F0_de(Shared_Particle *particle);

void func_8027C758_de(Shared_Particle *particle);

void func_8027C9CC_de(Shared_Particle *particle);

#if defined(VERSION_DE)
void func_8027CC20_de(Shared_Particle *particle);
#elif defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
void Particle_HitTarget(void *particle);
#endif

void Particle_ApplyImpactResponse(Shared_Particle *particle);

void func_80282E98_de(Shared_Particle *particle, SharedPlayer *player);

void func_80283E58_de(Shared_Particle *particle);

void func_80283F60_de(Shared_Particle *particle);

void func_8028422C_de(Shared_Particle *particle);

/* Squared distance from the particle to a player's position, raised by half the player's height unless the particle
 * is type 0x40F. */
static inline f32 func_8027B790_distance(Shared_Particle *particle, SharedPlayer *player) {
    CVector3 pos;
    pos = player->views0.view8_3.pos;
    if (particle->inst.type != 0x40F) {
        pos.y += Particle_GetActorHeight(player) * 0.5f;
    }
    return func_802726BC_de(&particle->inst.pos, &pos);
}

extern CVector3 D_80100290;

extern CVector3 D_801042C8;

extern s32 func_80276088_de(s32);

extern void func_80265E10_de(void *, void *, u16, s32, CVector3, struct IntPair);
extern struct Shape_typemap_165 func_80271818_de(CVector3 *);

#include "particle/8027A0F4_8.H"

extern s32 func_8025DE54_de(s16, CVector3, s32, s32);

extern void func_80271F9C_de(CVector3 *, CVector3 *, f32);
extern void func_80284570_de(void *, void *);
/* Picks an animation slot from a global mode, then plays the slot's effect, spawns its object at the owner or a fixed position, plays its sound, and flags the owner. Adapted from func_8027C9CC_de, with the slot chosen by a switch on D_801042C4 (the extra case below 7 that shares the default body is needed for the decision tree; its value is not recoverable), the constant triple, one argument, the dropped func_80271F9C_de call, and the final test changed. */





extern CVector3 D_801002B8;

extern CVector3 D_801002A8;

extern s32 func_802757E4_de(s32);

extern s32 func_80276054_de(s32);

/* Per-frame step of one live particle: sizes its culling box, resolves target hit and death, grows and spins it,
 * applies influence to nearby players, then runs the move and collision passes. */
void Particle_Update(Shared_Particle *particle) {
    Box bounds;
    Shared_ParticleOwner *owner;
    Shared_ParticleTarget *target;
    SharedPlayer *player;
    f32 savedStep;
    f32 extent;
    f32 boxSpan; /* the larger scaled size, then the box height */
    f32 halfExtent; /* the box half-size, then the shake decay */
    f32 growStep;
    f32 goalSize;
    f32 influenceRange;
    s32 die;
    s32 bounce;
    s32 done;
    s8 newShake;
    owner = particle->owner;
    savedStep = D_800D2988;
    if (particle->time < 0.0f) {
        return;
    }
    if (owner != NULL && owner->kind == 1 && (owner->flags & 0x300000) && owner->state != NULL &&
        (owner->state->flags & 0x2000)) {
        D_800D2988 = savedStep * 0.25f;
    }
    extent = particle->size.z;
    boxSpan = particle->size.y * extent;
    if (!(particle->size.x * extent <= boxSpan)) {
        boxSpan = particle->size.x * extent;
    }
    if (!(boxSpan <= extent)) {
        extent = boxSpan;
    }
    boxSpan = extent * 1.4142135f;
    halfExtent = boxSpan * 0.5f;
    bounds.min.x = particle->inst.pos.x - halfExtent;
    bounds.max.x = particle->inst.pos.x + halfExtent;
    bounds.min.y = particle->inst.pos.y - halfExtent;
    bounds.max.y = particle->inst.pos.y + boxSpan;
    bounds.min.z = particle->inst.pos.z - halfExtent;
    bounds.max.z = particle->inst.pos.z + halfExtent;
    if (particle->flags & 0x20000) {
        particle->time = 0.0f;
        particle->life = particle->unk148 * 32.0f;
        halfExtent = particle->shake - D_800D2988 * 6.0f;
        newShake = (halfExtent < 0.0f) ? 0 : (s32)halfExtent;
        particle->shake = newShake;
    }
    if (particle->flags & 0x10000) {
        target = particle->target;
        switch (particle->inst.type) {
            default:
                particle->time = 0.0f;
                particle->life = particle->unk148 * 32.0f;
            case 0x2D:
            case 0x4F:
                die = 0;
                break;
            case 0xB:
            case 0x41E:
                die = 0;
                break;
        }
        bounce = die;
        switch (particle->inst.type) {
            case 0x12A:
            case 0x132:
                die = 0;
#if defined(VERSION_DE)
                bounce = 1;
#elif defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
                if (target->unk174 == 0) {
                    bounce = 1;
                }
#endif
                break;
            case 2:
#if defined(VERSION_DE)
            case 0x111:
            case 0x3F5:
                bounce = 1;
            case 0x41E:
                die = 0;
                break;
#elif defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
#endif
            case 0xF:
            case 0x56:
#if defined(VERSION_DE)
#elif defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
            case 0x111:
#endif
            case 0x126:
#if defined(VERSION_DE)
                die = 1;
#elif defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
            case 0x3F5:
                if (particle->flags & 0x4000000) {
                    die = 1;
                } else if (!(target->flags & 0x100)) {
                    die = 1;
                } else if (target->flags & 0x300000) {
                    die = (f32)target->unk174 <= 0.0f;
                } else {
                    die = target->unk170 & 0x20;
                }
#endif
                bounce = 0;
                break;
            case 0xB:
                die = 0;
                if (target->unk1A4 != 0x21 || !(target->flags & 0x100)) {
                    bounce = 1;
                }
                break;
            case 4:
                die = 0;
                if (target->unk1A4 != 0x20 || !(target->flags & 0x100)) {
                    bounce = 1;
                }
                break;
            case 0x2D:
            case 0x4F:
                bounce = !(target->flags & 0x100);
#if defined(VERSION_DE)
#elif defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
                break;
            case 0x41E:
                die = 0;
#endif
                break;
            default:
                bounce = die = 0;
                particle->flags &= ~0x10000;
                break;
        }
        if (die || bounce) {
            particle->time = 0.0f;
            particle->space = -7;
            particle->flags = (particle->flags & ~0x30000) | 0x40000;
            particle->rot.z = (f32)(func_802744D4_de() % 360) * 0.017453294f;
            particle->inst.velocity.y = 0.0f;
            if (particle->flags & 0x4000000) {
                particle->inst.velocity.x = -particle->direction.x;
                particle->inst.velocity.z = -particle->direction.z;
            } else {
                particle->inst.velocity.x = 0.0f;
                particle->inst.velocity.z = 0.0f;
            }
            particle->inst.unk14 = 0;
            particle->unk1B4 &= ~0x4000;
            if (bounce) {
                particle->life = 1;
            }
        }
    }
    if (particle->flags & 0x40000) {
        if (func_80243A90_de(particle, particle->inst.pos, &particle->unk1B4) && D_801041F0.unkB4 != 0) {
            particle->space = -3;
        }
        if (particle->inst.unk38 & 0x1000) {
            particle->flags |= 4;
        } else {
            particle->flags &= ~4;
        }
    }
    particle->prevPos = particle->inst.pos;
    particle->frame += D_800D2988 * particle->unk148 * (D_800CD740_de * 0.06666667f);
    if (particle->desc->flags & 0x1000) {
        growStep = D_800D2988 * 10.24f;
        particle->size.x += growStep * particle->growth.x;
        particle->size.y += growStep * particle->growth.y;
        particle->size.z += D_800D2988 * particle->growth.z;
        particle->size.x = (particle->size.x > 4096.0f) ? 4096.0f : particle->size.x;
        particle->size.y = (particle->size.y > 4096.0f) ? 4096.0f : particle->size.y;
        particle->size.z = (particle->size.z > 400.0f) ? 400.0f : particle->size.z;
    } else {
        goalSize = RW_MIN(particle->size.x * particle->growth.x, 4096.0f);
        particle->size.x += (goalSize - particle->size.x) * D_800D2988;
        goalSize = RW_MIN(particle->size.y * particle->growth.y, 4096.0f);
        particle->size.y += (goalSize - particle->size.y) * D_800D2988;
        goalSize = RW_MIN(particle->size.z * particle->growth.z, 400.0f);
        particle->size.z += (goalSize - particle->size.z) * D_800D2988;
        if (particle->size.x < 0.0f || particle->size.y < 0.0f || particle->size.z < 0.0f) {
            func_80283F60_de(particle);
            func_80284570_de(&D_8011D8D0, particle);
            ((void (*)(Shared_Particle *))func_80284434_de)(particle);
            D_800D2988 = savedStep;
            return;
        }
    }
    particle->rot.x += particle->rotSpeed.x * D_800D2988;
    particle->rot.y += particle->rotSpeed.y * D_800D2988;
    particle->rot.z += particle->rotSpeed.z * D_800D2988;
    D_80103FCC->direction = particle->inst.velocity;
    func_80283E58_de(particle);
    influenceRange = particle->desc->unk10;
    if (!(influenceRange <= 0.0f)) {
        influenceRange *= 10.24f;
        influenceRange *= influenceRange;
        for (player = D_80145060; player != NULL;) {
            done = 0;
            if (func_8027B790_distance(particle, player) < influenceRange) {
                func_80282E98_de(particle, player);
                if (particle->inst.type == 0x40F) {
                    done = 1;
                }
            }
            if (done) {
                player = NULL;
            } else {
                player = player->views16E0.view16E0_1.next;
            }
        }
    }
    func_8027AD4C_de(particle);
    if ((particle->unk1BC == 0.0f || (particle->inst.pos.y == 0.0f && particle->unk1BC < 0.0f)) &&
        particle->inst.velocity.x * particle->inst.velocity.x + particle->inst.velocity.y * particle->inst.velocity.y +
                particle->inst.velocity.z * particle->inst.velocity.z <
            0.001f) {
        D_800D2988 = savedStep;
        return;
    }
    if (!(particle->flags & 0x72000)) {
        die = func_80243A90_de(particle, particle->inst.pos, &particle->unk1B4);
        if (particle->inst.unk38 & 0x1000) {
            particle->flags |= 4;
        } else {
            particle->flags &= ~4;
        }
        if (particle->inst.type == 0x68 && D_801041F0.current != NULL) {
            particle->target = D_801041F0.current;
        }
        if (die) {
            if (D_801041F0.current != NULL) {
                func_80271F68_de(&particle->direction, &particle->inst.pos, &D_801041F0.origin);
            } else if (D_801041F0.unk88 != 0) {
                func_80271F68_de(&particle->direction, &particle->inst.pos, &D_801041F0.unk90);
            } else if (D_801041F0.unk9C != 0) {
                func_80271F68_de(&particle->direction, &particle->inst.pos, &D_801041F0.unkA0);
            } else if (D_801041F0.unkB4 != 0) {
                func_80271F68_de(&particle->direction, &particle->inst.pos, &D_801041F0.unkB8);
                if (particle->space == -7) {
                    particle->space = -3;
                }
            } else if (D_801041F0.unkC4 != 0) {
                func_80271F68_de(&particle->direction, &particle->inst.pos, &D_801041F0.unkC8);
            }
            func_8027207C_de(&particle->direction);
        }
        func_8027B428_de(particle);
        if (D_801041F0.unkC4 != 0) {
            func_8027C4F0_de(particle);
        }
        if (particle->flags & 0x100) {
            if (D_801041F0.unk9C != 0) {
                if (!(particle->desc->flags & 0x10000000)) {
                    func_8027C274_de(particle);
                }
                if (particle->desc->flags & 0x800) {
                    particle->unk1B9 = 1;
                }
            }
            if (particle->flags & 0x100) {
                if (D_801041F0.current != NULL) {
                    if ((particle->unk1B4 & 0x4000) && D_801041F0.current->kind == 0) {
                        Particle_ApplyImpactResponse(particle);
                    } else {
#if defined(VERSION_DE)
                        func_8027CC20_de(particle);
#elif defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
                        Particle_HitTarget(particle);
#endif
                    }
                    if (particle->desc->flags & 0x800) {
                        particle->unk1B9 = 1;
                    }
                }
                if ((particle->flags & 0x100) && D_801041F0.unkB0 != 0 && !(particle->desc->flags & 0x20000000)) {
                    if (D_801041F0.unkB0 == 1) {
                        func_8027C758_de(particle);
                    } else {
                        func_8027C9CC_de(particle);
                    }
                }
            }
        }
    }
    if ((particle->flags & 0x8100) == 0x100) {
        func_8028422C_de(particle);
    }
    D_800D2988 = savedStep;
}

void func_8027C274_de(Shared_Particle *particle) {
    struct IntPair pair;
    struct Shape_typemap_165 rotation;
    CVector3 position;
    s32 temp_a1;
    struct Shared_ParticleEvents *events;
    s32 var_a0;
    s32 temp_a2;
    s32 kind;
    s32 sound;
    struct Shared_ParticleDesc *desc;
    struct IntPair *temp_v0_2;

    if ((particle->flags & 0x400) != 0) {
        if ((particle->desc->flags & 0x800) != 0) {
            goto skip_effects;
        }
    }
    {
        var_a0 = func_80276088_de(0);
        if (var_a0 == 10) {
            var_a0 = 0;
        }
        desc = particle->desc;
        temp_a1 = var_a0;
        events = desc->events;
        kind = events->particles[temp_a1];
        temp_a2 = events->effects[temp_a1];
        temp_v0_2 = &events->parameters[var_a0];
        pair = *temp_v0_2;
        sound = desc->events->sounds[temp_a1];
        if (temp_a2 != 0xFFFF) {
            func_80265E10_de(particle, particle, temp_a2, -1, D_80100290, pair);
        }
        if (kind != 0xFFFF) {
            if ((particle->desc->flags & 0x10) != 0) {
                position = D_801042C8;
            } else {
                position = particle->inst.velocity;
            }
            rotation = func_80271818_de(&position);
            func_802800C0_de((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)particle,
                          (struct EffectActor *)particle->owner,
                          (s32 *)particle->ownerId,
                          (s32)particle->target, kind,
                          position, *(CQuatern *)&rotation, D_80100290, 0,
                          D_8010029C,
                          (particle->flags & 0x200006) | 1);
        }
        if (sound != 0xFFFF) {
            func_8025DE54_de((s16)sound, D_80100290, 0, -1);
        }
    }
skip_effects:
    func_80271F9C_de(&particle->rotSpeed, &particle->rotSpeed,
                  particle->rotationScale);
    particle->flags |= 0x400;
    if (particle->unk1B9 == 1) {
        func_80284570_de(&D_8011D8D0, particle);
        func_80284434_de(particle);
    }
}

void func_8027C4F0_de(Shared_Particle *particle) {
    struct IntPair pair;
    struct Shape_typemap_165 rotation;
    CVector3 position;
    s32 temp_a1;
    struct Shared_ParticleEvents *events;
    s32 var_a0;
    s32 temp_a2;
    s32 kind;
    s32 sound;
    struct Shared_ParticleDesc *desc;
    struct IntPair *temp_v0_2;

    switch (D_801042C4) {
    case 1:
    default:
        var_a0 = 1;
        break;
    case 7:
        var_a0 = 7;
        break;
    case 8:
        var_a0 = 8;
        break;
    }
    desc = particle->desc;
    temp_a1 = var_a0;
    events = desc->events;
    kind = events->particles[temp_a1];
    temp_a2 = events->effects[temp_a1];
    temp_v0_2 = &events->parameters[var_a0];
    pair = *temp_v0_2;
    sound = desc->events->sounds[temp_a1];
    if (temp_a2 != 0xFFFF) {
        func_80265E10_de(particle, particle, temp_a2, -1, D_801002B8, pair);
    }
    if (kind != 0xFFFF) {
        if ((particle->desc->flags & 0x10) != 0) {
            position = D_801042C8;
        } else {
            position = particle->inst.velocity;
        }
        rotation = func_80271818_de(&position);
        func_802800C0_de((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)particle,
                      (struct EffectActor *)particle->owner,
                      (s32 *)particle->ownerId,
                      (s32)particle->target, kind,
                      position, *(CQuatern *)&rotation, D_801002B8, 0,
                      -5,
                      (particle->flags & 0x200006) | 1);
    }
    if (sound != 0xFFFF) {
        func_8025DE54_de((s16)sound, D_801002B8, 0, -1);
    }
    particle->flags |= 0x200;
    if ((particle->desc->flags & 0x20000) != 0) {
        func_80284570_de(&D_8011D8D0, particle);
        func_80284434_de(particle);
    }
}

void func_8027C758_de(Shared_Particle *particle) {
    struct IntPair pair;
    struct Shape_typemap_165 rotation;
    CVector3 position;
    s32 temp_a1;
    struct Shared_ParticleEvents *events;
    s32 var_a0;
    s32 temp_a2;
    s32 kind;
    s32 sound;
    struct Shared_ParticleDesc *desc;
    struct IntPair *temp_v0_2;

    if (func_802757E4_de(0) != 0) {
        var_a0 = func_80276088_de(0);
    } else {
        var_a0 = func_80276054_de(0);
    }
    if (var_a0 == 10) {
        var_a0 = 0;
    }
    desc = particle->desc;
    temp_a1 = var_a0;
    events = desc->events;
    kind = events->particles[temp_a1];
    temp_a2 = events->effects[temp_a1];
    temp_v0_2 = &events->parameters[var_a0];
    pair = *temp_v0_2;
    sound = desc->events->sounds[temp_a1];
    if (temp_a2 != 0xFFFF) {
        func_80265E10_de(particle, particle, temp_a2, -1, D_801002A8, pair);
    }
    if (kind != 0xFFFF) {
        if ((particle->desc->flags & 0x10) != 0) {
            position = D_801042C8;
        } else {
            position = particle->inst.velocity;
        }
        rotation = func_80271818_de(&position);
        func_802800C0_de((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)particle,
                      (struct EffectActor *)particle->owner,
                      (s32 *)particle->ownerId,
                      (s32)particle->target, kind,
                      position, *(CQuatern *)&rotation, D_801002A8, 0,
                      -3,
                      (particle->flags & 0x200006) | 1);
    }
    if (sound != 0xFFFF) {
        func_8025DE54_de((s16)sound, D_801002A8, 0, -1);
    }
    func_80271F9C_de(&particle->rotSpeed, &particle->rotSpeed,
                  particle->rotationScale);
    particle->flags |= 0x200;
    if (particle->unk1BA == 1) {
        func_80284570_de(&D_8011D8D0, particle);
        func_80284434_de(particle);
    }
}

void func_8027C9CC_de(Shared_Particle *particle) {
    struct IntPair pair;
    struct Shape_typemap_165 rotation;
    CVector3 position;
    s32 temp_a1;
    struct Shared_ParticleEvents *events;
    s32 var_a0;
    s32 temp_a2;
    s32 kind;
    s32 sound;
    struct Shared_ParticleDesc *desc;
    struct IntPair *temp_v0_2;

    var_a0 = func_80276088_de(0);
    if (var_a0 == 10) {
        var_a0 = 0;
    }
    desc = particle->desc;
    temp_a1 = var_a0;
    events = desc->events;
    kind = events->particles[temp_a1];
    temp_a2 = events->effects[temp_a1];
    temp_v0_2 = &events->parameters[var_a0];
    pair = *temp_v0_2;
    sound = desc->events->sounds[temp_a1];
    if (temp_a2 != 0xFFFF) {
        func_80265E10_de(particle, particle, temp_a2, -1, D_801002A8, pair);
    }
    if (kind != 0xFFFF) {
        if ((particle->desc->flags & 0x10) != 0) {
            position = D_801042C8;
        } else {
            position = particle->inst.velocity;
        }
        rotation = func_80271818_de(&position);
        func_802800C0_de((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)particle,
                      (struct EffectActor *)particle->owner,
                      (s32 *)particle->ownerId,
                      (s32)particle->target, kind,
                      position, *(CQuatern *)&rotation, D_801002A8, 0,
                      -2,
                      (particle->flags & 0x200006) | 1);
    }
    if (sound != 0xFFFF) {
        func_8025DE54_de((s16)sound, D_801002A8, 0, -1);
    }
    func_80271F9C_de(&particle->rotSpeed, &particle->rotSpeed,
                  particle->rotationScale);
    particle->flags |= 0x200;
    if (particle->unk1BA == 1) {
        func_80284570_de(&D_8011D8D0, particle);
        func_80284434_de(particle);
    }
}

#if defined(VERSION_DE)
#ifdef NON_MATCHING
/* Fuzzy draft: inline-asm carrier of the original instructions (no C written yet). */
void func_8027CC20_de(Shared_Particle *particle) {
    __asm__ volatile (
        ".set noreorder\n"
        ".set noat\n"
        "addiu      $sp, $sp, -0x140\n"
        "sw         $s2, 0x120($sp)\n"
        "addu       $s2, $a0, $zero\n"
        "sw         $s1, 0x11C($sp)\n"
        "addu       $s1, $zero, $zero\n"
        "sw         $s6, 0x130($sp)\n"
        "lui        $s6, %hi(D_801041F0)\n"
        "lw         $s6, %lo(D_801041F0)($s6)\n"
        "addiu      $t0, $zero, 0x1\n"
        "sw         $s7, 0x134($sp)\n"
        "addu       $s7, $s1, $zero\n"
        "sw         $ra, 0x13C($sp)\n"
        "sw         $fp, 0x138($sp)\n"
        "sw         $s5, 0x12C($sp)\n"
        "sw         $s4, 0x128($sp)\n"
        "sw         $s3, 0x124($sp)\n"
        "sw         $s0, 0x118($sp)\n"
        "sw         $t0, 0x10C($sp)\n"
        "sw         $zero, 0x110($sp)\n"
        "lw         $fp, 0x118($s2)\n"
        "jal        func_8024E2C4_de\n"
        "addu      $a0, $s6, $zero\n"
        "beqz       $v0, .Lauto_8027CC8C\n"
        "nop\n"
        "lb         $t1, 0x1B9($s2)\n"
        "j          .Lauto_8027CC94\n"
        "sw        $t1, 0x108($sp)\n"
        ".Lauto_8027CC8C:\n"
        "lb         $t2, 0x1B8($s2)\n"
        "sw         $t2, 0x108($sp)\n"
        ".Lauto_8027CC94:\n"
        "lw         $v0, 0x14($s2)\n"
        "beql       $v0, $zero, .Lauto_8027CCA0\n"
        "sw        $zero, 0x14($s2)\n"
        ".Lauto_8027CCA0:\n"
        "lui        $s0, %hi(D_80100204)\n"
        "addiu      $s0, $s0, %lo(D_80100204)\n"
        "lw         $v1, 0x0($s0)\n"
        "addiu      $v0, $zero, -0x1\n"
        "beq        $v1, $v0, .Lauto_8027CEFC\n"
        "nop\n"
        "jal        func_80216108_de\n"
        "addu      $a0, $s6, $zero\n"
        "addu       $s3, $v0, $zero\n"
        "addiu      $v0, $zero, 0x9\n"
        "beq        $s3, $v0, .Lauto_8027CF08\n"
        "addiu     $v0, $zero, 0xD\n"
        "lhu        $v1, 0x4($s2)\n"
        "lbu        $s3, 0x6A($s0)\n"
        "beql       $v1, $v0, .Lauto_8027CCE0\n"
        "addiu     $s3, $zero, 0x4\n"
        ".Lauto_8027CCE0:\n"
        "lw         $s1, -0x14($s0)\n"
        "lw         $v0, 0x100($s1)\n"
        "lui        $v1, (0x3000000 >> 16)\n"
        "and        $v0, $v0, $v1\n"
        "beqz       $v0, .Lauto_8027CF08\n"
        "addiu     $s5, $s0, -0x14\n"
        "addiu      $s4, $sp, 0x38\n"
        "addu       $a0, $s4, $zero\n"
        "addiu      $t3, $zero, 0x1\n"
        "sw         $t3, 0x110($sp)\n"
        "lw         $a1, 0x0($s0)\n"
        "lw         $v0, 0xB8($s1)\n"
        "sll        $a1, $a1, 6\n"
        "jal        Rsp_ConvertMatrixToFloat\n"
        "addu      $a1, $v0, $a1\n"
        "lw         $v0, 0x100($s1)\n"
        "lui        $v1, (0x1000000 >> 16)\n"
        "and        $v0, $v0, $v1\n"
        "beqz       $v0, .Lauto_8027CD70\n"
        "addu      $a0, $s1, $zero\n"
        "addiu      $a1, $s1, 0x170\n"
        "lw         $a3, 0x8($s5)\n"
        "lw         $v0, 0x0($s0)\n"
        "lw         $t0, 0xD8($s5)\n"
        "lw         $t1, 0xDC($s5)\n"
        "lw         $t2, 0xE0($s5)\n"
        "sw         $t0, 0x18($sp)\n"
        "sw         $t1, 0x1C($sp)\n"
        "sw         $t2, 0x20($sp)\n"
        "sw         $v0, 0x24($sp)\n"
        "lw         $t0, 0xC($s5)\n"
        "lw         $t1, 0x10($s5)\n"
        "sw         $t0, 0x10($sp)\n"
        "sw         $t1, 0x14($sp)\n"
        "jal        func_80247F18_de\n"
        "addu      $a2, $s4, $zero\n"
        ".Lauto_8027CD70:\n"
        "lw         $v0, 0x100($s1)\n"
        "lui        $v1, (0x2000000 >> 16)\n"
        "and        $v0, $v0, $v1\n"
        "beqz       $v0, .Lauto_8027CF08\n"
        "addiu     $v0, $zero, 0x12A\n"
        "lhu        $v1, 0x4($s2)\n"
        "beq        $v1, $v0, .Lauto_8027CD98\n"
        "addiu     $v0, $zero, 0x132\n"
        "bne        $v1, $v0, .Lauto_8027CDC8\n"
        "addiu     $v0, $zero, 0x56\n"
        ".Lauto_8027CD98:\n"
        "lw         $v0, 0x18($s1)\n"
        "lw         $v1, 0x0($v0)\n"
        "addiu      $v0, $zero, 0xB\n"
        "bne        $v1, $v0, .Lauto_8027CDC0\n"
        "nop\n"
        "lw         $v0, 0x13E4($s1)\n"
        "slti       $s7, $v0, 0x1\n"
        "beqz       $s7, .Lauto_8027CDC0\n"
        "addiu     $v0, $v0, 0x1\n"
        "sw         $v0, 0x13E4($s1)\n"
        ".Lauto_8027CDC0:\n"
        "lhu        $v1, 0x4($s2)\n"
        "addiu      $v0, $zero, 0x56\n"
        ".Lauto_8027CDC8:\n"
        "beq        $v1, $v0, .Lauto_8027CE10\n"
        "addiu     $v0, $zero, 0x2\n"
        "beq        $v1, $v0, .Lauto_8027CE10\n"
        "addiu     $v0, $zero, 0x126\n"
        "beq        $v1, $v0, .Lauto_8027CE10\n"
        "addiu     $v0, $zero, 0xF\n"
        "beq        $v1, $v0, .Lauto_8027CE14\n"
        "addiu     $a0, $sp, 0xB8\n"
        "bnez       $s7, .Lauto_8027CE14\n"
        "addiu     $v0, $zero, 0xB\n"
        "bne        $v1, $v0, .Lauto_8027CF0C\n"
        "addiu     $v0, $zero, 0x5\n"
        "lui        $v0, %hi(D_auto_8010026D)\n"
        "lbu        $v0, %lo(D_auto_8010026D)($v0)\n"
        "addiu      $v1, $zero, 0x1\n"
        "andi       $v0, $v0, 0x3\n"
        "bne        $v0, $v1, .Lauto_8027CF0C\n"
        "addiu     $v0, $zero, 0x5\n"
        ".Lauto_8027CE10:\n"
        "addiu      $a0, $sp, 0xB8\n"
        ".Lauto_8027CE14:\n"
        "lui        $s0, %hi(D_801041F0)\n"
        "lw         $s0, %lo(D_801041F0)($s0)\n"
        "jal        func_8026EF58_de\n"
        "addiu     $a1, $sp, 0x38\n"
        "addiu      $a0, $sp, 0xB8\n"
        "lui        $a1, %hi(D_801001F8)\n"
        "addiu      $a1, $a1, %lo(D_801001F8)\n"
        "jal        Particle_TransformPoint\n"
        "addiu     $a2, $s2, 0x50\n"
        "lui        $t3, %hi(D_801042C8)\n"
        "addiu      $t3, $t3, %lo(D_801042C8)\n"
        "lw         $t0, 0x0($t3)\n"
        "lw         $t1, 0x4($t3)\n"
        "lw         $t2, 0x8($t3)\n"
        "sw         $t0, 0xF8($sp)\n"
        "sw         $t1, 0xFC($sp)\n"
        "sw         $t2, 0x100($sp)\n"
        "jal        func_8027207C_de\n"
        "addiu     $a0, $sp, 0xF8\n"
        "addiu      $a0, $sp, 0xB8\n"
        "addiu      $a1, $sp, 0xF8\n"
        "jal        func_80272B38_de\n"
        "addiu     $a2, $s2, 0x1C\n"
        "lw         $v0, 0x5C($s2)\n"
        "lui        $v1, (0x10000 >> 16)\n"
        "or         $v0, $v0, $v1\n"
        "sw         $v0, 0x5C($s2)\n"
        "sw         $s0, 0x134($s2)\n"
        "lui        $v0, %hi(D_80100207)\n"
        "lbu        $v0, %lo(D_80100207)($v0)\n"
        "lhu        $v1, 0x4($s2)\n"
        "sb         $v0, 0x1D1($s2)\n"
        "addiu      $v0, $zero, 0x56\n"
        "bne        $v1, $v0, .Lauto_8027CEB4\n"
        "addiu     $v0, $zero, 0x2\n"
        "bne        $s3, $v0, .Lauto_8027CEB4\n"
        "lui       $v1, (0x4000000 >> 16)\n"
        "lw         $v0, 0x5C($s2)\n"
        "or         $v0, $v0, $v1\n"
        "sw         $v0, 0x5C($s2)\n"
        ".Lauto_8027CEB4:\n"
        "lbu        $v0, 0x1D9($s2)\n"
        "beqz       $v0, .Lauto_8027CED8\n"
        "nop\n"
        "jal        func_80284178_de\n"
        "addu      $a0, $s2, $zero\n"
        "lui        $a0, %hi(D_801379C0)\n"
        "addiu      $a0, $a0, %lo(D_801379C0)\n"
        "jal        func_802A42F4_de\n"
        "addu      $a1, $s2, $zero\n"
        ".Lauto_8027CED8:\n"
        "lw         $a1, 0x138($s2)\n"
        "beqz       $a1, .Lauto_8027CF0C\n"
        "addiu     $v0, $zero, 0x5\n"
        "lui        $a0, %hi(D_8013B1A8)\n"
        "addiu      $a0, $a0, %lo(D_8013B1A8)\n"
        "jal        func_80268C7C_de\n"
        "nop\n"
        "j          .Lauto_8027CF08\n"
        "sw        $zero, 0x138($s2)\n"
        ".Lauto_8027CEFC:\n"
        "jal        func_80216108_de\n"
        "addu      $a0, $s6, $zero\n"
        "addu       $s3, $v0, $zero\n"
        ".Lauto_8027CF08:\n"
        "addiu      $v0, $zero, 0x5\n"
        ".Lauto_8027CF0C:\n"
        "bne        $s3, $v0, .Lauto_8027CF24\n"
        "nop\n"
        "lw         $v0, 0x5C($s2)\n"
        "addiu      $s3, $zero, 0x4\n"
        "ori        $v0, $v0, 0x2\n"
        "sw         $v0, 0x5C($s2)\n"
        ".Lauto_8027CF24:\n"
        "jal        func_80284068_de\n"
        "addu      $a0, $s2, $zero\n"
        "beqz       $v0, .Lauto_8027CF44\n"
        "slti      $v0, $s3, 0x6\n"
        "beqz       $v0, .Lauto_8027CF44\n"
        "slti      $v0, $s3, 0x4\n"
        "beql       $v0, $zero, .Lauto_8027CF44\n"
        "addiu     $s3, $zero, 0x6\n"
        ".Lauto_8027CF44:\n"
        "sll        $a1, $s3, 1\n"
        "lw         $v0, 0x18($fp)\n"
        "sll        $a0, $s3, 3\n"
        "addu       $v1, $v0, $a1\n"
        "addu       $v0, $v0, $a0\n"
        "lhu        $s0, 0x70($v1)\n"
        "lhu        $s7, 0x8C($v1)\n"
        "addiu      $a0, $zero, 0x1\n"
        "lw         $t0, 0x0($v0)\n"
        "lw         $t1, 0x4($v0)\n"
        "sw         $t0, 0x28($sp)\n"
        "sw         $t1, 0x2C($sp)\n"
        "lw         $v0, 0x18($fp)\n"
        "lbu        $v1, 0x0($s6)\n"
        "addu       $v0, $v0, $a1\n"
        "lhu        $s4, 0xA8($v0)\n"
        "bne        $v1, $a0, .Lauto_8027CFCC\n"
        "ori       $v0, $zero, 0xFFFF\n"
        "addu       $s1, $s6, $zero\n"
        "lw         $v0, 0x288($s1)\n"
        "beqz       $v0, .Lauto_8027CFA8\n"
        "addu      $a0, $s1, $zero\n"
        "addiu      $a1, $s1, 0x170\n"
        "jalr       $v0\n"
        "addu      $a2, $s2, $zero\n"
        ".Lauto_8027CFA8:\n"
        "jal        func_8024E140_de\n"
        "addu      $a0, $s1, $zero\n"
        "bnel       $v0, $zero, .Lauto_8027CFB8\n"
        "sw        $zero, 0x10C($sp)\n"
        ".Lauto_8027CFB8:\n"
        "lw         $v0, 0x170($s1)\n"
        "andi       $v0, $v0, 0x2\n"
        "bnel       $v0, $zero, .Lauto_8027CFC8\n"
        "sw        $zero, 0x10C($sp)\n"
        ".Lauto_8027CFC8:\n"
        "ori        $v0, $zero, 0xFFFF\n"
        ".Lauto_8027CFCC:\n"
        "beq        $s7, $v0, .Lauto_8027D078\n"
        "sll       $v0, $s7, 3\n"
        "lui        $at, %hi(D_800CC134)\n"
        "addu       $at, $at, $v0\n"
        "lw         $v0, %lo(D_800CC134)($at)\n"
        "andi       $v0, $v0, 0x4\n"
        "beqz       $v0, .Lauto_8027D018\n"
        "addiu     $v0, $zero, 0x56\n"
        "lhu        $v1, 0x4($s2)\n"
        "bne        $v1, $v0, .Lauto_8027D01C\n"
        "sll       $v0, $s7, 3\n"
        "lh         $v0, 0x2A($sp)\n"
        "lwc1       $f1, 0x1E0($s2)\n"
        "mtc1       $v0, $f0\n"
        "cvt.s.w    $f0, $f0\n"
        "mul.s      $f0, $f0, $f1\n"
        "trunc.w.s  $f2, $f0\n"
        "mfc1       $v0, $f2\n"
        "sh         $v0, 0x2A($sp)\n"
        ".Lauto_8027D018:\n"
        "sll        $v0, $s7, 3\n"
        ".Lauto_8027D01C:\n"
        "lui        $at, %hi(D_800CC134)\n"
        "addu       $at, $at, $v0\n"
        "lw         $v0, %lo(D_800CC134)($at)\n"
        "andi       $v0, $v0, 0x2\n"
        "beqz       $v0, .Lauto_8027D038\n"
        "addu      $a0, $s6, $zero\n"
        "addu       $a0, $s2, $zero\n"
        ".Lauto_8027D038:\n"
        "addu       $a1, $s2, $zero\n"
        "addu       $a2, $s7, $zero\n"
        "lui        $t3, %hi(D_801001F8)\n"
        "addiu      $t3, $t3, %lo(D_801001F8)\n"
        "lw         $t0, 0x0($t3)\n"
        "lw         $t1, 0x4($t3)\n"
        "lw         $t2, 0x8($t3)\n"
        "sw         $t0, 0x10($sp)\n"
        "sw         $t1, 0x14($sp)\n"
        "sw         $t2, 0x18($sp)\n"
        "lw         $t0, 0x28($sp)\n"
        "lw         $t1, 0x2C($sp)\n"
        "sw         $t0, 0x1C($sp)\n"
        "sw         $t1, 0x20($sp)\n"
        "jal        func_80265E10_de\n"
        "addiu     $a3, $zero, -0x1\n"
        ".Lauto_8027D078:\n"
        "addiu      $v0, $zero, 0x4\n"
        "beq        $s3, $v0, .Lauto_8027D140\n"
        "ori       $s5, $zero, 0xFFFF\n"
        "lui        $v0, %hi(D_801462E5)\n"
        "lbu        $v0, %lo(D_801462E5)($v0)\n"
        "beqz       $v0, .Lauto_8027D0B4\n"
        "addiu     $a0, $zero, 0x1\n"
        "lw         $v0, 0x18($s6)\n"
        "lb         $v1, 0x1B9($s2)\n"
        "lw         $v0, 0x0($v0)\n"
        "lw         $t0, 0x108($sp)\n"
        "xori       $v0, $v0, 0xB\n"
        "bne        $t0, $v1, .Lauto_8027D0B4\n"
        "sltu      $a0, $zero, $v0\n"
        "addu       $a0, $zero, $zero\n"
        ".Lauto_8027D0B4:\n"
        "beqz       $a0, .Lauto_8027D13C\n"
        "ori       $v0, $zero, 0xFFFF\n"
        "lw         $a0, 0x18($fp)\n"
        "lhu        $a2, 0x94($a0)\n"
        "beq        $a2, $v0, .Lauto_8027D13C\n"
        "sll       $v0, $a2, 3\n"
        "lui        $at, %hi(D_800CC134)\n"
        "addu       $at, $at, $v0\n"
        "lw         $v1, %lo(D_800CC134)($at)\n"
        "lw         $t1, 0x20($a0)\n"
        "lw         $t2, 0x24($a0)\n"
        "sw         $t1, 0x30($sp)\n"
        "sw         $t2, 0x34($sp)\n"
        "andi       $v0, $v1, 0x4\n"
        "beqz       $v0, .Lauto_8027D13C\n"
        "andi      $v0, $v1, 0x2\n"
        "beqz       $v0, .Lauto_8027D100\n"
        "addu      $a0, $s6, $zero\n"
        "addu       $a0, $s2, $zero\n"
        ".Lauto_8027D100:\n"
        "addu       $a1, $s2, $zero\n"
        "lui        $t0, %hi(D_801001F8)\n"
        "addiu      $t0, $t0, %lo(D_801001F8)\n"
        "lw         $t1, 0x0($t0)\n"
        "lw         $t2, 0x4($t0)\n"
        "lw         $t3, 0x8($t0)\n"
        "sw         $t1, 0x10($sp)\n"
        "sw         $t2, 0x14($sp)\n"
        "sw         $t3, 0x18($sp)\n"
        "lw         $t1, 0x30($sp)\n"
        "lw         $t2, 0x34($sp)\n"
        "sw         $t1, 0x1C($sp)\n"
        "sw         $t2, 0x20($sp)\n"
        "jal        func_80265E10_de\n"
        "addiu     $a3, $zero, -0x1\n"
        ".Lauto_8027D13C:\n"
        "ori        $s5, $zero, 0xFFFF\n"
        ".Lauto_8027D140:\n"
        "beq        $s0, $s5, .Lauto_8027D158\n"
        "addu      $a0, $s2, $zero\n"
        "addu       $a1, $s0, $zero\n"
        "lw         $a3, 0x10C($sp)\n"
        "jal        func_80279B40_de\n"
        "addiu     $a2, $zero, -0x8\n"
        ".Lauto_8027D158:\n"
        "beq        $s4, $s5, .Lauto_8027D260\n"
        "addiu     $v0, $zero, 0x129\n"
        "lhu        $v1, 0x4($s2)\n"
        "beq        $v1, $v0, .Lauto_8027D190\n"
        "sll       $a0, $s4, 16\n"
        "lui        $v0, %hi(D_801001F8)\n"
        "addiu      $v0, $v0, %lo(D_801001F8)\n"
        "lw         $a1, 0x0($v0)\n"
        "lw         $a2, 0x4($v0)\n"
        "lw         $a3, 0x8($v0)\n"
        "sra        $a0, $a0, 16\n"
        "sw         $zero, 0x10($sp)\n"
        "j          .Lauto_8027D258\n"
        "sw        $s2, 0x14($sp)\n"
        ".Lauto_8027D190:\n"
        "lw         $s0, 0x118($s2)\n"
        "jal        func_80284068_de\n"
        "addu      $a0, $s2, $zero\n"
        "beqz       $v0, .Lauto_8027D1A8\n"
        "addiu     $a0, $zero, 0xA\n"
        "addiu      $a0, $zero, 0xC\n"
        ".Lauto_8027D1A8:\n"
        "sll        $a1, $a0, 1\n"
        "lw         $v0, 0x18($s0)\n"
        "sll        $a0, $a0, 3\n"
        "addu       $v1, $v0, $a1\n"
        "lhu        $s4, 0x70($v1)\n"
        "lhu        $a2, 0x8C($v1)\n"
        "addu       $v0, $v0, $a0\n"
        "lw         $t1, 0x0($v0)\n"
        "lw         $t2, 0x4($v0)\n"
        "sw         $t1, 0x78($sp)\n"
        "sw         $t2, 0x7C($sp)\n"
        "lw         $v0, 0x18($s0)\n"
        "addu       $v0, $v0, $a1\n"
        "lhu        $s0, 0xA8($v0)\n"
        "beq        $a2, $s5, .Lauto_8027D21C\n"
        "addu      $a0, $s2, $zero\n"
        "addu       $a1, $s2, $zero\n"
        "lw         $t1, 0x8($s2)\n"
        "lw         $t2, 0xC($s2)\n"
        "lw         $t3, 0x10($s2)\n"
        "sw         $t1, 0x10($sp)\n"
        "sw         $t2, 0x14($sp)\n"
        "sw         $t3, 0x18($sp)\n"
        "lw         $t1, 0x78($sp)\n"
        "lw         $t2, 0x7C($sp)\n"
        "sw         $t1, 0x1C($sp)\n"
        "sw         $t2, 0x20($sp)\n"
        "jal        func_80265E10_de\n"
        "addiu     $a3, $zero, -0x1\n"
        ".Lauto_8027D21C:\n"
        "beq        $s4, $s5, .Lauto_8027D234\n"
        "addu      $a0, $s2, $zero\n"
        "addu       $a1, $s4, $zero\n"
        "lb         $a2, 0x1D0($s2)\n"
        "jal        func_80279B40_de\n"
        "addiu     $a3, $zero, 0x1\n"
        ".Lauto_8027D234:\n"
        "beq        $s0, $s5, .Lauto_8027D260\n"
        "addiu     $v0, $zero, -0x1\n"
        "sll        $a0, $s0, 16\n"
        "sw         $zero, 0x10($sp)\n"
        "sw         $v0, 0x14($sp)\n"
        "lw         $a1, 0x8($s2)\n"
        "lw         $a2, 0xC($s2)\n"
        "lw         $a3, 0x10($s2)\n"
        "sra        $a0, $a0, 16\n"
        ".Lauto_8027D258:\n"
        "jal        func_8025DE54_de\n"
        "nop\n"
        ".Lauto_8027D260:\n"
        "lw         $v0, 0x5C($s2)\n"
        "lui        $v1, (0x30000 >> 16)\n"
        "and        $v0, $v0, $v1\n"
        "bnez       $v0, .Lauto_8027D478\n"
        "addiu     $v0, $zero, 0x3EF\n"
        "lhu        $v1, 0x4($s2)\n"
        "bne        $v1, $v0, .Lauto_8027D430\n"
        "nop\n"
        "lui        $a0, %hi(D_8012D538_de)\n"
        "lw         $a0, %lo(D_8012D538_de)($a0)\n"
        "beqz       $a0, .Lauto_8027D430\n"
        "nop\n"
        "lw         $v0, 0xB8($s1)\n"
        "beqz       $v0, .Lauto_8027D430\n"
        "addiu     $v0, $zero, 0x41E\n"
        "lhu        $v1, 0x4($a0)\n"
        "bne        $v1, $v0, .Lauto_8027D430\n"
        "addiu     $v0, $zero, 0x9\n"
        "beq        $s3, $v0, .Lauto_8027D430\n"
        "nop\n"
        "lui        $v0, %hi(D_80103FCC)\n"
        "lw         $v0, %lo(D_80103FCC)($v0)\n"
        "lw         $t1, 0xF0($v0)\n"
        "lw         $t2, 0xF4($v0)\n"
        "lw         $t3, 0xF8($v0)\n"
        "sw         $t1, 0x180($a0)\n"
        "sw         $t2, 0x184($a0)\n"
        "sw         $t3, 0x188($a0)\n"
        "lw         $t1, 0x110($sp)\n"
        "bnez       $t1, .Lauto_8027D2FC\n"
        "addiu     $s0, $sp, 0x38\n"
        "addiu      $a0, $sp, 0x38\n"
        "lui        $a1, %hi(D_80100204)\n"
        "lw         $a1, %lo(D_80100204)($a1)\n"
        "lw         $v0, 0xB8($s1)\n"
        "sll        $a1, $a1, 6\n"
        "jal        Rsp_ConvertMatrixToFloat\n"
        "addu      $a1, $v0, $a1\n"
        "addiu      $s0, $sp, 0x38\n"
        ".Lauto_8027D2FC:\n"
        "lui        $a1, (0x40490FDC >> 16)\n"
        "ori        $a1, $a1, (0x40490FDC & 0xFFFF)\n"
        "jal        func_802737F0_de\n"
        "addu      $a0, $s0, $zero\n"
        "lui        $v0, %hi(D_80103FCC)\n"
        "lw         $v0, %lo(D_80103FCC)($v0)\n"
        "lw         $v1, 0x0($v0)\n"
        "lbu        $s4, 0x0($v1)\n"
        "addiu      $v0, $zero, 0x1\n"
        "bne        $s4, $v0, .Lauto_8027D430\n"
        "addiu     $s5, $zero, 0x2\n"
        "lw         $v0, 0x18($v1)\n"
        "lw         $v0, 0x0($v0)\n"
        "bne        $v0, $s5, .Lauto_8027D350\n"
        "addu      $a0, $s0, $zero\n"
        "lui        $a1, %hi(D_80100204)\n"
        "lw         $a1, %lo(D_80100204)($a1)\n"
        "lw         $v0, 0xB8($s1)\n"
        "sll        $a1, $a1, 6\n"
        "jal        Rsp_ConvertMatrixToFloat\n"
        "addu      $a1, $v0, $a1\n"
        ".Lauto_8027D350:\n"
        "lui        $v0, %hi(D_80103FCC)\n"
        "lw         $v0, %lo(D_80103FCC)($v0)\n"
        "lw         $a0, 0x0($v0)\n"
        "lbu        $v0, 0x0($a0)\n"
        "bne        $v0, $s4, .Lauto_8027D430\n"
        "lui       $v1, (0x300000 >> 16)\n"
        "lw         $v0, 0x100($a0)\n"
        "and        $v0, $v0, $v1\n"
        "bnez       $v0, .Lauto_8027D388\n"
        "addu      $a1, $s0, $zero\n"
        "lw         $v0, 0x18($a0)\n"
        "lw         $v0, 0x0($v0)\n"
        "bne        $v0, $s5, .Lauto_8027D430\n"
        "nop\n"
        ".Lauto_8027D388:\n"
        "lui        $s1, %hi(D_8012D538_de)\n"
        "lw         $s1, %lo(D_8012D538_de)($s1)\n"
        "lui        $s0, %hi(D_801041F0)\n"
        "lw         $s0, %lo(D_801041F0)($s0)\n"
        "jal        func_8026EF58_de\n"
        "addiu     $a0, $sp, 0xB8\n"
        "addiu      $a0, $sp, 0xB8\n"
        "lui        $a1, %hi(D_801001F8)\n"
        "addiu      $a1, $a1, %lo(D_801001F8)\n"
        "jal        Particle_TransformPoint\n"
        "addiu     $a2, $s1, 0x50\n"
        "lui        $t1, %hi(D_801042C8)\n"
        "addiu      $t1, $t1, %lo(D_801042C8)\n"
        "lw         $t2, 0x0($t1)\n"
        "lw         $t3, 0x4($t1)\n"
        "lw         $t0, 0x8($t1)\n"
        "sw         $t2, 0xF8($sp)\n"
        "sw         $t3, 0xFC($sp)\n"
        "sw         $t0, 0x100($sp)\n"
        "jal        func_8027207C_de\n"
        "addiu     $a0, $sp, 0xF8\n"
        "addiu      $a0, $sp, 0xB8\n"
        "addiu      $a1, $sp, 0xF8\n"
        "jal        func_80272B38_de\n"
        "addiu     $a2, $s1, 0x1C\n"
        "lw         $v0, 0x5C($s1)\n"
        "lui        $v1, (0x10000 >> 16)\n"
        "sw         $s0, 0x134($s1)\n"
        "or         $v0, $v0, $v1\n"
        "sw         $v0, 0x5C($s1)\n"
        "lui        $v0, %hi(D_80100207)\n"
        "lbu        $v0, %lo(D_80100207)($v0)\n"
        "lhu        $v1, 0x4($s1)\n"
        "sb         $v0, 0x1D1($s1)\n"
        "addiu      $v0, $zero, 0x56\n"
        "bne        $v1, $v0, .Lauto_8027D430\n"
        "nop\n"
        "bne        $s3, $s5, .Lauto_8027D430\n"
        "lui       $v1, (0x4000000 >> 16)\n"
        "lw         $v0, 0x5C($s1)\n"
        "or         $v0, $v0, $v1\n"
        "sw         $v0, 0x5C($s1)\n"
        ".Lauto_8027D430:\n"
        "lw         $t2, 0x108($sp)\n"
        "addiu      $v0, $zero, 0x1\n"
        "beq        $t2, $v0, .Lauto_8027D460\n"
        "ori       $v0, $zero, 0xFFFF\n"
        "beq        $s7, $v0, .Lauto_8027D478\n"
        "sll       $v0, $s7, 3\n"
        "lui        $at, %hi(D_800CC134)\n"
        "addu       $at, $at, $v0\n"
        "lw         $v0, %lo(D_800CC134)($at)\n"
        "andi       $v0, $v0, 0x1\n"
        "beqz       $v0, .Lauto_8027D478\n"
        "nop\n"
        ".Lauto_8027D460:\n"
        "lui        $a0, %hi(D_8011D8D0)\n"
        "addiu      $a0, $a0, %lo(D_8011D8D0)\n"
        "jal        func_80284570_de\n"
        "addu      $a1, $s2, $zero\n"
        "jal        func_80284434_de\n"
        "addu      $a0, $s2, $zero\n"
        ".Lauto_8027D478:\n"
        "lw         $ra, 0x13C($sp)\n"
        "lw         $fp, 0x138($sp)\n"
        "lw         $s7, 0x134($sp)\n"
        "lw         $s6, 0x130($sp)\n"
        "lw         $s5, 0x12C($sp)\n"
        "lw         $s4, 0x128($sp)\n"
        "lw         $s3, 0x124($sp)\n"
        "lw         $s2, 0x120($sp)\n"
        "lw         $s1, 0x11C($sp)\n"
        "lw         $s0, 0x118($sp)\n"
        "jr         $ra\n"
        "addiu     $sp, $sp, 0x140\n"
    );
}
#else
INCLUDE_ASM("span_1000", func_8027CC20_de);
#endif
#endif

typedef struct ImpactContext { CVector3 position; char padC[0xE8 - 0xC]; CVector3 normal; } ImpactContext;
extern ImpactContext D_801001F8;
extern u8 D_801462E5;
extern char D_801379C0, D_8013B1A8;
extern s32 func_80216108_de(void *);
extern void func_80284178_de(void *);
extern void func_802A42F4_de(void *, void *);
extern void func_80279B40_de(void *, s32, s32, s32);
#if !(defined(VERSION_DE))
#include "FX_2/PARTICLE_LIFECYCLE.H"
extern LiveParticle *D_8013D538;
extern u8 D_8011026D;

s32 func_8024E2C4_de(void *);
void Rsp_ConvertMatrixToFloat(f32 *, void *);
void func_80247F18_de(void *, void *, void *, CVector3, CVector3, s32);
void func_8026EF58_de(f32 *, f32 *);
void func_80272B38_de(f32 *, CVector3 *, CVector3 *);
s32 func_8024E140_de(void *);
void func_802737F0_de(f32 *, f32);
static __inline__ void attachParticle(Shared_Particle *particle, f32 *transform, s32 action) {
    f32 localTransform[16];
    f32 inverse[16];
    CVector3 direction;
    Shared_ParticleTarget *attached;
    ParticleAttachmentState *scene;
    attached=D_801041F0.current;
    if (transform) func_8026EF58_de(inverse, transform);
    else {
        Rsp_ConvertMatrixToFloat(localTransform, &attached->drawMatrices[D_801041F0.frame]);
        func_8026EF58_de(inverse, localTransform);
    }
    scene=&D_801041F0;
    Particle_TransformPoint(inverse, &scene->origin, &particle->attachmentPosition);
    direction=scene->direction;
    func_8027207C_de(&direction);
    func_80272B38_de(inverse, &direction, &particle->inst.velocity);
    particle->flags|=0x10000;
    particle->target=attached;
    particle->shake=D_801041F0.frame;
    if (particle->inst.type==0x56 && action==2) particle->flags|=0x4000000;
}
void Particle_HitTarget(void *particle) {
    LiveParticle *actor = particle;
    ParticleActionPair primary, secondary;
    f32 boneMatrix[16];
    s32 handle, mode, enabled, hasMatrix, action, special;
    s32 model, effect, sound, extraEffect; u16 type;
    Shared_ParticleTarget *source, *owner, *hit;
    void *other;
    struct Shared_ParticleEvents *actions;
    struct Shared_ParticleEvents *extraActions;
    struct Shared_ParticleDesc *definition;
    s32 draw;
    owner=0;
    source=D_801041F0.current;
    enabled=1;
    special=0;
    hasMatrix=0;
    definition=actor->particle.desc;
    if (func_8024E2C4_de(source)) mode=actor->particle.unk1B9;
    else mode=actor->particle.mode0;
    if (!actor->particle.inst.unk14) actor->particle.inst.unk14=0;
    if (D_801041F0.frame!=-1) {
        action=func_80216108_de(source);
        if (action!=9) {
            action=D_801041F0.mode;
            if (actor->particle.inst.type==13) action=4;
            owner=D_801041F0.current;
            if (owner->flags&0x3000000) {
                Rsp_ConvertMatrixToFloat(boneMatrix, &owner->bones[D_801041F0.frame]);
                hasMatrix=1;
                if (owner->flags&0x1000000) {
                    func_80247F18_de(owner, &owner->unk170, boneMatrix, D_801041F0.origin, D_801041F0.direction, D_801041F0.frame);
                }
                if (owner->flags&0x2000000) {
                    type=actor->particle.inst.type;
                    if (type==0x12a || type==0x132) {
                        if (*owner->category==11) {
                            special=owner->extraUses<1;
                            if (special) owner->extraUses++;
                        }
                    }
                    if (actor->particle.inst.type==0x56 || actor->particle.inst.type==2 || actor->particle.inst.type==0x126 || actor->particle.inst.type==15 ||
                        special || (actor->particle.inst.type==11 && (D_8011026D&3)==1)) {
                        attachParticle(&actor->particle, boneMatrix, action);
                        if (actor->particle.drawWhenHidden) {
                            func_80284178_de(actor);
                            func_802A42F4_de(&D_801379C0, actor);
                        }
                        handle=actor->particle.handle;
                        if (handle) { func_80268C7C_de(&D_8013B1A8, handle); actor->particle.handle=0; }
                    }
                }
            }
        }
    } else action=func_80216108_de(source);
    if (action==5) { action=4; actor->particle.flags|=2; }
    if (func_80284068_de(actor) && action<6 && action>=4) action=6;
    actions=definition->events;
    model=actions->particles[action]; effect=actions->effects[action];
    primary.words=actions->parameters[action];
    sound=definition->events->sounds[action];
    if (source->kind==1) {
        owner=source;
        if (owner->callback) owner->callback(owner, &owner->unk170, actor);
        if (func_8024E140_de(owner)) enabled=0;
        if (owner->unk170&2) enabled=0;
    }
    if (effect!=0xffff) {
        if (D_800CC130[effect].flags&4) {
            if (actor->particle.inst.type==0x56) primary.control.lower=primary.control.lower*actor->scale;
        }
        other=source;
        if (D_800CC130[effect].flags&2) other=actor;
        func_80265E10_de(other, actor, effect, -1, D_801001F8.position, primary.words);
    }
    if (action!=4) {
        draw=1;
        if (D_801462E5) {
            draw=*source->category!=11;
            if (mode==actor->particle.unk1B9) draw=0;
        }
        if (draw) {
            extraActions=definition->events;
            extraEffect=extraActions->effects[4];
            if (extraEffect!=0xffff) {
                secondary.words=extraActions->parameters[4];
                if (D_800CC130[extraEffect].flags&4) {
                    other=source;
                    if (D_800CC130[extraEffect].flags&2) other=actor;
                    func_80265E10_de(other, actor, extraEffect, -1, D_801001F8.position, secondary.words);
                }
            }
        }
    }
    if (model!=0xffff) func_80279B40_de(actor, model, -8, enabled);
    if (sound!=0xffff) func_8025DE54_de((s16)sound, D_801001F8.position, 0, (s32)actor);
    if (!(actor->particle.flags&0x30000)) {
        if (actor->particle.inst.type==0x3ef && D_8013D538 && owner->bones && D_8013D538->particle.inst.type==0x41e && action!=9) {
            D_8013D538->particle.rot=D_80103FCC->point;
            if (!hasMatrix) Rsp_ConvertMatrixToFloat(boneMatrix, &owner->bones[D_801041F0.frame]);
            func_802737F0_de(boneMatrix, 3.141593f);
            if (D_80103FCC->current->kind==1) {
                if (*D_80103FCC->current->category==2) Rsp_ConvertMatrixToFloat(boneMatrix, &owner->bones[D_801041F0.frame]);
                hit=D_80103FCC->current;
                if (hit->kind==1 && (hit->flags&0x300000 || *hit->category==2)) {
                    attachParticle(&D_8013D538->particle, boneMatrix, action);
                }
            }
        }
        if (mode==1 || (effect!=0xffff && D_800CC130[effect].flags&1)) {
            func_80284570_de(&D_8011D8D0, actor);
            func_80284434_de(actor);
        }
    }
}
#endif

extern u32 D_801002F0;
extern void func_802A5BE4_de(void *, CVector3, CVector3, s32, s32);
extern void func_8022B064_de(void *, CVector3 *);
extern void func_80271F34_de(CVector3 *, CVector3 *, CVector3 *);

/* Reacts to a particle striking the current attachment target. The target picks the impact slot (slot 5 becomes slot 4
 * and sets flag 2). Under the controlled-impact mode (D_801462E5) descriptor slot 12 or 10 fires its event, particle
 * and sound at the particle. Otherwise slots 0, 2 and 3 leave a mark when the descriptor has flag 0x800000; a particle
 * whose response byte is 8 is handed to a kind 1 owner (flag 0x20000) or expires; types 0x56, 0x126, 0xCD and 0xF move
 * to the impact point and release their swooshes and light; then the particle is pushed off the surface along the hit
 * normal and the slot's event, particle and sound fire at the impact point (event table flag 2 makes the particle, not
 * the target, the event source). The particle is removed when its response byte is 1 and flags 0x30000 are clear. */
void Particle_ApplyImpactResponse(Shared_Particle *particle) {
    struct Shared_ParticleDesc *desc, *controlledDesc;
    Shared_ParticleTarget *target;
    void *eventSource;
    s32 hit;
    s32 event;
    u32 particleType, eventType, soundType;
    u32 model, sound, effect;
    struct IntPair params;
    CVector3 normal;
    struct IntPair controlledParams;
    Shared_ParticleOwner *owner;

    target = D_801041F0.current;
    desc = particle->desc;
    hit = func_80216108_de(target);
    if (hit == 5) {
        hit = 4;
        particle->flags |= 2;
    }
    if (D_801462E5 && func_80284068_de(particle)) {
        controlledDesc = particle->desc;
        event = func_80284068_de(particle) ? 12 : 10;
        particleType = controlledDesc->events->particles[event];
        eventType = controlledDesc->events->effects[event];
        controlledParams = controlledDesc->events->parameters[event];
        soundType = controlledDesc->events->sounds[event];
        if (eventType != 0xFFFF) {
            func_80265E10_de(particle, particle, eventType, -1, particle->inst.pos, controlledParams);
        }
        if (particleType != 0xFFFF) {
            func_80279B40_de(particle, particleType, particle->space, 1);
        }
        if (soundType != 0xFFFF) {
            func_8025DE54_de(soundType, particle->inst.pos, 0, -1);
        }
    } else {
        switch (hit) {
        case 0:
        case 2:
        case 3:
            if (desc->flags & 0x800000) {
                func_802A5BE4_de(&D_801379C0, D_801001F8.position, D_801001F8.normal, hit, 0);
            }
            break;
        }
        if (particle->unk1B9 == 8 || particle->unk1BA == 8) {
            if ((D_801002F0 & 0x1000000) && (owner = particle->owner) && owner->kind == 1 && (owner->flags & 0x300000)) {
                particle->flags |= 0x20000;
                particle->inst.pos = D_801001F8.position;
                particle->inst.velocity = D_801042C8;
                func_8022B064_de(particle->owner->state, &particle->inst.pos);
            } else {
                particle->life = 1;
            }
        }
        if (particle->inst.type == 0x56 || particle->inst.type == 0x126 || particle->inst.type == 0xCD ||
            particle->inst.type == 0xF) {
            particle->flags |= 0x20000;
            particle->inst.pos = D_801001F8.position;
            particle->inst.velocity = D_801042C8;
            if (particle->drawWhenHidden) {
                func_80284178_de(particle);
                func_802A42F4_de(&D_801379C0, particle);
            }
            if (particle->handle) {
                func_80268C7C_de(&D_8013B1A8, particle->handle);
                particle->handle = 0;
            }
        }
        normal = D_801001F8.normal;
        func_8027207C_de(&normal.x);
        func_80271F9C_de(&normal, &normal, 1.024f);
        func_80271F34_de(&particle->inst.pos, &particle->inst.pos, &normal);
        model = desc->events->particles[hit];
        effect = desc->events->effects[hit];
        params = desc->events->parameters[hit];
        sound = desc->events->sounds[hit];
        if (effect != 0xFFFF) {
            eventSource = target;
            if (D_800CC130[effect].flags & 2) {
                eventSource = particle;
            }
            func_80265E10_de(eventSource, particle, effect, -1, D_801001F8.position, params);
        }
        if (model != 0xFFFF) {
            func_80279B40_de(particle, model, -8, 1);
        }
        if (sound != 0xFFFF) {
            func_8025DE54_de(sound, D_801001F8.position, 0, (s32)particle);
        }
        if (particle->flags & 0x30000) {
            return;
        }
        if (particle->unk1B9 != 1) {
            return;
        }
    }
    func_80284570_de(&D_8011D8D0, particle);
    func_80284434_de(particle);
}
