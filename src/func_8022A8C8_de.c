#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022A274.h"
#include "types.h"






void func_8022A8C8_de(char *object, f32 arg1) {
    ObjRecAt20V2 *object_record = (void *)object;
    func_8022A8B8_S2 *record = object_record->unk20;
    if (record != 0) {
        do {
            record->unk670 = arg1;
            record = record->unk16E0;
        } while (record != 0);
    }
}
