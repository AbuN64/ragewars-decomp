#include "span_1000/code_802393F4.h"
#include "types.h"

extern void func_8025E3F0_de(s32 arg0);
extern void func_80253908_de(s32 a);
extern void func_80253838_de(void *, void *);




void func_8023A1F4_de(void *arg0) {
    s32 temp_a1;

    ((struct ScreenMessageOwner *)arg0)->state = 1;
    func_8025E3F0_de((s32)&((struct ScreenMessageOwner *)arg0)->rendering);
    func_80253908_de(0);
    temp_a1 = ((struct ScreenMessageOwner *)arg0)->allocation;
    if (temp_a1 != 0) {
        func_80253838_de(0, temp_a1);
        ((struct ScreenMessageOwner *)arg0)->allocation = 0;
        ((struct ScreenMessageOwner *)arg0)->allocationSize = 0;
        ((struct ScreenMessageOwner *)arg0)->count = 0;
    }
}
