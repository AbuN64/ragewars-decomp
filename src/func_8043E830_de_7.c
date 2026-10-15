#include "span_16E000/code_8043E9A8.h"
#include "types.h"

/* Calls func_804427C4_de with the third argument, the second argument and the resource D_4503E8,
   and returns one. */
extern char D_0044F798[];
extern void func_804427C4_de(void *, void *, void *);

s32 func_8043EC98_de(void *first, void *second, void *third) {
    func_804427C4_de(third, second, D_0044F798);
    return 1;
}
