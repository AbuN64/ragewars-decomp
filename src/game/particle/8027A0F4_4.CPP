#include "include_asm.h"
#include "COMMON/GAMEPLAY_ROUND_RULES.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "TYPES.H"
#include "GAME/CODE_8027302C.H"
#include "FX_2/80271B18.H"
#include "particle/80271B18_3.H"
#include "particle/8027A0F4_4.H"

extern char D_8011AD70;
extern char D_8011AF38;
extern f32 D_800C4C64_de;
extern void func_80273198_de(void *arg0, void *arg1);
extern f32 func_80275DD4_de(Node75 *node, f32 x, f32 z);
extern void func_80275410_de(void *arg0, s32 arg1);
extern void func_80275688_de(void *arg0, s32 arg1);
extern void func_80274244_de(void *arg0, void *arg1);
extern void func_8026F620_de(void *arg0, void *arg1, void *arg2);
extern f32 func_802760BC_de(s32 arg0, s32 arg1);








/** Resolve the shared effect object selected by the actor state. */
void *Particle_ParentTransform(EffectActor *arg0, Shared_ActorView *arg1) {
    char output[0x40];
    char state[0x10];
    void *shared;
    f32 value;

    {
        s32 sw_state_value = (s8)(arg0->unk1D0 + 8);
        if ((unsigned int)sw_state_value > 10) {
            goto sw_state_default;
        }
        switch (sw_state_value) {
        case 0: goto sw_state_neg_8;
        case 1: goto sw_state_default;
        case 2: goto sw_state_neg_6;
        case 3: goto sw_state_neg_5;
        case 4: goto sw_state_neg_4;
        case 5: goto sw_state_neg_3;
        case 6: goto sw_state_neg_2;
        case 7: goto sw_state_neg_4;
        case 8: goto sw_state_0;
        case 9: goto sw_state_0;
        case 10: goto sw_state_0;
        }
    }
    do {
    sw_state_neg_8:
        shared = &D_8011AD70;
        func_80273198_de(shared, (char *)arg0 + 0x174);
        return shared;
    sw_state_neg_6:
        if (arg1 == 0) {
            return 0;
        }
        return arg1->effectOffsetTransform;
    sw_state_neg_4:
    sw_state_neg_1:
        if (arg1 == 0) {
            return 0;
        }
        return arg1->effectTransform;
    sw_state_neg_3:
        value = func_80275DD4_de(0, arg0->pos.x,
            arg0->pos.z);
        if (arg0->pos.y - value <= D_800C4C64_de) {
            func_80275410_de(state, 0);
            func_80274244_de(state, output);
            shared = &D_8011AD70;
            func_8026F620_de(shared, &D_8011AF38, output);
            return shared;
        }
    sw_state_neg_5:
        return &D_8011AF38;
    sw_state_neg_2:
        func_80275688_de(state, 0);
        func_80274244_de(state, output);
        shared = &D_8011AD70;
        func_8026F620_de(shared, &D_8011AF38, output);
        return shared;
    sw_state_0:
    sw_state_1:
    sw_state_2:
        value = func_802760BC_de(0, arg0->unk1D0);
        func_802736D4_de(&D_8011AD70, value);
        return &D_8011AD70;
    sw_state_default:
        return 0;
    
    } while (0);
}

/* Refreshes an attached actor's placement and returns its position and heading through optional pointers: an actor flagged 0x10000 of one of the bone-mounted types takes its position and heading from its parent's bone matrix (or just the parent's position when the parent has no skeleton) and clears its field 0x14, and an actor flagged 0x400000 places its local offset through its owner's transform (the owner's model matrix for owners flagged 0x300000, built through func_80226DD0_de when missing). */









extern void func_80270910_de(f32 *out, void *in);
extern void func_80272B38_de(void *matrix, CVector3 *in, CVector3 *out);
extern void func_80226DD0_de(func_80228774_S5 *model, f32 *out);




