#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "MENU/PLAYERSETTINGS.H"
#include "TYPES.H"
#include "RENDER/SOUNDELEMENT_PLAYFLATSOUND.H"

#if !(defined(VERSION_DE))
/* Handles the team option of a menu: unless func_8026437C_de reports the confirm input, it steps the owner's team byte at 0x80 through Menu_StepValue between 1 and 18, applies it with func_8044A0C4_de and redraws it with Menu_SelectPreviewModel, returning zero; on confirm it applies the team, plays the sound g_profilePlayerAnimationChoices gives for the player's slot at 0x5E0 and shows the resource D_450698 through Menu_AllocateMenu, returning one. */







extern s32 Control_IsAButtonPressed(s32);
extern s8 Menu_StepValue(MenuCMenuProfileUpdatePlayerAnimationChoice *, s32, s32, s32, s32, s32);
extern void Player_StartPlayerAnimation(SharedPlayer *, s32);
extern void Menu_SelectPreviewModel(void *, s32, s32);
extern void Menu_AllocateMenu(void *, MenuCMenuProfileUpdatePlayerAnimationChoice *, char *);

s32 CMenuProfile_UpdatePlayerAnimationChoice(void *previewWidget, MenuCMenuProfileUpdatePlayerAnimationChoice *menu, void *menuContext) {
    SharedPlayer *player = menu->player;
    PlayerCharacterKindView *settings = player->views5D8.view5D8_7.settings;

    if (Control_IsAButtonPressed(menu->input) != 0) {
        Player_StartPlayerAnimation(player, settings->characterKind);
        SoundElement_PlayFlatSound(g_profilePlayerAnimationChoices[player->views5DC.view5E0_10.slot].mode);
        Menu_AllocateMenu(menuContext, menu, g_characterPreviewMenuRomResource);
        return 1;
    }
    settings->characterKind = Menu_StepValue(menu, settings->characterKind, 1, 0, 18, 1);
    Player_StartPlayerAnimation(player, settings->characterKind);
    Menu_SelectPreviewModel(previewWidget, 11, settings->characterKind);
    return 0;
}
#endif
