#include "TYPES.H"
#include "common/data.h"
#include "common/unused.h"
#include "shared/func_80404D84_de_closed.h"
#include "span_1000/code_80291054.h"
#include "span_1000/code_8028DF6C.h"
#include "span_C76B0/data.h"

void func_80253838_de(s32, void *);
u32 func_80265350_de(void);
void *func_80253530_de(s32, s32, u32, void *);

extern u8 D_800DCD1C[];
extern u8 D_800DCD0C[];
extern u8 D_800DCD3C[];
extern u8 D_800DCD54[];
extern s32 D_800DCD4C;
extern u8 D_800DCD00_de[];
extern s32 D_8014D460;
extern s32 D_8014D42C;
extern s32 D_8014D430_de;

void func_804058B0_de(void **param_1) {
    void **puVar2;
    u32 uVar3;
    s32 *piVar4;
    s32 *piVar5;
    u32 uVar6;
    u32 uVar7;
    s32 iVar8;
    u32 blockSize;
    s32 count;
    s32 i;

    if (param_1[1] != 0) {
        func_80253838_de(0, param_1[1]);
    }
    if (param_1[2] != 0) {
        func_80253838_de(0, param_1[2]);
    }
    if (param_1[6] != 0) {
        func_80253838_de(0, param_1[6]);
    }
    if (param_1[7] != 0) {
        func_80253838_de(0, param_1[7]);
    }
    iVar8 = 0;
    puVar2 = param_1;
    do {
        if (puVar2[3] != 0) {
            func_80253838_de(0, puVar2[3]);
        }
        iVar8 = iVar8 + 1;
        puVar2 = puVar2 + 1;
    } while (iVar8 < 3);

    iVar8 = 2;
    puVar2 = param_1 + 2;
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[6] = 0;
    param_1[7] = 0;
    do {
        puVar2[3] = 0;
        iVar8 = iVar8 - 1;
        puVar2 = puVar2 - 1;
    } while (-1 < iVar8);

    uVar3 = func_80265350_de();
    if (uVar3 < 0x600000) {
        blockSize = 0x1ecc0;
        piVar4 = (s32 *)func_80253530_de(0, (s32)(0x80400000U + (D_800DE850 + 1) * -0x1ecc0),
                                         (D_800DE850 + 1) * 0x1ecc0, D_800DCD1C);
        count = D_800DE850;
        param_1[3] = piVar4;
        for (i = 0; i < count; i++) {
            D_8014D468_de[i] = (void *)(*piVar4 + i * 0x1ecc0);
        }
        D_801536E8 = (void *)(*piVar4 + count * 0x1ecc0);
    } else {
        uVar3 = func_80265350_de();
        D_800DE850 = 3;
        piVar4 = (s32 *)func_80253530_de(0, (s32)((uVar3 | 0x80000000) - 0x100000), 0x54600,
                                         D_800DCD00_de);
        blockSize = 0x54600;
        piVar5 = (s32 *)func_80253530_de(0, (s32)((uVar3 | 0x80000000) - 0x200000),
                                         D_800DE850 * 0x54600, D_800DCD0C);
        func_802A001C_de((void *)*piVar5, 0, 0xfd200);
        func_802A001C_de((void *)*piVar4, 0, 0x54600);
        param_1[6] = piVar4;
        param_1[3] = piVar5;
        count = D_800DE850;
        D_801536E8 = (void *)*piVar4;
        for (i = 0; i < count; i++) {
            D_8014D468_de[i] = (void *)(*piVar5 + i * 0x54600);
        }
    }

    for (i = 0; i < D_800DE850; i++) {
        func_802A001C_de(D_8014D468_de[i], 0, blockSize);
    }
    func_802A001C_de(D_801536E8, 0, blockSize);

    param_1[1] = func_8025343C_de(0, (D_800E28A4 + D_800DE858) * 0x10, 0x23, D_800DCD3C);
    param_1[2] = func_8025343C_de(0, 0x8000, 0x23, &D_800DCD4C);
    param_1[7] = func_8025343C_de(0, 0x22000, 0x23, D_800DCD54);
    iVar8 = D_800E28A4;
    D_8014D424 = 0x8000;
    D_8014D45C = 0x22000;
    D_8014D460 = *(s32 *)param_1[1];
    D_8014D420_de = *(s32 *)param_1[7];
    D_8014D42C = D_8014D460 + iVar8 * 8;
    D_8014D464 = D_8014D42C + D_800DE858 * 8;
    D_8014D428 = *(s32 *)param_1[2];
    D_8014D430_de = D_8014D464 + iVar8 * 8;
    if (D_800DE850 != 0) {
        uVar6 = 1;
        do {
            uVar7 = uVar6 < D_800DE850;
            uVar6 = uVar6 + 1;
        } while (uVar7);
    }
    *param_1 = (void *)1;
}
