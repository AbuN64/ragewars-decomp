#include "common/types_8fd754e1e915.h"
#include "span_16E000/code_804221A0.h"
#include "types.h"

/* On event 3 with value 0xB, calls func_8029973C_de and sets the word at offset 0x20 of the object
   D_800E44A0 points to. Returns zero. */


extern struct func_8022A404_S1 *D_800E44A0;
extern void func_8029973C_de();

s32 func_804223CC_de(void *first, void *second, u32 event, s32 value) {
    if ((event >> 16) == 3 && value == 0xB) {
        func_8029973C_de();
        D_800E44A0->unk20 = 1;
    }
    return 0;
}
