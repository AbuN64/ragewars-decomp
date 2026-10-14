#include "span_1000/code_80297CD0.h"
#include "span_1000/code_80299DB4.h"
#include "types.h"
#include "stddef.h"
/* Refreshes the selected entry and updates its interface state. */
void func_80297310_de(s32, s32, void *, s32, s32); /* extern */
                               /* extern */
extern State_func_80297DBC_de *D_8014D080;
void func_80297DBC_de(void) {
    s32 (*temp_v0)(s32);
    s32 temp_s0;
    s32 value, param;
    temp_s0 = D_8014D080->unk4;
    temp_v0 = D_8014D080->unk10;
    param = (&D_8014D080->unkC[temp_s0])->unk4;
    if (temp_v0 != NULL) {
        value = temp_v0(param);
        (&D_8014D080->unkC[temp_s0])->unk0->unk40 = value;
    }
    func_80297310_de(1, 0xE06, 0, 0, 0);
    func_80297310_de(1, 0xE07, 0, 0, 0);
    (&D_8014D080->unkC[temp_s0])->unkC.readPosition = 0;
    func_80297310_de(1, 0xE02, &D_8014D080->unkC[temp_s0].unkC, 0, 0);
    func_80299C80_de(&D_8014D080->unkC[temp_s0].unkC);
}
