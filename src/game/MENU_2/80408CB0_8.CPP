#include "include_asm.h"
#include "COMMON/LONE/D_80152789.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "TYPES.H"
typedef struct { u8 pad0[0x14]; char **text; } PakRangeTextEu;
extern u16 D_8014D48C;
extern char *D_800E2814_eu[], *D_800E2824_eu[], *D_800E2834[], *D_800E2844_eu[], *D_800E2854_eu[], *D_800E2864[], *D_800E2874[],
    *D_800E2884[], *D_800E2894[], *D_800E28A4_eu[], *D_800E28B4_eu[], *D_800E28C4_eu[];
extern s32 Pak_CountLineChars();
/* Pak size line: picks the 11-character text for the value range D_8014D48C falls in (the bands end at 0x32, 0x96, 0x12C, 0x1F4,
   0x320, 0x514, 0x7D0, 0xBB8, 0x1194, 0x1964, 0x270F) in the current language and copies it onto the entry's line. */
s32 Menu_FormatLocalizedPakSizeRange(PakRangeTextEu *entry) {
    u32 v = D_8014D48C;
    char *src = 0;
    char *dst;
    s32 i;

    if (v < 0x32) src = D_800E2814_eu[g_languageIndex];
    else if (v - 0x32 < 0x64) src = D_800E2824_eu[g_languageIndex];
    else if (v - 0x96 < 0x96) src = D_800E2834[g_languageIndex];
    else if (v - 0x12C < 0xC8) src = D_800E2844_eu[g_languageIndex];
    else if (v - 0x1F4 < 0x12C) src = D_800E2854_eu[g_languageIndex];
    else if (v - 0x320 < 0x1F4) src = D_800E2864[g_languageIndex];
    else if (v - 0x514 < 0x2BC) src = D_800E2874[g_languageIndex];
    else if (v - 0x7D0 < 0x3E8) src = D_800E2884[g_languageIndex];
    else if (v - 0xBB8 < 0x5DC) src = D_800E2894[g_languageIndex];
    else if (v - 0x1194 < 0x7D0) src = D_800E28A4_eu[g_languageIndex];
    else if (v - 0x1964 < 0xDAB) src = D_800E28B4_eu[g_languageIndex];
    else if (v >= 0x270F) src = D_800E28C4_eu[g_languageIndex];
    dst = entry->text[g_languageIndex];
    dst += Pak_CountLineChars(entry) - 11;
    if (src != 0) {
        for (i = 0; i < 11; i++) {
            *dst++ = *src++;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", Menu_FormatLocalizedPakSizeRange);
#endif
#endif
