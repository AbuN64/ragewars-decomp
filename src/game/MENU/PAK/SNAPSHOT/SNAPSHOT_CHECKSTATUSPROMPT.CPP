#include "sdk/LIBC.H"
#include "include_asm.h"
#include "RESMGR/resmgr_string_memory.H"
#include "COMMON/LONE/D_0044E4F8.H"
#include "COMMON/LONE/D_0044ED44.H"
#include "COMMON/LONE/G_LANGUAGEINDEX.H"
#include "COMMON/PAK_MENU.H"
#include "COMMON/WORLD.H"
#include "MENU/PAK/SAVE_SNAPSHOT.H"
/* g_worldSnapshotNoteBytes is D_8011FE88.noteCount (world + 0x44). The tail reads it as that member, which keeps cse from
 * folding its loads across the snapshot header stores; the two head reads stay plain scalar loads (MIXED). */
extern s32 g_worldSnapshotNoteBytes;
extern void *g_pakSnapshotResourceHandle;
extern u8 g_pakSingleSaveBlockName[];
#include "COMMON/SHARED_GAMESLOT.H"
extern f32 g_matchRoundCounters[];
extern u8 g_worldSnapshotNoteData[];
extern void Cache_DrainAndCompactResources(s32);
extern SaveSnapshot **Cache_AllocateResource(s32, s32, s32, void *);
extern void XPlus_FillMemory(void *, s32, s32);

/* eu-x splits this function one word late (its leading lui sits in the
 * preceding data blob), so that version keeps the split asm. */
void Snapshot_CreateSaveSnapshot(u8 *player) {
    s32 snapshotSize = g_worldSnapshotNoteBytes + 0x610;
    s32 allocationSize;
    SaveSnapshot **snapshotHandle;
    SaveSnapshot *snapshot;
    if (g_pakSnapshotResourceHandle != 0) {
        Cache_DrainAndCompactResources(0);
        Cache_ReleaseResource(0, g_pakSnapshotResourceHandle);
    }
    allocationSize = g_worldSnapshotNoteBytes + 0x610;
    snapshotHandle = Cache_AllocateResource(0, allocationSize, 0x33, g_pakSingleSaveBlockName);
    g_pakSaveSnapshot = *snapshotHandle;
    g_pakSnapshotResourceHandle = snapshotHandle;
    XPlus_FillMemory(g_pakSaveSnapshot, 0, allocationSize);
    g_pakSaveSnapshot->player = *(Copy70 *)(player + 0x5E0);
    g_pakSaveSnapshot->world = *(Copy584 *)&g_gameSettings;
    snapshot = g_pakSaveSnapshot;
    snapshot->view[0] = g_matchRoundCounters[0];
    snapshot->view[1] = g_matchRoundCounters[1];
    snapshot->view[2] = g_matchRoundCounters[2];
    snapshot->view[3] = g_matchRoundCounters[3];
    snapshot->size = snapshotSize;
    snapshot->dataSize = g_world.noteCount;
    Libc_CopyBytes(snapshot->name, g_worldSnapshotNoteData, g_world.noteCount);
}

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern char *g_pakLegacySnapshotGameNames[];
extern char *g_pakCompanyCodes[];
extern char *g_pakProfileGameNames[];
extern char *g_pakSnapshotGameNames[];
#define PAK_CODE g_pakLegacySnapshotGameNames[g_languageIndex]
#define PAK_COMPANY g_pakCompanyCodes[g_languageIndex]
#define PAK_TITLE1 g_pakProfileGameNames[getSettings()->language]
#define PAK_TITLE2 g_pakSnapshotGameNames[getSettings()->language]
#else
#define PAK_CODE g_pakLegacySnapshotGameNameFixed
#define PAK_COMPANY g_pakCompanyCodeFixed
#define PAK_TITLE1 g_pakProfileGameNameFixed
#define PAK_TITLE2 g_pakSnapshotGameNameFixed
#endif
extern s32 g_introSelectedItem, D_800DE874;
extern char *g_pakProfileGameNameFixed, *g_pakSnapshotGameNameFixed, *g_pakCompanyCodeFixed;