void Particle_Attach(Actor_func_8027DAD0_de *actor, CVector3 *outPosition, CVector3 *outHeading) {
    f32 matrix[16];
    CVector3 position;
    CVector3 heading;
    f32 built[16];
    Parent *parent;
    Parent *owner;
    void *transform;
    void *skeleton;

    position = actor->position;
    heading = actor->heading;
    if (actor->flags & 0x10000) {
        parent = actor->parent;
        switch (actor->type) {
            case 2:
            case 0xB:
            case 0xF:
            case 0x2D:
            case 0x4F:
            case 0x56:
            case 0x126:
            case 0x12A:
            case 0x132:
            case 0x41E:
                skeleton = parent->skeleton;
                if (skeleton != 0) {
                    func_80270910_de(matrix, (char *)skeleton + actor->bone * 64);
                    func_80272898_de(matrix, &actor->offset, &position);
                    func_80272B38_de(matrix, &actor->heading, &heading);
                    actor->position = position;
                    actor->facing = heading;
                } else {
                    position = parent->position;
                    actor->position = position;
                }
                break;
        }
        actor->unk14 = 0;
    }
    if (actor->flags & 0x400000) {
        owner = actor->owner;
        if (owner->flags & 0x300000) {
            if (owner->model->unk5DC != 0) {
                transform = ((SharedRecAt564V1 *)owner->model->unk5DC)->transform;
            } else {
                func_80226DD0_de(owner->model, built);
                transform = built;
            }
        } else {
            transform = owner->transform;
        }
        func_80272898_de(transform, &actor->offset, &position);
        actor->position = position;
    }
    if (outPosition != 0) {
        *outPosition = position;
    }
    if (outHeading != 0) {
        *outHeading = heading;
    }
}

#ifdef NON_MATCHING
#include "COMMON/MTX.H"
#include "TYPES.H"
#include "COMMON/APPROACHLOCATION.H"
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "COMMON/WORLD.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/MATH_HELPERS.H"

void func_80272018_de(CVector3 *out, CVector3 *a, CVector3 *b);
void func_80272E3C_de(f32 *m, f32 x, f32 y, f32 z);
void func_802727D8_de(void *matrix);
void func_8028C6D4_de(Shared_World *world, CVector3 *pos, struct Shared_ParticleLighting *out);
void func_80273760_de(void *matrix, f32 angle);
void func_80273448_de(void *matrix, f32 x, f32 y, f32 z);
f32 func_8027525C_de(void *node, f32 x, f32 z);
s32 func_8027254C_de(f32 *vector, f32 limit);
void func_8027347C_de(void *matrix, f32 sx, f32 sy, f32 sz);
void func_80273D6C_de(void *matrix);
void func_8027302C(f32 *dst, f32 *src);
void func_80272C60_de(void *matrix, f32 x, f32 y, f32 z);
void func_80273A98_de(void *matrix, f32 angle);
void func_802738C0_de(void *matrix, f32 angle);
void func_80272828_de(f32 *matrix);
void func_8027027C_de(f32 *src, PackedMatrixWords *dst);



/* 640/655 aligned words; remaining: depth-clamp floating register allocation. */
static inline f32 particleDepthScale(struct Shared_ParticleDesc *desc, f32 depth) {
    f32 near;
    f32 farness;
    f32 size;

    if (desc->flags & 4) {
        size = depth;
        near = size - 16.0f;
        farness = RW_MIN_LT(1.0f, RW_MAX_GT(0.0f, near) * (1.0f / 2032.0f));
        size = depth * (desc->distanceRange->minimum + (desc->distanceRange->maximum - desc->distanceRange->minimum) * farness);
        depth = size * 0.001f;
    } else {
        depth = 1.0f;
    }
    return depth;
}

/* Builds a particle's display matrix: its size scaled for camera depth and field of view, its wobble, its
 * orientation (model particles) or roll (sprites), its placement for the space it lives in, and an optional
 * decaying shake, then packs the result into the fixed-point matrix the display list loads. */
