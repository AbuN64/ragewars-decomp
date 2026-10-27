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














void Weapon_ApplyWeaponSwitch(void *part, void *body) {
    s16 index;
    u16 unsigned_index;
    void *owner;
    void *state;

    state = ((Shared_ActorView *)part)->self;
    index = ((Shared_ActorView *)state)->nextWeapon;
    unsigned_index = (u16)((Shared_ActorView *)state)->nextWeapon;
    if ((((Shared_ActorView *)state)->selectedAction != index) || (g_world.mode != 4)) {
        if (Weapon_IsPrimarySwitchGroup(index) != 0) {
            ((Shared_ActorView *)state)->weaponChanged = 1;
        } else if (Weapon_IsSecondarySwitchGroup(index) != 0) {
            ((Shared_ActorView *)state)->secondaryChanged = 1;
        } else if (Weapon_IsSpecialSwitchGroup(index) != 0) {
            ((Shared_ActorView *)state)->specialChanged = 1;
        }
        ((Shared_ActorView *)state)->selectedAction = unsigned_index;
        ((WeaponFireState *)body)->animation = ((WeaponInfo *)D_800D052C[(s16)unsigned_index])->animation;
        ((WeaponFireState *)body)->animationCount = ((WeaponInfo *)(D_800D052C[((Shared_ActorView *)state)->selectedAction]))->animationCount;
        owner = ((Shared_ActorView *)state)->message;
        if ((owner != 0) && ((u32)D_800CD730 >= 5U)) {
            Camera_PostScreenMessage(&D_80145088, owner,
                *(void **)*(void **)D_800D052C[((Shared_ActorView *)state)->selectedAction]);
        }
        ((WeaponFireState *)body)->spinStep = 0;
        ((WeaponFireState *)body)->spin = 0;
        ((Shared_Actor *)part)->color = 0;
        ((WeaponFireState *)body)->charge = 0;
    }
}
#endif
