#include "TYPES.H"
#include "shared/func_80425674_de_layout.h"
typedef struct WinRules { u8 pad0[0x18]; s32 limit; u8 pad1c[8]; s32 teams; u8 pad28[4]; s32 scores[5]; u8 pad40[0x68]; s32 humanWon; } WinRules;
typedef struct WinScore { u8 pad0[4]; s16 score; } WinScore;
typedef struct WinPlayer WinPlayer;
struct WinPlayer { u8 pad0[0x5d4]; s32 kind; WinScore *stats; u8 pad5dc[0x1104]; WinPlayer *next; };
typedef struct WinWorld { u8 pad0[0x20]; WinPlayer *players; } WinWorld;
extern WinRules D_801468A0;
extern Shared_Game D_801462C8;
extern s32 func_80245784_de(void),func_80245798_de(void);
s32 func_80228070_de(WinWorld *world) {
    WinPlayer *player;
    u32 team,i;
    if (func_80245784_de() || func_80245798_de() || D_801468A0.limit == 0) return 0;
    if (D_801468A0.teams == 0) {
        for (player = world->players; player != 0; player = player->next) {
            if (D_801468A0.limit <= player->stats->score) {
                if (D_801462C8.controllerMode == 0) return 1;
                if (player->kind < 4) { D_801468A0.humanWon = 1; return 1; }
                D_801468A0.humanWon = 0;
                if (D_801462C8.controllerMode != 1) return 1;
            }
        }
    } else {
        team = 0xff;
        if (D_801462C8.controllerMode != 0) {
            i = 0;
            while (D_801462C8.slots[i].enabled == 0) i++;
            team = D_801462C8.slots[i].slot;
        }
        for (i = 0; (s32)i < 5; i++) {
            if (D_801468A0.limit <= D_801468A0.scores[i]) {
                if (D_801462C8.controllerMode == 0) return 1;
                if (i == team) { D_801468A0.humanWon = 1; return 1; }
                D_801468A0.humanWon = 0;
                if (D_801462C8.controllerMode != 1) return 1;
            }
        }
    }
    return 0;
}
