#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OBJECTLINKS1E8.H"
#include "TYPES.H"
#include "FX/PARTICLE_SOUND.H"
#include "SYSTEM/80255C40_3.H"
#include "particle/80271B18_3.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "particle/8027A0F4_4.H"
#include "particle/PARTICLE_SPAWNEFFECTGROUP.H"
#include "COMMON/UNUSED.H"
#include "COMMON/PACKEDMESHMATERIAL.H"
#include "COMMON/S1.H"
#include "COMMON/SELF.H"
#include "RENDER/8028469C.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "PARTICLE/PARTICLE_5.H"

/* CODE_8028414C.CPP */
extern s32 func_8025CA24_de(void *arg0, void *arg1);

extern s32 D_80140FF8[];
extern s32 D_800D297C;

void Particle_UpdateMatrix(Shared_Particle *particle) {
    CVector3 delta;
    GameplayCamera *camera;
    f32 amount;
    s32 *state;

    state = D_80140FF8;
    if (state[0] == 1) {
        camera = (GameplayCamera *)state[-4];
        Graphu64_TransformPoint(camera->worldToView, &particle->inst.pos, &delta);
        amount = delta.z;
        if (amount < 0.0f) {
            amount = -amount;
        }
        Particle_BuildMatrix(particle, &particle->mtx[D_800D297C], camera, amount);
    } else {
        Particle_BuildMatrix(particle, &particle->mtx[D_800D297C], 0, 0.0f);
    }
    particle->flags |= 0x100000;
}

/* Spawns a sequence of effects along an object's motion segment. */

extern char D_8011D8D0;

void Particle_SpawnInterpolatedTrail(TrailActor *actor) {
        CQuatern rotation;
        int temp;
        Triple delta;
        Triple step;
        unsigned int actor_2;
        Triple position;
        f32 divisor;
        s32 i;
        s8 count;
        void *system;
        count = actor->node->state->count;
        if (count > 0) {
                position = actor->position;
                rotation = Graphu64_BuildDirectionQuaternion((f32 *)&position);
                Graphu64_SubtractVectors(&delta, &actor->origin, &actor->end);
                system = &D_8011D8D0;
                i = 1;
                temp = i <= count;
                if (temp) {
                        divisor = (f32) count + (&D_800C4E88_de)[1];
                        do {
    do { Graphu64_ScaleVector(&step, &delta, (f32) i / divisor); Graphu64_AddVec3(&step, &step, &actor->end); actor_2 = actor->model; Particle_SpawnEffectGroup((struct EffectSystem *)system, (struct EffectActor *)actor, (struct EffectActor *)actor->owner, (s32 *)actor->property, actor->type, actor_2, *(CVector3 *)&position, *(CQuatern *)&rotation, *(CVector3 *)&step, 0, -1, 0x20E001); i++; } while (0);
                        } while (count >= i);
                }
        }
}

extern void *func_8025CC6C_de(void);

void Particle_PlayAttachedSound(void *soundParticle, s32 arg1) {
    void *node;

    node = ((SoundParticle *)soundParticle)->sound;
    if (node != 0) {
        if (((Node80253610 *)node)->flags == arg1 && ((Node80253610 *)node)->references != -1) {
            return;
        }
        Particle_StopSound(soundParticle);
    }
    ((SoundParticle *)soundParticle)->sound =
        func_8025C95C_de(func_8025CC6C_de(), arg1, &((SoundParticle *)soundParticle)->particle.inst.pos, &((SoundParticle *)soundParticle)->particle.inst.pos, -1);
}

void Particle_StopSound(void *a) {
    if (((SoundParticle *)a)->sound != 0) {
        func_8025CA24_de(func_8025CC6C_de(), ((SoundParticle *)a)->sound);
        ((SoundParticle *)a)->sound = 0;
    }
}

