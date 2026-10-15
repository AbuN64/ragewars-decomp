#include "span_1000/code_8022F3E8.h"
#include "types.h"

s32 func_8022F454_de(Obj_func_8022F3F8_de *obj, s32 index) {
    if (index == 17) {
        goto slot17;
    }
    if (index < 18) {
        goto lower;
    }
    if (index == 18) {
        goto slot18;
    }
    return 2;
lower:
    if (index >= 11) {
        return 2;
    }
    if (index < 0) {
        return 2;
    }
    goto load;
slot17:
    index = 11;
    goto load;
slot18:
    index = 12;
load:
    return obj->slots[index];
}
