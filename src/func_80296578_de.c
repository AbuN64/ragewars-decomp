#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80296014.h"
#include "types.h"

extern s32 func_80263154_de(void *arg0, s32 arg1);

s32 func_80296578_de(void *arg0) {
    s32 field;

    field = ((struct func_8022BC04_S3 *) ((s8 *) arg0))->unk10;
    if (field != 2) {
        return field == 1;
    }
    return func_80263154_de(arg0, 1) != 0;
}
