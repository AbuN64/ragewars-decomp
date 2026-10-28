#include "COMMON/MODEL_RENDER.H"
#include "RSP/8026E1F8_5.H"
#include "COMMON/LISTHEADER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJECTLINKS180_2.H"
#include "TYPES.H"
#include "ENGINE/INSTANCE/GOBJINST_11.H"
#include "SCENE/802508E0_4.H"
#include "RENDER/8028FD2C_6.H"
#include "LISTS/80279520.H"

extern s32 Cinema_IsSequenceInWindow(void);
extern CQuatern Gobjinst_BuildActorDirectionTilt(void *arg1);


extern void MultiplyQuaternions(CQuatern *arg0, CQuatern *arg1, CQuatern *arg2);
extern void MatrixFromQuaternion(void *, void *);
extern void ScaleMatrixLocal(void *arg0, f32 sx, f32 sy, f32 sz);
extern s32 Graphu64_LimitVectorLength(f32 *arg0, f32 arg1);
extern void TranslateMatrix(char *, f32, f32, f32);
extern void SwapMatrixUpForward(void *);


void Gobjinst_BuildActorTransform(void *levelActor) {
    CQuatern trig;
    CQuatern product;
    CQuatern copy;
    CQuatern *copy_ptr;
    CQuatern *product_ptr;
    char *transform;
    f32 scale;
    f32 sine;
    f32 angle;

    copy = ((struct LevelActor *)(levelActor))->rotation;
    copy_ptr = &copy;
    if (Cinema_IsSequenceInWindow() != 0) {
        copy = Gobjinst_BuildActorDirectionTilt(levelActor);
    }

    angle = ((struct LevelActor *)(levelActor))->yaw;
    scale = (0.5f);
    sine = Math_Sinf(angle * scale);
    trig.x = 0.0f;
    trig.y = sine;
    trig.z = 0.0f;
    angle = ((struct LevelActor *)(levelActor))->yaw * scale;
    D_80115DEC = sine;
    trig.w = Math_Cosf(angle);

    product_ptr = &product;
    MultiplyQuaternions(product_ptr, &trig, copy_ptr);
    transform = &((struct LevelActor *)(levelActor))->transform[0];
    MatrixFromQuaternion(product_ptr, transform);
    ScaleMatrixLocal(transform, ((struct LevelActor *)(levelActor))->scale.x,
                    ((struct LevelActor *)(levelActor))->scale.y,
                    ((struct LevelActor *)(levelActor))->scale.z);
    Graphu64_LimitVectorLength(&((struct LevelActor *)(levelActor))->position0.x, 20000.0f);
    TranslateMatrix(transform, ((struct LevelActor *)(levelActor))->position0.x,
                   ((struct LevelActor *)(levelActor))->position0.y,
                   ((struct LevelActor *)(levelActor))->position0.z);
    SwapMatrixUpForward(transform);
}

void Gobjinst_NoOperation(void) {
}

void Gobjinst_QueueAnimation(void *actorStorage, unsigned int animationIndex)
{
  ((struct LevelActor *)(actorStorage))->nextAnimation = animationIndex;
  ((struct LevelActor *)(actorStorage))->animationPending = 0;
  if ((((struct LevelActor *)(actorStorage))->animation) != animationIndex)
  {
    ((struct LevelActor *)(actorStorage))->animationChanged = 1;
  }
}

void Gobjinst_RestartAnimation(void *actorAnimationState) {
    (((struct ObjectState110 *) ((s8 *) actorAnimationState))->unk_10F) = 1;
    (((struct ObjectState110 *) ((s8 *) actorAnimationState))->unk_104) = 0;
    (((struct ObjectState110 *) ((s8 *) actorAnimationState))->unk_10E) = 0;
    (((struct ObjectState110 *) ((s8 *) actorAnimationState))->unk_100) = (s32) ((((struct ObjectState110 *) ((s8 *) actorAnimationState))->unk_100) & ~0x400);
}

extern s32 Gobjinst_ChooseAnimationVariant(void *, s32, s32);


s32 Gobjinst_RequestAnimationKind(void *a, s32 c, s32 flag) {
    s32 selectedAnimation = Gobjinst_ChooseAnimationVariant(a, c, -1);

    if (selectedAnimation != -1) {
        return Gobjinst_RequestAnimationIndex(a, selectedAnimation, flag);
    }
    return 0;
}

extern void Gobjinst_QueueAnimation(void *arg0, u32 arg1);

s32 Gobjinst_RequestAnimationIndex(void *levelActor, s32 animationIndex, s32 allowDuringBlend) {
    if (animationIndex < 0 || (allowDuringBlend == 0 && (((struct LevelActor *)(levelActor))->flags & 0x400))) {
        return 0;
    }
    Gobjinst_QueueAnimation(levelActor, (u32) animationIndex);
    return 1;
}

extern void Lists_ClearWeightedTable(WeightedTable *arg0);
extern s32 Gobjinst_ChooseAnimationVariant(void *arg0, s32 arg1, s32 arg2);

