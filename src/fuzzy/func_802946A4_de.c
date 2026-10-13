#include "shared/round_state_variants.h"
#include "types.h"

/* Prepares a session for a new round: clears the round flag, resets the round state, records the round seed when func_80264B6C_de allows, resets the scoreboard and player slot, restarts the arena with the session's arena setting, resets the camera timers and reloads the session's sound bank and music. */

typedef struct Session {
    char pad0[0x3C4];
    s32 soundBank;
    char pad3C8[0x26826 - 0x3C8];
    unsigned char arena;
    char pad26827[0x26DD8 - 0x26827];
    s32 music;
} Session;

typedef struct Board {
    char pad0[0x20];
    s32 field20;
    char pad24[0x40];
    s32 field64;
} Board;

typedef struct Slot {
    char pad0[0x1D];
    unsigned char field1D;
    unsigned char field1E;
    char pad1F[0x5D8-0x1F];
    Board board;
} Slot;

extern s32 D_800CD730;
extern f32 D_800D2988[];
extern f32 D_800CD740_de;
extern f32 D_800CD744_de;

extern Slot D_801462C8;
extern char D_8011FE88;
extern void func_80293268_de(void);
extern s32 func_80264B6C_de(void);
extern s32 func_80264B5C_de(void);
extern void func_80264B8C_de(void);
extern void func_80293334_de(Session *session, s32 arena, s32 arg2);
extern void func_8023EE00_de(void);
extern void func_8044CFF8_de(void *player, s32 bank);
extern void func_8044D528_de(void *player, s32 music, s32 arg2);

void func_802946A4_de(Session *session) {
    Board *board;
    Slot *slot;
    s32 bank;

    D_800CD730 = 0;
    func_80293268_de();
    if (func_80264B6C_de() != 0) {
        session->music = func_80264B5C_de();
    }
    board = &D_801462C8.board;
    board->field20 = 0;
    board->field64 = 3;
    slot = &D_801462C8;
    slot->field1D = 1;
    slot->field1E = 8;
    func_80293334_de(session, session->arena, 0);
    if (func_80264B6C_de() != 0) {
        func_80264B8C_de();
    }
    func_8023EE00_de();
    resetRoundExtra();
    bank = session->soundBank;
    clearRoundExtra();
    D_800CD744_de = roundTimerConstant();
    D_800D2988[1] = roundTimerConstant();
    D_800CD740_de = roundTimerConstant();
    func_8044CFF8_de(&D_8011FE88, bank);
    func_8044D528_de(&D_8011FE88, session->music, 0);
}

