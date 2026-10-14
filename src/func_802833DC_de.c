#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8028308C.h"
#include "types.h"

extern u8 D_801462E3;




s32 func_802833DC_de(void *arg0) {
    Obj_func_80283920_de *object = arg0;
    s32 result;

    result = 0;
    if ((*object->effectFlags) & 0x02000000) {
        if (object->unk5C & 2) {
            result = 2;
        } else if (D_801462E3 == 2) {
            result = 1;
        }
    }
    return result;
}
