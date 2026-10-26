#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/UNUSED.H"
#include "RENDER_4/8026AC38.H"
#include "COMMON/MODEL_RENDER.H"
#include "COMMON/OBJRECV5.H"
#include "COMMON/OBJECTLINKS180_2.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "TYPES.H"
#include "RENDER_4/8028FD2C_6.H"

/* Refreshes the actor's animation from the lookup through func_8024AA18_de and func_8026DA4C_de and, when the lookup's third node carries flag 0x8000, spawns a 0x94 effect at the actor scaled by its size, then clears D_800D15E0. Adapted from func_8024C454_de with its body moved into a static inline helper, the func_8024B8EC_de update calls added before it, the D_800C8B38 scale constants and the trailing D_800D15E0 clear changed. */












extern char D_8011D8D0;



extern void func_8024AA18_de(char *obj, s32 unused, char *info);

extern s32 func_8026E340_de(void);


extern EffectRecAt154 *func_802830B8_de(void *system);

#include "particle/8027A0F4_8.H"
extern f32 Particle_GetActorRadius(void *actor);
extern f32 Particle_GetActorHeight(void *actor);
static inline void func_8024A1C0_spawn(Actor_func_8024A1D0_de *actor, Lookup *lookup) {
    CVector3 position;
    EffectRecAt154 *effect;
    f32 scale;
    s32 *node;

    if (func_8026E340_de() != 0) {
        node = Render_GetPackSection(*lookup->value, 2);
        if ((*node != 0) &&
            (*((s32 *)Render_GetPackSection(Render_GetPackSection(node, 0), 0)) & 0x8000)) {
            position = actor->position0;
            position.y += Particle_GetActorHeight(actor) * D_800C8B38[1];
            func_802800C0_de((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)actor, (struct EffectActor *)actor, 0, 0, 0x94,
                          actor->position1, actor->rotation, position, 0, -1, 0);
            effect = func_802830B8_de(&D_8011D8D0);
            if (effect != 0) {
                scale = D_800C3A50_de;
                effect->field150 = Particle_GetActorRadius(actor) * scale;
                effect->field154 = Particle_GetActorHeight(actor) * scale;
            }
        }
    }
}

static inline void spawn(LevelActor *actor) {
    CVector3 position;

    position = actor->position0;
    position.y += Particle_GetActorHeight(actor) * *(&D_800C3A50_de + 1);
    func_802800C0_de((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)actor, (struct EffectActor *)actor, 0, 0, 0x94,
                  actor->position1, actor->rotation, position, 0, -1, 0);
}

void func_8024A1D0_de(Actor_func_8024A1D0_de *actor, void *context, Lookup *lookup) {
    s32 one;

    if (lookup->unk4 != 0) {
        func_8024AA18_de(actor, context, lookup);
    }
    if (lookup->unk0 != 0) {
        one = 1;
        func_8026DA4C_de(lookup->value, actor->animation, one,
                      &actor->lighting[D_800D297C],
                      0, actor->pass);
        func_8024A1C0_spawn(actor, lookup);
    }
    D_800D15E0 = 0;
}

void func_8024A3B0_de(LevelActor *actor, PlayerCode80225D10 *player, s32 animationContext, Draw *params) {
    EffectRecAt154 *effect;
    f32 scale;
    s32 *node;

    if (params->updateAnimation != 0) {
        func_8024AA18_de(actor, animationContext, params);
    }
    if (params->drawModel != 0) {
        Render_DrawActorModelParts(params->model, player, actor->fieldB4, 1, &actor->lighting[D_800D297C], 0, actor->field3);
        if (func_8026E340_de() != 0) {
            node = Render_GetPackSection(*params->model, 2);
            if ((*node != 0) &&
                (*((s32 *)Render_GetPackSection(Render_GetPackSection(node, 0), 0)) & 0x8000)) {
                spawn(actor);
                effect = func_802830B8_de(&D_8011D8D0);
                if (effect != 0) {
                    scale = D_800C8B48;
                    effect->field150 = Particle_GetActorRadius(actor) * scale;
                    effect->field154 = Particle_GetActorHeight(actor) * scale;
                }
            }
        }
    }
    D_800D15E0 = 0;
}
