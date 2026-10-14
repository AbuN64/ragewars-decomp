#include "span_16E000/code_80444030.h"
#include "types.h"

/* Replaces the byte at offset 0x7A of the second argument's owner settings (or the defaults D_80146302) with what func_804423BC_de returns for the second argument, that byte, 8, 8, 0xF8 and 0, and returns zero. Adapted from func_80444988_de with the settings byte 0x7A changed. */







extern struct Settings_func_80444AB8_de D_80146302;
extern s32 func_804423BC_de(void *, s32, s32, s32, s32, s32);

s32 func_80444AB8_de(void *first, struct Holder_func_80444AB8_de *holder) {
    struct Settings_func_80444AB8_de *settings = &D_80146302;

    if (holder->owner != 0 && holder->owner->settings != 0) {
        settings = holder->owner->settings;
    }
    settings->value = func_804423BC_de(holder, settings->value, 8, 8, 0xF8, 0);
    return 0;
}
