#include "span_1000/code_8028CCB8.h"
#include "types.h"

extern char *func_8028FDB4_de(s32 *, s32);

void *func_8028CF6C_de(void *arg0, s32 arg1) {
    void *result;

    if (arg1 == -1) {
        goto ret_null;
    }
    result = func_8028FDB4_de(((struct ObjRecAt78V1 *) ((s8 *) arg0))->unk78, arg1);
    goto end;
ret_null:
    result = 0;
end:
    return result;
}
