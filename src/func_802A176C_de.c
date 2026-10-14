#include "span_1000/code_802A1264.h"
#include "types.h"

extern s32 D_800CD960_de;
extern s32 D_800CD964[2];

extern void func_802547E4_de(void *);

void func_802A176C_de(void) {
    if (D_800CD960_de != 0) {
        func_802547E4_de(D_800CD964[0]);
        func_802547E4_de(D_800CD964[1]);
        D_800CD964[0] = 0;
        D_800CD964[1] = 0;
        D_800CD960_de = 0;
    }
}
