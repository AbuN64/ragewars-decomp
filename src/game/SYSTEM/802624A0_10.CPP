#include "COMMON/OBJRECAT5F14.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/WORLD.H"
#include "COMMON/S1.H"
#include "TYPES.H"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_7.H"

/* Spawns an effect in a scene when effects are enabled and a count is given: resolves a missing effect id
 * from the variant (func_8028B21C_de, giving up when unknown) and a default variant from the id
 * (func_8028B25C_de), takes a node from the scene's free list when allowed (always with D_8013B290, otherwise
 * while fewer than three are active), moves it to the active list and attaches the counted reference, then
 * initialises it through func_802466A0_de with the position, scale, direction and colour vectors and starts it
 * with func_8024B2D0_de. Returns the effect or 0. */





extern s32 D_800CD764_de;

extern s32 D_800CD8D0;

extern s32 D_8013B290;

extern s32 func_8028B21C_de(struct Shared_World *, s32);

extern s32 func_8028B25C_de(void *, s32);

extern void func_802466A0_de(SceneEffect *, s32, s32, s32, s32, s32, s32, f32, CVector3, s32, CVector3, CVector3, s32);

extern void func_8024B2D0_de(SceneEffect *);

static inline SceneEffect *take_effect(struct SceneEffectPool *scene, s32 *ref) {
    SceneEffect *effect;

    if (D_8013B290 == 0 && (unsigned int)scene->UsedList.count >= 3) {
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

/* Culls a scene's active effects against the view box: effects whose bounds overlap the box ending at
 * D_801031F8 + 4 are passed to func_8028C934_de and, when idle, drop their counted reference; the others are
 * reset, release their reference, and are unlinked from the active list (func_80255ED8_de) and returned to
 * the free list (func_80255D14_de). */



extern f32 D_801031F8;

extern void func_8028C934_de(s32, Effect_func_80262E88_de *);

static inline s32 overlaps(Effect_func_80262E88_de *effect, f32 *max) {
    if (max[0] > effect->min[0] && max[-3] < effect->max[0] && max[2] > effect->min[2] &&
        max[-1] < effect->max[2] && max[1] > effect->min[1] && max[-2] < effect->max[1]) {
        return 1;
    }
    return 0;
}

SceneEffect *func_80262CE0_de(struct SceneEffectPool *scene, s32 id, s32 variant, s32 count, s32 owner, CVector3 position, f32 scale,
                      CVector3 direction, CVector3 color, s32 *ref) {
    SceneEffect *effect;

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

void func_80262E88_de(struct SceneEffectPool *scene, s32 arg1) {
    Effect_func_80262E88_de *effect;
    Effect_func_80262E88_de *next;
    f32 *max;

    effect = scene->UsedList.head;
    if (effect == 0) {
        return;
    }
    do {
        max = (&D_801031F8 + 1);
    next_effect:
        next = effect->next;
        if (overlaps(effect, max)) {
            func_8028C934_de(arg1, effect);
            if (effect->ref != 0 && effect->busy == 0) {
                *effect->ref -= 1;
                effect->ref = 0;
            }
        } else {
            effect->busy = 0;
            effect->flags &= ~0x200;
            if (effect->ref != 0) {
                *effect->ref -= 1;
            }
            func_80255ED8_de(&scene->UsedList, effect);
            func_80255D14_de(&scene->FreeList, effect);
        }
        effect = next;
    } while (0);
    if (effect != 0) {
        goto next_effect;
    }
}

void *func_80262FF8_de(s32 arg0, s32 *arg1) {
    void *temp_s0;

    if ((D_8013B290 != 0) || ((u32)((struct ObjectLinks5F28 *) arg0)->unk_5F24 < 3)) {
        temp_s0 = ((struct ObjectLinks5F28 *) arg0)->unk_5F00;
        if (temp_s0 != 0) {
            func_80255ED8_de((void *)(arg0 + 0x5F00), temp_s0);
            func_80255CB8_de((void *)(arg0 + 0x5F14), temp_s0);
            ((SceneEffect *)(temp_s0))->ref = arg1;
            if (arg1 != 0) {
                *arg1 += 1;
            }
        }
        return temp_s0;
    }
    return 0;
}
