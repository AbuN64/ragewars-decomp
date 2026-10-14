#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_8043962C.h"
#include "types.h"
#include "stddef.h"
/* Initializes the six object parameters and clears its transient state. */
void func_80439C80_de(); /* extern */
void func_80439CD4_de(void *, s32); /* extern */
s32 func_80439B5C_de(State_func_80439B5C_de *arg0, s32 arg1, Triple first, Triple second) {
    arg0->second = second;
    arg0->first = first;
    arg0->unk1C = 0;
    arg0->unk20 = 0;
    arg0->unk24 = 0;
    arg0->unk28 = 0;
    arg0->unk2C = 0;
    arg0->unk30 = 0;
    func_80439C80_de();
    func_80439CD4_de(arg0, 0);
    return arg0->unk34;
}
