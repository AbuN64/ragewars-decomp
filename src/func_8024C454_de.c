#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8024BA6C.h"
#include "types.h"












extern char D_8011D8D0;

extern s32 func_8026E340_de(void);
extern s32 *func_8028FDB4_de(void *value, s32 index);
extern f32 func_8024D284_de(Actor_func_8024A1D0_de *actor);
extern void func_802800C0_de(void *system, Actor_func_8024A1D0_de *source, Actor_func_8024A1D0_de *owner,
                          s32 arg3, s32 arg4, s32 arg5, Vec3 position,
                          Vector4f rotation, Vec3 position2, s32 arg15,
                          s32 arg16, s32 arg17);
extern EffectRecAt154 *func_802830B8_de(void *system);
extern f32 func_8024D398_de(Actor_func_8024A1D0_de *actor);

void func_8024C454_de(Actor_func_8024A1D0_de *actor, LookupRecAtC *lookup) {
    Vec3 position;
    EffectRecAt154 *effect;
    f32 scale;
    s32 *node;

    if (func_8026E340_de() != 0) {
        node = func_8028FDB4_de(*lookup->value, 2);
        if ((*node != 0) &&
            (*func_8028FDB4_de(func_8028FDB4_de(node, 0), 0) & 0x8000)) {
            position = actor->position0;
            position.y += func_8024D284_de(actor) * D_800C3B60_de;
            func_802800C0_de(&D_8011D8D0, actor, actor, 0, 0, 0x94,
                          actor->position1, actor->rotation, position, 0, -1, 0);
            effect = func_802830B8_de(&D_8011D8D0);
            if (effect != 0) {
                scale = *(&D_800C3B60_de + 1);
                effect->field150 = func_8024D398_de(actor) * scale;
                effect->field154 = func_8024D284_de(actor) * scale;
            }
        }
    }
}
