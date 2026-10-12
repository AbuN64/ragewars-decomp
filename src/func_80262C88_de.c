#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802624A0.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"

extern void func_80255ED8_de(void *, void *);





s32 func_80262C88_de(struct Effect_func_80262A9C_de *arg0) {
    s32 *counter;

    counter = arg0->ref;
    arg0->active = 0;
    if (counter != 0) {
        *counter -= 1;
    }
    func_80255ED8_de(&D_80137064, arg0);
    return func_80255D14_de(&D_80137050, arg0);
}
