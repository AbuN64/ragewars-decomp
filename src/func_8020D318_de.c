#include "shared/navigation_graph.h"
#include "span_1000/code_8020AF9C.h"



/** Report whether the word at object offset 0x28 equals two. */
int func_8020D318_de(void *arg0) {
    NavigationSearchNode *node = arg0;
    return node->open == 2;
}
