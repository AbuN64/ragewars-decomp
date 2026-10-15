#include "span_1000/code_80200610.h"
#include "types.h"

/** Return strlen(arg0) + 1 (byte count including the terminating NUL). */
s32 func_802016DC_de(u8 *arg0) {
    u8 *var_v1;
    u8 temp;

    var_v1 = arg0 + 1;
    if (*arg0 != 0) {
        do {
            temp = *var_v1;
            var_v1 += 1;
        } while (temp != 0);
    }
    return var_v1 - arg0;
}
