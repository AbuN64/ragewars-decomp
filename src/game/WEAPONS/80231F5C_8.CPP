#include "COMMON/MODEL_RENDER.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/UNUSED.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/INTEGERSTATE244.H"
#include "COMMON/VECTOR4F.H"
#include "WEAPONS/PLAYERRECAT1450V1.H"
#include "TYPES.H"
#include "COMMON/SELF.H"
#include "COMMON/OBJECTLINKS14C.H"


extern s32 Pak_CountLiveNodes(void *arg0);
extern s32 Weapons_GetWeaponAmmo(void *arg0, s16 arg1);

void Weapon_DrawWeaponLookupModel(void *arg0, Dest *arg1, Lookup *lookup) {
    void *actor;
    void *resource;
    s32 result;
    s32 one;
    s16 state;

    actor = ((LevelActor *)arg0)->controller;
    resource = ((Shared_ActorView *)actor)->message;
    result = -1;
    if (resource == 0) {
        return;
    }
    if (D_801462C8.local != 0) {
        if (Pak_CountLiveNodes((char *)resource + 0x554) != 0) {
            return;
        }
    }
    state = ((Shared_ActorView *)actor)->selectedAction;
    one = 1;
    if ((state == one) && (arg1->field144 == 0)) {
        return;
    }
    if ((state >= 0x12) && (Weapons_GetWeaponAmmo(actor, state) <= 0)) {
        return;
    }
    state = ((Shared_ActorView *)actor)->selectedAction;
    if ((state == 0xE) || (state == one) || (state == 0)) {
        result = ((Shared_ActorView *)actor)->unk_0x11F8;
    }
    func_8026DA4C_de(lookup->value,
                  ((LevelActor *)arg0)->fieldB4, 1,
                  (char *)arg0 + (D_800D297C * 0x18 + 0x140), 0, result);
}

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern void Weapon_ApplySwitchAndRequestIdle(void *arg0, void *arg1);
#else
#endif







void Weapon_InitializeFireStateCallbacks(void *arg0, void *arg1) {
    f32 k = D_800C3018_de;

    ((Dest *)arg1)->table = &D_800CA058;
    ((Dest *)arg1)->enter = &D_0022FC20;
    ((Dest *)arg1)->draw = &D_0023293C;
    ((Dest *)arg1)->field124 = 0;
    ((Dest *)arg1)->charge = 0;
    ((Dest *)arg1)->field130 = 0;
    ((Dest *)arg1)->field138 = 0;
    ((Dest *)arg1)->field13C = 1;
    ((Dest *)arg1)->field12C = k;
    ((LevelActor *)arg0)->team = 0;
    ((Dest *)arg1)->field148 = 0;
    ((Dest *)arg1)->field144 = 1;
    ((Dest *)arg1)->field14C = 0;
    ((Dest *)arg1)->field150 = 0;
    
#if defined(VERSION_EU) || defined(VERSION_EU_X)
Weapon_ApplySwitchAndRequestIdle
#else
Weapon_InitializeSwitchAndRequestIdle
#endif
(arg0, arg1);
}

extern s32 World_PlayerHasAmmoForWeapon(void *arg0, s32 arg1);




s32 Weapons_PickRandomArmedWeapon(void *player) {
    s32 weapon;
    s32 remainingArmedSteps;

    weapon = ((Shared_ActorView *)player)->selectedAction;
    remainingArmedSteps = Nav_NextRandom() % 22;
    if (remainingArmedSteps >= 0) {
        do {
            weapon += 1;
            if (weapon >= 0x10) {
                weapon = 0;
            }
            if (World_PlayerHasAmmoForWeapon(player, weapon) != 0) {
                remainingArmedSteps -= 1;
            }
        } while (remainingArmedSteps >= 0);
    }
    return weapon;
}
