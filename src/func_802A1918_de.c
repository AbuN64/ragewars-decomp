#include "span_1000/code_802A1264.h"
#include "types.h"

extern s32 D_800E28D0;
extern int D_800E28D4;

/** Copy the global two-word record into the two output pointers. */
void func_802A1918_de(int *arg0, int *arg1) {
    *arg0 = D_800E28D0;
    *arg1 = D_800E28D4;
}
