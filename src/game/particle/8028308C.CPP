#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/OBJECTLINKS1E8.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "FX_2/PARTICLE_ATTACHMENT.H"
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "stddef.h"
#include "TYPES.H"
#include "particle/8028308C.H"
#include "RSP/8026E1F8_5.H"
#include "FX_2/80271B18.H"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_7.H"
#include "particle/80271B18_3.H"
#include "particle/8027A0F4_4.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/MATH_HELPERS.H"
#include "particle/CAMERA_SCALE.H"
extern void Particle_UpdateMatrix(void *);

extern void Particle_FinishActorEffects(void *arg0);

extern void Fx_DetachParticleSwooshes(void *arg0, void *arg1);







extern char D_8011D8D0;

extern void Particle_Release(void *a, void *b);

extern CVector3 D_801042C8;

extern Params D_80100290;


/* Apply resource indices and dispatch the optional object effect. */


 /* extern */
s32 DynLight_AllocateWorldLight(void *, s8);

 /* extern */
void Particle_PlayAttachedSound(void *, s32);

 /* extern */
void Fx_AttachActorRibbon(void *, void *, s8);

/* Adds acceleration along a direction and clamps the resulting speed to its configured limit. */

f32 Math_Sqrtf(f32);

void GraphU64_ScaleVector(CVector3 *,CVector3 *,f32);

 void GraphU64_AddVec3(CVector3 *,CVector3 *,CVector3 *);

/* Transform the measured attachment position and direction into the target frame. */
extern ParticleAttachmentState D_801041F0;

extern void GraphU64_ConvertMatrixToFloat(f32 *out, void *in);




extern void GraphU64_TransformDirection(void *matrix, void *input, void *output);

extern void Events_DeliverContactEffect(void *, void *, s32, s32, CVector3, struct IntPair);

extern void Particle_SpawnChildEffect(void *, s32, s8, s32);

/** Return the word at offset 0xFC68. */
int Particle_GetLastSpawnedEffect(struct EffectSystem *effectSystem) {
    return (s32)effectSystem->last;
}

void Particle_ReleaseOwnerListOneEffects(struct EffectSystem *effectSystem, s32 arg1) {
    s32 *temp_v1_3;
    s32 temp_a1;
    s32 flags;
    u16 kind;
    ParticleEffect *next;
    ParticleEffect *var_s0;

    var_s0 = effectSystem->lists[1].head;
    if (var_s0 != 0) {
        do {
            kind = var_s0->kind;
            next = var_s0->next;
            if ((kind == 0x41E) || (kind == 0x3EF)) {
                flags = var_s0->flags;
                if ((flags & 0x100) && (var_s0->owner == (void *)arg1) && !(flags & 0x800)) {
                    Particle_FinishActorEffects(var_s0);
                    if (var_s0->unk1D9 != 0) {
                        Particle_UpdateMatrix(var_s0);
                        Fx_DetachParticleSwooshes(&D_801379C0, var_s0);
                    }
                    temp_a1 = var_s0->unk138;
                    if (temp_a1 != 0) {
                        DynLight_ReleaseLight(&D_8013B1A8, temp_a1);
                        var_s0->unk138 = 0;
                    }
                    temp_v1_3 = var_s0->refCount;
                    if (temp_v1_3 != 0) {
                        *temp_v1_3 -= 1;
                    }
                    var_s0->flags = var_s0->flags & 0xFDFFFEFF;
                    func_80255ED8_de(var_s0->list, var_s0);
                    var_s0->list = 0;
                    func_80255CB8_de(&effectSystem->free, var_s0);
                    if (var_s0->flags & 0x01000000) {
                        func_80255ED8_de(&effectSystem->groups, var_s0);
                    }
                }
            }
            var_s0 = next;
        } while (var_s0 != 0);
    }
}

s32 Particle_CountOwnerListOneEffects(struct EffectSystem *effectSystem, s32 arg1) {
    ParticleEffect *record;
    s32 count;
    u16 v;

    record = effectSystem->lists[1].head;
    count = 0;
    if (record != 0) {
        do {
            v = record->kind;
            if (((v == 0x3EF) || (v == 0x41E)) && (record->owner == (void *)arg1)) {
                count += 1;
            }
            record = record->next;
        } while (record != 0);
    }
    return count;
}

