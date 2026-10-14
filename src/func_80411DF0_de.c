#include "span_16E000/code_80411B68.h"
#include "types.h"

/* Returns whether an index lies inside the table bound D_80153C40, from zero up to but not
   including it. */
extern s16 D_80153C40;

s32 func_80411DF0_de(s32 index) {
    if (index >= 0 && index < D_80153C40) {
        return 1;
    }
    return 0;
}
