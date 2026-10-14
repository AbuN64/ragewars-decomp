#include "span_1000/code_802A208C.h"





/** Reset the object state and mark non-type-eight linked records. */
int func_802A1DE4_de(struct CommandListController *object) {
    struct LinkedCommandEntry *record = object->entries;
    object->state = 2;
    object->progress = 0;
    while (record != 0) {
        if (record->kind != 8) {
            record->command = 100;
        }
        record = record->next;
    }
    return 0;
}
