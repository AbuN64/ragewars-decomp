#include "span_1000/code_8024E914.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "math_helpers.h"
#include "shared/legacy_collision_actor.h"
#include "span_1000/code_8026E1F8.h"
#include "types.h"
#include "span_1000/code_8022F3E8.h"

extern f32 D_800C3D90_de;

extern char D_8011D8D0;


extern s32 *func_8028FDB4_de(void *value, s32 index);

extern f32 func_8024D284_de(Actor_func_8024ED90_de *actor);

extern void func_802800C0_de(void *system, Actor_func_8024ED90_de *source, Actor_func_8024ED90_de *owner,
                          s32 arg3, s32 arg4, s32 arg5, Vec3 position,
                          Vector4f rotation, Vec3 position2, s32 arg15,
                          s32 arg16, s32 arg17);

extern EffectRecAt154 *func_802830B8_de(void *system);

extern f32 func_8024D398_de(Actor_func_8024ED90_de *actor);

/* Places an actor's ground shadow: the shadow size is the smaller of half the vertical offset from
 * func_8024E2FC_de and that minus a tenth of the actor's height above its ground height at 0x40, vanishing
 * when negative; a transform is built from the actor's orientation, scaled flat by the shadow size,
 * positioned at the ground under the actor, stored as the actor's per-frame matrix and submitted through
 * func_8026992C_de. */


extern void func_8024D870_de(f32 *, void *);

extern void func_8027254C_de(Vec3 *, f32);

extern void func_80274244_de(f32 *, f32 *);

extern void func_8027347C_de(f32 *, f32, f32, f32);

extern void func_80273448_de(f32 *, f32, f32, f32);

extern void func_8027027C_de(f32 *, void *);

extern void func_8026992C_de(void *, s32, s32);

extern void * *func_8025193C_de(s32, s32, s32, s32, s32, s32, void *, void *, s32);

extern void func_80253838_de(void *arg0, void *arg1);

extern s32 func_802540F4_de(s32, void **, s32, void *, s32);

extern s32 func_8028FE28_de(s32 *, s32, s32);

extern s32 func_8028FE3C_de(s32, s32, s32, s32 *);

extern void func_80253754_de(s32, void *);

extern char D_0026D7F4;

extern char D_800C3DA8_de;

extern char D_800C3DC0_de;

extern char D_800C3DD4_de;

void func_8024ED90_de(Actor_func_8024ED90_de *actor, void **arg1) {
    Vec3 position;
    Vector4f rotation;
    EffectRecAt154 *effect;
    f32 scale;
    s32 *node;

    if (func_8026E340_de() != 0) {
        rotation.x = rotation.y = rotation.z = 0.0f;
        rotation.w = D_800C3D90_de;
        node = func_8028FDB4_de(*arg1, 2);
        if ((*node != 0) &&
            (*func_8028FDB4_de(func_8028FDB4_de(node, 0), 0) & 0x8000)) {
            position = actor->position0;
            position.y += func_8024D284_de(actor) * *(&D_800C3D90_de + 1);
            func_802800C0_de(&D_8011D8D0, actor, actor, 0, 0, 0x94,
                          actor->position1, rotation, position, 0, -1, 0);
            effect = func_802830B8_de(&D_8011D8D0);
            if (effect != 0) {
                scale = D_800C3D98_de;
                effect->field150 = func_8024D398_de(actor) * scale;
                effect->field154 = func_8024D284_de(actor) * scale;
            }
        }
    }
}

void func_8024EF28_de(void *actor) {
    f32 matrix[16];
    Vec3 position;
    f32 rotation[4];
    f32 ground;
    f32 height;
    f32 size;
    ground = ((Shared_Func80243A80Actor *)actor)->groundY;
    height = ((Shared_Func80243A80Actor *)actor)->y - ground;
    if (!(RW_MIN_LT(func_8024E2FC_de(actor) * 0.5f, func_8024E2FC_de(actor) * 0.5f - height * 0.1f) < 0.0f)) {
        size = RW_MIN_LT(func_8024E2FC_de(actor) * 0.5f, func_8024E2FC_de(actor) * 0.5f - height * 0.1f);
    } else {
        size = 0.0f;
    }
    func_8024D870_de(rotation, actor);
    position.x = ((Shared_Func80243A80Actor *)actor)->x;
    position.z = ((Shared_Func80243A80Actor *)actor)->z;
    position.y = ground;
    func_8027254C_de(&position, 20000.0f);
    func_80274244_de(rotation, matrix);
    func_8027347C_de(matrix, size, 1.0f, size);
    func_80273448_de(matrix, position.x, position.y, position.z);
    func_8027027C_de(matrix, (char *)actor + ((D_800D297C << 6) + 0xE8));
    func_8026992C_de((char *)actor + ((D_800D297C << 6) + 0xE8), 1, 0x96);
}

void func_8024F108_de(StaticObject *arg0) {
    void *sp28;
    void **resource;
    s32 key;
    s32 found;
    s32 index;

    index = arg0->model;
    if (index != arg0->animation) {
        resource = func_8025193C_de(0, arg0->animationKey,
                                arg0->animationKey, 0x18,
                                0, 0, 0, &D_800C3DA8_de + 4, 1);
        if (resource != 0) {
            key = func_8028FE28_de(*resource, arg0->animationKey, 1);
            func_80253838_de(0, resource);
            found = func_802540F4_de(0, &sp28, key, &D_800C3DC0_de, 1);
            if (found != 0) {
                arg0->resource = func_8028FE3C_de((s32)sp28, key,
                                                    index % *(s32 *)sp28,
                                                    &arg0->resourceSize);
                arg0->animation = index;
                func_80253838_de(0, (void *)found);
            }
        }
    }
    if (arg0->resource != 0) {
        resource = func_8025193C_de(0, arg0->resource,
                                arg0->resource, arg0->resourceSize,
                                0, 0, &D_0026D7F4, &D_800C3DD4_de, 0);
    } else {
        resource = 0;
    }
    if (resource != 0) {
        func_8026E1F8_de(resource);
        func_80253754_de(0, resource);
    }
}
