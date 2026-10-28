#include "COMMON/TRIPLE.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/S1.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "RSP/8026E1F8_5.H"
#include "SYSTEM/80265370.H"
#include "FX/80271B18.H"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_3.H"
#include "particle/80271B18_3.H"
#include "RENDER/8028FD2C_6.H"
#include "SYSTEM/CONTACT_EFFECT.H"
#include "particle/8027A0F4_4.H"

/* Spawns the effects that template block 2 of the system lists for a kind: for each template in the kind's range it filters by player mask, existing owner effects, anchor distance, mode, team flags and a percent chance, builds a spawn matrix (source matrix, mirror, translation or rotation), then for a random count allocates effects, fills their timing, spread, colour, render and direction fields from the template's packed floats, links them into their group, aims shots at the held target for kinds 0x2D and 0x4F, and plays their sound. Returns the number spawned. */

/* These canonical scalar owners are immutable ROM rodata. */

extern EffectTarget *D_80103FCC;
extern EffectTarget D_801041F0;

extern CVector3 D_801042C8;

extern s32 D_80140FF8;


extern f32 D_800CD6B0;

extern void Graphu64_TransformDirection(MatrixF *, CVector3 *, CVector3 *);
extern void Graphu64_IdentityMatrix(MatrixF *);
extern CQuatern Gobjinst_BuildTargetAimOrientation(EffectActor *, CVector3);
extern void BuildDirectionMatrix(MatrixF *, CVector3 *);
extern void Graphu64_ConvertMatrixToFloat(MatrixF *, PackedMatrixWords *);
extern void ScaleMatrixLocal(MatrixF *, f32, f32, f32);
extern void TranslateMatrix(MatrixF *, f32, f32, f32);
extern void Particle_Release(EffectSystem *, ParticleEffect *);
extern void func_80255D70_de(IntrusiveList *, ParticleEffect *, ParticleEffect *);
extern void Textload_LocateTextureResource(u32 *, s32);
extern void GameObject_ResetActorMotion(ParticleEffect *);
extern f32 Rumble_SamplePackedFloatRange(CharacterScreenCell);

#if defined(VERSION_EU)
#include "COMMON.H"
#else
#endif

extern void func_8022B040_de(s32, ParticleEffect *);
extern void Fx_AttachActorRibbon(void *, ParticleEffect *, s32);
extern s32 Gdynlight_AllocateWorldLight(void *, s32);
extern void Particle_PlayAttachedSound(ParticleEffect *, s32);
extern void SoundElement_PlaySoundAtPosition(s16, CVector3, s32, s32);
extern void Gregion_ShiftColorHue(s8, u8, u8, u8, u8 *, u8 *, u8 *);

extern void Gregion_DarkenColor(u8, u8, u8, u8, u8 *, u8 *, u8 *);

static inline s32 effect_spawn_random_count(s32 range) {
    return range != 0 ? Graphu64_NextRandom() % (range + 1) : 0;
}

static inline ParticleEffect *effect_spawn_find_owned(IntrusiveList *list, void *ownerId, EffectEntry *entry) {
    ParticleEffect *effect;

    effect = list->head;
    if (entry != 0) {
        for (; effect != 0; effect = effect->next) {
            if (effect->ownerId == ownerId && effect->entry == entry) {
                return effect;
            }
        }
    } else {
        for (; effect != 0; effect = effect->next) {
            if (effect->ownerId == ownerId) {
                return effect;
            }
        }
    }
    return 0;
}

static inline ParticleEffect *effect_spawn_allocate(EffectSystem *sys, u8 index) {
    ParticleEffect *effect;
    IntrusiveList *list;
    s32 i;

    if (sys->free.head == 0) {
        for (i = 0; i <= index; i++) {
            if ((&sys->lists[i])->tail != 0) {
                Particle_Release(sys, (&sys->lists[i])->tail);
                break;
            }
        }
    }
    effect = sys->free.head;
    if (effect == 0) {
        return 0;
    }
    func_80255ED8_de(&sys->free, effect);
    list = &sys->lists[index];
    func_80255CB8_de(list, effect);
    effect->list = list;
    effect->groupNext = 0;
    effect->unk1F0 = 0;
    effect->flags = 0x100;
    return effect;
}

