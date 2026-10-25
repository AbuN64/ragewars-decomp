#include "include_asm.h"
#include "COMMON/LONE/D_8011AF38.H"
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
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/AIPROFILE.H"

extern void BuildDirectionMatrix(void *arg0, void *arg1);
extern f32 Anim_GetPolygonHeight(Node75 *node, f32 x, f32 z);
extern void Nav_GetPolygonUpQuat(void *arg0, s32 arg1);
extern void Nav_GetCachedUpQuat(void *arg0, s32 arg1);
extern void MatrixFromQuaternion(void *arg0, void *arg1);
extern void Rsp_MultiplyAffineMatrices(void *arg0, void *arg1, void *arg2);
extern f32 Anim_GetTriangleEdgeAngle(s32 arg0, s32 arg1);








/* Returns the matrix a particle's alignment places it in, or null for world space: the travel direction (-8),
 * the camera's billboards (-6 upright, -4 and -1 facing the screen), the ground basis D_8011AF38 (-5, and -3 when
 * off the ground) or the ground basis tilted to the floor (-3 on the ground, -2 cached), or turned to a floor
 * triangle edge (0..2). Built matrices go to the scratch matrix D_8011AD70. */
f32 *Particle_ParentTransform(Shared_Particle *particle, GameplayCamera *camera) {
    char output[0x40];
    char state[0x10];
    void *shared;
    f32 value;

    {
        s32 sw_state_value = (s8)(particle->space + 8);
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
        shared = D_8011AD70;
        BuildDirectionMatrix(shared, &particle->direction);
        return shared;
    sw_state_neg_6:
        if (camera == 0) {
            return 0;
        }
        return camera->faceScreenUpright;
    sw_state_neg_4:
    sw_state_neg_1:
        if (camera == 0) {
            return 0;
        }
        return camera->faceScreen;
    sw_state_neg_3:
        value = Anim_GetPolygonHeight(0, particle->inst.pos.x,
            particle->inst.pos.z);
        if (particle->inst.pos.y - value <= 0.01f) {
            Nav_GetPolygonUpQuat(state, 0);
            MatrixFromQuaternion(state, output);
            shared = D_8011AD70;
            Rsp_MultiplyAffineMatrices(shared, D_8011AF38, output);
            return shared;
        }
    sw_state_neg_5:
        return D_8011AF38;
    sw_state_neg_2:
        Nav_GetCachedUpQuat(state, 0);
        MatrixFromQuaternion(state, output);
        shared = D_8011AD70;
        Rsp_MultiplyAffineMatrices(shared, D_8011AF38, output);
        return shared;
    sw_state_0:
    sw_state_1:
    sw_state_2:
        value = Anim_GetTriangleEdgeAngle(0, particle->space);
        BuildYawMatrix(D_8011AD70, value);
        return D_8011AD70;
    sw_state_default:
        return 0;
    
    } while (0);
}

/* Refreshes a particle that rides something and returns its position and direction through optional pointers: a
 * particle riding a target (flag 0x10000) of one of the bone-mounted types takes its position and direction from
 * the target's draw matrix for its collision node (or just the target's position when the target has no draw
 * matrices) and clears its region; a particle carried by its owner (flag 0x400000) places its local position through
 * the owner's orientation, or for a player owner (flags 0x300000) through its camera's view orientation, or the
 * player view transform when the player has no camera. */
extern void Rsp_ConvertMatrixToFloat(f32 *dst, PackedMatrixWords *src);
extern void Particle_TransformDirection(void *matrix, CVector3 *in, CVector3 *out);
extern void Weapons_BuildPlayerViewTransform(Player *player, f32 out[4][4]);
void Particle_Attach(Shared_Particle *particle, CVector3 *outPosition, CVector3 *outDirection) {
    f32 matrix[16];
    CVector3 position;
    CVector3 direction;
    f32 viewTransform[4][4];
    Shared_ParticleTarget *target;
    Shared_ParticleOwner *owner;
    f32 *transform;
    PackedMatrixWords *drawMatrices;

    position = particle->inst.pos;
    direction = particle->inst.velocity;
    if (particle->flags & 0x10000) {
        target = particle->target;
        switch (particle->inst.type) {
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
                drawMatrices = target->drawMatrices;
                if (drawMatrices != 0) {
                    Rsp_ConvertMatrixToFloat(matrix, &drawMatrices[particle->collisionNode]);
                    Particle_TransformPoint(matrix, &particle->attachmentPosition, &position);
                    Particle_TransformDirection(matrix, &particle->inst.velocity, &direction);
                    particle->inst.pos = position;
                    particle->direction = direction;
                } else {
                    position = target->position;
                    particle->inst.pos = position;
                }
                break;
        }
        particle->inst.unk14 = 0;
    }
    if (particle->flags & 0x400000) {
        owner = particle->owner;
        if (owner->flags & 0x300000) {
            if (owner->player->camera != 0) {
                transform = owner->player->camera->viewOrient;
            } else {
                Weapons_BuildPlayerViewTransform(owner->player, viewTransform);
                transform = viewTransform[0];
            }
        } else {
            transform = owner->orient;
        }
        Particle_TransformPoint(transform, &particle->attachmentPosition, &position);
        particle->inst.pos = position;
    }
    if (outPosition != 0) {
        *outPosition = position;
    }
    if (outDirection != 0) {
        *outDirection = direction;
    }
}