struct PoolNode84478;
typedef struct PoolBucket84478 {
    struct PoolNode84478 *head;
    struct PoolNode84478 *tail;
    s32 data[3];
} PoolBucket84478;
typedef struct PoolOwner84478 {
    char pad0[0xFC00];
    PoolBucket84478 free;
    char padFC14[0x14];
    PoolBucket84478 slots[256];
} PoolOwner84478;
typedef struct PoolNode84478 {
    char pad0[0x5C];
    s32 state;
    char pad60[0x184];
    PoolBucket84478 *owner;
    char pad1E8[8];
    s32 counter;
    s32 flags;
} PoolNode84478;
void Particle_Release(EffectSystem *, ParticleEffect *);

PoolNode84478 *Particle_AllocPoolNode(PoolOwner84478 *owner, s32 index) {
    PoolNode84478 *node;
    PoolBucket84478 *slot;
    s32 i;
    PoolNode84478 *tail;
    if (owner->free.head == 0) {
        for (i = 0; i <= (index & 0xFF); i++) {
            tail = (&owner->slots[i])->tail;
            if (tail != 0) {
                Particle_Release((EffectSystem *)owner, (ParticleEffect *)tail);
                break;
            }
        }
    }
    node = owner->free.head;
    if (node == 0) {
        return 0;
    }
    func_80255ED8_de(&owner->free, node);
    slot = &owner->slots[index & 0xFF];
    func_80255CB8_de(slot, node);
    node->owner = slot;
    node->flags = 0;
    node->counter = 0;
    node->state = 0x100;
    return node;
}

/* 8028308C_3.CPP */
extern void Particle_FinishActorEffects(void *arg0);
extern void Fx_DetachParticleSwooshes(void *arg0, void *arg1);

void Particle_Release(EffectSystem *owner, ParticleEffect *releasedEffect) {
    s32 *releaseReferenceCount;
    s32 releasedLight;
    s32 flags;

    flags = releasedEffect->flags;
    if (flags & 0x100) {
        if (!(flags & 0x800)) {
            Particle_FinishActorEffects(releasedEffect);
            if (releasedEffect->unk1D9 != 0) {
                Particle_UpdateMatrix(releasedEffect);
                Fx_DetachParticleSwooshes(&D_801379C0, releasedEffect);
            }
            releasedLight = releasedEffect->unk138;
            if (releasedLight != 0) {
                Gdynlight_ReleaseLight(&D_8013B1A8, releasedLight);
                releasedEffect->unk138 = 0;
            }
            releaseReferenceCount = releasedEffect->refCount;
            if (releaseReferenceCount != 0) {
                *releaseReferenceCount -= 1;
            }
            releasedEffect->flags =
                releasedEffect->flags & 0xFDFFFEFF;
            func_80255ED8_de(releasedEffect->list, releasedEffect);
            releasedEffect->list = 0;
            func_80255CB8_de(&owner->free, releasedEffect);
            if (releasedEffect->flags & 0x01000000) {
                func_80255ED8_de(&owner->groups, releasedEffect);
            }
        }
    }
}

/* 8028308C_4.CPP */
/* Passes the first non-null handle among entries 0 to count of the object's twenty-byte table at
   0xFC28 to func_80284570_de together with the object. */

void Particle_ReleaseFirstHandle(char *obj, unsigned char count) {
    int i;

    for (i = 0; i <= count; i++) {
        EntryRecAt4V1 *e = (EntryRecAt4V1 *)(obj + i * sizeof(EntryRecAt4V1) + 0xFC28);
        if (e->handle != 0) {
            Particle_Release(obj, e->handle);
            return;
        }
    }
}

/* 8028469C.CPP */
void *Particle_FindOwnerEntry(EffectSystem *effectSystem, s32 arg1, EffectEntry *effectEntry) {
    void *record;

    record = effectEntry->params->listIndex[effectSystem->lists].head;
    if (effectEntry != 0) {
        if (record != 0) {
            do {
                if (((ParticleEffect *)record)->ownerId == arg1) {
                    if (((ParticleEffect *)record)->entry == effectEntry) {
                        return record;
                    }
                }
                record = ((ParticleEffect *)record)->next;
            } while (record != 0);
        }
    } else if (record != 0) {
        do {
            if (((ParticleEffect *)record)->ownerId == arg1) {
                return record;
            }
            record = ((ParticleEffect *)record)->next;
        } while (record != 0);
    }
    return 0;
}

