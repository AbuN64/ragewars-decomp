#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8028CCB8.h"
#include "types.h"

extern void *func_8028FDB4_de(void *, s32);
extern void func_8028FDF8_de(s32 arg0, s32 arg1);




void func_8028DAB4_de(struct World_func_8028787C_de *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *base;
    void *temp_v0;

    if (arg1 != 0) {
        base = arg0->levels;
    } else {
        base = arg0->secondaryLevels;
    }
    temp_v0 = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(base, 0), arg3), arg2);
    func_8028FDB4_de(temp_v0, 0);
    func_8028FDF8_de((s32) temp_v0, 1);
    func_8028FDB4_de(temp_v0, 1);
}
