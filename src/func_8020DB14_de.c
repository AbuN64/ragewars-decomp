#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8020D370.h"
/** Find the first of an object's four nodes that starts a type-6 link, record it and return 0; return 1 when none does. */






extern func_80205628_S3 D_8013B364;
extern Link *func_8020C9B0_de(func_80205628_S3 *, int);

int func_8020DB14_de(Obj_func_8020DB14_de *obj) {
    int j;
    int i;
    Link *link;
    func_80205628_S3 *graph = &D_8013B364;

    obj->node = -1;
    obj->pending = 0;
    for (j = 0; j < 4; j++) {
        for (i = 0; i < graph->unkC; i++) {
            link = func_8020C9B0_de(graph, i);
            if (link->from == obj->nodes[j] && link->type == 6) {
                obj->hits++;
                obj->node = obj->nodes[j];
                return 0;
            }
        }
    }
    return 1;
}
