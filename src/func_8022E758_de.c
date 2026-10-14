#include "span_1000/code_8022D944.h"
#include "types.h"

extern u8 D_801462E5;

u8 func_8022E758_de(s32 arg0, s32 arg1) {
    u8 *ptr;

    if (arg1 == 0x2DA) {
        ptr = &D_801462E5;
        if (*ptr != 0) {
            return ptr[0xE];
        }
    }
    return 1;
}
