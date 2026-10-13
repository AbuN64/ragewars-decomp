#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022BA90.h"
#include "types.h"

extern void func_8022BE20_de(void *arg0, void *arg1);
extern void func_8022BEFC_de(void *arg0, void *arg1);
extern void func_8022C060_de(void *arg0, void *arg1);






void func_8022BD94_de(void *arg0, void *arg1, s32 arg2) {
    func_8022BD84_S2 *object = arg0;
    func_8020D1FC_S1 *argument = arg1;
    s32 flags;
    s32 flag_1000;
    s32 flag_8000;
    s32 flag_10000;

    if (arg2 != 0) {
        flags = argument->unk38;
        flag_1000 = flags & 0x1000;
        flag_8000 = flags & 0x8000;
        flag_10000 = flags & 0x10000;
        if (flag_1000 == 0) {
            object->unk840 = 0;
        } else {
            func_8022BE20_de(arg0, arg1);
        }
        if (flag_8000) {
            func_8022BEFC_de(arg0, arg1);
        }
        if (flag_10000) {
            func_8022C060_de(arg0, arg1);
        }
    }
}
