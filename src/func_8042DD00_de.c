#include "span_16E000/code_8042BD40.h"
#include "types.h"

/* When the fourth argument is one, calls func_8029973C_de, advances the word at 0x20 of the object D_800E5430 holds while func_80264614_de reports one for it and it is below func_80264690_de's limit, formats that word into the object's text at 0x14 through func_802A0C08_de with D_800E1B60, and plays sound 0xE81 through func_8025DF34_de; returns zero.
   Adapted from func_80422340_de with the object chain changed to a guarded counter increment, text format and sound call. */



extern struct Object_func_8042DD00_de *D_800E5430;
extern char D_800E1B60[];
extern void func_8029973C_de();
extern s32 func_80264614_de(s32);
extern s32 func_80264690_de();
extern void func_802A0C08_de(char *, char *, s32);
extern void func_8025DF34_de(s32);

s32 func_8042DD00_de(void *a0, void *a1, void *a2, s32 press) {
    struct Object_func_8042DD00_de *object;

    if (press != 1) {
        return 0;
    }
    func_8029973C_de();
    if (func_80264614_de(D_800E5430->value) == press) {
        object = D_800E5430;
        if (object->value < func_80264690_de()) {
            D_800E5430->value++;
        }
    }
    func_802A0C08_de(D_800E5430->text, D_800E1B60, D_800E5430->value);
    func_8025DF34_de(0xE81);
    return 0;
}
