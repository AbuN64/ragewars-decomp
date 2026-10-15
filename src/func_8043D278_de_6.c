#include "span_166000/code_8043D1DC.h"
#include "types.h"

extern s32 D_801462C8;
extern s32 D_801462CC;
extern s32 D_800D3B0C;
extern s32 D_800D3B10;

/* Updates the option item's flag bit and selects its associated text pointer. */
s32 func_8043D278_de(struct Func8043D458Arg *arg0) {
    if (D_801462CC & 1) {
        arg0->flags |= 0x01000000;
    } else {
        arg0->flags &= 0xFEFFFFFF;
    }
    if (D_801462C8 & 1) {
        arg0->text = &D_800D3B0C;
    } else {
        arg0->text = &D_800D3B10;
    }
    return 0;
}

extern s32 D_801462C8;

/* Toggles bit 1 of the settings flag word D_801462C8 and returns 0. */
s32 func_8043D2E4_de(void) {
    D_801462C8 ^= 2;
    return 0;
}
