#include "span_1000/code_80217388.h"
#include "gbi.h"
#include "gfx.h"
#include "n64sdk.h"
#include "types.h"
#include "shared/func_8021E2A0_de_closed.h"
#include "span_1000/code_80291054.h"



extern void func_80218F9C_de(s32 arg0, s32 arg1, s32 arg2);

void func_80218F08_de(s32 arg0, s32 arg1, s32 arg2) {
    Gfx *cmd;

    func_802A9234_de(0xFF);
    gDPSetTextureFilter(D_80110634++, G_TF_BILERP);
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
