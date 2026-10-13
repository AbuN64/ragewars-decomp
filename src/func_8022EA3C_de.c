#include "common/unused.h"
#include "shared/gameplay_transition.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022E938.h"
#include "span_1000/code_8025E280.h"
#include "types.h"

extern f32 func_8027525C_de(void *arg0, f32 arg1, f32 arg2);
extern f32 func_80275DD4_de(s32, f32, f32);











void func_8022EA3C_de(void *arg0, void *arg1) {
    f32 first;
    f32 amount;

    if (arg0 != 0 && arg1 != 0 &&
        (((Shared_Func80243A80Collision *)arg0)->flags & 0x40)) {
        first = func_8027525C_de(arg0,
            ((Vec3 *)arg1)->x, ((Vec3 *)arg1)->z);
        amount = (f32)(s32)(first - func_80275DD4_de(arg0,
            ((Vec3 *)arg1)->x, ((Vec3 *)arg1)->z));
        if (amount < D_800C2E24_de) {
            func_8025E440_de(D_800C2E2C_de - (amount * D_800C2E28_de));
            return;
        }
    }
    func_8025E440_de(0.0f);
}

/** Perform no work for callers at VRAM 0x8022EAF4. */
void func_8022EB04_de(void) {
}

extern char D_8011D8D0;
extern s32 func_80283228_de(void *, s32);









/** Test whether an actor satisfies the condition selected by an entry type. */
s32 func_8022EB0C_de(void *arg0, s32 arg1) {
    void *entry;
    s16 *condition;
    char *indexed;
    s32 offset;

    entry = D_800D052C[arg1];
    {
        s32 sw_arg1_value = arg1;
        if ((unsigned int)sw_arg1_value > 21) {
            goto sw_arg1_default;
        }
        switch (sw_arg1_value) {
        case 0: goto sw_arg1_0;
        case 1: goto sw_arg1_1;
        case 2: goto sw_arg1_1;
        case 3: goto sw_arg1_3;
        case 4: goto sw_arg1_4;
        case 5: goto sw_arg1_1;
        case 6: goto sw_arg1_1;
        case 7: goto sw_arg1_1;
        case 8: goto sw_arg1_1;
        case 9: goto sw_arg1_1;
        case 10: goto sw_arg1_1;
        case 11: goto sw_arg1_1;
        case 12: goto sw_arg1_12;
        case 13: goto sw_arg1_1;
        case 14: goto sw_arg1_1;
        case 15: goto sw_arg1_1;
        case 16: goto sw_arg1_default;
        case 17: goto sw_arg1_default;
        case 18: goto sw_arg1_0;
        case 19: goto sw_arg1_0;
        case 20: goto sw_arg1_0;
        case 21: goto sw_arg1_0;
        }
    }
    do {
    sw_arg1_1:
    sw_arg1_2:
    sw_arg1_5:
    sw_arg1_6:
    sw_arg1_7:
    sw_arg1_8:
    sw_arg1_9:
    sw_arg1_10:
    sw_arg1_11:
    sw_arg1_13:
    sw_arg1_14:
    sw_arg1_15:
        condition = ((WeaponInfo *)(entry))->weaponClass;
        offset = condition[0] * 2;
        indexed = arg0;
        indexed += offset;
        return ((Shared_ActorView *)arg0)->ammo[condition[0]] >= condition[3];
    sw_arg1_3:
        return ((Shared_ActorView *)arg0)->ammo[0] >= 3;
    sw_arg1_4:
        return ((Shared_ActorView *)arg0)->ammo[0] >= 5;
    sw_arg1_12:
        if (((Shared_ActorView *)arg0)->ammo[2] == 0) {
            goto check_external;
        }
    sw_arg1_0:
    sw_arg1_18:
    sw_arg1_19:
    sw_arg1_20:
    sw_arg1_21:
        return 1;
    check_external:
        return func_80283228_de(&D_8011D8D0, (s32)arg0);
    sw_arg1_default:
        return 0;
    
    } while (0);
}

int func_8022EBC4_de(void) {
    char pad[0x10];
    return 0;
}

extern s32 func_8024E62C_de(void *arg0);
extern void func_802227F4_de(void *, void *, s32);




s32 func_8022EBD4_de(void *arg0, void *arg1) {
    if (((Actor_func_8024A7A0_de *)arg1)->position1.y <= 0.0f && func_8024E62C_de(arg1) != 0) {
        func_802227F4_de(arg0, arg1, 2);
        return 1;
    }
    return 0;
}

/** Update the object's state code from identity, mode, and height bounds. */