void Particle_ReleaseOwnerListTwoEffects(struct EffectSystem *effectSystem, s32 arg1) {
    s32 *temp_v1_3;
    s32 temp_a1;
    s32 flags;
    u16 kind;
    ParticleEffect *next;
    ParticleEffect *var_s0;

    var_s0 = effectSystem->lists[2].head;
    if (var_s0 != 0) {
        do {
            kind = var_s0->kind;
            next = var_s0->next;
            if (((kind == 0x414) || (kind == 0x42D)) &&
                (var_s0->owner == (void *)arg1)) {
                flags = var_s0->flags;
                if (flags & 0x100) {
                  if (!(flags & 0x800)) {
                    Particle_FinishActorEffects(var_s0);
                    if (var_s0->unk1D9 != 0) {
                        Particle_UpdateMatrix(var_s0);
                        Fx_DetachParticleSwooshes(&D_801379C0, var_s0);
                    }
                    temp_a1 = var_s0->unk138;
                    if (temp_a1 != 0) {
                        DynLight_ReleaseLight(&D_8013B1A8, temp_a1);
                        var_s0->unk138 = 0;
                    }
                    temp_v1_3 = var_s0->refCount;
                    if (temp_v1_3 != 0) {
                        *temp_v1_3 -= 1;
                    }
                    var_s0->flags =
                        var_s0->flags & 0xFDFFFEFF;
                    func_80255ED8_de(var_s0->list, var_s0);
                    var_s0->list = 0;
                    func_80255CB8_de(&effectSystem->free, var_s0);
                    if (var_s0->flags & 0x01000000) {
                        func_80255ED8_de(&effectSystem->groups, var_s0);
                    }
                  }
                }
            }
            var_s0 = next;
        } while (var_s0 != 0);
    }
}

int Particle_GetEffectResource(void *arg0) {
    ObjParticleInitializeAttachmentsAndSound *actor = arg0;
    return (int)actor->effectResource;
}

s32 Particle_GetRenderLayer(void *arg0) {
    ObjParticleInitializeAttachmentsAndSound *object = arg0;
    s32 result;

    result = 0;
    if ((*object->effectFlags) & 0x02000000) {
        if (object->unk5C & 2) {
            result = 2;
        } else if (D_801462C8.firstListMode == 2) {
            result = 1;
        }
    }
    return result;
}

void Particle_InitializeObjectLinks(void *arg0) {
    (((struct ObjectLinks1E8 *) ((s8 *) arg0))->unk_18) = &D_8011ADB0;
    (((struct ObjectLinks1E8 *) ((s8 *) arg0))->unk_0) = 2;
    (((struct ObjectLinks1E8 *) ((s8 *) arg0))->unk_5C) = 0;
    (((struct ObjectLinks1E8 *) ((s8 *) arg0))->unk_1DC) = 0;
    (((struct ObjectLinks1E8 *) ((s8 *) arg0))->unk_1E4) = 0;
}

void Particle_ReleaseObjectAndSound(void *object) {
    Particle_Release(&D_8011D8D0, object);
    Particle_StopSound(object);
}

#include "particle/8027A0F4_8.H"
extern CQuatern GraphU64_BuildDirectionQuaternion(CVector3 *);
extern Triple D_801002A8;
extern s32 SoundElement_PlaySoundAtPosition(s16, CVector3, s32, s32);
void Particle_SpawnAtSharedContactPoint(ObjParticleInitializeAttachmentsAndSound *source, s32 kind) {
    CQuatern q;
    CVector3 pos;

    if ((*source->effectFlags & 0x10) != 0) {
        pos = D_801042C8;
    } else {
        pos = source->rotation;
    }
    q = GraphU64_BuildDirectionQuaternion(&pos);
    func_802800C0_de((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)source,
                  (struct EffectActor *)source->effectResource,
                  (s32 *)source->effectIndex,
                  source->effectCount, kind,
                  pos, q, *(CVector3 *)&D_80100290.v, 0, D_80100290.w,
                  (source->unk5C & 0x200006) | 1);
}

