#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/FIELD_VEC_B0.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "particle/8027A0F4_8.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/REC.H"
#include "COMMON/AIPROFILE.H"
#include "FX/80271B18.H"

/* 80213ED4_6.CPP */
/* The call sites in Events_SpawnFilteredActorEffect, Ghot_DispatchAttachmentEffects and Events_SpawnActorEffect
 * pass a fourth incoming slot; the callee never reads it. The signature here
 * is the one those callers and this definition agree on across the ROM. */

extern char D_8011D8D0;

extern void InstHdr_CopyActorPositionAndModel(void *actor, Triple input, Triple *output,
                          s32 *actorField, s32 unused0, s32 unused1);
extern CQuatern func_8024796C_de(CActor_t *actor);
extern s32 func_8024BE80_de(CActor_t *actor);
extern CQuatern func_8024F478_de(CActor_t *actor);

void Barrel_SpawnActorEffect(void *actor, s32 kind, Triple input, s32 unused0) {
    Triple copiedInput;
    CVector3 position;
    CQuatern rotation;
    s32 actorField;
    CActor_t *typedActor;
    s32 mode;
    s32 eventValue;
    s32 value;

    typedActor = 0;
    mode = 1;
    InstHdr_CopyActorPositionAndModel(actor, input, &copiedInput, &actorField, 0, mode);
    eventValue = 0;

    switch (((CActor_t *)actor)->type) {
    case 0:
    case 2:
        position.x = position.y = position.z = 0.0f;
        rotation.x = rotation.y = rotation.z = 0.0f;
        rotation.w = D_800C21C0_de[1];
        break;

    case 1:
        typedActor = actor;
        position = typedActor->position;
        rotation = func_8024796C_de(typedActor);
        eventValue = typedActor->eventValue;
        if (func_8024BE80_de(typedActor) == 5) {
            mode = 3;
        }
        break;

    case 3:
        position = ((CActor_t *)actor)->position;
        rotation = func_8024F478_de(actor);
        break;
    }

    Particle_SpawnEffectGroup((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)actor, (struct EffectActor *)actor, 0, eventValue, kind,
                  position, rotation, *(CVector3 *)&copiedInput, 0, -1, mode);

    if ((((CActor_t *)actor)->type == 1) && (typedActor->objectId == 0x40C)) {
        value = typedActor->eventCount - 1;
        if (value < 0) {
            value = 0;
        }
        typedActor->eventCount = value;
    }
}

/* 80213ED4_7.CPP */
void Barrel_FillDamagePacket(void *packet, s32 damageSource, s32 damage, s32 radius, s32 damageFlags, s32 shield) {
    (((struct ObjRecAt10V2 *) ((s8 *) packet))->unk0) = damageSource;
    (((struct ObjRecAt10V2 *) ((s8 *) packet))->unk4) = damage;
    (((struct ObjRecAt10V2 *) ((s8 *) packet))->unk8) = radius;
    (((struct ObjRecAt10V2 *) ((s8 *) packet))->unkC) = damageFlags;
    (((struct ObjRecAt10V2 *) ((s8 *) packet))->unk10) = shield;
}

/* 80213ED4_8.CPP */
extern void Barrel_StopActorLoopingSound(void);
extern void Actor_ApplySupportingPlatformMotion(SourceBarrelUpdateActorController *, DestBarrelUpdateActorController *);
extern void Actor_UpdateActorStateAnimation(SourceBarrelUpdateActorController *, DestBarrelUpdateActorController *);

void Barrel_UpdateActorController(SourceBarrelUpdateActorController *src, DestBarrelUpdateActorController *dst) {
    if ((dst->aux != 0) && (dst->aux->unkC == -1)) {
        Barrel_StopActorLoopingSound();
    }
    if (dst->timer != 0) {
        dst->timer--;
        D_800D2988 = 0.0f;
        return;
    }
    if ((src->active != 0) && (src->kind != 0)) {
        if (*src->kind == 2) {
            dst->old_position = src->position;
            dst->height = src->height;
        }
        dst->position = src->position;
        dst->value += D_800D2988;
        if (src->flags & 0x10000) {
            Actor_ApplySupportingPlatformMotion(src, dst);
        }
        if (dst->callback != 0) {
            dst->callback(src, dst);
        }
        Actor_UpdateActorStateAnimation(src, dst);
        if (*src->kind != 2) {
            dst->old_position = src->position;
            dst->height = src->height;
        }
    }
}

/* 80213ED4_9.CPP */
extern void Graphu64_SubtractVectors(CVector3 *arg0, CVector3 *arg1, CVector3 *arg2);
extern f32 Gu_Sqrtf(f32);

void Barrel_ComputeTargetOffset(Player *player, ActorMotionState *motionState, CAIMovementInfo *result) {
    Graphu64_SubtractVectors(&result->first, &player->pos,
                  &motionState->position);
    result->first_normalized = result->first;
    Graphu64_NormalizeVec3(&result->first_normalized.x);
    result->first_length = Gu_Sqrtf(
        result->first.x * result->first.x +
        result->first.y * result->first.y +
        result->first.z * result->first.z);
    result->flat.x = result->first.x;
    result->flat.y = 0.0f;
    result->flat.z = result->first.z;
    result->flat_normalized = result->flat;
    Graphu64_NormalizeVec3(&result->flat_normalized.x);
    result->flat_length = Gu_Sqrtf(
        result->flat.x * result->flat.x +
        result->flat.y * result->flat.y +
        result->flat.z * result->flat.z);
    result->height = player->heading -
                     motionState->height;
}
