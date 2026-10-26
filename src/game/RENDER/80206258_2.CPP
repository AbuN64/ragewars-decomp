#include "COMMON/MODEL_RENDER.H"
#include "include_asm.h"
#include "COMMON/REC.H"
#include "COMMON/LIGHTDATA.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/WORLD.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/LISTHEADER.H"
#include "TYPES.H"
#include "RENDER/80206258_2.H"
#include "RENDER/80206258.H"
#include "COMMON/SHAREDPLAYER.H"
#include "stddef.h"
#include "FX_2/80271B18.H"
#include "WEAPONS/80213ED4.H"

extern void Scene_SetLevelActorStateBit(void *a, unsigned short b, unsigned short c, int d);

extern int Cinema_IsSequenceInWindow(void);

/** For each of the object's child slots, attach the child to the record and spawn its effect. */
extern int D_800D297C;

extern void *func_8024BFD4_de(void *, int);

extern void func_8024AA18_de(char *obj, s32 unused, char *info);

extern void func_802472F0_de(void *);
extern void Menu_RequestTrackByIds(s32, void *);

void func_8020676C_de(void *actor, void *motionState, Trigger *trigger) {
    extern void Rumble_SetActorStateBit(Shared_World *a, void *b, int c);
    func_802065C0_de(actor, motionState, trigger->unk6);
    ((LevelActor *)actor)->flags = ((LevelActor *)actor)->flags | 0x2100;
    func_802472F0_de(actor);
    Rumble_SetActorStateBit(&g_world, actor, 0);
}

void func_802067BC_de(Shared_Actor *actor) {
    extern void Rumble_SetActorStateBit(Shared_World *, void *, s32);
    s32 v = actor->weaponFlags;
    v &= ~0x2000;
    v &= ~0x100;
    actor->weaponFlags = v;
    Rumble_SetActorStateBit(&g_world, actor, 1);
}

void func_802067FC_de(Trigger *trigger) {
    Scene_SetLevelActorStateBit(&g_world, trigger->owner, trigger->actor, 1);
}

void func_8020682C_de(Shared_Actor *actor, s32 *sequenceFlags) {
    extern void Rumble_SetActorStateBit(Shared_World *, void *, s32);
    actor->weaponFlags |= 0x2100;
    if (Cinema_IsSequenceInWindow() != 0) {
        *sequenceFlags |= 0x200;
    }
    func_802472F0_de(actor);
    Rumble_SetActorStateBit(&g_world, actor, 0);
}

void func_80206898_de(Trigger *trigger) {
    Scene_SetLevelActorStateBit(&g_world, trigger->owner, trigger->actor, 0);
}

void func_802068C8_de(struct Shared_Actor *actor, s32 arg1, s32 trackRequest) {
    extern void Rumble_SetActorStateBit(Shared_World *, void *, s32);
    Menu_RequestTrackByIds((s32)actor, (void *)trackRequest);
    actor->weaponFlags |= 0x2100;
    Rumble_SetActorStateBit(&g_world, actor, 0);
}

void func_80206910_de(s32 trackRequest) {
    Menu_RequestTrackByIds(0, (void *)trackRequest);
}

/** Copy the source byte at offset 7 into two fields under object offset 0x18. */
void func_80206930_de(LevelActor *actor, int arg1, Trigger *triggerRecord) {
    void *inner = actor->definition;
    ((ActorDefinitionHeader *)inner)->first = (s8)triggerRecord->unk6;
    inner = actor->definition;
    ((ActorDefinitionHeader *)inner)->second = (s8)triggerRecord->unk6;
}

void func_8020694C_de(char *actor, void *renderContext, Rec *info) {
    int i;
    int n;
    void *child;

    n = (s8)((LevelActor *)actor)->stateE7;
    for (i = 0; i < n; i++) {
        child = func_8024BFD4_de(actor, i);
        if (child != 0) {
            info->a = child;
            info->b = child;
            func_8024AA18_de(actor, renderContext, info);
            Geometry_DrawModelResource(child, ((LevelActor *)actor)->fieldB4, 1, &((LevelActor *)actor)->lighting[D_800D297C], 0, ((LevelActor *)actor)->field3);
        }
    }
}

extern f32 D_800D2988;

