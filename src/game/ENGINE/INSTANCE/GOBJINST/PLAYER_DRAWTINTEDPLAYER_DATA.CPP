#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/UNUSED.H"
#include "RENDER/MATERIAL_COLOR_AND_FOG_VIEWS.H"
#include "COMMON/MODEL_RENDER.H"
#include "COMMON/OBJRECV5.H"
#include "COMMON/OBJECTLINKS180_2.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "TYPES.H"
#include "RENDER/SETN64_GETPACKSECTION.H"
#include "particle/PARTICLE_SPAWNEFFECTGROUP.H"

/* GOBJINST_6.CPP */
/* Refreshes the actor's animation from the lookup through GameObject_DrawActorShadow and Geometry_DrawModelResource and, when the lookup's third node carries flag 0x8000, spawns a 0x94 effect at the actor scaled by its size, then clears D_800D15E0. Adapted from Gobjinst_SpawnAnimatedModelViewEffect with its body moved into a static inline helper, the Gobjinst_DrawMaskedModel update calls added before it, the D_800C8B38 scale constants and the trailing D_800D15E0 clear changed. */

extern char D_8011D8D0;

extern void GameObject_DrawActorShadow(char *obj, s32 unused, char *info);

extern s32 Geometry_GetViewEffect(void);

extern EffectRecAt154 *Particle_GetLastSpawnedEffect(void *system);

extern f32 Gobjinst_GetActorRadius(void *actor);
extern f32 Gobjinst_GetActorHeight(void *actor);
static inline void func_8024A1C0_spawn(Actor_func_8024A1D0_de *actor, Lookup *lookup) {
    CVector3 position;
    EffectRecAt154 *effect;
    f32 scale;
    s32 *node;

    if (Geometry_GetViewEffect() != 0) {
        node = SetN64_GetPackSection(*lookup->value, 2);
        if ((*node != 0) &&
            (*((s32 *)SetN64_GetPackSection(SetN64_GetPackSection(node, 0), 0)) & 0x8000)) {
            position = actor->position0;
            position.y += Gobjinst_GetActorHeight(actor) * D_800C8B38[1];
            Particle_SpawnEffectGroup((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)actor, (struct EffectActor *)actor, 0, 0, 0x94,
                          actor->position1, actor->rotation, position, 0, -1, 0);
            effect = Particle_GetLastSpawnedEffect(&D_8011D8D0);
            if (effect != 0) {
                scale = D_800C3A50_de;
                effect->field150 = Gobjinst_GetActorRadius(actor) * scale;
                effect->field154 = Gobjinst_GetActorHeight(actor) * scale;
            }
        }
    }
}

static inline void spawn(LevelActor *actor) {
    CVector3 position;

    position = actor->position0;
    position.y += Gobjinst_GetActorHeight(actor) * *(&D_800C3A50_de + 1);
    Particle_SpawnEffectGroup((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)actor, (struct EffectActor *)actor, 0, 0, 0x94,
                  actor->position1, actor->rotation, position, 0, -1, 0);
}

void func_8024A1D0_de(Actor_func_8024A1D0_de *actor, void *context, Lookup *lookup) {
    s32 one;

    if (lookup->unk4 != 0) {
        GameObject_DrawActorShadow(actor, context, lookup);
    }
    if (lookup->unk0 != 0) {
        one = 1;
        Geometry_DrawModelResource(lookup->value, actor->animation, one,
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
        GameObject_DrawActorShadow(actor, animationContext, params);
    }
    if (params->drawModel != 0) {
        Geometry_DrawActorModelParts(params->model, player, actor->fieldB4, 1, &actor->lighting[D_800D297C], 0, actor->field3);
        if (Geometry_GetViewEffect() != 0) {
            node = SetN64_GetPackSection(*params->model, 2);
            if ((*node != 0) &&
                (*((s32 *)SetN64_GetPackSection(SetN64_GetPackSection(node, 0), 0)) & 0x8000)) {
                spawn(actor);
                effect = Particle_GetLastSpawnedEffect(&D_8011D8D0);
                if (effect != 0) {
                    scale = D_800C8B48;
                    effect->field150 = Gobjinst_GetActorRadius(actor) * scale;
                    effect->field154 = Gobjinst_GetActorHeight(actor) * scale;
                }
            }
        }
    }
    D_800D15E0 = 0;
}

/* GOBJINST_7.CPP */
/* Optionally runs GameObject_DrawActorShadow, then starts the actor's current block through Geometry_DrawBlendParts and, when the resulting animation node is flagged, spawns an effect at the actor raised by its height and scales it to the actor's size, always clearing D_800D15E0 at the end. Adapted from func_8024A3B0_de with Geometry_DrawActorModelParts changed to Geometry_DrawBlendParts and the height and scale constants taken from D_800C8B48[1] and D_800C8B50. */

extern void Geometry_DrawBlendParts(void **value, s32 arg1, s32 arg2, s32 arg3, BlockRecAt0 *block, s32 arg5, s32 arg6);



static inline void spawn_blend_effect(Actor_func_8024A3B0_de *actor) {
    CVector3 position;

    position = actor->position0;
    position.y += Gobjinst_GetActorHeight(actor) * *(&D_800C8B48 + 1);
    Particle_SpawnEffectGroup((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)actor, (struct EffectActor *)actor, 0, 0, 0x94,
                  actor->position1, actor->rotation, position, 0, -1, 0);
}

void func_8024A5A8_de(Actor_func_8024A3B0_de *actor, s32 drawView, s32 animationContext, Lookup *params) {
    EffectRecAt154 *effect;
    f32 scale;
    s32 *node;

    if (params->unk4 != 0) {
        GameObject_DrawActorShadow(actor, animationContext, params);
    }
    if (params->unk0 != 0) {
        Geometry_DrawBlendParts(params->value, drawView, actor->fieldB4, 1, &actor->blocks[D_800D297C], 0, actor->field3);
        if (Geometry_GetViewEffect() != 0) {
            node = SetN64_GetPackSection(*params->value, 2);
            if ((*node != 0) &&
                (*((s32 *)SetN64_GetPackSection(SetN64_GetPackSection(node, 0), 0)) & 0x8000)) {
                spawn_blend_effect(actor);
                effect = Particle_GetLastSpawnedEffect(&D_8011D8D0);
                if (effect != 0) {
                    scale = D_800C8B50;
                    effect->field150 = Gobjinst_GetActorRadius(actor) * scale;
                    effect->field154 = Gobjinst_GetActorHeight(actor) * scale;
                }
            }
        }
    }
    D_800D15E0 = 0;
}
