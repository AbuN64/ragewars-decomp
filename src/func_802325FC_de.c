#include "shared/gameplay_transition.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80231F5C.h"
#include "types.h"

extern void *D_800D052C[];
extern s32 D_800CD730;
extern s32 D_8011FE88;
extern char D_80145088;


extern s32 func_802327A0_de(s32);

extern void func_80237E80_de(void *, void *, void *);












void func_802325FC_de(void *arg0, void *arg1) {
    s16 index;
    u16 unsigned_index;
    void *owner;
    void *state;

    state = ((Shared_ActorView *)arg0)->self;
    index = ((Shared_ActorView *)state)->nextWeapon;
    unsigned_index = (u16)((Shared_ActorView *)state)->nextWeapon;
    if ((((Shared_ActorView *)state)->selectedAction != index) || (D_8011FE88 != 4)) {
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
