#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/PACKEDMESHMATERIAL.H"
#include "RENDER/8028469C.H"
#include "TYPES.H"
#include "RENDER/8028469C_2.H"

extern func_80284AF4_G2 D_80145060;

extern f32 GameObject_GetActorHeight(void *arg0);
extern f32 GraphU64_GetSquaredDistance(f32 *arg0, f32 *arg1);
extern void func_80282E98_de(void *arg0, void *arg1);








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
    node = D_80145060.unk0;
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
            point.y += GameObject_GetActorHeight(node) * height_scale;
        }
        if (GraphU64_GetSquaredDistance(&particle->inst.pos.x, point_ptr) < radius_sq) {
            func_80282E98_de(particle, node);
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
extern Instance8020CD74 *Sky_FindScreenMessage(Arg1 *arg0);
extern s32 Unicol_MoveActorWithCollision(Instance8020CD74 *, CVector3, CollisionInfo *);

s32 Particle_HasClearMotionPath(Instance8020CD74 *arg0, Arg1 *arg1) {
    Instance8020CD74 saved;
    Instance8020CD74 *instance;
    s32 collisions;

    instance = Sky_FindScreenMessage(arg1);
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

extern void GraphU64_SubtractVectors(f32 *, f32 *, f32 *);
void Particle_MarkNearbyObjects(s32 unused, ObjParticleMarkNearbyObjects *center, ObjParticleMarkNearbyObjects **objects, s32 count) {
 f32 d[3]; s32 i; ObjParticleMarkNearbyObjects *o;
 for(i=0;i<count;i++) {
  o=objects[i];
  if(o->unk4 != 0x57) {
   GraphU64_SubtractVectors(d,o->pos,center->pos);
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
   GraphU64_SubtractVectors(d,o->pos,center->pos);
   if(d[0]*d[0]+d[1]*d[1]+d[2]*d[2]<=65536.0f) o->unk14C=1;
  }
 }
}
extern void func_80281A9C_de(int,ObjParticleMarkNearbyObjects *,ObjParticleMarkNearbyObjects **,int);
void Particle_UpdateNearbyObjectFlags(int context,ObjParticleMarkNearbyObjects **objects,int count) {
 int i; ObjParticleMarkNearbyObjects *obj;
 for(i=0;i<count;i++) {
  obj=objects[i];
  switch(obj->unk4) {
   case 0xC: break;
   case 0x22: func_80281A9C_de(context,obj,objects,count); break;
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

extern f32 GraphU64_GetSquaredDistance(f32 *a, f32 *b);









void Particle_FindNearestForeignEffectDistance(EffectSystem *arg0, LevelActor *actor, f32 *arg2) {
    f32 temp;
    void *node;

    *arg2 = D_800C4EA0_de;
    node = arg0->groups.head;
    if (node != 0) {
        do {
            if (((ParticleEffect *)node)->owner != actor && (((ParticleEffect *)node)->flags & 0x100)) {
                temp = GraphU64_GetSquaredDistance(&((ParticleEffect *)node)->pos.x, &actor->position0.x);
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
