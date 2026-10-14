#include "span_16E000/code_804290E8.h"
#include "types.h"

/* Calls func_80429654_de with 1 when the fourth argument is zero, and returns zero;
   func_8042994C_de and func_80429970_de are the same function. */
extern void func_80429654_de(s32);

s32 func_8042994C_de(void *first, void *second, void *third, s32 fourth) {
    if (fourth == 0) {
        func_80429654_de(1);
        return 0;
    }
    return 0;
}
