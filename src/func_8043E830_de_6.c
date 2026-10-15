#include "span_16E000/code_8043E9A8.h"
#include "types.h"

/* Calls func_804427C4_de with the third argument, the second argument and the resource D_4500F4,
   and returns one. */
extern char D_0044F4A4[];
extern void func_804427C4_de(void *, void *, void *);

s32 func_8043EC6C_de(void *first, void *second, void *third) {
    func_804427C4_de(third, second, D_0044F4A4);
    return 1;
}
