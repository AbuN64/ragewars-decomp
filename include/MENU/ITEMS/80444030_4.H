#ifndef MENU_ITEMS_80444030_4_H
#define MENU_ITEMS_80444030_4_H
#include "MENU/HOLDERRECAT1CV2.H"
extern void Items_ResetPlayerSettings(u8 *record, u8 value);
/* The per-slot reset routine sits at different addresses in the PAL and non-PAL builds. */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern void func_80444F30_eu(u8 *);
#define RESET_SLOT_80445074 func_80444F30_eu
#else
extern void Items_SetDefaultPlayerName(u8 *);
#define RESET_SLOT_80445074 Items_SetDefaultPlayerName
#endif
#endif
