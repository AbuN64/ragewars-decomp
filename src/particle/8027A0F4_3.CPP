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

void func_8027D4A8_de(void *particle);

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
extern void func_80271818_de(struct Shape_typemap_165 *, CVector3 *);

extern s32 func_802800C0_de(void *, void *, void *, s32, s32, s32,
                         CVector3, struct Shape_typemap_165, CVector3, s32, s32, s32);

extern s32 func_8025DE54_de(s16, CVector3, s32, s32);

extern void func_80271F9C_de(CVector3 *, CVector3 *, f32);
extern void func_80284570_de(void *, void *);
/* Picks an animation slot from a global mode, then plays the slot's effect, spawns its object at the owner or a fixed position, plays its sound, and flags the owner. Adapted from func_8027C9CC_de, with the slot chosen by a switch on D_801042C4 (the extra case below 7 that shares the default body is needed for the decision tree; its value is not recoverable), the constant triple, one argument, the dropped func_80271F9C_de call, and the final test changed. */





extern CVector3 D_801002B8;

extern CVector3 D_801002A8;

extern s32 func_802757E4_de(s32);

extern s32 func_80276054_de(s32);

void func_8027B720_de(Shared_Particle *particle) {
    Box bounds;
    Shared_ParticleOwner *owner;
    Shared_ParticleTarget *target;
    SharedPlayer *player;
    f32 savedStep;
    f32 extent;
    f32 scaled; /* FAKEMATCH: one temporary holds the larger scaled size and then the box height; separate locals let local-alloc tie the constants to the products and pick other FPRs. */
    f32 half; /* FAKEMATCH: the box half-size temporary is reused for the fade below for the same reason. */
    f32 step;
    f32 grow;
    f32 range;
    s32 die;
    s32 bounce;
    s32 done;
    s8 fade;
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
    scaled = particle->size.y * extent;
    if (!(particle->size.x * extent <= scaled)) {
        scaled = particle->size.x * extent;
    }
    if (!(scaled <= extent)) {
        extent = scaled;
    }
    scaled = extent * 1.4142135f;
    half = scaled * 0.5f;
    bounds.min.x = particle->inst.pos.x - half;
    bounds.max.x = particle->inst.pos.x + half;
    bounds.min.y = particle->inst.pos.y - half;
    bounds.max.y = particle->inst.pos.y + scaled;
    bounds.min.z = particle->inst.pos.z - half;
    bounds.max.z = particle->inst.pos.z + half;
    if (particle->flags & 0x20000) {
        particle->time = 0.0f;
        particle->life = particle->unk148 * 32.0f;
        half = particle->shake - D_800D2988 * 6.0f;
        fade = (half < 0.0f) ? 0 : (s32)half;
        particle->shake = fade;
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
        step = D_800D2988 * 10.24f;
        particle->size.x += step * particle->growth.x;
        particle->size.y += step * particle->growth.y;
        particle->size.z += D_800D2988 * particle->growth.z;
        particle->size.x = (particle->size.x > 4096.0f) ? 4096.0f : particle->size.x;
        particle->size.y = (particle->size.y > 4096.0f) ? 4096.0f : particle->size.y;
        particle->size.z = (particle->size.z > 400.0f) ? 400.0f : particle->size.z;
    } else {
        grow = RW_MIN(particle->size.x * particle->growth.x, 4096.0f);
        particle->size.x += (grow - particle->size.x) * D_800D2988;
        grow = RW_MIN(particle->size.y * particle->growth.y, 4096.0f);
        particle->size.y += (grow - particle->size.y) * D_800D2988;
        grow = RW_MIN(particle->size.z * particle->growth.z, 400.0f);
        particle->size.z += (grow - particle->size.z) * D_800D2988;
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
    range = particle->desc->unk10;
    if (!(range <= 0.0f)) {
        range *= 10.24f;
        range *= range;
        for (player = D_80145060; player != NULL;) {
            done = 0;
            if (func_8027B790_distance(particle, player) < range) {
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
                        func_8027D4A8_de(particle);
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

void func_8027C274_de(Shared_Particle *arg0) {
    struct IntPair pair;
    struct Shape_typemap_165 rotation;
    CVector3 position;
    s32 temp_a1;
    struct Shared_ParticleEvents *temp_v0;
    s32 var_a0;
    s32 temp_a2;
    s32 temp_s2;
    s32 sound;
    struct Shared_ParticleDesc *temp_s1;
    struct IntPair *temp_v0_2;

    if ((arg0->flags & 0x400) != 0) {
        if ((arg0->desc->flags & 0x800) != 0) {
            goto skip_effects;
        }
    }
    {
        var_a0 = func_80276088_de(0);
        if (var_a0 == 10) {
            var_a0 = 0;
        }
        temp_s1 = arg0->desc;
        temp_a1 = var_a0;
        temp_v0 = temp_s1->events;
        temp_s2 = temp_v0->particles[temp_a1];
        temp_a2 = temp_v0->effects[temp_a1];
        temp_v0_2 = &temp_v0->parameters[var_a0];
        pair = *temp_v0_2;
        sound = temp_s1->events->sounds[temp_a1];
        if (temp_a2 != 0xFFFF) {
            func_80265E10_de(arg0, arg0, temp_a2, -1, D_80100290, pair);
        }
        if (temp_s2 != 0xFFFF) {
            if ((arg0->desc->flags & 0x10) != 0) {
                position = D_801042C8;
            } else {
                position = arg0->inst.velocity;
            }
            func_80271818_de(&rotation, &position);
            func_802800C0_de(&D_8011D8D0, arg0,
                          arg0->owner,
                          arg0->ownerId,
                          (s32)arg0->target, temp_s2,
                          position, rotation, D_80100290, 0,
                          D_8010029C,
                          (arg0->flags & 0x200006) | 1);
        }
        if (sound != 0xFFFF) {
            func_8025DE54_de((s16)sound, D_80100290, 0, -1);
        }
    }
skip_effects:
    func_80271F9C_de(&arg0->rotSpeed, &arg0->rotSpeed,
                  arg0->rotationScale);
    arg0->flags |= 0x400;
    if (arg0->unk1B9 == 1) {
        func_80284570_de(&D_8011D8D0, arg0);
        func_80284434_de(arg0);
    }
}

void func_8027C4F0_de(Shared_Particle *arg0) {
    struct IntPair pair;
    struct Shape_typemap_165 rotation;
    CVector3 position;
    s32 temp_a1;
    struct Shared_ParticleEvents *temp_v0;
    s32 var_a0;
    s32 temp_a2;
    s32 temp_s2;
    s32 sound;
    struct Shared_ParticleDesc *temp_s1;
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
    temp_s1 = arg0->desc;
    temp_a1 = var_a0;
    temp_v0 = temp_s1->events;
    temp_s2 = temp_v0->particles[temp_a1];
    temp_a2 = temp_v0->effects[temp_a1];
    temp_v0_2 = &temp_v0->parameters[var_a0];
    pair = *temp_v0_2;
    sound = temp_s1->events->sounds[temp_a1];
    if (temp_a2 != 0xFFFF) {
        func_80265E10_de(arg0, arg0, temp_a2, -1, D_801002B8, pair);
    }
    if (temp_s2 != 0xFFFF) {
        if ((arg0->desc->flags & 0x10) != 0) {
            position = D_801042C8;
        } else {
            position = arg0->inst.velocity;
        }
        func_80271818_de(&rotation, &position);
        func_802800C0_de(&D_8011D8D0, arg0,
                      arg0->owner,
                      arg0->ownerId,
                      (s32)arg0->target, temp_s2,
                      position, rotation, D_801002B8, 0,
                      -5,
                      (arg0->flags & 0x200006) | 1);
    }
    if (sound != 0xFFFF) {
        func_8025DE54_de((s16)sound, D_801002B8, 0, -1);
    }
    arg0->flags |= 0x200;
    if ((arg0->desc->flags & 0x20000) != 0) {
        func_80284570_de(&D_8011D8D0, arg0);
        func_80284434_de(arg0);
    }
}

void func_8027C758_de(Shared_Particle *arg0) {
    struct IntPair pair;
    struct Shape_typemap_165 rotation;
    CVector3 position;
    s32 temp_a1;
    struct Shared_ParticleEvents *temp_v0;
    s32 var_a0;
    s32 temp_a2;
    s32 temp_s2;
    s32 sound;
    struct Shared_ParticleDesc *temp_s1;
    struct IntPair *temp_v0_2;

    if (func_802757E4_de(0) != 0) {
        var_a0 = func_80276088_de(0);
    } else {
        var_a0 = func_80276054_de(0);
    }
    if (var_a0 == 10) {
        var_a0 = 0;
    }
    temp_s1 = arg0->desc;
    temp_a1 = var_a0;
    temp_v0 = temp_s1->events;
    temp_s2 = temp_v0->particles[temp_a1];
    temp_a2 = temp_v0->effects[temp_a1];
    temp_v0_2 = &temp_v0->parameters[var_a0];
    pair = *temp_v0_2;
    sound = temp_s1->events->sounds[temp_a1];
    if (temp_a2 != 0xFFFF) {
        func_80265E10_de(arg0, arg0, temp_a2, -1, D_801002A8, pair);
    }
    if (temp_s2 != 0xFFFF) {
        if ((arg0->desc->flags & 0x10) != 0) {
            position = D_801042C8;
        } else {
            position = arg0->inst.velocity;
        }
        func_80271818_de(&rotation, &position);
        func_802800C0_de(&D_8011D8D0, arg0,
                      arg0->owner,
                      arg0->ownerId,
                      (s32)arg0->target, temp_s2,
                      position, rotation, D_801002A8, 0,
                      -3,
                      (arg0->flags & 0x200006) | 1);
    }
    if (sound != 0xFFFF) {
        func_8025DE54_de((s16)sound, D_801002A8, 0, -1);
    }
    func_80271F9C_de(&arg0->rotSpeed, &arg0->rotSpeed,
                  arg0->rotationScale);
    arg0->flags |= 0x200;
    if (arg0->unk1BA == 1) {
        func_80284570_de(&D_8011D8D0, arg0);
        func_80284434_de(arg0);
    }
}

void func_8027C9CC_de(Shared_Particle *arg0) {
    struct IntPair pair;
    struct Shape_typemap_165 rotation;
    CVector3 position;
    s32 temp_a1;
    struct Shared_ParticleEvents *temp_v0;
    s32 var_a0;
    s32 temp_a2;
    s32 temp_s2;
    s32 sound;
    struct Shared_ParticleDesc *temp_s1;
    struct IntPair *temp_v0_2;

    var_a0 = func_80276088_de(0);
    if (var_a0 == 10) {
        var_a0 = 0;
    }
    temp_s1 = arg0->desc;
    temp_a1 = var_a0;
    temp_v0 = temp_s1->events;
    temp_s2 = temp_v0->particles[temp_a1];
    temp_a2 = temp_v0->effects[temp_a1];
    temp_v0_2 = &temp_v0->parameters[var_a0];
    pair = *temp_v0_2;
    sound = temp_s1->events->sounds[temp_a1];
    if (temp_a2 != 0xFFFF) {
        func_80265E10_de(arg0, arg0, temp_a2, -1, D_801002A8, pair);
    }
    if (temp_s2 != 0xFFFF) {
        if ((arg0->desc->flags & 0x10) != 0) {
            position = D_801042C8;
        } else {
            position = arg0->inst.velocity;
        }
        func_80271818_de(&rotation, &position);
        func_802800C0_de(&D_8011D8D0, arg0,
                      arg0->owner,
                      arg0->ownerId,
                      (s32)arg0->target, temp_s2,
                      position, rotation, D_801002A8, 0,
                      -2,
                      (arg0->flags & 0x200006) | 1);
    }
    if (sound != 0xFFFF) {
        func_8025DE54_de((s16)sound, D_801002A8, 0, -1);
    }
    func_80271F9C_de(&arg0->rotSpeed, &arg0->rotSpeed,
                  arg0->rotationScale);
    arg0->flags |= 0x200;
    if (arg0->unk1BA == 1) {
        func_80284570_de(&D_8011D8D0, arg0);
        func_80284434_de(arg0);
    }
}

#if defined(VERSION_DE)
INCLUDE_ASM("span_1000", func_8027CC20_de);
#endif

typedef struct ImpactContext { CVector3 position; char padC[0xE8 - 0xC]; CVector3 normal; } ImpactContext;
typedef struct ImpactKind { u32 flags; s32 unused; } ImpactKind;
extern ImpactContext D_801001F8;
extern ImpactKind D_800CC134[];
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
void func_80270910_de(f32 *, void *);
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
        func_80270910_de(localTransform, &attached->drawMatrices[D_801041F0.frame]);
        func_8026EF58_de(inverse, localTransform);
    }
    scene=&D_801041F0;
    func_80272898_de(inverse, &scene->origin, &particle->attachmentPosition);
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
                func_80270910_de(boneMatrix, &owner->bones[D_801041F0.frame]);
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
        if (D_800CC134[effect].flags&4) {
            if (actor->particle.inst.type==0x56) primary.control.lower=primary.control.lower*actor->scale;
        }
        other=source;
        if (D_800CC134[effect].flags&2) other=actor;
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
                if (D_800CC134[extraEffect].flags&4) {
                    other=source;
                    if (D_800CC134[extraEffect].flags&2) other=actor;
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
            if (!hasMatrix) func_80270910_de(boneMatrix, &owner->bones[D_801041F0.frame]);
            func_802737F0_de(boneMatrix, 3.141593f);
            if (D_80103FCC->current->kind==1) {
                if (*D_80103FCC->current->category==2) func_80270910_de(boneMatrix, &owner->bones[D_801041F0.frame]);
                hit=D_80103FCC->current;
                if (hit->kind==1 && (hit->flags&0x300000 || *hit->category==2)) {
                    attachParticle(&D_8013D538->particle, boneMatrix, action);
                }
            }
        }
        if (mode==1 || (effect!=0xffff && D_800CC134[effect].flags&1)) {
            func_80284570_de(&D_8011D8D0, actor);
            func_80284434_de(actor);
        }
    }
}
#endif

#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
typedef struct ImpactEvents { struct IntPair params[14]; u16 models[14], particles[14], sounds[14]; } ImpactEvents;
typedef struct ImpactDef { u32 flags; char pad4[0x14]; ImpactEvents *events; } ImpactDef;
typedef struct ImpactOwner { u8 kind; char pad1[0xFF]; u32 flags; char pad104[0xD4]; void *state; } ImpactOwner;
typedef struct ImpactParticle {
    char pad0[4]; u16 type; char pad6[2]; CVector3 position;
    char pad14[8]; CVector3 facing;
    char pad28[0x34]; u32 flags; char pad60[0xB8]; ImpactDef *definition;
    char pad11C[0x10]; ImpactOwner *owner; char pad130[8]; void *sound;
    char pad13C[0x10]; s16 dead; char pad14E[0x6B]; s8 state, nextState;
    char pad1BB[0x15]; s8 modelOffset; char pad1D1[8]; u8 active;
} ImpactParticle;
extern CVector3 D_801002E0;
extern u32 D_801002F0;
extern void func_802A5BE4_de(void *, CVector3, CVector3, s32, s32);
extern void func_8022B064_de(void *, CVector3 *);

extern void func_80271F34_de(CVector3 *, CVector3 *, CVector3 *);

void func_8027D4A8_de(void *particleArg) {
    ImpactParticle *particle = particleArg;
    ImpactDef *definition, *controlledDefinition;
    Shared_ParticleTarget *source;
    void *eventSource;
    s32 kind, controlledKind, selection;
    s32 model, sound, effect, halfOffset, paramOffset;
    struct IntPair params;
    CVector3 normal;
    struct IntPair controlledParams;
    ImpactOwner *owner;
    ImpactContext *context;
    CVector3 *normalSource;

    source = D_801041F0.current;
    definition = particle->definition;
    kind = func_80216108_de(source);
    if (kind == 5) {
        kind = 4;
        particle->flags |= 2;
    }
    if (D_801462E5 && func_80284068_de(particle)) {
        controlledDefinition = particle->definition;
        if (func_80284068_de(particle)) controlledKind = 12;
        else controlledKind = 10;
        halfOffset = controlledKind * 2;
        kind = controlledDefinition->events->models[controlledKind];
        effect = controlledDefinition->events->particles[controlledKind];
        controlledParams = controlledDefinition->events->params[controlledKind];
        sound = controlledDefinition->events->sounds[controlledKind];
        if (effect != 0xFFFF) {
            func_80265E10_de(particle, particle, effect, -1, particle->position, controlledParams);
        }
        if (kind != 0xFFFF) {
            func_80279B40_de(particle, kind, particle->modelOffset, 1);
        }
        if (sound != 0xFFFF) {
            func_8025DE54_de((s16)sound, particle->position, 0, -1);
        }
    } else {
        switch (kind) {
        case 0:
        case 2:
        case 3:
            if (definition->flags & 0x800000) {
                context = &D_801001F8;
                func_802A5BE4_de(&D_801379C0, context->position, context->normal, kind, 0);
            }
            break;
        }
        if (particle->state == 8 || particle->nextState == 8) {
            if ((D_801002F0 & 0x1000000) && (owner = particle->owner) && owner->kind == 1 && (owner->flags & 0x300000)) {
                particle->flags |= 0x20000;
                particle->position = D_801001F8.position;
                particle->facing = D_801042C8;
                func_8022B064_de(particle->owner->state, &particle->position);
            } else particle->dead = 1;
        }
        if (particle->type == 0x56 || particle->type == 0x126 || particle->type == 0xCD || particle->type == 0xF) {
            particle->flags |= 0x20000;
            particle->position = D_801001F8.position;
            particle->facing = D_801042C8;
            if (particle->active) {
                func_80284178_de(particle);
                func_802A42F4_de(&D_801379C0, particle);
            }
            if (particle->sound) {
                func_80268C7C_de(&D_8013B1A8, (s32)particle->sound);
                particle->sound = 0;
            }
        }
        normalSource = &D_801002E0;
        normal = *normalSource;
        func_8027207C_de(&normal.x);
        func_80271F9C_de(&normal, &normal, 1.024f);
        func_80271F34_de(&particle->position, &particle->position, &normal);
        selection = kind;
        halfOffset = kind * 2;
        paramOffset = kind * 8;
        kind = definition->events->models[selection];
        effect = definition->events->particles[selection];
        params = definition->events->params[selection];
        sound = definition->events->sounds[selection];
        if (effect != 0xFFFF) {
            eventSource = source;
            if (D_800CC134[effect].flags & 2) eventSource = particle;
            func_80265E10_de(eventSource, particle, effect, -1, D_801001F8.position, params);
        }
        if (kind != 0xFFFF) func_80279B40_de(particle, kind, -8, 1);
        if (sound != 0xFFFF) func_8025DE54_de((s16)sound, D_801001F8.position, 0, (s32)particle);
        if (particle->flags & 0x30000) return;
        if (particle->state != 1) return;
    }
    func_80284570_de(&D_8011D8D0, particle);
    func_80284434_de(particle);
}
#else
INCLUDE_ASM("span_1000", func_8027D4A8_de);
#endif
