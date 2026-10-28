#include "include_asm.h"
#include "COMMON/LONE/D_0044ED44.H"
#include "COMMON/PAK_MENU.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RECORDRECAT1C.H"
#include "COMMON/MENURECAT24.H"
#include "TYPES.H"

/* Enters pak menu mode 2: sets the mode flags, shows the D_0044FFA4 prompt when a message is pending (D_800E28C0), and otherwise clears the owner's 0x01000000 flag, probes the Controller Pak on the selected channel, falls back to Pak_MarkSaveNotes when Pak_GetStatus reports none, and shows the D_0044EA2C, D_0044ED44 or D_0044E9C0 prompt according to func_80404F3C_de and Note_NeedsIdRepair. */











extern s32 D_8015375C;
extern s32 D_800E28C0;
extern char D_8014561C[];
extern char D_0044FFA4[];
extern unsigned char D_0044E4B0[];
extern char D_0044EA2C[];
extern char D_0044E9C0[];
extern void Pak_ProbeStatus(s32 ch);
extern s32 Pak_GetStatus(s32 ch);
extern s32 Note_IsChannelReady(s32 ch);
extern s32 Note_NeedsIdRepair(s32 ch);
extern void Menu_OpenDialog(char *, char *, ObjRecAt5DC *, PakMenuSlot *, char *);
void Snapshot_BeginBlockLoad(Shared_PakMenu *menu)
{
  Shared_PakMenu *new_var3;
  int new_var;
  char *new_var2;
  s32 ch;
  new_var = 1;
  D_800DE874 = 2;
  D_8014D4C0_de = 0;
  D_8014D4DC = 0;
  D_80153760 = new_var;
  D_8014D4EC_de = 0;
  D_80153784 = 0;
  D_8015375C = 0;
  ch = menu->slot->unk4;
  if (D_800E28C0 != 0)
  {
    D_80153784 = 1;
    Menu_OpenDialog(D_8014561C, D_0044FFA4, menu->player, menu->slot, 0);
    return;
  }
  menu->items[20].flags &= ~0x01000000;
  Pak_ProbeStatus(menu->slot->unk4);
  new_var = 0;
  if (Pak_GetStatus(ch) == new_var)
  {
    Pak_MarkSaveNotes(menu);
    return;
  }
  D_80153784 = 1;
  if (Note_IsChannelReady(ch) != new_var)
  {
    new_var2 = D_0044EA2C;
    Menu_OpenDialog(D_8014561C, new_var2, menu->player, menu->slot, (char *) 1);
  }
  else
  {
    new_var3 = menu;
    if (Note_NeedsIdRepair(ch) != 0)
    {
      Menu_OpenDialog(D_8014561C, D_0044ED44, new_var3->player, menu->slot, D_0044E4B0);
    }
    else
    {
      Menu_OpenDialog(D_8014561C, D_0044E9C0, new_var3->player, new_var3->slot, D_0044FFA4);
    }
  }
}

#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PAK_SAVE_TEXT.H"
#include "MENU/PAK/SAVE_SNAPSHOT.H"
extern void Cache_ReleaseResource(s32, void *);
extern void *D_800DE860_de;
extern struct Shape_typemap_165 *D_800DE864_de;
extern s32 D_800E28BC;
extern char D_80153738[];
extern char D_8014561C[];
extern char D_00450BF0_de[];
extern char D_00450C14_de[];
extern char D_00450C38_de[];
extern char D_00450C5C_de[];
extern s32 Note_BytesToPakPages(s32);
extern s32 Note_GetFreePages(s32, s32 *);
extern s32 Note_CountFreeNotes(s32, s32 *);
extern s32 Note_FindFreeNoteExtension(s32, char *);
extern s32 Note_SaveNote(s32, s32, void *, char *, char *, char *);
extern void func_80253908_de(s32);
/* Save the small controller-pak record when capacity allows, release the
 * pending resources, and show the channel-specific success/error dialog. */
