#ifndef MENU_PAK_80405DC0_H
#define MENU_PAK_80405DC0_H
#include "COMMON/MENURECAT24.H"
#include "MENU/80405DC0.H"
/* Plays the pak menu entry for a channel; quiet suppresses the prompt. */
extern s32 Pak_CheckStatusPrompt(MenuRecAt24 *menu, s32 channel, s32 quiet);
extern int func_80409144_de(void * owner, struct MenuRecAt24 * menu, void * arg);
extern s32 func_80408DF0_de(void *owner, MenuRecAt24 *menu);
#endif
