#include "include_asm.h"
#include "COMMON/ACTIVE.H"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "FRONTEND/8042E080_22.H"
#include "SYSTEM_2/8025E280.H"

/* Prepares a match: stops the current screen, starts screen 2, resets the eight player status
   records (clearing bytes 0x94 and 0x95 and, for human slots, the team byte 0x92) while counting
   active humans, clears the match counters, and outside mode 0 looks up the stage default for the
   first active player through func_80425C70_de and resets the round state. It then runs the setup of
   the current rule set D_8014DD98, copies each active human's name and the five profile bytes at 0x189
   of their player record into status bytes 0x7B, 0x7D, 0x79, 0x7A and 0x82, sets the game mode (team mode 2 falls back to 1 with fewer than two
   humans) and, when func_8025E2C4_de allows, picks a random arena 0x38 to 0x3B. */







extern struct RecordRecAt189 D_80102B00[];
extern s32 D_800E4680;
extern s32 D_8015402C;
extern s32 D_80146948;
extern s32 D_8014DD98;

extern void func_8029973C_de(void);
extern void func_80298368_de(s32);
extern void func_802A230C_de(void);
extern s32 func_80425C70_de(s32, s32, s32);





extern void func_802A025C_de(char *, char *);
extern void func_8040C428_de(s32);
extern s32 func_802744D4_de(void);


void func_8042DEA0_de(void) {
    u8 *settings;
    u8 *config;
    struct StatusRecAt95 *status;
    s32 humans;
    s32 i;
    s32 first;
    RenderCounters *match;

    func_8029973C_de();
    func_80298368_de(2);
    func_802A230C_de();
    humans = 0;
    settings = (u8 *)&D_801462C8;
    for (i = 0; i < 8; i++) {
        status = (struct StatusRecAt95 *)(settings + 0xD0 + i * 0x96);
        status->lives = 0;
        status->score = 0;
        if (status->computer == 0) {
            status->team = 0xFF;
        }
        if (status->computer == 0 && status->joined == 1) {
            humans++;
        }
    }
    match = &D_801462C8.counters;
    match->enabled = 0;
    match->kills = 0;
    D_800E4680 = 0;
    if (settings[0xD] != 0) {
        first = 0;
        while (((struct StatusRecAt95 *)(settings + 0xD0 + first * 0x96))->joined == 0) {
            first++;
        }
        status = (struct StatusRecAt95 *)(settings + 0xD0 + first * 0x96);
        switch (settings[0xD]) {
        case 1:
            D_800E4680 = func_80425C70_de(D_8015402C, 0, status->kind);
            break;
        case 2:
            D_800E4680 = func_80425C70_de(D_8015402C, 1, 0);
            break;
        case 3:
            D_800E4680 = func_80425C70_de(D_8015402C, 3, 0);
            break;
        case 4:
            D_800E4680 = func_80425C70_de(D_8015402C, 2, 0);
            break;
        }
        D_80146948 = 0;
        func_8042E1F0_de();
    }
    switch (D_8014DD98) {
    case 0:
        func_8042EBA4_de();
        break;
    case 1:
        func_8042EB10_de();
        break;
    case 2:
        func_8042ECD8_de();
        break;
    case 3:
        func_8042EC38_de();
        break;
    }
    for (i = 0; i < 4; i++) {
        status = (struct StatusRecAt95 *)(settings + 0xD0 + i * 0x96);
        if (status->joined == 1 && status->computer == 0) {
            func_802A025C_de(status->name, D_80102B00[i].name);
            if (settings[0xD] != 0) {
                status->team = 0;
            } else {
                status->team = 0xFF;
            }
            status->unk7B = D_80102B00[i].profile[0];
            status->unk7D = D_80102B00[i].profile[1];
            status->unk79 = D_80102B00[i].profile[2];
            status->unk7A = D_80102B00[i].profile[3];
            status->unk82 = D_80102B00[i].profile[4];
        }
    }
    config = (u8 *)&D_801462C8;
    if (config[0x580] == 2 && humans >= 2) {
        func_8040C428_de(1);
    } else {
        func_8040C428_de(config[0x580]);
    }
    if (func_8025E2C4_de() != 0) {
        func_8025E2D4_de(func_802744D4_de() % 4 + 0x38);
    }
}

