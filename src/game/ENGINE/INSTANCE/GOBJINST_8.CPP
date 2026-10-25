#include "COMMON/MODEL_RENDER.H"
#include "COMMON/OBJECTLINKS180_2.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "RENDER_4/8028FD2C_6.H"
struct Node80253610;
extern void Scene_MarkResourceInUse(s32 heap, struct Node80253610 *resource);

extern char D_0024D108;
extern char D_800C3A64_de;


extern char D_8011D8D0;

extern void func_8024AA18_de(char *obj, s32 unused, char *info);
extern s32 func_80251F6C_de(s32, s32, void *, s32, s32, void *, void *, void *, s32);
extern void func_8027892C_de(void *object, void *colors);

extern void Scene_UnlockResource(s32, s32);
extern s32 func_8026E340_de(void);
#include "particle/8027A0F4_8.H"
extern EffectRecAt154 *func_802830B8_de(void *system);

static inline void spawn(LevelActor *actor) {
    CVector3 position;

    position = actor->position0;
    position.y += Particle_GetActorHeight(actor) * D_800C3A74_de;
    func_802800C0_de((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)actor, (struct EffectActor *)actor, 0, 0, 0x94,
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
    Scene_MarkResourceInUse(0, resource);
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
        node = Render_GetPackSection(*params->value, 2);
        if ((*node != 0) &&
            (*((s32 *)Render_GetPackSection(Render_GetPackSection(node, 0), 0)) & 0x8000)) {
            spawn(actor);
            effect = func_802830B8_de(&D_8011D8D0);
            if (effect != 0) {
                scale = D_800C3A78_de;
                effect->field150 = func_8024D398_de(actor) * scale;
                effect->field154 = Particle_GetActorHeight(actor) * scale;
            }
        }
    }
    Scene_UnlockResource(0, resource);
}
