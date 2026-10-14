#include "span_16E000/code_804453C4.h"
#include "types.h"

extern s32 D_801462C8;

/* Toggles bit 0 of the settings flag word D_801462C8 and returns 0. */
s32 func_8043D25C_de(void) {
    D_801462C8 ^= 1;
    return 0;
}
