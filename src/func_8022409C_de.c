#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8021CD70.h"
#include "types.h"
































extern f32 D_800D2988;

#include "shared/menu_match_globals.h"
extern char D_800C2950_de;

extern void func_80274870_de(f32 *value, f32 target, f32 rate);




extern void func_80271F9C_de(Vec3 *, Vec3 *, f32);
extern void func_80271F34_de(Vec3 *, Vec3 *, Vec3 *);

extern void func_802227F4_de(void *, void *, s32);
extern void func_80237E80_de(void *, void *, void *);







void func_8022409C_de(void *arg0, void *arg1) {
    Vec3 direction;
    f32 held;
    f32 value;
    s32 flags;
    s32 result;
    void *data;

    if (((func_80224078_Arg0 *)arg0)->unk650 == 0 &&
        !(((func_80224078_Arg0 *)arg0)->unk6AC & 0xE000)) {
        ((func_80224078_Arg0 *)arg0)->unk650 = 1;
    }
    ((func_80224078_Arg0 *)arg0)->unk72C = 0;

    held = (&D_800C2960_de)[1];
    func_80274870_de(&((func_80224078_Arg1 *)(arg1))->unk6C,
                  ((func_80224078_Arg1 *)arg1)->unk6C +
                      (f32)((ControllerRecAtC7 *)((func_80224078_Arg0 *)arg0)->unk698)->x * D_800C2960_de,
                  held);
    func_80274870_de(&((func_80224078_Arg0 *)(arg0))->unk724,
                  ((func_80224078_Arg0 *)arg0)->unk724 +
                      (f32)-((ControllerRecAtC7 *)((func_80224078_Arg0 *)arg0)->unk698)->y * D_800C2968_de,
                  held);

    value = ((func_80224078_Arg0 *)arg0)->unk6A8;
    if (value != 0.0f) {
        f32 step;
        f32 limit;
        step = value * (&D_800C2968_de)[1];
        if (value < 0.0f) {
            limit = -value * D_800C2970_de;
        } else {
            limit = value * D_800C2974_de;
        }
        ((func_80224078_Arg0 *)arg0)->unk6C0 =
            func_802746A0_de(((func_80224078_Arg0 *)arg0)->unk6C0, step, limit);
    } else {
        ((func_80224078_Arg0 *)arg0)->unk6C0 =
            func_802747A0_de(((func_80224078_Arg0 *)arg0)->unk6C0, D_800C2978_de);
    }

    value = ((func_80224078_Arg0 *)arg0)->unk6A4;
    if (value != 0.0f) {
        f32 step;
        f32 limit;
        step = value * D_800C297C_de;
        if (value < 0.0f) {
            limit = -value * D_800C2980_de;
        } else {
            limit = value * D_800C2984_de;
        }
        ((func_80224078_Arg0 *)arg0)->unk6C4 =
            func_802746A0_de(((func_80224078_Arg0 *)arg0)->unk6C4, step, limit);
    } else {
        ((func_80224078_Arg0 *)arg0)->unk6C4 =
            func_802747A0_de(((func_80224078_Arg0 *)arg0)->unk6C4, D_800C2988_de);
    }

    flags = ((func_80224078_Arg0 *)arg0)->unk6AC;
    if (flags & 0x10) {
        ((func_80224078_Arg1 *)arg1)->unk20 =
            func_802746A0_de(((func_80224078_Arg1 *)arg1)->unk20, D_800C298C_de, 71.68f);
    } else if (flags & 0x2020) {
        ((func_80224078_Arg1 *)arg1)->unk20 =
            func_802746A0_de(((func_80224078_Arg1 *)arg1)->unk20, D_800C2990_de, 71.68f);
    } else {
        ((func_80224078_Arg1 *)arg1)->unk20 =
            func_802747A0_de(((func_80224078_Arg1 *)arg1)->unk20, D_800C2994_de);
    }

    {
        f32 angle;
        angle = ((func_80224078_Arg1 *)arg1)->unk6C;
        angle += (held = D_800C2998_de);
        direction.x = ((func_80224078_Arg0 *)arg0)->unk6C0 * func_802B7130_de(angle);
    }
    direction.y = ((func_80224078_Arg1 *)arg1)->unk20;
    direction.z = ((func_80224078_Arg0 *)arg0)->unk6C0 *
                  func_802B6560_de(((func_80224078_Arg1 *)arg1)->unk6C + held);
    held = D_800C299C_de;
    direction.x += ((func_80224078_Arg0 *)arg0)->unk6C4 *
                   func_802B7130_de(((func_80224078_Arg1 *)arg1)->unk6C - held);
    direction.z += ((func_80224078_Arg0 *)arg0)->unk6C4 *
                   func_802B6560_de(((func_80224078_Arg1 *)arg1)->unk6C - held);

    func_80271F9C_de(&direction, &direction, D_800D2988);
    func_80271F34_de(&((func_80224078_Arg0 *)(arg0))->unk6E8,
                  &((func_80224078_Arg0 *)(arg0))->unk6E8, &direction);
    result = func_80286728_de(&D_8011FE88, &((func_80224078_Arg1 *)arg1)->unk8);
    if (result != 0) {
        ((func_80224078_Arg1 *)arg1)->unk14 = result;
    }

    if (((func_80224078_Arg0 *)arg0)->unk650 == 1 &&
        (((func_80224078_Arg0 *)arg0)->unk6AC & 0xE000) == 0xE000 &&
        (((func_80224078_Arg0 *)arg0)->unk6B0 & 0xE000)) {
        func_802227F4_de(arg0, arg1, 2);
        data = ((func_80224078_Arg0 *)arg0)->unk5DC;
        if (data != 0) {
            func_80237E80_de(&D_80145088, data, &D_800C2950_de);
        }
    }
}
