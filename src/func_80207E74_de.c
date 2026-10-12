#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80207ABC.h"
extern void func_80214178_de(void *a, void *b, int c);




void func_80207E74_de(struct Shared_Actor *arg0, int *arg1) {
    arg0->weaponFlags |= 0x2100;
    *arg1 |= 0x20000;
    func_80214178_de(arg0, arg1, 3);
}