/* Advance triggered shaking and vertical motion, invalidating animation on a state change. */
/* A hold segment keeps the motion until the input is held. */
void Device_UpdateTriggeredMotion(Actor_func_80206DD4_de *actor, RiderCode80206258 *motion) {
    SegmentRecAt5C *segment;
    s32 oldState;
    s32 release;
    f32 shakeMin;
    f32 shakeMax;

    oldState = motion->state;
    segment = &actor->motionTrack->segment;
    switch (oldState) {
    case 0:
        if (segment->flags & 0xC00000) {
            if (segment->flags & 0x04000000) {
                if (actor->inputFlags & 0x40) {
                    motion->triggerTime = motion->triggerTime + D_800D2988;
                } else {
                    motion->triggerTime = 0.0f;
                    break;
                }
            } else if (motion->triggerTime > 0.0f || (actor->inputFlags & 0x20)) {
                motion->triggerTime += D_800D2988;
            }
            if (motion->triggerTime >= segment->triggerDelay) {
                motion->timer = 0.0f;
                if (segment->flags & 0x01000000) {
                    motion->state = 3;
                } else if (segment->flags & 0x400000) {
                    motion->state = 1;
                } else if (segment->flags & 0x800000) {
                    motion->state = 4;
                }
            }
        }
        break;
    case 3:
        shakeMin = -0.512f;
        shakeMax = 0.512f;
        motion->shake.x = GraphU64_RandomBetween(shakeMin, shakeMax);
        motion->shake.y = GraphU64_RandomBetween(shakeMin, shakeMax);
        motion->shake.z = GraphU64_RandomBetween(shakeMin, shakeMax);
        motion->timer += D_800D2988;
        if (45.0f < motion->timer) {
            motion->timer = 0.0f;
            if (segment->flags & 0x400000) {
                motion->state = 1;
            } else if (segment->flags & 0x800000) {
                motion->state = 4;
            }
        }
        break;
    case 1:
        if (motion->timer < segment->duration) {
            motion->timer += D_800D2988;
        } else if (segment->flags & 0x02000000) {
            actor->flags &= ~0x2000;
        } else {
            motion->timer = segment->duration;
            if ((segment->flags & 0x08000000) && !(actor->inputFlags & 0x40)) {
                release = 0;
            } else {
                u32 flags = segment->flags;
                release = 1;
                if (flags & 0x10000000) {
                    release = (actor->inputFlags & 0x40) < release;
                }
            }
            if (release) {
                motion->state = 2;
            }
        }
        if (segment->duration > 0.0f) {
            motion->shake.y = -segment->displacement * Defs_CosineEase(motion->timer / segment->duration);
        } else {
            motion->shake.y = -segment->displacement;
        }
        break;
    case 2:
        if (motion->timer > 0.0f) {
            motion->timer -= D_800D2988;
        } else {
            motion->state = 0;
            motion->triggerTime = 0.0f;
        }
        if (segment->duration > 0.0f) {
            motion->shake.y = -segment->displacement * Defs_CosineEase(motion->timer / segment->duration);
        } else {
            motion->shake.y = -segment->displacement;
        }
        break;
    case 4:
        if (motion->timer < segment->duration) {
            motion->timer += D_800D2988;
        }
        if (segment->duration > 0.0f) {
            motion->shake.y = -segment->displacement * Defs_CosineEase(motion->timer / segment->duration);
        } else {
            motion->shake.y = -segment->displacement;
        }
        if (segment->flags & 0x02000000) {
            actor->flags &= ~0x2000;
        }
        break;
    }
    if (oldState != motion->state) {
        motion->animation = -1;
    }
}

/* Places a rider along its path for the frame: clamps the throttle to 0..1 (eased through Defs_CosineEase unless the segment is linear), offsets its base by the segment's rise and circle point, moves the rider there through func_80271FC8_de, adds a bob to its height (one wave or a sum of four detuned waves by the segment's bob mode), applies its shake offsets, turns the actor by the segment's yaw mode (interpolated, constant spin unless held, or constant spin) and, for free segments, snaps the actor to the ground through Region_GetPolygonHeight and func_802761EC_de. */


extern void func_80271FC8_de(CVector3 *, f32, CVector3 *, CVector3 *);

extern f32 Region_GetPolygonHeight(s32, f32, f32);

