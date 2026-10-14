#include "span_16E000/code_80429C10.h"
#include "types.h"

/* Returns whether D_80154010 holds anything other than -1; func_8042AFC0_de stores it. */

s32 func_8042AF28_de(void) {
    return D_80154010.index != -1;
}
