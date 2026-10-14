#include "span_16E000/code_80400000.h"
extern int D_800DE7E8;
extern unsigned char *D_80145060;
extern void func_804030E0_de(int);
static inline int test_bit(unsigned char *bits, int index) {
    int offset = index >> 3;
    int mask;
    index &= 7;
    mask = 1;
    bits += offset;
    return *bits & (mask << index);
}
static inline void set_bit(unsigned char *bits, int index) {
    int offset = index >> 3;
    int mask;
    index &= 7;
    mask = 1;
    bits += offset;
    *bits |= mask << index;
}
void func_804037E8_de(int event) {
    unsigned char *bits = D_80145060;
    int index;
    if (D_800DE7E8 != 0) {
        index = event - 0x259;
        if ((unsigned int)index < 6 && bits != 0) {
            if (test_bit(bits + 0x638, index)) return;
            set_bit(bits + 0x638, index);
        }
        func_804030E0_de(event);
    }
}