extern void func_80255D70_de(void *, s32, s32);

void Particle_InsertEntryGroup(EffectSystem *arg0, ParticleEffect *arg1)
{
    void *current;
    s32 key;

    current = arg0->groups.head;
    if (current != 0) {
        key = (s32)arg1->entry;
loop:
        if (((ParticleEffect *)current)->entry != key) {
            current = ((ParticleEffect *)current)->groupNext;
            if (current != 0) {
                goto loop;
            }
        }
    }

    if (current != 0) {
        func_80255D70_de(&arg0->groups, current, arg1);
    } else if (arg1->entry->flags & 0x2000) {
        func_80255CB8_de(&arg0->groups, arg1);
    } else {
        func_80255D14_de(&arg0->groups, arg1);
    }

    arg1->flags |= 0x01000000;
}

s32 Particle_RandomInclusiveCount(s32 arg0) {
    if (arg0 != 0) {
        return Graphu64_NextRandom() % (arg0 + 1);
    }
    return 0;
}

void Particle_AdvanceRandomWhenNonzero(f32 arg0) {
    if (arg0 != 0.0f) {
        ((s32 (*)())Graphu64_RandomFloat)();
    }
}

/** Return offset 0x180 only when the nested state word is zero. */
float Particle_GetConditionalFirstValue(ParticleEffect *effect) {
    void *inner = effect->entry;
    if (((EffectEntry *)inner)->unk14 != 0) {
        return 0.0f;
    }
    return effect->unk180[0];
}

f32 Particle_GetConditionalSecondValue(ParticleEffect *effect) {
    f32 result;
    result = 0.0f;
    if ((effect->entry->unk14) == 0) {
        result = (effect->unk180[1]);
    }
    return result;
}

s32 Particle_IsKind2Or86Or273Or294(ParticleEffect *effect) {
    u16 kind;
    s32 val;

    kind = effect->kind;
    val = kind;
    if (val == 0x56) {
        goto ret1;
    }
    if (val >= 0x57) {
        goto ge_e;
    }
    if (val == 2) {
        goto ret1;
    }
    goto ret0;
ge_e:
    if (val == 0x111) {
        goto ret1;
    }
    if (val != 0x126) {
        goto ret0;
    }
ret1:
    return 1;
ret0:
    return 0;
}

s32 Particle_IsKind5To7Or9Or17Or19Or26Or257Or272(ParticleEffect *effect) {
    u16 kind;
    s32 val;

    kind = effect->kind;
    val = kind;
    if (val == 0x11) {
        goto ret1;
    }
    if (val >= 0x12) {
        goto ge_12;
    }
    if (val < 5) {
        goto ret0;
    }
    if (val < 8) {
        goto ret1;
    }
    if (val == 9) {
        goto ret1;
    }
    goto ret0;
ge_12:
    if (val == 0x1A) {
        goto ret1;
    }
    if (val >= 0x1B) {
        goto ge_1b;
    }
    if (val == 0x13) {
        goto ret1;
    }
    goto ret0;
ge_1b:
    if (val == 0x101) {
        goto ret1;
    }
    if (val != 0x110) {
        goto ret0;
    }
ret1:
    return 1;
ret0:
    return 0;
}

s32 Particle_IsKind8Or13Or18(ParticleEffect *effect) {
    u16 kind;
    s32 val;

    kind = effect->kind;
    val = kind;
    if (val == 0xD) {
        goto ret1;
    }
    if (val >= 0xE) {
        goto ge_e;
    }
    if (val == 8) {
        goto ret1;
    }
    goto ret0;
ge_e:
    if (val != 0x12) {
        goto ret0;
    }
ret1:
    return 1;
ret0:
    return 0;
}

