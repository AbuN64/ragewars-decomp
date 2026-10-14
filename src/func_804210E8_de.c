#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_80420E90.h"
#include "types.h"

/* Copies the four checkboxes at 0xC to 0x18 of the screen D_800E4400 into the game flags word
   D_801462C8, setting or clearing bits 0x08000000, 0x10000000, 0x8 and 0x20000000 as
   func_8041AD04_de reports each box checked. */



extern struct Screen_func_804210E8_de *D_800E4400;


extern struct Shape_func_8021A2D4_de_2 D_801462C8;
extern s32 func_8041AD04_de(void *);

void func_804210E8_de(void) {
    if (func_8041AD04_de(D_800E4400->boxes[0]) == 0) {
        D_801462C8.field_0 &= ~0x08000000;
    } else {
        D_801462C8.field_0 |= 0x08000000;
    }
    if (func_8041AD04_de(D_800E4400->boxes[1]) == 0) {
        D_801462C8.field_0 &= ~0x10000000;
    } else {
        D_801462C8.field_0 |= 0x10000000;
    }
    if (func_8041AD04_de(D_800E4400->boxes[2]) == 0) {
        D_801462C8.field_0 &= ~0x8;
    } else {
        D_801462C8.field_0 |= 0x8;
    }
    if (func_8041AD04_de(D_800E4400->boxes[3]) == 0) {
        D_801462C8.field_0 &= ~0x20000000;
    } else {
        D_801462C8.field_0 |= 0x20000000;
    }
}
