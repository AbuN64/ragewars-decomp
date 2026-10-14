#include "span_16E000/code_80429C10.h"
#include "types.h"

/* Calls func_80265688_de on D_80154018 for each index from 0 to 0x27 with zero. */
extern char D_80154018[];
extern void func_80265688_de(void *, s32, s32);

void func_8042B350_de(void) {
    s32 i;

    for (i = 0; i < 0x28; i++) {
        func_80265688_de(D_80154018, i, 0);
    }
}
