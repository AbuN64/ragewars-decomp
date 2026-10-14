#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80403BCC.h"
#include "types.h"

/* Returns entry i of D_80153500 when entry i of the state table D_801534F0 is 3, otherwise -2. */



s32 func_80404F04_de(s32 index) {
    if (D_801534F0[index] != 3) {
        return -2;
    }
    return D_80153500[index];
}
