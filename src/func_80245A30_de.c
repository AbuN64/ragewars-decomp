#include "span_1000/code_80245980.h"
#include "types.h"
#include "shared/func_804235A8_eu_layout.h"
extern void *D_800E2830;


extern s32 D_800E28D0;
extern int D_800E28D4;




/** Copy a two-word record into the global record and clear two trailing fields. */
void func_80245A30_de(void) {
    Shared_MenuContext *record = D_800E2830;
    int hi = D_800E28D4;
    int lo = D_800E28D0;
    record->unknown104[2] = hi;
    record->unknown104[1] = lo;
    record->unknown104[3] = 0;
    record->unknown104[4] = 0;
}
