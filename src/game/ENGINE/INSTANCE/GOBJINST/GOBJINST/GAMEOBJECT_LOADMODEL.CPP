#include "COMMON/UNUSED.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ACCESS_S8_10F.H"
#include "TYPES.H"
#include "SCENE/802508E0_4.H"
#include "SCENE/802508E0_9.H"
#include "RENDER/8028FD2C_6.H"
#include "COMMON/OBJECTLINKS180_2.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/APPROACHLOCATION.H"
#include "COMMON/PPDECOM_UNPACKRESOURCE.H"
#include "COMMON/WORLD.H"
#include "COMMON/OBJRECAT4V7.H"
#include "stddef.h"
#include "ENGINE/INSTANCE/GOBJINST_3.H"
#include "GAME/CODE_8027302C.H"

/* GOBJINST_2.CPP */
extern s32 SetN64_GetDirectoryEntry(s32 *arg0, s32 arg1, s32 arg2);
extern s32 SetN64_LocatePackSection(s32, s32, s32, s32 *);
extern void func_80262480_de(void *);
extern s32 Gobjinst_ChooseAnimationVariant(void *, s32, s32);

void Gobjinst_LoadModel(void *actorStorage, s32 *modelDirectory, s32 directoryBank, s32 extra) {
    s32 *animationMetadata;
    void **resource1;
    void **resource2;
    s32 *entry;
    void *temp;
    void *node;
    s32 key;
    s32 found;

    ((LevelActor *)actorStorage)->resourceHandle = -1;
    ((LevelActor *)actorStorage)->resourceState = 0;
    ((LevelActor *)actorStorage)->resourceWindow = 0;
    ((LevelActor *)actorStorage)->flags &= 0xFFFBFFFF;
    key = SetN64_GetDirectoryEntry(modelDirectory, directoryBank, (u16)((LevelActor *)actorStorage)->modelIndex);
    resource1 = Cache_RequestResource(0, key, key, 0x18, 0, 0, 0, &g_gameObjectAnimIndexText, 1);
    if (resource1 != 0) {
        entry = *resource1;
        ((LevelActor *)actorStorage)->animationKey = SetN64_GetDirectoryEntry(entry, key, 1);
        found = Cache_RequestWordCountedResource(0, &animationMetadata, ((LevelActor *)actorStorage)->animationKey, &s_animModelsIndexText, 1);
        if (found != 0) {
            ((LevelActor *)actorStorage)->stateE7 = (u8)*animationMetadata;
            ((LevelActor *)actorStorage)->resourceAlignment = ((*animationMetadata * 4) + 0xF) & ~7;
            Cache_UnlockResource(0, (void *)found);
        }
        ((LevelActor *)actorStorage)->resource = SetN64_LocatePackSection((s32)entry, key, 0, &((LevelActor *)actorStorage)->resourceFlags);
        ((LevelActor *)actorStorage)->resourceKey = SetN64_GetDirectoryEntry(entry, key, 2);
        resource2 = Cache_RequestResource(0, ((LevelActor *)actorStorage)->resource,
                                 ((LevelActor *)actorStorage)->resource, ((LevelActor *)actorStorage)->resourceFlags,
                                 0, 0, 0, &g_gameObjectResetAnimInfoText, 1);
        if (resource2 != 0) {
            node = *resource2;
            temp = SetN64_GetPackSection(node, 0);
            ((LevelActor *)actorStorage)->controllerUpdate(actorStorage, (char *)actorStorage + 0x170);
            Graphu64_TransformBoundingBox(&((LevelActor *)actorStorage)->transform, (s32)temp, (char *)actorStorage + 0xE8);
            func_80262480_de((char *)actorStorage + 0x104);
            func_80262480_de((char *)actorStorage + 0x118);
            ((LevelActor *)actorStorage)->stateE6 = (u8)((ResourceManagerState *)SetN64_GetPackSection(node, 1))->count;
            ((LevelActor *)actorStorage)->flags |= 0x40000;
            if (extra > 0) {
                extra = Gobjinst_ChooseAnimationVariant(actorStorage, extra, -1);
            } else {
                extra = -extra;
            }
            if (extra == -1) {
                extra = 0;
            }
            ((LevelActor *)actorStorage)->nextAnimation = extra;
            ((LevelActor *)actorStorage)->animationPending = 0;
            if (((LevelActor *)actorStorage)->animation != extra) {
                ((LevelActor *)actorStorage)->animationChanged = 1;
            }
            ((LevelActor *)actorStorage)->animationState = -1;
            ((LevelActor *)actorStorage)->lean = extra;
            Cache_UnlockResource(0, resource2);
        }
        Cache_UnlockResource(0, resource1);
    }
}

/* GOBJINST_3.CPP */
/* Update or blend object rotation when the movement state permits it. */
CQuatern Insthdr_BuildActorGroundRotation(void *);

 /* extern */
s32 InstHdr_UsesGroundRotation(void *);

 /* extern */
s32 InstHdr_GetActorMotionState(void *);

 /* extern */
void Graphu64_InterpolateQuaternionWithLinearFallback(void *, f32, void *, f32 *);

 /* extern */

 /* extern */
extern f32 D_800C3928_de[], D_800C3930_de[], D_800D2988[];

typedef struct CollisionInfo CollisionInfo;

extern CollisionInfo D_801003D8;

extern func_80237E70_G1 D_801041F0;

extern s32 Unicol_MoveActorWithCollision(void *arg0, CVector3 arg1, CollisionInfo *arg2);

extern void Link_DispatchObjectLinks(s32 arg0, s32 arg1, void *arg2);