s16 Gobjinst_ChooseAvailableAnimationKind(void *actor, s16 *callback, s32 excludedAnimation) {
    WeightedTable eligibleKinds;
    u16 animationKind;

    Lists_ClearWeightedTable(&eligibleKinds);
    animationKind = *(u16 *) callback;
    if (*callback != -1) {
        do {
            if (Gobjinst_ChooseAnimationVariant(actor, (s32) (s16) animationKind, excludedAnimation) != -1) {
                Lists_AppendWeightedEntry(&eligibleKinds, callback[0], callback[1]);
            }
            callback += 2;
            animationKind = *(u16 *) callback;
        } while (*callback != -1);
    }
    return Lists_ChooseWeightedTableEntry(&eligibleKinds);
}

extern s32 *Gobjinst_RequestAnimatedModelVariant(void *arg0, s8 arg1);
extern s32 Gobjinst_BuildActorPose(void *arg0, s32 arg1, void *arg2);
extern void Cache_UnlockResource(s32 arg0, s32 arg1);

s32 Gobjinst_BuildAnimatedPose(void *actorStorage, s32 resourceRequestMode)
{
  void *resource;
  s32 *entry;
  s32 value;
  s32 result;
  result = 0;
  if ((((struct LevelActor *)(actorStorage))->flags) & 0x40000)
  {
    if (resource)
    {
      resource = Cache_RequestResource(0, ((struct LevelActor *)(actorStorage))->resource, ((struct LevelActor *)(actorStorage))->resource, ((struct LevelActor *)(actorStorage))->resourceFlags, 0, 0, 0, (&D_800C39E0_de) + 4, resourceRequestMode);
    }
    else
    {
      resource = Cache_RequestResource(0, ((struct LevelActor *)(actorStorage))->resource, ((struct LevelActor *)(actorStorage))->resource, ((struct LevelActor *)(actorStorage))->resourceFlags, 0, 0, 0, (&D_800C39E0_de) + 4, resourceRequestMode);
    }
    if (resource == 0)
    {
      return result;
    }
    entry = Gobjinst_RequestAnimatedModelVariant(actorStorage, ((struct LevelActor *)(actorStorage))->team);
    if (entry != 0)
    {
      value = *entry;
      result = Gobjinst_BuildActorPose(actorStorage, value, SetN64_GetPackSection(*((void **) resource), 0));
      Cache_UnlockResource(0, (s32) entry);
    }
    Cache_UnlockResource(0, (s32) resource);
  }
  return result;
}

void Gobjinst_RotatePoseMatrixBuffers(void *actorRenderState) {
    s32 previousPoseMatrices;
    previousPoseMatrices = (((struct IntegerState104 *) ((s8 *) actorRenderState))->unk_B4);
    (((struct IntegerState104 *) ((s8 *) actorRenderState))->unk_B4) = 0;
    (((struct IntegerState104 *) ((s8 *) actorRenderState))->unk_BC) = 0;
    (((struct IntegerState104 *) ((s8 *) actorRenderState))->unk_C0) = 0;
    (((struct IntegerState104 *) ((s8 *) actorRenderState))->unk_100) = (s32) ((((struct IntegerState104 *) ((s8 *) actorRenderState))->unk_100) & ~0x200);
    (((struct IntegerState104 *) ((s8 *) actorRenderState))->unk_B8) = previousPoseMatrices;
}

extern s32 D_800D297C;
extern void func_8024AA18_de(char *obj, s32 unused, char *info);
extern void Gobjinst_SpawnAnimatedModelViewEffect(void *arg0, void *arg1);

void Gobjinst_DrawMaskedModel(void *actor, void *unusedShadowContext, void *renderSettings) {
    s8 index;
    s32 one;

    index = ((struct LevelActor *)(actor))->team;
    if (index != -1) {
        ((struct LevelActor *)(actor))->mask = 1 << index;
        if (((struct ActorRenderSettings *)(renderSettings))->drawShadow != 0) {
            func_8024AA18_de(actor, unusedShadowContext, renderSettings);
        }
        if (*(s32 *)renderSettings != 0) {
            one = 1;
            Geometry_DrawModelResource(((struct ActorRenderSettings *)(renderSettings))->view,
                          ((struct LevelActor *)(actor))->fieldB4, one,
                          (char *)actor
                              + ((((D_800D297C << one) + D_800D297C) << 3)
                                 + 0x140),
                          0, ((struct LevelActor *)(actor))->field3);
            Gobjinst_SpawnAnimatedModelViewEffect(actor, renderSettings);
        }
    }
}


void Gobjinst_DrawMaskedModelWithLighting(void *actor, void *unusedShadowContext, void *renderSettings, Block24 *lighting) {
    s8 index;
    s32 one;

    ((ObjectRecAt140 *)actor)->blocks[D_800D297C] = *lighting;
    index = ((struct LevelActor *)(actor))->team;
    if (index != -1) {
        ((struct LevelActor *)(actor))->mask = 1 << index;
        if (((struct ActorRenderSettings *)(renderSettings))->drawShadow != 0) {
            func_8024AA18_de(actor, unusedShadowContext, renderSettings);
        }
        if (*(s32 *)renderSettings != 0) {
            one = 1;
            Geometry_DrawModelResource(((struct ActorRenderSettings *)(renderSettings))->view,
                          ((struct LevelActor *)(actor))->fieldB4, one,
                          (char *)actor
                              + ((((D_800D297C << one) + D_800D297C) << 3)
                                 + 0x140),
                          0, ((struct LevelActor *)(actor))->field3);
            Gobjinst_SpawnAnimatedModelViewEffect(actor, renderSettings);
        }
    }
}
