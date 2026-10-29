#include "include_asm.h"
#include "COMMON/LONE/G_LANGUAGEINDEX.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "TYPES.H"
typedef struct { u8 pad0[0x14]; char **text; } PakRangeTextEu;
extern u16 g_pakProfileRankScore;
extern char *g_pakSizeUnder50Text[];
extern char *g_pakSizeUnder150Text[];
extern char *g_pakSizeUnder300Text[];
extern char *g_pakSizeUnder500Text[];
extern char *g_pakSizeUnder800Text[];
extern char *g_pakSizeUnder1300Text[];
extern char *g_pakSizeUnder2000Text[];
extern char *g_pakSizeUnder3000Text[];
extern char *g_pakSizeUnder4500Text[];
extern char *g_pakSizeUnder6500Text[];
extern char *g_pakSizeUnder9999Text[];
extern char *g_pakSizeAtLeast9999Text[];
extern s32 Menu_CountLineChars();
/* Pak size line: picks the 11-character text for the value range g_pakProfileRankScore falls in (the bands end at 0x32, 0x96, 0x12C, 0x1F4,
   0x320, 0x514, 0x7D0, 0xBB8, 0x1194, 0x1964, 0x270F) in the current language and copies it onto the entry's line. */
s32 Menu_FormatLocalizedPakSizeRange(PakRangeTextEu *entry) {
    u32 v = g_pakProfileRankScore;
    char *src = 0;
    char *dst;
    s32 i;

    if (v < 0x32) src = g_pakSizeUnder50Text[g_languageIndex];
    else if (v - 0x32 < 0x64) src = g_pakSizeUnder150Text[g_languageIndex];
    else if (v - 0x96 < 0x96) src = g_pakSizeUnder300Text[g_languageIndex];
    else if (v - 0x12C < 0xC8) src = g_pakSizeUnder500Text[g_languageIndex];
    else if (v - 0x1F4 < 0x12C) src = g_pakSizeUnder800Text[g_languageIndex];
    else if (v - 0x320 < 0x1F4) src = g_pakSizeUnder1300Text[g_languageIndex];
    else if (v - 0x514 < 0x2BC) src = g_pakSizeUnder2000Text[g_languageIndex];
    else if (v - 0x7D0 < 0x3E8) src = g_pakSizeUnder3000Text[g_languageIndex];
    else if (v - 0xBB8 < 0x5DC) src = g_pakSizeUnder4500Text[g_languageIndex];
    else if (v - 0x1194 < 0x7D0) src = g_pakSizeUnder6500Text[g_languageIndex];
    else if (v - 0x1964 < 0xDAB) src = g_pakSizeUnder9999Text[g_languageIndex];
    else if (v >= 0x270F) src = g_pakSizeAtLeast9999Text[g_languageIndex];
    dst = entry->text[g_languageIndex];
    dst += Menu_CountLineChars(entry) - 11;
    if (src != 0) {
        for (i = 0; i < 11; i++) {
            *dst++ = *src++;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("ovl_frontendMenu", Menu_FormatLocalizedPakSizeRange);
#endif
#endif
