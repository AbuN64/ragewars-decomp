#include "span_1000/code_802636D0.h"
#include "types.h"

extern u8 D_8010FBE3[];

s32 func_80264690_de(void) {
    s32 count;
    s32 i;

    count = 0;
    i = 0;
    do {
        if (((D_8010FBE3[i * 4] >> 3) ^ 1) & 1) {
            count += 1;
        }
        i += 1;
    } while (i < 4);
    return count;
}
