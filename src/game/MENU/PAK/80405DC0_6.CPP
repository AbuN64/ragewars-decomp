#include "include_asm.h"
#include "RESMGR/resmgr_string_memory.H"
#include "COMMON/LONE/D_0044E4F8.H"
#include "COMMON/LONE/D_0044ED44.H"
#include "COMMON/LONE/D_80152789.H"
#include "COMMON/PAK_MENU.H"
#include "COMMON/WORLD.H"
#include "MENU/PAK/SAVE_SNAPSHOT.H"
/* D_8011FECC is D_8011FE88.noteCount (world + 0x44). The tail reads it as that member, which keeps cse from
 * folding its loads across the snapshot header stores; the two head reads stay plain scalar loads (MIXED). */
extern s32 D_8011FECC;
extern void *D_800DE860_de;
extern u8 g_pakSingleSaveBlockName[];
#include "COMMON/SHARED_GAMESLOT.H"
extern f32 D_801468A0[];
extern u8 D_800F91F0[];
extern void func_80253908_de(s32);
extern SaveSnapshot **Cache_AllocateResource(s32, s32, s32, void *);
extern void XPlus_FillMemory(void *, s32, s32);
extern void func_802BD3A0_de(void *, void *, s32);
/* eu-x splits this function one word late (its leading lui sits in the
 * preceding data blob), so that version keeps the split asm. */
#ifndef VERSION_EU_X
void Pak_CreateSaveSnapshot(u8 *player) {
    s32 snapshotSize = D_8011FECC + 0x610;
    s32 allocationSize;
    SaveSnapshot **snapshotHandle;
    SaveSnapshot *snapshot;
    if (D_800DE860_de != 0) {
        func_80253908_de(0);
        Cache_ReleaseResource(0, D_800DE860_de);
    }
    allocationSize = D_8011FECC + 0x610;
    snapshotHandle = Cache_AllocateResource(0, allocationSize, 0x33, g_pakSingleSaveBlockName);
    D_800DE868 = *snapshotHandle;
    D_800DE860_de = snapshotHandle;
    XPlus_FillMemory(D_800DE868, 0, allocationSize);
    D_800DE868->player = *(Copy70 *)(player + 0x5E0);
    D_800DE868->world = *(Copy584 *)&D_801462C8;
    snapshot = D_800DE868;
    snapshot->view[0] = D_801468A0[0];
    snapshot->view[1] = D_801468A0[1];
    snapshot->view[2] = D_801468A0[2];
    snapshot->view[3] = D_801468A0[3];
    snapshot->size = snapshotSize;
    snapshot->dataSize = g_world.noteCount;
    func_802BD3A0_de(snapshot->name, D_800F91F0, g_world.noteCount);
}
#else
INCLUDE_ASM("ovl_80400000", Pak_CreateSaveSnapshot);
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern char *D_800E25D4[];
extern char *D_800E25C4[];
extern char *D_800E25A4[];
extern char *D_800E25B4[];
#define PAK_CODE D_800E25D4[g_languageIndex]
#define PAK_COMPANY D_800E25C4[g_languageIndex]
#define PAK_TITLE1 D_800E25A4[getSettings()->language]
#define PAK_TITLE2 D_800E25B4[getSettings()->language]
#else
#define PAK_CODE D_800D36E0
#define PAK_COMPANY D_800D36DC
#define PAK_TITLE1 D_800D36D4
#define PAK_TITLE2 D_800D36D8
#endif
extern s32 D_800E28C8, D_800DE874;
extern char *D_800D36D4, *D_800D36D8, *D_800D36DC;

extern s32 D_8015375C;

extern char *D_800D36E0;

extern s32 Pak_ReadNoteInfo(s32 ch, s32 index, s32 *exists, char *name, char *ext, s32 *size,
                         char *company, char *code);
extern s32 XPlus_StringLength(char *);

/* Inlined into each title lookup: the loop pass merges the two address loads into one hoisted register,
 * which then outranks the loop-hoisted length constants 4 and 2 (a local pointer loses that race). */
static __inline__ Shared_Game *getSettings(void) {
    return &D_801462C8;
}

