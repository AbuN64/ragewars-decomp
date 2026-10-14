#include "span_16E000/code_80434F4C.h"
#include "types.h"
/* Reads two values and reports whether the first reaches the rounded object size when the second is nonzero. */

extern s32 func_80405160_de(void *a0, s32 *a1);
extern s32 func_804050CC_de(void *a0, s32 *a1);

extern s32 func_804057EC_de(s32 a0);

s32 func_80435384_de(void *arg0, s32 *out)
{
    s32 a, b;
    s32 ret;
    s32 val;

    *out = 0;

    ret = func_80405160_de(arg0, &a);
    if (ret == 0) {
        ret = func_804050CC_de(arg0, &b);
        if (ret == 0) {
            val = func_804057EC_de(func_80435424_de());
            if (b == 0) {
                *out = 0;
            } else if (a < val) {
                *out = 0;
            } else {
                *out = 1;
            }
        }
    }

    return ret;
}
