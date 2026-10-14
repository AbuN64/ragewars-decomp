#include "shared/world.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8022D944.h"
#include "types.h"

/* Returns whether the entry func_8028B2F8_de finds in D_8011FE88 for an object's key at 0x14 exists
   and has bit 6 of its flags at 0x52 set. */





extern struct Entry_func_8022E130_de *func_8028B2F8_de(void *, s32);

s32 func_8022E130_de(struct func_80204468_S3 *object) {
    struct Entry_func_8022E130_de *entry;

    if (object->unk14 != 0) {
        entry = func_8028B2F8_de(&D_8011FE88, object->unk14);
        if (entry != 0 && (entry->flags & 0x40)) {
            return 1;
        }
    }
    return 0;
}
