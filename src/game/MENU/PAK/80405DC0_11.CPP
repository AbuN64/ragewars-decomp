#include "include_asm.h"
#include "RESMGR/resmgr_string_memory.H"
#include "COMMON/LONE/D_80152789.H"
#include "COMMON/MENURECAT24.H"
#include "MENU/80405DC0.H"
#include "COMMON/UNUSED.H"
#include "COMMON/PAK_MENU.H"
#include "TYPES.H"
#include "MENU/PAK/80405DC0_11.H"
#include "SYSTEM_3/80265370.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
/* Drafted below with the other versions' body. */
#else
INCLUDE_ASM("ovl_80400000", func_80407F6C_de);
#endif
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
/* Drafted below with the other versions' body. */
#else
INCLUDE_ASM("ovl_80400000", func_80408118_de);
#endif
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
/* Drafted below with the other versions' body. */
#else
INCLUDE_ASM("ovl_80400000", func_804082FC_de);
#endif
#endif

#if !(defined(VERSION_EU) || defined(VERSION_EU_X)) || defined(NON_MATCHING)
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/SHARED_GAMESLOT.H"
extern char *D_800E27B4[];
extern char *D_800E27C4_eu[];
extern u8 *D_800E2804_eu[];
extern char *D_800E25B4[];
extern char D_004501C4[];
#define ENTRY_TEXT(e) ((e)->text[g_languageIndex])
#define PAK_HEADER_376C D_800E2804_eu
#else
#define ENTRY_TEXT(e) (*(e)->text)
#define PAK_HEADER_376C (&D_800D376C)
#endif
extern s32 D_8015375C;

extern char *D_800D3758;

extern char *D_800D375C;

extern s32 Pak_ReadNoteInfo(s32 ch, s32 index, s32 *exists, u8 *name, u8 *ext, s32 *size,
                         char *companyCode, char *gameCode);

extern s32 func_804057BC_de(u8 *name, s32 size);

extern void Resmgr_CopyString(u8 *dst, char *src);

/* Native resident constant storage; absolute access symbols retain their addresses. */
#if defined(VERSION_US)

#elif defined(VERSION_US_REV1)

#elif defined(VERSION_DE)

#endif

extern s32 D_8011FECC;

extern Digits D_800DCD78;

extern u8 *D_800D3754;

extern u8 *D_800D376C;

extern u8 *D_800D7E14;

extern s32 Pak_GetFreePages(s32 ch, s32 *freeSpace);

extern s32 Ovlgame_BytesToPakPages(s32 size);

static inline int space_required(int size) {size += 0x610; return Ovlgame_BytesToPakPages(size);}

extern char D_8014561C[];
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#define PAK_D0044EEF4 D_004501C4
#else
#define PAK_D0044EEF4 D_0044EEF4
#endif

extern char D_0044EEF4[];

extern s32 Pak_CheckStatusPrompt(Shared_PakMenu *menu, s32 ch, s32 mode);

extern s32 Pak_SaveControllerRecord(s32 arg0, Shared_PakMenu *menu, s32 arg2);

extern void Pak_SaveSnapshotAndClose(s32 arg0, Shared_PakMenu *menu, s32 arg2);

extern void Pak_GetNoteGameName(s32 ch, s32 note, s32 *state);

extern void func_80405648_de(s32 state, char *name, s32 size);


extern void Pak_OpenDialog(char *, char *, ObjRecAt5DC *, PakMenuSlot *, char *);

extern void Pak_ProbeStatus(s32 ch);

extern s32 Pak_GetStatus(s32 ch);

static inline void pickChannel(Shared_PakMenu *menu, s32 *ch)
{
    if (D_8015375C != 0) {
        *ch = D_800E28C8;
    } else {
        *ch = menu->owner->unk4;
    }
}

static inline s32 findNote(s32 ch, s32 *found)
{
    char name[16];
    s32 state;
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    char *game = D_800E25B4[g_languageIndex];
#else
    char *game = D_800D36D8;
#endif
    s32 i;

    D_8014D4FC = -1;
    for (i = 0; i < 16; i++) {
        Pak_GetNoteGameName(ch, i, &state);
        func_80405648_de(state, name, 16);
        if (Resmgr_CompareStrings(name, game) == 0) {
            if (found != 0) {
                *found = i;
            }
            return 1;
        }
    }
    return 0;
}

