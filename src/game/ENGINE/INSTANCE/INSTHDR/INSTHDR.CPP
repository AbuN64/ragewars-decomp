#include "COMMON/PROBE.H"
#include "COMMON/OBJ.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/MATH_HELPERS.H"
#include "COMMON/ACTOR_HEADER.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "TYPES.H"
#include "particle/8024D018_4.H"
#include "FX/80271B18.H"

/* Returns a player's body lean on the ground: a controlled player on an accepted floor (Region_TestPolygonSlopeFlag) that
 * is not held (flag 1) nor in states 1 or 2 computes a tilt toward the floor normal from func_80275C94_de by
 * three eighths of its slope (at most 25 degrees), which the body tilt from Gobjinst_BuildActorDirectionTilt then replaces,
 * and leans along its heading by three quarters of the ground slope ahead from CPlane_GetSlopeAngle (at most 25),
 * blending lean and tilt halfway through GraphU64_InterpolateQuaternionWithLinearFallback; other players take Gobjinst_BuildActorDirectionTilt's tilt, and
 * objects without a floor or held players get the identity. The sine is kept in D_80115DEC. */


extern s32 Region_TestPolygonSlopeFlag(s32);

extern void Region_GetNodeNormal(CVector3 *, s32);

extern void Graphu64_CrossVectors(CVector3 *, CVector3 *, CVector3 *);


extern CQuatern Gobjinst_BuildActorDirectionTilt(char *);

extern f32 CPlane_GetSlopeAngle(Probe *, f32, f32, f32, f32);

extern void GraphU64_InterpolateQuaternionWithLinearFallback(CQuatern *, f32, CQuatern *, CQuatern *);

static inline s32 is_held(char *obj) {
    return (*(u8 *)obj != 1) ? 0 : (((LevelActor *)(obj))->flags & 1);
}

/* Plays a sound effect for an actor at a position: snaps the position to the nearest registered emitter
 * in D_8013B364 when there is one, draws a random direction and (except for sound 0xBD7) scales it to a
 * velocity of 409.6, then starts the sound through SetN64_SpawnModelEffect on D_80131600 with the actor's id and
 * the given volume. */








extern char D_8013B364;


extern s32 Portal_FindNearestPointIndex(void *, void *);

extern CVector3 *Portal_GetGraphPoint(void *, s32);

extern void GraphU64_ScaleVector(void *, void *, f32);

extern s32 SetN64_SpawnModelEffect(s32, s32, s32, CVector3, CVector3, s32, f32);


/* Callers write the lean through a pointer (the MIPS hidden result pointer); a native host cannot call a
 * struct-returning function that way, so the host entry takes the pointer and the body stays by value. */
