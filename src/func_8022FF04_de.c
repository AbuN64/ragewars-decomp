#include "shared/gameplay_transition.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_8022F3E8.h"
#include "span_1000/code_80231F5C.h"
#include "types.h"

extern s32 D_8011FE88;
extern void ***D_800D052C[];
extern s32 D_800CD730;
#include "shared/menu_match_globals.h"


extern s32 func_802327A0_de(s32);

extern void func_80237E80_de(void *, void *, void *);













void func_8022FF04_de(void *arg0, void *arg1) {
    s16 temp_s0;
    u16 temp_s2;
    void *temp_a1;
    char *temp_s1;

    temp_s1 = ((Shared_ActorView *)arg0)->self;
    temp_s0 = ((Shared_ActorView *)temp_s1)->nextWeapon;
    temp_s2 = (u16)((Shared_ActorView *)temp_s1)->nextWeapon;
    if ((((Shared_ActorView *)temp_s1)->selectedAction != temp_s0) || (D_8011FE88 != 4)) {
        if (func_80232780_de(temp_s0) != 0) {
            ((Shared_ActorView *)temp_s1)->weaponChanged = 1;
        } else if (func_802327A0_de(temp_s0) != 0) {
            ((Shared_ActorView *)temp_s1)->secondaryChanged = 1;
        } else if (func_802327D4_de(temp_s0) != 0) {
            ((Shared_ActorView *)temp_s1)->specialChanged = 1;
        }
        ((Shared_ActorView *)temp_s1)->selectedAction = temp_s2;
        ((WeaponFireState *)arg1)->animation = ((WeaponInfo *)(D_800D052C[(s16)temp_s2]))->animation;
        ((WeaponFireState *)arg1)->animationCount = ((WeaponInfo *)(D_800D052C[((Shared_ActorView *)temp_s1)->selectedAction]))->animationCount;
        temp_a1 = ((Shared_ActorView *)temp_s1)->message;
        if ((temp_a1 != 0) && ((u32)D_800CD730 >= 5U)) {
            func_80237E80_de(&D_80145088, temp_a1,
                          **D_800D052C[((Shared_ActorView *)temp_s1)->selectedAction]);
        }
        ((WeaponFireState *)arg1)->spinStep = 0;
        ((WeaponFireState *)arg1)->spin = 0;
        ((Shared_Actor *)arg0)->color = 0;
        ((WeaponFireState *)arg1)->charge = 0;
    }
    ((WeaponFireState *)arg1)->mode = 1;
    ((WeaponFireState *)arg1)->rounds = 1;
}
