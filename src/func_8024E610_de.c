#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8024E130.h"



/** Return offset 0x34 only when the type byte at offset 0 is 1. */
int func_8024E610_de(void *arg0) {
    struct Item_func_8024E6A0_de *item = arg0;
    if (item->kind == 1) {
        return (int)item->value;
    }
    return 0;
}
