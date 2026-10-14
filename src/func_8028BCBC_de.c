#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8028B64C.h"
#include "types.h"

extern void *func_8028FDB4_de(void *, s32);





/* Finds an identifier in the object's list and returns its mapped byte from the resource record, or -1 when absent. */
s32 func_8028BCBC_de(ObjectRecAtB0 *arg0, s32 arg1) {
    s32 i;
    void *record;
    Table *list = arg0->list;
    s32 count = list->unk4;
    s32 *ids = list->deltas;

    for (i = 0; i < count; i++) {
        if (ids[i] == arg1) {
            record = func_8028FDB4_de(arg0->resource, 1);
            func_8028FDB4_de(record, 0);
            return ((u8 *)func_8028FDB4_de(record, 1))[i];
        }
    }
    return -1;
}
