#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_802624A0.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"
/* Culls a scene's active effects against the view box: effects whose bounds overlap the box ending at
 * D_801031F8 + 4 are passed to func_8028C934_de and, when idle, drop their counted reference; the others are
 * reset, release their reference, and are unlinked from the active list (func_80255ED8_de) and returned to
 * the free list (func_80255D14_de). */



extern f32 D_801031F8;
extern void func_8028C934_de(s32, Effect_func_80262E88_de *);
extern void func_80255ED8_de(void *, Effect_func_80262E88_de *);

static inline s32 overlaps(Effect_func_80262E88_de *effect, f32 *max) {
    if (max[0] > effect->min[0] && max[-3] < effect->max[0] && max[2] > effect->min[2] &&
        max[-1] < effect->max[2] && max[1] > effect->min[1] && max[-2] < effect->max[1]) {
        return 1;
    }
    return 0;
}







void func_80262E88_de(struct SceneEffectPool *scene, s32 arg1) {
    Effect_func_80262E88_de *effect;
    Effect_func_80262E88_de *next;
    f32 *max;

    effect = scene->activeEffects.head;
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
            func_80255ED8_de(&scene->activeEffects, effect);
            func_80255D14_de(&scene->freeEffects, effect);
        }
        effect = next;
    } while (0);
    if (effect != 0) {
        goto next_effect;
    }
}