void Particle_UpdateForcesAndMotion(ParticleEffect *effect)
{
    CVector3 delta;
    CVector3 direction;
    f32 acceleration;
    f32 speed;
    f32 limit;
    f32 x, y, z;
    CVector3 *velocity;

    Playerai_ApplyPlayerForces(&D_80145040, effect);
    acceleration = Menu_ExpandFloatHighWord(effect->entry->motion->acceleration);
    if (acceleration != 0.0f) {
        direction = effect->direction;
        Graphu64_ScaleVector(&delta, &direction, acceleration);
        Graphu64_AddVec3(&effect->velocity, &effect->velocity, &delta);
        velocity = &effect->velocity;
        x = effect->velocity.x;
        y = effect->velocity.y;
        z = effect->velocity.z;
        speed = Gu_Sqrtf(x * x + y * y + z * z);
        limit = Menu_ExpandFloatHighWord(effect->entry->motion->speedLimit);
        if (acceleration > 0.0f) {
            if (!(limit < speed)) goto finished;
        } else {
            if (!(speed < limit)) goto finished;
        }
        Graphu64_ScaleVector(velocity, &direction, limit);
finished:
        ;
    }
    Particle_UpdateSineMotion(effect, 1.0f);
}

/* 8028469C_2.CPP */

extern f32 Graphu64_GetSquaredDistance(f32 *arg0, f32 *arg1);
extern void Particle_HandlePlayerContact(void *arg0, void *arg1);

const unsigned int D_blob_35af2254633920324f03[2] = {
    0x4123D70A, 0x3F000000,
};
void Particle_CheckNearbyPlayerContacts(Shared_Particle *particle) {
    CVector3 point;
    void *node;
    void *point_ptr;
    int actor_id;
    s16 amount;
    int stop;
    f32 radius_sq;
    f32 height_scale;

    amount = particle->desc->unk10;
    radius_sq = (f32)amount;
    if (radius_sq <= 0.0f) {
        return;
    }
    radius_sq *= D_800C4E90_de;
    node = D_80145060.actorList;
    radius_sq *= radius_sq;
    if (node == 0) {
        return;
    }

    point_ptr = &point;
    actor_id = 0x40F;
    height_scale = (&D_800C4E90_de)[1];
    do {
        point = ((Shared_ActorView *)node)->position.vector;
        stop = 0;
        if (particle->inst.type != actor_id) {
            point.y += Gobjinst_GetActorHeight(node) * height_scale;
        }
        if (Graphu64_GetSquaredDistance(&particle->inst.pos.x, point_ptr) < radius_sq) {
            Particle_HandlePlayerContact(particle, node);
            if (particle->inst.type == actor_id) {
                stop = 1;
            }
        }
        if (stop != 0) {
            node = 0;
        } else {
            node = ((Shared_ActorView *)node)->next;
        }
    } while (node != 0);
}

typedef struct CollisionInfo CollisionInfo;

extern CollisionInfo D_80100030;
extern Instance8020CD74 *Gsky_FindScreenMessage(Arg1 *arg0);
extern s32 Unicol_MoveActorWithCollision(Instance8020CD74 *, CVector3, CollisionInfo *);

s32 Particle_HasClearMotionPath(Instance8020CD74 *arg0, Arg1 *arg1) {
    Instance8020CD74 saved;
    Instance8020CD74 *instance;
    s32 collisions;

    instance = Gsky_FindScreenMessage(arg1);
    if (instance != 0 && arg1->field24 == 0) {
        saved = *instance;
        instance->position = arg1->position128;
        collisions = Unicol_MoveActorWithCollision(instance, arg0->position, &D_80100030);
        *instance = saved;
    } else {
        saved = *arg0;
        saved.position = arg1->position128;
        collisions = Unicol_MoveActorWithCollision(&saved, arg0->position, &D_80100030);
    }
    return collisions == 0;
}

/* Marks nearby objects other than type 87 as active. */

