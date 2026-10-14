#include "shared/world.h"
#include "span_1000/code_80277444.h"
#include "span_1000/code_8028B64C.h"
#include "types.h"






s32 func_8028C424_de(char *object, s32 type) {
    s32 index;
    Record14 *record;
    u8 *flags;

    index = ((Shared_World *)object)->recordCount;
    record = ((Shared_World *)object)->recordArray;
    index--;
    if (index != -1) {
        flags = &record->flags;
        do {
            if (flags[1] == type &&
                (*flags & 0x40) == 0) {
                return 0;
            }
            index--;
            flags += sizeof(Record14);
        } while (index != -1);
    }

    index = ((Shared_World *)object)->alternateRecordCount;
    record = ((Shared_World *)object)->alternateRecordArray;
    index--;
    if (index != -1) {
        do {
            if (record->kind == type &&
                (record->flags & 0x40) == 0) {
                return 0;
            }
            index--;
            record++;
        } while (index != -1);
    }

    return 1;
}
