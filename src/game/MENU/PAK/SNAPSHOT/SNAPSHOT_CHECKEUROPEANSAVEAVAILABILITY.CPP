#include "include_asm.h"
#include "RESMGR/resmgr_string_memory.H"
#include "MENU/PAK/SAVE_SNAPSHOT.H"
#include "COMMON/PAK_MENU.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RECORDRECAT1C.H"
#include "COMMON/MENURECAT24.H"
#include "TYPES.H"
#include "stddef.h"

#if defined(VERSION_EU)
#define Snapshot_CheckControllerPak Snapshot_CheckEuropeanSaveAvailability
#endif
#if defined(VERSION_EU_X)
#define Snapshot_CheckControllerPak Snapshot_CheckLocalizedSaveAvailability
#endif
/* Selects a usable Controller Pak, checks its notes and free space, and opens the appropriate prompt. */
s32 Control_AnyControllerConnected(void);
void SetN64_CommitSessionInputs(s32);
void Note_ProbeStatus(s32);
s32 Note_GetStatus(s32);
s32 Note_CountFreeNotes(s32, s32 *);
int Note_GetFreePages(int, int *);
s32 Note_GetNoteGameName(s32, s32, char **);
s32 Note_NeedsIdRepair(s32);
void Note_DecodeNoteText(u8 *, u8 *, s32);
u32 Note_BytesToPakPages(u32);
s32 Snapshot_EvaluateSaveChannel(void *, s32, s32 *, s32 *);
void * Menu_OpenDialog(void *, void *, s32, s32, s32);
extern s32 D_0044E4F8;
extern s32 D_0044ED44;
/* Per-version dialog scripts opened by Snapshot_CheckControllerPak. */
#if defined(VERSION_DE)
extern s32 D_0044EA74, D_0044EABC, D_0044EEAC, D_0044EED0;
#define PAK_DIALOG_NO_CONTROLLER D_0044EABC
#define PAK_DIALOG_NO_PAK D_0044EA74
#define PAK_DIALOG_LOW_SPACE D_0044EED0
#define PAK_DIALOG_FULL D_0044EEAC
#elif defined(VERSION_US)
extern s32 D_0044EBE4, D_0044EC2C, D_0044F01C, D_0044F040;
#define PAK_DIALOG_NO_CONTROLLER D_0044EC2C
#define PAK_DIALOG_NO_PAK D_0044EBE4
#define PAK_DIALOG_LOW_SPACE D_0044F040
#define PAK_DIALOG_FULL D_0044F01C
#elif defined(VERSION_EU)
extern s32 D_0044FD44_eu, D_0044FD8C_eu, D_0045017C, D_004501A0_eu;
#define PAK_DIALOG_NO_CONTROLLER D_0044FD8C_eu
#define PAK_DIALOG_NO_PAK D_0044FD44_eu
#define PAK_DIALOG_LOW_SPACE D_004501A0_eu
#define PAK_DIALOG_FULL D_0045017C
#elif defined(VERSION_EU_X)
extern s32 D_0044FE74_eu_x, D_0044FEBC_eu_x, D_0045017C, D_004502D0_eu_x;
#define PAK_DIALOG_NO_CONTROLLER D_0044FEBC_eu_x
#define PAK_DIALOG_NO_PAK D_0044FE74_eu_x
#define PAK_DIALOG_LOW_SPACE D_004502D0_eu_x
#define PAK_DIALOG_FULL D_0045017C
#else
#define PAK_DIALOG_NO_CONTROLLER D_0044F70C
#define PAK_DIALOG_NO_PAK D_0044F6C4
#define PAK_DIALOG_LOW_SPACE D_0044FB20
#define PAK_DIALOG_FULL D_0044FAFC
#endif
/* The game's two Controller Pak note names (PAL: per language). */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/LONE/D_80152789.H"
extern char *D_800E25A4[];
extern char *D_800E25B4[];
#define PAK_NOTE_NAME_1 D_800E25A4[g_languageIndex]
#define PAK_NOTE_NAME_2 D_800E25B4[g_languageIndex]
#else
#define PAK_NOTE_NAME_1 D_800D36D4
#define PAK_NOTE_NAME_2 D_800D36D8
#endif
extern s32 D_8011FECC;
#include "COMMON/GAME_SESSION.H"
extern s32 D_8014561C;
extern s32 D_8015375C;
/* Timer_FindNextAvailableChannel's scan: from the channel after currentChannel (or 0), the first channel whose probe is not -2; -1 if none. */
static inline s32 Pak_ScanNextChannel(s32 currentChannel) {
    s32 channel = 0;
    s32 attempts;
    if (currentChannel != -1) {
        channel = currentChannel + 1;
        if (channel >= 4) {
            channel = 0;
        }
    }
    attempts = 0;
    do {
        Note_ProbeStatus(channel);
        if (Note_GetStatus(channel) != -2) {
            break;
        }
        channel++;
        if (channel >= 4) {
            channel = 0;
        }
        attempts++;
    } while (attempts < 4);
    if (attempts == 4) {
        channel = -1;
    }
    return channel;
}
static inline s32 Pak_HasNamedNote(char *name, s32 channel) {
    u8 text[16];
    char *note;
    s32 index;
    for (index = 0; index < 16; index++) {
        Note_GetNoteGameName(channel, index, &note);
        Note_DecodeNoteText((u8 *)note, text, 16);
        if (XPlus_CompareStrings(text, name) == 0) {
            return 1;
        }
    }
    return 0;
}
void Snapshot_CheckControllerPak(Shared_PakMenu *menu) {
    s32 firstChannel;
    s32 freeChannel;
    s32 freeBytes;
    s32 freeNotes;
    s32 error;
    s32 retries;
    s32 status;
    s32 hasNote1;
    s32 hasNote2;
    u32 minBytes;
    u32 maxBytes;

    D_8014D4C0_de = 0;
    D_8014D4DC = 1;
    D_80153760 = 0;
    D_8014D4EC_de = 0;
    D_800DE874 = 0;
    D_80153784 = 0;
    D_8015375C = 1;
    if (Control_AnyControllerConnected() == 0) {
        D_80153784 = 1;
        D_8014AD9C = 0;
        Menu_OpenDialog(&D_8014561C, &PAK_DIALOG_NO_CONTROLLER, (s32)menu->player, (s32) menu->slot, 0);
        D_800E28CC = 1;
        D_8014AD94 = 0;
        return;
    }
    if (D_800E28C8 == -1) {
        D_800E28C8 = Pak_ScanNextChannel(-1);
        if (D_800E28C8 == -1) {
            D_80153784 = 1;
            D_8014AD9C = 0;
            Menu_OpenDialog(&D_8014561C, &PAK_DIALOG_NO_PAK, (s32)menu->player, (s32) menu->slot, 0);
            D_8014AD94 = 0;
            D_800E28CC = 1;
            return;
        }
    }
    error = Note_NeedsIdRepair(D_800E28C8);
    if (error == 0) {
        SetN64_CommitSessionInputs((s32) &D_8011FAC0);
        if ((menu->slot->unkB0 & 0x1000) && (D_800E28CC == 0)) {
            D_80146D60 = 1;
            D_800E28CC = 1;
        }
        D_800E28CC = 1;
        if ((D_80142CAC != 0) || (D_80146D60 != 0)) {
            Note_ProbeStatus(D_800E28C8);
            if (Note_GetStatus(D_800E28C8) == -2) {
                D_80153784 = 1;
                D_8014AD9C = 0;
                Menu_OpenDialog(&D_8014561C, &PAK_DIALOG_NO_PAK, (s32)menu->player, (s32) menu->slot, 0);
                D_8014AD94 = 0;
                D_800E28CC = 1;
                return;
            }
            goto finish;
        }
        status = 0;
        retries = 0;
        freeChannel = -1;
        firstChannel = D_800E28C8;
        do {
            if (D_800E28C8 != -1) {
                status = Snapshot_EvaluateSaveChannel(menu, D_800E28C8, &firstChannel, &freeChannel);
                if (status != 0) {
                    break;
                }
            }
            D_800E28C8 = Pak_ScanNextChannel(D_800E28C8);
        } while (++retries < 4);
        if (status == 0) {
            D_800E28C8 = firstChannel;
            Note_ProbeStatus(firstChannel);
            if (Note_GetStatus(D_800E28C8) == -2) {
                D_80153784 = 1;
                D_8014AD9C = 0;
                Menu_OpenDialog(&D_8014561C, &PAK_DIALOG_NO_PAK, (s32)menu->player, (s32) menu->slot, 0);
                D_8014AD94 = 0;
                D_800E28CC = 1;
                return;
            }
        }
        hasNote1 = Pak_HasNamedNote(PAK_NOTE_NAME_1, D_800E28C8);
        hasNote2 = Pak_HasNamedNote(PAK_NOTE_NAME_2, D_800E28C8);
        if ((hasNote1 == 0) && (hasNote2 == 0)) {
            error = Note_GetFreePages(D_800E28C8, &freeBytes);
            if (error == 0) {
                error = Note_CountFreeNotes(D_800E28C8, &freeNotes);
                if (error == 0) {
                    maxBytes = Note_BytesToPakPages(D_8011FECC + sizeof(SaveSnapshot));
                    minBytes = Note_BytesToPakPages(0x18U);
                    if (freeNotes != 0) {
                        if (freeBytes >= (s32)minBytes && freeBytes < (s32)maxBytes) {
                            D_80153784 = 1;
                            D_80146D60 = 1;
                            Menu_OpenDialog(&D_8014561C, &PAK_DIALOG_LOW_SPACE, (s32)menu->player, (s32) menu->slot, (s32) &D_0044E4F8);
                        } else if (freeBytes < (s32)minBytes) {
                            D_80153784 = 1;
                            D_80146D60 = 1;
                            Menu_OpenDialog(&D_8014561C, &PAK_DIALOG_FULL, (s32)menu->player, (s32) menu->slot, (s32) &D_0044E4F8);
                        }
                    } else {
                        D_80153784 = 1;
                        D_80146D60 = 1;
                        Menu_OpenDialog(&D_8014561C, &PAK_DIALOG_FULL, (s32)menu->player, (s32) menu->slot, (s32) &D_0044E4F8);
                    }
                }
            }
        } else {
            goto finish;
        }
    }
    if (error != 0) {
        D_80153784 = 1;
        D_80146D60 = 1;
        Menu_OpenDialog(&D_8014561C, &D_0044ED44, (s32)menu->player, (s32) menu->slot, (s32) &D_0044E4F8);
    }
finish:
    if (D_80153784 == 0) {
        Snapshot_MarkSaveNotes(menu);
    }
    D_8014AD94 = 0;
    D_800E28CC = 1;
}

