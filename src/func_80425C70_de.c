#include "shared/world.h"
#include "span_16E000/code_804251F4.h"
/* Looks up the record keyed by key in the table set D_8011FE88 and copies its trial preset at row and
   column into the shared result buffer D_8014DD50, returning the buffer, or null when there is no such
   record. */
#include "types.h"









extern Preset D_8014DD50;
extern PresetTable *func_8028D474_de(void *table, s32 key);
extern void *func_802BD3A0_de(void *destination, const void *source, int count);

Preset *func_80425C70_de(s32 key, s32 row, s32 column) {
    PresetTable *table;

    table = func_8028D474_de(&D_8011FE88, key);
    if (table == 0) {
        return 0;
    }
    func_802BD3A0_de(&D_8014DD50, &table->rows[row].presets[column], sizeof(Preset));
    return &D_8014DD50;
}
