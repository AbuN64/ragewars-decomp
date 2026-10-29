#include "include_asm.h"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
extern char *g_playerPartnerSuffixByLanguage[];
/* Copies the eight-byte name from the language table entry g_playerPartnerSuffixByLanguage[language] into the record at 0x84. Only the default
   case of the original switch on the byte at 0x7F lives in this symbol (its jump table has cases 0..7); the others sit in the
   following unsplit code, so the draft applies the default copy to every value. */
void Items_CopyDefaultLocalizedPlayerName(u8 *record) {
    s32 i;
    char *table = g_playerPartnerSuffixByLanguage[g_gameSettings.language];

    for (i = 0; i < 8; i++) {
        record[0x84 + i] = table[i];
    }
}
#else
INCLUDE_ASM("ovl_80400000", Items_CopyDefaultLocalizedPlayerName);
#endif
#endif

#if defined(VERSION_EU)
unsigned char g_ItemsCopydefaultlocalizedplayernameTrailingBytesBlock1[4] = { 0x00, 0x00, 0x28, 0x21 };
#endif