void Particle_BuildMatrix(Shared_Particle *particle, PackedMatrixWords *out, GameplayCamera *camera, f32 depth) {
    f32 rotation[16], basis[16], local[16], world[16], shakeMtx[16];
    CVector3 position;
    CVector3 up;
    CVector3 heading;
    CVector3 axisX;
    CVector3 axisY;
    CVector3 axisZ;
    CVector3 across;
    CVector3 side;
    CVector3 direction;
    CVector3 offset;
    struct Shared_ParticleDesc *desc;
    f32 *parent;
    f32 *final;
    f32 scale;
    f32 lift;
    f32 depthScale;
    f32 ramp;
    f32 fade;
    f32 ground;
    f32 rest;
    f32 extent;
    f32 size;
    f32 jolt;
    f32 joltSq;
    f32 angle;
    f32 tiltX;
    f32 tiltY;
    f32 fov;
    s32 rampTime;
    s32 shake;
    s32 model;
    u16 type;

    desc = particle->desc;
    if (camera != 0) {
        depthScale = particleDepthScale(particle->desc, depth);
        fov = camera->fovY;
        scale = depthScale * (1.0f / 47.5f) * (fov + (47.5f - fov) * 0.25f);
    } else {
        scale = 1.0f;
    }
    if (desc->flags & 8) {
        lift = particle->size.y * particle->size.z * scale;
    } else {
        lift = 0.0f;
    }
    Particle_Attach((struct Actor_func_8027DAD0_de *)particle, &position, &heading);
    if (!(particle->flags & 0x30000)) {
        ramp = particle->time;
        if (ramp > 0.0f) {
            rampTime = desc->oscillation->ramp;
            fade = 1.0f;
            if (rampTime != 0) {
                f32 rampLength = (f32)rampTime;
                if (ramp < rampLength) {
                    fade = ramp / rampLength;
                }
            }
            direction = particle->direction;
            if (particle->amplitudeA < 0.0f) {
                up.x = 0;
                up.z = 0;
                up.y = 1.0f;
                func_80272018_de(&side, &up, &direction);
                func_80271F9C_de(&offset, &side, func_802B7130_de(particle->phaseA) * -particle->amplitudeA * fade);
                func_80271F34_de(&position, &position, &offset);
            }
            if (particle->amplitudeB < 0.0f) {
                up.x = 0;
                up.z = 0;
                up.y = 1.0f;
                func_80272018_de(&across, &up, &direction);
                func_80272018_de(&side, &across, &direction);
                func_80271F9C_de(&offset, &side, func_802B7130_de(particle->phaseB) * -particle->amplitudeB * fade);
                func_80271F34_de(&position, &position, &offset);
            }
        }
    }
    if (particle->desc->renderModel != 0) {
        if (particle->space == -7) {
            func_80272E3C_de(rotation, particle->rot.x + RW_PI_F6 / 2, particle->rot.y, particle->rot.z);
            if ((heading.x == 0.0f) && (heading.y == 0.0f) && (heading.z == 0.0f)) {
                axisZ = particle->direction;
            } else {
                axisZ = heading;
            }
            func_8027207C_de(&axisZ.x);
            up.x = 0;
            up.z = 0;
            up.y = 1.0f;
            func_80272018_de(&axisX, &up, &axisZ);
            func_80272018_de(&axisY, &axisX, &axisZ);
            func_802727D8_de(basis);
            func_8027207C_de(&axisX.x);
            func_8027207C_de(&axisY.x);
            func_8027207C_de(&axisZ.x);
            basis[0] = axisX.x;
            basis[1] = axisX.y;
            basis[2] = axisX.z;
            basis[4] = axisY.x;
            basis[5] = axisY.y;
            basis[6] = axisY.z;
            basis[8] = axisZ.x;
            basis[9] = axisZ.y;
            basis[10] = axisZ.z;
            func_8026F620_de(local, rotation, basis);
        } else {
            func_80272E3C_de(local, particle->rot.x, particle->rot.y + RW_PI_F6, particle->rot.z);
        }
        func_8028C6D4_de(&D_8011FE88, &particle->inst.pos, &particle->lighting[D_800D297C]);
    } else if ((particle->rot.x == 0.0f) && (particle->rot.y == 0.0f)) {
        func_80273760_de(local, particle->rot.z);
    } else {
        func_80273760_de(local, particle->rot.z);
        model = particle->desc->renderModel;
        tiltX = 0.0f;
        if (model == 0) {
            tiltX = particle->rot.x;
        }
        tiltX = -tiltX;
        tiltY = 0.0f;
        if (model == 0) {
            tiltY = particle->rot.y;
        }
        func_802733B4_de(local, tiltX, -tiltY, 0.0f);
    }
    if (lift != 0.0f) {
        func_802733B4_de(local, 0.0f, lift, 0.0f);
        func_80273448_de(local, 0.0f, -lift, 0.0f);
    }
    particle->flags &= ~0x800000;
    switch (particle->space) {
    case -8:
        position.x += particle->direction.x * 5.12f;
        position.y += particle->direction.y * 5.12f;
        position.z += particle->direction.z * 5.12f;
        break;
    case -5:
        if (desc->clampToGround != 0) {
            position.y = RW_MAX_GT(position.y, func_80275DD4_de(0, position.x, position.z) + 5.12f);
        }
        break;
    case -3:
        ground = func_80275DD4_de(0, position.x, position.z);
        if (desc->flags & 0x400) {
            if (position.y < ground + 1.024f) {
                position.y = ground;
                particle->flags |= 0x800000;
            }
        } else {
            rest = ground + 5.12f;
            position.y = (position.y <= rest) ? rest : position.y;
        }
        break;
    case -2:
        if (desc->clampToGround != 0) {
            position.y = RW_MIN_LT(position.y, func_8027525C_de(0, position.x, position.z) - 5.12f);
        }
        break;
    case -6:
    case -4:
    case -1:
        position.y += lift;
        break;
    case -7:
    case 0:
    case 1:
    case 2:
        break;
    }
    func_8027254C_de(&position.x, 20000.0f);
    if ((desc->flags & 0x80000) && (desc->animMode == 1)) {
        scale = scale * (1.0f / 255.0f) * (f32)particle->opacity;
    }
    if (particle->desc->renderModel != 0) {
        type = particle->inst.type;
        extent = scale * particle->size.z * (35.0f / 1024.0f);
        if ((type == 0x40B) || (type == 0x40F) || (type == 0x41E) || (type == 0x40B) || (type == 0x436)) {
            func_8027347C_de(local, -1.0f, -1.0f, -1.0f);
        }
        func_8027347C_de(local, particle->size.x * extent, particle->size.y * extent, extent * 10.24f);
        func_80273D6C_de(local);
    } else {
        extent = scale * particle->size.z;
        func_8027347C_de(local, particle->size.x * extent, particle->size.y * extent, extent * 10.24f);
    }
    parent = Particle_ParentTransform((EffectActor *)particle, (Shared_ActorView *)camera);
    if (parent != 0) {
        func_8026F620_de(world, local, parent);
    } else {
        func_8027302C(world, local);
    }
    func_80273448_de(world, position.x, position.y, position.z);
    if ((particle->flags & 0x20000) && (shake = particle->shake) != 0) {
        jolt = (f32)shake * (1.0f / 127.0f);
        joltSq = jolt * jolt;
        angle = joltSq * (RW_PI_F6 * 5 / 180);
        func_80272C60_de(shakeMtx, 0.0f, 0.0f, -66.56f);
        func_80273A98_de(shakeMtx, angle * (func_802B7130_de(joltSq * (6 * RW_PI_F6)) * 0.25f));
        func_802738C0_de(shakeMtx, angle * func_802B7130_de(joltSq * (14 * RW_PI_F6)));
        func_80273448_de(shakeMtx, 0.0f, 0.0f, 66.56f);
        func_8026F620_de(rotation, shakeMtx, world);
        func_80272828_de(rotation);
        final = rotation;
    } else {
        func_80272828_de(world);
        final = world;
    }
    func_8027027C_de(final, out);
}
#else
INCLUDE_ASM("span_1000", Particle_BuildMatrix);
#endif
