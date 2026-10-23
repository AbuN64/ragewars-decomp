#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/NUMBERPADSCREEN.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SCREEN.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
const unsigned int rodata_func_80421568_de_800E15E8[10] = {
    0x00421B24, 0x00421B38, 0x00421B4C, 0x00421B60, 0x00421B74, 0x00421B88, 0x00421B9C, 0x00421BB0,
    0x00421BC4, 0x00421BD8,
};
#endif

#if (defined(VERSION_EU) || defined(VERSION_EU_X)) && !defined(NON_MATCHING)
INCLUDE_ASM("ovl_80400000", func_80421568_de);
#endif

#if !(defined(VERSION_EU) || defined(VERSION_EU_X)) || defined(NON_MATCHING)
/* Fuzzy draft in EU and EU-X: their body differs. */
#if defined(VERSION_DE)
#define ID_ROW0 946
#define ID_CLOSE 933
#else
#define ID_ROW0 952
#define ID_CLOSE 939
#endif
void func_80421568_de(void) {
    MenuWidget *item;
    char *text;
    s32 line;
    s32 index;

    line = D_800E4400->length;
    index = D_800E4400->value;
    do {
        text = D_800D3E14_de[0][index];

        if (text != 0) {
            index++;
        }
        item = func_8040EC30_de(D_800E4400->window, ID_ROW0);
        switch (line) {
        case 0:
            item = func_8040EC30_de(D_800E4400->window, ID_ROW0);
            break;
        case 1:
            item = func_8040EC30_de(D_800E4400->window, ID_ROW0 + 1);
            break;
        case 2:
            item = func_8040EC30_de(D_800E4400->window, ID_ROW0 + 2);
            break;
        case 3:
            item = func_8040EC30_de(D_800E4400->window, ID_ROW0 + 3);
            break;
        case 4:
            item = func_8040EC30_de(D_800E4400->window, ID_ROW0 + 4);
            break;
        case 5:
            item = func_8040EC30_de(D_800E4400->window, ID_ROW0 + 5);
            break;
        case 6:
            item = func_8040EC30_de(D_800E4400->window, ID_ROW0 + 6);
            break;
        case 7:
            item = func_8040EC30_de(D_800E4400->window, ID_ROW0 + 7);
            break;
        case 8:
            item = func_8040EC30_de(D_800E4400->window, ID_ROW0 + 8);
            break;
        case 9:
            item = func_8040EC30_de(D_800E4400->window, ID_ROW0 + 9);
            break;
        }
        item->text = text;
        line++;
    } while (line < 10);
        if (D_800D3E14_de[0][D_800E4400->value] != 0)

    {
        if (D_800E4400->length == 0) {
            D_800E4400->value++;
        }
    } else {
        func_8040E8D8_de(D_800E4400->pad, 0);
        func_8040E8D8_de(func_8040EC30_de(D_800E4400->window, ID_CLOSE), 1);
        D_800E4400->cursor = 1;
    }
    if (D_800E4400->length > 0) {
        D_800E4400->length--;
    }
}
#endif
