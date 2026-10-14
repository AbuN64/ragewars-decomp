#include "shared/world.h"
#include "span_16E000/code_804264F0.h"
#include "types.h"
/* Enumerates the eight item identifiers of the record func_8028D474_de finds for a key and registers each nonzero identifier above 0x4C3 through func_8042854C_de, translated by 0x4C3 and numbered in order. */





extern Record_func_804284C0_de *func_8028D474_de(void *table, s32 key);
extern void func_8042854C_de(s32 slot, s32 item, s32 arg2);

void func_804284C0_de(s32 key) {
    Record_func_804284C0_de *record;
    s32 count;
    s32 i;
    s32 item;

    func_80428700_de();
    record = func_8028D474_de(&D_8011FE88, key);
    count = 0;
    for (i = 0; i < 8; i++) {
        item = record->items[i];
        if (item >= 0x4C3) {
            item -= 0x4C3;
            if (item != 0) {
                func_8042854C_de(count, item, 0);
                count++;
            }
        }
    }
}
