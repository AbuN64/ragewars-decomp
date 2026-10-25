#include "COMMON/MODEL_RENDER.H"
#include "COMMON/LISTHEADER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJECTLINKS180_2.H"
#include "TYPES.H"
#include "ENGINE/INSTANCE/GOBJINST_11.H"
#include "SCENE/802508E0_4.H"
#include "RENDER_4/8028FD2C_6.H"
#include "LISTS/80279520.H"

extern s32 Camera_IsSequenceInWindow(void);
extern CQuatern func_8024D728_de(void *arg1);


extern void MultiplyQuaternions(CQuatern *arg0, CQuatern *arg1, CQuatern *arg2);
extern void MatrixFromQuaternion(void *, void *);
extern void func_8027347C_de(void *arg0, f32 sx, f32 sy, f32 sz);
extern s32 func_8027254C_de(f32 *arg0, f32 arg1);
extern void TranslateMatrix(char *, f32, f32, f32);
extern void SwapMatrixUpForward(void *);

extern f32 D_80115DEC;

void func_8024B53C_de(void *levelActor) {
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
    if (Camera_IsSequenceInWindow() != 0) {
        copy = func_8024D728_de(levelActor);
    }

    angle = ((struct LevelActor *)(levelActor))->yaw;
    scale = (0.5f);
    sine = func_802B7130_de(angle * scale);
    trig.x = 0.0f;
    trig.y = sine;
    trig.z = 0.0f;
    angle = ((struct LevelActor *)(levelActor))->yaw * scale;
    D_80115DEC = sine;
    trig.w = func_802B6560_de(angle);

    product_ptr = &product;
    MultiplyQuaternions(product_ptr, &trig, copy_ptr);
    transform = &((struct LevelActor *)(levelActor))->transform[0];
    MatrixFromQuaternion(product_ptr, transform);
    func_8027347C_de(transform, ((struct LevelActor *)(levelActor))->scale.x,
                    ((struct LevelActor *)(levelActor))->scale.y,
                    ((struct LevelActor *)(levelActor))->scale.z);
    func_8027254C_de(&((struct LevelActor *)(levelActor))->position0.x, 20000.0f);
    TranslateMatrix(transform, ((struct LevelActor *)(levelActor))->position0.x,
                   ((struct LevelActor *)(levelActor))->position0.y,
                   ((struct LevelActor *)(levelActor))->position0.z);
    SwapMatrixUpForward(transform);
}

void func_8024B654_de(void) {
}

void func_8024B65C_de(void *arg0, unsigned int arg1)
{
  ((struct LevelActor *)(arg0))->nextAnimation = arg1;
  ((struct LevelActor *)(arg0))->animationPending = 0;
  if ((((struct LevelActor *)(arg0))->animation) != arg1)
  {
    ((struct LevelActor *)(arg0))->animationChanged = 1;
  }
}

void func_8024B67C_de(void *arg0) {
    (((struct ObjectState110 *) ((s8 *) arg0))->unk_10F) = 1;
    (((struct ObjectState110 *) ((s8 *) arg0))->unk_104) = 0;
    (((struct ObjectState110 *) ((s8 *) arg0))->unk_10E) = 0;
    (((struct ObjectState110 *) ((s8 *) arg0))->unk_100) = (s32) ((((struct ObjectState110 *) ((s8 *) arg0))->unk_100) & ~0x400);
}

extern s32 func_80246A08_de(void *, s32, s32);


s32 func_8024B6A0_de(void *a, s32 c, s32 flag) {
    s32 temp_v0 = func_80246A08_de(a, c, -1);

    if (temp_v0 != -1) {
        return func_8024B6F4_de(a, temp_v0, flag);
    }
    return 0;
}

extern void func_8024B65C_de(void *arg0, u32 arg1);

s32 func_8024B6F4_de(void *levelActor, s32 arg1, s32 arg2) {
    if (arg1 < 0 || (arg2 == 0 && (((struct LevelActor *)(levelActor))->flags & 0x400))) {
        return 0;
    }
    func_8024B65C_de(levelActor, (u32) arg1);
    return 1;
}

extern void func_8027985C_de(WeightedTable *arg0);
extern s32 func_80246A08_de(void *arg0, s32 arg1, s32 arg2);
extern s32 func_80279864_de(WeightedTable *arg0, s16 arg1, s16 arg2);

s16 func_8024B738_de(void *arg0, s16 *callback, s32 arg2) {
    WeightedTable sp10;
    u16 var_a1;

    func_8027985C_de(&sp10);
    var_a1 = *(u16 *) callback;
    if (*callback != -1) {
        do {
            if (func_80246A08_de(arg0, (s32) (s16) var_a1, arg2) != -1) {
                func_80279864_de(&sp10, callback[0], callback[1]);
            }
            callback += 2;
            var_a1 = *(u16 *) callback;
        } while (*callback != -1);
    }
    return func_802798A8_de(&sp10);
}

