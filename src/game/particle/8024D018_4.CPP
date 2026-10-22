#include "COMMON/PROBE.H"
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
#include "FX_2/80271B18.H"

/* Returns a player's body lean on the ground: a controlled player on an accepted floor (func_802757E4_de) that
 * is not held (flag 1) nor in states 1 or 2 computes a tilt toward the floor normal from func_80275C94_de by
 * three eighths of its slope (at most 25 degrees), which the body tilt from func_8024D728_de then replaces,
 * and leans along its heading by three quarters of the ground slope ahead from func_80240A98_de (at most 25),
 * blending lean and tilt halfway through func_80270CD0_de; other players take func_8024D728_de's tilt, and
 * objects without a floor or held players get the identity. The sine is kept in D_80115DEC. */

extern f32 D_80115DEC;

extern s32 func_802757E4_de(s32);

extern void func_80275C94_de(CVector3 *, s32);

extern void func_80272018_de(CVector3 *, CVector3 *, CVector3 *);


extern CQuatern func_8024D728_de(char *);

extern f32 func_80240A98_de(Probe *, f32, f32, f32, f32);

extern void func_80270CD0_de(CQuatern *, f32, CQuatern *, CQuatern *);

static inline s32 is_held(char *obj) {
    return (*(u8 *)obj != 1) ? 0 : (((LevelActor *)(obj))->flags & 1);
}

/* Plays a sound effect for an actor at a position: snaps the position to the nearest registered emitter
 * in D_8013B364 when there is one, draws a random direction and (except for sound 0xBD7) scales it to a
 * velocity of 409.6, then starts the sound through func_8028FFD0_de on D_80131600 with the actor's id and
 * the given volume. */







extern char D_80131600;

extern char D_8013B364;

extern f32 D_800C3CD0_de[];

extern s32 func_8020CB3C_de(void *, void *);

extern CVector3 *func_8020C994_de(void *, s32);

extern void func_80271F9C_de(void *, void *, f32);

extern s32 func_8028FFD0_de(s32, s32, s32, CVector3, CVector3, s32, f32);

extern u8 D_801462E5;

CQuatern func_8024D870_de(char *obj) {
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
                if (func_802757E4_de(((LevelActor *)(obj))->model) != 0) {
                    goto identity;
                }
                func_80275C94_de(&normal, ((LevelActor *)(obj))->model);
                up.x = 0.0f;
                up.y = 1.0f;
                up.z = 0.0f;
                func_80272018_de(&axis, &up, &normal);
                func_8027207C_de(&axis);
                slope = func_802745D0_de(up.x * normal.x + up.y * normal.y + up.z * normal.z);
                D_80115DEC = func_802B7130_de(RW_MIN(slope, 0.43633235f) * 0.375f);
                tilt.x = axis.x * D_80115DEC;
                tilt.y = axis.y * D_80115DEC;
                tilt.z = axis.z * D_80115DEC;
                tilt.w = func_802B6560_de(RW_MIN(slope, 0.43633235f) * 0.375f);
                tilt = func_8024D728_de(obj);
                sine = func_802B7130_de(((LevelActor *)(self))->yaw);
                cosine = func_802B6560_de(((LevelActor *)(self))->yaw);
                probe.dir = ((LevelActor *)(self))->floorDirection;
                probe.start.x = ((LevelActor *)(self))->position0.x;
                probe.start.y = ((LevelActor *)(self))->floorHeight;
                probe.start.z = ((LevelActor *)(self))->position0.z;
                slope = func_80240A98_de(&probe, ((LevelActor *)(obj))->position0.x, ((LevelActor *)(obj))->position0.z, ((LevelActor *)(obj))->position0.x - sine,
                                      ((LevelActor *)(obj))->position0.z - cosine);
                slope = RW_MIN(slope, 25.0f) * 0.75f;
                half = 0.5f;
                angle = slope * half;
                D_80115DEC = func_802B7130_de(angle);
                lean.y = 0.0f;
                lean.x = cosine * D_80115DEC;
                lean.z = -sine * D_80115DEC;
                lean.w = func_802B6560_de(angle);
                func_80270CD0_de(&result, half, &lean, &tilt);
                return result;
            }
        }
        return func_8024D728_de(obj);
    }
identity:
    tilt.x = tilt.y = tilt.z = 0.0f;
    tilt.w = 1.0f;
    return tilt;
}

