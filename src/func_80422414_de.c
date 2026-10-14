#include "common/types_8fd754e1e915.h"
#include "span_16E000/code_804221A0.h"
#include "types.h"

/* Sets the word at offset 0x20 of the object D_800E44A0 points to and returns zero. */


extern struct func_8022A404_S1 *D_800E44A0;

s32 func_80422414_de(void) {
    D_800E44A0->unk20 = 1;
    return 0;
}
