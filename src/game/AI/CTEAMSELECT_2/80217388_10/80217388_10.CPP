#include "COMMON/VECTOR4F.H"
#include "MENU/TEAMMENU.H"
#include "TYPES.H"
#include "COMMON/TRIPLE.H"
#include "MENU/TEAM/80217388_10.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/SESSIONHANDLERROW.H"

/* 80217388_10.CPP */
/** Reset the team menu: closed, no cursor or hover, and its four team slots fanned 30 degrees apart. */
void func_80218E98_de(TeamMenu *menu) {
    s32 i;

    menu->state = 0;
    menu->unused = 0;
    menu->open = 0;
    menu->reset = 0;
    menu->spin = 0;
    menu->cursor = -1;
    menu->count = 4;
    menu->hover = -1;
    for (i = 0; i < 4; i++) {
        menu->slots[i].angle = -(i * D_800C22AC_de);
        menu->slots[i].unused2 = 0;
        menu->slots[i].scale = D_800C917C;
    }
}

/* 80217388_11.CPP */
extern void func_80218F9C_de(s32 arg0, s32 arg1, s32 arg2);

void func_80218F08_de(s32 menu, s32 arg1, s32 player) {
    Gfx *cmd;

    OnScreen_SetupSpriteMode(0xFF);
    gDPSetTextureFilter(g_displayListCursor++, G_TF_BILERP);
    func_80218F9C_de(menu, arg1, player);
}

/** Reset a record and mark its word at offset 0x6C as invalid. */
void func_80218F84_de(void *record) {
    TeamMenu *menu = record;
    menu->state = 0;
    menu->unused = 0;
    menu->cursor = -1;
    menu->open = 0;
}
