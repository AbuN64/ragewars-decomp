#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_8022D944.h"
#include "types.h"




/* Returns whether a record in state 3 carries type 0x5E2A or 0x5E5A, or a type in the range 0x7DF to 0x7E3. */

s32 func_8022E5EC_de(struct SharedPlayer *arg0) {
    s32 type;

    if (arg0->views5E8.view650_15.unk650 == 3) {
        type = arg0->views5E8.view86C_125.unk86C;
        if (type == 0x5E2A || type == 0x5E5A) {
            return 1;
        }
    }
    return arg0->views5E8.view650_15.unk650 == 3 && arg0->views5E8.view86C_125.unk86C >= 0x7DF && arg0->views5E8.view86C_125.unk86C < 0x7E4;
}
