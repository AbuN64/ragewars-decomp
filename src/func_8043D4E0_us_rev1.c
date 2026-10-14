#include "span_166000/code_8043D1DC.h"
#include "types.h"

extern s32 D_801462C8;
extern s32 D_801462CC;
extern s32 D_800D3B14;
extern s32 D_800D3B18;

/* Updates the option item's flag bit and selects its associated text pointer. */
s32 func_8043D4E0_us_rev1(struct Func8043D458Arg *arg0) {
    if (D_801462CC & 2) {
        arg0->flags |= 0x01000000;
    } else {
        arg0->flags &= 0xFEFFFFFF;
    }
    if (D_801462C8 & 2) {
        arg0->text = &D_800D3B14;
    } else {
        arg0->text = &D_800D3B18;
    }
    return 0;
}
