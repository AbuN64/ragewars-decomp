#include "span_16E000/code_8041B020.h"
/* Releases the supplied object through func_802547E4_de and returns zero. */
extern void func_802547E4_de(void *object);

int func_8041B5BC_de(void *object)
{
    func_802547E4_de(object);
    return 0;
}
