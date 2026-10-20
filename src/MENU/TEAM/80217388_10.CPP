#include "COMMON/VECTOR4F.H"
#include "MENU/TEAMMENU.H"
#include "TYPES.H"
#include "COMMON/TRIPLE.H"
#include "MENU/TEAM/80217388_10.H"

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
