#include "span_16E000/code_80405DC0.h"
#include "common/types_1dc8418c21db.h"
#include "types.h"

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

struct WorldNoteCount_func_80408870_de {
    char pad0[0x44];
    s32 count;
};

extern s32 D_8015375C;
extern s32 D_80153780;
extern char D_0044EAE0[];
extern char D_80145040[];
extern char D_8014561C[];
extern s32 D_80140FB4[];
extern s32 D_801462C8[];
extern s32 D_801462CC;
extern s32 D_8013B2D4;
extern u8 D_80146848;
extern f32 D_801468A0;
extern f32 D_801427E4;
extern f32 D_801427E8;
extern f32 D_801427EC;
extern char D_800F91F0[];
extern struct WorldNoteCount_func_80408870_de D_8011FE88;
extern struct PakLoadBlock_func_80408870_de *D_800E28BC;

extern s32 func_80406178_de(Menu_func_80409144_de *menu, s32 ch, s32 quiet);
extern s32 func_80404858_de(s32 ch, s32 index);
extern struct PakLoadOwner_func_80408870_de *func_8022A5C0_de(char *profiles, PakMenuSlot *slot);
extern void func_80442574_de(void *owner, char *message, void *player, void *slot, char *title);

s32 func_80408870_de(void *unused, Menu_func_80409144_de *menu) {
    struct PakLoadOwner_func_80408870_de *owner;
    struct WorldNoteCount_func_80408870_de *world;
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
        dst = D_801462C8;
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
        D_801468A0 = D_800E28BC->view8;
        D_801427E4 = D_800E28BC->viewC;
        indexWord = D_801462CC;
        D_801427E8 = D_800E28BC->view10;
        copied = 0;
        D_801427EC = D_800E28BC->view14;
        D_8013B2D4 = indexWord;
        D_80146848 = keepByte;
        if (world->count > 0) {
            noteSrc = &D_800E28BC->notes[0];
            noteDst = D_800F91F0;
            do {
                noteByte = *noteSrc;
                noteSrc = noteSrc + 1;
                copied = copied + 1;
                *noteDst = noteByte;
                noteDst = noteDst + 1;
            } while (copied < world->count);
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
