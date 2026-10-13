#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80231F5C.h"
#include "types.h"

extern void *D_800D052C[];

extern void func_8022AF74_de(void *arg0, s32 arg1);










void func_80232C88_de(void *arg0, void *arg1) {
    void *temp_a0;
    s16 idx;

    temp_a0 = ((func_8020A028_S3 *)(arg0))->unk1D8;
    idx = ((func_80232C78_S2 *)(temp_a0))->unk62E;
    ((func_80228774_S7 *)(arg1))->unk130 = ((func_80232C78_S4 *)(D_800D052C[idx]))->unk18 * D_800C3020_de;
    if ((((func_80232C78_S2 *)(temp_a0))->unk62E == 8) && (((func_80232C78_S2 *)(temp_a0))->unk11C0 == 0)) {
        func_8022AF74_de(temp_a0, 0xA3C);
    }
}
