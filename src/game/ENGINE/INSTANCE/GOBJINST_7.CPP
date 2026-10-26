#include "COMMON/VECTOR4F.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "RENDER_4/8026AC38.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OBJECTLINKS180_2.H"
#include "TYPES.H"
#include "RENDER_4/8028FD2C_6.H"

/* Optionally runs func_8024AA18_de, then starts the actor's current block through Geometry_DrawBlendParts and, when the resulting animation node is flagged, spawns an effect at the actor raised by its height and scales it to the actor's size, always clearing D_800D15E0 at the end. Adapted from func_8024A3B0_de with Geometry_DrawActorModelParts changed to Geometry_DrawBlendParts and the height and scale constants taken from D_800C8B48[1] and D_800C8B50. */















extern char D_8011D8D0;

extern void func_8024AA18_de(char *obj, s32 unused, char *info);
extern void Geometry_DrawBlendParts(void **value, s32 arg1, s32 arg2, s32 arg3, BlockRecAt0 *block, s32 arg5, s32 arg6);
extern s32 Geometry_GetViewEffect(void);
extern f32 GameObject_GetActorHeight(Actor_func_8024A3B0_de *actor);
#include "particle/8027A0F4_8.H"
extern EffectRecAt154 *func_802830B8_de(void *system);
extern f32 GameObject_GetActorRadius(Actor_func_8024A3B0_de *actor);

static inline void spawn(Actor_func_8024A3B0_de *actor) {
    CVector3 position;

    position = actor->position0;
    position.y += GameObject_GetActorHeight(actor) * *(&D_800C8B48 + 1);
    func_802800C0_de((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)actor, (struct EffectActor *)actor, 0, 0, 0x94,
                  actor->position1, actor->rotation, position, 0, -1, 0);
}

void func_8024A5A8_de(Actor_func_8024A3B0_de *actor, s32 drawView, s32 animationContext, Lookup *params) {
    EffectRecAt154 *effect;
    f32 scale;
    s32 *node;

    if (params->unk4 != 0) {
        func_8024AA18_de(actor, animationContext, params);
    }
    if (params->unk0 != 0) {
        Geometry_DrawBlendParts(params->value, drawView, actor->fieldB4, 1, &actor->blocks[D_800D297C], 0, actor->field3);
        if (Geometry_GetViewEffect() != 0) {
            node = SetN64_GetPackSection(*params->value, 2);
            if ((*node != 0) &&
                (*((s32 *)SetN64_GetPackSection(SetN64_GetPackSection(node, 0), 0)) & 0x8000)) {
                spawn(actor);
                effect = func_802830B8_de(&D_8011D8D0);
                if (effect != 0) {
                    scale = D_800C8B50;
                    effect->field150 = GameObject_GetActorRadius(actor) * scale;
                    effect->field154 = GameObject_GetActorHeight(actor) * scale;
                }
            }
        }
    }
    D_800D15E0 = 0;
}
