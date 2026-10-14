#include "shared/navigation_graph.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8020AF9C.h"
#include "types.h"









void *func_8020D28C_de(void *arg0) {
    NavigationGraph *graph = arg0;
    NavigationSearchNode *node;
    NavigationSearchNode *best;
    f32 best_value;

    node = graph->nodes;
    best_value = (-1.0f);
    best = 0;
    if (node != 0) {
        do {
            if (node->open == 1) {
                f32 value = node->total;
                if (value < best_value || best_value == (-1.0f)) {
                    best = node;
                    best_value = value;
                }
            }
            node = node->next;
        } while (node != 0);
    }
    if (best != 0) {
        best->open = 0;
    }
    return best;
}