#include "TYPES.H"
extern s32 D_8015375C, D_800E28C0;
extern s32 D_8014561C, D_0044ED44, D_8011FECC;
extern char D_0044EA08[];
extern void Note_ProbeStatus(s32 ch);
extern s32 Note_GetStatus(s32 ch);
extern s32 Note_IsChannelReady(s32 ch);
extern s32 Note_NeedsIdRepair(s32 ch);
extern void Snapshot_CreateSaveSnapshot(ObjRecAt5DC *);
extern u32 Note_Crc32(void *data, u32 size, u32 seed);
void *Menu_OpenDialog(void *, void *, s32, s32, s32);
/* The channel the pak menu works on: the scanned channel D_800E28C8 while D_8015375C is set, else the slot's. */
static __inline__ void pakGetChannel(Shared_PakMenu *menu, s32 *channel) {
    if (D_8015375C != 0) {
        *channel = D_800E28C8;
    } else {
        *channel = menu->owner->unk4;
    }
}
/* Timer_SetSaveTrailerValue's body: store the snapshot checksum after the D_8011FECC bytes of note data. */
static __inline__ void pakSetChecksum(s32 offset, s32 value) {
    *(s32 *)((u8 *)(D_8011FECC + offset) + 0x60C) = value;
}
/* Opens the pak menu for a snapshot save: unless a message is pending (D_800E28C0), probes the channel's
   Controller Pak; a ready pak gets the save snapshot with its checksum and the note list (Snapshot_MarkSaveNotes),
   otherwise the damaged-pak (D_0044EA08) or D_0044ED44 prompt opens. Twin of Snapshot_BeginProfileSave. */
