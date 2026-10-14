#include "span_1000/code_802A208C.h"





int func_802A1E20_de(struct CommandListController *object) {
    struct LinkedCommandEntry *record = object->entries;
    object->state = 2;
    object->progress = 0;
    while (record != 0) {
        if (record->kind != 8) {
            record->command = 200;
        }
        record = record->next;
    }
    return 0;
}