extern s32 g_pakUseScannedChannel;

extern char *g_pakLegacySnapshotGameNameFixed;

extern s32 Note_ReadNoteInfo(s32 ch, s32 index, s32 *exists, char *name, char *ext, s32 *size,
                         char *company, char *code);
extern s32 XPlus_StringLength(char *);

/* Inlined into each title lookup: the loop pass merges the two address loads into one hoisted register,
 * which then outranks the loop-hoisted length constants 4 and 2 (a local pointer loses that race). */
static __inline__ Shared_Game *getSettings(void) {
    return &g_gameSettings;
}

void Snapshot_MarkSaveNotes(Shared_PakMenu *menu) {
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

    if (g_pakUseScannedChannel != 0) {
        ch = g_introSelectedItem;
    } else {
        ch = menu->owner->controllerPort;
    }
    for (i = 0; i < 16; i++) {
        result = Note_ReadNoteInfo(ch, i, &exists, name, ext, &size, company, code);
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
#include "MENU/PAK_PROFILE_PROMPT_VIEWS.H"
extern s32 D_8014D4C0_de, D_8014D4EC_de, g_pakUseScannedChannel, D_80153760, D_80153784, g_introSelectedItem;
extern char g_matchEndingTeamWheelClose[], D_0044FFA4[], D_0044FB50[];
extern char D_0044EA98[], D_0044E9C0[], D_0044EA2C[], D_0044EA08[], D_0044E9E4[];
extern void Note_ProbeStatus(s32);
extern s32 Note_GetStatus(s32), Note_IsChannelReady(s32), Note_NeedsIdRepair(s32), Control_TakePakChange(s32);
extern void Menu_OpenDialog(char *, char *, ActorOwnerView *, PakMenuSlot *, char *);
s32 Snapshot_CheckStatusPrompt(MenuPakBeginProfileLoad *menu, s32 channel, s32 quiet)
{
    s32 result, busy, slot;
    char *prompt, *sel;
    char *message;
    Note_ProbeStatus(channel);
    result = Note_GetStatus(channel);
    sel = 0;
    if (D_8014D4C0_de) {
        if (D_8014D4EC_de) {
            if (g_pakUseScannedChannel) slot = g_introSelectedItem;
            else slot = menu->slot->controllerPort;
            sel = pakPrompt(&slot);
        }
    } else if (D_80153760) {
        sel = D_0044FFA4;
        if (D_8014D4EC_de) sel = D_0044FB50;
    } else if (g_pakUseScannedChannel) sel = D_0044E4F8;
    prompt = sel;
    if (!prompt) return 0;
    busy = Control_TakePakChange(channel);
    if ((result == 0 || busy != 0) && result != -2) {
        if (busy) {
            Menu_OpenDialog(g_matchEndingTeamWheelClose, D_0044EA98, menu->player, menu->slot, prompt);
            return -1;
        }
        return result;
    }
    if (Note_IsChannelReady(channel)) {
        D_80153784 = 1;
        if (g_pakUseScannedChannel) message = D_0044E9E4;
        else {
            if (D_8014D4C0_de) message = D_0044EA08;
            else message = D_0044EA2C;
        }
        Menu_OpenDialog(g_matchEndingTeamWheelClose, message, menu->player, menu->slot, prompt);
    } else if (!quiet) {
        D_80153784 = 1;
        if (Note_NeedsIdRepair(channel))
            Menu_OpenDialog(g_matchEndingTeamWheelClose, D_0044ED44, menu->player, menu->slot, prompt);
        else Menu_OpenDialog(g_matchEndingTeamWheelClose, D_0044E9C0, menu->player, menu->slot, prompt);
    } else if (result != -2) result = 0;
    return result;
}

#include "COMMON/SHAREDPLAYER.H"
extern void Cache_ReleaseResource(s32, void *);
extern s32 D_8014D4C0_de, D_8014D4DC, D_80153760, D_8014D4EC_de, D_800DE874, D_80153784, g_pakUseScannedChannel, D_800E28C0, g_introSelectedItem;
extern struct Saved g_pakControllerRecord;
extern struct { u8 value; } g_controllerPakPreviewProfileFlags;
extern u8 D_8014D4B1, D_8014D4B2, D_8014D4B3;
extern u8 g_controllerPakPreviewProfileName[];
extern struct { u16 value; } g_pakProfileSavedWordOne, g_pakProfileSavedWordTwo, g_pakProfileSavedWordThree;
extern char D_0044EA08[], g_playerMenuDialogRomResource[], D_0044E9C0[], g_matchEndingTeamWheelClose[];
extern void Note_ProbeStatus(s32 ch);
extern s32 Note_GetStatus(s32 ch);
extern s32 Note_IsChannelReady(s32 ch);
extern s32 Note_NeedsIdRepair(s32 ch);
extern u32 Note_Crc32(void *data, u32 size, u32 seed);


/* Enters pak menu mode 1 on the selected channel: shows the pending message (D_800E28C0) with the channel's
   prompt, else probes the Controller Pak; with no pak data it saves the player's profile (flags, four words
   and eight name bytes) with its checksum and opens the note list through Snapshot_MarkSaveNotes, otherwise it
   shows the D_0044EA08, D_0044ED44 or D_0044E9C0 prompt. */
void Snapshot_BeginProfileSave(Shared_PakMenu *menu) {
    ActorOwnerView *owner = menu->player;
    ActorOwnerView *player;
    PakStatusProfile *profile;
    s32 channel;
    char *prompt;
    s32 i;

    D_8014D4C0_de = 1;
    D_8014D4DC = 1;
    D_80153760 = 0;
    D_8014D4EC_de = 1;
    D_800DE874 = 0;
    D_80153784 = 0;
    g_pakUseScannedChannel = 0;
    channel = menu->slot->controllerPort;
    player = owner;
    prompt = pakPrompt(&channel);
    if (D_800E28C0) {
        D_80153784 = 1;
        Menu_OpenDialog(menu->player->owner + 0x554, prompt, player, player->controller, 0);
        return;
    }
    if (g_pakUseScannedChannel) {
        Note_ProbeStatus(g_introSelectedItem);
    } else {
        Note_ProbeStatus(menu->slot->controllerPort);
    }
    if (!Note_GetStatus(channel)) {
        profile = player->profile;
        g_controllerPakPreviewProfileFlags.value = profile->flags;
        g_pakControllerRecord.values[0] = profile->words[0];
        g_pakProfileSavedWordOne.value = profile->words[1];
        g_pakProfileSavedWordTwo.value = profile->words[2];
        g_pakProfileSavedWordThree.value = profile->words[3];
        D_8014D4B1 = 0;
        D_8014D4B2 = 0;
        D_8014D4B3 = 0;
        for (i = 0; i < 8; i++) {
            g_controllerPakPreviewProfileName[i] = profile->name[i];
        }
        g_pakControllerRecord.checksum = Note_Crc32(&g_pakControllerRecord, 0x14, 4);
        Snapshot_MarkSaveNotes(menu);
        return;
    }
    D_80153784 = 1;
    if (Note_IsChannelReady(channel)) {
        Menu_OpenDialog(g_matchEndingTeamWheelClose, D_0044EA08, player, player->controller, prompt);
    } else if (Note_NeedsIdRepair(channel)) {
        Menu_OpenDialog(g_matchEndingTeamWheelClose, D_0044ED44, player, player->controller, g_playerMenuDialogRomResource);
    } else {
        Menu_OpenDialog(g_matchEndingTeamWheelClose, D_0044E9C0, player, player->controller, prompt);
    }
}