void func_8024DBC0_de(void *actor, CVector3 pos, s32 sound, f32 volume) {
    CVector3 up;
    CVector3 dir;
    CVector3 velocity;
    CVector3 at;
    SoundRequest request;
    CVector3 *emitter;

    emitter = func_8020C994_de(&D_8013B364, func_8020CB3C_de(&D_8013B364, &pos));
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
    func_8027207C_de(&dir);
    if (sound != 0xBD7) {
        func_80271F9C_de(&velocity, &dir, 409.59998f);
    }
    func_8028FFD0_de((s32)&D_80131600, 0, sound, velocity, at, request.owner, volume);
}

/** Reset three byte-sized fields. */
void func_8024DD10_de(signed char *arg0) {
    arg0[3] = -1;
    arg0[1] = 0;
    arg0[2] = 0;
}

s32 func_8024DD24_de(void *arg0)
{
    struct Object *object = arg0;
    struct Model *model;
    s32 kind;

    model = (struct Model *)object->owner;
    kind = model->kind;
    if ((kind == 1) || (kind == 4)) {
        do { return model->flags & 0x20; } while (0);
    }
    return 0;
}

s32 func_8024DD58_de(void *arg0)
{
    struct Object *object = arg0;
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

int func_8024DD8C_de(void *arg0) {
    Actor_u1 *actor = arg0;
    Resource_u1 *temp_a0 = actor->resource;
    unsigned int new_var = 0;
    if (temp_a0->kind != 1) {
        return new_var;
    }
    if (new_var) {
        return temp_a0->flags14 & 1;
    } else {
        return temp_a0->flags14 & 1;
    }
}

int func_8024DDB4_de(void *arg0) {
    Actor_u1 *actor = arg0;
    Resource_u1 *temp_a0 = actor->resource;
    unsigned int new_var = 0;
    if (temp_a0->kind != 1) {
        return new_var;
    }
    if (new_var) {
        return temp_a0->flags14 & 2;
    } else {
        return temp_a0->flags14 & 2;
    }
}

s32 func_8024DDDC_de(void *arg0)
{
    struct Object *object = arg0;
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

s32 func_8024DE10_de(void *arg0)
{
    struct Object *object = arg0;
    struct Model *model;
    s32 kind;

    model = (struct Model *)object->owner;
    kind = model->kind;
    if ((kind == 1) || (kind == 4)) {
        do { return model->flags & 0x100; } while (0);
    }
    return 0;
}

int func_8024DE44_de(void *arg0) {
    Actor_u1 *actor = arg0;
    Resource_u1 *temp_a0 = actor->resource;
    unsigned int new_var = 0;
    if (temp_a0->kind != 1) {
        return new_var;
    }
    if (new_var) {
        return temp_a0->flags14 & 0x200;
    } else {
        return temp_a0->flags14 & 0x200;
    }
}

s32 func_8024DE6C_de(void *arg0)
{
    struct Object *object = arg0;
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

s32 func_8024DEA0_de(void *arg0) {
    void *temp_a0;
    temp_a0 = (((struct ObjRecAt18V5 *) ((s8 *) arg0))->unk18);
    if ((((struct ObjRecAt14V3 *) ((s8 *) temp_a0))->unk0) == 0xB) {
        if (D_801462E5 != 0) {
            return (((struct ObjRecAt14V3 *) ((s8 *) temp_a0))->unk14) & 1;
        }
        return 1;
    }
    return 0;
}

int func_8024DEE0_de(void *arg0) {
    Actor_u1 *actor = arg0;
    Resource_u1 *temp_a0 = actor->resource;
    unsigned int new_var = 0;
    if (temp_a0->kind != 1) {
        return new_var;
    }
    if (new_var) {
        return temp_a0->flags4C & 1;
    } else {
        return temp_a0->flags4C & 1;
    }
}

s32 func_8024DF08_de(LevelActor *arg0) {
    void *temp_a1 = arg0->definition;
    s32 temp_v1 = ((ModelBlend *)temp_a1)->kind;

    if (temp_v1 != 1) {
        if (temp_v1 != 0xB) {
            goto ret0;
        }
        return 1;
    }
    {
        s32 var_v1 = 0;
        if (arg0->active <= 0 || (((ModelBlend *)temp_a1)->collisionOptions & 2)) {
            var_v1 = 1;
        }
        return var_v1;
    }
ret0:
    return 0;
}

s32 func_8024DF5C_de(void *arg0) {
    ModelBlend *temp_a1;
    s32 var_v1;

    temp_a1 = ((LevelActor *)arg0)->definition;
    if (temp_a1->kind == 1) {
        var_v1 = 0;
        if (((LevelActor *)arg0)->active <= 0 || (temp_a1->collisionOptions & 4)) {
            var_v1 = 1;
        }
        return var_v1;
    }
    return 0;
}

int func_8024DFA0_de(void *arg0) {
    Actor_u1 *actor = arg0;
    Resource_u1 *temp_a0 = actor->resource;
    unsigned int new_var = 0;
    if (temp_a0->kind != 1) {
        return new_var;
    }
    if (new_var) {
        return temp_a0->flags4C & 8;
    } else {
        return temp_a0->flags4C & 8;
    }
}

s32 func_8024DFC8_de(LevelActor *arg0) {
    ModelBlend *temp_a1;
    s32 var_v1;

    temp_a1 = arg0->definition;
    if (temp_a1->kind == 1) {
        var_v1 = 0;
        if (arg0->active <= 0 || (temp_a1->collisionOptions & 0x800)) {
            var_v1 = 1;
        }
        return var_v1;
    }
    return 0;
}

s32 func_8024E00C_de(void *arg0)
{
    Actor_u1 *actor = arg0;
  unsigned int new_var;
  Resource_u1 *temp_a0;
  temp_a0 = actor->resource;
  new_var = 0;
  if ((temp_a0->kind) != 1)
  {
    return new_var;
  }
  if (new_var)
  {
    return (temp_a0->flags4C) & 0x1000;
  }
  else
  {
    return (temp_a0->flags4C) & 0x1000;
  }
}

s32 func_8024E034_de(LevelActor *arg0) {
    ModelBlend *temp_a1;
    s32 var_v1;

    temp_a1 = arg0->definition;
    if (temp_a1->kind == 1) {
        var_v1 = 0;
        if (arg0->active <= 0 || (temp_a1->collisionOptions & 0x10)) {
            var_v1 = 1;
        }
        return var_v1;
    }
    return 0;
}

int func_8024E078_de(void *arg0) {
    Actor_u1 *actor = arg0;
    Resource_u1 *temp_a0 = actor->resource;
    unsigned int new_var = 0;
    if (temp_a0->kind != 1) {
        return new_var;
    }
    if (new_var) {
        return temp_a0->flags4C & 0x20;
    } else {
        return temp_a0->flags4C & 0x20;
    }
}

s32 func_8024E0A0_de(void *arg0)
{
    Actor_u1 *actor = arg0;
  Resource_u1 *temp_a0;
  int new_var;
  temp_a0 = actor->resource;
  new_var = 1;
  if ((temp_a0->kind) != new_var)
  {
    return 0;
  }
  if (new_var)
  {
    return (temp_a0->flags4C) & 0x200;
  }
}

int func_8024E0C8_de(void *arg0) {
    Actor_u1 *actor = arg0;
    Resource_u1 *temp_a0 = actor->resource;
    unsigned int new_var = 0;
    if (temp_a0->kind != 1) {
        return new_var;
    }
    if (new_var) {
        return temp_a0->flags4C & 0x400;
    } else {
        return temp_a0->flags4C & 0x400;
    }
}

s32 func_8024E0F0_de(void *arg0)
{
    Actor_u1 *actor = arg0;
  Resource_u1 *new_var2;
  int new_var;
  Resource_u1 *temp_a0;
  temp_a0 = actor->resource;
  new_var2 = temp_a0;
  if ((new_var2->kind) != 1)
  {
    if (temp_a0 || new_var)
    {
      return 0;
    }
    else
    {
      return 0;
    }
  }
  new_var = 0x4C;
  return (temp_a0->flags4C) & 0x2000;
}

int func_8024E118_de(void *arg0) {
    Actor_u1 *actor = arg0;
    Resource_u1 *temp_a0 = actor->resource;
    unsigned int new_var = 0;
    if (temp_a0->kind != 1) {
        return new_var;
    }
    if (new_var) {
        return temp_a0->flags4C & 0x4000;
    } else {
        return temp_a0->flags4C & 0x4000;
    }
}
