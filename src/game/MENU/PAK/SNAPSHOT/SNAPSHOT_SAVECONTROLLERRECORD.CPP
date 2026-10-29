#include "include_asm.h"
#include "COMMON/LONE/D_0044ED44.H"
#include "COMMON/PAK_MENU.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RECORDRECAT1C.H"
#include "COMMON/MENURECAT24.H"
#include "TYPES.H"

/* Enters pak menu mode 2: sets the mode flags, shows the D_0044FFA4 prompt when a message is pending (D_800E28C0), and otherwise clears the owner's 0x01000000 flag, probes the Controller Pak on the selected channel, falls back to Snapshot_MarkSaveNotes when Note_GetStatus reports none, and shows the D_0044EA2C, D_0044ED44 or D_0044E9C0 prompt according to func_80404F3C_de and Note_NeedsIdRepair. */











extern s32 g_pakUseScannedChannel;
extern s32 D_800E28C0;
extern char g_matchEndingTeamWheelClose[];
extern char D_0044FFA4[];
extern unsigned char g_controllerPakReadyDialogResource[];
extern char D_0044EA2C[];
extern char D_0044E9C0[];
extern void Note_ProbeStatus(s32 ch);
extern s32 Note_GetStatus(s32 ch);
extern s32 Note_IsChannelReady(s32 ch);
extern s32 Note_NeedsIdRepair(s32 ch);
extern void Menu_OpenDialog(char *, char *, ActorOwnerView *, PakMenuSlot *, char *);
void Snapshot_BeginBlockLoad(Shared_PakMenu *menu)
{
  Shared_PakMenu *activeMenu;
  int statusValue;
  char *channelUnavailableDialog;
  s32 ch;
  statusValue = 1;
  D_800DE874 = 2;
  D_8014D4C0_de = 0;
  D_8014D4DC = 0;
  D_80153760 = statusValue;
  D_8014D4EC_de = 0;
  D_80153784 = 0;
  g_pakUseScannedChannel = 0;
  ch = menu->slot->controllerPort;
  if (D_800E28C0 != 0)
  {
    D_80153784 = 1;
    Menu_OpenDialog(g_matchEndingTeamWheelClose, D_0044FFA4, menu->player, menu->slot, 0);
    return;
  }
  menu->items[20].flags &= ~0x01000000;
  Note_ProbeStatus(menu->slot->controllerPort);
  statusValue = 0;
  if (Note_GetStatus(ch) == statusValue)
  {
    Snapshot_MarkSaveNotes(menu);
    return;
  }
  D_80153784 = 1;
  if (Note_IsChannelReady(ch) != statusValue)
  {
    channelUnavailableDialog = D_0044EA2C;
    Menu_OpenDialog(g_matchEndingTeamWheelClose, channelUnavailableDialog, menu->player, menu->slot, (char *) 1);
  }
  else
  {
    activeMenu = menu;
    if (Note_NeedsIdRepair(ch) != 0)
    {
      Menu_OpenDialog(g_matchEndingTeamWheelClose, D_0044ED44, activeMenu->player, menu->slot, g_controllerPakReadyDialogResource);
    }
    else
    {
      Menu_OpenDialog(g_matchEndingTeamWheelClose, D_0044E9C0, activeMenu->player, activeMenu->slot, D_0044FFA4);
    }
  }
}

#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PAK_SAVE_TEXT.H"
#include "MENU/PAK/SAVE_SNAPSHOT.H"
extern void Cache_ReleaseResource(s32, void *);
extern void *g_pakSnapshotResourceHandle;
extern struct CacheResourceBlockView *g_pakLoadedNoteResourceHandle;
extern s32 g_controllerPakSnapshotPayload;
extern char g_pakControllerRecord[];
extern char g_matchEndingTeamWheelClose[];
extern char D_00450BF0_de[];
extern char D_00450C14_de[];
extern char D_00450C38_de[];
extern char D_00450C5C_de[];
extern u32 Note_BytesToPakPages(u32);
extern s32 Note_GetFreePages(s32, s32 *);
extern s32 Note_CountFreeNotes(s32, s32 *);
extern s32 Note_FindFreeNoteExtension(s32, char *);
extern s32 Note_SaveNote(s32, s32, void *, char *, char *, char *);
extern void Cache_DrainAndCompactResources(s32);
/* Save the small controller-pak record when capacity allows, release the
 * pending resources, and show the channel-specific success/error dialog. */
static inline ActorOwnerView *pakRecordChannel(Shared_PakMenu *menu, s32 *channel) {
    if (g_pakUseScannedChannel != 0) {
        *channel = g_introSelectedItem;
        return 0;
    }
    *channel = menu->owner->controllerPort;
    return menu->player;
}

static inline char *pakRecordChannelLabel(s32 channel) {
    switch (channel) {
    case 0:
    default: return D_00450BF0_de;
    case 1: return D_00450C14_de;
    case 2: return D_00450C38_de;
    case 3: return D_00450C5C_de;
    }
}

