#include "span_1000/code_8022D56C.h"
extern void func_80225B98_de(void *a, void *b, int c);

/** Thin wrapper around func_80225B98_de with a fixed third argument. */
void func_8022D900_de(void *a, void *b) {
    func_80225B98_de(a, b, 0x49);
}