extern void func_802761EC_de(s32, f32);

/* Steers an actor along path nodes, blending direction, speed and orientation as it advances waypoints. */
/* The values func_802070D0_de loads by address:
 * 0x800C6C18 = 3.0 (float, D_800C6C18 in this cartridge's tables)
 * 0x800C6C1C = 10.24 (float, unnamed in this cartridge's tables)
 * 0x800C6C20 = 1.0 (float, D_800C6C20 in this cartridge's tables)
 * 0x800C6C24 = 1.0 (float, unnamed in this cartridge's tables)
 * 0x800C6C28 = 1.0 (float, D_800C6C28 in this cartridge's tables)
 * 0x800C6C2C = 3.1415927 (float, D_800C6C2C in this cartridge's tables)
 * 0x800C6C30 = 0.5 (float, D_800C6C30 in this cartridge's tables)
 * 0x800C6C34 = 0.3 (float, D_800C6C34 in this cartridge's tables)
 * 0x800C6C38 = 15.0 (float, D_800C6C38 in this cartridge's tables)
 * 0x800D2988 = 1.0 (float, D_800D2988 in this cartridge's tables; not a literal: a variable, its value in the image, since D_800D2988: `swc1` at %lo(D_800D2988) in Nav_UpdateActorStateAnimation.s)
 * 0x800C6C3C = 1.0 (float, D_800C6C3C in this cartridge's tables)
 * 0x800C6C40 = 3.1415927 (float, D_800C6C40 in this cartridge's tables)
 * 0x800C6C44 = 0.5 (float, D_800C6C44 in this cartridge's tables)
 * 0x800C6C48 = 2.670354 (float, D_800C6C48 in this cartridge's tables)
 * 0x800C6C4C = 0.5 (float, unnamed in this cartridge's tables)
 * 0x800C6C50 = 1.0 (float, D_800C6C50 in this cartridge's tables)
 * 0x800C6C54 = 0.017453294 (float, unnamed in this cartridge's tables)
 * 0x800C6C58 = 0.017453294 (float, D_800C6C58 in this cartridge's tables)
 * 0x800C6C5C = 0.1 (float, unnamed in this cartridge's tables)
 * 0x800C6C60 = 0.017453294 (float, D_800C6C60 in this cartridge's tables)
 * 0x800C6C64 = 0.017453294 (float, unnamed in this cartridge's tables)
 * 0x800C6C68 = 0.1 (float, D_800C6C68 in this cartridge's tables)
 * 0x800C6C6C = 0.017453294 (float, D_800C6C6C in this cartridge's tables)
 * 0x800C6C70 = 0.017453294 (float, D_800C6C70 in this cartridge's tables)
 * 0x800C6C74 = 0.1 (float, unnamed in this cartridge's tables)
 */
void Barrel_ApplyClampedTurn(void *, s32, f32, f32);

void func_802192C0_de(void *);

void * func_80219408_de(struct Cursor *);

void *func_80219434_de(struct Cursor *);

void GraphU64_SubtractVectors(void *, void *, void *);


f32 Math_Sqrtf(f32);

f32 Barrel_GetSignedAngleToPoint(void *, CVector3);

 /* extern */

/* Chooses the option label from the signed kind byte and, for the default
 * kind, the paired variant byte. The caller's context is unused. */
struct InputRecAt37 {
    char pad0[0x34];
    s8 variant;
    char pad35[2];
    s8 kind;
};

extern char D_800C86A0_de;

extern char D_002079B0;

extern char D_00207910;

extern f32 D_800C1B9C_de;


