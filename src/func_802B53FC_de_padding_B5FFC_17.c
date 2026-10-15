#include "span_1000/code_802B0388.h"
#include "types.h"

extern void func_802B1E50_de(void *arg0, f32 arg1);

void func_802B1DEC_de(void *arg0, void *arg1) {
    u8 *p = (u8 *)arg1;
    int pad[4];

    (void)pad;
    if (p[8] == 0xFF && p[9] == 0x51) {
        func_802B1E50_de(arg0, (f32)((p[0xB] << 0x10) | (p[0xC] << 8) | p[0xD]));
    }
}
