#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8028B64C.h"
#include "types.h"

extern char *func_8028FDB4_de(s32 *, s32);

s32 func_8028BDAC_de(void *arg0, s32 arg1) {
    void *temp_v0;
    u8 *result;

    temp_v0 = func_8028FDB4_de((((struct Field_void_80 *) ((s8 *) arg0))->value), 1);
    func_8028FDB4_de(temp_v0, 0);
    result = (u8 *)func_8028FDB4_de(temp_v0, 1) + arg1;
    return *result == 0;
}
