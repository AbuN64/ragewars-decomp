#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_8043DF84.h"
#include "types.h"
/* Clears D_80146914, runs func_80264788_de on the value at 0x4 of the menu's widget and then func_80264248_de and func_802647E8_de(widget, 1) on the widget itself, clears the flag at 0x85C of the owner at 0x1C, and returns 1. */







extern s32 D_80146914;
extern void func_80264788_de(s8);
extern void func_80264248_de(PakMenuSlot *widget);
extern void func_802647E8_de(PakMenuSlot *, s32);

s32 func_8043E1F8_de(s32 arg0, MenuRecAt20V2 *menu) {
    PakMenuSlot **slot;

    D_80146914 = 0;
    slot = &menu->widget;
    func_80264788_de((*slot)->unk4);
    func_80264248_de(*slot);
    func_802647E8_de(*slot, 1);
    menu->owner->unk85C = 0;
    return 1;
}
