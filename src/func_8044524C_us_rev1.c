#include "span_16E000/code_80444EC0.h"
#include "types.h"

/* Replaces the word at offset 0x10 of the option block D_801462C8 with what func_804423BC_de returns
   for the second argument, that word, 0x10, 0, 0x80 and 0, and returns zero. */


extern struct Options_func_80444D50_de D_801462C8;
extern s32 func_804423BC_de(void *, s32, s32, s32, s32, s32);

s32 func_80444D50_de(void *first, void *second) {
    struct Options_func_80444D50_de *options = &D_801462C8;

    options->value = func_804423BC_de(second, options->value, 0x10, 0, 0x80, 0);
    return 0;
}
