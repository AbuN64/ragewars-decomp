#include "span_166000/code_80426310.h"
#include "types.h"
#include "common/unused.h"
#include "common/data.h"

extern s32 D_801462C8[];

/* Toggles the bits arg1 names in the settings flag word D_801462C8 and returns 0. */
s32 func_8043D0D4_de(s32 arg0, s32 arg1) {
    s32 *flags = D_801462C8;

    *flags ^= arg1;
    return 0;
}

extern s32 D_800D3B8C;
extern s32 D_800D3B90;
extern s32 D_800D3B94;
extern s32 D_800D3B98;
extern s32 D_800D3B9C;
extern s32 D_800D3BA0;
extern s32 D_800D3BA4;
extern s32 D_800D3BA8;
extern s32 D_800D3BAC;
extern s32 D_800D3BB0;
extern s32 D_800D3BB4;
extern s32 D_800D7E14;

s32 func_8043D0F0_de(func_8043D2D0_S *arg0) {
    switch (D_80154034) {
    default:
        arg0->value = &D_800D7E14;
        break;
    case 0:
        arg0->value = &D_800D3B8C;
        break;
    case 1:
        arg0->value = &D_800D3B90;
        break;
    case 2:
        arg0->value = &D_800D3B94;
        break;
    case 3:
        arg0->value = &D_800D3B98;
        break;
    case 4:
        arg0->value = &D_800D3B9C;
        break;
    case 5:
        arg0->value = &D_800D3BA0;
        break;
    case 6:
        arg0->value = &D_800D3BA8;
        break;
    case 7:
        arg0->value = &D_800D3BA4;
        break;
    case 8:
        arg0->value = &D_800D3BAC;
        break;
    case 9:
        arg0->value = &D_800D3BB0;
        break;
    case 10:
        arg0->value = &D_800D3BB4;
        break;
    }
    return 0;
}