void Particle_MarkNearbyObjects(s32 unused, ObjParticleMarkNearbyObjects *center, ObjParticleMarkNearbyObjects **objects, s32 count) {
 f32 d[3]; s32 i; ObjParticleMarkNearbyObjects *o;
 for(i=0;i<count;i++) {
  o=objects[i];
  if(o->unk4 != 0x57) {
   Graphu64_SubtractVectors(d,o->pos,center->pos);
   if(d[0]*d[0]+d[1]*d[1]+d[2]*d[2]<=65536.0f) o->unk14C=1;
  }
 }
}

/* Checks object proximity through type-specific handlers and marks nearby objects active. */

static inline void nearby(s32 unused, ObjParticleMarkNearbyObjects *center, ObjParticleMarkNearbyObjects **objects, s32 count) {
 f32 d[3]; s32 i; ObjParticleMarkNearbyObjects *o;
 for(i=0;i<count;i++) {
  o=objects[i];
  if(o->unk4 != 0x57) {
   Graphu64_SubtractVectors(d,o->pos,center->pos);
   if(d[0]*d[0]+d[1]*d[1]+d[2]*d[2]<=65536.0f) o->unk14C=1;
  }
 }
}
extern void Particle_MarkCrowdedActor(int,ObjParticleMarkNearbyObjects *,ObjParticleMarkNearbyObjects **,int);
void Particle_UpdateNearbyObjectFlags(int context,ObjParticleMarkNearbyObjects **objects,int count) {
 int i; ObjParticleMarkNearbyObjects *obj;
 for(i=0;i<count;i++) {
  obj=objects[i];
  switch(obj->unk4) {
   case 0xC: break;
   case 0x22: Particle_MarkCrowdedActor(context,obj,objects,count); break;
   case 0x57: nearby(context,obj,objects,count); break;
  }
 }
}

void Particle_AverageOwnerEffectPositions(EffectSystem *effectSystem, s32 arg1, CVector3 *arg2) {
    f32 temp_f2;
    s32 count;
    u16 v;
    s8 *record;

    arg2->x = 0.0f;
    arg2->y = 0.0f;
    arg2->z = 0.0f;
    record = effectSystem->lists[1].head;
    count = 0;
    if (record != 0) {
        do {
            v = ((ParticleEffect *)record)->kind;
            if (((v == 0x41E) || (v == 0x3EF)) &&
                (((ParticleEffect *)record)->owner == arg1) &&
                (((ParticleEffect *)record)->flags & 0x100)) {
                arg2->x += ((ParticleEffect *)record)->pos.x;
                arg2->y += ((ParticleEffect *)record)->pos.y;
                count += 1;
                arg2->z += ((ParticleEffect *)record)->pos.z;
            }
            record = ((ParticleEffect *)record)->next;
        } while (record != 0);
    }
    if (count != 0) {
        temp_f2 = (f32)count;
        arg2->x = (f32)(arg2->x / temp_f2);
        arg2->y = (f32)(arg2->y / temp_f2);
        arg2->z = (f32)(arg2->z / temp_f2);
    }
}

void Particle_FindNearestForeignEffectDistance(EffectSystem *arg0, LevelActor *actor, f32 *arg2) {
    f32 temp;
    void *node;

    *arg2 = D_800C4EA0_de;
    node = arg0->groups.head;
    if (node != 0) {
        do {
            if (((ParticleEffect *)node)->owner != actor && (((ParticleEffect *)node)->flags & 0x100)) {
                temp = Graphu64_GetSquaredDistance(&((ParticleEffect *)node)->pos.x, &actor->position0.x);
                if (temp < *arg2) {
                    *arg2 = temp;
                }
            }
            node = ((ParticleEffect *)node)->groupNext;
        } while (node != 0);
    }
}

#if defined(VERSION_DE)
unsigned int func_8028515C_de_padding_85D5C[1] = {
    0x0C0A145C,
};
#endif

/* 800C9F80.CPP */

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80284B20_CAB80_us_rev1.c */
#endif
