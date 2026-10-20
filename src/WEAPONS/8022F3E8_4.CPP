#include "COMMON/WORLD.H"
#include "include_asm.h"
#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "WEAPONS/PLAYERRECAT1450V1.H"
#include "TYPES.H"
extern void *D_800D052C[];
#include "WEAPONS/80213ED4.H"

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
extern s32 D_800CD730;




extern void func_80237E80_de(void *, void *, void *);

void func_8022FDAC_de(void *arg0, void *arg1) {
    s16 index;
    u16 unsigned_index;
    void *owner;
    void *state;

    state = ((Shared_ActorView *)arg0)->self;
    index = ((Shared_ActorView *)state)->nextWeapon;
    unsigned_index = (u16)((Shared_ActorView *)state)->nextWeapon;
    if ((((Shared_ActorView *)state)->selectedAction != index) || (D_8011FE88.mode != 4)) {
        if (func_80232780_de(index) != 0) {
            ((Shared_ActorView *)state)->weaponChanged = 1;
        } else if (func_802327A0_de(index) != 0) {
            ((Shared_ActorView *)state)->secondaryChanged = 1;
        } else if (func_802327D4_de(index) != 0) {
            ((Shared_ActorView *)state)->specialChanged = 1;
        }
        ((Shared_ActorView *)state)->selectedAction = unsigned_index;
        ((WeaponFireState *)arg1)->animation = ((WeaponInfo *)D_800D052C[(s16)unsigned_index])->animation;
        ((WeaponFireState *)arg1)->animationCount = ((WeaponInfo *)(D_800D052C[((Shared_ActorView *)state)->selectedAction]))->animationCount;
        owner = ((Shared_ActorView *)state)->message;
        if ((owner != 0) && ((u32)D_800CD730 >= 5U)) {
            func_80237E80_de(&D_80145088, owner,
                *(void **)*(void **)D_800D052C[((Shared_ActorView *)state)->selectedAction]);
        }
        ((WeaponFireState *)arg1)->spinStep = 0;
        ((WeaponFireState *)arg1)->spin = 0;
        ((Shared_Actor *)arg0)->color = 0;
        ((WeaponFireState *)arg1)->charge = 0;
    }
    func_80214178_de(arg0, arg1, 0);
}

void func_8022FF04_de(void *arg0, WeaponFireState *arg1) {
    s16 temp_s0;
    u16 temp_s2;
    void *temp_a1;
    char *temp_s1;

    temp_s1 = ((Shared_ActorView *)arg0)->self;
    temp_s0 = ((Shared_ActorView *)temp_s1)->nextWeapon;
    temp_s2 = (u16)((Shared_ActorView *)temp_s1)->nextWeapon;
    if ((((Shared_ActorView *)temp_s1)->selectedAction != temp_s0) || (D_8011FE88.mode != 4)) {
        if (func_80232780_de(temp_s0) != 0) {
            ((Shared_ActorView *)temp_s1)->weaponChanged = 1;
        } else if (func_802327A0_de(temp_s0) != 0) {
            ((Shared_ActorView *)temp_s1)->secondaryChanged = 1;
        } else if (func_802327D4_de(temp_s0) != 0) {
            ((Shared_ActorView *)temp_s1)->specialChanged = 1;
        }
        ((Shared_ActorView *)temp_s1)->selectedAction = temp_s2;
        arg1->animation = ((WeaponInfo *)(D_800D052C[(s16)temp_s2]))->animation;
        arg1->animationCount = ((WeaponInfo *)(D_800D052C[((Shared_ActorView *)temp_s1)->selectedAction]))->animationCount;
        temp_a1 = ((Shared_ActorView *)temp_s1)->message;
        if ((temp_a1 != 0) && ((u32)D_800CD730 >= 5U)) {
            func_80237E80_de(&D_80145088, temp_a1,
                          **(void ***)D_800D052C[((Shared_ActorView *)temp_s1)->selectedAction]);
        }
        arg1->spinStep = 0;
        arg1->spin = 0;
        ((Shared_Actor *)arg0)->color = 0;
        arg1->charge = 0;
    }
    arg1->mode = 1;
    arg1->rounds = 1;
}
#endif

INCLUDE_ASM("span_1000", func_80230058_de);
