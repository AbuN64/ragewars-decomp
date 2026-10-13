#include "span_1000/code_80208000.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80231F5C.h"
#include "types.h"






void func_80232744_de(void *arg0, s32 arg1, s32 arg2) {
    AiTarget *target = arg0;
    func_8021A9A4_de(target->player, arg2);
}

extern int *D_800CB358_de[];

/** Return the value pointed to by the indexed pointer table entry. */
int func_80232764_de(int arg0) {
    return *D_800CB358_de[arg0];
}

s32 func_80232780_de(s32 arg0) {
    if (arg0 < 7) {
        if (arg0 >= 3) {
            return 1;
        }
    }
    return 0;
}
