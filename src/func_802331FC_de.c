#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80231F5C.h"
/* FAKEMATCH: retains inherited volatile storage qualifiers to preserve compiler load/store order; semantic volatility has not been established. */
#include "types.h"

extern struct Shape_func_8020AF9C_de_2 D_80140FF8;
extern void *D_800D052C[];
extern f32 D_800C3048_de[2];

extern void func_802227F4_de(void *, void *, s32);

extern s32 func_80214178_de(void *, void *, s32);
extern void func_8022AEA0_de(void *arg0, s32 arg1);
extern void func_8022AF74_de(void *arg0, s32 arg1);












void func_802331FC_de(void *arg0, void *arg1) {
    void *temp_s0;
    void *temp_a0;
    s16 index;

    temp_s0 = ((func_8020A028_S3 *)(arg0))->unk1D8;
    if (((ObjectState140 *)(arg1))->unk_13C == 2) {
        func_802227F4_de(temp_s0, temp_s0, 2);
    } else {
        ((ObjectState140 *)(arg1))->unk_64 = D_800C3048_de[0];
        if ((((func_8022E3B4_S1 *)(temp_s0))->unk1450 == 0) &&
            (D_80140FF8.field_0 == 1)) {
            func_8021A9A4_de(((func_8020A028_S3 *)(arg0))->unk1D8, 0x3FB);
        } else {
            func_8021A9A4_de(((func_8020A028_S3 *)(arg0))->unk1D8, 0x4CD);
        }
        func_80214178_de(arg0, arg1, 4);
        func_8022AEA0_de(temp_s0, 0x977);
        func_8022AF74_de(temp_s0, 0x974);

        temp_a0 = ((func_8020A028_S3 *)(arg0))->unk1D8;
        index = ((func_80232C78_S2 *)(temp_a0))->unk62E;
        ((ObjectState140 *)(arg1))->unk_130 =
            ((func_80232C78_S4 *)(D_800D052C[index]))->unk18 *
            D_800C3048_de[1];
        if ((((func_80232C78_S2 *)(temp_a0))->unk62E == 8) &&
            (((func_80232C78_S2 *)(temp_a0))->unk11C0 == 0)) {
            func_8022AF74_de(temp_a0, 0xA3C);
        }
    }
}
