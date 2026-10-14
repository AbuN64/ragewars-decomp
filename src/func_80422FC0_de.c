#include "span_16E000/code_80423280.h"
#include "types.h"

/* Refreshes the option block D_801462C8 from the menu D_800E4510 points to: the bytes at 0x1B, 0x1F
   and 0x580 from the selections func_8041AD04_de reports for its items at 0xC, 0x10 and 0x14, and the
   word at 0x10 from the position func_8041A6E0_de reports for its item at 8. */





extern OptionsCommitContext *D_800E4510;
extern struct OptionsBuildSettings D_801462C8;
extern s32 func_8041AD04_de(void *);
extern s32 func_8041A6E0_de(void *);

void func_80422FC0_de(void) {
    struct OptionsBuildSettings *options;
    s32 value;

#if defined(VERSION_DE)
    value = func_8041AD04_de(D_800E4510->unk_10);
    options = &D_801462C8;
    options->second = value;
#else
    value = func_8041AD04_de(D_800E4510->unk_C);
    options = &D_801462C8;
    options->first = value;
    options->second = func_8041AD04_de(D_800E4510->unk_10);
#endif
    options->third = func_8041AD04_de(D_800E4510->unk_14);
    options->position = func_8041A6E0_de(D_800E4510->unk_8);
}
