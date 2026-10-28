#include "sdk/LIBC.H"
#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/LLDIVRESULT.H"
#include "TYPES.H"
#include "sdk/EXTERNS.H"

/* sprintf: formats into a buffer through Libc_FormatToCallback with the copying output routine, terminates the text when the length is not negative, and returns the length. */
s32 func_802BD320_de(char *buffer, const char *format, ...) {
    s32 length = Libc_FormatToCallback(D_002BD378, buffer, format, __builtin_next_arg(format));

    if (length >= 0) {
        buffer[length] = 0;
    }
    return length;
}



/* _Printf output routine: copy a span and return the next output position. */
void *proutSprintf(void *arg0, const void *arg1, s32 arg2) {
    return (char *)func_802BD3A0_de(arg0, arg1, arg2) + arg2;
}

/** Copy a byte span and return its destination. */
void *func_802BD3A0_de(void *destination, const void *source, size_t count) {
    unsigned char *out = destination;
    const unsigned char *in = source;
    while (count != 0) {
        *out++ = *in++;
        --count;
    }
    return destination;
}

/** Find a byte in a zero-terminated string. */
char *func_802BD3C8_de(const char *string, int value) {
    const unsigned char *cursor = (const unsigned char *)string;
    unsigned char byte = (unsigned char)value;
    while (*cursor != byte) {
        if (*cursor == 0) {
            return 0;
        }
        ++cursor;
    }
    return (char *)cursor;
}

size_t func_802BD400_de(const char *string) {
    const unsigned char *cursor = (const unsigned char *)string;
    const unsigned char *terminator;
    terminator = cursor;
    if (*cursor != 0) {
        do {
            terminator += 1;
        } while (*terminator != 0);
    }
    return terminator - cursor;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_802BD354[3] = {
    0x0C000000, 0x0000086D, 0x5F546578,
};
#endif
