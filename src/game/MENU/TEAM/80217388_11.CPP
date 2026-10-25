#include "MENU/TEAMMENU.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/SESSIONHANDLERROW.H"

extern void func_80218F9C_de(s32 arg0, s32 arg1, s32 arg2);

void func_80218F08_de(s32 arg0, s32 arg1, s32 arg2) {
    Gfx *cmd;

    Text_SetupSpriteMode(0xFF);
    gDPSetTextureFilter(g_displayListCursor++, G_TF_BILERP);
    func_80218F9C_de(arg0, arg1, arg2);
}

/** Reset a record and mark its word at offset 0x6C as invalid. */
void func_80218F84_de(void *record) {
    TeamMenu *menu = record;
    menu->state = 0;
    menu->unused = 0;
    menu->cursor = -1;
    menu->open = 0;
}
