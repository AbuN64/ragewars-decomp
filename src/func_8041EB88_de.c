#include "span_16E000/code_8041DF04.h"
#include "types.h"

/* Returns entry column - 1 of row r in the five-word table D_800E37B8, or zero when the column is
   not positive. */
extern s32 D_800E37B8[];

s32 func_8041EB88_de(s32 column, s32 row) {
    s32 previous = column - 1;

    if (column <= 0) {
        return 0;
    }
    return D_800E37B8[row * 5 + previous];
}
