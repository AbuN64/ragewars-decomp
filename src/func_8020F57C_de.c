#include "span_1000/code_8020EAE0.h"
#include "types.h"

/** Return whether arg0 is within the range [0xBC4, 0xBCA). */
s32 func_8020F57C_de(s32 arg0) {
    if (arg0 < 0xBCA) {
        if (arg0 >= 0xBC4) {
            return 1;
        }
    }
    return 0;
}
