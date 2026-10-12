#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_802022E0.h"
extern void func_80214178_de(void *a, void *b, int c);




void func_80203AB0_de(void *a, struct WeaponEventSource *b) {
    if (b->eventEnabled != 0) {
        func_80214178_de(a, b, 0x3E);
    }
}
