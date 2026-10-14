#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80277444.h"
#include "types.h"

extern void func_80217388_de(void);
extern void func_80262C88_de(struct Shared_Actor *arg0);




void func_802790C0_de(struct Shared_Actor *arg0, s32 *arg1) {
    s32 temp_v0;

    func_80217388_de();
    *arg1 |= 0x20;
    temp_v0 = arg0->weaponFlags & 0xFFFEFFFF;
    temp_v0 = temp_v0 & ~0x2000;
    temp_v0 = temp_v0 & ~0x100;
    arg0->weaponFlags = temp_v0;
    if (temp_v0 & 0x80000) {
        func_80262C88_de(arg0);
    }
}
