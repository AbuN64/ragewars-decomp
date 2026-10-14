#include "span_1000/code_8024E914.h"
#include "span_1000/code_8028FC98.h"
#include "types.h"

extern f32 D_801031F8[];

extern s32 func_8024D160_de(void *arg0);








void func_8029076C_de(ContainerRecAt3C04 *arg0, Results *arg1) {
    f32 *bounds;
    s32 count;
    s32 mask;
    s32 required;
    s32 limit;
    Node_func_8029076C_de *node;

    node = arg0->head;
    if (node != 0) {
        mask = 0x30000;
        required = 0x20000;
        bounds = D_801031F8 + 1;
        limit = 0x200;
        do {
            func_8024F470_de(node);
            if (((node->flags & mask) == required) &&
                (func_8024D160_de(node) != 0) &&
                !(*(u16 *)&node->flags & 0x100) &&
                (bounds[0] > node->x0) &&
                (bounds[-3] < node->y0) &&
                (bounds[2] > node->x2) &&
                (bounds[-1] < node->y2) &&
                (bounds[1] > node->x1) &&
                (bounds[-2] < node->y1)) {
                count = arg1->count;
                if (count != limit) {
                    arg1->nodes[count] = node;
                    arg1->count = count + 1;
                }
            }
            node = node->next;
        } while (node != 0);
    }
}
