#include "shared/navigation_graph.h"
void func_8020D1FC_de(s32 arg0) {
    NavigationGraph *graph = (NavigationGraph *)arg0;
    s32 i;
    s32 value = -1;
    for (i = 63; i >= 0; i--) {
        graph->goals[i] = value;
    }
}
