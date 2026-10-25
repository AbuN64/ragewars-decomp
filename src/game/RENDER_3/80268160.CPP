#include "RENDER_3/RANGENODE.H"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/LONE/D_8010EC90.H"
#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "RENDER_3/80268160.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/WORLD.H"
#include "COMMON/OBJRECAT5F14.H"
#include "COMMON/ANIMATIONTRIGGERDEFINITION.H"
#include "COMMON/TARGET.H"
extern f32 D_800C4460_de;
extern void func_80266810_de(void *, s32, s32, Triple, struct IntPair, s32, s32, s32);


extern void func_8028CE94_de(void *, void *, s32, Triple, f32, f32);

/* Plays an effect at a position through func_8025DEC0_de unless the global D_80146894 is set, selecting the target from the given object's type and team masks and choosing the scale from the global option flags. Adapted from func_8026730C_de with the null object test and case 2 removed, a team test for case 0, a mask test for case 1, and the scale constants changed. */













/* Effect callback that fires only near an object's height: when the event's height lies within D_800C9564 below or D_800C9560 above the object's y at 0xC, it forwards the event to func_80266810_de with mode 1 and flags 0x200. */









static inline void fire(char *arg0, s32 arg1, s32 arg2, Triple arg3, struct IntPair arg6)
{
    func_80266810_de((void *)arg0, arg1, arg2, arg3, arg6, 1, 0, 0x200);
}

void func_80268150_de(s32 source, s32 target, s32 kind, Triple position, struct IntPair arg6) {
    func_80266810_de((void *)source, target, kind, position, arg6, 1, 1, 0x400);
}

void func_802681A8_de(func_8024E8F0_S1 *arg0, Context_func_802681A8_de *arg1, s32 unused2, Triple arg3, Params_func_802681A8_de arg6) {
    void *resource;

    if ((arg0->unk0 == 1) && (arg0->unk100 & 0x300000)) {
        resource = arg1->inner->resource + 0x140;
        arg3.x = 0;
        arg3.y = 0;
        arg3.z = 0;
    } else {
        resource = &D_8010EC90;
    }

    func_8028CE94_de(&D_8011FE88, resource, arg6.value, arg3,
                  arg6.angle * *(&D_800C4458_de + 1), arg6.scale * D_800C4460_de);
}

void func_80268264_de(int arg0, int arg1, int arg2, int arg3, ...)
{
  int new_var;
  float new_var2;
  new_var = 1;
  new_var2 = (float) new_var;
  if (new_var2)
  {
  }
}

void func_8026826C_de(ObjectRecAt17C *arg0, ObjectRecAt17C *arg1, s32 arg2, CVector3 arg3,
                   ParamsRecAt4 arg6) {
    s32 *global = &D_8011FAC0.clockPaused;
    s32 selected;
    f32 scale;

    scale = (&D_800C4460_de)[1];
    selected = -1;
    if (global[0] != 0) {
        return;
    }

    switch (arg1->type) {
    case 0:
        if (arg0->kind->team != arg6.team) {
            return;
        }
        selected = arg1->value;
        break;
    case 1:
        if (arg1->kind->value == arg1->type) {
            if (global[-371] & 0x40) {
                scale = D_800C4468_de;
            } else if (global[-371] & 0x20) {
                scale = D_800C446C_de;
            }
        }
        if ((arg1->mask & (1 << arg6.team)) == 0) {
            return;
        }
        break;
    }

    func_8025DEC0_de(arg6.value, arg3, 0, selected, scale);
}

void func_8026835C_de(void *actor, Filter *filter, s32 arg2, Triple position, struct IntPair arg6) {
    ObjRecAt1 *object = actor;
    switch (filter->type) {
    case 0:
        if (object->unk1 != arg6.field_4) {
            return;
        }
        break;
    case 1:
        if (!(filter->mask & (filter->type << arg6.field_4))) {
            return;
        }
        break;
    }
    func_80216288_de(actor, arg6.field_0, position, 0);
}

void func_802683E0_de(char *arg0, s32 arg1, s32 arg2, Triple_func_802683E0_de arg3, struct IntPair arg6)
{
    LevelActor *actor = (LevelActor *)arg0;
    f32 d = actor->position0.y - arg3.y;

    if (d < 0.0f ? -d <= D_800C9560 : d <= D_800C9564) {
        fire(arg0, arg1, arg2, *(Triple *)&arg3, arg6);
    }
}

void func_802684B8_de(void *arg0, s32 unused1, s32 unused2, s32 arg3, s32 unused4, s32 unused5, s32 unused6) {
    u8 temp = *(u8 *)arg0;
    if (temp == 1) {
        s32 *p = &arg3;
        ((Field_s32_2E0 *)(arg0))->value = ((Field_s32_2E0 *)(arg0))->value | (temp << p[3]);
    }
}

void func_802684E8_de(void *arg0, s32 unused1, s32 unused2, s32 arg3, s32 unused4, s32 unused5, s32 unused6) {
    u8 temp = *(u8 *)arg0;
    if (temp == 1) {
        s32 *p = &arg3;
        ((Field_s32_2E0 *)(arg0))->value = ((Field_s32_2E0 *)(arg0))->value & ~(temp << p[3]);
    }
}
