#include "COMMON/OBJECTLINKS180_2.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/APPROACHLOCATION.H"
#include "COMMON/EXTERNS_14.H"
#include "COMMON/WORLD.H"
#include "COMMON/OBJRECAT4V7.H"
#include "stddef.h"
#include "TYPES.H"
#include "ENGINE/INSTANCE/GOBJINST_3.H"
#include "GAME/CODE_8027302C.H"
#include "SCENE/802508E0_4.H"
#include "RENDER_4/8028FD2C_6.H"

extern void func_80247004_de(Obj_func_80247004_de *);


extern void Scene_UnlockResource(void *, Node80253610 *);

/* Update or blend object rotation when the movement state permits it. */
CQuatern func_8024D870_de(void *);

 /* extern */
s32 func_8024E29C_de(void *);

 /* extern */
s32 func_8024E62C_de(void *);

 /* extern */
void func_80270CD0_de(void *, f32, void *, f32 *);

 /* extern */

 /* extern */
extern f32 D_800C3928_de[], D_800C3930_de[], D_800D2988[];

typedef struct CollisionInfo CollisionInfo;

extern CollisionInfo D_801003D8;

extern func_80237E70_G1 D_801041F0;

extern s32 Camera_MoveActorWithCollision(void *arg0, CVector3 arg1, CollisionInfo *arg2);

extern void func_80278E04_de(s32 arg0, s32 arg1, void *arg2);

extern void func_80278D78_de(void *arg0, s32 arg1, void *arg2);

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
        Particle_SubtractVectors(&after, &after, &before);
        Particle_AddVec3(&after, &after, &actor->displacement);
        func_8024715C_de((void *)actor, &after);
        if (*actor->kind == 1) {
            Scene_UpdateMovementTriggers(&g_world, actor, &before, &actor->position);
        }
    }
    func_80247004_de((void *)actor);
    resource = Scene_RequestResource(0, actor->size, actor->size, actor->alignment, 0, 0, 0, D_800C38F4_de, 1);
    if (resource != 0) {
        box = Render_GetPackSection(*resource, 0);
        actor->update(actor, actor->state);
        func_8026EE20_de(actor->matrix, box, &actor->box);
        Scene_UnlockResource(0, (void *)resource);
    }
}

void func_80247004_de(Obj_func_80247004_de *actor) {
    CQuatern vec;
    f32 rotationBlend;
    f32 var_f1;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_v0;
    s32 flags;
    void *rotation;
    void *var_a0;
    temp_v0 = actor->unk100;
    flags = temp_v0 & 0x300000;
    if (!(temp_v0 & 1) && (temp_s2 = func_8024E62C_de(actor), (actor->unk14 != NULL)) && (vec = func_8024D870_de(actor), temp_s1 = actor->unk14->unk2 & 1, (func_8024E29C_de(actor) != 0))) {
        if (temp_s1 != 0) {
            vec.x = vec.y = vec.z = 0.0f;
            vec.w = D_800C3924_de;
        }
        if (flags) {
            if ((!(actor->unk100 & 0x1000) && (var_a0 = actor->rotation, (temp_s2 != 0))) || (var_a0 = actor->rotation, (temp_s1 != 0))) {
                func_80274380_de(var_a0, &vec);
            }
        } else {
            if ((temp_s2 != 0) && !(actor->unk100 & 0x1000)) {
                rotationBlend = D_800D2988[0]; var_f1 = D_800C3928_de[0];
            } else {
                rotationBlend = D_800D2988[0]; var_f1 = D_800C3928_de[1];
            }
            rotationBlend = rotationBlend * var_f1;
            rotation = actor->rotation;
            if (rotationBlend > D_800C3930_de[0]) {
                rotationBlend = D_800C3930_de[0];
            }
            func_80270CD0_de(rotation, rotationBlend, rotation, &vec);
        }
    }
}

void func_8024715C_de(char *actor, CVector3 *arg1) {
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
        collided = Camera_MoveActorWithCollision(actor, *arg1, collision);
        if (old_contact != ((ObjectLinks23C *)(actor))->unk_14) {
            ((ObjectLinks23C *)(actor))->unk_1F4 = old_contact;
        }
        ((ObjectStateC *)(collision))->unk_8.v0 = saved;
        if (old_contact != 0 && ((ObjectLinks23C *)(actor))->unk_14 != 0 &&
                *old_contact != *((ObjectLinks23C *)(actor))->unk_14 &&
                *((ObjectLinks23C *)(actor))->unk_18 == 1) {
            func_80278E04_de((s32)old_contact, 0x80, actor);
            func_80278E04_de((s32)((ObjectLinks23C *)(actor))->unk_14, 0x40, actor);
        }
        if (collided != 0 && !(((ObjectLinks23C *)(actor))->unk_100 & 0x300000) &&
                *((ObjectLinks23C *)(actor))->unk_18 == 1 && D_801041F0.unk0 != 0 &&
                *D_801041F0.unk0 == 1) {
            func_80278D78_de(D_801041F0.unk0, 0x20, actor);
        }
        callback = ((struct CallbackState288 *) ((char *) actor))->callback;
        if (callback != 0) {
            callback(actor, actor + 0x170, collision);
        }
    } else {
        ((ObjectLinks23C *)(actor))->unk_8 = *arg1;
    }
}
