#include "span_1000/code_80297CD0.h"
#include "types.h"


s32 func_802998E0_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    Element *element = arg0;
    MenuElementHandler handler;

    handler = func_802997E4_de(element->kind);
    if (handler != 0) {
        return handler(arg0, arg1, arg2, arg3, arg4);
    }
    return 0;
}
