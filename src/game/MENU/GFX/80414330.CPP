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
            length = XStdio_FormatBuffer(g_uiFormattedMessage, D_800DD0C0, name, number);
        } else {
            length = XStdio_FormatBuffer(g_uiFormattedMessage, D_800DD0C0, D_800DD0D0_de, number);
        }
        Gfx_FormatArgumentList(g_uiFormattedMessage + length, format, arguments);
        va_end(arguments);
    }
    return 1;
}

/* Returns the address of the table g_uiFormattedMessage. */

char *Gfx_GetDiagnosticMessage(void) {
    return g_uiFormattedMessage;
}
