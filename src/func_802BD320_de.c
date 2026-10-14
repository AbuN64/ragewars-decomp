#include "common/unused.h"
#include "span_1000/code_802BD1A8.h"
#include "types.h"

extern s32 func_802BD430_de(void *(*)(void *, const char *, s32), void *, const char *, char *);
/* sprintf: formats into a buffer through func_802BD430_de with the copying output routine, terminates the text when the length is not negative, and returns the length. */
s32 func_802BD320_de(char *buffer, const char *format, ...) {
    s32 length = func_802BD430_de(D_002BD378, buffer, format, __builtin_next_arg(format));

    if (length >= 0) {
        buffer[length] = 0;
    }
    return length;
}

s32 func_802BD378_de(void *arg0, void *arg1, s32 arg2) {
    return func_802BD3A0_de(arg0, arg1, arg2) + arg2;
}

/** Copy a byte span and return its destination. */
void *func_802BD3A0_de(void *destination, const void *source, int count) {
    unsigned char *out = destination;
    const unsigned char *in = source;
    while (count != 0) {
        *out++ = *in++;
        --count;
    }
    return destination;
}

/** Find a byte in a zero-terminated string. */
unsigned char *func_802BD3C8_de(unsigned char *string, unsigned char value) {
    while (*string != value) {
        if (*string == 0) {
            return 0;
        }
        ++string;
    }
    return string;
}

s32 func_802BD400_de(u8 *arg0) {
    u8 *var_v1;
    var_v1 = arg0;
    if (*arg0 != 0) {
        do {
            var_v1 += 1;
        } while (*var_v1 != 0);
    }
    return var_v1 - arg0;
}
