#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "MENU/PLAYERSETTINGS.H"
#include "TYPES.H"
#include "RENDER_2/8025DE50_5.H"

#if !(defined(VERSION_DE))
/* Handles the team option of a menu: unless func_8026437C_de reports the confirm input, it steps the owner's team byte at 0x80 through Pak_StepValue between 1 and 18, applies it with func_8044A0C4_de and redraws it with Pak_SelectPreviewModel, returning zero; on confirm it applies the team, plays the sound D_800E5DFA gives for the player's slot at 0x5E0 and shows the resource D_450698 through Pak_AllocateMenu, returning one. */







extern s32 Control_IsAButtonPressed(s32);
extern s8 Pak_StepValue(Menu_func_8043F37C_eu *, s32, s32, s32, s32, s32);
extern void Ovlgame_StartPlayerAnimation(SharedPlayer *, s32);
extern void Pak_SelectPreviewModel(void *, s32, s32);
extern void Pak_AllocateMenu(void *, Menu_func_8043F37C_eu *, char *);

s32 func_8043F37C_eu(void *previewWidget, Menu_func_8043F37C_eu *menu, void *menuContext) {
    SharedPlayer *player = menu->player;
    ObjRecAt80 *settings = player->views5D8.view5D8_7.settings;

    if (Control_IsAButtonPressed(menu->input) != 0) {
        Ovlgame_StartPlayerAnimation(player, settings->unk80);
        SoundElement_PlayFlatSound(D_800E5DFA[player->views5DC.view5E0_10.slot].mode);
        Pak_AllocateMenu(menuContext, menu, D_0044FA6C);
        return 1;
    }
    settings->unk80 = Pak_StepValue(menu, settings->unk80, 1, 0, 18, 1);
    Ovlgame_StartPlayerAnimation(player, settings->unk80);
    Pak_SelectPreviewModel(previewWidget, 11, settings->unk80);
    return 0;
}
#endif
