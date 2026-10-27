#include "include_asm.h"
#include "COMMON/LONE/D_80152789.H"
#include "MENU/80408CB0_10.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "TYPES.H"
typedef struct { u8 pad0[0x14]; char **text; } PakTextEu;
extern s32 D_80153774;
extern s32 Pak_CountLineChars(void *);
extern char D_8014B49B[];
extern char D_800D2478[];
extern char D_8014B494[];
/* Select the status text and right-align its nonblank characters (the us body with eu addresses; the eu symbol of the
   pointer table is D_8014B49B, of the last status character D_800D2478, of the status characters D_8014B494). */
s32 Menu_FormatLocalizedPakName(PakTextEu *entry) {
    s32 count = 8;
    u8 *scan;
    char *dst;
    s32 i;

    if (D_80153774 != 0) {
        entry->text = (char **)D_800E2984_eu;
        return 0;
    }
    entry->text = (char **)D_8014B49B;
    scan = (u8 *)D_800D2478;
    while (*scan-- == 0x20 && count != 0) count--;
    dst = entry->text[g_languageIndex];
    dst += Pak_CountLineChars(entry) - 8;
    for (i = 7; i >= 0; i--) dst[i] = 0x20;
    dst += 8 - count;
    for (i = 0; i < count; i++) *dst++ = D_8014B494[i];
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", Menu_FormatLocalizedPakName);
#endif
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "TYPES.H"
extern s8 D_8014D490;
extern char *D_800E2994[];
extern char *D_800E3234[];
extern char *D_800E3244[];
extern char *D_800E3294[];
extern char *D_800E32B4_eu[];
extern char *D_800E32C4_eu[];
/* Pak status line: picks the 11-character status text for the state D_8014D490 in the current language and copies it into
   the entry's line; with D_80153774 set it only selects the heading table. */
s32 Menu_FormatLocalizedPakStatus(PakTextEu *entry) {
    char **table;
    char *src;
    char *dst;
    s32 i;

    if (D_80153774 != 0) {
        entry->text = D_800E2994;
        return 0;
    }
    entry->text = D_800E29B4;
    switch (D_8014D490) {
    case 1: table = D_800E3244; break;
    case 2: table = D_800E3294; break;
    case 3: table = D_800E32B4_eu; break;
    case 4: table = D_800E32C4_eu; break;
    default: table = D_800E3234; break;
    }
    src = table[g_languageIndex];
    dst = entry->text[g_languageIndex];
    dst += Pak_CountLineChars(entry) - 11;
    for (i = 0; i < 11; i++) {
        *dst++ = *src++;
    }
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", Menu_FormatLocalizedPakStatus);
#endif
#endif

#if defined(VERSION_EU_X)
const unsigned int D_auto_rodata_func_8040AC68_eu_800E8618[15] = {
    0x0040ACC8, 0x0040ACC8, 0x0040AD28, 0x0040AD08, 0x0040ACC8, 0x0040ACE8, 0x0040ACC8, 0x0040ACC8,
    0x0040ACC8, 0x0040ACC8, 0x0040ACC8, 0x0040ACC8, 0x0040ACC8, 0x0040ACC8, 0x0040AD48,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800E8654[1] = {
    0x00000000,
};
#endif
