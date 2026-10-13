#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80246E34.h"
#include "types.h"
/* Refreshes the actor's animation from the lookup through func_8024AA18_de and func_8026DA4C_de and, when the lookup's third node carries flag 0x8000, spawns a 0x94 effect at the actor scaled by its size, then clears D_800D15E0. Adapted from func_8024C454_de with its body moved into a static inline helper, the func_8024B8EC_de update calls added before it, the D_800C8B38 scale constants and the trailing D_800D15E0 clear changed. */











extern f32 D_800C8B38[];

extern char D_8011D8D0;
extern s32 D_800D297C;
extern s32 D_800D15E0;

extern void func_8024AA18_de(void *arg0, void *arg1, void *arg2);
extern void func_8026DA4C_de();
extern s32 func_8026E340_de(void);
extern s32 *func_8028FDB4_de(void *value, s32 index);
extern f32 func_8024D284_de(Actor_func_8024A1D0_de *actor);
extern void func_802800C0_de(void *system, Actor_func_8024A1D0_de *source, Actor_func_8024A1D0_de *owner,
                          s32 arg3, s32 arg4, s32 arg5, Vec3 position,
                          Vector4f rotation, Vec3 position2, s32 arg15,
                          s32 arg16, s32 arg17);
extern Effect_func_8024A1D0_de *func_802830B8_de(void *system);
extern f32 func_8024D398_de(Actor_func_8024A1D0_de *actor);

static inline void func_8024A1C0_spawn(Actor_func_8024A1D0_de *actor, Lookup *lookup) {
    Vec3 position;
    Effect_func_8024A1D0_de *effect;
    f32 scale;
    s32 *node;

    if (func_8026E340_de() != 0) {
        node = func_8028FDB4_de(*lookup->value, 2);
        if ((*node != 0) &&
            (*func_8028FDB4_de(func_8028FDB4_de(node, 0), 0) & 0x8000)) {
            position = actor->position0;
            position.y += func_8024D284_de(actor) * D_800C8B38[1];
            func_802800C0_de(&D_8011D8D0, actor, actor, 0, 0, 0x94,
                          actor->position1, actor->rotation, position, 0, -1, 0);
            effect = func_802830B8_de(&D_8011D8D0);
            if (effect != 0) {
                scale = D_800C3A50_de;
                effect->field150 = func_8024D398_de(actor) * scale;
                effect->field154 = func_8024D284_de(actor) * scale;
            }
        }
    }
}




void func_8024A1D0_de(Actor_func_8024A1D0_de *actor, void *arg1, Lookup *lookup) {
    s32 one;

    if (lookup->unk4 != 0) {
        func_8024AA18_de(actor, arg1, lookup);
    }
    if (lookup->unk0 != 0) {
        one = 1;
        func_8026DA4C_de((s32)lookup->value, ((Actor_func_8024A3B0_de *)actor)->fieldB4, one,
                      (char *)actor + ((((D_800D297C << one) + D_800D297C) << 3) + 0x140),
                      0, ((Actor_func_8024A3B0_de *)actor)->field3);
        func_8024A1C0_spawn(actor, lookup);
    }
    D_800D15E0 = 0;
}
