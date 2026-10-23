#include "COMMON/WORLD.H"
#include "include_asm.h"
#include "COMMON/MENURECAT24.H"
#include "MENU/80405DC0.H"

#ifdef NON_MATCHING
#include "COMMON/MENURECAT24.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"

/* Reloads a saved controller-pak block when func_80406178_de reports no problem for the selected
   channel: with D_80153780 set it loads the block D_800E28BC points to onto the player found at
   D_80145040 - the 0x18 Block70 into the player's 0x5E0 block, the 352 words at 0x88 into the option
   block D_801462C8 plus the word at its 0x580 (keeping the byte D_80146848 there), the four floats at
   0x8 into D_801468A0, D_801427E4, D_801427E8 and D_801427EC, the word at D_8011FE88+0x44 as a byte
   count for the block at 0x60C copied into D_800F91F0 - then shows the D_0044EAE0 prompt through
   func_80442574_de; otherwise it retries func_80404858_de on note D_8014D4FC and shows the
   D_0044EB70/D_0044EBDC result. func_80409144_de's state 4 flow with the load path added; returns 1. */

struct PakLoadBlock_func_80408870_de {
    char pad0[0x8];
    f32 view8;
    f32 viewC;
    f32 view10;
    f32 view14;
    Block70 block18;
    s32 gameWords[353];
    u8 notes[0x1000];
};

struct PakLoadOwner_func_80408870_de {
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
extern s32 D_801462CC;
extern s32 D_8013B2D4;
extern u8 D_80146848;
extern f32 D_801427E4;
extern f32 D_801427E8;
extern f32 D_801427EC;
extern char D_800F91F0[];
extern struct PakLoadBlock_func_80408870_de *D_800E28BC;

extern s32 func_80406178_de(MenuRecAt24 *menu, s32 ch, s32 quiet);
extern s32 func_80404858_de(s32 ch, s32 index);
extern struct PakLoadOwner_func_80408870_de *func_8022A5C0_de(char *profiles, PakMenuSlot *slot);
extern void func_80442574_de(void *owner, char *message, void *player, void *slot, char *title);

s32 func_80408870_de(void *unused, MenuRecAt24 *menu) {
    struct PakLoadOwner_func_80408870_de *owner;
    Shared_World *world;
    s32 channel;
    s32 indexWord;
    u8 keepByte;
    s32 *src;
    s32 *stop;
    s32 *dst;
    s32 w0;
    s32 w1;
    s32 w2;
    s32 w3;
    u8 *noteSrc;
    u8 *noteDst;
    u8 noteByte;
    s32 copied;
    void *callOwner;
    char *message;
    void *callPlayer;
    void *callSlot;
    char *callTitle;

    if (D_8015375C != 0) {
        channel = D_800E28C8;
    } else {
        channel = menu->slot->unk4;
    }
    if (func_80406178_de(menu, channel, 0) != 0) {
        D_80153784 = 1;
        return 1;
    }
    if (D_80153780 != 0) {
        owner = func_8022A5C0_de(D_80145040, menu->slot);
        world = &D_8011FE88;
        keepByte = D_80146848;
        src = D_800E28BC->block18.w;
        stop = &D_800E28BC->block18.w[28];
        dst = owner->block.w;
        while (src != stop) {
            w0 = src[0];
            w1 = src[1];
            w2 = src[2];
            w3 = src[3];
            dst[0] = w0;
            dst[1] = w1;
            dst[2] = w2;
            dst[3] = w3;
            src = src + 4;
            dst = dst + 4;
        }
        src = D_800E28BC->gameWords;
        stop = &D_800E28BC->gameWords[352];
        dst = (s32 *)&D_801462C8;
        while (src != stop) {
            w0 = src[0];
            w1 = src[1];
            w2 = src[2];
            w3 = src[3];
            dst[0] = w0;
            dst[1] = w1;
            dst[2] = w2;
            dst[3] = w3;
            src = src + 4;
            dst = dst + 4;
        }
        *dst = *src;
        D_801462C8.counters.ticks = D_800E28BC->view8;
        D_801427E4 = D_800E28BC->viewC;
        indexWord = D_801462CC;
        D_801427E8 = D_800E28BC->view10;
        copied = 0;
        D_801427EC = D_800E28BC->view14;
        D_8013B2D4 = indexWord;
        D_80146848 = keepByte;
        if (world->noteCount > 0) {
            noteSrc = &D_800E28BC->notes[0];
            noteDst = D_800F91F0;
            do {
                noteByte = *noteSrc;
                noteSrc = noteSrc + 1;
                copied = copied + 1;
                *noteDst = noteByte;
                noteDst = noteDst + 1;
            } while (copied < world->noteCount);
        }
        D_80140FB4[0] = 0;
        D_80140FB4[1] = 0;
        callOwner = D_80140FB4 + 0x16A;
        message = D_0044EAE0;
        callPlayer = owner;
        callSlot = owner->slot698;
        callTitle = 0;
    } else {
        if (func_80404858_de(channel, D_8014D4FC) == 0) {
            message = D_0044EB70;
        } else {
            message = D_0044EBDC;
        }
        callOwner = D_8014561C;
        callPlayer = menu->player;
        callSlot = menu->slot;
        callTitle = menu->prompt;
    }
    func_80442574_de(callOwner, message, callPlayer, callSlot, callTitle);
    return 1;
}
#else
INCLUDE_ASM("ovl_80400000", func_80408870_de);
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* Writes the 11-character rank title for the score D_8014D48C into the end of the item's text:
   the title comes from the band the score falls in (below 50, 150, 300, 500, 800, 1300, 2000,
   3000, 4500, 6500 and 9999 and above), and the text position is the text length from
   func_80441FE8_de minus 11; returns 0. */
#include "TYPES.H"



extern u16 D_8014D48C;

























extern s32 func_80441FE8_de(void);

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
    dest += func_80441FE8_de() - 11;
    if (title != 0) {
        for (i = 0; i < 11; i++) {
            *dest++ = *title++;
        }
    }
    return 0;
}
#endif
