#include "span_16E000/code_8040C780.h"
#include "types.h"




void func_8040E928_de(void *object, int enabled) {
    u16 *flags = &((Widget_func_8040E67C_de *)(object))->flags;
    if (enabled) {
        *flags |= 0x40;
    } else {
        *flags &= 0xFFBF;
    }
}
