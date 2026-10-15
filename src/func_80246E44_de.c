#include "span_1000/code_80246E34.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "resident_event_handler.h"
#include "shared/func_80214624_de_closed.h"
#include "shared/func_8044DA54_de_closed.h"
#include "shared/world.h"
#include "span_1000/code_8026E1F8.h"
#include "stddef.h"
#include "types.h"

extern void func_80247004_de(Obj_func_80247004_de *);

extern void **func_8025193C_de(s32,s32,s32,s32,s32,s32,void *,void *,s32);

extern void func_80253754_de(void *, Node80253610 *);

/* Update or blend object rotation when the movement state permits it. */
void func_8024D870_de(f32 *, void *);

 /* extern */
s32 func_8024E29C_de(void *);

 /* extern */
s32 func_8024E62C_de();

 /* extern */
void func_80270CD0_de(void *, f32, void *, f32 *);

 /* extern */
void func_80274380_de(void *, f32 *);

 /* extern */
extern f32 D_800C3928_de[], D_800C3930_de[], D_800D2988[];

typedef struct CollisionInfo CollisionInfo;

extern CollisionInfo D_801003D8;

extern func_80237E70_G1 D_801041F0;

extern s32 func_80243A90_de(void *arg0, Vec3 arg1, CollisionInfo *arg2);

extern void func_80278E04_de(s32 arg0, s32 arg1, void *arg2);

extern void func_80278D78_de(void *arg0, s32 arg1, void *arg2);

void func_80246E44_de(Actor36 *actor) {
    Vec3 before, after;
    u32 flags, mode;
    void **resource;
    void *box;
    flags = actor->flags;
    if (!(flags & 0x40000)) return;
    if (D_8011FE88.mode == 4 && !(flags & 0x2000)) return;
    mode = flags & 0x300000;
    before = actor->position;
    func_802472F0_de(actor);
    after = actor->position;
    actor->position = before;
    if (mode == 0 && *actor->kind != 0) {
        func_80271F68_de(&after, &after, &before);
        func_80271F34_de(&after, &after, &actor->displacement);
        func_8024715C_de((void *)actor, &after);
        if (*actor->kind == 1) {
            func_8028A27C_de(&D_8011FE88, actor, &before, &actor->position);
        }
    }
    func_80247004_de((void *)actor);
    resource = func_8025193C_de(0, actor->size, actor->size, actor->alignment, 0, 0, 0, D_800C38F4_de, 1);
    if (resource != 0) {
        box = func_8028FDB4_de(*resource, 0);
        actor->update(actor, actor->state);
        func_8026EE20_de(actor->matrix, box, &actor->box);
        func_80253754_de(0, (void *)resource);
    }
}

void func_80247004_de(Obj_func_80247004_de *arg0) {
    f32 vec[4];
    f32 var_f0;
    f32 var_f1;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_v0;
    s32 flags;
    void *temp_a0;
    void *var_a0;
    temp_v0 = arg0->unk100;
    flags = temp_v0 & 0x300000;
    if (!(temp_v0 & 1) && (temp_s2 = func_8024E62C_de(), (arg0->unk14 != NULL)) && (func_8024D870_de(vec, arg0), temp_s1 = arg0->unk14->unk2 & 1, (func_8024E29C_de(arg0) != 0))) {
        if (temp_s1 != 0) {
            vec[0] = vec[1] = vec[2] = 0.0f;
            vec[3] = D_800C3924_de;
        }
        if (flags) {
            if ((!(arg0->unk100 & 0x1000) && (var_a0 = arg0->rotation, (temp_s2 != 0))) || (var_a0 = arg0->rotation, (temp_s1 != 0))) {
                func_80274380_de(var_a0, vec);
            }
        } else {
            if ((temp_s2 != 0) && !(arg0->unk100 & 0x1000)) {
                var_f0 = D_800D2988[0]; var_f1 = D_800C3928_de[0];
            } else {
                var_f0 = D_800D2988[0]; var_f1 = D_800C3928_de[1];
            }
            var_f0 = var_f0 * var_f1;
            temp_a0 = arg0->rotation;
            if (var_f0 > D_800C3930_de[0]) {
                var_f0 = D_800C3930_de[0];
            }
            func_80270CD0_de(temp_a0, var_f0, temp_a0, vec);
        }
    }
}

void func_8024715C_de(char *arg0, Vec3 *arg1) {
    CollisionInfo *collision;
    u16 *old_contact;
    s32 collided;
    f32 saved;
    void (*callback)(void *, void *, CollisionInfo *);

    if ((((ObjectLinks23C *)(arg0))->unk_100 & 0x10000) && ((ObjectLinks23C *)(arg0))->unk_1A0 != 0) {
        collision = ((ObjectLinks10 *)(((ObjectLinks23C *)(arg0))->unk_1A0))->unk_C;
        if (collision == 0) {
            collision = &D_801003D8;
        }
        saved = ((ObjectStateC *)(collision))->unk_8.v0;
        if ((u32)(((ObjectLinks23C *)(arg0))->unk_238 - 0x2B0C) < 8) {
            ((ObjectStateC *)(collision))->unk_8.v1 = 0;
        }
        old_contact = ((ObjectLinks23C *)(arg0))->unk_14;
        collided = func_80243A90_de(arg0, *arg1, collision);
        if (old_contact != ((ObjectLinks23C *)(arg0))->unk_14) {
            ((ObjectLinks23C *)(arg0))->unk_1F4 = old_contact;
        }
        ((ObjectStateC *)(collision))->unk_8.v0 = saved;
        if (old_contact != 0 && ((ObjectLinks23C *)(arg0))->unk_14 != 0 &&
                *old_contact != *((ObjectLinks23C *)(arg0))->unk_14 &&
                *((ObjectLinks23C *)(arg0))->unk_18 == 1) {
            func_80278E04_de((s32)old_contact, 0x80, arg0);
            func_80278E04_de((s32)((ObjectLinks23C *)(arg0))->unk_14, 0x40, arg0);
        }
        if (collided != 0 && !(((ObjectLinks23C *)(arg0))->unk_100 & 0x300000) &&
                *((ObjectLinks23C *)(arg0))->unk_18 == 1 && D_801041F0.unk0 != 0 &&
                *D_801041F0.unk0 == 1) {
            func_80278D78_de(D_801041F0.unk0, 0x20, arg0);
        }
        callback = ((struct CallbackState288 *) ((char *) arg0))->callback;
        if (callback != 0) {
            callback(arg0, arg0 + 0x170, collision);
        }
    } else {
        ((ObjectLinks23C *)(arg0))->unk_8 = *arg1;
    }
}