void Pak_MarkSaveNotes(Shared_PakMenu *menu) {
    s32 ch;
    s32 i;
    s32 other;
    s32 result;
    s32 match;
    char *title;
    char ext[8];
    char company[8];
    char code[8];
    char name[16];
    s32 exists;
    s32 size;

    if (D_8015375C != 0) {
        ch = D_800E28C8;
    } else {
        ch = menu->owner->unk4;
    }
    for (i = 0; i < 16; i++) {
        result = Pak_ReadNoteInfo(ch, i, &exists, name, ext, &size, company, code);
        other = 1;
        if (result == 0 && exists != 0) {
            switch (D_800DE874) {
                case 1:
                    if (XPlus_StringLength(code) == 4 && XPlus_StringLength(company) == 2 &&
                        XPlus_CompareStrings(code, PAK_CODE) == 0 && XPlus_CompareStrings(company, PAK_COMPANY) == 0) {
                        match = 1;
                    } else {
                        match = 0;
                    }
                    title = PAK_TITLE1;
                    break;
                case 2:
                    if (XPlus_StringLength(code) == 4 && XPlus_StringLength(company) == 2 &&
                        XPlus_CompareStrings(code, PAK_CODE) == 0 && XPlus_CompareStrings(company, PAK_COMPANY) == 0) {
                        match = 1;
                    } else {
                        match = 0;
                    }
                    title = PAK_TITLE2;
                    break;
                case 0:
                default:
                    other = 0;
                    goto done;
            }
            if (XPlus_CompareStrings(name, title) == 0 && match != 0) {
                other = 0;
            }
        }
    done:
        if (other) {
            menu->items[i + 3].flags &= ~0x1000000;
        } else {
            menu->items[i + 3].flags |= 0x1000000;
        }
    }
}

extern char D_00450BF0_de[], D_00450C14_de[], D_00450C38_de[], D_00450C5C_de[];
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
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RECORDRECAT1C.H"
#include "MENU/80405DC0.H"
extern s32 D_8014D4C0_de, D_8014D4EC_de, D_8015375C, D_80153760, D_80153784, D_800E28C8;
extern char D_8014561C[], D_0044FFA4[], D_0044FB50[];
extern char D_00450BF0_de[], D_00450C14_de[], D_00450C38_de[], D_00450C5C_de[];
extern char D_0044EA98[], D_0044E9C0[], D_0044EA2C[], D_0044EA08[], D_0044E9E4[];
extern void Pak_ProbeStatus(s32);
extern s32 Pak_GetStatus(s32), Pak_IsChannelReady(s32), Pak_NeedsIdRepair(s32), Control_TakePakChange(s32);
extern void Pak_OpenDialog(char *, char *, ObjRecAt5DC *, PakMenuSlot *, char *);
s32 Pak_CheckStatusPrompt(MenuPakBeginProfileLoad *menu, s32 channel, s32 quiet)
{
    s32 result, busy, slot;
    char *prompt, *sel;
    char *message;
    Pak_ProbeStatus(channel);
    result = Pak_GetStatus(channel);
    sel = 0;
    if (D_8014D4C0_de) {
        if (D_8014D4EC_de) {
            if (D_8015375C) slot = D_800E28C8;
            else slot = menu->slot->unk4;
            sel = pakPrompt(&slot);
        }
    } else if (D_80153760) {
        sel = D_0044FFA4;
        if (D_8014D4EC_de) sel = D_0044FB50;
    } else if (D_8015375C) sel = D_0044E4F8;
    prompt = sel;
    if (!prompt) return 0;
    busy = Control_TakePakChange(channel);
    if ((result == 0 || busy != 0) && result != -2) {
        if (busy) {
            Pak_OpenDialog(D_8014561C, D_0044EA98, menu->player, menu->slot, prompt);
            return -1;
        }
        return result;
    }
    if (Pak_IsChannelReady(channel)) {
        D_80153784 = 1;
        if (D_8015375C) message = D_0044E9E4;
        else {
            if (D_8014D4C0_de) message = D_0044EA08;
            else message = D_0044EA2C;
        }
        Pak_OpenDialog(D_8014561C, message, menu->player, menu->slot, prompt);
    } else if (!quiet) {
        D_80153784 = 1;
        if (Pak_NeedsIdRepair(channel))
            Pak_OpenDialog(D_8014561C, D_0044ED44, menu->player, menu->slot, prompt);
        else Pak_OpenDialog(D_8014561C, D_0044E9C0, menu->player, menu->slot, prompt);
    } else if (result != -2) result = 0;
    return result;
}

