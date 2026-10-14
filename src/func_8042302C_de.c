#include "span_16E000/code_80423280.h"
#include "types.h"

/* Refreshes the option block D_801462C8 from the menu D_800E4514 points to: the bytes at 0x1B and 0x580
   from the selections func_8041AD04_de reports for its items at 4 and 8, and the word at 0x10 from
   the position func_8041A6E0_de reports for its item at 0. */







extern CompactOptionsCommitContext *D_800E4514;
extern struct TabOptionsCommitOptions D_801462C8;
extern s32 func_8041AD04_de(void *);
extern s32 func_8041A6E0_de(void *);

void func_8042302C_de(void) {
    struct TabOptionsCommitOptions *options;
    s32 value;

#if defined(VERSION_DE)
    value = func_8041AD04_de(D_800E4514->unk_8);
    options = &D_801462C8;
    options->second = value;
#else
    value = func_8041AD04_de(D_800E4514->unk_4);
    options = &D_801462C8;
    options->first = value;
    options->second = func_8041AD04_de(D_800E4514->unk_8);
#endif
    options->position = func_8041A6E0_de(D_800E4514->unk_0);
}
