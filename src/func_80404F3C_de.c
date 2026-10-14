#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80403BCC.h"
#include "types.h"

/* Returns whether entry i of the word table D_801534F0 equals 2. */


s32 func_80404F3C_de(s32 index) {
    return D_801534F0[index] == 2;
}
