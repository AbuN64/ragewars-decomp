#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80412270.h"
#include "types.h"
/* Visits every cell of a list's column-by-row grid, computing each cell's rectangle through func_804122CC_de and drawing it through func_8040D2D0_de with the given style. */







extern void func_804122CC_de(List_func_80412634_de *list, UnitMtx *cell, u32 column, u32 row);
extern void func_8040D2D0_de(UnitMtx *cell, NodeEvent style);

void func_80412634_de(List_func_80412634_de *arg0, NodeEvent style) {
    List_func_80412634_de *list = arg0;
    UnitMtx cell;
    u32 column;
    u32 row;

    for (column = 0; column < list->columns; column++) {
        for (row = 0; row < list->rows; row++) {
            func_804122CC_de(list, &cell, column, row);
            func_8040D2D0_de(&cell, style);
        }
    }
}
