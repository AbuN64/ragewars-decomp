#include "span_16E000/code_80444030.h"
#include "types.h"

/* Replaces the byte at offset 0x7D of the second argument's owner settings (or the defaults D_80146302) with what func_804423BC_de returns for the second argument, that byte, 1, 0, 1 and 1, and returns zero. Adapted from func_80444488_de with the settings byte 0x7D changed. */







extern struct Settings_func_80444548_de D_80146302;
extern s32 func_804423BC_de(void *, s32, s32, s32, s32, s32);

s32 func_80444548_de(void *first, struct Holder_func_80444548_de *holder) {
    struct Settings_func_80444548_de *settings = &D_80146302;

    if (holder->owner != 0 && holder->owner->settings != 0) {
        settings = holder->owner->settings;
    }
    settings->value = func_804423BC_de(holder, settings->value, 1, 0, 1, 1);
    return 0;
}
