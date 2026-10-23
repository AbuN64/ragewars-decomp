#include "include_asm.h"
#include "COMMON/CHARACTERSELECTIONROOT.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
extern Choice D_800E3A50[];

/* Returns the index of the first of the seventeen 0x70-byte slots of D_800E3A50 whose leading word equals the argument, or zero when none does. Adapted from func_8041F140_de with the slot word D_800E3A50 changed. */





/* Returns the second word of the first of the seventeen 0x70-byte slots of D_800E3A50 whose leading word equals the argument, or zero when none does.
   Adapted from func_8041F18C_de with the returned index changed to the slot's second word D_800E3A54. */





s32 func_8041F18C_de(s32 key) {
    s32 index = 0;
    s32 found = 0;
    s32 i;

    for (i = 0; i < 17 && !found; i++) {
        if (D_800E3A50[i].id == key) {
            found = 1;
            index = i;
        }
    }
    return index;
}

s32 func_8041F1D8_de(s32 key) {
    s32 value = 0;
    s32 found = 0;
    s32 i;

    for (i = 0; i < 17 && !found; i++) {
        if (D_800E3A50[i].id == key) {
            found = 1;
            value = D_800E3A50[i].value;
        }
    }
    return value;
}

#if defined(VERSION_US)
unsigned int func_8041F298_us_padding_183298[2] = {
    0x35657175, 0xD0100000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int func_8041F6D8_eu_x_padding_10F6D8[2] = {
    0x8C42BAB0, 0x00531021,
};
#endif

#if defined(VERSION_EU)
unsigned int func_8041F6D8_eu_padding_1956D8[2] = {
    0xAFB3001C, 0x0C0A669E,
};
#endif

#if defined(VERSION_DE)
unsigned int func_8041F228_de_padding_185228[2] = {
    0x00021600, 0x00822025,
};
#endif
