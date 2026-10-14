#ifndef MENU_UI_PROVIDERS_H
#define MENU_UI_PROVIDERS_H
#include "types.h"
#include "common/unused.h"
#include "shared/func_80425674_de_layout.h"
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
#include "shared/menu_match_globals.h"
extern f32 D_800DE47C_de;
extern void func_802A7DE4_de(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
#endif
