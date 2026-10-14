#include "span_1000/code_802646F4.h"
#include "types.h"

extern unsigned char D_8010B308[];

s32 func_80264728_de(void) {
    s32 i = 0;
    while (1) {
        if (D_8010B308[i] == 0) {
            i += 1;
            if (i >= 4) {
                return 0;
            }
        } else {
            return 1;
        }
    }
}
