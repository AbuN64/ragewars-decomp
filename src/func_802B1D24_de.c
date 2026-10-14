#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B0388.h"
#include "types.h"



extern s32 func_802B22F4_de(void *arg0, s32 *arg1);
extern s32 func_802B20C8_de(void *arg0);
extern void func_802B22BC_de(void *arg0, void *arg1);
extern s32 func_802B00D4_de(void *, s16 *, s32);




void func_802B1D24_de(void *arg0) {
    Message_func_802AF150_de sp10;
    s32 sp20;
    s32 temp_v1;
    void *temp_s0;

    temp_s0 = ((ObjectLinks88 *)(arg0))->unk_18;
    if ((((ObjectLinks88 *)(arg0))->unk_2C == 1) && (temp_s0 != 0) &&
        (func_802B22F4_de(temp_s0, &sp20) & 0xFF)) {
        if ((((ObjectLinks88 *)(arg0))->unk_84 != 0) &&
            ((func_802B20C8_de(temp_s0) + sp20) >=
             ((struct func_80254D70_S2 *) ((ObjectLinks88 *) arg0)->unk_80)->unk8)) {
            func_802B22BC_de(temp_s0, ((ObjectLinks88 *)(arg0))->unk_7C);
            temp_v1 = ((ObjectLinks88 *)(arg0))->unk_84;
            if (temp_v1 != -1) {
                ((ObjectLinks88 *)(arg0))->unk_84 = temp_v1 - 1;
            }
        }
        sp10.type = 0;
        func_802B00D4_de(&((ObjectLinks88 *)(arg0))->unk_48, &sp10,
                      sp20 * ((ObjectLinks88 *)(arg0))->unk_24);
    }
}
