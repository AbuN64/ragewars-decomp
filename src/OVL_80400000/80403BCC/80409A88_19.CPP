#include "span_16E000/code_8040A83C.h"
#include "common/unused.h"
/* Draws an item's label at its position into the text layer D_8014561C through func_80442574_de, using
   the fixed label D_44F0B8 instead of the item's own when D_80153730 is set; returns 1. */


extern char D_8014561C[];
extern char D_0044E468[];
extern void func_80442574_de(char *, char *, int, int, int);

int func_8040AA4C_de(int unused, ItemRecAt24 *item) {
    if (D_80153730 != 0) {
        func_80442574_de(D_8014561C, D_0044E468, item->x, item->y, 0);
    } else {
        func_80442574_de(D_8014561C, item->label, item->x, item->y, 0);
    }
    return 1;
}
