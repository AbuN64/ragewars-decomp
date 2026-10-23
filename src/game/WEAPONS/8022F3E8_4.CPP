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
#include "COMMON/CHANNEL.H"

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
extern s32 D_800CD730;




void func_8022FDAC_de(void *arg0, void *weaponFireState) {
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
        ((WeaponFireState *)weaponFireState)->animation = ((WeaponInfo *)D_800D052C[(s16)unsigned_index])->animation;
        ((WeaponFireState *)weaponFireState)->animationCount = ((WeaponInfo *)(D_800D052C[((Shared_ActorView *)state)->selectedAction]))->animationCount;
        owner = ((Shared_ActorView *)state)->message;
        if ((owner != 0) && ((u32)D_800CD730 >= 5U)) {
            Camera_PostScreenMessage(&D_80145088, owner,
                *(void **)*(void **)D_800D052C[((Shared_ActorView *)state)->selectedAction]);
        }
        ((WeaponFireState *)weaponFireState)->spinStep = 0;
        ((WeaponFireState *)weaponFireState)->spin = 0;
        ((Shared_Actor *)arg0)->color = 0;
        ((WeaponFireState *)weaponFireState)->charge = 0;
    }
    func_80214178_de(arg0, weaponFireState, 0);
}

void func_8022FF04_de(void *arg0, WeaponFireState *fireState) {
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
        fireState->animation = ((WeaponInfo *)(D_800D052C[(s16)temp_s2]))->animation;
        fireState->animationCount = ((WeaponInfo *)(D_800D052C[((Shared_ActorView *)temp_s1)->selectedAction]))->animationCount;
        temp_a1 = ((Shared_ActorView *)temp_s1)->message;
        if ((temp_a1 != 0) && ((u32)D_800CD730 >= 5U)) {
            Camera_PostScreenMessage(&D_80145088, temp_a1,
                          **(void ***)D_800D052C[((Shared_ActorView *)temp_s1)->selectedAction]);
        }
        fireState->spinStep = 0;
        fireState->spin = 0;
        ((Shared_Actor *)arg0)->color = 0;
        fireState->charge = 0;
    }
    fireState->mode = 1;
    fireState->rounds = 1;
}
#endif

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
#include "TYPES.H"
typedef struct WeaponRecord8F { u8 pad0[0x8F]; u8 flag8F; } WeaponRecord8F;
typedef struct WeaponPlayer {
    u8 pad0[0x5D8];
    WeaponRecord8F *record;
    u8 pad5DC[0x5F6 - 0x5DC];
    s16 ammo;
    u8 pad5F8[0x62E - 0x5F8];
    s16 mode;
    u8 pad630[0x6AC - 0x630];
    s32 flags6AC;
    u8 pad6B0[0x788 - 0x6B0];
    s32 state788;
    u8 pad78C[0x11B4 - 0x78C];
    s32 busy;
    u8 pad11B8[0x11D8 - 0x11B8];
    f32 recoil;
} WeaponPlayer;
typedef struct WeaponOwner { u8 pad0[0x1D8]; WeaponPlayer *player; } WeaponOwner;
typedef struct WeaponSlot {
    u8 pad0[0x130];
    f32 delay;
    u8 pad134[0x13C - 0x134];
    s32 mode13C;
    u8 pad140[0x144 - 0x140];
    s32 flag144;
    f32 timer148;
} WeaponSlot;
s32 func_80283228_de(s32 *, void *);
extern s32 D_8011D8D0;
extern s32 D_801468F4;
s32 func_80230058_de(void *owner, void *slot) {
    WeaponOwner *weaponOwner = (WeaponOwner *)owner;
    WeaponSlot *weaponSlot = (WeaponSlot *)slot;
    WeaponPlayer *player = weaponOwner->player;
    if (weaponSlot->delay > 0.0f || !Weapons_HasAmmoForMode(player, player->mode)) return 0;
    if ((player->record->flag8F == 1 && D_801468F4 != 0) || player->recoil > 0.0f || player->busy != 0) return 0;
    switch ((s16)(player->mode - 1)) {
    case 10:
        if (player->flags6AC & 0x4000) return 0;
        break;
    case 17:
        if (player->state788 != 2) return 0;
        break;
    case 8:
        if (weaponSlot->timer148 > 0.0f && weaponSlot->mode13C == 2) return 0;
        if (player->ammo < 0x32 && weaponSlot->mode13C == 2) return 0;
        if (player->ammo < 10) {
            if (weaponSlot->mode13C == 1) return 0;
        }
        break;
    case 11:
        if (func_80283228_de(&D_8011D8D0, player) >= 3) return 0;
        break;
    case 0:
        if (weaponSlot->flag144 == 0) return 0;
        break;
    }
    return 1;
}
#else
INCLUDE_ASM("span_1000", func_80230058_de);
#endif
