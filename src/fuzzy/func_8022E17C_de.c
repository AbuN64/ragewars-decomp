#include "TYPES.H"

typedef struct TeamStats {
    /* 0x00 */ char pad0[0x92];
    /* 0x92 */ u8 team;
} TeamStats;

typedef struct TeamPlayer {
    /* 0x000 */ char pad0[0x5D8];
    /* 0x5D8 */ TeamStats *stats;
} TeamPlayer;

typedef struct TeamCounters {
    /* 0x00 */ char pad0[0x24];
    /* 0x24 */ s32 active;
    /* 0x28 */ char pad28[0x4];
    /* 0x2C */ s32 wins[5];
    /* 0x40 */ s32 losses[5];
    /* 0x54 */ s32 locked;
    /* 0x58 */ char pad58[0x20];
    /* 0x78 */ s32 frozen;
} TeamCounters;

extern TeamCounters D_801468A0;

void func_8022E17C_de(TeamPlayer *a, TeamPlayer *b, s32 mode) {
    TeamCounters *c = &D_801468A0;
    s32 teamA;
    s32 teamB;
    s32 *win;
    s32 *loss;
    s32 off;
    s32 *wins;
    s32 *losses;

    if (c->active != 0) {
        teamA = a->stats->team;
        teamB = b->stats->team;
        if (teamA >= 0) {
          if (teamA < 5) {
            off = teamA * 4;
            wins = c->wins;
            win = &wins[teamA];
            losses = c->losses;
            loss = &losses[teamA];
            switch (mode) {
            case 0:
                if (c->frozen == 0 && c->locked == 0) {
                    *win -= 1;
                }
                break;
            case 1:
                if (teamB != teamA) {
                    *win += 1;
                }
                break;
            case 3:
                *loss += 1;
                break;
            case 2:
                if (teamB != teamA) {
                    *win += 1;
                    break;
                }
                *win -= 1;
                break;
            }
          }
        }
    }
}
