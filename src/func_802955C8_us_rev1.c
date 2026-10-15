#include "span_1000/code_80294C64.h"
/** Report the global count only while its enable byte is set. */
extern unsigned char D_8014AEB0;
extern unsigned int D_800D2AE0;

int func_802955C8_us_rev1(void) {
    int result = 0;
    if (D_8014AEB0 != 0) {
        result = D_800D2AE0 != 0;
    }
    return result;
}
