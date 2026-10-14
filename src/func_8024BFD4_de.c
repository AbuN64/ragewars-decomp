#include "span_1000/code_8024BA6C.h"
#include "common/types_1dc8418c21db.h"
/* Phase1 source candidate; contract holds and immutable inputs in per-function JSON. */
#include "span_1000/code_80245980.h"
#include "types.h"














extern void * *func_8025193C_de(s32, s32, s32, s32, s32, s32, void *, void *, s32);
extern s32 func_8028FE3C_de(s32, s32, s32, s32 *);
extern void func_80253754_de(s32, void *);

extern char D_0026D814;
extern char D_800C3B28;
extern char D_800C3B3C;




void **func_8024BFD4_de(MenuPanelRoot *arg0, s32 arg1) {
    void **resource;

    if (arg1 < 0) {
        return 0;
    }
    if (arg1 != arg0->selected) {
        resource = func_8025193C_de(0, arg0->resource,
                                 arg0->resource, arg0->resourceSize,
                                 0, 0, 0, &D_800C3B28, 1);
        if (resource != 0) {
            arg0->selectedResource = func_8028FE3C_de((s32)*resource,
                                                arg0->resource,
                                                arg1 % *(s32 *)*resource,
                                                &arg0->window);
            arg0->selected = arg1;
            func_80253754_de(0, resource);
        }
    }
    if (arg0->selectedResource != 0) {
        return func_8025193C_de(0, arg0->selectedResource,
                             arg0->selectedResource, arg0->window,
                             0, 0, &D_0026D814, &D_800C3B3C, 0);
    }
    return 0;
}

