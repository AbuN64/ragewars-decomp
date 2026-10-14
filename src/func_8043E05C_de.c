#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8043DF84.h"
#include "types.h"
#include "stddef.h"
/* Finds the first of the four slots in D_8010F328 that func_8026437C_de accepts, writing its index to out and returning it, or writing -1 and returning NULL when none does. */
extern ControllerProfile D_8010F328[4];
extern s32 func_8026437C_de(ControllerProfile *slot);
ControllerProfile *func_8043E05C_de(s32 *out) {
    s32 i;
    ControllerProfile *s;
    i = 0;
    s = D_8010F328;
    while (i < 4) {
        if (func_8026437C_de(s) != 0) {
            *out = i;
            return s;
        }
        i++;
        s++;
    }
    *out = -1;
    return 0;
}
