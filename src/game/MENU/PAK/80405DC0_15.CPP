#include "include_asm.h"
#include "RESMGR/resmgr_string_memory.H"
#include "COMMON/UNUSED.H"
#include "COMMON/ENTRYRECAT0V3.H"
#include "TYPES.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/SHARED_GAMESLOT.H"
extern char *D_800E25D4[];
extern char *D_800E25C4[];

s32 Pak_MatchesGameIdentity(char *code, char *name) {
    Shared_Game *settings;
    if (XPlus_StringLength((u8 *)name) == 4 && XPlus_StringLength((u8 *)code) == 2) {
        settings = &D_801462C8;
        if (XPlus_CompareStrings(name, D_800E25D4[settings->language]) == 0 &&
            XPlus_CompareStrings(code, D_800E25C4[settings->language]) == 0) {
            return 1;
        }
    }
    return 0;
}
#endif

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
/* Reports whether the two-character code arg0 and the four-character name arg1 are the pair D_800D36DC and D_800D36E0, measuring them with XPlus_StringLength and comparing them with XPlus_CompareStrings; returns one on a match and zero otherwise. */

extern char *D_800D36E0;

extern s32 XPlus_StringLength(u8 *);

s32 Pak_MatchesGameIdentity(char *code, char *name) {
    if (XPlus_StringLength((u8 *)name) == 4 && XPlus_StringLength((u8 *)code) == 2 &&
        XPlus_CompareStrings(name, D_800D36E0) == 0 && XPlus_CompareStrings(code, D_800D36DC) == 0) {
        return 1;
    }
    return 0;
}
#endif