void Particle_SpawnWithModeMinusThree(ObjParticleInitializeAttachmentsAndSound *source, s32 kind) {
    CQuatern rotation;
    CVector3 position;

    if ((*source->effectFlags & 0x10) != 0) {
        position = D_801042C8;
    } else {
        position = source->rotation;
    }
    rotation = GraphU64_BuildDirectionQuaternion(&position);
    func_802800C0_de((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)source,
                  (struct EffectActor *)source->effectResource,
                  (s32 *)source->effectIndex,
                  source->effectCount, kind,
                  position, rotation, *(CVector3 *)&D_801002A8, 0, -3,
                  (source->unk5C & 0x200006) | 1);
}

void Particle_SpawnWithModeMinusTwo(ObjParticleInitializeAttachmentsAndSound *source, s32 kind) {
    CQuatern rotation;
    CVector3 position;

    if ((*source->effectFlags & 0x10) != 0) {
        position = D_801042C8;
    } else {
        position = source->rotation;
    }
    rotation = GraphU64_BuildDirectionQuaternion(&position);
    func_802800C0_de((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)source,
                  (struct EffectActor *)source->effectResource,
                  (s32 *)source->effectIndex,
                  source->effectCount, kind,
                  position, rotation, *(CVector3 *)&D_801002A8, 0, -2,
                  (source->unk5C & 0x200006) | 1);
}

void Particle_SpawnWithModeMinusFive(ObjParticleInitializeAttachmentsAndSound *source, s32 kind) {
    CQuatern rotation;
    CVector3 position;

    if (*source->effectFlags & 0x10) {
        position = D_801042C8;
    } else {
        position = source->rotation;
    }
    rotation = GraphU64_BuildDirectionQuaternion(&position);
    func_802800C0_de((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)source,
                  (struct EffectActor *)source->effectResource,
                  (s32 *)source->effectIndex,
                  source->effectCount, kind,
                  position, rotation, *(CVector3 *)&D_801002B8, 0, -5,
                  (source->unk5C & 0x200006) | 1);
}

void Particle_InitializeAttachmentsAndSound(ObjParticleInitializeAttachmentsAndSound *actor, ParamsParticleInitializeAttachmentsAndSound *arg1) {
    s32 temp_t0;
    s8 temp_a1;
    s8 resourceId;
    u16 temp_v1;
    Particle_Attach((Shared_Particle *)actor, 0, 0);
    resourceId = arg1->unk6;
    if (resourceId != -1) {
        Fx_AttachActorRibbon(&D_801379C0, actor, resourceId);
    }
    temp_a1 = arg1->unk7;
    actor->unk138 = temp_a1 == -1 ? 0 : DynLight_AllocateWorldLight(&D_8013B1A8, temp_a1);
    if (!(actor->unk5C & 0x200000) && (temp_t0 = arg1->unkC, (temp_t0 != 0))) {
        switch(actor->unk4) {
        case 0x22: case 0x5f: case 0x60:
            Particle_PlayAttachedSound(actor,temp_t0); break;
        default:
            SoundElement_PlaySoundAtPosition(temp_t0, *(CVector3 *)&actor->unk8, 0, -1); break;
        }
    }
}

void Particle_ReleaseAttachments(void *arg0) {
    s32 temp;

    if (((ObjParticleInitializeAttachmentsAndSound *)arg0)->active1D9 != 0) {
        Particle_UpdateMatrix(arg0);
        Fx_DetachParticleSwooshes(&D_801379C0, arg0);
    }
    temp = ((ObjParticleInitializeAttachmentsAndSound *)arg0)->unk138;
    if (temp != 0) {
        DynLight_ReleaseLight(&D_8013B1A8, temp);
        ((ObjParticleInitializeAttachmentsAndSound *)arg0)->unk138 = 0;
    }
}

void Particle_ApplyDirectionalAcceleration(ObjRecAt174 *arg0) {
 CVector3 delta, direction;
 CVector3 *velocity, *dir;
 int condition;
 f32 accel, length, limit;
 accel=RW_BITS_TO_FLOAT(arg0->link->params->accel);
 if(accel != 0.0f) {
 dir=&direction;
 direction=arg0->direction;
 GraphU64_ScaleVector(&delta,dir,accel);
 velocity=&arg0->velocity;
 GraphU64_AddVec3(velocity,velocity,&delta);
 length=Math_Sqrtf(arg0->velocity.x*arg0->velocity.x+arg0->velocity.y*arg0->velocity.y+arg0->velocity.z*arg0->velocity.z);
 limit=RW_BITS_TO_FLOAT(arg0->link->params->limit);
 if(accel>0.0f) { if(!(limit<length)) goto done; } else { if(!(length<limit)) goto done; } GraphU64_ScaleVector(velocity,dir,limit); done:;
 }
}

