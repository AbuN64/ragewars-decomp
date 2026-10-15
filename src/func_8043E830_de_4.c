#include "span_16E000/code_8043E9A8.h"
#include "types.h"

/* Sets the option bytes at 0x1D and 0x1E of D_801462C8 to 1 and 4, clears the first byte of each
   of the eight 150-byte player records at 0x148, then calls func_804427C4_de with the third argument,
   the second and the resource D_0044FEA8, and returns one. */




extern struct Options_func_8043EBE4_de D_801462C8;
extern char D_0044FEA8[];
extern void func_804427C4_de(void *, void *, void *);

s32 func_8043EBE4_de(void *first, void *second, void *third) {
    struct Options_func_8043EBE4_de *options = &D_801462C8;
    s32 i;

    options->first = 1;
    options->second = 4;
    for (i = 0; i < 8; i++) {
        options->players[i].flag = 0;
    }
    func_804427C4_de(third, second, D_0044FEA8);
    return 1;
}
