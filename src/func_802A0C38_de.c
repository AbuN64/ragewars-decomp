#include "span_1000/code_802A0AC4.h"
#include "types.h"

/* Formats its arguments into the shared buffer D_8014D0D0 and writes the text to the stream through func_802A0F50_de in runs, emitting the one-byte D_800CAEF0 before every newline, returning the number of bytes written. */

extern unsigned char D_8014D0D0;
extern char D_800CAEF0;
extern s32 func_80414CCC_de(unsigned char *buffer, const char *format, char *args);
extern void func_802A0F50_de(const unsigned char *data, s32 size, s32 count, void *stream);

s32 func_802A0C38_de(void *stream, const char *format, ...) {
    unsigned char *run;
    unsigned char *p;
    s32 length;
    s32 total;

    func_80414CCC_de(&D_8014D0D0, format, __builtin_next_arg(format));
    run = &D_8014D0D0;
    p = run;
    length = 0;
    total = 0;
    for (; *p != 0; p++, length++) {
        if (*p == '\n') {
            if (length > 0) {
                func_802A0F50_de(run, 1, length, stream);
                total += length;
                length = 0;
                run = p;
            }
            func_802A0F50_de(&D_800CAEF0, 1, 1, stream);
            total++;
        }
    }
    if (length > 0) {
        func_802A0F50_de(run, 1, length, stream);
        total += length;
    }
    return total;
}