void Particle_FlagKind86ModeTwo(void *arg0, s32 arg1) {
    if (((((struct ObjectState60 *) ((s8 *) arg0))->unk_4) == 0x56) && (arg1 == 2)) {
        (((struct ObjectState60 *) ((s8 *) arg0))->unk_5C) = (s32) ((((struct ObjectState60 *) ((s8 *) arg0))->unk_5C) | 0x04000000);
    }
}

void Particle_CaptureSharedTrailState(void *arg0) {
    ((ObjParticleInitializeAttachmentsAndSound *)arg0)->unk5C |= 0x20000;
    ((TrailActor *)arg0)->origin = D_801001F8.first;
    ((TrailActor *)arg0)->position = D_801001F8.second;
}

void Particle_AttachToCurrentTarget(void *arg0, f32 *arg1, s32 arg2) {
    f32 source[16];
    f32 matrix[16];
    CVector3 direction;
    void *actor;
    s32 mode;
    Shared_ParticleTarget *current;
    f32 *matrix_ptr;
    SceneState *scene;
    CVector3 *direction_ptr;

    actor = arg0;
    mode = arg2;
    current = D_801041F0.current;
    if (arg1 != 0) {
        GraphU64_InvertAffineMatrix(matrix, arg1);
    } else {
        GraphU64_ConvertMatrixToFloat(source,
            &current->drawMatrices[D_801041F0.frame]);
        GraphU64_InvertAffineMatrix(matrix, source);
    }
    matrix_ptr = matrix;
    scene = &D_801001F8;
    GraphU64_TransformPoint(matrix_ptr, scene, &((Shared_Particle *)actor)->attachmentPosition);
    direction_ptr = &direction;
    direction = scene->direction;
    GraphU64_NormalizeVec3((f32 *)direction_ptr);
    GraphU64_TransformDirection(matrix_ptr, direction_ptr, &((Shared_Particle *)actor)->inst.velocity);
    ((Shared_Particle *)actor)->target = current;
    ((Shared_Particle *)actor)->flags |= 0x10000;
    ((Shared_Particle *)actor)->collisionNode = scene->actor_byte;
    if (((Shared_Particle *)actor)->inst.type == 0x56 && mode == 2) {
        ((Shared_Particle *)actor)->flags |= 0x04000000;
    }
}

/** Return arg0, but treat the sentinel value 0xA as 0. */
s32 Particle_MapEventTenToZero(s32 arg0) {
    if (arg0 == 0xA) {
        return 0;
    }
    return arg0;
}

void Particle_DispatchActorContactEvents(void *actor) {
    struct IntPair pair;
    s32 temp_a1;
    struct Shared_ParticleEvents *events;
    s32 var_a0;
    s32 temp_a2;
    s32 model;
    s32 temp_s3;
    struct Shared_ParticleDesc *temp_s1;
    void *temp_v0_2;
    void *temp_v1;

    temp_s1 = ((Shared_Particle *)actor)->desc;
    if (Particle_HasSurfaceFlag(actor) != 0) {
        var_a0 = 0xC;
    } else {
        var_a0 = 0xA;
    }
    temp_a1 = var_a0 * 2;
    events = temp_s1->events;
    temp_v1 = (char *)events + temp_a1;
    model = events->particles[var_a0];
    temp_a2 = events->effects[var_a0];
    temp_v0_2 = (char *)events + (var_a0 * 8);
    pair = events->parameters[var_a0];
    temp_s3 = temp_s1->events->sounds[var_a0];
    if (temp_a2 != 0xFFFF) {
        Events_DeliverContactEffect(actor, actor, temp_a2, -1,
                     ((Shared_Particle *)actor)->inst.pos, pair);
    }
    if (model != 0xFFFF) {
        Particle_SpawnChildEffect(actor, model, ((Shared_Particle *)actor)->space, 1);
    }
    if (temp_s3 != 0xFFFF) {
        SoundElement_PlaySoundAtPosition((s16)temp_s3,
                      ((Shared_Particle *)actor)->inst.pos, 0, -1);
    }
}

