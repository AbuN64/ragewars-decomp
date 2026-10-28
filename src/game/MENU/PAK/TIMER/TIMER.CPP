#include "include_asm.h"
#include "RESMGR/resmgr_string_memory.H"
#include "COMMON/UNUSED.H"
#include "COMMON/ENTRYRECAT0V3.H"
#include "TYPES.H"
#include "COMMON/MENURECAT24.H"
#include "MENU/PAK/SAVE_SNAPSHOT.H"
#include "MENU/80405DC0.H"
#include "COMMON/SHAREDPLAYER.H"
#include "stddef.h"
#include "MENU/PAK/80405DC0_16.H"
#include "RESMGR/802A0888.H"

/* 80405DC0_15.CPP */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/SHARED_GAMESLOT.H"
extern char *D_800E25D4[];
extern char *D_800E25C4[];

s32 Timer_MatchesGameIdentity(char *code, char *name) {
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

s32 Timer_MatchesGameIdentity(char *code, char *name) {
    if (XPlus_StringLength((u8 *)name) == 4 && XPlus_StringLength((u8 *)code) == 2 &&
        XPlus_CompareStrings(name, D_800D36E0) == 0 && XPlus_CompareStrings(code, D_800D36DC) == 0) {
        return 1;
    }
    return 0;
}
#endif

/* 80405DC0_16.CPP */
extern void Cache_ReleaseResource(void *arg0, void *arg1);

/* Returns the address of block n, n times 256; block zero is the area 0x610 bytes into the
   buffer D_8011FECC points to. */
extern char *D_8011FECC;

extern void Cache_DrainAndCompactResources(s32 a);

extern void **Cache_AllocateResource(s32, s32, s32, char *);

/* Releases the two active resources and clears their associated state. */

 /* extern */

 /* extern */

extern s32 D_800E28BC;

/* Saves the settings the object at offset 0x5D8 of an owner holds into the block D_80153738: the
   flag byte, the four halfwords, three cleared bytes after the flag and the eight bytes at 0x84. */

extern struct Saved D_80153738;

char *Timer_GetSaveBlockByteCount(s32 block) {
    if (block == 0) {
        return D_8011FECC + 0x610;
    }
    return (char *) (block << 8);
}

void Timer_SetSaveTrailerValue(s32 offset, s32 value) {
    ((struct IntegerState610 *) (D_8011FECC + offset))->unk_60C = value;
}

/* Returns the last word of a self-sized block: the first word holds the block's byte length and
   the result is the word just before that many bytes from the start. */
s32 Timer_GetSaveTrailerValue(s32 *block) {
    return ((struct Shape_typemap_3 *) (block[0] + (s32) block))[-1].field_0;
}

void Timer_AllocateSaveBlock(void ***handle, void **data, s32 units) {
    void **block;
    void *first;

    if (*handle != 0) {
        Cache_DrainAndCompactResources(0);
        Cache_ReleaseResource(0, *handle);
    }
    if (units != 0) {
        units <<= 8;
    } else {
        units = (s32)(D_8011FECC + 0x610);
    }
    block = Cache_AllocateResource(0, units, 0x33, g_pakSingleSaveBlockName);
    *handle = block;
    first = *block;
    *data = first;
    XPlus_FillMemory(first, 0, units);
}

void Timer_ReleaseSaveBlocks(void) {
    if ((D_800DE860_de != 0) || (D_800DE864_de != 0)) {
        Cache_DrainAndCompactResources(0);
    }
    if (D_800DE860_de != 0) {
        Cache_ReleaseResource(0, D_800DE860_de);
    }
    if (D_800DE864_de != 0) {
        Cache_ReleaseResource(0, D_800DE864_de);
    }
    D_800DE860_de = 0;
    D_800DE864_de = 0;
    D_800DE868 = 0;
    D_800E28BC = 0;
}

void Timer_CapturePlayerProfile(struct OwnerRecAt5D8V1 *owner) {
    struct ProfileRecAt84 *settings = owner->settings;
    s32 i;

    D_80153738.flag = settings->flags;
    D_80153738.values[0] = settings->words[0];
    D_80153738.values[1] = settings->words[1];
    D_80153738.values[2] = settings->words[2];
    D_80153738.values[3] = settings->words[3];
    D_80153738.pad[0] = 0;
    D_80153738.pad[1] = 0;
    D_80153738.pad[2] = 0;
    for (i = 0; i < 8; i++) {
        D_80153738.bytes[i] = settings->name[i];
    }
}
