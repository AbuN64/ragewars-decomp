#include "include_asm.h"
#include "COMMON/GFX_INITIALIZEFRONTENDSERVICES.H"
#include "COMMON/FORMAT.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "TYPES.H"
#include "stdarg.h"
#include "MENU/GFX/GFX_FORMATARGUMENTLIST.H"

/* 80414330.CPP */
extern char g_debugNameNumberFormat[];
extern char g_debugUnnamedLabelText[];
extern s32 XStdio_FormatBuffer(char *, char *, ...);

s32 Gfx_FormatDiagnosticMessage(char *name, s32 number, char *format, ...) {
    va_list arguments;
    s32 length;

    if (format != 0) {
        va_start(arguments, format);
        if (name != 0) {
            length = XStdio_FormatBuffer(g_uiFormattedMessage, g_debugNameNumberFormat, name, number);
        } else {
            length = XStdio_FormatBuffer(g_uiFormattedMessage, g_debugNameNumberFormat, g_debugUnnamedLabelText, number);
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

/* 800E10F0.CPP */
#if !(defined(VERSION_US_REV1))
const char s_gfxDebugLocationFormat[13] =
    "[ %s : %d ]\012\000";
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/s_gfxDebugLocationFormatRev1.c */
const unsigned char k_DebugEncodedBytes[13] = {
    0x5B, 0x20, 0x25, 0x73, 0x20, 0x3A, 0x20, 0x25, 0x64, 0x20, 0x5D, 0x0A, 0x00,
};
#endif

/* 800E1100.CPP */
#if !(defined(VERSION_US_REV1))
const char s_gfxDebugUNKNOWNLabel[8] =
    "UNKNOWN\000";
#endif

#if defined(VERSION_EU_X)
unsigned int k_DebugEncodedWordsBlock1[4] = {
    0x0000001E, 0x00000001, 0x496E6600, 0x4E614E00,
};
#endif

#if defined(VERSION_EU)
unsigned int k_DebugEncodedWordsBlock2[4] = {
    0x0800FFD5, 0x0800FFD6, 0x496E6600, 0x4E614E00,
};
#endif

#if defined(VERSION_DE)
unsigned int k_DebugEncodedWords[4] = {
    0x00000000, 0x00000000, 0x496E6600, 0x4E614E00,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/s_gfxDebugUNKNOWNLabelRev1.c */
const char s_gfxDebugUNKNOWNLabelRev1[8] = "UNKNOWN";
#endif