CQuatern Insthdr_BuildActorGroundRotation(char *obj) {
    CVector3 normal;
    CVector3 up;
    CVector3 axis;
    CQuatern tilt;
    CQuatern lean;
    CQuatern result;
    Probe probe;
    f32 slope;
    f32 sine;
    f32 cosine;
    f32 angle;
    f32 half;
    char *self;

    if (((LevelActor *)(obj))->model != 0 && is_held(obj) == 0) {
        if (*(u8 *)obj == 1) {
            self = obj;
            if (((LevelActor *)(obj))->motionState & 3) {
                goto identity;
            }
            if (((LevelActor *)(obj))->flags & 0x300000) {
                if (Region_TestPolygonSlopeFlag(((LevelActor *)(obj))->model) != 0) {
                    goto identity;
                }
                Region_GetNodeNormal(&normal, ((LevelActor *)(obj))->model);
                up.x = 0.0f;
                up.y = 1.0f;
                up.z = 0.0f;
                Graphu64_CrossVectors(&axis, &up, &normal);
                GraphU64_NormalizeVec3(&axis);
                slope = GraphU64_ArcCos(up.x * normal.x + up.y * normal.y + up.z * normal.z);
                D_80115DEC = Math_Sinf(RW_MIN(slope, 0.43633235f) * 0.375f);
                tilt.x = axis.x * D_80115DEC;
                tilt.y = axis.y * D_80115DEC;
                tilt.z = axis.z * D_80115DEC;
                tilt.w = Math_Cosf(RW_MIN(slope, 0.43633235f) * 0.375f);
                tilt = Gobjinst_BuildActorDirectionTilt(obj);
                sine = Math_Sinf(((LevelActor *)(self))->yaw);
                cosine = Math_Cosf(((LevelActor *)(self))->yaw);
                probe.dir = ((LevelActor *)(self))->floorDirection;
                probe.start.x = ((LevelActor *)(self))->position0.x;
                probe.start.y = ((LevelActor *)(self))->floorHeight;
                probe.start.z = ((LevelActor *)(self))->position0.z;
                slope = CPlane_GetSlopeAngle(&probe, ((LevelActor *)(obj))->position0.x, ((LevelActor *)(obj))->position0.z, ((LevelActor *)(obj))->position0.x - sine,
                                      ((LevelActor *)(obj))->position0.z - cosine);
                slope = RW_MIN(slope, 25.0f) * 0.75f;
                half = 0.5f;
                angle = slope * half;
                D_80115DEC = Math_Sinf(angle);
                lean.y = 0.0f;
                lean.x = cosine * D_80115DEC;
                lean.z = -sine * D_80115DEC;
                lean.w = Math_Cosf(angle);
                GraphU64_InterpolateQuaternionWithLinearFallback(&result, half, &lean, &tilt);
                return result;
            }
        }
        return Gobjinst_BuildActorDirectionTilt(obj);
    }
identity:
    tilt.x = tilt.y = tilt.z = 0.0f;
    tilt.w = 1.0f;
    return tilt;
}

void Insthdr_PlayActorGraphSound(void *actor, CVector3 pos, s32 sound, f32 volume) {
    CVector3 up;
    CVector3 dir;
    CVector3 velocity;
    CVector3 at;
    SoundRequest request;
    CVector3 *emitter;

    emitter = Portal_GetGraphPoint(&D_8013B364, Portal_FindNearestPointIndex(&D_8013B364, &pos));
    request.position = pos;
    at = request.position;
    request.owner = ((struct Actor_func_80214DD4_de *)actor)->room;
    if (emitter != 0) {
        at = *emitter;
    }
    up.x = 0.0f;
    up.y = D_800C3CD0_de[1];
    up.z = 0.0f;
    dir.x = dir.y = dir.z = up.x;
    GraphU64_NormalizeVec3(&dir);
    if (sound != 0xBD7) {
        GraphU64_ScaleVector(&velocity, &dir, 409.59998f);
    }
    SetN64_SpawnModelEffect((s32)&D_80131600, 0, sound, velocity, at, request.owner, volume);
}

/** Reset three byte-sized fields. */
void Insthdr_ResetInstanceRenderIndices(signed char *prop) {
    prop[3] = -1;
    prop[1] = 0;
    prop[2] = 0;
}

s32 Insthdr_GetSharedModelFlag20(void *actorStorage)
{
    struct EffectOwnerObject *object = actorStorage;
    struct Model *model;
    s32 kind;

    model = (struct Model *)object->owner;
    kind = model->kind;
    if ((kind == 1) || (kind == 4)) {
        do { return model->flags & 0x20; } while (0);
    }
    return 0;
}

s32 Insthdr_GetSharedModelFlag40(void *actorStorage)
{
    struct EffectOwnerObject *object = actorStorage;
    struct Model *model;
    s32 kind;

    model = (struct Model *)object->owner;
    kind = model->kind;
    if ((kind == 1) || (kind == 4)) {
        if (model) {
            return model->flags & 0x40;
        } else {
            return model->flags & 0x40;
        }
    }
    return 0;
}

