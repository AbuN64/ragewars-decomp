#include "span_16E000/code_804290E8.h"
#include "types.h"

/* Refreshes the option block D_801462C8 from the menu D_800E4EF0 points to: the bytes at 0x24 to
   0x27 from the values func_802A1B18_de reports for its items at 0x28, 0x24, 0x2C and 0x30, and the
   byte at 0x28 from the selection func_8041AD04_de reports for its item at 0x1C. */





extern func_804296A4_S1 *D_800E4EF0;
extern struct Options D_801462C8;
extern s32 func_802A1B18_de(void *);
extern s32 func_8041AD04_de(void *);

void func_804294C4_de(void) {
    struct Options *options;
    s32 value;

    value = func_802A1B18_de(D_800E4EF0->unk28);
    options = &D_801462C8;
    options->values[0] = value;
    options->values[1] = func_802A1B18_de(D_800E4EF0->unk24);
    options->values[2] = func_802A1B18_de(D_800E4EF0->unk2C);
    options->values[3] = func_802A1B18_de(D_800E4EF0->unk30);
    options->values[4] = func_8041AD04_de(D_800E4EF0->unk1C);
}
