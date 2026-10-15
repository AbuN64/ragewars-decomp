#include "span_1000/code_8022F3E8.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "gbi.h"
#include "gfx.h"
#include "span_1000/code_8026AC38.h"
#include "span_1000/code_80291054.h"
#include "types.h"
#include "span_1000/code_8022E938.h"


extern void func_80271F9C_de(void *, void *, f32);

extern void func_80272CB0_de(void *, f32, f32, f32);

extern void func_802732D0_de(char *, f32 *);

extern void func_80226DD0_de(char *, Matrix *);

extern void func_80226C60_de(char *object, Vector4f *output);

extern void func_80274244_de(void *, void *);

extern void func_80273448_de(char *, f32, f32, f32);

extern void func_80273D6C_de(void *);

extern void func_8026F620_de(void *, void *, void *);

void func_8022F4BC_de(s32 arg0, s32 arg1) {
    extern void func_80265688_de(s32 arg0, s32 arg1, s32 arg2);
    func_80265688_de(arg0 + 0x79, arg1, 1);
}

s32 func_8022F4DC_de(s32 arg0, s32 arg1)
{
    extern s32 func_80265650_de(s32, s32);
  if (arg1 == 0x10)
  {
    return 1;
  }
  if (arg1 == 0x11)
  {
    if (arg1 || arg0)
    {
      return 1;
    }
    else
    {
      return 1;
    }
  }
  return func_80265650_de(arg0 + 0x79, arg1);
}

void func_8022F514_de(s32 arg0, s32 arg1) {
    extern void func_80265688_de(u8 *, s32, s32);
    u8 *var_a0;
    s32 var_a1 = arg1;

    switch (var_a1) {
    case 16:
        var_a0 = (u8 *)(arg0 + 0x78);
        var_a1 = 0;
        break;
    case 17:
        var_a0 = (u8 *)(arg0 + 0x78);
        var_a1 = 1;
        break;
    default:
        var_a0 = (u8 *)(arg0 + 0x7B);
        break;
    }
    func_80265688_de(var_a0, var_a1, 1);
}

s32 func_8022F55C_de(s32 arg0, s32 arg1) {
    extern s32 func_80265650_de(s32, s32);
    s32 var_a0;
    s32 var_a1 = arg1;

    switch (var_a1) {
    case 16:
        var_a0 = arg0 + 0x78;
        var_a1 = 0;
        break;
    case 17:
        var_a0 = arg0 + 0x78;
        var_a1 = 1;
        break;
    default:
        var_a0 = arg0 + 0x7B;
        break;
    }
    func_80265650_de(var_a0, var_a1);
}

void func_8022F5A4_de(s32 arg0, s32 arg1) {
    extern void func_80265688_de(s32 arg0, s32 arg1, s32 arg2);
    func_80265688_de(arg0 + 0x51, arg1, 1);
}

/** Thin wrapper forwarding an offset argument to func_80265650_de. */
void func_8022F5C4_de(int arg0) {
    extern void func_80265650_de(int a);
    func_80265650_de(arg0 + 0x51);
}

void func_8022F5E0_de(char *arg0) {
    Vec3 sp10;
    Matrix sp20;
    Vec3 sp60;
    Vec3 sp70;
    Matrix sp80;
    Matrix spC0;
    Vector4f sp100;
    char *object;
    char *orientation;

    object = ((ObjectLinks1DC *)(arg0))->unk_1D8;
    sp70 = ((struct ObjectState44 *) D_800D052C[((ObjectState630 *) object)->unk_62E])->unk_38;
    if (D_800CA040_de != 0) {
        sp70.x = -sp70.x;
    }
    if (D_800CA044 != 0) {
        sp70.y = -sp70.y;
    }
    if (D_800CA048 != 0) {
        sp70.z = -sp70.z;
    }
    func_80271F9C_de(&sp60, &((ObjectLinks1DC *)(arg0))->unk_50, 0.1f);
    func_80272CB0_de(&sp80, sp60.x, sp60.y, sp60.z);
    func_80271F9C_de(&sp70, &sp70, -10.24f);
    if (((ObjectState630 *)(object))->unk_5DC.v0 != 0) {
        func_802732D0_de(((ObjectState630 *)(object))->unk_5DC.v1 + 0x160, &sp10);
        func_80274244_de((Vector4f *)(((ObjectState630 *)(object))->unk_5DC.v1 + 0x140),
                      &sp20);
    } else {
        func_80226DD0_de(object, &spC0);
        func_80226C60_de(object, &sp100);
        func_802732D0_de((char *)&spC0, &sp10);
        func_80274244_de(&sp100, &sp20);
    }
    orientation = arg0 + 0x74;
    func_80273448_de(&sp80, sp70.x, sp70.y, sp70.z);
    func_80273D6C_de(&sp80);
    func_8026F620_de((Matrix *)orientation, &sp80, &sp20);
    func_80273448_de((Matrix *)orientation, sp10.x, sp10.y, sp10.z);
}