static inline void effect_spawn_aim(ParticleEffect *effect, EffectTarget *aimTarget, CVector3 *vel, s32 sourceType) {
    MatrixF targetMtx;
    MatrixF targetInv;
    CVector3 up;
    EffectActor *targetActor;
    s32 targetTeam;

    if (aimTarget->matrixIndex != -1) {
        effect->mode = -4;
        targetActor = D_801041F0.actor;
        targetTeam = aimTarget->victimTeam;
        Graphu64_ConvertMatrixToFloat(&targetMtx, &targetActor->u60.link.matrixArray[D_801041F0.matrixIndex]);
        Graphu64_InvertAffineMatrix(targetInv.m[0], targetMtx.m[0]);
        Graphu64_TransformPoint(&targetInv, &aimTarget->pos, &effect->startPosition);
        up = D_801042C8;
        Graphu64_NormalizeVec3(&up.x);
        Graphu64_TransformDirection(&targetInv, &up, vel);
        effect->followedActor = (s32) targetActor;
        effect->flags |= 0x10000;
        effect->boundMatrixIndex = D_801041F0.matrixIndex;
        if (effect->kind == 0x56 && targetTeam == sourceType) {
            effect->flags |= 0x4000000;
        }
    }
}

s32 Particle_SpawnEffectGroup(EffectSystem *sys, EffectActor *source, EffectActor *owner, s32 *refCount, s32 followTarget, s32 kind,
                  CVector3 inheritedVelocity, CQuatern rotation, CVector3 pos, CVector3 *aim, s32 requestedMode, s32 spawnFlags) {
    MatrixF mtx;
    CVector3 dir;
    CVector3 dirOut;
    CVector3 offset;
    CVector3 offsetOut;
    CVector3 delta;
    CQuatern quat;
    EffectTarget target;
    CVector3 aimDelta;
    s32 first;
    s32 last;
    u8 h, sv, v;
    u8 r, g, b;
    u8 r0, g0, b0;
    u8 r1, g1, b1;
    s32 count;
    s32 j;
    s32 n;
    s32 mode;
    s32 i;
    EffectActor *anchor;
    void *ownerId;
    s32 extra;
    s32 life;
    s32 layer;
    s32 ok;
    s32 hue;
    u8 sat;
    u8 val;
    s32 spread;
    u32 *bits;
    u8 mask;
    s32 resource;
    EffectBlock *block;
    s32 numEntries;
    EffectEntry *entries;
    EffectEntry *entry;
    ParticleEffect *effect;
    CCollisionInfo2_t *render;
    CVector3 *vel;
    EffectTarget *aimTarget;
    GameplayCamera *camera;
    f32 distSq;
    f32 scale;
    f32 depth;
    s32 sourceType;
    s32 sound;

    if (D_80145060.frozen != 0) {
        return 0;
    }
    count = 0;
    resource = sys->resource;
    D_80103FCC = &target;
    sys->last = 0;
    block = SetN64_GetPackSection(resource, 1);
    numEntries = block->count;
    if (Defs_FindSortedGroupRange(block->entries, numEntries, kind, &first, &last) != 0) {
        entries = ((EffectBlock *)SetN64_GetPackSection(resource, 2))->entries;
        anchor = 0;
        if (D_80145060.actorList != 0) {
            anchor = D_80145060.actorList;
        }
        ownerId = 0;
        if (owner != 0) {
            switch (owner->type) {
                case 1:
                case 2:
                    ownerId = owner;
                    break;
                case 0:
                    ownerId = owner->u60.link.owner;
                    owner = 0;
                    break;
            }
        }
        mask = 1;
        if (D_80145088.settings.local != 0) {
            mask = 2;
        }
        for (i = first; i <= last; i++) {
            entry = &entries[i];
            ok = (entry->playerMask & mask) != 0;
            if ((entry->flags & 0x80) && ownerId != 0) {
                if (effect_spawn_find_owned(&sys->lists[entry->params->listIndex], ownerId, entry) != 0) {
                    ok = 0;
                }
            }
            if (anchor != 0) {
                Graphu64_SubtractVectors(&delta, &pos, &anchor->pos);
            } else {
                delta.x = delta.y = delta.z = 0.0f;
            }
            distSq = delta.x * delta.x + delta.y * delta.y + delta.z * delta.z;
            if (entry->flags & 0x400000) {
                if (262144.0f <= distSq) {
                    ok = 0;
                }
            } else if (entry->flags & 0x200000) {
                if (distSq <= 262144.0f) {
                    ok = 0;
                }
            }
            switch (entry->params->unkE) {
                case 6:
                    mode = -7;
                    break;
                case 5:
                    mode = -6;
                    break;
                case 0:
                    mode = -4;
                    break;
                case 1:
                    mode = -5;
                    break;
                default:
                    switch (requestedMode) {
                        case -5:
                        case -3:
                        case -2:
                            mode = requestedMode;
                            break;
                        default:
                            mode = -3;
                            break;
                    }
                    break;
                case 3:
                    if (0.0f <= (f32) requestedMode) {
                        mode = requestedMode;
                    } else {
                        ok = 0;
                        mode = 0;
                    }
                    break;
                case 4:
                    if (source->type == 2 && source->unk1D0 == -8) {
                        requestedMode = -8;
                        D_801002E0 = source->unk174;
                    }
                    mode = requestedMode;
                    break;
            }
            if (entry->flags & 0x2000000) {
                if (D_801462C8.firstListMode == 0 || !(spawnFlags & 1)) {
                    ok = 0;
                }
            }
            if (entry->flags & 0x4000000) {
                if (D_801462C8.firstListMode != 0) {
                    ok = 0;
                }
            }
            if (entry->params->chance != 100) {
                if (Graphu64_NextRandom() % 1000 + 1 > entry->params->chance * 10) {
                    ok = 0;
                }
            }
            if (!ok) {
                continue;
            }
            extra = 0;
            if (entry->flags & 0x8000) {
                switch (source->type) {
                    case 2:
                        if (!(source->flags & 0x100000)) {
                            if (D_80140FF8 == 1) {
                                camera = D_80140FE8_de.camera;
                                Graphu64_TransformPoint(camera->worldToView, &source->pos, &aimDelta);
                                depth = aimDelta.z;
                                if (depth < 0.0f) {
                                    depth = -depth;
                                }
                                Particle_BuildMatrix((Shared_Particle *)source, &source->u60.matrices[D_800D297C], camera, depth);
                            } else {
                                Particle_BuildMatrix((Shared_Particle *)source, &source->u60.matrices[D_800D297C], 0, 0.0f);
                            }
                            source->flags |= 0x100000;
                        }
                        Graphu64_ConvertMatrixToFloat(&mtx, &source->u60.matrices[D_800D297C]);
                        scale = 0.09765625f;
                        if (source->model->unk14 != 0) {
                            scale = 2.857143f;
                        }
                        ScaleMatrixLocal(&mtx, scale, scale, scale);
                        if (source->model->flags & 8) {
                            TranslateMatrix(&mtx, 0.0f, -source->unk154 * source->unk158, 0.0f);
                        }
                        break;
                    case 1:
                        extra = 0x400000;
                        Graphu64_BuildScaleMatrix(&mtx, -1.0f, 1.0f, -1.0f);
                        break;
                    default:
                        Graphu64_BuildTranslationMatrix(&mtx, source->pos.x, source->pos.y, source->pos.z);
                        break;
                }
            } else if (entry->flags & 0x1000000) {
                Graphu64_IdentityMatrix(&mtx);
            } else {
                if (entry->flags & 0x40000) {
                    quat = Gobjinst_BuildTargetAimOrientation(owner, pos);
                } else {
                    quat = rotation;
                }
                MatrixFromQuaternion(&quat.x, &mtx.m[0][0]);
            }
            n = entry->params->countBase + effect_spawn_random_count(entry->params->countRange);
            for (j = 0; j < n; j++) {
                life = entry->params->lifeBase + effect_spawn_random_count(entry->params->lifeRange);
                if (life == 0) {
                    continue;
                }
                effect = effect_spawn_allocate(sys, entry->params->listIndex);
                if (effect == 0) {
                    break;
                }
                count++;
                Textload_LocateTextureResource(&effect->unk11C, entry->unk4);
                GameObject_ResetActorMotion(effect);
                effect->unk110 = 0;
                effect->unk114 = 0;
                effect->kind = kind;
                effect->entry = entry;
                effect->mode = mode;
                if (source->type == 2) {
                    effect->source = source;
                } else {
                    effect->source = 0;
                }
                effect->ownerId = ownerId;
                effect->owner = owner;
                effect->refCount = refCount;
                if (refCount != 0) {
                    (*refCount)++;
                }
                effect->followedActor = followTarget;
                effect->unk13C = 0;
                effect->flags = (effect->flags & ~0xE600) | (spawnFlags | extra);
                bits = &effect->unk11C;
                layer = 0;
                if (effect->entry->flags & 0x2000000) {
                    if (effect->flags & 2) {
                        layer = 2;
                    } else if (D_801462C8.firstListMode == 2) {
                        layer = 1;
                    }
                }
                *bits |= layer << 30;
                effect->unk1D9 = 0;
                spread = entry->params->emitSpread;
                if (spread < 0) {
                    effect->spreadAngle = spread;
                } else {
                    effect->spreadAngle = -(f32) effect_spawn_random_count(spread);
                }
                effect->unk19C[0] = Rumble_SamplePackedFloatRange(entry->unk2C[2]) * D_800C4E04_de;
                effect->unk19C[2] = Rumble_SamplePackedFloatRange(entry->unk2C[1]) * 0.41887906f;
                effect->unk19C[4] = Rumble_SamplePackedFloatRange(entry->unk2C[0]);
                effect->unk19C[1] = Rumble_SamplePackedFloatRange(entry->unk2C[5]) * D_800C4E04_de;
                effect->unk19C[3] = Rumble_SamplePackedFloatRange(entry->unk2C[4]) * 0.41887906f;
                effect->unk19C[5] = Rumble_SamplePackedFloatRange(entry->unk2C[3]);
                if (entry->flags & 2) {
                    effect->unk144 = effect_spawn_random_count(life);
                } else {
                    effect->unk144 = 0.0f;
                }
                effect->unk148 = entry->params->unkB;
                effect->life = life;
                effect->unk14E = 0;
                effect->unk14F = -1;
                if (aim == 0) {
                    dir.x = Rumble_SamplePackedFloatRange(entry->direction[0]);
                    dir.y = Rumble_SamplePackedFloatRange(entry->direction[1]);
                    dir.z = Rumble_SamplePackedFloatRange(entry->direction[2]);
                    Graphu64_NormalizeVec3(&dir.x);
                    if (dir.x != 0.0f || dir.y != 0.0f || dir.z != 0.0f) {
                        Graphu64_TransformPoint(&mtx, &dir, &dirOut);
                    } else {
                        dirOut = dir;
                    }
                    if (mode == -8) {
                        effect->direction = D_801002E0;
                        Graphu64_NormalizeVec3(&effect->direction.x);
                    } else {
                        effect->direction = dirOut;
                    }
                }
                effect->unk150[0] = Rumble_SamplePackedFloatRange(entry->unk24[0]);
                effect->unk150[1] = Rumble_SamplePackedFloatRange(entry->unk24[2]);
                effect->unk150[2] = Rumble_SamplePackedFloatRange(entry->unk24[4]);
                effect->unk150[3] = Rumble_SamplePackedFloatRange(entry->unk24[1]);
                effect->unk150[4] = Rumble_SamplePackedFloatRange(entry->unk24[3]);
                effect->unk150[5] = Rumble_SamplePackedFloatRange(entry->unk24[5]);
                if (entry->unk14 != 0) {
                    effect->unk180[0] = Rumble_SamplePackedFloatRange(entry->unk20[0]);
                    effect->unk180[1] = Rumble_SamplePackedFloatRange(entry->unk20[2]);
                    effect->unk180[2] = Rumble_SamplePackedFloatRange(entry->unk20[4]);
                    effect->unk180[3] = Rumble_SamplePackedFloatRange(entry->unk20[1]);
                    effect->unk180[4] = Rumble_SamplePackedFloatRange(entry->unk20[3]);
                    effect->unk180[5] = Rumble_SamplePackedFloatRange(entry->unk20[5]);
                } else {
                    effect->unk180[0] = Rumble_SamplePackedFloatRange(entry->unk20[0]);
                    effect->unk180[1] = Rumble_SamplePackedFloatRange(entry->unk20[2]);
                    effect->unk180[2] = Rumble_SamplePackedFloatRange(entry->unk20[4]);
                    effect->unk180[3] = Rumble_SamplePackedFloatRange(entry->unk20[1]);
                    effect->unk180[4] = Rumble_SamplePackedFloatRange(entry->unk20[3]);
                    effect->unk180[5] = Rumble_SamplePackedFloatRange(entry->unk20[5]);
                }
                if ((entry->flags & 0x80000) && entry->unk8 == 1) {
                    effect->unk1D8 = 0;
                    effect->alpha = 0.0f;
                } else {
                    effect->unk1D8 = 0xFF;
                    effect->alpha = 255.0f;
                }
                effect->unk14 = 0;
                effect->pos = pos;
                offset.x = Rumble_SamplePackedFloatRange(entry->offset[0]);
                offset.y = Rumble_SamplePackedFloatRange(entry->offset[1]);
                offset.z = Rumble_SamplePackedFloatRange(entry->offset[2]);
                if (offset.x != 0.0f || offset.y != 0.0f || offset.z != 0.0f) {
                    Graphu64_TransformPoint(&mtx, &offset, &offsetOut);
                    if (!(entry->flags & 0x8000)) {
                        Graphu64_AddVec3(&offsetOut, &pos, &offsetOut);
                    }
                    effect->pos = offsetOut;
                }
                if (aim != 0) {
                    Graphu64_SubtractVectors(&aimDelta, aim, &effect->pos);
                    Graphu64_NormalizeVec3(&aimDelta.x);
                    BuildDirectionMatrix(&mtx, &aimDelta);
                    if (mode == -8) {
                        effect->direction = D_801002E0;
                        Graphu64_NormalizeVec3(&effect->direction.x);
                    } else {
                        dir.x = Rumble_SamplePackedFloatRange(entry->direction[0]);
                        dir.y = Rumble_SamplePackedFloatRange(entry->direction[1]);
                        dir.z = Rumble_SamplePackedFloatRange(entry->direction[2]);
                        Graphu64_NormalizeVec3(&dir.x);
                        if (dir.x != 0.0f || dir.y != 0.0f || dir.z != 0.0f) {
                            Graphu64_TransformPoint(&mtx, &dir, &dirOut);
                        } else {
                            dirOut = dir;
                        }
                        effect->direction = dirOut;
                    }
                }
                effect->unk168 = effect->pos;
                effect->startPosition = effect->pos;
                Graphu64_ScaleVector(&effect->velocity, &dirOut, Rumble_SamplePackedFloatRange(entry->motion->speed));
                if (entry->flags & 0x20) {
                    Graphu64_AddVec3(&effect->velocity, &effect->velocity, &inheritedVelocity);
                }
                hue = 0;
                if (entry->color->m_RandomizeHue != 0) {
                    hue = Graphu64_NextRandom() % (entry->color->m_RandomizeHue * 2) - (u8) entry->color->m_RandomizeHue;
                }
                sat = entry->color->m_RandomizeSaturation != 0 ? Graphu64_NextRandom() % entry->color->m_RandomizeSaturation : 0;
                val = entry->color->unkE != 0 ? Graphu64_NextRandom() % entry->color->unkE : 0;
                r = entry->color->m_WhiteColor[0];
                g = entry->color->m_WhiteColor[1];
                b = entry->color->m_WhiteColor[2];
                Gregion_ShiftColorHue(hue, r, g, b, &h, &sv, &v);
                Gregion_DesaturateColor(sat, h, sv, v, &r, &g, &b);
                Gregion_DarkenColor(val, r, g, b, &r0, &g0, &b0);
                r = entry->color->m_BlackColor[0];
                g = entry->color->m_BlackColor[1];
                b = entry->color->m_BlackColor[2];
                Gregion_ShiftColorHue(hue, r, g, b, &h, &sv, &v);
                Gregion_DesaturateColor(sat, h, sv, v, &r, &g, &b);
                Gregion_DarkenColor(val, r, g, b, &r1, &g1, &b1);
                effect->rgb0[0] = r0;
                effect->rgb0[1] = g0;
                effect->rgb0[2] = b0;
                effect->rgb1[0] = r1;
                effect->rgb1[1] = g1;
                effect->rgb1[2] = b1;
                render = &effect->render;
                *render = D_80100090;
                render->WallBehavior = entry->unkA;
                render->InstanceBehavior = entry->unk9;
                render->GroundBehavior = entry->unkB;
                render->GravityAcceleration = Rumble_SamplePackedFloatRange(entry->motion->unk0);
#if defined(VERSION_EU)
                render->BounceReturnEnergy = Menu_ExpandFloatHighWord(entry->motion->unk8);
                render->GroundFriction = Menu_ExpandFloatHighWord(entry->motion->unkA);
                render->AirFriction = Menu_ExpandFloatHighWord(entry->motion->unkC);
                render->WaterFriction = Menu_ExpandFloatHighWord(entry->motion->unkE);
#else
                render->BounceReturnEnergy = Menu_ExpandFloatHighWord(entry->motion->unk8);
                render->GroundFriction = Menu_ExpandFloatHighWord(entry->motion->unkA);
                render->AirFriction = Menu_ExpandFloatHighWord(entry->motion->unkC);
                render->WaterFriction = Menu_ExpandFloatHighWord(entry->motion->unkE);
#endif
                if (render->WallBehavior == 8 || render->GroundBehavior == 8 || render->InstanceBehavior == 8) {
                    if (effect->owner != 0 && effect->owner->type == 1 && (effect->owner->unk100 & 0x300000)) {
                        func_8022B040_de(effect->owner->unk1D8, effect);
                    }
                }
                if (kind == 0x101 || kind == 0x128) {
                    render->dwFlags |= 4;
                }
                if (entry->flags & 0x100000) {
                    render->dwFlags |= 0x40000;
                }
                if (entry->flags & 0x800) {
                    render->dwFlags |= 0x2000;
                }
                if (entry->flags & 0x40000000) {
                    render->dwFlags |= 0x4000;
                }
                if (entry->params->unk5 != 3) {
                    ParticleEffect *other;

                    for (other = sys->groups.head; other != 0; other = other->groupNext) {
                        if (other->entry == effect->entry) {
                            break;
                        }
                    }
                    if (other != 0) {
                        func_80255D70_de(&sys->groups, other, effect);
                    } else if (effect->entry->flags & 0x2000) {
                        func_80255CB8_de(&sys->groups, effect);
                    } else {
                        func_80255D14_de(&sys->groups, effect);
                    }
                    effect->flags |= 0x1000000;
                }
                if ((g_effectCallbackFlags[entry->model->unk94].flags & 1) || kind == 0x68) {
                    render->dwFlags |= 0x20000;
                }
                vel = &effect->velocity;
                Graphu64_ScaleVector(vel, vel, D_800CD6B0);
                if ((kind == 0x2D || kind == 0x4F) && (sourceType = source->type) == 2) {
                    aimTarget = &D_801041F0;
                    if (aimTarget->actor != 0) {
                        effect_spawn_aim(effect, aimTarget, vel, sourceType);
                    }
                }
                effect->unk1E0 = D_800CD6B4;
                Particle_Attach((Shared_Particle *)effect, 0, 0);
                if (entry->unk6 != -1) {
                    Fx_AttachActorRibbon(&D_801379C0, effect, entry->unk6);
                }
                if (entry->unk7 != -1) {
                    effect->unk138 = Gdynlight_AllocateWorldLight(&D_8013B1A8, entry->unk7);
                } else {
                    effect->unk138 = 0;
                }
                if (!(effect->flags & 0x200000) && (sound = entry->sound) != 0) {
                    switch (effect->kind) {
                        case 0x22:
                        case 0x5F:
                        case 0x60:
                            Particle_PlayAttachedSound(effect, sound);
                            break;
                        default:
                            SoundElement_PlaySoundAtPosition(sound, effect->pos, 0, -1);
                            break;
                    }
                }
                sys->last = effect;
            }
        }
    }
    D_80103FCC = &D_801041F0;
    return count;
}