static inline ObjRecAt5DC *pakRecordChannel(Shared_PakMenu *menu, s32 *channel) {
    if (D_8015375C != 0) {
        *channel = D_800E28C8;
        return 0;
    }
    *channel = menu->owner->unk4;
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
    ObjRecAt5DC *player, *selectedPlayer;
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
                        status = Note_SaveNote(channel, 0x18, D_80153738,
                                              RW_PAK_RECORD_TITLE, extension, RW_PAK_GAME_CODE);
                    }
                }
            }
            if (insufficient != 0) {
                Menu_OpenDialog(D_8014561C, rw_pak_no_space_dialog(), player,
                                (PakMenuSlot *)player->controller, menu->dialogData);
                return 0;
            }
        }
    }
    if (D_800DE860_de != 0 || D_800DE864_de != 0) func_80253908_de(0);
    if (D_800DE860_de != 0) Cache_ReleaseResource(0, D_800DE860_de);
    if (D_800DE864_de != 0) Cache_ReleaseResource(0, D_800DE864_de);
    D_800DE860_de = 0;
    D_800DE864_de = 0;
    D_800DE868 = 0;
    D_800E28BC = 0;
    if (!attempted) return 1;
    if (status == 0) {
        Menu_OpenDialog(D_8014561C, rw_pak_save_success_dialog(), player,
                        (PakMenuSlot *)player->controller, pakRecordChannelLabel(channel));
    } else {
        Menu_OpenDialog(D_8014561C, rw_pak_save_error_dialog(), player,
                        (PakMenuSlot *)player->controller, pakRecordChannelLabel(channel));
    }
    return 1;
}

extern u32 D_8011FECC;
extern char D_0044FAFC[];
/* The capacity prompt is per release. */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern char D_0045017C[];
static inline char *pakSnapshotCapacityPrompt(void) { return D_0045017C; }
#else
#if defined(VERSION_US_REV1)
static inline char *pakSnapshotCapacityPrompt(void) { return D_0044FAFC; }
#elif defined(VERSION_US)
extern char D_0044F01C[];
static inline char *pakSnapshotCapacityPrompt(void) { return D_0044F01C; }
#else
extern char D_0044EEAC[];
static inline char *pakSnapshotCapacityPrompt(void) { return D_0044EEAC; }
#endif
#endif
/* Save the snapshot only when both page and note capacity are available;
 * retain pending resources while showing the insufficient-capacity prompt. */
s32 Snapshot_SaveSnapshotAndClose(void *unused, Shared_PakMenu *menu) {
    ObjRecAt5DC *player, *selectedPlayer;
    char extension[8];
    s32 channel, freePages, freeNotes;
    s32 snapshotBytes, required, status;
    s32 showPrompt = 1;
    selectedPlayer = pakRecordChannel(menu, &channel);
    player = selectedPlayer;
    snapshotBytes = D_8011FECC + sizeof(SaveSnapshot);
    if (D_8014D4C0_de != 0) {
        required = Note_BytesToPakPages(snapshotBytes);
        status = Note_GetFreePages(channel, &freePages);
        if (status == 0) {
            if (required <= freePages) {
                if (Note_CountFreeNotes(channel, &freeNotes) == 0 && freeNotes != 0) {
                    showPrompt = 0;
                    if (Note_FindFreeNoteExtension(channel, extension) == 0) {
                        Note_SaveNote(channel, snapshotBytes, D_800DE868,
                                     RW_PAK_SNAPSHOT_TITLE, extension, RW_PAK_GAME_CODE);
                    }
                }
            }
            if (showPrompt != 0) {
                Menu_OpenDialog(D_8014561C, pakSnapshotCapacityPrompt(), player,
                                (PakMenuSlot *)player->controller, menu->dialogData);
                return 0;
            }
        }
    }
    if (D_800DE860_de != 0 || D_800DE864_de != 0) func_80253908_de(0);
    if (D_800DE860_de != 0) Cache_ReleaseResource(0, D_800DE860_de);
    if (D_800DE864_de != 0) Cache_ReleaseResource(0, D_800DE864_de);
    D_800DE860_de = 0;
    D_800DE864_de = 0;
    D_800DE868 = 0;
    D_800E28BC = 0;
    return 1;
}
