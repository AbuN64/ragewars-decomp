#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8020EAE0.h"
#include "types.h"
#include "common/unused.h"
#include "span_1000/code_8020AF9C.h"
/* Selects the nodes of D_8013B364's list whose flagged record matches one of thirty ids: every match
   whose owner at 0x34 is active at 0x294 is selected through func_8020D220_de, and when none was, every
   matching node is selected regardless of owner. Returns the number of selections. Written from its
   own assembly in the style of func_8020EEA4_de. */



extern s32 D_8013B364;
extern void *func_8020C994_de(s32 *, s32);
extern void func_8020D220_de(s32 *, s32);







s32 func_8020F150_de(s32 *ids) {
    s32 *base;
    Node_func_8020F150_de *node;
    void *record;
    s32 count;
    s32 i;

    base = &D_8013B364;
    count = 0;
    for (node = (Node_func_8020F150_de *)((Obj8020BC50 *)base)->nodes; node != 0; node = node->next) {
        record = func_8020C994_de(base, node->id);
        if (((NavigationNode *)record)->flags & 1) {
            for (i = 0; i < 30; i++) {
                if (((NavigationNode *)record)->reservedE == ids[i] && node->owner != 0
                    && ((Owner8020F150 *)node->owner)->active != 0) {
                    func_8020D220_de(base, node->id);
                    count++;
                }
            }
        }
    }
    if (count == 0) {
        for (node = (Node_func_8020F150_de *)((Obj8020BC50 *)base)->nodes; node != 0; node = node->next) {
            record = func_8020C994_de(base, node->id);
            if (((NavigationNode *)record)->flags & 1) {
                for (i = 0; i < 30; i++) {
                    if (((NavigationNode *)record)->reservedE == ids[i]) {
                        func_8020D220_de(base, node->id);
                        count++;
                    }
                }
            }
        }
    }
    return count;
}
