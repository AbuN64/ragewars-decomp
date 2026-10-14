#include "span_1000/code_8024BA6C.h"
extern void func_802164A8_de(void *a, void *b);

/** Thin wrapper forwarding arg0 and an offset of it to func_802164A8_de. */
void func_8024BE3C_de(void *arg0) {
    func_802164A8_de(arg0, (char *)arg0 + 0x170);
}
