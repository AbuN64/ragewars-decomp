#include "span_16E000/code_8043E9A8.h"
#include "types.h"

/* Calls func_804427C4_de with the third argument, the second argument and the resource D_451AF0,
   and returns one. */
extern char D_00450E9C[];
extern void func_804427C4_de(void *, void *, void *);

s32 func_8043EC40_de(void *first, void *second, void *third) {
    func_804427C4_de(third, second, D_00450E9C);
    return 1;
}
