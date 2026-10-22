#include "include_asm.h"
#include "COMMON/WORLD.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ACTIVE.H"
#include "TYPES.H"
#include "FRONTEND/8042E080_25.H"
#include "RESMGR/802A0888.H"
#include "RENDER_2/8025DE50_5.H"

/* Returns 0xBC2 plus ten times either the halfword at offset 2 of what func_8028D474_de finds for
   D_8015402C in D_8011FE88, when the option byte D_801462D5 is one, or D_8015402C itself. */


extern u8 D_801462D5;
extern s32 D_8015402C;

extern struct StateFlags *func_8028D474_de(void *, s32);

s32 func_8042EE34_de(void) {
    return (D_801462D5 == 1 ? func_8028D474_de(&D_8011FE88, D_8015402C)->flags : D_8015402C) * 10 + 0xBC2;
}

extern struct Status D_80146398[];

extern s32 func_802744D4_de(void);

/* Draws a random item type from 0 to 10, redrawing types 0 and 5 while any of the eight active players already holds that type, and returns it. */
s32 func_8042EE94_de(void) {
    s32 type;
    s32 free;
    s32 i;
    s32 excl; /* FAKEMATCH: constant-holding local places the li of 5 */
    struct Status *players; /* FAKEMATCH: copy-only local, set inside the draw loop, steers the base register */

    do {
        type = func_802744D4_de() % 11;
        excl = 5;
        players = D_80146398;
        do {
            free = 1;
        } while (0);
        if (type == 0 || type == excl) {
            for (i = 0; i < 8; i++) {
                if (players[i].active != 0 && players[i].kind == type) {
                    free = 0;
                }
            }
        }
    } while (free == 0);
    return type;
}

#if defined(VERSION_US_REV1)
#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"

/* Creates the match setup block D_800E54A4 for screen arg0: allocates and clears it, loads its sprites and centres the two banner rows, links every player slot, shows the header for the game mode, resets each player's menu state, records and name entries, then starts each player in the state the mode needs (team handoff for mode 5, memory-card check for mode 6, the host for mode 7) and starts the menu music. Returns zero. */


typedef struct PakSetupRecord {
    char pad0[0x190];
} PakSetupRecord;

typedef struct PakSetupName {
    char pad0[0x28];
    u8 code[0x14];
    u8 text[0xA];
} PakSetupName;

typedef struct PakSetupPlayer {
    s32 state;
    s32 sub;
    s32 next;
    s32 menu;
    MenuWidget *sprite;
    s32 back;
    PakSetupRecord records[4];
    PakSetupName names[16];
    u8 codes[3][0xA];
    char padAD6[0xAD8 - 0xAD6];
    s32 slot;
    char padADC[0xAEC - 0xADC];
    s32 choice;
    s32 used[4];
    s32 notes[4];
    char padB10[0xB28 - 0xB10];
    s32 port;
    s32 record;
    s32 host;
    char padB34[0xB64 - 0xB34];
    s32 profile;
} PakSetupPlayer;

typedef struct PakSetupLink {
    s32 player;
    s32 slot;
    s32 state;
} PakSetupLink;

typedef struct PakSetupState {
    void *screen;
    void *menu;
    char setup[0x24 - 0x8];
    void *music;
    MenuWidget *title;
    s32 counts[4];
    MenuWidget *top;
    s32 topStep;
    MenuWidget *bottom;
    s32 bottomStep;
    s32 ready;
    s32 slots;
    s32 mode;
    PakSetupPlayer players[4];
    PakSetupLink links[4];
    char pad2E28[0x3470 - 0x2E28];
    s32 focus;
} PakSetupState;

typedef struct PakSetupProfile {
    char pad0[0xD];
    s8 owner;
    s8 dropped;
    char padF[0x190 - 0xF];
} PakSetupProfile;

typedef struct PakSetupStatus {
    char pad0[0x78];
    u8 active;
    char pad79[0x91 - 0x79];
    u8 out;
    char pad92[0x96 - 0x92];
} PakSetupStatus;

typedef struct PakSetupGame {
    char pad0[0xD0];
    PakSetupStatus status[8];
} PakSetupGame;

extern PakSetupState *D_800E54A4;
extern s32 D_800E54A0;
extern s32 D_800DF4C0;
extern s32 D_800DF4C4;
extern PakSetupProfile D_80102B00[];
extern PakSetupGame D_801462C8;

