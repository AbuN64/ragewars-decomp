#include "include_asm.h"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/LONE/G_LANGUAGEINDEX.H"
#include "MENU/MENU_ACTION_TEXT_TABLES.H"
#include "MENU/PAK/PROFILE_PREVIEW_AND_LINE_TEXT.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "TYPES.H"
extern s8 g_pakPreviewNoteType;
extern char *g_localizedPakStatusHeading[];
extern char *g_pakStatusDefaultText[];
extern char *g_pakStatusStateOneText[];
extern char *g_pakStatusStateTwoText[];
extern char *g_pakStatusStateThreeText[];
extern char *g_pakStatusStateFourText[];
/* Pak status line: picks the 11-character status text for the state g_pakPreviewNoteType in the current language and copies it into
   the entry's line; with g_pakUseDefaultPreviewLabels set it only selects the heading table. */
s32 Menu_FormatLocalizedPakStatus(struct Field *entry) {
    char **table;
    char *src;
    char *dst;
    s32 i;

    if (g_pakUseDefaultPreviewLabels != 0) {
        entry->text = g_localizedPakStatusHeading;
        return 0;
    }
    entry->text = g_localizedPakStatusLines;
    switch (g_pakPreviewNoteType) {
    case 1: table = g_pakStatusStateOneText; break;
    case 2: table = g_pakStatusStateTwoText; break;
    case 3: table = g_pakStatusStateThreeText; break;
    case 4: table = g_pakStatusStateFourText; break;
    default: table = g_pakStatusDefaultText; break;
    }
    src = table[g_languageIndex];
    dst = entry->text[g_languageIndex];
    dst += Menu_CountLineChars(entry) - 11;
    for (i = 0; i < 11; i++) {
        *dst++ = *src++;
    }
    return 0;
}
#else
INCLUDE_ASM("ovl_frontendMenu", Menu_FormatLocalizedPakStatus);
#endif
#endif

#if defined(VERSION_EU_X)
const unsigned int g_noteTypeLabelJumpTableEuropean[15] = {
    0x0040ACC8, 0x0040ACC8, 0x0040AD28, 0x0040AD08, 0x0040ACC8, 0x0040ACE8, 0x0040ACC8, 0x0040ACC8,
    0x0040ACC8, 0x0040ACC8, 0x0040ACC8, 0x0040ACC8, 0x0040ACC8, 0x0040ACC8, 0x0040AD48,
};
#endif
