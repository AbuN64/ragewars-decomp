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



extern f32 GameObject_GetActorHeight(ActorSimpleInstanceSpawnModelEffect *actor);

#include "particle/8027A0F4_8.H"
extern void Cache_ReleaseResource(void *arg0, void *arg1);

extern EffectRecAt154 *Particle_GetLastSpawnedEffect(void *system);

extern f32 GameObject_GetActorRadius(ActorSimpleInstanceSpawnModelEffect *actor);

/* Places an actor's ground shadow: the shadow size is the smaller of half the vertical offset from
 * InstHdr_GetActorShadowRadius and that minus a tenth of the actor's height above its ground height at 0x40, vanishing
 * when negative; a transform is built from the actor's orientation, scaled flat by the shadow size,
 * positioned at the ground under the actor, stored as the actor's per-frame matrix and submitted through
 * Geometry_DrawIntensityMask. */


extern CQuatern InstHdr_BuildActorGroundRotation(void *);

extern void GraphU64_LimitVectorLength(CVector3 *, f32);

extern void MatrixFromQuaternion(f32 *, f32 *);

extern void ScaleMatrixLocal(f32 *, f32, f32, f32);

extern void TranslateMatrix(f32 *, f32, f32, f32);

extern void GraphU64_ConvertMatrixToFixed(f32 *, void *);

extern void Geometry_DrawIntensityMask(void *, s32, s32);



extern s32 func_802540F4_de(s32, void **, s32, void *, s32);

extern s32 SetN64_GetDirectoryEntry(s32 *, s32, s32);

extern s32 SetN64_LocatePackSection(s32, s32, s32, s32 *);

extern void Cache_UnlockResource(s32, void *);

extern char D_0026D7F4;




void SimpleInstance_SpawnModelEffect(ActorSimpleInstanceSpawnModelEffect *actor, void **resource) {
    CVector3 position;
    CQuatern rotation;
    EffectRecAt154 *effect;
    f32 scale;
    s32 *node;

    if (Geometry_GetViewEffect() != 0) {
        rotation.x = rotation.y = rotation.z = 0.0f;
        rotation.w = D_800C3D90_de;
        node = SetN64_GetPackSection(*resource, 2);
        if ((*node != 0) &&
            (*((s32 *)SetN64_GetPackSection(SetN64_GetPackSection(node, 0), 0)) & 0x8000)) {
            position = actor->position0;
            position.y += GameObject_GetActorHeight(actor) * *(&D_800C3D90_de + 1);
            func_802800C0_de((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)actor, (struct EffectActor *)actor, 0, 0, 0x94,
                          actor->position1, rotation, position, 0, -1, 0);
            effect = Particle_GetLastSpawnedEffect(&D_8011D8D0);
            if (effect != 0) {
                scale = D_800C3D98_de;
                effect->field150 = GameObject_GetActorRadius(actor) * scale;
                effect->field154 = GameObject_GetActorHeight(actor) * scale;
            }
        }
    }
}

void SimpleInstance_DrawGroundShadow(void *actor) {
    f32 matrix[16];
    CVector3 position;
    CQuatern rotation;
    f32 ground;
    f32 height;
    f32 size;
    ground = ((Shared_Func80243A80Actor *)actor)->groundY;
    height = ((Shared_Func80243A80Actor *)actor)->y - ground;
    if (!(RW_MIN_LT(InstHdr_GetActorShadowRadius(actor) * 0.5f, InstHdr_GetActorShadowRadius(actor) * 0.5f - height * 0.1f) < 0.0f)) {
        size = RW_MIN_LT(InstHdr_GetActorShadowRadius(actor) * 0.5f, InstHdr_GetActorShadowRadius(actor) * 0.5f - height * 0.1f);
    } else {
        size = 0.0f;
    }
    rotation = InstHdr_BuildActorGroundRotation(actor);
    position.x = ((Shared_Func80243A80Actor *)actor)->x;
    position.z = ((Shared_Func80243A80Actor *)actor)->z;
    position.y = ground;
    GraphU64_LimitVectorLength(&position, 20000.0f);
    MatrixFromQuaternion(&rotation.x, matrix);
    ScaleMatrixLocal(matrix, size, 1.0f, size);
    TranslateMatrix(matrix, position.x, position.y, position.z);
    GraphU64_ConvertMatrixToFixed(matrix, (char *)actor + ((D_800D297C << 6) + 0xE8));
    Geometry_DrawIntensityMask((char *)actor + ((D_800D297C << 6) + 0xE8), 1, 0x96);
}

void SimpleInstance_RefreshModelResourceUsage(StaticObject *staticObject) {
    void *variantDirectory;
    void **resource;
    s32 key;
    s32 found;
    s32 index;

    index = staticObject->model;
    if (index != staticObject->animation) {
        resource = Cache_RequestResource(0, staticObject->animationKey,
                                staticObject->animationKey, 0x18,
                                0, 0, 0, &D_800C3DA8_de + 4, 1);
        if (resource != 0) {
            key = SetN64_GetDirectoryEntry(*resource, staticObject->animationKey, 1);
            Cache_ReleaseResource(0, resource);
            found = func_802540F4_de(0, &variantDirectory, key, g_simpModelsIndexText, 1);
            if (found != 0) {
                staticObject->resource = SetN64_LocatePackSection((s32)variantDirectory, key,
                                                    index % *(s32 *)variantDirectory,
                                                    &staticObject->resourceSize);
                staticObject->animation = index;
                Cache_ReleaseResource(0, (void *)found);
            }
        }
    }
    if (staticObject->resource != 0) {
        resource = Cache_RequestResource(0, staticObject->resource,
                                staticObject->resource, staticObject->resourceSize,
                                0, 0, &D_0026D7F4, g_simpModelText, 0);
    } else {
        resource = 0;
    }
    if (resource != 0) {
        Geometry_RefreshMaterialResources(resource);
        Cache_UnlockResource(0, resource);
    }
}
