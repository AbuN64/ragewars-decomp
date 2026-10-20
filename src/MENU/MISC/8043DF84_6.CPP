#include "COMMON/ITEMRECAT20V1.H"
#include "MENU/PLAYERSETTINGS.H"
#include "TYPES.H"
#include "RENDER_2/8025DE50_5.H"

#if !(defined(VERSION_DE))
/* Handles the team option of a menu: unless func_8026437C_de reports the confirm input, it steps the owner's team byte at 0x80 through func_80442488_de between 1 and 18, applies it with func_8044A0C4_de and redraws it with func_8044214C_de, returning zero; on confirm it applies the team, plays the sound D_800E5DFA gives for the player's slot at 0x5E0 and shows the resource D_450698 through func_804427C4_de, returning one. */






extern Clip D_800E5DFA[];
extern char D_0044FA6C[];

extern s32 func_8026437C_de(s32);
extern s8 func_80442488_de(Menu_func_8043F37C_eu *, s32, s32, s32, s32, s32);
extern void func_8044A0C4_de(SharedPlayer *, s32);
extern void func_8044214C_de(void *, s32, s32);
extern void func_804427C4_de(void *, Menu_func_8043F37C_eu *, char *);

s32 func_8043F37C_eu(void *arg0, Menu_func_8043F37C_eu *menu, void *arg2) {
    SharedPlayer *player = menu->player;
    ObjRecAt80 *settings = player->views5D8.view5D8_7.settings;

    if (func_8026437C_de(menu->input) != 0) {
        func_8044A0C4_de(player, settings->unk80);
        func_8025DF34_de(D_800E5DFA[player->views5DC.view5E0_10.slot].mode);
        func_804427C4_de(arg2, menu, D_0044FA6C);
        return 1;
    }
    settings->unk80 = func_80442488_de(menu, settings->unk80, 1, 0, 18, 1);
    func_8044A0C4_de(player, settings->unk80);
    func_8044214C_de(arg0, 11, settings->unk80);
    return 0;
}
#endif