int Insthdr_GetModelPropertyFlag1(void *other) {
    Actor_u1 *actor = other;
    Resource_u1 *resource = actor->resource;
    unsigned int new_var = 0;
    if (resource->kind != 1) {
        return new_var;
    }
    if (new_var) {
        return resource->flags14 & 1;
    } else {
        return resource->flags14 & 1;
    }
}

int Insthdr_GetModelPropertyFlag2(void *actorStorage) {
    Actor_u1 *actor = actorStorage;
    Resource_u1 *resource = actor->resource;
    unsigned int new_var = 0;
    if (resource->kind != 1) {
        return new_var;
    }
    if (new_var) {
        return resource->flags14 & 2;
    } else {
        return resource->flags14 & 2;
    }
}

s32 Insthdr_GetSharedModelFlag80(void *actorStorage)
{
    struct EffectOwnerObject *object = actorStorage;
    struct Model *model;
    s32 kind;

    model = (struct Model *)object->owner;
    kind = model->kind;
    if ((kind == 1) || (kind == 4)) {
        if (model) {
            return model->flags & 0x80;
        } else {
            return model->flags & 0x80;
        }
    }
    return 0;
}

s32 Insthdr_GetSharedModelFlag100(void *actorStorage)
{
    struct EffectOwnerObject *object = actorStorage;
    struct Model *model;
    s32 kind;

    model = (struct Model *)object->owner;
    kind = model->kind;
    if ((kind == 1) || (kind == 4)) {
        do { return model->flags & 0x100; } while (0);
    }
    return 0;
}

int Insthdr_GetModelPropertyFlag200(void *actorStorage) {
    Actor_u1 *actor = actorStorage;
    Resource_u1 *resource = actor->resource;
    unsigned int new_var = 0;
    if (resource->kind != 1) {
        return new_var;
    }
    if (new_var) {
        return resource->flags14 & 0x200;
    } else {
        return resource->flags14 & 0x200;
    }
}

s32 Insthdr_HasActorTerritory(void *actorStorage)
{
    struct EffectOwnerObject *object = actorStorage;
    struct Model *model;
    s32 kind;

    model = (struct Model *)object->owner;
    kind = model->kind;
    if ((kind == 1) || (kind == 4)) {
        if (model) {
            return model->flags & 0x10;
        } else {
            return model->flags & 0x10;
        }
    }
    return 0;
}

s32 Insthdr_IsKindElevenEnabledForLocalMode(void *actorStorage) {
    void *actorDefinition;
    actorDefinition = (((struct ObjRecAt18V5 *) ((s8 *) actorStorage))->unk18);
    if ((((struct ObjRecAt14V3 *) ((s8 *) actorDefinition))->unk0) == 0xB) {
        if (D_801462C8.local != 0) {
            return (((struct ObjRecAt14V3 *) ((s8 *) actorDefinition))->unk14) & 1;
        }
        return 1;
    }
    return 0;
}

int Insthdr_GetModelCollisionFlag1(void *actorStorage) {
    Actor_u1 *actor = actorStorage;
    Resource_u1 *resource = actor->resource;
    unsigned int new_var = 0;
    if (resource->kind != 1) {
        return new_var;
    }
    if (new_var) {
        return resource->flags4C & 1;
    } else {
        return resource->flags4C & 1;
    }
}

s32 Insthdr_IsInactiveOrCollisionOption2(LevelActor *actor) {
    void *definition = actor->definition;
    s32 actorKind = ((ModelBlend *)definition)->kind;

    if (actorKind != 1) {
        if (actorKind != 0xB) {
            goto ret0;
        }
        return 1;
    }
    {
        s32 result = 0;
        if (actor->active <= 0 || (((ModelBlend *)definition)->collisionOptions & 2)) {
            result = 1;
        }
        return result;
    }
ret0:
    return 0;
}

s32 Insthdr_IsInactiveOrCollisionOption4(void *actor) {
    ModelBlend *modelBlend;
    s32 result;

    modelBlend = ((LevelActor *)actor)->definition;
    if (modelBlend->kind == 1) {
        result = 0;
        if (((LevelActor *)actor)->active <= 0 || (modelBlend->collisionOptions & 4)) {
            result = 1;
        }
        return result;
    }
    return 0;
}

