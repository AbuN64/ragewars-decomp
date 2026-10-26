#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "COMMON/TRIPLE.H"
#include "particle/8027A0F4.H"
#include "FX_2/80271B18.H"
#include "particle/80271B18_3.H"

extern s32 *func_8025CC6C_de(void);
extern s32 func_8025CA24_de(void *,void *);
static inline void makeImpulse(CVector3 *input,f32 scale,CVector3 *out){GraphU64_ScaleVector(out,input,scale);}
static inline void addImpulse(CVector3 *v,CVector3 *impulse){GraphU64_AddVec3(v,v,impulse);}
void Particle_SteerSoundTrackingParticle(void *particle) {
    SteeringParticle *arg0=particle;
    CVector3 sp18;
    CVector3 sp28;
    CVector3 sp38;
    CQuatern sp48;
    CQuatern sp58;
    CQuatern sp68;
    Matrix sp78;
    CVector3 spB8;
    CVector3 spC8;
    CVector3 *temp_s0_3;
    CVector3 *temp_s2;
    CVector3 *temp_s4;
    f32 temp_fa0;
    f32 temp_fa0_2;
    f32 temp_fs0;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 scale;
    f32 temp_fv0_4;
    f32 temp_fv0_5;
    f32 temp_fv0f;
    f32 temp_fv0f_2;
    f32 temp_fv0f_3;
    f32 amount;
    
    s32 var_condition_bit;s32 id;
    CVector3 *temp_a2;
    SteeringTarget *target;
    CVector3 *temp_s0_2;
    SteeringSound *sound;

    if (arg0->flags & 0x10000) {
        if (arg0->sound != 0) {
            func_8025CA24_de(func_8025CC6C_de(), arg0->sound);
            arg0->sound = 0;
        }
    } else {
        id=0x730;sound = arg0->sound;
        if (sound != 0) {
            if ((sound->id != id) || (sound->handle == -1)) {
                Particle_StopSound(arg0);
                goto block_7;
            }
        } else {
block_7:
            arg0->sound = func_8025C95C_de(func_8025CC6C_de(), 0x730, &arg0->position, &arg0->position, -1);
        }
        target = arg0->target;
        if ((target != 0) && (arg0->time > D_800C4B4C_de)) {
            temp_s2 = &arg0->direction;
            sp48 = GraphU64_BuildDirectionQuaternion(temp_s2);
            temp_fv0f = arg0->velocity.x;
            temp_fv0 = arg0->velocity.y;
            temp_fa0 = arg0->velocity.z;
            temp_fv0_2 = Math_Sqrtf((temp_fv0f * temp_fv0f) + (temp_fv0 * temp_fv0) + (temp_fa0 * temp_fa0));
            
            sp18 = target->position;
            GraphU64_SubtractVectors(&sp28, &sp18, &arg0->position);
            amount = Math_Sqrtf((sp28.x * sp28.x) + (sp28.y * sp28.y) + (sp28.z * sp28.z));
            if (amount < D_800C4B50_de) {
                sp68 = GraphU64_BuildDirectionQuaternion(&sp28);
                MatrixFromQuaternion(&sp68.x, sp78.m);
                sp38.x = 0;
                sp38.y = 0;
                sp38.z = D_800C4B54_de;
                GraphU64_TransformPoint(&sp78, &sp38, temp_s2);
                GraphU64_ScaleVector(&arg0->velocity, temp_s2, temp_fv0_2);
                return;
            }
            if (D_800C4B58_de < amount) {
                sp18.y += D_800C4B50_de;
                GraphU64_SubtractVectors(&sp28, &sp18, &arg0->position);
                amount = Math_Sqrtf((sp28.x * sp28.x) + (sp28.y * sp28.y) + (sp28.z * sp28.z));
            }
            GraphU64_NormalizeVec3(&sp28.x);
            sp58 = GraphU64_BuildDirectionQuaternion(&sp28);
            if (amount < D_800C4B5C_de) {
                temp_fv0f_2 = amount - D_800C4B60_de;
                if (temp_fv0f_2 < 0.0f) {
                    amount = 0.0f;
                } else {
                    amount = temp_fv0f_2 * D_800C4B64_de;
                }
                amount = D_800C4B6C_de - (amount * D_800C4B68_de);
            } else {
                amount = D_800C4B70_de;
            }
            GraphU64_NormalizeQuaternion(&sp58.x);
            GraphU64_NormalizeQuaternion(&sp48.x);
            GraphU64_InterpolateQuaternionWithLinearFallback(&sp68, amount, &sp48, &sp58);
            MatrixFromQuaternion(&sp68.x, sp78.m);
            temp_s0_2 = &arg0->direction;
            sp38.x = 0;
            sp38.y = 0;
            sp38.z = D_800C4B74_de;
            GraphU64_TransformPoint(&sp78, &sp38, temp_s0_2);
            GraphU64_ScaleVector(&arg0->velocity, temp_s0_2, temp_fv0_2);
            goto block_21;
        }
block_21:
        scale = func_802B2350((s32) arg0->descriptor->motion->acceleration);
        if (scale != 0.0f) {
            spC8 = arg0->direction;
            makeImpulse(&spC8,scale,&spB8);
            addImpulse(&arg0->velocity,&spB8);
            temp_s0_3=&arg0->velocity;
            temp_fv0f_3 = arg0->velocity.x;
            temp_fv0_4 = arg0->velocity.y;
            temp_fa0_2 = arg0->velocity.z;
            temp_fs0 = Math_Sqrtf((temp_fv0f_3 * temp_fv0f_3) + (temp_fv0_4 * temp_fv0_4) + (temp_fa0_2 * temp_fa0_2));
            temp_fv0_5 = func_802B2350((s32) arg0->descriptor->motion->speed);
            if (scale > 0.0f) {if (!(temp_fv0_5 < temp_fs0)) goto after_clamp;} else {if (!(temp_fs0 < temp_fv0_5)) goto after_clamp;}
            GraphU64_ScaleVector(temp_s0_3, &spC8, temp_fv0_5);
            after_clamp:;
        }
        Particle_UpdateSineMotion(arg0, 1.0f);
    }
}

