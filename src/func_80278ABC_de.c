#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80277444.h"
#include "types.h"
/* Sums the size field of the record func_8028FDB4_de returns for each entry of the D_8011FE88 table and returns the total.
   Adapted from func_802AFFC0_de with the loop over the global entry table and the accumulated return changed. */



extern struct Shape_typemap_13 *func_8028FDB4_de(s32, s32);
extern char D_8011FE88[];




s32 func_80278ABC_de(void) {
    s32 total = 0;
    s32 i;
    char *base = D_8011FE88;

    for (i = 0; i < ((IntegerState1504 *)(base))->unk_1500; i++) {
        total += func_8028FDB4_de(*((struct ObjectLinks150C *) (base + (i * 0xC)))->unk_1508, 2)->field_4;
    }
    return total;
}
