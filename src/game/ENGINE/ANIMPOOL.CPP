#include "COMMON/WORLD.H"
#include "COMMON/LONE/D_800CD764_de.H"
#include "COMMON/LONE/D_800CD8D0.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OBJRECAT5F14.H"
#include "COMMON/VERSION_CALLS.H"

/* Spawns the effect of an item variant: resolves the variant's effect id, loads its descriptor and first record, takes the effect count from the record's model and turns the colour vector by the record's angle, then spawns the effect through the inline spawner of AnimPool_SpawnDescribedSceneEffect with the given owner, position, scale, direction and counted reference, releasing both resources. Adapted from AnimPool_SpawnDescribedSceneEffect with the descriptor loading added. */
#include "TYPES.H"
#include "SCENE/802508E0_4.H"
#include "SCENE/802508E0_9.H"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_7.H"
#include "RENDER_4/8028FD2C_6.H"
extern s32 Render_GetDirectoryEntry(s32, s32, s32);
extern s32 Render_LocatePackSection(void *, s32, s32, s32 *);
extern s32 Engine_GetActorDefinition(void *, s32);
extern f32 func_802B2350(s32);
extern void Particle_ScaleVector(CVector3 *, CVector3 *, f32);
struct Shared_World;
extern s32 func_8028B21C_de(struct Shared_World *, s32);
extern s32 func_8028B25C_de(void *, s32);
extern void func_802466A0_de(SceneEffect *, s32, s32, s32, s32, s32, s32, f32, CVector3, s32, CVector3, CVector3, s32);
extern void func_8024B2D0_de(SceneEffect *);
static inline SceneEffect *take_effect(struct SceneEffectPool *scene, s32 *ref) {
    SceneEffect *effect;
    if (g_world.visibilityEnabled == 0 && (unsigned int)scene->UsedList.count >= 3) {
        return 0;
    }
    effect = scene->FreeList.head;
    if (effect != 0) {
        func_80255ED8_de(&scene->FreeList, effect);
        func_80255CB8_de(&scene->UsedList, effect);
        effect->ref = ref;
        if (ref != 0) {
            *ref += 1;
        }
    }
    return effect;
}
static inline SceneEffect *spawn_effect(struct SceneEffectPool *scene, s32 id, s32 variant, s32 count, s32 owner, CVector3 position,
                                   f32 scale, CVector3 direction, CVector3 color, s32 *ref) {
    SceneEffect *effect;
    if (D_800CD764_de == 0) {
        return 0;
    }
    if (count == 0) {
        return 0;
    }
    if (id == -1) {
        id = func_8028B21C_de(&g_world, variant);
        if (id == -1) {
            return 0;
        }
    }
    if ((unsigned int)(variant + 1) < 2) {
        variant = func_8028B25C_de(&g_world, id);
    }
    effect = take_effect(scene, ref);
    if (effect == 0) {
        return 0;
    }
    func_802466A0_de(effect, id, variant, D_800CD8D0, count, -1, owner, scale, position, 0x80000, color, direction, 0);
    func_8024B2D0_de(effect);
    return effect;
}
SceneEffect *AnimPool_SpawnAnimationObject(struct SceneEffectPool *scene, s32 variant, s32 owner, CVector3 position, f32 scale, CVector3 direction,
                      CVector3 color, s32 *ref) {
    SceneEffect *effect;
    s32 id;
    s32 key;
    void **descriptor;
    void **resource;
    RecordAnimPoolSpawnAnimationObject *record;
    s32 count;
    s32 size;
    s32 clip;
    effect = 0;
    id = func_8028B21C_de(&g_world, variant);
    if (id != -1) {
        key = Render_GetDirectoryEntry((s32)g_world.indexedDirectory, g_world.indexedBank, id);
        descriptor = Scene_RequestResource(0, key, key, 0x18, 0, 0, 0, &s_animObjectIndexText, 1);
        if (descriptor != 0) {
            clip = Render_LocatePackSection(*descriptor, key, 0, &size);
            resource = Scene_RequestResource(0, clip, clip, size, 0, 0, 0, &s_animObjectInfoText, 1);
            if (resource != 0) {
                record = Render_GetPackSection(*resource, 0);
                count = Engine_GetActorDefinition(&g_world, record->count);
                Particle_ScaleVector(&color, &color, func_802B2350(record->angle));
                effect = spawn_effect(scene, id, variant, count, owner, position, scale, direction, color, ref);
                Scene_UnlockResource(0, resource);
            }
            Scene_UnlockResource(0, descriptor);
        }
    }
    return effect;
}
