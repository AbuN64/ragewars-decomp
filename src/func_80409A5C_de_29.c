#include "span_16E000/code_8040A83C.h"
#include "types.h"

/* Sets the state word D_80153788 to 0xF; this is one of a run of functions that each store one
   state number there, and func_8040AAB8_de clears it. */
extern s32 D_80153788;

void func_8040AC40_de(void) {
    D_80153788 = 0xF;
}
