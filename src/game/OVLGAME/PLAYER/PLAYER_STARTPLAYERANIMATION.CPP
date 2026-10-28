#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/WORLD.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/OBJB.H"
#include "TYPES.H"
#include "COMMON/OBJECTSTATE18.H"
#include "ENGINE/SCENE_DRAWOPAQUEACTORS.H"

/* Releases the two handles at offsets 0x11BC and 0x11C0 of an object: each goes to func_8025CA24_de
   with what func_8025CC6C_de returns, and each is then cleared. */


extern void *func_8025CC6C_de();
extern void func_8025CA24_de(void *, s32);

void Player_ReleaseObjectHandles(struct ItemsHandleOwner *object) {
    func_8025CA24_de(func_8025CC6C_de(), object->first);
    object->first = 0;
    func_8025CA24_de(func_8025CC6C_de(), object->second);
    object->second = 0;
}

/* Stores the second argument at 0x5E0 of the actor, calls Playerai_InitializePlayerHealth and Player_ResetPlayerWeapons on it, then starts sound D_8011FE88 for it through Scene_ChangeInstanceModel with 0x66, D_800CE47C or its type's entry of D_800CE430 chosen by the options D_801462E5 and D_801468F4.
   Adapted from func_8022BB80_de with a leading field store and two calls added and the D_801462C8 offsets changed to the symbols D_801462E5 and D_801468F4. */


extern void Playerai_InitializePlayerHealth(void *);
extern void Player_ResetPlayerWeapons(void *);











void Player_StartPlayerAnimation(Player *animatedPlayer, s32 animationState) {
    s32 modelResource;

    animatedPlayer->state = animationState;
    Playerai_InitializePlayerHealth(animatedPlayer);
    Player_ResetPlayerWeapons(animatedPlayer);
    if (D_801462C8.local == 0) {
        modelResource = 0x66;
    } else if (D_801468F4 != 0 && ((Shared_ControlView *)animatedPlayer->profile)->transientFlag != 0) {
        modelResource = D_800CE47C;
    } else {
        modelResource = D_800CE430[((Shared_struct_D_800D34C0_0x18 *)animatedPlayer->definition)->unkC];
        animatedPlayer->playerId = ((Shared_ControlView *)animatedPlayer->profile)->playerId;
    }
    ((void (*)(void *, void *, s32, s32))Scene_ChangeInstanceModel)(&g_world, animatedPlayer, modelResource, animatedPlayer->animation);
}
