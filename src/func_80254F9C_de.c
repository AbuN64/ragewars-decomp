#include "span_1000/code_802508E0.h"
#include "span_C76B0/data.h"

#include "common/unused.h"
#include "types.h"

extern s32 D_80100560;

extern void func_802BB420_de(void *arg0, s32 arg1, s32 arg2);

void func_80254F9C_de(s32 unused, s32 arg1) {
    s32 mask;
    u32 count;
    s32 new_var;
    u32 new_var2;
    s32 offset;
    u32 limit;

    if (D_801005A0[arg1] != 0) {
        D_801005A0[arg1] = 0;
        func_802BB420_de(&D_80101160, 0, 1);
    }
    mask = -0x201;
    if (arg1 != 0) {
        mask = -0x401;
    }
    do { count = 0; limit = D_800CB6E0; } while (0);
    new_var2 = limit;
    if (limit != 0) {
        offset = count;
        do {
            new_var = offset + D_80100560;
            count += 1;
            *(s32 *)&((Node80254C10 *)new_var)->flags &= mask;
            offset += 0x28;
        } while (count < new_var2);
    }
    do { D_80101134[arg1] = 0; } while (0);
}
