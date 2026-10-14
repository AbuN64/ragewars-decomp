#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8029EB74.h"


void func_8029EA44_de(void *arg0, void *arg1) {
    char *dst = (char *)arg0;
    char *src = (char *)arg1;
    char *end = src + 0x40;
    do {
        *(struct Shape_typemap_165 *)dst = *(struct Shape_typemap_165 *)src;
        src += 0x10;
        dst += 0x10;
    } while (src != end);
}
