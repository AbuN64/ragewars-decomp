#include "types.h"

typedef struct DraftScoreRecord {
    char pad0[4]; s16 kills; s16 score; s16 alternate;
    char padA[0x6E]; u8 active;
    char pad79[0x19]; u8 team;
    char pad93[3];
} DraftScoreRecord;
typedef struct DraftScoreTable { char pad0[0x2C]; s32 teamScore[5]; s32 teamAlternate[5]; } DraftScoreTable;
typedef struct DraftScoreGame {
    char pad0[0xD0]; DraftScoreRecord players[8];
    char pad580[0x58]; DraftScoreTable teams;
} DraftScoreGame;
typedef struct DraftScoreScreen { char pad0[0xE8]; s32 selection; s32 count; s32 order[8]; } DraftScoreScreen;
extern DraftScoreScreen *D_800E53C0;
extern DraftScoreRecord D_80146398[8];
extern DraftScoreGame D_801462C8;
extern DraftScoreTable D_801468A0;
extern s32 D_8014DD98;
extern s32 func_8042D060_de(void);

void func_8042C6CC_de(void) {
    DraftScoreScreen *screen;
    DraftScoreRecord *a, *b;
    s32 teams[5];
    s32 i, j, k, pass, mode, value, first, second;
    s16 killsA, killsB, scoreA, scoreB;
    u32 team;
    screen = D_800E53C0;
    screen->selection = 0;
    screen->count = 0;
    for (i = 0; i < 8; i++) {
        screen->order[i] = -1;
        if (D_80146398[i].active == 1) {
            screen->order[screen->count] = i;
            screen->count++;
        }
    }
    mode = func_8042D060_de();
    if (mode == 0) {
        if (D_8014DD98 == 1) mode = 2;
        else if (D_8014DD98 == 0) mode = 3;
        else mode = 1;
    }
    if (D_8014DD98 == 3 || D_8014DD98 == 0) {
        for (i = 4; i >= 0; i--) teams[i] = i;
        for (pass = 0; pass < 5; pass++) {
            for (i = 0; i < 4; i++) {
                if (D_8014DD98 == 0) first = D_801468A0.teamAlternate[teams[i]];
                else first = D_801468A0.teamScore[teams[i]];
                if (D_8014DD98 == 0) second = D_801468A0.teamAlternate[teams[i + 1]];
                else second = D_801468A0.teamScore[teams[i + 1]];
                if (first < second) { value = teams[i]; teams[i] = teams[i + 1]; teams[i + 1] = value; }
            }
        }
        screen = D_800E53C0;
        for (pass = 0; pass < D_800E53C0->count; pass++) {
            for (i = 0; i < D_800E53C0->count - 1; i++) {
                team = D_801462C8.players[D_800E53C0->order[i]].team;
                first = -1;
                if (team < 5) {
                    if (D_8014DD98 == 0) first = D_801462C8.teams.teamAlternate[team];
                    else first = D_801462C8.teams.teamScore[team];
                }
                team = D_801462C8.players[screen->order[i + 1]].team;
                second = -1;
                if (team < 5) {
                    if (D_8014DD98 == 0) second = D_801462C8.teams.teamAlternate[team];
                    else second = D_801462C8.teams.teamScore[team];
                }
                if (first < second) { value = screen->order[i]; screen->order[i] = screen->order[i + 1]; screen->order[i + 1] = value; }
            }
        }
        screen = D_800E53C0;
        for (k = 0; k < 5; k++) {
            team = teams[k];
            for (pass = 0; pass < D_800E53C0->count; pass++) {
                for (j = 0; j < D_800E53C0->count - 1; j++) {
                    a = &D_801462C8.players[D_800E53C0->order[j]];
                    b = &D_801462C8.players[D_800E53C0->order[j + 1]];
                    killsA = a->kills; killsB = b->kills;
                    if (a->team == team && b->team == team) {
                        if (mode == 1 || mode != 3) { scoreA = killsA; scoreB = killsB; }
                        else { scoreA = a->alternate; scoreB = b->alternate; }
                        if (scoreA < scoreB || (scoreA == scoreB && killsA < killsB)) {
                            value = screen->order[j]; screen->order[j] = screen->order[j + 1]; screen->order[j + 1] = value;
                        }
                    }
                }
            }
        }
    } else {
        screen = D_800E53C0;
        for (pass = 0; pass < D_800E53C0->count; pass++) {
            for (i = 0; i < D_800E53C0->count - 1; i++) {
                a = &D_801462C8.players[D_800E53C0->order[i]];
                b = &D_801462C8.players[D_800E53C0->order[i + 1]];
                killsA = a->kills; killsB = b->kills;
                if (mode == 2) { scoreA = a->score; scoreB = b->score; }
                else if (mode < 3 || mode != 3) { scoreA = killsA; scoreB = killsB; }
                else { scoreA = a->alternate; scoreB = b->alternate; }
                if (scoreA < scoreB || (scoreA == scoreB && killsA < killsB)) {
                    value = screen->order[i]; screen->order[i] = screen->order[i + 1]; screen->order[i + 1] = value;
                }
            }
        }
    }
}
