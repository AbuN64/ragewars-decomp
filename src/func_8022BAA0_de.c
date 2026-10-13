#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022BA90.h"





/** Report whether the nested pointer's word at 0x564 is nonzero. */
int func_8022BAA0_de(void *object) {
    func_80228774_S5 *object_record = object;
    func_8021CD70_S4 *nested = object_record->unk5DC;
    if (nested != 0) {
        return nested->unk564 != 0;
    }
    return 0;
}
