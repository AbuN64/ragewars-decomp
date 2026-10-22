#include "include_asm.h"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
extern char *D_800E3B64[];
/* Copies the eight-byte name from the language table entry D_800E3B64[language] into the record at 0x84. Only the default
   case of the original switch on the byte at 0x7F lives in this symbol (its jump table has cases 0..7); the others sit in the
   following unsplit code, so the draft applies the default copy to every value. */
void func_80444F30_eu(u8 *record) {
    s32 i;
    char *table = D_800E3B64[D_801462C8.language];

    for (i = 0; i < 8; i++) {
        record[0x84 + i] = table[i];
    }
}
#else
INCLUDE_ASM("ovl_80400000", func_80444F30_eu);
#endif
#endif

#if defined(VERSION_EU)
unsigned char D_auto_func_80444F9C_eu_padding_1BAF9C[4] = { 0x00, 0x00, 0x28, 0x21 };
#endif