extern char D_800C39E0_de;
extern s32 *func_8024BFD4_de(void *arg0, s8 arg1);
extern s32 func_802484B0_de(void *arg0, s32 arg1, void *arg2);
extern void Scene_UnlockResource(s32 arg0, s32 arg1);

s32 func_8024B7E4_de(void *arg0, s32 arg1)
{
  void *resource;
  s32 *entry;
  s32 value;
  s32 result;
  result = 0;
  if ((((struct LevelActor *)(arg0))->flags) & 0x40000)
  {
    if (resource)
    {
      resource = Scene_RequestResource(0, ((struct LevelActor *)(arg0))->resource, ((struct LevelActor *)(arg0))->resource, ((struct LevelActor *)(arg0))->resourceFlags, 0, 0, 0, (&D_800C39E0_de) + 4, arg1);
    }
    else
    {
      resource = Scene_RequestResource(0, ((struct LevelActor *)(arg0))->resource, ((struct LevelActor *)(arg0))->resource, ((struct LevelActor *)(arg0))->resourceFlags, 0, 0, 0, (&D_800C39E0_de) + 4, arg1);
    }
    if (resource == 0)
    {
      return result;
    }
    entry = func_8024BFD4_de(arg0, ((struct LevelActor *)(arg0))->team);
    if (entry != 0)
    {
      value = *entry;
      result = func_802484B0_de(arg0, value, Render_GetPackSection(*((void **) resource), 0));
      Scene_UnlockResource(0, (s32) entry);
    }
    Scene_UnlockResource(0, (s32) resource);
  }
  return result;
}

void func_8024B8C4_de(void *arg0) {
    s32 temp_a1;
    temp_a1 = (((struct IntegerState104 *) ((s8 *) arg0))->unk_B4);
    (((struct IntegerState104 *) ((s8 *) arg0))->unk_B4) = 0;
    (((struct IntegerState104 *) ((s8 *) arg0))->unk_BC) = 0;
    (((struct IntegerState104 *) ((s8 *) arg0))->unk_C0) = 0;
    (((struct IntegerState104 *) ((s8 *) arg0))->unk_100) = (s32) ((((struct IntegerState104 *) ((s8 *) arg0))->unk_100) & ~0x200);
    (((struct IntegerState104 *) ((s8 *) arg0))->unk_B8) = temp_a1;
}

extern s32 D_800D297C;
extern void func_8024AA18_de(char *obj, s32 unused, char *info);
extern void func_8024C454_de(void *arg0, void *arg1);

void func_8024B8EC_de(void *actor, void *arg1, void *arg2) {
    s8 index;
    s32 one;

    index = ((struct LevelActor *)(actor))->team;
    if (index != -1) {
        ((struct LevelActor *)(actor))->mask = 1 << index;
        if (((struct ActorRenderSettings *)(arg2))->drawShadow != 0) {
            func_8024AA18_de(actor, arg1, arg2);
        }
        if (*(s32 *)arg2 != 0) {
            one = 1;
            func_8026DA4C_de(((struct ActorRenderSettings *)(arg2))->view,
                          ((struct LevelActor *)(actor))->fieldB4, one,
                          (char *)actor
                              + ((((D_800D297C << one) + D_800D297C) << 3)
                                 + 0x140),
                          0, ((struct LevelActor *)(actor))->field3);
            func_8024C454_de(actor, arg2);
        }
    }
}

extern s32 D_800D297C;
extern void func_8024AA18_de(char *obj, s32 unused, char *info);
extern void func_8024C454_de(void *arg0, void *arg1);

void func_8024B990_de(void *actor, void *arg1, void *arg2, Block24 *arg3) {
    s8 index;
    s32 one;

    ((ObjectRecAt140 *)actor)->blocks[D_800D297C] = *arg3;
    index = ((struct LevelActor *)(actor))->team;
    if (index != -1) {
        ((struct LevelActor *)(actor))->mask = 1 << index;
        if (((struct ActorRenderSettings *)(arg2))->drawShadow != 0) {
            func_8024AA18_de(actor, arg1, arg2);
        }
        if (*(s32 *)arg2 != 0) {
            one = 1;
            func_8026DA4C_de(((struct ActorRenderSettings *)(arg2))->view,
                          ((struct LevelActor *)(actor))->fieldB4, one,
                          (char *)actor
                              + ((((D_800D297C << one) + D_800D297C) << 3)
                                 + 0x140),
                          0, ((struct LevelActor *)(actor))->field3);
            func_8024C454_de(actor, arg2);
        }
    }
}
