#include "shared/navigation_graph.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8020AF9C.h"



/** Set the word at byte offset 0x28 to the state value two. */
void func_8020D2FC_de(void *object) {
    NavigationSearchNode *node = object;
    node->open = 2;
}
