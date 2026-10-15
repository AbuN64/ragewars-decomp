#include "span_16E000/code_8043E9A8.h"
#include "types.h"

/* Calls func_804427C4_de with the third argument, the second argument and the resource D_450C18,
   and returns one. */
extern char D_0044FFEC[];
extern void func_804427C4_de(void *, void *, void *);

s32 func_8043ED78_de(void *first, void *second, void *third) {
    func_804427C4_de(third, second, D_0044FFEC);
    return 1;
}
