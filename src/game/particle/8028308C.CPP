#include "include_asm.h"
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
extern void func_80284178_de(void *);

extern void func_80279A00_de(void *arg0);

extern void func_802A42F4_de(void *arg0, void *arg1);



extern char D_801379C0;

extern char D_8013B1A8;

extern u8 D_801462E3;

extern s32 D_8011ADB0;

extern char D_8011D8D0;

extern void func_80284570_de(void *a, void *b);

extern CVector3 D_801042C8;

extern Params D_80100290;

extern Triple D_801002B8;

/* Apply resource indices and dispatch the optional object effect. */


 /* extern */
s32 func_80268BE0_de(void *, s8);

 /* extern */
void func_802843B8_de(void *, s32);

 /* extern */
void func_802A4598_de(void *, void *, s8);

/* Adds acceleration along a direction and clamps the resulting speed to its configured limit. */

f32 func_802B72B0_de(f32);

void func_80271F9C_de(CVector3 *,CVector3 *,f32);

 void func_80271F34_de(CVector3 *,CVector3 *,CVector3 *);

/* Transform the measured attachment position and direction into the target frame. */
extern ParticleAttachmentState D_801041F0;

extern void Rsp_ConvertMatrixToFloat(f32 *out, void *in);

extern void func_8026EF58_de(f32 *out, f32 *m);



extern void func_80272B38_de(void *matrix, void *input, void *output);

extern void func_80265E10_de(void *, void *, s32, s32, CVector3, struct IntPair);

extern void func_80279B40_de(void *, s32, s8, s32);

/** Return the word at offset 0xFC68. */
int func_802830B8_de(struct EffectSystem *effectSystem) {
    return (s32)effectSystem->last;
}

