#include "include_asm.h"
#include "COMMON/PAK_MENU.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RECORDRECAT1C.H"
#include "COMMON/MENURECAT24.H"
#include "TYPES.H"
#include "stddef.h"

#if !(defined(VERSION_EU) || defined(VERSION_EU_X)) || (defined(NON_MATCHING) && (defined(VERSION_EU) || defined(VERSION_EU_X)))
#if defined(VERSION_EU)
#define Pak_CheckControllerPak func_80406A90_eu
#endif
#if defined(VERSION_EU_X)
#define Pak_CheckControllerPak func_80406A90_eu_x
#endif
/* Selects a usable Controller Pak, checks its notes and free space, and opens the appropriate prompt. */
s32 func_8026464C_de(void);
void func_80293268_de(s32);
void func_80404E28_de(s32);
s32 Pak_GetStatus(s32);
s32 Pak_CountFreeNotes(s32, s32 *);
int Pak_GetFreePages(int, int *);
s32 Pak_GetNoteGameName(s32, s32, char **);
s32 func_80405598_de(s32);
void func_80405648_de(u8 *, u8 *, s32);
u32 func_804057EC_de(u32);
s32 func_80406858_de(void *, s32, s32 *, s32 *);
void * Pak_OpenDialog(void *, void *, s32, s32, s32);
s32 func_802A037C_de(); /* extern */
extern s32 D_0044E4F8;
#if defined(VERSION_DE)
extern s32 D_0044EA74;
extern s32 D_0044EABC;
#elif defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)


#elif defined(VERSION_US)
extern s32 D_0044EBE4;
extern s32 D_0044EC2C;
#endif
extern s32 D_0044ED44;
#if defined(VERSION_DE)
extern s32 D_0044EEAC;
extern s32 D_0044EED0;
#elif defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)


