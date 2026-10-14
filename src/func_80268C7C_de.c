#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80268160.h"
#include "types.h"

s32 func_80255CB8_de(void *, s32);
s32 func_80255ED8_de();
void func_80268C7C_de(void *a, s32 b) {
    (((struct Limit *) ((s8 *) b))->limit) = 0;
    func_80255ED8_de();
    func_80255CB8_de(a + 0x14, b);
}
