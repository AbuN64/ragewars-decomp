#include "common/types_06e4f7ef1f9e.h"
#include "span_16E000/code_80423280.h"
#include "types.h"

/* Sets the word at offset 0xC of the object D_800E4514 points to and calls func_802A2360_de, once:
   nothing happens when the word is already set. Returns zero. */


extern struct func_80205628_S3 *D_800E4514;
extern void func_802A2360_de();

s32 func_80423620_de(void) {
    struct func_80205628_S3 *state = D_800E4514;

    if (state->unkC == 0) {
        state->unkC = 1;
        func_802A2360_de();
    }
    return 0;
}