#include "COMMON/SHAREDPLAYER.H"
extern void Cache_ReleaseResource(s32, void *);
extern s32 D_8014D4C0_de, D_8014D4DC, D_80153760, D_8014D4EC_de, D_800DE874, D_80153784, D_8015375C, D_800E28C0, D_800E28C8;
extern struct Saved D_80153738;
extern struct { u8 value; } D_8014D4B0_de;
extern u8 D_8014D4B1, D_8014D4B2, D_8014D4B3;
extern u8 D_8014D4B4[];
extern struct { u16 value; } D_8014D4AA, D_8014D4AC_de, D_8014D4AE;
extern char D_00450BF0_de[], D_00450C14_de[], D_00450C38_de[], D_00450C5C_de[];
extern char D_0044EA08[], D_0044E48C[], D_0044E9C0[], D_8014561C[];
extern void Pak_ProbeStatus(s32 ch);
extern s32 Pak_GetStatus(s32 ch);
extern s32 Pak_IsChannelReady(s32 ch);
extern s32 Pak_NeedsIdRepair(s32 ch);
extern u32 Pak_Crc32(void *data, u32 size, u32 seed);


/* Enters pak menu mode 1 on the selected channel: shows the pending message (D_800E28C0) with the channel's
   prompt, else probes the Controller Pak; with no pak data it saves the player's profile (flags, four words
   and eight name bytes) with its checksum and opens the note list through Pak_MarkSaveNotes, otherwise it
   shows the D_0044EA08, D_0044ED44 or D_0044E9C0 prompt. */
void Pak_BeginProfileSave(Shared_PakMenu *menu) {
    ObjRecAt5DC *owner = menu->player;
    ObjRecAt5DC *player;
    ProfileRecAt84 *profile;
    s32 channel;
    char *prompt;
    s32 i;

    D_8014D4C0_de = 1;
    D_8014D4DC = 1;
    D_80153760 = 0;
    D_8014D4EC_de = 1;
    D_800DE874 = 0;
    D_80153784 = 0;
    D_8015375C = 0;
    channel = menu->slot->unk4;
    player = owner;
    prompt = pakPrompt(&channel);
    if (D_800E28C0) {
        D_80153784 = 1;
        Pak_OpenDialog(menu->player->unk5DC + 0x554, prompt, player, player->controller, 0);
        return;
    }
    if (D_8015375C) {
        Pak_ProbeStatus(D_800E28C8);
    } else {
        Pak_ProbeStatus(menu->slot->unk4);
    }
    if (!Pak_GetStatus(channel)) {
        profile = player->profile;
        D_8014D4B0_de.value = profile->flags;
        D_80153738.values[0] = profile->words[0];
        D_8014D4AA.value = profile->words[1];
        D_8014D4AC_de.value = profile->words[2];
        D_8014D4AE.value = profile->words[3];
        D_8014D4B1 = 0;
        D_8014D4B2 = 0;
        D_8014D4B3 = 0;
        for (i = 0; i < 8; i++) {
            D_8014D4B4[i] = profile->name[i];
        }
        D_80153738.checksum = Pak_Crc32(&D_80153738, 0x14, 4);
        Pak_MarkSaveNotes(menu);
        return;
    }
    D_80153784 = 1;
    if (Pak_IsChannelReady(channel)) {
        Pak_OpenDialog(D_8014561C, D_0044EA08, player, player->controller, prompt);
    } else if (Pak_NeedsIdRepair(channel)) {
        Pak_OpenDialog(D_8014561C, D_0044ED44, player, player->controller, D_0044E48C);
    } else {
        Pak_OpenDialog(D_8014561C, D_0044E9C0, player, player->controller, prompt);
    }
}
