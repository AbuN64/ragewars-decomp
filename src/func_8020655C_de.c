#include "span_1000/code_80204E78.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80206258.h"
#include "types.h"


extern char D_80145040;
extern void *func_8022A8F0_de(void *arg0);




s32 func_8020655C_de(s32 arg0) {
    SpawnDispatchActor *node;

    if (arg0 == 0x84F) {
        node = D_80137064.head;
        while (node != 0) {
            if (*node->definition == 4) {
                return 0;
            }
            node = node->next;
        }
        return func_8022A8F0_de(&D_80145040) == 0;
    }
    return 1;
}
