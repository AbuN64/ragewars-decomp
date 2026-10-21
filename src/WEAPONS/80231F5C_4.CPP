#include "COMMON/WORLD.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/VECTOR4F.H"
#include "WEAPONS/PLAYERRECAT1450V1.H"
#include "TYPES.H"
#include "COMMON/RESOURCELOADSTATE.H"
#include "COMMON/OBJECTLINKS14C.H"

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
extern s32 D_800CD730;
#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "COMMON/CHANNEL.H"














void func_802325FC_de(void *arg0, void *arg1) {
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
}
#endif