#elif defined(VERSION_US)
extern s32 D_0044F01C;
extern s32 D_0044F040;
#endif
extern s32 D_8011FECC;
#include "COMMON/GAME_SESSION.H"
extern s32 D_8014561C;
extern s32 D_8015375C;
/* Pak_FindNextAvailableChannel's scan: from the channel after currentChannel (or 0), the first channel whose probe is not -2; -1 if none. */
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
        func_80404E28_de(channel);
        if (Pak_GetStatus(channel) != -2) {
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
void Pak_CheckControllerPak(Shared_PakMenu *menu) {
    u8 noteText[16];
    s32 firstChannel;
    s32 freeChannel;
    s8 *note1;
    s8 *note2;
    s32 freeBytes;
    s32 freeNotes;
    s32 channelArg1;
    s32 channelArg2;
    s32 channel1;
    s32 channel2;
    s32 firstNoteName;
    s32 noteIndex;
    s32 noteIndex2; /* second note cursor, then the Pak error status */
    s32 retries; /* channel retries, then the second note name */
    s32 hasNote2; /* second note found */
    s32 status;
    s32 hasNote1;
    u32 minBytes;
    u32 maxBytes;
    D_8014D4C0_de = 0;
    D_8014D4DC = 1;
    D_80153760 = 0;
    D_8014D4EC_de = 0;
    D_800DE874 = 0;
    D_80153784 = 0;
    D_8015375C = 1;
    if (func_8026464C_de() == 0) {
        D_80153784 = 1;
        D_8014AD9C = 0;
#if defined(VERSION_DE)
        Pak_OpenDialog(&D_8014561C, &D_0044EABC, (s32)menu->player, (s32) menu->slot, 0);
#elif defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)
        Pak_OpenDialog(&D_8014561C, &D_0044F70C, (s32)menu->player, (s32) menu->slot, 0);
#elif defined(VERSION_US)
        Pak_OpenDialog(&D_8014561C, &D_0044EC2C, (s32)menu->player, (s32) menu->slot, 0);
#endif
        D_800E28CC = 1;
        D_8014AD94 = 0;
        return;
    }
    if (D_800E28C8 == -1) {
        D_800E28C8 = Pak_ScanNextChannel(-1);
        if (D_800E28C8 == -1) {
            D_80153784 = 1;
            D_8014AD9C = 0;
#if defined(VERSION_DE)
            Pak_OpenDialog(&D_8014561C, &D_0044EA74, (s32)menu->player, (s32) menu->slot, 0);
#elif defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)
            Pak_OpenDialog(&D_8014561C, &D_0044F6C4, (s32)menu->player, (s32) menu->slot, 0);
#elif defined(VERSION_US)
            Pak_OpenDialog(&D_8014561C, &D_0044EBE4, (s32)menu->player, (s32) menu->slot, 0);
#endif
            D_8014AD94 = 0;
            D_800E28CC = 1;
            return;
        }
    }
    if (func_80405598_de(D_800E28C8) == 0) {
        func_80293268_de((s32) &D_8011FAC0);
        if ((menu->slot->unkB0 & 0x1000) && (D_800E28CC == 0)) {
            D_80146D60 = 1;
            D_800E28CC = 1;
        }
        D_800E28CC = 1;
        if ((D_80142CAC != 0) || (D_80146D60 != 0)) {
            func_80404E28_de(D_800E28C8);
            if (Pak_GetStatus(D_800E28C8) == -2) {
                D_80153784 = 1;
                D_8014AD9C = 0;
#if defined(VERSION_DE)
                Pak_OpenDialog(&D_8014561C, &D_0044EA74, (s32)menu->player, (s32) menu->slot, 0);
#elif defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)
                Pak_OpenDialog(&D_8014561C, &D_0044F6C4, (s32)menu->player, (s32) menu->slot, 0);
#elif defined(VERSION_US)
                Pak_OpenDialog(&D_8014561C, &D_0044EBE4, (s32)menu->player, (s32) menu->slot, 0);
#endif
                D_8014AD94 = 0;
                D_800E28CC = 1;
                return;
            }
            goto block_60;
        }
        status = 0;
        retries = 0;
        freeChannel = -1;
        firstChannel = D_800E28C8;
        do {
            if (D_800E28C8 != -1) {
                status = func_80406858_de(menu, D_800E28C8, &firstChannel, &freeChannel);
                if (status != 0) {
                    break;
                }
            }
            D_800E28C8 = Pak_ScanNextChannel(D_800E28C8);
        } while (++retries < 4);
        if (status == 0) {
            D_800E28C8 = firstChannel;
            func_80404E28_de(firstChannel);
            if (Pak_GetStatus(D_800E28C8) == -2) {
                        D_80153784 = 1;
                        D_8014AD9C = 0;
#if defined(VERSION_DE)
                        Pak_OpenDialog(&D_8014561C, &D_0044EA74, (s32)menu->player, (s32) menu->slot, 0);
#elif defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)
                        Pak_OpenDialog(&D_8014561C, &D_0044F6C4, (s32)menu->player, (s32) menu->slot, 0);
#elif defined(VERSION_US)
                        Pak_OpenDialog(&D_8014561C, &D_0044EBE4, (s32)menu->player, (s32) menu->slot, 0);
#endif
                        D_8014AD94 = 0;
                        D_800E28CC = 1;
                        return;
            }
        }
        goto block_39;
/* FAKEMATCH: place found-note exits before the loops to preserve branch layout. */
first_note_found:
        hasNote1 = 1;
        goto second_note_search;
second_note_found:
        hasNote2 = 1;
        goto notes_checked;
block_39:
        noteIndex = 0;
        firstNoteName = D_800D36D4;
        channel1 = D_800E28C8;
        channelArg1 = channel1;
loop_40:
        Pak_GetNoteGameName(channelArg1, noteIndex, &note1);
        func_80405648_de((u8 *) note1, noteText, 0x10);
        if (func_802A037C_de(noteText, firstNoteName) == 0) {
            goto first_note_found;
        }
        noteIndex += 1;
        if (noteIndex < 0x10) {
            goto loop_40;
        }
        hasNote1 = 0;
second_note_search:
        noteIndex2 = 0;
        retries = D_800D36D8;
        channel2 = D_800E28C8;
        channelArg2 = channel2;
loop_44:
        Pak_GetNoteGameName(channelArg2, noteIndex2, &note2);
        func_80405648_de((u8 *) note2, noteText, 0x10);
        if (func_802A037C_de(noteText, retries) == 0) {
            goto second_note_found;
        }
        noteIndex2 += 1;
        if (noteIndex2 < 0x10) {
            goto loop_44;
        }
        hasNote2 = 0;
notes_checked:
        if ((hasNote1 == 0) && (hasNote2 == 0)) {
            if ((Pak_GetFreePages(D_800E28C8, &freeBytes) == 0) && (noteIndex2 = Pak_CountFreeNotes(D_800E28C8, &freeNotes), (noteIndex2 == 0))) {
                maxBytes = func_804057EC_de(D_8011FECC + 0x610);
                minBytes = func_804057EC_de(0x18U);
                if ((freeNotes != 0) && (freeBytes >= (s32) minBytes)) {
                    if (freeBytes < (s32) maxBytes) {
                        D_80153784 = 1;
                        D_80146D60 = 1;
#if defined(VERSION_DE)
                        Pak_OpenDialog(&D_8014561C, &D_0044EED0, (s32)menu->player, (s32) menu->slot, (s32) &D_0044E4F8);
#elif defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)
                        Pak_OpenDialog(&D_8014561C, &D_0044FB20, (s32)menu->player, (s32) menu->slot, (s32) &D_0044E4F8);
#elif defined(VERSION_US)
                        Pak_OpenDialog(&D_8014561C, &D_0044F040, (s32)menu->player, (s32) menu->slot, (s32) &D_0044E4F8);
#endif
                        goto prompt_checked;
                    }
                    /* FAKEMATCH: retain the repeated minimum-size test and its target branch. */
                    if (freeBytes < (s32) minBytes) {
                        goto block_56;
                    }
                } else {
block_56:
                    D_80153784 = 1;
                    D_80146D60 = 1;
#if defined(VERSION_DE)
                    Pak_OpenDialog(&D_8014561C, &D_0044EEAC, (s32)menu->player, (s32) menu->slot, (s32) &D_0044E4F8);
#elif defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)
                    Pak_OpenDialog(&D_8014561C, &D_0044FAFC, (s32)menu->player, (s32) menu->slot, (s32) &D_0044E4F8);
#elif defined(VERSION_US)
                    Pak_OpenDialog(&D_8014561C, &D_0044F01C, (s32)menu->player, (s32) menu->slot, (s32) &D_0044E4F8);
#endif
                }
prompt_checked:
                if (noteIndex2 != 0) {
                    goto block_59;
                }
            } else {
                goto block_59;
            }
        }
        goto block_60;
    }
block_59:
    D_80153784 = 1;
    D_80146D60 = 1;
    Pak_OpenDialog(&D_8014561C, &D_0044ED44, (s32)menu->player, (s32) menu->slot, (s32) &D_0044E4F8);
block_60:
    if (D_80153784 == 0) {
        func_80405F48_de(menu);
    }
    D_8014AD94 = 0;
    D_800E28CC = 1;
}
#endif

#ifdef NON_MATCHING
#include "TYPES.H"
extern s32 D_8014D4C0_de, D_8014D4DC, D_80153760, D_8014D4EC_de, D_800DE874, D_80153784, D_8015375C, D_800E28C0, D_800DE868;
extern char D_0044EA08[], D_00450BF0_de[], D_00450C14_de[], D_00450C38_de[], D_00450C5C_de[];
extern void func_80404E28_de(s32 ch);
extern s32 Pak_GetStatus(s32 ch);
extern s32 func_80404F3C_de(s32 ch);
extern s32 func_80405598_de(s32 ch);
extern void Pak_CreateSaveSnapshot(ObjRecAt5DC *);
extern u32 func_804057F8_de(s32 offset, void *data, s32 seed);
static __inline__ char *pakPrompt(s32 *channel) {
    char *result;
    switch (*channel) {
    case 0:
    default: result = D_00450BF0_de; break;
    case 1: result = D_00450C14_de; break;
    case 2: result = D_00450C38_de; break;
    case 3: result = D_00450C5C_de; break;
    }
    return result;
}
void func_80406F7C_de(Shared_PakMenu *menu) {
    s32 ch;
    ObjRecAt5DC *player;
    char *prompt;

    D_8014D4C0_de = 1;
    D_8014D4DC = 1;
    D_80153760 = 0;
    D_8014D4EC_de = 0;
    D_800DE874 = 0;
    D_80153784 = 0;
    D_8015375C = 0;
    ch = menu->slot->unk4;
    player = menu->player;
    prompt = pakPrompt(&ch);
    if (D_800E28C0 != 0) {
        D_80153784 = 1;
        return;
    }
    func_80404E28_de(menu->slot->unk4);
    if (Pak_GetStatus(ch) == 0) {
        Pak_CreateSaveSnapshot(player);
        *(u32 *)(D_8011FECC + D_800DE868 + 0x60C) = func_804057F8_de(D_800DE868, (void *)(D_8011FECC + 0x60C), 11);
        func_80405F48_de(menu);
        return;
    }
    D_80153784 = 1;
    if (func_80404F3C_de(ch) != 0) {
        Pak_OpenDialog(player->unk5DC + 0x554, D_0044EA08, (s32)player, (s32)player->controller, 1);
    } else if (func_80405598_de(ch) != 0) {
        Pak_OpenDialog(&D_8014561C, &D_0044ED44, (s32)player, (s32)player->controller, (s32)D_0044E4D4);
    }
}
#else
INCLUDE_ASM("ovl_80400000", func_80406F7C_de);
#endif
