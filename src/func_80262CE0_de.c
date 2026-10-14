#include "shared/world.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802624A0.h"
#include "types.h"
/* Spawns an effect in a scene when effects are enabled and a count is given: resolves a missing effect id
 * from the variant (func_8028B21C_de, giving up when unknown) and a default variant from the id
 * (func_8028B25C_de), takes a node from the scene's free list when allowed (always with D_8013B290, otherwise
 * while fewer than three are active), moves it to the active list and attaches the counted reference, then
 * initialises it through func_802466A0_de with the position, scale, direction and colour vectors and starts it
 * with func_8024B2D0_de. Returns the effect or 0. */





extern s32 D_800CD764_de;
extern s32 D_800CD8D0;
extern s32 D_8013B290;

extern s32 func_8028B21C_de(void *, s32);
extern s32 func_8028B25C_de(void *, s32);
extern void func_80255ED8_de(void *, Actor_func_80290238_de *);
extern void func_80255CB8_de(void *, Actor_func_80290238_de *);
extern void func_802466A0_de(Actor_func_80290238_de *, s32, s32, s32, s32, s32, s32, f32, Vec3, s32, Vec3, Vec3, s32);
extern void func_8024B2D0_de(Actor_func_80290238_de *);





static inline Actor_func_80290238_de *take_effect(struct SceneEffectPool *scene, s32 *ref) {
    Actor_func_80290238_de *effect;

    if (D_8013B290 == 0 && (unsigned int)scene->activeEffects.count >= 3) {
        return 0;
    }
    effect = scene->freeEffects.head;
    if (effect != 0) {
        func_80255ED8_de(&scene->freeEffects, effect);
        func_80255CB8_de(&scene->activeEffects, effect);
        effect->ref = ref;
        if (ref != 0) {
            *ref += 1;
        }
    }
    return effect;
}

Actor_func_80290238_de *func_80262CE0_de(struct SceneEffectPool *scene, s32 id, s32 variant, s32 count, s32 owner, Vec3 position, f32 scale,
                      Vec3 direction, Vec3 color, s32 *ref) {
    Actor_func_80290238_de *effect;

    if (D_800CD764_de == 0 || count == 0) {
        return 0;
    }
    if (id == -1) {
        id = func_8028B21C_de(&D_8011FE88, variant);
        if (id == -1) {
            return 0;
        }
    }
    if ((unsigned int)(variant + 1) < 2) {
        variant = func_8028B25C_de(&D_8011FE88, id);
    }
    effect = take_effect(scene, ref);
    if (effect == 0) {
        return 0;
    }
    func_802466A0_de(effect, id, variant, D_800CD8D0, count, -1, owner, scale, position, 0x80000, color, direction, 0);
    func_8024B2D0_de(effect);
    return effect;
}
