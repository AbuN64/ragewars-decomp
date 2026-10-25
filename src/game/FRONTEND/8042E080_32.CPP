#include "RESMGR/resmgr_string_memory.H"
#include "FRONTEND/PAKMENU.H"
#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/NAME.H"
#include "TYPES.H"
#include "FRONTEND/8042E080_53.H"

#if defined(VERSION_DE)
enum { PAK_LIST_FIELD = 748 };
#elif defined(VERSION_EU_X)
enum { PAK_LIST_FIELD = 752 };
#else
enum { PAK_LIST_FIELD = 726 };
#endif

/* Moves player p's list cursor in the block D_800E54A4 points to: direction 1 steps the cursor at
   0xAD8 of the player's 2920-byte record at 0x58 forward below 15 and scrolls the window at 0xADC
   so the cursor stays in the three visible rows (at most 13), any other direction steps both back
   while positive; then it sets the three row labels at 0xAE0 to alpha 0xFF with the texts of the
   70-byte name entries at 0x658 from the scroll position, and points item PAK_LIST_FIELD of the player's
   window at 0xC at the code at 0x3C of the entry under the cursor. */

extern MenuWidget *func_8040EC30_de(void *, s32);

void func_80434250_de(s32 player, s32 direction) {
    s32 i;
    s32 cursor;

    if (direction == 1) {
        if (D_800E54A4->players[player].slot < 15) {
            D_800E54A4->players[player].slot++;
            if (D_800E54A4->players[player].slot >= D_800E54A4->players[player].scroll + 3) {
                if (D_800E54A4->players[player].scroll + 3 < 15) {
                    D_800E54A4->players[player].scroll++;
                } else {
                    D_800E54A4->players[player].scroll = 13;
                }
            }
        }
    } else if (D_800E54A4->players[player].slot > 0) {
        D_800E54A4->players[player].slot--;
        if (D_800E54A4->players[player].scroll > 0 &&
            D_800E54A4->players[player].slot - D_800E54A4->players[player].scroll < 0) {
            D_800E54A4->players[player].scroll--;
        }
    }
    for (i = 0; i < 3; i++) {
        D_800E54A4->players[player].labels[i]->alpha = 0xFF;
        D_800E54A4->players[player].labels[i]->text =
            D_800E54A4->players[player].displayNames[D_800E54A4->players[player].scroll + i].text;
    }
    cursor = D_800E54A4->players[player].slot;
    func_8040EC30_de(D_800E54A4->players[player].menuWidget, PAK_LIST_FIELD)->text =
        D_800E54A4->players[player].displayNames[cursor].code;
}

#include "COMMON/NAME.H"
#include "COMMON/PAK_SAVE_TEXT.H"
#include "MENU/PAK/pak_note_search.H"
extern s32 Pak_DeleteNote(s32, s32);
extern s32 Pak_GetFreePages(s32, s32 *);
extern s32 Pak_CountFreeNotes(s32, s32 *);
extern s32 Frontend_GetRecordsNoteSize(void);
extern s32 Ovlgame_BytesToPakPages(s32);
extern s32 Ovlgame_FindFreeNoteExtension(s32, char *);
extern u32 Ovlgame_Crc32(void *, u32, u32);
extern char *Resmgr_CopyString(char *, char *);
extern s32 Pak_SaveNote(s32, s32, void *, char *, char *, char *);
extern void Frontend_RefreshPlayerPanel(s32);
/* The save view of the menu block: the four player records staged at 0x2E28, then the profile and
 * checksum stored behind them, written to the pak as one 0x648-byte note. */
static __inline__ PakMenuController *pakRecordSave(void) {
    return D_800E54A4;
}
/* The note's game code is read through the settings view in the PAL releases. */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#define RECORDS_NOTE_CODE (D_800E25D4[rw_pak_settings()->language])
#else
#define RECORDS_NOTE_CODE RW_PAK_GAME_CODE
#endif
/* Replace or create the selected port's four-profile Controller Pak note: delete the old note if
 * there is one, else check that a free note and enough pages exist; then stage the port's records,
 * profile and CRC and save them. On failure the port's panel goes back to state 2. */
s32 Frontend_SavePlayerRecords(s32 channel)
{
    char extension[8];
    char name[16];
    struct { s32 note, fits, freePages, freeNotes; } space;
    s32 status, required;
    Profile *staged, *data;
    s32 i;
    u32 checksum;
    s32 success = 0;
    if (Pak_FindNoteByName(rw_pak_save_name(), channel, &space.note) == 1) {
        success = Pak_DeleteNote(channel, space.note) == 0;
    } else {
        space.fits = 0;
        status = Pak_GetFreePages(channel, &space.freePages);
        if (status == 0) {
            status = Pak_CountFreeNotes(channel, &space.freeNotes);
            if (status == 0) {
                required = Ovlgame_BytesToPakPages(Frontend_GetRecordsNoteSize());
                if (space.freeNotes == 0 || space.freePages < required) space.fits = 0;
                else space.fits = 1;
            }
        }
        /* Dead store kept from the original: flow deletes it, but it stops jump threading of
         * the two status tests above into the one below (ROM keeps both branches). */
        required = 0;
        if (status == 0 && space.fits == 1) success = 1;
    }
    if (success == 1) {
        success = 0;
        if (Ovlgame_FindFreeNoteExtension(channel, extension) == 0) {
            staged = pakRecordSave()->packet.saved;
            Resmgr_CopyBytes(staged, pakRecordSave()->players[channel].records, 0x640);
            pakRecordSave()->packet.savedProfile = pakRecordSave()->players[channel].profile;
            checksum = Ovlgame_Crc32(staged, 0x640, 7);
            pakRecordSave()->packet.checksum = checksum;
            data = pakRecordSave()->packet.saved;
            for (i = 0; i < 16; i++) name[i] = 0;
            Resmgr_CopyString(name, RW_PAK_RECORD_TITLE);
            if (Pak_SaveNote(channel, 0x648, data, name, extension, RECORDS_NOTE_CODE) == 0) success = 1;
        }
    }
    if (!success) {
        pakRecordSave()->players[channel].back = 2;
        pakRecordSave()->players[channel].state = 2;
        Frontend_RefreshPlayerPanel(channel);
    }
    return success;
}
