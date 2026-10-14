#include "span_1000/code_80297CD0.h"
#include "types.h"
extern ScreenManager *D_8014D080;
s16 func_80299A08_de(void) {
    Element *ptr;
    ptr = D_8014D080->screens[D_8014D080->current].focus;
    if (ptr != 0) {
        return ptr->id;
    }
    return -1;
}
