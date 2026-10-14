#include "span_1000/code_8022F3E8.h"
/* Increments the object's byte counter for a slot in the table at 0x18: indices 0 to 10 directly,
   17 and 18 as slots 11 and 12, and other indices are ignored. */


void func_8022F3F8_de(Obj_func_8022F3F8_de *obj, int index) {
    if (index == 17) {
        goto is17;
    }
    if (index < 18) {
        goto below18;
    }
    if (index == 18) {
        goto is18;
    }
    return;
below18:
    if (index >= 11) {
        return;
    }
    if (index < 0) {
        return;
    }
    goto store;
is18:
    index = 12;
    goto store;
is17:
    index = 11;
store:
    obj->slots[index]++;
}
