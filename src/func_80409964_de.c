#include "span_16E000/code_80405DC0.h"
#include "types.h"
#include "stddef.h"
/* Releases the two active resources and clears their associated state. */
void func_80253838_de(void *, void *); /* extern */
void func_80253908_de(s32); /* extern */
extern void *D_800DE860_de;
extern struct Shape_typemap_165 *D_800DE864_de;
extern s32 D_800DE868;
extern s32 D_800E28BC;
void func_80409964_de(void) {
    if ((D_800DE860_de != 0) || (D_800DE864_de != 0)) {
        func_80253908_de(0);
    }
    if (D_800DE860_de != 0) {
        func_80253838_de(0, D_800DE860_de);
    }
    if (D_800DE864_de != 0) {
        func_80253838_de(0, D_800DE864_de);
    }
    D_800DE860_de = 0;
    D_800DE864_de = 0;
    D_800DE868 = 0;
    D_800E28BC = 0;
}
