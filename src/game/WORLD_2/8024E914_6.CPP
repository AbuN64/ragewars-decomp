#include "COMMON/PROPGEOMETRY.H"
#include "WORLD_2/8024E914.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/MATH_HELPERS.H"
#include "COMMON/LEGACY_COLLISION_ACTOR.H"
#include "COMMON/OBJRECAT4V7.H"
#include "TYPES.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "SOUND/8024E130_2.H"
#include "WORLD_2/8024E914_6.H"
#include "SCENE/802508E0_4.H"
#include "RENDER_4/8028FD2C_6.H"

extern f32 D_800C3D90_de;

extern char D_8011D8D0;



extern f32 Particle_GetActorHeight(Actor_func_8024ED90_de *actor);

#include "particle/8027A0F4_8.H"
extern void Scene_ReleaseResource(void *arg0, void *arg1);

extern EffectRecAt154 *func_802830B8_de(void *system);

extern f32 func_8024D398_de(Actor_func_8024ED90_de *actor);

/* Places an actor's ground shadow: the shadow size is the smaller of half the vertical offset from
 * func_8024E2FC_de and that minus a tenth of the actor's height above its ground height at 0x40, vanishing
 * when negative; a transform is built from the actor's orientation, scaled flat by the shadow size,
 * positioned at the ground under the actor, stored as the actor's per-frame matrix and submitted through
 * func_8026992C_de. */


extern CQuatern func_8024D870_de(void *);

extern void func_8027254C_de(CVector3 *, f32);

extern void MatrixFromQuaternion(f32 *, f32 *);

extern void func_8027347C_de(f32 *, f32, f32, f32);

extern void func_80273448_de(f32 *, f32, f32, f32);

extern void func_8027027C_de(f32 *, void *);

extern void func_8026992C_de(void *, s32, s32);



extern s32 func_802540F4_de(s32, void **, s32, void *, s32);

extern s32 Render_GetDirectoryEntry(s32 *, s32, s32);

extern s32 Render_LocatePackSection(s32, s32, s32, s32 *);

extern void Scene_UnlockResource(s32, void *);

extern char D_0026D7F4;

extern char D_800C3DA8_de;

extern char D_800C3DC0_de[];

extern char D_800C3DD4_de[];

void func_8024ED90_de(Actor_func_8024ED90_de *actor, void **resource) {
    CVector3 position;
    CQuatern rotation;
    EffectRecAt154 *effect;
    f32 scale;
    s32 *node;

    if (func_8026E340_de() != 0) {
        rotation.x = rotation.y = rotation.z = 0.0f;
        rotation.w = D_800C3D90_de;
        node = Render_GetPackSection(*resource, 2);
        if ((*node != 0) &&
            (*((s32 *)Render_GetPackSection(Render_GetPackSection(node, 0), 0)) & 0x8000)) {
            position = actor->position0;
            position.y += Particle_GetActorHeight(actor) * *(&D_800C3D90_de + 1);
            func_802800C0_de((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)actor, (struct EffectActor *)actor, 0, 0, 0x94,
                          actor->position1, rotation, position, 0, -1, 0);
            effect = func_802830B8_de(&D_8011D8D0);
            if (effect != 0) {
                scale = D_800C3D98_de;
                effect->field150 = func_8024D398_de(actor) * scale;
                effect->field154 = Particle_GetActorHeight(actor) * scale;
            }
        }
    }
}

void func_8024EF28_de(void *actor) {
    f32 matrix[16];
    CVector3 position;
    CQuatern rotation;
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
    rotation = func_8024D870_de(actor);
    position.x = ((Shared_Func80243A80Actor *)actor)->x;
    position.z = ((Shared_Func80243A80Actor *)actor)->z;
    position.y = ground;
    func_8027254C_de(&position, 20000.0f);
    MatrixFromQuaternion(&rotation.x, matrix);
    func_8027347C_de(matrix, size, 1.0f, size);
    func_80273448_de(matrix, position.x, position.y, position.z);
    func_8027027C_de(matrix, (char *)actor + ((D_800D297C << 6) + 0xE8));
    func_8026992C_de((char *)actor + ((D_800D297C << 6) + 0xE8), 1, 0x96);
}

void func_8024F108_de(StaticObject *staticObject) {
    void *sp28;
    void **resource;
    s32 key;
    s32 found;
    s32 index;

    index = staticObject->model;
    if (index != staticObject->animation) {
        resource = Scene_RequestResource(0, staticObject->animationKey,
                                staticObject->animationKey, 0x18,
                                0, 0, 0, &D_800C3DA8_de + 4, 1);
        if (resource != 0) {
            key = Render_GetDirectoryEntry(*resource, staticObject->animationKey, 1);
            Scene_ReleaseResource(0, resource);
            found = func_802540F4_de(0, &sp28, key, D_800C3DC0_de, 1);
            if (found != 0) {
                staticObject->resource = Render_LocatePackSection((s32)sp28, key,
                                                    index % *(s32 *)sp28,
                                                    &staticObject->resourceSize);
                staticObject->animation = index;
                Scene_ReleaseResource(0, (void *)found);
            }
        }
    }
    if (staticObject->resource != 0) {
        resource = Scene_RequestResource(0, staticObject->resource,
                                staticObject->resource, staticObject->resourceSize,
                                0, 0, &D_0026D7F4, D_800C3DD4_de, 0);
    } else {
        resource = 0;
    }
    if (resource != 0) {
        func_8026E1F8_de(resource);
        Scene_UnlockResource(0, resource);
    }
}