s32 func_80407F6C_de(PakNoteTextEntry *entry, PakNotesMenu *menu) {
    u8 name[16];
    u8 ext[8];
    char companyCode[8];
    char gameCode[8];
    s32 exists;
    s32 size;
    s32 ch;
    s32 result;
    s32 more;
    s32 i;
    u8 *dst;
    u8 c;
    s32 index;
    char **placeholder;

    c = ' ';
    index = entry->id - 3;
    if (D_80153784 != 0) {
        return 0;
    }
    if (D_8015375C != 0) {
        ch = D_800E28C8;
    } else {
        ch = menu->owner->unk4;
    }
    result = Pak_ReadNoteInfo(ch, index, &exists, name, ext, &size, companyCode, gameCode);
    if (exists != 0 && result == 0) {
        if (func_804057BC_de(name, 16) != 0) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
            Resmgr_CopyString(name, D_800E27B4[g_languageIndex]);
#else
            Resmgr_CopyString(name, D_800D3758);
#endif
        }
    } else {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        Resmgr_CopyString(name, D_800E27C4_eu[D_801462C8.language]);
        Resmgr_CopyString(ext, D_800E27C4_eu[D_801462C8.language]);
#else
        placeholder = &D_800D375C;
        Resmgr_CopyString(name, *placeholder);
        Resmgr_CopyString(ext, *placeholder);
#endif
        size = 0;
    }
    more = 1;
    dst = ENTRY_TEXT(entry);
    dst += 3;
    for (i = 0; i < 16; i++) {
        if (more) {
            c = name[i];
        }
        if (c == 0) {
            more = 0;
            c = ' ';
        }
        *dst++ = c;
    }
    more = 1;
    dst++;
    for (i = 0; i < 4; i++) {
        if (more) {
            c = ext[i];
        }
        if (c == 0) {
            more = 0;
            c = ' ';
        }
        *dst++ = c;
    }
    *dst += 2;
    func_802658E4_de(dst, g_pakFormatInt3, size);
    return 0;
}

s32 func_80408118_de(PakNoteTextEntry *entry, PakStatusPakSaveMenu *menu) {
    Digits digits;
    s32 freeSpace;
    s32 ch;
    s32 need;
    s32 result;
    u8 *text;
    u8 **header;
    char *format;
    Digits *buffer;

    if (D_8015375C != 0) {
        ch = D_800E28C8;
    } else {
        ch = menu->slot->unk4;
    }
    digits = D_800DCD78;
    buffer = &digits;
    if (D_8014D4C0_de != 0) {
        entry->text = &D_800D3754;
        if (Pak_GetFreePages(ch, &freeSpace) == 0) {
            if (D_8014D4EC_de) need=Ovlgame_BytesToPakPages(0x18); else need=space_required(D_8011FECC);
            text = ENTRY_TEXT(entry);
            func_802658E4_de(digits.c, g_pakFormatInt3, freeSpace);
            text += 14;
            *text++ = digits.c[0];
            *text++ = digits.c[1];
            *text = digits.c[2];
            func_802658E4_de(digits.c, g_pakFormatInt3, need);
            text += 15;
            *text++ = digits.c[0];
            *text = digits.c[1];
            text[1] = digits.c[2];
        }
    } else if (D_8015375C != 0) {
        header = PAK_HEADER_376C;
        goto fill;
    } else if (D_80153760 != 0) {
        header = &D_800D3754;
    fill:
        entry->text = header;
        result = Pak_GetFreePages(ch, &freeSpace);
        need = Ovlgame_BytesToPakPages(D_8011FECC + 0x610);
        text = ENTRY_TEXT(entry);
        if (result == 0) {
            text += 14;
            format = g_pakFormatInt3;
            func_802658E4_de(buffer->c, format, freeSpace);
            *text++ = digits.c[0];
            *text++ = digits.c[1];
            *text = digits.c[2];
            func_802658E4_de(buffer->c, format, need);
            text += 15;
            *text++ = digits.c[0];
            *text = digits.c[1];
            text[1] = digits.c[2];
        }
    } else {
        entry->text = &D_800D7E14;
    }
    return 0;
}

s32 func_804082FC_de(s32 arg0, Shared_PakMenu *menu, s32 arg2)
{
    s32 ch = 0;
    s32 use;
    s32 next;
    s32 tries;
    s32 hasNote;
    s32 c;

    if (D_8014D4C0_de != 0) {
        pickChannel(menu, &ch);
    }
    if (D_8015375C != 0) {
        use = D_800E28C8;
    } else {
        use = ch;
    }
    if (Pak_CheckStatusPrompt(menu, use, 0) != 0) {
        D_80153784 = 1;
        return 1;
    }
    if (D_8014D4EC_de != 0) {
        if (D_8014D4C0_de != 0) {
            Pak_SaveControllerRecord(arg0, menu, arg2);
            return 1;
        }
    } else if (D_8014D4C0_de != 0) {
        hasNote = findNote(use, &D_8014D4FC);
        if (hasNote != 0 && D_8014D4FC >= 0 && D_8014D4FC < 16) {
            Pak_OpenDialog(D_8014561C, PAK_D0044EEF4, menu->player, menu->owner, D_0044E4D4);
            return 1;
        }
        Pak_SaveSnapshotAndClose(arg0, menu, arg2);
        return 1;
    }
    if (D_8015375C != 0) {
        next = 0;
        if (D_800E28C8 != -1) {
            next = D_800E28C8 + 1;
            if (next >= 4) {
                next = 0;
            }
        }
        for (tries = 0; tries < 4; tries++) {
            Pak_ProbeStatus(next);
            if (Pak_GetStatus(next) != -2) {
                break;
            }
            next++;
            if (next >= 4) {
                next = 0;
            }
        }
        if (tries == 4) {
            next = -1;
        }
        D_800E28C8 = next;
        if (next == -1) {
            D_8014ADA0 = D_80153784 = 1;
            return 1;
        }
        if (D_8015375C != 0) {
            c = D_800E28C8;
        } else {
            c = menu->owner->unk4;
        }
        ch = c;
        if (Pak_CheckStatusPrompt(menu, c, 0) != 0) {
            D_80153784 = 1;
            return 1;
        }
        Pak_MarkSaveNotes(menu);
    }
    return 0;
}
#endif