extern void Link_DispatchActorLinks(void *arg0, s32 arg1, void *arg2);

void func_80246E44_de(Actor36 *actor) {
    CVector3 before, after;
    u32 flags, mode;
    void **resource;
    void *box;
    flags = actor->flags;
    if (!(flags & 0x40000)) return;
    if (g_world.mode == 4 && !(flags & 0x2000)) return;
    mode = flags & 0x300000;
    before = actor->position;
    func_802472F0_de(actor);
    after = actor->position;
    actor->position = before;
    if (mode == 0 && *actor->kind != 0) {
        Graphu64_SubtractVectors(&after, &after, &before);
        Graphu64_AddVec3(&after, &after, &actor->displacement);
        func_8024715C_de((void *)actor, &after);
        if (*actor->kind == 1) {
            Scene_UpdateMovementTriggers(&g_world, actor, &before, &actor->position);
        }
    }
    func_80247004_de((void *)actor);
    resource = Cache_RequestResource(0, actor->size, actor->size, actor->alignment, 0, 0, 0, D_800C38F4_de, 1);
    if (resource != 0) {
        box = SetN64_GetPackSection(*resource, 0);
        actor->update(actor, actor->state);
        Graphu64_TransformBoundingBox(actor->matrix, box, &actor->box);
        Cache_UnlockResource(0, (void *)resource);
    }
}

void func_80247004_de(Obj_func_80247004_de *actor) {
    CQuatern vec;
    f32 rotationBlend;
    f32 rotationBlendRate;
    s32 resetRotationFlag;
    s32 rotationState;
    s32 actorFlags;
    s32 flags;
    void *rotation;
    void *rotationDestination;
    actorFlags = actor->unk100;
    flags = actorFlags & 0x300000;
    if (!(actorFlags & 1) && (rotationState = InstHdr_GetActorMotionState(actor), (actor->unk14 != NULL)) && (vec = Insthdr_BuildActorGroundRotation(actor), resetRotationFlag = actor->unk14->unk2 & 1, (InstHdr_UsesGroundRotation(actor) != 0))) {
        if (resetRotationFlag != 0) {
            vec.x = vec.y = vec.z = 0.0f;
            vec.w = D_800C3924_de;
        }
        if (flags) {
            if ((!(actor->unk100 & 0x1000) && (rotationDestination = actor->rotation, (rotationState != 0))) || (rotationDestination = actor->rotation, (resetRotationFlag != 0))) {
                Graphu64_ApproachQuaternion(rotationDestination, &vec);
            }
        } else {
            if ((rotationState != 0) && !(actor->unk100 & 0x1000)) {
                rotationBlend = D_800D2988[0]; rotationBlendRate = D_800C3928_de[0];
            } else {
                rotationBlend = D_800D2988[0]; rotationBlendRate = D_800C3928_de[1];
            }
            rotationBlend = rotationBlend * rotationBlendRate;
            rotation = actor->rotation;
            if (rotationBlend > D_800C3930_de[0]) {
                rotationBlend = D_800C3930_de[0];
            }
            Graphu64_InterpolateQuaternionWithLinearFallback(rotation, rotationBlend, rotation, &vec);
        }
    }
}

void func_8024715C_de(char *actor, CVector3 *destination) {
    CollisionInfo *collision;
    u16 *old_contact;
    s32 collided;
    f32 saved;
    void (*callback)(void *, void *, CollisionInfo *);

    if ((((ObjectLinks23C *)(actor))->unk_100 & 0x10000) && ((ObjectLinks23C *)(actor))->unk_1A0 != 0) {
        collision = ((ObjectLinks10 *)(((ObjectLinks23C *)(actor))->unk_1A0))->unk_C;
        if (collision == 0) {
            collision = &D_801003D8;
        }
        saved = ((ObjectStateC *)(collision))->unk_8.v0;
        if ((u32)(((ObjectLinks23C *)(actor))->unk_238 - 0x2B0C) < 8) {
            ((ObjectStateC *)(collision))->unk_8.v1 = 0;
        }
        old_contact = ((ObjectLinks23C *)(actor))->unk_14;
        collided = Unicol_MoveActorWithCollision(actor, *destination, collision);
        if (old_contact != ((ObjectLinks23C *)(actor))->unk_14) {
            ((ObjectLinks23C *)(actor))->unk_1F4 = old_contact;
        }
        ((ObjectStateC *)(collision))->unk_8.v0 = saved;
        if (old_contact != 0 && ((ObjectLinks23C *)(actor))->unk_14 != 0 &&
                *old_contact != *((ObjectLinks23C *)(actor))->unk_14 &&
                *((ObjectLinks23C *)(actor))->unk_18 == 1) {
            Link_DispatchObjectLinks((s32)old_contact, 0x80, actor);
            Link_DispatchObjectLinks((s32)((ObjectLinks23C *)(actor))->unk_14, 0x40, actor);
        }
        if (collided != 0 && !(((ObjectLinks23C *)(actor))->unk_100 & 0x300000) &&
                *((ObjectLinks23C *)(actor))->unk_18 == 1 && D_801041F0.unk0 != 0 &&
                *D_801041F0.unk0 == 1) {
            Link_DispatchActorLinks(D_801041F0.unk0, 0x20, actor);
        }
        callback = ((struct CallbackState288 *) ((char *) actor))->callback;
        if (callback != 0) {
            callback(actor, actor + 0x170, collision);
        }
    } else {
        ((ObjectLinks23C *)(actor))->unk_8 = *destination;
    }
}
