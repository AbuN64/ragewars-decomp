#include "include_asm.h"
#include "COMMON/EXTERNS_4.H"
#include "COMMON/FORMAT.H"
#include "COMMON/UNUSED.H"

#include "TYPES.H"
#include "stdarg.h"
#include "MENU/GFX/80414480_3.H"
extern char D_800DD0C0[];
extern char D_800DD0D0_de[];
extern s32 XStdio_FormatBuffer(char *, char *, ...);

s32 Gfx_FormatDiagnosticMessage(char *name, s32 number, char *format, ...) {
    va_list arguments;
    s32 length;

    if (format != 0) {
        va_start(arguments, format);
        if (name != 0) {
            length = XStdio_FormatBuffer(D_80153D60, D_800DD0C0, name, number);
        } else {
            length = XStdio_FormatBuffer(D_80153D60, D_800DD0C0, D_800DD0D0_de, number);
        }
        Gfx_FormatArgumentList(D_80153D60 + length, format, arguments);
        va_end(arguments);
    }
    return 1;
}

/* Returns the address of the table D_80153D60. */

char *Gfx_GetDiagnosticMessage(void) {
    return D_80153D60;
}
