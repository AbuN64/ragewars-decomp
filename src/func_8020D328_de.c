#include "span_1000/code_8020AF9C.h"
#include "types.h"






s32 func_8020D328_de(void *arg0) {
    NavigationGraph *graph = (NavigationGraph *)arg0;
    NavigationSearchNode *record = graph->nodes;
    if (record != 0) {
        do {
            if (record->open == 1) {
                return 1;
            }
            record = record->next;
        } while (record != 0);
    }
    return 0;
}
