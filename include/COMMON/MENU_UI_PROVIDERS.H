#ifndef COMMON_MENU_UI_PROVIDERS_H
#define COMMON_MENU_UI_PROVIDERS_H
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SHARED_GAMESLOT.H"
typedef struct MenuOption {
    u8 unobserved0[8];
    s32 flags;
    u8 unobservedC[8];
    s32 resource;
} MenuOption;
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
typedef struct MenuOptionFade {
    u8 unobserved0[0x30];
    f32 fade;
    f32 alpha;
    s32 field38;
    s32 highlighted;
} MenuOptionFade;
#include "COMMON/MENU_MATCH_GLOBALS.H"
extern f32 D_800DE47C_de;
extern void func_802A7DE4_de(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
#endif
