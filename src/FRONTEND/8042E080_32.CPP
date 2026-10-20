#include "RESMGR/resmgr_string_memory.H"
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

extern PakMenuController *D_800E54A4;
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

#ifdef NON_MATCHING
#include "COMMON/NAME.H"
#include "COMMON/PAK_SAVE_TEXT.H"
extern struct Block_func_804347CC_de *D_800E54A4;
extern s32 func_80404BE8_de(char *, s32, s32 *);
extern s32 func_80404858_de(s32, s32);
extern s32 func_80405160_de(s32, s32 *);
extern s32 func_804050CC_de(s32, s32 *);
extern s32 func_80435424_de(void);
extern s32 func_804057EC_de(s32);
extern s32 func_80405454_de(s32, char *);
extern u32 func_804057F8_de(void *, u32, u32);
extern char *func_802A025C_de(char *, char *);
extern s32 func_80404958_de(s32, s32, void *, char *, char *, char *);
extern void func_804322AC_de(s32);
/* Replace or create the selected port's four-profile Controller Pak note. */
s32 func_80434428_de(s32 channel)
{
    char extension[8];
    char name[16];
    s32 note, bytes, slots, status, required, i;
    s32 success = 0;
    status = func_80404BE8_de(rw_pak_save_name(), channel, &note);
    if (status == 1) {
        success = func_80404858_de(channel, note) == 0;
    } else {
        status = func_80405160_de(channel, &bytes);
        if (status == 0) {
            status = func_804050CC_de(channel, &slots);
            if (status == 0) {
                required = func_804057EC_de(func_80435424_de());
                success = slots != 0 && bytes >= required;
            }
        }
    }
    if (success) {
        success = 0;
        if (func_80405454_de(channel, extension) == 0) {
            Resmgr_CopyBytes(D_800E54A4->saved, D_800E54A4->players[channel].records, 0x640);
            D_800E54A4->savedProfile = D_800E54A4->players[channel].profile;
            D_800E54A4->checksum = func_804057F8_de(D_800E54A4->saved, 0x640, 7);
            for (i = 15; i >= 0; i--) name[i] = 0;
            func_802A025C_de(name, rw_pak_save_name());
            success = func_80404958_de(channel, 0x648, D_800E54A4->saved,
                                       name, extension, rw_pak_save_code()) == 0;
        }
    }
    if (!success) {
        D_800E54A4->players[channel].back = 2;
        D_800E54A4->players[channel].state = 2;
        func_804322AC_de(channel);
    }
    return success;
}
#else
INCLUDE_ASM("ovl_80400000", func_80434428_de);
#endif
