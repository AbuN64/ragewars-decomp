#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80400000.h"



/** Advance a byte pointer by eight bytes. */
void *func_80403B04_de(void *value) {
    ObjRecAt8V2 *record = value;
    return &record->unk8;
}
