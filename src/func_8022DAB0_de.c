#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_8022D944.h"
#include "types.h"

extern void func_80225F44_de(void);
extern void func_802227F4_de(void *arg0, void *arg1, int arg2);




void func_8022DAB0_de(void *arg0, void *arg1) {
    struct SharedPlayer *a0 = arg0;
    void *a1 = arg1;

    func_80225F44_de();
    if (a0->views5E8.view6C0_51.unk6C0 == 0.0f) {
        func_802227F4_de(a0, a1, 0x24);
    }
}
