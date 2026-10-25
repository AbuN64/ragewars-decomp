#ifndef COMMON_MENU_UI_PROVIDERS_H
#define COMMON_MENU_UI_PROVIDERS_H
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SHARED_GAMESLOT.H"
typedef struct MenuOptionBox {
    s32 field0;
    s32 width;
    s32 height;
    f32 scaleX;
    f32 scaleY;
    s32 left;
    s32 field18;
    s32 top;
} MenuOptionBox;
#include "COMMON/MENU_MATCH_GLOBALS.H"
extern f32 D_800DE47C_de;
extern void Text_DrawBevelBox(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
#endif
