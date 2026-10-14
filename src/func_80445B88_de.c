#include "span_16E000/code_804453C4.h"
#include "types.h"

/* Compares two strings byte by byte and returns whether the last pair compared is equal. It stops
   at the first difference or terminator, and keeps going only while the count, decremented once
   per byte, is exactly zero, so a count of one compares a single byte. */
s32 func_80445B88_de(u8 *a, u8 *b, s32 count) {
    u8 c;
    u8 d;

    do {
        c = *a++;
        d = *b++;
        count--;
    } while (c == d && c != 0 && count == 0);
    return c == d;
}
