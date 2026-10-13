#include "shared/navigation_graph.h"
#include "span_1000/code_80208000.h"
#include "span_1000/code_80206258.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8020EAE0.h"
#include "types.h"

extern s32 D_8013B364;

extern void func_8020D014_de(void *arg0);
extern void func_8020D1FC_de(s32);
extern void *func_8020C994_de(void *, s32);
extern void func_8020D220_de(void *, s32);
extern void func_8020D0CC_de(void *arg0, s32 arg1);
extern void func_8020D114_de(void *arg0, void *arg1, s32 arg2);












s32 func_8020F444_de(void *arg0) {
    NavigationGraph *global;
    NavigationGraph *scanbase;
    NavigationSearchNode *node;
    NavigationPoint *result;
    s32 count;
    s32 type;
    s32 value;
    s32 current;

    global = (NavigationGraph *)&D_8013B364;
    func_8020D014_de(global);
    func_8020D1FC_de((s32)global);
    count = 0;
    node = D_801372C8;
    scanbase = global;
    if (node != 0) {
        type = 0x64E;
        do {
            result = func_8020C994_de(scanbase, node->key);
            if ((result->flags & 1) &&
                result->objectId == type &&
                ((ActorMotionState *)node->object->motion)->mode == 0) {
                func_8020D220_de(scanbase, node->key);
                count += 1;
            }
            node = node->next;
        } while (node != 0);
    }
    if (count == 0) {
        ((AiController *)arg0)->routeObject = 0;
        ((AiController *)arg0)->routeState = -1;
        return 1;
    }
    value = -1;
    global->result = value;
    func_8020D0CC_de(global, ((AiController *)arg0)->current);
    current = global->result;
    if (current != value) {
        ((AiController *)arg0)->mode = current;
        func_8020D114_de(global, &((AiController *)arg0)->queue, 4);
    }
    return 1;
}
