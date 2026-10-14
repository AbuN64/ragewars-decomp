#include "span_1000/code_8020EAE0.h"
#include "types.h"

/** Return whether arg0 is within the range [0x6BA, 0x6BC). */
s32 func_8020F55C_de(s32 arg0) {
    if (arg0 < 0x6BC) {
        if (arg0 >= 0x6BA) {
            return 1;
        }
    }
    return 0;
}
