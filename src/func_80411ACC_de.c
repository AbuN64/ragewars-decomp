#include "span_16E000/code_8040F1E0.h"
#include "types.h"

/* Returns entry i of the word array D_80153C14 points to. */
extern s32 *D_80153C14;

s32 func_80411ACC_de(s32 index) {
    return D_80153C14[index];
}
