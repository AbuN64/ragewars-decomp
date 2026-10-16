#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80246E34.h"
#include "TYPES.H"

/* Optionally runs func_8024AA18_de, then starts the actor's current block through func_8026DD50_de and, when the resulting animation node is flagged, spawns an effect at the actor raised by its height and scales it to the actor's size, always clearing D_800D15E0 at the end. Adapted from func_8024A3B0_de with func_8026B6A0_de changed to func_8026DD50_de and the height and scale constants taken from D_800C8B48[1] and D_800C8B50. */













extern s32 D_800D297C;
extern s32 D_800D15E0;


extern char D_8011D8D0;

extern void func_8024AA18_de(char *obj, s32 unused, char *info);
extern void func_8026DD50_de(void **value, s32 arg1, s32 arg2, s32 arg3, BlockRecAt0 *block, s32 arg5, s32 arg6);
extern s32 func_8026E340_de(void);
extern s32 *func_8028FDB4_de(void *value, s32 index);
extern f32 func_8024D284_de(Actor_func_8024A3B0_de *actor);
extern void func_802800C0_de(void *system, Actor_func_8024A3B0_de *source, Actor_func_8024A3B0_de *owner,
                          s32 arg3, s32 arg4, s32 arg5, Vec3 position,
                          Vector4f rotation, Vec3 position2, s32 arg15,
                          s32 arg16, s32 arg17);
extern EffectRecAt154 *func_802830B8_de(void *system);
extern f32 func_8024D398_de(Actor_func_8024A3B0_de *actor);

static inline void spawn(Actor_func_8024A3B0_de *actor) {
    Vec3 position;

    position = actor->position0;
    position.y += func_8024D284_de(actor) * *(&D_800C8B48 + 1);
    func_802800C0_de(&D_8011D8D0, actor, actor, 0, 0, 0x94,
                  actor->position1, actor->rotation, position, 0, -1, 0);
}

void func_8024A5A8_de(Actor_func_8024A3B0_de *actor, s32 arg1, s32 arg2, Lookup *params) {
    EffectRecAt154 *effect;
    f32 scale;
    s32 *node;

    if (params->unk4 != 0) {
        func_8024AA18_de(actor, arg2, params);
    }
    if (params->unk0 != 0) {
        func_8026DD50_de(params->value, arg1, actor->fieldB4, 1, &actor->blocks[D_800D297C], 0, actor->field3);
        if (func_8026E340_de() != 0) {
            node = func_8028FDB4_de(*params->value, 2);
            if ((*node != 0) &&
                (*func_8028FDB4_de(func_8028FDB4_de(node, 0), 0) & 0x8000)) {
                spawn(actor);
                effect = func_802830B8_de(&D_8011D8D0);
                if (effect != 0) {
                    scale = D_800C8B50;
                    effect->field150 = func_8024D398_de(actor) * scale;
                    effect->field154 = func_8024D284_de(actor) * scale;
                }
            }
        }
    }
    D_800D15E0 = 0;
}
