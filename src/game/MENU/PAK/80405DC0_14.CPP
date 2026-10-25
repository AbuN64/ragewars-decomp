#include "COMMON/WORLD.H"
#include "include_asm.h"
#include "COMMON/MENURECAT24.H"
#include "MENU/80405DC0.H"

#include "COMMON/MENURECAT24.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"

/* Reloads a saved controller-pak block when Pak_CheckStatusPrompt reports no problem for the selected
   channel: with D_80153780 set it loads the block D_800E28BC points to onto the player found at
   D_80145040 - the 0x18 Block70 into the player's 0x5E0 block, the 352 words at 0x88 into the option
   block D_801462C8 plus the word at its 0x580 (keeping the byte D_80146848 there), the four floats at
   0x8 (the game clock) into D_801468A0, D_801427E4, D_801427E8 and D_801427EC, the word at D_8011FE88+0x44 as a byte
   count for the block at 0x60C copied into D_800F91F0 - then shows the D_0044EAE0 prompt through
   Pak_OpenDialog; otherwise it retries Pak_DeleteNote on note D_8014D4FC and shows the
   D_0044EB70/D_0044EBDC result. func_80409144_de's state 4 flow with the load path added; returns 1. */

/* The persistent options block: the first 0x584 bytes of Shared_Game (D_801462C8). */
typedef struct PakSavedOptions {
    s32 words[353];
} PakSavedOptions;

struct PakSaveBlock {
    char pad0[0x8];
    f32 ticks; /* the saved game clock, restored into D_801462C8.counters */
    f32 seconds;
    f32 minutes;
    f32 hours;
    Block70 block18;
    PakSavedOptions options;
    u8 notes[0x1000];
};

struct PakSaveOwner {
    char pad0[0x5E0];
    Block70 block;
    char pad650[0x698 - 0x650];
    void *slot698;
};

extern s32 D_8015375C;
extern s32 D_80153780;
extern char D_0044EAE0[];
extern char D_80145040[];
extern char D_8014561C[];
extern s32 D_80140FB4[];
extern s32 D_8013B2D4;
extern u8 D_80146848[]; /* D_801462C8+0x580, kept across the options reload */
/* The ROM stores the clock's seconds/minutes/hours through three separate objects (no shared base
   register, each store ordered after the block load), not through D_801462C8.counters. */
extern f32 D_801427E4[];
extern f32 D_801427E8[];
extern f32 D_801427EC[];
extern u8 D_800F91F0[];
extern struct PakSaveBlock *D_800E28BC;

extern s32 Pak_CheckStatusPrompt(MenuRecAt24 *menu, s32 ch, s32 quiet);
extern s32 Pak_DeleteNote(s32 ch, s32 index);
extern struct PakSaveOwner *Weapons_FindPlayerByController(char *profiles, PakMenuSlot *slot);
extern void Pak_OpenDialog(void *owner, char *message, void *player, void *slot, char *title);

extern s32 D_801462CC; /* MIXED Pak_RestoreSaveBlock */
s32 Pak_RestoreSaveBlock(void *unused, MenuRecAt24 *menu) {
    struct PakSaveOwner *owner;
    s32 channel;
    Shared_World *world;
    u8 kept;
    u8 *src;
    u8 *dst;
    s32 i;

    if (D_8015375C != 0) {
        channel = D_800E28C8;
    } else {
        channel = menu->slot->unk4;
    }
    if (Pak_CheckStatusPrompt(menu, channel, 0) != 0) {
        D_80153784 = 1;
        return 1;
    }
    if (D_80153780 != 0) {
        owner = Weapons_FindPlayerByController(D_80145040, menu->slot);
        world = &D_8011FE88;
        kept = D_80146848[0];
        owner->block = D_800E28BC->block18;
        *(PakSavedOptions *)&D_801462C8 = D_800E28BC->options;
        D_801462C8.counters.m_GameTimeFifteenth = D_800E28BC->ticks;
        D_801427E4[0] = D_800E28BC->seconds;
        D_801427E8[0] = D_800E28BC->minutes;
        D_801427EC[0] = D_800E28BC->hours;
        D_8013B2D4 = D_801462CC;
        D_80146848[0] = kept;
        src = D_800E28BC->notes;
        dst = D_800F91F0;
        for (i = 0; i < world->noteCount; i++) {
            *dst++ = *src++;
        }
        D_80140FB4[0] = 0;
        D_80140FB4[1] = 0;
        Pak_OpenDialog(&D_80140FB4[0x16A], D_0044EAE0, owner, owner->slot698, 0);
    } else if (Pak_DeleteNote(channel, D_8014D4FC) == 0) {
        Pak_OpenDialog(D_8014561C, D_0044EB70, menu->player, menu->slot, menu->prompt);
    } else {
        Pak_OpenDialog(D_8014561C, D_0044EBDC, menu->player, menu->slot, menu->prompt);
    }
    return 1;
}

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* Writes the 11-character rank title for the score D_8014D48C into the end of the item's text:
   the title comes from the band the score falls in (below 50, 150, 300, 500, 800, 1300, 2000,
   3000, 4500, 6500 and 9999 and above), and the text position is the text length from
   Pak_CountLineChars minus 11; returns 0. */
#include "TYPES.H"



extern u16 D_8014D48C;

























extern s32 Pak_CountLineChars(void);

s32 func_80408AC4_us(PakNoteTextEntry *item) {
    char *title;
    u8 *dest;
    s32 i;
    s32 score;

    title = 0;
    score = D_8014D48C;
    if (D_8014D48C < 50) {
        title = D_800D241C;
    } else if (score >= 50 && score < 150) {
        title = D_800D2420;
    } else if (score >= 150 && score < 300) {
        title = D_800D2424;
    } else if (score >= 300 && score < 500) {
        title = D_800D2428;
    } else if (score >= 500 && score < 800) {
        title = D_800D242C;
    } else if (score >= 800 && score < 1300) {
        title = D_800D2430;
    } else if (score >= 1300 && score < 2000) {
        title = D_800D2434;
    } else if (score >= 2000 && score < 3000) {
        title = D_800D2438;
    } else if (score >= 3000 && score < 4500) {
        title = D_800D243C;
    } else if (score >= 4500 && score < 6500) {
        title = D_800D2440;
    } else if (score >= 6500 && score < 9999) {
        title = D_800D2444;
    } else if (score >= 9999) {
        title = D_800D2448;
    }
    dest = *item->text;
    dest += Pak_CountLineChars() - 11;
    if (title != 0) {
        for (i = 0; i < 11; i++) {
            *dest++ = *title++;
        }
    }
    return 0;
}
#endif