void func_8022EC3C_de(void *object) {
    int suppress = 0;
    float value;

    if (((Actor_func_8022ED48_de *)object)->unk_0x086C == 0x1144) {
        suppress = ((Actor_func_8022ED48_de *)object)->unk_0x010E == 0;
    }
    if (((Actor_func_8022ED48_de *)object)->ownerId == D_800CE47C) {
        ((Actor_func_8022ED48_de *)object)->unk_0x086C = 0x8A2;
        return;
    }
    if (!suppress) {
        value = ((Actor_func_8022ED48_de *)object)->unk_0x06C0;
        if (D_800C2E88_de <= value) {
            ((Actor_func_8022ED48_de *)object)->unk_0x086C = 0x8A2;
            return;
        }
        if (value <= D_800C2E8C_de) {
            ((Actor_func_8022ED48_de *)object)->unk_0x086C = 0x8A7;
            return;
        }
        ((Actor_func_8022ED48_de *)object)->unk_0x086C = 0x14;
    }
}

/** Empty adjacent entry point included in func_8022EC3C_de's Splat span. */
void func_8022ECC4_de(void) {
}

extern s32 D_800C9FE4;
extern s32 D_800CD6E0_de;



extern func_8022ECBC_S1 *D_800FE9F0;

extern void func_80449870_de(void *);
extern void func_802227F4_de(void *, void *, s32);

void func_8022ECCC_de(void) {
    if (D_800FE9F0->unk5EA == 1) {
        func_80449870_de((s32)D_800FE9F0);
    } else {
        func_802227F4_de(D_800FE9F0, D_800FE9F0, 0x22);
    }
    D_800CD6E0_de = 1;
    D_800C9FE4 = 0;
}

/** Passes D_80102A48 to func_80449870_de. */

extern void func_80449870_de(void *);

extern s32 D_80102A48;

void func_8022ED24_de(void) {
    func_80449870_de(D_80102A48);
}

extern s32 D_800CED30;
void func_8022ED48_de(Actor_func_8022ED48_de *arg0)
{
  s32 temp_v0;
  temp_v0 = arg0->flags & 0xFF7FFFFF;
  arg0->flags = temp_v0;
  arg0->unk_0x001C = 0;
  arg0->unk_0x0020 = 0;
  arg0->unk_0x0024 = 0;
  arg0->unk_0x11D8 = 0.0f;
  arg0->flags = temp_v0 | 0x01000000;
  arg0->unk_0x11FC = 0;
  arg0->flags = temp_v0 | 0x01000000;
  if (arg0->unk_0x13B4 == (&D_800CED30))
  {
    arg0->unk_0x086C = 0x5E24;
    return;
  }
  arg0->unk_0x086C = 1;
}


extern void func_80253908_de(s32 a);
extern void func_80253838_de(void *, void *);




void func_8022EDA4_de(void *arg0) {
    s32 temp_a1;

    func_80264854_de(0);
    func_80253908_de(0);
    temp_a1 = ((ResourceLoadState *)arg0)->handle;
    if (temp_a1 != 0) {
        func_80253838_de(0, temp_a1);
        ((ResourceLoadState *)arg0)->handle = 0;
        ((ResourceLoadState *)arg0)->state4 = 0;
        ((ResourceLoadState *)arg0)->state8 = 0;
    }
}

/** Preserve the empty hook at VRAM 0x8022EDE4. */
void func_8022EDF4_de(void) {
}

extern s32 D_80142850;

extern s32 func_8025DE54_de(s16 arg0, Vec3 position, s32 arg4, s32 arg5);
extern void func_80218464_de(void *arg0);
extern s32 func_80214178_de(void *arg0, void *arg1, s32 arg2);
extern void func_8021B1E4_de(void *, s32, s32, s32);
extern void func_80226708_de(void *arg0);






void func_8022EDFC_de(void *arg0) {
    s32 mode;

    ((Shared_ActorView *)arg0)->controls->transientFlag = 1;
    mode = D_80142850;
    switch (mode) {
    case 0:
        func_8025DE54_de(0x18A1,
                      ((Shared_ActorView *)arg0)->position.vector,
                      (s32)((char *)arg0 + 8), -1);
        break;
    case 1:
        func_8025DE54_de(0x1969,
                      ((Shared_ActorView *)arg0)->position.vector,
                      (s32)((char *)arg0 + 8), -1);
        break;
    case 2:
        func_8025DE54_de(0x1905,
                      ((Shared_ActorView *)arg0)->position.vector,
                      (s32)((char *)arg0 + 8), -1);
        break;
    }
    func_80218464_de((char *)arg0 + 0x938);
    ((Actor_func_8022ED48_de *)arg0)->unk_0x11B4 = 0;
    func_80214178_de(((Shared_ActorView *)arg0)->weapon, ((Shared_ActorView *)arg0)->ammoData, 1);
    func_8021B1E4_de(arg0, ((Shared_ActorView *)arg0)->spawn, 0, 1);
    func_80226708_de(arg0);
}

s32 func_8022EF04_de(s32 arg0, s32 arg1) {
    s32 var_a1;
    s32 var_v1;
    s32 space;

    var_v1 = 0;
    space = 0x20;
    var_a1 = arg1;
loop_1:
    var_a1 -= 1;
    if (*((u8 *)arg0 + var_a1) == space) {
        var_v1 += 1;
        if (var_a1 > 0) {
            goto loop_1;
        }
    }
    return var_v1;
}