void Snapshot_BeginSnapshotSave(Shared_PakMenu *menu) {
    ObjRecAt5DC *owner = menu->player;
    ObjRecAt5DC *player;
    s32 channel;

    D_8014D4C0_de = 1;
    D_8014D4DC = 1;
    D_80153760 = 0;
    D_8014D4EC_de = 0;
    D_800DE874 = 0;
    D_80153784 = 0;
    D_8015375C = 0;
    pakGetChannel(menu, &channel);
    player = owner;
    if (D_800E28C0) {
        D_80153784 = 1;
        return;
    }
    if (D_8015375C) {
        Note_ProbeStatus(D_800E28C8);
    } else {
        Note_ProbeStatus(menu->slot->unk4);
    }
    if (!Note_GetStatus(channel)) {
        Snapshot_CreateSaveSnapshot(player);
        pakSetChecksum((s32)D_800DE868, Note_Crc32(D_800DE868, D_8011FECC + 0x60C, 11));
        Snapshot_MarkSaveNotes(menu);
        return;
    }
    D_80153784 = 1;
    if (Note_IsChannelReady(channel)) {
        Menu_OpenDialog(player->unk5DC + 0x554, D_0044EA08, (s32)player, (s32)player->controller, 1);
    } else if (Note_NeedsIdRepair(channel)) {
        Menu_OpenDialog(&D_8014561C, &D_0044ED44, (s32)player, (s32)player->controller, (s32)D_0044E4D4);
    }
}
