#include "span_1000/code_8029F3A8.h"
#include "types.h"

/* Copies n bytes between possibly overlapping buffers and returns the destination: forwards when the destination is below the source and backwards otherwise, aligning to a word boundary with single bytes when both pointers share alignment, then copying whole words and the remaining bytes. */

char *func_802A0470(char *dst, char *src, s32 n) {
    char *d;
    s32 count;

    d = dst;
    if (n == 0 || dst == src) {
        return dst;
    }
    if (dst < src) {
        count = (s32)src;
        if ((count | (s32)dst) & 3) {
            if ((count ^ (s32)dst) & 3) {
                count = n;
            } else if (n < 4) {
                count = n;
            } else {
                count = 4 - (count & 3);
            }
            n -= count;
            do {
                *d++ = *src++;
            } while (--count != 0);
        }
        count = (u32)n >> 2;
        if (count != 0) {
            do {
                *(s32 *)d = *(s32 *)src;
                src += 4;
                d += 4;
            } while (--count != 0);
        }
        count = n & 3;
        if (count != 0) {
            do {
                *d++ = *src++;
            } while (--count != 0);
        }
    } else {
        src += n;
        d = dst + n;
        count = (s32)src;
        if ((count | (s32)d) & 3) {
            if ((count ^ (s32)d) & 3) {
                count = n;
            } else if (n < 5) {
                count = n;
            } else {
                count &= 3;
            }
            n -= count;
            do {
                *--d = *--src;
            } while (--count != 0);
        }
        count = (u32)n >> 2;
        if (count != 0) {
            do {
                src -= 4;
                d -= 4;
                *(s32 *)d = *(s32 *)src;
            } while (--count != 0);
        }
        count = n & 3;
        if (count != 0) {
            do {
                *--d = *--src;
            } while (--count != 0);
        }
    }
    return dst;
}