void Particle_DispatchSpatialContactEvents(void *particle) {
    struct IntPair pair;
    s32 temp_a1;
    struct Shared_ParticleEvents *events;
    s32 var_a0;
    s32 temp_a2;
    s32 temp_s2;
    s32 temp_s3;
    struct Shared_ParticleDesc *temp_s1;
    void *temp_v0_2;
    void *temp_v1;

    temp_s1 = ((Shared_Particle *)particle)->desc;
    if (Particle_HasSurfaceFlag(particle) != 0) {
        var_a0 = 0xD;
    } else {
        var_a0 = 0xB;
    }
    temp_a1 = var_a0 * 2;
    events = temp_s1->events;
    temp_v1 = (char *)events + temp_a1;
    temp_s2 = events->particles[var_a0];
    temp_a2 = events->effects[var_a0];
    temp_v0_2 = (char *)events + (var_a0 * 8);
    pair = events->parameters[var_a0];
    temp_s3 = temp_s1->events->sounds[var_a0];
    if (temp_a2 != 0xFFFF) {
        Events_DeliverContactEffect(particle, particle, temp_a2, -1,
                     ((Shared_Particle *)particle)->inst.pos, pair);
    }
    if (temp_s2 != 0xFFFF) {
        Particle_SpawnChildEffect(particle, temp_s2, ((Shared_Particle *)particle)->space, 1);
    }
    if (temp_s3 != 0xFFFF) {
        SoundElement_PlaySoundAtPosition((s16)temp_s3,
                      ((Shared_Particle *)particle)->inst.pos,
                      (s32)&((Shared_Particle *)particle)->inst.pos, (s32)particle);
    }
}

void Particle_DispatchParticleContactEvents(void *particle) {
    struct IntPair pair;
    s32 temp_a1;
    struct Shared_ParticleEvents *events;
    s32 var_a0;
    s32 temp_a2;
    s32 temp_s2;
    s32 temp_s3;
    struct Shared_ParticleDesc *temp_s1;
    void *temp_v0_2;
    void *temp_v1;

    temp_s1 = ((Shared_Particle *)particle)->desc;
    if (Particle_HasSurfaceFlag(particle) != 0) {
        var_a0 = 0xC;
    } else {
        var_a0 = 0xA;
    }
    temp_a1 = var_a0 * 2;
    events = temp_s1->events;
    temp_v1 = (char *)events + temp_a1;
    temp_s2 = events->particles[var_a0];
    temp_a2 = events->effects[var_a0];
    temp_v0_2 = (char *)events + (var_a0 * 8);
    pair = events->parameters[var_a0];
    temp_s3 = temp_s1->events->sounds[var_a0];
    if (temp_a2 != 0xFFFF) {
        Events_DeliverContactEffect(particle, particle, temp_a2, -1,
                     ((Shared_Particle *)particle)->inst.pos, pair);
    }
    if (temp_s2 != 0xFFFF) {
        Particle_SpawnChildEffect(particle, temp_s2, ((Shared_Particle *)particle)->space, 1);
    }
    if (temp_s3 != 0xFFFF) {
        SoundElement_PlaySoundAtPosition((s16)temp_s3,
                      ((Shared_Particle *)particle)->inst.pos, 0, -1);
    }
}

int Particle_HasSurfaceFlag(void *particle) {
    char pad[0x10];
    return ((u32)((Shared_Particle *)particle)->flags >> 2) & 1;
}

int Particle_ReturnZero(void) {
    char pad[0x10];
    return 0;
}

/* Size scale for a particle seen through a camera: the out-of-line copy of the inline particleCameraScale
 * (particle/CAMERA_SCALE.H), which Particle_BuildMatrix inlines. */
f32 Particle_CameraScale(Shared_Particle *particle, f32 distFromCamera, GameplayCamera *camera) {
    return particleCameraScale(particle, distFromCamera, camera);
}
