#include "span_1000/code_8025C544.h"
#include "types.h"
/* Picks a random entry from the range func_80265550_de finds for an id in the owner's table: returns -1
 * when there is none and the single entry when the range has one; otherwise every entry weighs 100, a
 * random draw selects one, and when it equals the entry to avoid it steps to the next entry (or back
 * from the last). */

extern s32 func_80265550_de(s32, s32, s32, s32 *, s32 *);
extern s32 func_802744D4_de(void);




s32 func_8025D238_de(void **arg0, s16 id, s16 avoid) {
    s32 first;
    s32 last;
    s32 total;
    s32 entry;
    s32 draw;
    Context_func_8025D450_de *table;
    s32 result;

    total = 0;
    table = *arg0;
    if (func_80265550_de(table->unk2B60, table->unk2B64, id, &first, &last) == 0) {
        return -1;
    }
    result = first;
    if (result != last) {
        for (entry = first; entry <= last; entry++) {
            total += 100;
        }
        draw = func_802744D4_de() % total;
        total = 0;
        for (entry = first; entry < last; entry++) {
            total += 100;
            if (total >= draw) {
                break;
            }
        }
        if (avoid != 0 && entry == avoid) {
            if (entry == last) {
                entry--;
            } else {
                entry++;
            }
        }
        result = entry;
    }
    return result;
}
