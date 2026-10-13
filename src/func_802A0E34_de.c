#include "span_1000/code_802A0AC4.h"
#include "types.h"

extern void func_802547E4_de(void *);

static inline void clear_resource_state(void) {
    D_800CD940_de[0] = 0;
    D_800CD940_de[3] = 0;
    D_800CD940_de[4] = 0;
}

void func_802A0E34_de(void) {
    D_800D2B80--;
    if (D_800CD940_de[0] != 0) {
        func_802547E4_de(D_800CD940_de[0]);
    }
    clear_resource_state();
}
