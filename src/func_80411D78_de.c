#include "span_16E000/code_80411B68.h"
#include "types.h"

/* The debugger showed this global holding 0x80698160, a heap address rather than a static one,
   so it is a pointer variable and not an array base. The returned words were 0x8069A52F and
   0x8069A673, which are guest addresses that are not word aligned, so the element type is a
   pointer to bytes. */
extern char **D_8014D9AC;

char *func_80411D78_de(s32 index) {
    return D_8014D9AC[index];
}
