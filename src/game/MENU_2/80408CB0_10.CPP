#include "include_asm.h"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
/* Drafted from the other version's body in its unit. */
#else
INCLUDE_ASM("ovl_80400000", func_8040AB70_eu);
#endif
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "TYPES.H"
typedef struct { u8 pad0[0x14]; char **text; } PakTextEu;
extern s32 D_80153774;
extern u8 D_80152789;
extern s8 D_8014D490;
extern char *D_800E2994[], *D_800E29B4[];
extern char *D_800E3234[], *D_800E3244[], *D_800E3294[], *D_800E32B4_eu[], *D_800E32C4_eu[];
extern s32 func_80441FE8_de(void *);
/* Pak status line: picks the 11-character status text for the state D_8014D490 in the current language and copies it into
   the entry's line; with D_80153774 set it only selects the heading table. */
s32 func_8040AC68_eu(PakTextEu *entry) {
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
    src = table[D_80152789];
    dst = entry->text[D_80152789];
    dst += func_80441FE8_de(entry) - 11;
    for (i = 0; i < 11; i++) {
        *dst++ = *src++;
    }
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_8040AC68_eu);
#endif
#endif