#ifdef NON_MATCHING
/* Places the computer opponents of the stage entry D_800E4680: first frees the status slots
   (from 0x80146398) still marked joined and computer, then for each of the entry's seven opponent
   records with a nonzero kind places it through func_8042E460_de and, by kind, sets byte 0x94 of the
   returned slot's status and the words at 0x98 to 0xA4 of D_801468A0: kind 0xC sets 2 with 0x98 = 1,
   0xA0 = 100 and 0xA4 = -1; 0xD sets 1 with 0x98 = 1; 0x10 sets 2; 0xE sets 1 with 0x98 = 1 for the
   first such opponent and 0 after; 0xF sets 1 with 0x98 = 1 and 0x9C = 0; any other kind sets 0 and,
   once a kind 0xF opponent was placed, byte 0x95 = 1. */
#include "TYPES.H"

struct Status {
    char pad0[0x78];
    u8 joined;
    char pad79[0x91 - 0x79];
    u8 computer;
    char pad92[0x96 - 0x92];
};

struct Match {
    char pad0[0x98];
    s32 rules;
    s32 escorts;
    s32 limit;
    s32 leader;
};

struct Stage {
    char pad0[5];
    u8 opponents[7][4];
};

extern struct Status D_80146398[];
extern struct Stage *D_800E4680;

extern s32 func_8042E460_de(u8 *);

void func_8042E1F0_de(void) {
    RenderCounters *match;
    struct Status *status;
    u8 *settings;
    s32 boss;
    s32 escorted;
    s32 i;
    s32 on;
    s32 slot;

    boss = 0;
    escorted = 0;
    match = &D_801462C8.counters;
    status = D_80146398;
    for (i = 0; i < 8; i++) {
        if (status[i].joined == 1 && status[i].computer == status[i].joined) {
            status[i].joined = 0;
            status[i].computer = 0;
        }
    }
    for (i = 0; i < 7; i++) {
        on = 1;
        settings = (u8 *)&D_801462C8;
        if (D_800E4680->opponents[i][0] == 0) {
            continue;
        }
        switch (D_800E4680->opponents[i][0]) {
        case 12:
            match->enabled = 1;
            slot = func_8042E460_de(D_800E4680->opponents[i]);
            settings[slot * 0x96 + 0x164] = 2;
            match->timer = 100;
            match->cooldown = -1;
            break;
        case 13:
            match->enabled = on;
            slot = func_8042E460_de(D_800E4680->opponents[i]);
            settings[slot * 0x96 + 0x164] = on;
            break;
        case 16:
            slot = func_8042E460_de(D_800E4680->opponents[i]);
            settings[slot * 0x96 + 0x164] = 2;
            break;
        case 14:
            slot = func_8042E460_de(D_800E4680->opponents[i]);
            if (boss == 0) {
                match->enabled = on;
                settings[slot * 0x96 + 0x164] = on;
                boss = 1;
            } else {
                settings[slot * 0x96 + 0x164] = 0;
            }
            break;
        case 15:
            match->enabled = on;
            match->unk9C = 0;
            slot = func_8042E460_de(D_800E4680->opponents[i]);
            settings[slot * 0x96 + 0x164] = 1;
            escorted = 1;
            break;
        default:
            slot = func_8042E460_de(D_800E4680->opponents[i]);
            settings[slot * 0x96 + 0x164] = 0;
            if (escorted) {
                settings[slot * 0x96 + 0x165] = on;
            }
            break;
        }
    }
}
#else
INCLUDE_ASM("ovl_80400000", func_8042E1F0_de);
#endif
