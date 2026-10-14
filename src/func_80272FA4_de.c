#include "span_1000/code_80271B18.h"
#include "types.h"

/** Trivial busy-wait delay loop (no side effects). */
void func_80272FA4_de(void) {
    s32 count;

    count = 3;
    do {
        count -= 1;
    } while (count >= 0);
}
