#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8020AF9C.h"
/** Return the index of the link joining two nodes, accepting reversed links of two-way types, or -1. */






static inline int isTwoWay(Link *link) {
    switch (link->type) {
    case 1:
    case 4:
    case 7:
        return 1;
    }
    return 0;
}




int func_8020CC0C_de(Graph *graph, int from, int to) {
    int i;
    Link *link;

    for (i = 0; i < graph->count; i++) {
        link = (Link *)((char *)&graph->links->first + i * graph->links->stride);
        if (link->from == from && link->to == to) {
            return i;
        }
        if (link->to == from && link->from == to && isTwoWay(link)) {
            return i;
        }
        if (link->to == from && link->from == to && link->type == 6) {
            return i;
        }
    }
    return -1;
}
