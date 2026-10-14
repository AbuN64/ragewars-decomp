#include "span_1000/code_80246E34.h"
#include "span_C76B0/data.h"
#include "types.h"
#include "common/unused.h"
#include "span_1000/code_80246E34.h"


extern char D_0024D108;
extern char D_800C3A64_de;


extern char D_8011D8D0;

extern void func_8024AA18_de(char *obj, s32 unused, char *info);
extern s32 func_80251F6C_de(s32, s32, void *, s32, s32, void *, void *, void *, s32);
extern void func_8027892C_de(void *object, void *colors);
extern void func_8026DA4C_de(void **value, s32 arg1, s32 arg2, s32 arg3, void *arg4, s32 arg5);
extern void func_80253754_de(s32, s32);
extern s32 func_8026E340_de(void);
extern s32 *func_8028FDB4_de(void *value, s32 index);
extern void func_802800C0_de(void *system, LevelActor *source, LevelActor *owner,
                          s32 arg3, s32 arg4, s32 arg5, Vec3 position,
                          Vector4f rotation, Vec3 position2, s32 arg15,
                          s32 arg16, s32 arg17);
extern EffectRecAt154 *func_802830B8_de(void *system);

static inline void spawn(LevelActor *actor) {
    Vec3 position;

    position = actor->position0;
    position.y += func_8024D284_de(actor) * D_800C3A74_de;
    func_802800C0_de(&D_8011D8D0, actor, actor, 0, 0, 0x94,
                  actor->position1, actor->rotation, position, 0, -1, 0);
}

void func_8024A7A0_de(LevelActor *actor, s32 arg1, Lookup *params) {
    EffectRecAt154 *effect;
    f32 scale;
    s32 *node;
    s32 resource;
    s32 *header;
    char *data;

    actor->mask = 1 << actor->team;
    if (params->unk4 != 0) {
        func_8024AA18_de(actor, arg1, params);
    }
    if (params->unk0 == 0) {
        return;
    }
    resource = func_80251F6C_de(0, actor->flags2E4 | D_800CD3F0, params->value, 0, 0,
                             actor, &D_0024D108, &D_800C3A64_de, 1);
    if (resource == 0) {
        return;
    }
    func_80253BBC_de(0, resource);
    header = *(s32 **)resource;
    if (header[0] == 1) {
        char *object = (char *)header + header[1];

        func_8027892C_de(object, (char *)header + header[2]);
        data = object;
    } else {
        data = (char *)(header + 2);
    }
    func_8026DA4C_de(params->value, actor->fieldB4, 1, 0, data, actor->field3);
    if (func_8026E340_de() != 0) {
        node = func_8028FDB4_de(*params->value, 2);
        if ((*node != 0) &&
            (*func_8028FDB4_de(func_8028FDB4_de(node, 0), 0) & 0x8000)) {
            spawn(actor);
            effect = func_802830B8_de(&D_8011D8D0);
            if (effect != 0) {
                scale = D_800C3A78_de;
                effect->field150 = func_8024D398_de(actor) * scale;
                effect->field154 = func_8024D284_de(actor) * scale;
            }
        }
    }
    func_80253754_de(0, resource);
}