void func_80206DD4_de(Actor_func_80206DD4_de *actor, RiderCode80206258 *rider) {
    CVector3 point;
    SegmentRecAt5C *segment;
    f32 t;
    f32 phase;
    f32 amp;
    CVector3 *base;
    Actor_func_80206DD4_de *owner;
    t = rider->throttle;
    segment = (SegmentRecAt5C *)(actor->track + 0x14);
    if (t < 0.0f) {
        t = 0.0f;
    } else if (t > 1.0f) {
        t = 1.0f;
    }
    if (segment->linear == 0) {
        t = Defs_CosineEase(t);
    }
    owner = actor;
    point = rider->base;
    base = &rider->base;
    point.y += segment->rise;
    if (segment->moving != 0) {
        point.x += segment->radius * Math_Sinf(segment->angle);
        point.z += segment->radius * Math_Cosf(segment->angle);
    }
    func_80271FC8_de(&rider->pos, t, base, &point);
    switch (segment->bobMode) {
    case 0:
        rider->pos.y += segment->bob * Math_Sinf(rider->phase);
        break;
    case 1:
        phase = rider->phase;
        amp = 0.25f;
        rider->pos.y += segment->bob * (Math_Sinf(phase) * amp);
        rider->pos.y += segment->bob * (Math_Sinf(phase * 1.1f) * amp);
        rider->pos.y += segment->bob * (Math_Sinf(phase * 1.2f) * amp);
        rider->pos.y += segment->bob * (Math_Sinf(phase * 1.3f) * amp);
        break;
    }
    rider->pos.x += rider->shake.x;
    rider->pos.y += rider->shake.y;
    rider->pos.z += rider->shake.z;
    switch (segment->yawMode) {
    case 0:
        owner->yaw = rider->baseYaw + t * ((rider->baseYaw + segment->yaw) - rider->baseYaw);
        break;
    case 1:
        if (rider->flags & 0x400) {
            break;
        }
    case 2:
        owner->yaw += segment->yaw * 0.06666667f;
        break;
    }
    if (segment->moving == 0) {
        func_802761EC_de(owner->model, Region_GetPolygonHeight(owner->model, owner->x, owner->z) + rider->pos.y - owner->y);
    }
}