void func_802830CC_de(struct EffectSystem *effectSystem, s32 arg1) {
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
                    func_80279A00_de(var_s0);
                    if (var_s0->unk1D9 != 0) {
                        func_80284178_de(var_s0);
                        func_802A42F4_de(&D_801379C0, var_s0);
                    }
                    temp_a1 = var_s0->unk138;
                    if (temp_a1 != 0) {
                        func_80268C7C_de(&D_8013B1A8, temp_a1);
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

s32 func_80283228_de(struct EffectSystem *effectSystem, s32 arg1) {
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

void func_80283278_de(struct EffectSystem *effectSystem, s32 arg1) {
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
                    func_80279A00_de(var_s0);
                    if (var_s0->unk1D9 != 0) {
                        func_80284178_de(var_s0);
                        func_802A42F4_de(&D_801379C0, var_s0);
                    }
                    temp_a1 = var_s0->unk138;
                    if (temp_a1 != 0) {
                        func_80268C7C_de(&D_8013B1A8, temp_a1);
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

int func_802833D0_de(void *arg0) {
    Obj_func_80283920_de *actor = arg0;
    return (int)actor->effectResource;
}

s32 func_802833DC_de(void *arg0) {
    Obj_func_80283920_de *object = arg0;
    s32 result;

    result = 0;
    if ((*object->effectFlags) & 0x02000000) {
        if (object->unk5C & 2) {
            result = 2;
        } else if (D_801462E3 == 2) {
            result = 1;
        }
    }
    return result;
}

void func_80283424_de(void *arg0) {
    (((struct ObjectLinks1E8 *) ((s8 *) arg0))->unk_18) = &D_8011ADB0;
    (((struct ObjectLinks1E8 *) ((s8 *) arg0))->unk_0) = 2;
    (((struct ObjectLinks1E8 *) ((s8 *) arg0))->unk_5C) = 0;
    (((struct ObjectLinks1E8 *) ((s8 *) arg0))->unk_1DC) = 0;
    (((struct ObjectLinks1E8 *) ((s8 *) arg0))->unk_1E4) = 0;
}

void func_80283448_de(void *object) {
    func_80284570_de(&D_8011D8D0, object);
    func_80284434_de(object);
}

#include "particle/8027A0F4_8.H"
extern CQuatern func_80271818_de(CVector3 *);
extern Triple D_801002A8;
extern s32 func_8025DE54_de(s16, CVector3, s32, s32);
void func_80283480_de(Obj_func_80283920_de *source, s32 kind) {
    CQuatern q;
    CVector3 pos;

    if ((*source->effectFlags & 0x10) != 0) {
        pos = D_801042C8;
    } else {
        pos = source->rotation;
    }
    q = func_80271818_de(&pos);
    func_802800C0_de((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)source,
                  (struct EffectActor *)source->effectResource,
                  (s32 *)source->effectIndex,
                  source->effectCount, kind,
                  pos, q, *(CVector3 *)&D_80100290.v, 0, D_80100290.w,
                  (source->unk5C & 0x200006) | 1);
}

void func_802835A8_de(Obj_func_80283920_de *source, s32 kind) {
    CQuatern rotation;
    CVector3 position;

    if ((*source->effectFlags & 0x10) != 0) {
        position = D_801042C8;
    } else {
        position = source->rotation;
    }
    rotation = func_80271818_de(&position);
    func_802800C0_de((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)source,
                  (struct EffectActor *)source->effectResource,
                  (s32 *)source->effectIndex,
                  source->effectCount, kind,
                  position, rotation, *(CVector3 *)&D_801002A8, 0, -3,
                  (source->unk5C & 0x200006) | 1);
}

void func_802836D0_de(Obj_func_80283920_de *source, s32 kind) {
    CQuatern rotation;
    CVector3 position;

    if ((*source->effectFlags & 0x10) != 0) {
        position = D_801042C8;
    } else {
        position = source->rotation;
    }
    rotation = func_80271818_de(&position);
    func_802800C0_de((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)source,
                  (struct EffectActor *)source->effectResource,
                  (s32 *)source->effectIndex,
                  source->effectCount, kind,
                  position, rotation, *(CVector3 *)&D_801002A8, 0, -2,
                  (source->unk5C & 0x200006) | 1);
}

void func_802837F8_de(Obj_func_80283920_de *source, s32 kind) {
    CQuatern rotation;
    CVector3 position;

    if (*source->effectFlags & 0x10) {
        position = D_801042C8;
    } else {
        position = source->rotation;
    }
    rotation = func_80271818_de(&position);
    func_802800C0_de((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)source,
                  (struct EffectActor *)source->effectResource,
                  (s32 *)source->effectIndex,
                  source->effectCount, kind,
                  position, rotation, *(CVector3 *)&D_801002B8, 0, -5,
                  (source->unk5C & 0x200006) | 1);
}

void func_80283920_de(Obj_func_80283920_de *actor, Params_func_80283920_de *arg1) {
    s32 temp_t0;
    s8 temp_a1;
    s8 resourceId;
    u16 temp_v1;
    Particle_Attach((struct Actor_func_8027DAD0_de *)actor, 0, 0);
    resourceId = arg1->unk6;
    if (resourceId != -1) {
        func_802A4598_de(&D_801379C0, actor, resourceId);
    }
    temp_a1 = arg1->unk7;
    actor->unk138 = temp_a1 == -1 ? 0 : func_80268BE0_de(&D_8013B1A8, temp_a1);
    if (!(actor->unk5C & 0x200000) && (temp_t0 = arg1->unkC, (temp_t0 != 0))) {
        switch(actor->unk4) {
        case 0x22: case 0x5f: case 0x60:
            func_802843B8_de(actor,temp_t0); break;
        default:
            func_8025DE54_de(temp_t0, *(CVector3 *)&actor->unk8, 0, -1); break;
        }
    }
}

void func_80283A1C_de(void *arg0) {
    s32 temp;

    if (((Obj_func_80283920_de *)arg0)->active1D9 != 0) {
        func_80284178_de(arg0);
        func_802A42F4_de(&D_801379C0, arg0);
    }
    temp = ((Obj_func_80283920_de *)arg0)->unk138;
    if (temp != 0) {
        func_80268C7C_de(&D_8013B1A8, temp);
        ((Obj_func_80283920_de *)arg0)->unk138 = 0;
    }
}

void func_80283A80_de(ObjRecAt174 *arg0) {
 CVector3 delta, direction;
 CVector3 *velocity, *dir;
 int condition;
 f32 accel, length, limit;
 accel=RW_BITS_TO_FLOAT(arg0->link->params->accel);
 if(accel != 0.0f) {
 dir=&direction;
 direction=arg0->direction;
 func_80271F9C_de(&delta,dir,accel);
 velocity=&arg0->velocity;
 func_80271F34_de(velocity,velocity,&delta);
 length=func_802B72B0_de(arg0->velocity.x*arg0->velocity.x+arg0->velocity.y*arg0->velocity.y+arg0->velocity.z*arg0->velocity.z);
 limit=RW_BITS_TO_FLOAT(arg0->link->params->limit);
 if(accel>0.0f) { if(!(limit<length)) goto done; } else { if(!(length<limit)) goto done; } func_80271F9C_de(velocity,dir,limit); done:;
 }
}

void func_80283BA0_de(void *arg0, s32 arg1) {
    if (((((struct ObjectState60 *) ((s8 *) arg0))->unk_4) == 0x56) && (arg1 == 2)) {
        (((struct ObjectState60 *) ((s8 *) arg0))->unk_5C) = (s32) ((((struct ObjectState60 *) ((s8 *) arg0))->unk_5C) | 0x04000000);
    }
}

void func_80283BCC_de(void *arg0) {
    ((Obj_func_80283920_de *)arg0)->unk5C |= 0x20000;
    ((TrailActor *)arg0)->origin = D_801001F8.first;
    ((TrailActor *)arg0)->position = D_801001F8.second;
}

void func_80283C1C_de(void *arg0, f32 *arg1, s32 arg2) {
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
        func_8026EF58_de(matrix, arg1);
    } else {
        Rsp_ConvertMatrixToFloat(source,
            &current->drawMatrices[D_801041F0.frame]);
        func_8026EF58_de(matrix, source);
    }
    matrix_ptr = matrix;
    scene = &D_801001F8;
    Particle_TransformPoint(matrix_ptr, scene, &((Shared_Particle *)actor)->attachmentPosition);
    direction_ptr = &direction;
    direction = scene->direction;
    func_8027207C_de((f32 *)direction_ptr);
    func_80272B38_de(matrix_ptr, direction_ptr, &((Shared_Particle *)actor)->inst.velocity);
    ((Shared_Particle *)actor)->target = current;
    ((Shared_Particle *)actor)->flags |= 0x10000;
    ((Shared_Particle *)actor)->shake = scene->actor_byte;
    if (((Shared_Particle *)actor)->inst.type == 0x56 && mode == 2) {
        ((Shared_Particle *)actor)->flags |= 0x04000000;
    }
}

/** Return arg0, but treat the sentinel value 0xA as 0. */
s32 func_80283D38_de(s32 arg0) {
    if (arg0 == 0xA) {
        return 0;
    }
    return arg0;
}

void func_80283D50_de(void *actor) {
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
    if (func_80284068_de(actor) != 0) {
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
        func_80265E10_de(actor, actor, temp_a2, -1,
                     ((Shared_Particle *)actor)->inst.pos, pair);
    }
    if (model != 0xFFFF) {
        func_80279B40_de(actor, model, ((Shared_Particle *)actor)->space, 1);
    }
    if (temp_s3 != 0xFFFF) {
        func_8025DE54_de((s16)temp_s3,
                      ((Shared_Particle *)actor)->inst.pos, 0, -1);
    }
}

void func_80283E58_de(void *particle) {
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
    if (func_80284068_de(particle) != 0) {
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
        func_80265E10_de(particle, particle, temp_a2, -1,
                     ((Shared_Particle *)particle)->inst.pos, pair);
    }
    if (temp_s2 != 0xFFFF) {
        func_80279B40_de(particle, temp_s2, ((Shared_Particle *)particle)->space, 1);
    }
    if (temp_s3 != 0xFFFF) {
        func_8025DE54_de((s16)temp_s3,
                      ((Shared_Particle *)particle)->inst.pos,
                      (s32)&((Shared_Particle *)particle)->inst.pos, (s32)particle);
    }
}

void func_80283F60_de(void *particle) {
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
    if (func_80284068_de(particle) != 0) {
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
        func_80265E10_de(particle, particle, temp_a2, -1,
                     ((Shared_Particle *)particle)->inst.pos, pair);
    }
    if (temp_s2 != 0xFFFF) {
        func_80279B40_de(particle, temp_s2, ((Shared_Particle *)particle)->space, 1);
    }
    if (temp_s3 != 0xFFFF) {
        func_8025DE54_de((s16)temp_s3,
                      ((Shared_Particle *)particle)->inst.pos, 0, -1);
    }
}

int func_80284068_de(void *particle) {
    char pad[0x10];
    return ((u32)((Shared_Particle *)particle)->flags >> 2) & 1;
}

int func_80284080_de(void) {
    char pad[0x10];
    return 0;
}

/* Size scale for a particle seen through a camera. A descriptor with flag 4 scales with depth: from 16 to 2048
 * units the scale ramps from the distance range's minimum to its maximum (in thousandths of the depth); others
 * use 1. The result is then corrected for the camera's vertical field of view against the 47.5 degree default.
 * Particle_BuildMatrix inlines the same body. */
f32 Particle_CameraScale(Shared_Particle *particle, f32 depth, GameplayCamera *camera) {
    struct Shared_ParticleDesc *desc = particle->desc;
    f32 near;
    f32 farness;
    f32 scale;
    f32 fov;
    f32 low;
    f32 high;
    if (desc->flags & 4) {
        scale = depth;
        near = scale - 16.0f;
        /* FAKEMATCH: three dead clamps (each result is overwritten before any use; jump2 deletes their compares
         * after allocation) keep high/low and then depth/near live in the RTL, which gives the ROM's float
         * registers (depth $f5, the range ramp in $f2/$f3). */
        farness = RW_MAX_GT(high, near);
        farness = RW_MAX_GT(low, near);
        farness = RW_MIN_LT(1.0f, RW_MAX_GT(0.0f, near) * (1.0f / 2032.0f));
        high = RW_MAX_GT(depth, near);
        high = desc->distanceRange->maximum;
        low = desc->distanceRange->minimum;
        high -= low;
        high *= farness;
        low += high;
        scale *= low;
        scale *= 0.001f;
    } else {
        scale = 1.0f;
    }
    fov = camera->fovY;
    return scale * (1.0f / 47.5f) * (fov + (47.5f - fov) * 0.25f);
}
