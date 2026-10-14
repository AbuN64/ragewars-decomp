#include "span_16E000/code_8043962C.h"
#include "types.h"

/* On event 3 with value 0xD, calls func_8029973C_de and func_80298368_de with 3. Returns zero. */
extern void func_8029973C_de();
extern void func_80298368_de(s32);

s32 func_804396F0_de(void *first, void *second, u32 event, s32 value) {
    if ((event >> 16) == 3) {
        if (value != 0xD) {
            return 0;
        }
        func_8029973C_de();
        func_80298368_de(3);
    }
    return 0;
}
