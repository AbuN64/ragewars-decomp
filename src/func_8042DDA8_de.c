#include "span_16E000/code_8042BD40.h"
#include "types.h"

/* Slider-down handler: when the fourth argument is one, calls func_8029973C_de, lowers the value at
   offset 0x20 of the object D_800E5430 points to by one while it is at least 2, formats it into the
   text at offset 0x14 with D_800E1B60 through func_802A0C08_de and plays sound 0xE81. Returns zero. */


extern struct Object_func_8042DD00_de *D_800E5430;
extern char D_800E1B60[];
extern void func_8029973C_de();
extern void func_802A0C08_de(char *, char *, s32);
extern void func_8025DF34_de(s32);

s32 func_8042DDA8_de(void *first, void *second, void *third, s32 fourth) {
    s32 value;

    if (fourth != 1) {
        return 0;
    }
    func_8029973C_de();
    value = D_800E5430->value;
    if (value >= 2) {
        D_800E5430->value = value - 1;
    }
    func_802A0C08_de(D_800E5430->text, D_800E1B60, D_800E5430->value);
    func_8025DF34_de(0xE81);
    return 0;
}