int Insthdr_GetModelCollisionFlag8(void *actorStorage) {
    Actor_u1 *actor = actorStorage;
    Resource_u1 *resource = actor->resource;
    unsigned int new_var = 0;
    if (resource->kind != 1) {
        return new_var;
    }
    if (new_var) {
        return resource->flags4C & 8;
    } else {
        return resource->flags4C & 8;
    }
}

s32 Insthdr_IsInactiveOrCollisionOption800(LevelActor *actor) {
    ModelBlend *definition;
    s32 result;

    definition = actor->definition;
    if (definition->kind == 1) {
        result = 0;
        if (actor->active <= 0 || (definition->collisionOptions & 0x800)) {
            result = 1;
        }
        return result;
    }
    return 0;
}

s32 Insthdr_GetModelCollisionFlag1000(void *actorStorage)
{
    Actor_u1 *actor = actorStorage;
  unsigned int new_var;
  Resource_u1 *actorDefinition;
  actorDefinition = actor->resource;
  new_var = 0;
  if ((actorDefinition->kind) != 1)
  {
    return new_var;
  }
  if (new_var)
  {
    return (actorDefinition->flags4C) & 0x1000;
  }
  else
  {
    return (actorDefinition->flags4C) & 0x1000;
  }
}

s32 Insthdr_IsInactiveOrCollisionOption10(LevelActor *actor) {
    ModelBlend *definition;
    s32 result;

    definition = actor->definition;
    if (definition->kind == 1) {
        result = 0;
        if (actor->active <= 0 || (definition->collisionOptions & 0x10)) {
            result = 1;
        }
        return result;
    }
    return 0;
}

int Insthdr_GetModelCollisionFlag20(void *actorStorage) {
    Actor_u1 *actor = actorStorage;
    Resource_u1 *resource = actor->resource;
    unsigned int new_var = 0;
    if (resource->kind != 1) {
        return new_var;
    }
    if (new_var) {
        return resource->flags4C & 0x20;
    } else {
        return resource->flags4C & 0x20;
    }
}

s32 Insthdr_GetModelCollisionFlag200(void *actorStorage)
{
    Actor_u1 *actor = actorStorage;
  Resource_u1 *actorDefinition;
  int new_var;
  actorDefinition = actor->resource;
  new_var = 1;
  if ((actorDefinition->kind) != new_var)
  {
    return 0;
  }
  if (new_var)
  {
    return (actorDefinition->flags4C) & 0x200;
  }
}

int Insthdr_GetModelCollisionFlag400(void *actorStorage) {
    Actor_u1 *actor = actorStorage;
    Resource_u1 *resource = actor->resource;
    unsigned int new_var = 0;
    if (resource->kind != 1) {
        return new_var;
    }
    if (new_var) {
        return resource->flags4C & 0x400;
    } else {
        return resource->flags4C & 0x400;
    }
}

s32 Insthdr_GetModelCollisionFlag2000(void *actorStorage)
{
    Actor_u1 *actor = actorStorage;
  Resource_u1 *new_var2;
  int new_var;
  Resource_u1 *actorDefinition;
  actorDefinition = actor->resource;
  new_var2 = actorDefinition;
  if ((new_var2->kind) != 1)
  {
    if (actorDefinition || new_var)
    {
      return 0;
    }
    else
    {
      return 0;
    }
  }
  new_var = 0x4C;
  return (actorDefinition->flags4C) & 0x2000;
}

int Insthdr_GetModelCollisionFlag4000(void *actorStorage) {
    Actor_u1 *actor = actorStorage;
    Resource_u1 *resource = actor->resource;
    unsigned int new_var = 0;
    if (resource->kind != 1) {
        return new_var;
    }
    if (new_var) {
        return resource->flags4C & 0x4000;
    } else {
        return resource->flags4C & 0x4000;
    }
}
