#include "common/types_8fd754e1e915.h"
#include "span_16E000/code_804221A0.h"
#include "types.h"

/* Unless func_8043C308_de reports one for the object D_800E44A0 holds, calls func_802A2360_de and, when
   the object's word at 0x20 is one, calls func_802A2394_de, then func_80245B28_de and func_8042B2E4_de unless
   the option byte D_801462D5 is set, and finally resets the object through func_8043C278_de. Returns
   zero. */


extern struct func_8022A404_S1 *D_800E44A0;
extern u8 D_801462D5;
extern s32 func_8043C308_de(struct func_8022A404_S1 *);
extern void func_802A2360_de();
extern void func_802A2394_de();
extern void func_80245B28_de();
extern void func_8042B2E4_de();
extern void func_8043C278_de(struct func_8022A404_S1 *);

s32 func_80422340_de(void) {
    s32 one = 1;

    if (func_8043C308_de(D_800E44A0) == one) {
        return 0;
    }
    func_802A2360_de();
    if (D_800E44A0->unk20 != one) {
        return 0;
    }
    func_802A2394_de();
    if (D_801462D5 == 0) {
        func_80245B28_de();
        func_8042B2E4_de();
    }
    func_8043C278_de(D_800E44A0);
    return 0;
}