#include "COMMON/MTX.H"
#include "TYPES.H"
#include "COMMON/APPROACHLOCATION.H"
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "COMMON/WORLD.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/MATH_HELPERS.H"
#include "particle/DEPTH_SCALE.H"

void Particle_CrossVectors(CVector3 *out, CVector3 *a, CVector3 *b);
void Particle_MatrixFromEulerXYZ(f32 *m, f32 x, f32 y, f32 z);
void Particle_IdentityMatrix(void *matrix);
void Engine_SampleWorldLighting(Shared_World *world, CVector3 *pos, struct Shared_ParticleLighting *out);
void BuildRollMatrix(void *matrix, f32 angle);
void TranslateMatrix(void *matrix, f32 x, f32 y, f32 z);
f32 Nav_GetTrianglePlaneHeight(void *node, f32 x, f32 z);
s32 Particle_LimitVectorLength(f32 *vector, f32 limit);
void ScaleMatrixLocal(void *matrix, f32 sx, f32 sy, f32 sz);
void SwapMatrixUpForward(void *matrix);
void CopyMatrix(f32 *dst, f32 *src);
void Particle_BuildTranslationMatrix(void *matrix, f32 x, f32 y, f32 z);
void YawMatrix(void *matrix, f32 angle);
void PitchMatrix(void *matrix, f32 angle);
void Particle_ClampMatrixToFixedRange(f32 *matrix);
void Rsp_ConvertMatrixToFixed(f32 *src, PackedMatrixWords *dst);



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
    Particle_Attach(particle, &position, &heading);
    if (!(particle->flags & 0x30000)) {
        ramp = particle->time;
        if (ramp > 0.0f) {
            rampTime = desc->sineWave->fadeInFrames;
            fade = 1.0f;
            if (rampTime != 0) {
                f32 rampLength = (f32)rampTime;
                if (ramp < rampLength) {
                    fade = ramp / rampLength;
                }
            }
            direction = particle->direction;
            if (particle->sineAmplitudeX < 0.0f) {
                up.x = 0;
                up.z = 0;
                up.y = 1.0f;
                Particle_CrossVectors(&side, &up, &direction);
                Particle_ScaleVector(&offset, &side, Math_Sinf(particle->sineAngleX) * -particle->sineAmplitudeX * fade);
                Particle_AddVec3(&position, &position, &offset);
            }
            if (particle->sineAmplitudeY < 0.0f) {
                up.x = 0;
                up.z = 0;
                up.y = 1.0f;
                Particle_CrossVectors(&across, &up, &direction);
                Particle_CrossVectors(&side, &across, &direction);
                Particle_ScaleVector(&offset, &side, Math_Sinf(particle->sineAngleY) * -particle->sineAmplitudeY * fade);
                Particle_AddVec3(&position, &position, &offset);
            }
        }
    }
    if (particle->desc->renderModel != 0) {
        if (particle->space == -7) {
            Particle_MatrixFromEulerXYZ(rotation, particle->rot.x + RW_PI_F6 / 2, particle->rot.y, particle->rot.z);
            if ((heading.x == 0.0f) && (heading.y == 0.0f) && (heading.z == 0.0f)) {
                axisZ = particle->direction;
            } else {
                axisZ = heading;
            }
            Particle_NormalizeVec3(&axisZ.x);
            up.x = 0;
            up.z = 0;
            up.y = 1.0f;
            Particle_CrossVectors(&axisX, &up, &axisZ);
            Particle_CrossVectors(&axisY, &axisX, &axisZ);
            Particle_IdentityMatrix(basis);
            Particle_NormalizeVec3(&axisX.x);
            Particle_NormalizeVec3(&axisY.x);
            Particle_NormalizeVec3(&axisZ.x);
            basis[0] = axisX.x;
            basis[1] = axisX.y;
            basis[2] = axisX.z;
            basis[4] = axisY.x;
            basis[5] = axisY.y;
            basis[6] = axisY.z;
            basis[8] = axisZ.x;
            basis[9] = axisZ.y;
            basis[10] = axisZ.z;
            Rsp_MultiplyAffineMatrices(local, rotation, basis);
        } else {
            Particle_MatrixFromEulerXYZ(local, particle->rot.x, particle->rot.y + RW_PI_F6, particle->rot.z);
        }
        Engine_SampleWorldLighting(&g_world, &particle->inst.pos, &particle->lighting[D_800D297C]);
    } else if ((particle->rot.x == 0.0f) && (particle->rot.y == 0.0f)) {
        BuildRollMatrix(local, particle->rot.z);
    } else {
        BuildRollMatrix(local, particle->rot.z);
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
        TranslateMatrixLocal(local, tiltX, -tiltY, 0.0f);
    }
    if (lift != 0.0f) {
        TranslateMatrixLocal(local, 0.0f, lift, 0.0f);
        TranslateMatrix(local, 0.0f, -lift, 0.0f);
    }
    particle->flags &= ~0x800000;
    switch (particle->space) {
    case -8:
        position.x += particle->direction.x * 5.12f;
        position.y += particle->direction.y * 5.12f;
        position.z += particle->direction.z * 5.12f;
        break;
    case -5:
        if (desc->wallBehavior != 0) {
            position.y = RW_MAX_GT(position.y, Anim_GetPolygonHeight(0, position.x, position.z) + 5.12f);
        }
        break;
    case -3:
        ground = Anim_GetPolygonHeight(0, position.x, position.z);
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
        if (desc->wallBehavior != 0) {
            position.y = RW_MIN_LT(position.y, Nav_GetTrianglePlaneHeight(0, position.x, position.z) - 5.12f);
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
    Particle_LimitVectorLength(&position.x, 20000.0f);
    if ((desc->flags & 0x80000) && (desc->playback == 1)) {
        scale = scale * (1.0f / 255.0f) * (f32)particle->opacity;
    }
    if (particle->desc->renderModel != 0) {
        type = particle->inst.type;
        extent = scale * particle->size.z * (35.0f / 1024.0f);
        if ((type == 0x40B) || (type == 0x40F) || (type == 0x41E) || (type == 0x40B) || (type == 0x436)) {
            ScaleMatrixLocal(local, -1.0f, -1.0f, -1.0f);
        }
        ScaleMatrixLocal(local, particle->size.x * extent, particle->size.y * extent, extent * 10.24f);
        SwapMatrixUpForward(local);
    } else {
        extent = scale * particle->size.z;
        ScaleMatrixLocal(local, particle->size.x * extent, particle->size.y * extent, extent * 10.24f);
    }
    parent = Particle_ParentTransform(particle, camera);
    if (parent != 0) {
        Rsp_MultiplyAffineMatrices(world, local, parent);
    } else {
        CopyMatrix(world, local);
    }
    TranslateMatrix(world, position.x, position.y, position.z);
    if ((particle->flags & 0x20000) && (shake = particle->quiver) != 0) {
        jolt = (f32)shake * (1.0f / 127.0f);
        joltSq = jolt * jolt;
        angle = joltSq * (RW_PI_F6 * 5 / 180);
        Particle_BuildTranslationMatrix(shakeMtx, 0.0f, 0.0f, -66.56f);
        YawMatrix(shakeMtx, angle * (Math_Sinf(joltSq * (6 * RW_PI_F6)) * 0.25f));
        PitchMatrix(shakeMtx, angle * Math_Sinf(joltSq * (14 * RW_PI_F6)));
        TranslateMatrix(shakeMtx, 0.0f, 0.0f, 66.56f);
        Rsp_MultiplyAffineMatrices(rotation, shakeMtx, world);
        Particle_ClampMatrixToFixedRange(rotation);
        final = rotation;
    } else {
        Particle_ClampMatrixToFixedRange(world);
        final = world;
    }
    Rsp_ConvertMatrixToFixed(final, out);
}
