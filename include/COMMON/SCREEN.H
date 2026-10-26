#ifndef COMMON_SCREEN_H
#define COMMON_SCREEN_H
#include "TYPES.H"
#include "COMMON/NUMBERPADSCREEN.H"

/* After MarkMenuEventHandled, opens screen D_800E4400 through Menu_ShowExtraOptionsPanel while its word at 0x34 is
   zero; otherwise handles the menu message func_80299A08_de reports: 0x3AC closes the screen's first
   word through func_8041A430_de with 2 and calls Menu_ApplyExtraOptionFlags, and 0x3B6 calls Menu_OpenOptionsKeypad.
   Returns zero. */

extern struct NumberPadScreen *D_800E4400;
extern void MarkMenuEventHandled(void);
extern s32 func_80299A08_de(void);
extern void Menu_ShowExtraOptionsPanel(void);
extern void func_8041A430_de(s32, s32);
extern void Menu_ApplyExtraOptionFlags(void);
extern void Menu_OpenOptionsKeypad(void);
#endif
