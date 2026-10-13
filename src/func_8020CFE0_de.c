#include "span_1000/code_8020AF9C.h"
#include "types.h"






void *func_8020CFE0_de(char *object, s32 arg1) {
    NavigationGraph *graph = (NavigationGraph *)object;
    NavigationSearchNode *record = graph->nodes;
    if (record != 0) {
        do {
            if (record->key == arg1) {
                return record;
            }
            record = record->next;
        } while (record != 0);
    }
    return 0;
}