s32 Snapshot_SaveControllerRecord(s32 unused, struct Shared_PakMenu *menu, s32 unusedEvent)
{
    ActorOwnerView *player, *selectedPlayer;
    char extension[8];
    s32 channel, freeBytes, slots, required, status = 0;
    s32 insufficient = 1;
    s32 attempted = 0;
    selectedPlayer = pakRecordChannel(menu, &channel);
    player = selectedPlayer;
    if (D_8014D4C0_de != 0) {
        required = Note_BytesToPakPages(0x18);
        status = Note_GetFreePages(channel, &freeBytes);
        if (status == 0) {
            if (required <= freeBytes) {
                status = Note_CountFreeNotes(channel, &slots);
                if (status == 0 && slots != 0) {
                    insufficient = 0;
                    status = Note_FindFreeNoteExtension(channel, extension);
                    if (status == 0) {
                        attempted = 1;
                        status = Note_SaveNote(channel, 0x18, g_pakControllerRecord,
                                              RW_PAK_RECORD_TITLE, extension, RW_PAK_GAME_CODE);
                    }
                }
            }
            if (insufficient != 0) {
                Menu_OpenDialog(g_matchEndingTeamWheelClose, rw_pak_no_space_dialog(), player,
                                (PakMenuSlot *)player->controller, menu->dialogData);
                return 0;
            }
        }
    }
    if (g_pakSnapshotResourceHandle != 0 || g_pakLoadedNoteResourceHandle != 0) Cache_DrainAndCompactResources(0);
    if (g_pakSnapshotResourceHandle != 0) Cache_ReleaseResource(0, g_pakSnapshotResourceHandle);
    if (g_pakLoadedNoteResourceHandle != 0) Cache_ReleaseResource(0, g_pakLoadedNoteResourceHandle);
    g_pakSnapshotResourceHandle = 0;
    g_pakLoadedNoteResourceHandle = 0;
    g_pakSaveSnapshot = 0;
    g_controllerPakSnapshotPayload = 0;
    if (!attempted) return 1;
    if (status == 0) {
        Menu_OpenDialog(g_matchEndingTeamWheelClose, rw_pak_save_success_dialog(), player,
                        (PakMenuSlot *)player->controller, pakRecordChannelLabel(channel));
    } else {
        Menu_OpenDialog(g_matchEndingTeamWheelClose, rw_pak_save_error_dialog(), player,
                        (PakMenuSlot *)player->controller, pakRecordChannelLabel(channel));
    }
    return 1;
}

extern u32 g_worldSnapshotNoteBytes;
extern char g_pakSnapshotCapacityPromptEuX[];
/* The capacity prompt is per release. */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern char g_pakSnapshotCapacityPromptEu[];
static inline char *pakSnapshotCapacityPrompt(void) { return g_pakSnapshotCapacityPromptEu; }
#else
#if defined(VERSION_US_REV1)
static inline char *pakSnapshotCapacityPrompt(void) { return g_pakSnapshotCapacityPromptEuX; }
#elif defined(VERSION_US)
extern char g_pakSnapshotCapacityPromptUsRev1[];
static inline char *pakSnapshotCapacityPrompt(void) { return g_pakSnapshotCapacityPromptUsRev1; }
#else
extern char g_pakSnapshotCapacityPromptDe[];
static inline char *pakSnapshotCapacityPrompt(void) { return g_pakSnapshotCapacityPromptDe; }
#endif
#endif
/* Save the snapshot only when both page and note capacity are available;
 * retain pending resources while showing the insufficient-capacity prompt. */
s32 Snapshot_SaveSnapshotAndClose(void *unused, Shared_PakMenu *menu) {
    ActorOwnerView *player, *selectedPlayer;
    char extension[8];
    s32 channel, freePages, freeNotes;
    s32 snapshotBytes, required, status;
    s32 showPrompt = 1;
    selectedPlayer = pakRecordChannel(menu, &channel);
    player = selectedPlayer;
    snapshotBytes = g_worldSnapshotNoteBytes + sizeof(SaveSnapshot);
    if (D_8014D4C0_de != 0) {
        required = Note_BytesToPakPages(snapshotBytes);
        status = Note_GetFreePages(channel, &freePages);
        if (status == 0) {
            if (required <= freePages) {
                if (Note_CountFreeNotes(channel, &freeNotes) == 0 && freeNotes != 0) {
                    showPrompt = 0;
                    if (Note_FindFreeNoteExtension(channel, extension) == 0) {
                        Note_SaveNote(channel, snapshotBytes, g_pakSaveSnapshot,
                                     RW_PAK_SNAPSHOT_TITLE, extension, RW_PAK_GAME_CODE);
                    }
                }
            }
            if (showPrompt != 0) {
                Menu_OpenDialog(g_matchEndingTeamWheelClose, pakSnapshotCapacityPrompt(), player,
                                (PakMenuSlot *)player->controller, menu->dialogData);
                return 0;
            }
        }
    }
    if (g_pakSnapshotResourceHandle != 0 || g_pakLoadedNoteResourceHandle != 0) Cache_DrainAndCompactResources(0);
    if (g_pakSnapshotResourceHandle != 0) Cache_ReleaseResource(0, g_pakSnapshotResourceHandle);
    if (g_pakLoadedNoteResourceHandle != 0) Cache_ReleaseResource(0, g_pakLoadedNoteResourceHandle);
    g_pakSnapshotResourceHandle = 0;
    g_pakLoadedNoteResourceHandle = 0;
    g_pakSaveSnapshot = 0;
    g_controllerPakSnapshotPayload = 0;
    return 1;
}
