#include "shared/func_80206724_de_closed.h"
#include "span_1000/code_80203F04.h"
#include "shared/func_80204C34_de_closed.h"

void func_80204C34_de(void *arg0, void *arg1) {
    Shared_CallbackHook *obj = ((Shared_CallbackOwner *)arg1)->hook;
    if (obj != 0) {
        Shared_VoidCallback fn = obj->callback;
        if (fn != 0) {
            fn();
        }
    }
}