#ifndef FIELD
#define FIELD(type, base, off) (*(type *)((char *)(base) + (off)))
#endif
extern char D_8011D8D0[];
extern void func_8022B09C_de(void *, CVector3 *);
extern void func_80283D50_de(void *);
extern void Particle_Release(void *, void *);
extern f32 GraphU64_ArcCos(f32);
/* Steers a homing particle (sound 0x8AC) at its target, or straight ahead when it has none: keeps its loop
 * sound alive, drops the target after D_800C4B78_de seconds, ends the particle when it gets close enough,
 * otherwise turns the direction toward the target by a blend rate chosen from the turn angle and age,
 * resets the velocity along the new direction and applies the descriptor's acceleration (clamped to its
 * top speed). */
void Particle_SteerHoming(void *particle) {
    SteeringParticle *homingParticle = particle;
    CVector3 v18;
    CVector3 v28;
    CVector3 v38;
    CQuatern v48;
    CVector3 v58;
    CVector3 v68;
    CQuatern q78;
    CQuatern q88;
    CQuatern q98;
    Matrix mA8;
    CVector3 vE8;
    CVector3 vF8;
    CVector3 *direction;
    void *owner;
    f32 speed;
    f32 distance;
    f32 angle;
    f32 rate;
    f32 accel;
    f32 limit;
    f32 speed2;
    s32 id;
    CVector3 *velocity;
    SteeringSound *sound;
    q78 = GraphU64_BuildDirectionQuaternion(&homingParticle->direction);
    speed = Math_Sqrtf(homingParticle->velocity.x * homingParticle->velocity.x + homingParticle->velocity.y * homingParticle->velocity.y +
                             homingParticle->velocity.z * homingParticle->velocity.z);
    owner = FIELD(void *, FIELD(void *, homingParticle, 0x12C), 0x1D8);
    id = 0x8AC;
    sound = homingParticle->sound;
    if (sound != 0) {
        if ((sound->id != id) || (sound->handle == -1)) {
            Particle_StopSound(homingParticle);
            goto create_sound;
        }
    } else {
create_sound:
        homingParticle->sound = func_8025C95C_de(func_8025CC6C_de(), 0x8AC, &homingParticle->position, &homingParticle->position, -1);
    }
    if (FIELD(void *, homingParticle, 0x134) != 0) {
        if (homingParticle->time >= D_800C4B78_de) {
            FIELD(void *, homingParticle, 0x134) = 0;
        }
    }
    if (FIELD(void *, homingParticle, 0x134) == 0) {
        v58.x = 0;
        v58.y = 0;
        v58.z = D_800C4B7C_de;
        func_8022B09C_de(owner, &v58);
        GraphU64_SubtractVectors(&v68, &v58, &homingParticle->position);
        distance = Math_Sqrtf(v68.x * v68.x + v68.y * v68.y + v68.z * v68.z);
        if (distance < D_800C4B80_de && homingParticle->time > D_800C4B84_de) {
            func_80283D50_de(homingParticle);
            Particle_Release(D_8011D8D0, homingParticle);
            Particle_StopSound(homingParticle);
            return;
        }
    } else {
        v18 = FIELD(CVector3, FIELD(void *, homingParticle, 0x134), 0x8);
        v18.y += GameObject_GetActorHeight(FIELD(void *, homingParticle, 0x134)) * D_800C4B88_de;
        GraphU64_SubtractVectors(&v68, &v18, &homingParticle->position);
    }
    v28 = v68;
    GraphU64_NormalizeVec3(&v28);
    q88 = GraphU64_BuildDirectionQuaternion(&v28);
    GraphU64_NormalizeQuaternion(&q88);
    GraphU64_NormalizeQuaternion(&q78);
    GraphU64_NormalizeVec3(&v28);
    v38 = homingParticle->direction;
    GraphU64_NormalizeVec3(&v38);
    angle = GraphU64_ArcCos(v28.x * v38.x + v28.y * v38.y + v28.z * v38.z);
    rate = 0.0f;
    if (!(homingParticle->time < D_800C4B8C_de)) {
        rate = D_800C4B94_de;
        if ((angle < D_800C4B90_de && D_800C4B98_de < homingParticle->time) || FIELD(void *, homingParticle, 0x134) != 0) {
            rate = D_800C4B9C_de;
        }
    }
    GraphU64_InterpolateQuaternionWithLinearFallback(&q98, rate, &q78, &q88);
    MatrixFromQuaternion(&q98, mA8.m);
    direction = &homingParticle->direction;
    v48.x = 0;
    v48.y = 0;
    v48.z = D_800C4BA0_de;
    GraphU64_TransformPoint(&mA8, &v48, direction);
    velocity = &homingParticle->velocity;
    GraphU64_ScaleVector(velocity, direction, speed);
    if (homingParticle->time >= D_800C4BA4_de) {
        FIELD(s8, homingParticle, 0x1B9) = 0;
        FIELD(s8, homingParticle, 0x1BA) = 0;
    }
    accel = func_802B2350((s32)homingParticle->descriptor->motion->acceleration);
    if (accel != 0.0f) {
        vF8 = homingParticle->direction;
        makeImpulse(&vF8, accel, &vE8);
        addImpulse(velocity, &vE8);
        speed2 = Math_Sqrtf(homingParticle->velocity.x * homingParticle->velocity.x + homingParticle->velocity.y * homingParticle->velocity.y +
                                  homingParticle->velocity.z * homingParticle->velocity.z);
        limit = func_802B2350((s32)homingParticle->descriptor->motion->speed);
        if (accel > 0.0f) {
            if (!(limit < speed2)) goto after_clamp;
        } else {
            if (!(speed2 < limit)) goto after_clamp;
        }
        GraphU64_ScaleVector(velocity, &vF8, limit);
    after_clamp:;
    }
    Particle_UpdateSineMotion(homingParticle, 1.0f);
}