struct Cursor;

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x40, 0x44, 0x48, 0x4c, 0x50, 0x54, 0x58, 0x68, 0x6c], gap at: 0x5c. */
/* Steers an actor along path nodes, blending direction, speed and orientation as it advances waypoints. */
void func_802070D0_de(func_802070D0_S3 *actor, func_802070D0_S1 *pathState) {
    Triple initial;
    CVector3 vec0;
    CVector3 vec1;
    f32 advancedBlend;
    f32 remainingPause;
    f32 previousBlend;
    f32 temp_f1_2;
    f32 previousDirectionY;
    f32 previousDirectionZ;
    f32 pauseOrDirectionZ;
    f32 currentHeading;
    f32 currentSecondaryAngle;
    f32 currentTertiaryAngle;
    f32 blendRate;
    f32 targetDistance;
    f32 temp_f2_2;
    f32 segmentDirectionY;
    f32 segmentDirectionZ;
    f32 arg0_2;
    f32 initialHeading;
    f32 initialSecondaryAngle;
    f32 initialTertiaryAngle;
    f32 arrivalRadius;
    f32 movementSpeed;
    u16 half;
    func_802070D0_S2 *segmentNode;
    void *pathCursor;
    func_802070D0_S2 *targetNode;
    pathCursor = (void *) &pathState->unk94;
    targetNode = func_80219408_de(pathCursor);
    initial = targetNode->pos;
    GraphU64_SubtractVectors(&vec0, &initial, &actor->unk8);
    segmentNode = func_80219434_de(pathCursor);
    targetDistance = Math_Sqrtf(vec0.x * vec0.x + vec0.y * vec0.y + vec0.z * vec0.z);
    arrivalRadius = targetNode->unk1C;
    blendRate = segmentNode->unk20;
    if (arrivalRadius < 3.0f) {
        arrivalRadius = 3.0f;
    }
    if (targetDistance <= arrivalRadius * 10.24f) {
        pathState->unk14C = 0.0f;
        segmentNode->unk14.half = (u16) (segmentNode->unk14.half & 0x7FFF);
        func_802192C0_de(pathCursor);
        pathState->unk140 = (f32) pathState->unk150;
        pathState->unk144 = (f32) pathState->unk154;
        pathState->unk148 = (f32) pathState->unk158;
        pathState->unk15C = (f32) pathState->unk134;
        arg0_2 = actor->unk6C;
        pathState->unk164 = (f32) pathState->unk138;
        pathState->unk160 = (f32) arg0_2;
        return;
    }
    if (segmentNode->unk14.half & 2) {
        previousBlend = pathState->unk14C;
        if (previousBlend <= 0.0f) {
            pathState->unk14C = blendRate;
        } else {
            advancedBlend = previousBlend + blendRate;
            pathState->unk14C = advancedBlend;
            if (advancedBlend > 1.0f) {
                pathState->unk14C = 1.0f;
            }
        }
        if (segmentNode == targetNode) {
            GraphU64_SubtractVectors(&vec1, segmentNode, &actor->unk8);
        } else {
            GraphU64_SubtractVectors(&vec1, targetNode, segmentNode);
        }
        GraphU64_NormalizeVec3(&vec1);
        ;
        vec1.x = pathState->unk140 + pathState->unk14C * (vec1.x - pathState->unk140);
        segmentDirectionY = pathState->unk144;
        vec1.y = segmentDirectionY + pathState->unk14C * (vec1.y - segmentDirectionY);
        segmentDirectionZ = pathState->unk148;
        vec1.z = segmentDirectionZ + pathState->unk14C * (vec1.z - segmentDirectionZ);
        GraphU64_NormalizeVec3(&vec1);
        if (pathState->unk14C >= 1.0f) {
            goto block_17;
        }
    } else {
        GraphU64_NormalizeVec3(&vec0);
        ;
        vec1.x = pathState->unk140 + blendRate * (vec0.x - pathState->unk140);
        previousDirectionY = pathState->unk144;
        vec1.y = previousDirectionY + blendRate * (vec0.y - previousDirectionY);
        previousDirectionZ = pathState->unk148;
        vec1.z = previousDirectionZ + blendRate * (vec0.z - previousDirectionZ);
        GraphU64_NormalizeVec3(&vec1);
        block_17:
        pathState->unk140 = vec1.x;
        pathState->unk144 = vec1.y;
        pathState->unk148 = vec1.z;
    }
    pathState->unk150 = vec1.x;
    pathState->unk154 = vec1.y;
    pathState->unk158 = vec1.z;
    half = segmentNode->unk14.half;
    if (half & 1) {
        if (pathState->unk168 > 0.0f && !(half & 0x8000)) {
            movementSpeed = pathState->unk168 + (Math_Cosf((1.0f - segmentNode->unk30) * 3.1415927f) + 1.0f) * (-pathState->unk168 * 0.5f);
            if (movementSpeed <= 0.3f) {
                pathState->unk16C = (f32) (segmentNode->unk34 * 15.0f);
                movementSpeed = 0.0f;
                segmentNode->unk14.half = (u16) (segmentNode->unk14.half | 0x8000);
            }
        } else {
            pauseOrDirectionZ = pathState->unk16C;
            movementSpeed = 0.0f;
            if (pauseOrDirectionZ > 0.0f) {
                remainingPause = pauseOrDirectionZ - D_800D2988;
                pathState->unk16C = remainingPause;
                if (remainingPause <= 0.0f) {
                    pathState->unk16C = 0.0f;
                }
            } else if (pauseOrDirectionZ == 0.0f) {
                movementSpeed = pathState->unk168 + (Math_Cosf((1.0f - segmentNode->unk30) * 3.1415927f) + 1.0f) * ((segmentNode->unk24 - pathState->unk168) * 0.5f);
            }
        }
    } else {
        movementSpeed = pathState->unk168 + (Math_Cosf(2.670354f) + 1.0f) * ((segmentNode->unk24 - pathState->unk168) * 0.5f);
    }
    if (actor->unk38 & 8) {
        movementSpeed = 0.0f;
    }
    pathState->unk168 = movementSpeed;
    pathState->unk54 = (f32) (actor->unk8.v1 + vec1.x * movementSpeed * D_800D2988);
    pathState->unk58 = (f32) (actor->unkC + vec1.y * movementSpeed * D_800D2988);
    pauseOrDirectionZ = vec1.z;
    pathState->unk5C = (f32) (actor->unk10 + pauseOrDirectionZ * movementSpeed * D_800D2988);
    if (segmentNode->unk14.half & 8) {
        if ((segmentNode->unk14.word & 0x420000) == 0x420000) {
            initialHeading = pathState->unk160;
            actor->unk6C = (f32) (initialHeading + pathState->unk14C * (segmentNode->unk10 * 0.017453294f - initialHeading));
        } else {
            currentHeading = actor->unk6C;
            actor->unk6C = (f32) (currentHeading + (segmentNode->unk10 * 0.017453294f - currentHeading) * 0.1f);
        }
    } else {
        Barrel_ApplyClampedTurn(actor, (s32) pathState, 10.0f, Barrel_GetSignedAngleToPoint(actor, *(CVector3 *) &pathState->unk54));
    }
    if (segmentNode->unk14.half & 4) {
        if ((segmentNode->unk14.word & 0x220000) == 0x220000) {
            initialSecondaryAngle = pathState->unk15C;
            pathState->unk134 = (f32) (initialSecondaryAngle + pathState->unk14C * (segmentNode->unk28 * 0.017453294f - initialSecondaryAngle));
        } else {
            currentSecondaryAngle = pathState->unk134;
            pathState->unk134 = (f32) (currentSecondaryAngle + (segmentNode->unk28 * 0.017453294f - currentSecondaryAngle) * 0.1f);
        }
    }
    if (segmentNode->unk14.half & 0x10) {
        if ((segmentNode->unk14.word & 0x820000) == 0x820000) {
            initialTertiaryAngle = pathState->unk164;
            pathState->unk138 = (f32) (initialTertiaryAngle + pathState->unk14C * (segmentNode->unk2C * 0.017453294f - initialTertiaryAngle));
            return;
        }
        currentTertiaryAngle = (*pathState).unk138;
        pathState->unk138 = (f32) (currentTertiaryAngle + (segmentNode->unk2C * 0.017453294f - currentTertiaryAngle) * 0.1f);
    }
}