extern void *func_8025305C_de(s32);
extern void func_8043C210_de(void *, s32, s32, s32, s32);
extern void *func_8041B610_de(void *, s32);
extern void func_8041B6E8_de(void *, s32, s32);
extern MenuWidget *func_8040EC30_de(void *, s32);
extern void func_8040E8D8_de(MenuWidget *, s32);
extern void *func_80419E54_de(s32, s32);
extern void func_80433BCC_de(s32);
extern void func_804322AC_de(s32);
extern void func_80264770_de(s32);
extern void func_8022EF30_de(PakSetupRecord *);
extern void func_80404E28_de(s32);
extern s32 func_80404F04_de(s32);
extern void func_8040C428_de(s32);
extern void func_802A2394_de(void);
extern void func_802A2418_de(s32);

s32 func_8042F12C_us_rev1(void *screen) {
    PakSetupState *block;
    PakSetupGame *globals;
    MenuWidget *sprite;
    MenuWidget *row;
    s32 rest;
    s32 i;
    s32 j;

    block = func_8025305C_de(sizeof(PakSetupState));
    D_800E54A4 = block;
    block->screen = screen;
    func_8043C210_de(block->setup, 0x67, 0, 0, 0);
    D_800E54A4->menu = func_8041B610_de(screen, 4);
    func_8041B6E8_de(screen, 0, 0x285);
    func_8041B6E8_de(screen, 1, 0x285);
    func_8041B6E8_de(screen, 2, 0x285);
    func_8041B6E8_de(screen, 3, 0x285);
    for (i = 0; i < 4; i++) {
        D_800E54A4->counts[i] = 0;
    }
    D_800E54A4->ready = 1;
    D_800E54A4->slots = 4;
    D_800E54A4->top = func_8040EC30_de(screen, 0x2FB);
    D_800E54A4->top->x -= D_800E54A4->top->w;
    D_800E54A4->topStep = D_800E54A4->top->w / 4;
    rest = D_800E54A4->top->w - D_800E54A4->topStep * 4;
    D_800E54A4->top->x += rest;
    D_800E54A4->bottom = func_8040EC30_de(screen, 0x2A2);
    D_800E54A4->bottom->x += D_800E54A4->bottom->w;
    D_800E54A4->bottomStep = D_800E54A4->bottom->w / 4;
    rest = D_800E54A4->bottom->w - D_800E54A4->bottomStep * 4;
    D_800E54A4->bottom->x -= rest;
    func_8040EC30_de(screen, 0x286)->alpha = 0x6E;
    D_800E54A4->music = func_80419E54_de(0x287, 0xFF);
    D_800E54A4->title = func_8040EC30_de(screen, 0x287);
    func_8040E8D8_de(D_800E54A4->title, 0);
    D_800E54A4->players[0].sprite = func_8040EC30_de(screen, 0x2FC);
    D_800E54A4->players[1].sprite = func_8040EC30_de(screen, 0x2A3);
    D_800E54A4->players[2].sprite = func_8040EC30_de(screen, 0x2FD);
    D_800E54A4->players[3].sprite = func_8040EC30_de(screen, 0x2FA);
    D_800E54A4->mode = D_800E54A0;
    for (i = 0; i < 4; i++) {
        D_800E54A4->links[i].player = -1;
        D_800E54A4->links[i].slot = 0;
        D_800E54A4->links[i].state = 2;
    }
    switch (D_800E54A4->mode) {
    case 5:
        sprite = func_8040EC30_de(screen, 0x293);
        func_8040E8D8_de(sprite, 1);
        sprite->alpha = 0xFF;
        break;
    case 6:
        sprite = func_8040EC30_de(screen, 0x296);
        func_8040E8D8_de(sprite, 1);
        sprite->alpha = 0xFF;
        break;
    case 4:
        sprite = func_8040EC30_de(screen, 0x288);
        func_8040E8D8_de(sprite, 1);
        sprite->alpha = 0xFF;
        break;
    case 0:
        sprite = func_8040EC30_de(screen, 0x2A1);
        func_8040E8D8_de(sprite, 1);
        sprite->alpha = 0xFF;
        break;
    case 3:
        sprite = func_8040EC30_de(screen, 0x295);
        func_8040E8D8_de(sprite, 1);
        sprite->alpha = 0xFF;
        break;
    case 1:
        sprite = func_8040EC30_de(screen, 0x289);
        func_8040E8D8_de(sprite, 1);
        sprite->alpha = 0xFF;
        for (i = 0; i < 4; i++) {
            if (D_80102B00[i].owner >= 0) {
                if (D_80102B00[i].dropped == 1) {
                    D_80102B00[i].owner = -1;
                    D_80102B00[i].dropped = 0;
                }
                if (D_80102B00[i].owner >= 0) {
                    D_800E54A4->links[i].player = 0;
                    D_800E54A4->links[i].slot = i;
                    D_800E54A4->links[i].state = 1;
                }
            }
        }
        func_80433BCC_de(-1);
        break;
    case 7:
        break;
    case 2:
        sprite = func_8040EC30_de(screen, 0x297);
        func_8040E8D8_de(sprite, 1);
        sprite->alpha = 0xFF;
        break;
    }
    for (i = 0; i < 4; i++) {
        D_800E54A4->players[i].state = 0;
        D_800E54A4->players[i].menu = 0;
        D_800E54A4->players[i].back = -1;
        func_804322AC_de(i);
        func_80264770_de(i);
        for (j = 0; j < 4; j++) {
            func_8022EF30_de(&D_800E54A4->players[i].records[j]);
        }
        for (j = 0; j < 16; j++) {
            func_802A001C_de(D_800E54A4->players[i].names[j].code, 0, 0x14);
            func_802A001C_de(D_800E54A4->players[i].names[j].text, 0, 0xA);
        }
        func_802A001C_de(D_800E54A4->players[i].codes[2], 0, 0xA);
        func_802A001C_de(D_800E54A4->players[i].codes[1], 0, 0xA);
        func_802A001C_de(D_800E54A4->players[i].codes[0], 0, 0xA);
        D_800E54A4->players[i].slot = 0;
        D_800E54A4->players[i].choice = 0;
        for (j = 0; j < 4; j++) {
            D_800E54A4->players[i].used[j] = 2;
            D_800E54A4->players[i].notes[j] = 0;
        }
        D_800E54A4->players[i].record = 0;
        D_800E54A4->players[i].host = 0;
        D_800E54A4->players[i].profile = 0;
        D_800E54A4->players[i].sub = 0;
        D_800E54A4->players[i].next = -1;
        D_800E54A4->players[i].port = -1;
    }
    D_800E54A4->focus = -1;
    switch (D_800E54A4->mode) {
    case 5:
        for (i = 0; i < 4; i++) {
            D_800E54A4->players[i].state = 0xE;
        }
        for (i = 0; i < 4; i++) {
            globals = &D_801462C8;
            if (D_80102B00[i].dropped == 0 && D_80102B00[i].owner >= 0 && globals->status[i].active == 1 &&
                globals->status[i].out == 0) {
                D_800E54A4->players[D_80102B00[i].owner].back = 2;
                D_800E54A4->players[D_80102B00[i].owner].state = 2;
                D_800E54A4->players[D_80102B00[i].owner].next = 6;
            }
        }
        for (i = 0; i < 4; i++) {
            func_804322AC_de(i);
        }
        break;
    case 6:
        if (D_800DF4C4 == 0) {
            for (i = 0; i < 4; i++) {
                func_80404E28_de(i);
                switch (func_80404F04_de(i)) {
                case -4:
                case -3:
                case -1:
                case 0:
                    D_800E54A4->players[i].back = 2;
                    D_800E54A4->players[i].state = 2;
                    D_800E54A4->players[i].next = 4;
                    func_804322AC_de(i);
                    break;
                }
            }
        } else {
            func_80404E28_de(D_800DF4C0);
            switch (func_80404F04_de(D_800DF4C0)) {
            case -4:
            case -3:
            case -1:
            case 0:
                D_800E54A4->players[D_800DF4C0].back = 2;
                D_800E54A4->players[D_800DF4C0].state = 2;
                D_800E54A4->players[D_800DF4C0].next = 4;
                func_804322AC_de(D_800DF4C0);
                break;
            }
        }
        break;
    case 7:
        D_800E54A4->players[0].back = 2;
        D_800E54A4->players[0].state = 2;
        D_800E54A4->players[0].next = 0xD;
        D_800E54A4->players[0].sub = 6;
        func_804322AC_de(0);
        break;
    }
    func_8040C428_de(0);
    func_802A2394_de();
    func_802A2418_de(0);
    func_8025DF34_de(0xE78);
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_8042F12C_us_rev1);
#endif
#endif