#include "COMMON/APPROACHLOCATION.H"
/* Steers a homing particle toward goal: snaps onto it within 51.2 units, otherwise turns its heading
   toward it (harder as it closes in), keeps its speed along the new heading and applies its acceleration
   up to the speed limit before moving it. */
void Particle_SteerToward(AccelSteeringObj *particle, AccelSteeringVec *goal) {
    AccelSteeringVec offset;
    AccelSteeringVec forward;
    CQuatern current;
    CQuatern wanted;
    CQuatern turned;
    f32 rotation[16];
    AccelSteeringVec impulse;
    AccelSteeringVec heading;
    f32 distance;
    f32 speed;
    f32 blend;
    f32 acceleration;
    f32 newSpeed;
    f32 limit;
    AccelSteeringVec *vel;

    GraphU64_SubtractVectors(&offset, goal, &particle->position);
    distance = Math_Sqrtf((offset.x * offset.x) + (offset.y * offset.y) + (offset.z * offset.z));
    if (distance <= 51.199997f) {
        particle->position = *goal;
        return;
    }
    GraphU64_NormalizeVec3(&offset.x);
    wanted = GraphU64_BuildDirectionQuaternion(&offset.x);
    current = GraphU64_BuildDirectionQuaternion(&particle->direction.x);
    speed = Math_Sqrtf((particle->velocity.x * particle->velocity.x) + (particle->velocity.y * particle->velocity.y) + (particle->velocity.z * particle->velocity.z));
    if (distance < 1024.0f) {
        blend = distance - 204.79999f;
        if (blend < 0.0f) {
            blend = 0.0f;
        } else {
            blend = blend * 0.0012207031f;
        }
        blend = 0.9f - (blend * 0.85999995f);
    } else {
        blend = 0.04f;
    }
    GraphU64_InterpolateQuaternionWithLinearFallback(&turned, blend, &current, &wanted);
    MatrixFromQuaternion(&turned.x, rotation);
    forward.x = 0.0f;
    forward.y = 0.0f;
    forward.z = 1.0f;
    GraphU64_TransformPoint(rotation, &forward, &particle->direction);
    GraphU64_ScaleVector(&particle->velocity, &particle->direction, speed);
    acceleration = func_802B2350(particle->link->params->accel);
    vel = &particle->velocity;
    if (acceleration != 0.0f) {
        heading = particle->direction;
        makeImpulse(&heading, acceleration, &impulse);
        addImpulse(vel, &impulse);
        newSpeed = Math_Sqrtf((particle->velocity.x * particle->velocity.x) + (particle->velocity.y * particle->velocity.y) + (particle->velocity.z * particle->velocity.z));
        limit = func_802B2350(particle->link->params->limit);
        if (acceleration > 0.0f) {
            if (!(limit < newSpeed)) goto skip;
        } else if (!(newSpeed < limit)) goto skip;
        GraphU64_ScaleVector(vel, &heading, limit);
    skip:;
    }
    Particle_UpdateSineMotion(particle, 1.0f);
}
