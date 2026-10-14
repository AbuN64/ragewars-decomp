#include "span_1000/code_8022AE90.h"
#include "types.h"







/** Return the linked record with the greatest eight-slot score excluding itself. */
void *func_8022BA0C_de(Context *context) {
    Record_func_8022BA0C_de *node;
    Record_func_8022BA0C_de *base;
    Record_func_8022BA0C_de *bestNode = 0;
    int best = -1;

    node = context->head;
    if (node != 0) {
        base = context->base;
        do {
            unsigned int own = (unsigned int)((u8 *)node - (u8 *)base) / sizeof(Record_func_8022BA0C_de);
            int score = 0;
            int i;
            for (i = 0; i < 8; i++) {
                if (i == own) {
                    continue;
                }
                score += node->scores->value[i];
                if (best < score) {
                    best = score;
                    bestNode = node;
                }
            }
            node = node->next;
        } while (node != 0);
    }
    return bestNode;
}