/** Perform no operation. */
void func_80207730_de(void) {
}

s32 func_80207738_de(void *context, struct InputRecAt37 *option) {
    s32 result;
    switch (option->kind) {
    case 3:
        return 21120;
    case 1:
    case 2:
        return 21140;
    case 0:
        result = 21100;
        switch (option->variant) {
        case 0:
        case 2:
            return 21100;
        case 1:
        case 3:
            return 21110;
        }
        break;
    default:
        return 21100;
    case 4:
        return 21130;
    }
    return result;
}

extern s32 Rumble_TestActorStateBit(void *, void *);
void func_802077CC_de(int actorHandle) {
    Rumble_TestActorStateBit(&g_world, (void *)actorHandle);
}

void func_802077F4_de(void *object, void *state)
{
    Player *actor = object;
    ActorMotionState *motionState = state;
    f32 k;
    f32 value;
    f32 scaled;
    ActorMotionResource *motionResource;
    ActorMotionDefinition *motionDefinition;

    motionResource = actor->definition;
    k = D_800C1B9C_de;
    motionState->table = &D_800C86A0_de;
    motionState->update = &D_002079B0;
    motionState->transform = &D_00207910;
    motionState->yaw = 0;
    motionState->pitch = 0;
    motionDefinition = &motionResource->motion;
    value = motionDefinition->speed;
    motionState->unk124 = 0;
    motionState->unk128 = 0;
    motionState->unk12C = 0;
    motionState->unk130 = 0;
    motionState->speed = value;
    scaled = motionDefinition->speed;
    motionState->unk140 = 0;
    motionState->unk144 = 0;
    scaled = scaled * k;
    motionState->unk148 = 0;
    motionState->unk14C = 0;
    motionState->unk168 = 0;
    motionState->unk16C = 0;
    motionState->progress = scaled;
    if (motionResource->motion.flags & 4) {
        actor->weaponFlags = actor->weaponFlags & ~0x2000;
    }
}

void func_80207890_de(void *object, void *state) {
    Player *player = object;
    ActorMotionState *motionState = state;
    motionState->state = 0;
    Nav_RequestActorState(player, motionState, 0);
    if (motionState->routeMode == 1) {
        motionState->destination = motionState->start;
        Nav_RequestActorState(player, motionState, 4);
    }
    if (Rumble_TestActorStateBit(&g_world, player) == 0) {
        player->weaponFlags &= ~0x100;
    }
}

#if !(defined(VERSION_US_REV1))
const unsigned int D_802077F4_C788C[1] = {
    0x40C90FDC,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802077F4_C788C_us_rev1.c */
const unsigned int D_blob_349aecbf22c8d4304034[1] = {
    0x40C90FDC,
};
#endif
