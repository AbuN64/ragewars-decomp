#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8024E130.h"
#include "types.h"

/* Returns the float at offset 0x20 of the entry func_8028B2F8_de finds in D_8011FE88 for an object's
   key at 0x14, when the key's flag halfword at 2 has bit 0 set; zero otherwise. */







extern struct func_8022CA04_S3 *func_8028B2F8_de(void *, struct StateFlags *);

f32 func_8024E80C_de(struct Object_func_8024E80C_de *object) {
    struct func_8022CA04_S3 *entry;

    if (object->key != 0 && (object->key->flags & 1)) {
        entry = func_8028B2F8_de(&D_8011FE88, object->key);
        if (entry != 0) {
            return entry->unk20;
        }
    }
    return 0.0f;
}
