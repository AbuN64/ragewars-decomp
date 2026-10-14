#include "span_1000/code_8020AF9C.h"
#include "types.h"

extern void func_8020D014_de(void *arg0);
extern void func_8020D1FC_de(s32);
extern void func_8020D220_de(void *, s32);
extern void func_8020D0CC_de(void *arg0, s32 arg1);

void func_8020D070_de(void *arg0, s32 arg1, s32 arg2) {
    func_8020D014_de(arg0);
    func_8020D1FC_de((s32) arg0);
    func_8020D220_de(arg0, arg2);
    func_8020D0CC_de(arg0, arg1);
}
