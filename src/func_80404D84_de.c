#include "span_16E000/code_80403BCC.h"
#include "shared/func_80404D84_de_closed.h"

void func_80404D84_de(void) {
    struct Shape_typemap_165 *temp_v0;
    s32 temp_a0;

    temp_v0 = func_8025343C_de(0, 0x810, 0x23, &D_800DCCC0);
    temp_a0 = temp_v0->field_0;
    D_800DE808 = (s32 *)temp_v0;
    D_800E2854 = temp_a0;
    func_802A001C_de((void *)temp_a0, 0, 0x810);
    D_800E2850 = 1;
}

/* Releases the save buffer and clears its global state. */
extern void func_80253908_de(int);
extern void func_80253838_de(int, int *);
extern int D_800E2850;
extern int D_800E2854;
extern int *D_800DE808;

void func_80404DDC_de(void) {
    func_80253908_de(0);
    if (D_800DE808) {
        func_80253838_de(0, D_800DE808);
        D_800DE808 = 0;
        D_800E2854 = 0;
    }
    D_800E2850 = 0;
}
