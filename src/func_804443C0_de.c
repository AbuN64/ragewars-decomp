#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80444030.h"
#include "types.h"

/* Replaces the signed byte at offset 0x7B of the second argument's owner settings (or the defaults D_80146302) with what func_804423BC_de returns for the second argument, that byte, 1, 0, 1 and 1, returning zero. Adapted from func_80444610_de with the settings byte made the signed byte at 0x7B. */







extern struct Record_func_8043E494_de D_80146302;
extern s32 func_804423BC_de(void *, s32, s32, s32, s32, s32);

s32 func_804443C0_de(void *first, struct Menu_func_8043E494_de *holder) {
    struct Record_func_8043E494_de *settings = &D_80146302;

    if (holder->owner != 0 && holder->owner->record != 0) {
        settings = holder->owner->record;
    }
    settings->mode = func_804423BC_de(holder, settings->mode, 1, 0, 1, 1);
    return 0;
}
