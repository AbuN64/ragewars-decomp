#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80443868.h"
#include "types.h"
/* Forwards arg1's word at 0x1C to func_8044972C_de and always reports success. */

extern s32 func_8044972C_de(s32 arg0);



s32 func_80443710_de(void *arg0, MenuRules *arg1) {
    func_8044972C_de(arg1->locked);
    return 1;
}
