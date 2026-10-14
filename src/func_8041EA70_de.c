#include "span_16E000/code_8041DF04.h"
#include "types.h"

/* Resets the three 28-byte entries of D_80153F80: -1 in the first word and zero in the next
   three. */


extern struct RequestRecAt10 D_80153F80[];

void func_8041EA70_de(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        D_80153F80[i].id = -1;
        D_80153F80[i].variant = 0;
        D_80153F80[i].word8 = 0;
        D_80153F80[i].variantC = 0;
    }
}
