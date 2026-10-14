#include "shared/world.h"
#include "span_1000/code_80204E78.h"
#include "types.h"








extern s32 func_80285F58_de(void *, void *);


void func_80206018_de(void *arg0, EventRecAt30 *arg1) {
    CallbackHolder *holder;
    s32 different;

    different = func_80285F58_de(&D_8011FE88, arg0) != 1;
    if (different == 0) {
        holder = arg1->holder;
        if ((holder != 0) && (holder->callback != 0)) {
            holder->callback(arg0, arg1);
        }
    }
}
