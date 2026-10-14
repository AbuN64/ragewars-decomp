#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8042BD40.h"
#include "types.h"

/* Hides the four child items of a selected menu panel. */

void func_8040E8D8_de(s32, s32);                            /* extern */
s32 func_8040EC30_de(s32, s32);                        /* extern */
extern MenuPanelRoot *D_800E53C0;

#if defined(VERSION_DE)
enum { ITEM0 = 616, ITEM1 = 615, ITEM2 = 614, ITEM3 = 613 };
#elif defined(VERSION_EU_X)
enum { ITEM0 = 625, ITEM1 = 624, ITEM2 = 623, ITEM3 = 622 };
#else
enum { ITEM0 = 621, ITEM1 = 620, ITEM2 = 619, ITEM3 = 618 };
#endif

void func_8042D418_de(s32 arg0) {
    s32 temp_s1;
    s32 var_a1;
    s32 var_s0;

    temp_s1 = func_8040EC30_de(D_800E53C0->window, arg0 & 0xFFFF);
    var_s0 = 0;
    do {
        switch(var_s0) {
        case 0: var_a1=ITEM0; break;
        case 1: var_a1=ITEM1; break;
        case 2: var_a1=ITEM2; break;
        case 3: var_a1=ITEM3; break;
        default: var_a1=ITEM0; break;
        }
        func_8040E8D8_de(func_8040EC30_de(temp_s1, var_a1), 0);
        var_s0 += 1;
    } while (var_s0 < 4);
}
