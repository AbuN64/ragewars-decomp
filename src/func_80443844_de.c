#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80443868.h"
/* When team sync is enabled, copies a player's team flag from its actor (byte 0x8F of the record at
   0x5D8) into D_801468A0 if it is 1; then resumes the script D_8011FAC0 through func_8044DD50_de in mode
   1 or else clears the actor's word at 0x5D0; returns 1. Matched through a local pointer to
   D_801468A0 and the team byte held in a local. */








extern Sync D_801468A0;

extern char D_8011FAC0[];
extern void func_8044DD50_de(char *);

int func_80443844_de(int unused, PlayerRecAt1C *player) {
    Sync *sync = &D_801468A0;
    int team;

    if (sync->sync != 0) {
        team = player->actor->info->unk8F;
        if (team == 1) {
            sync->team = team;
        }
    }
    if (D_80145070 == 1) {
        func_8044DD50_de(D_8011FAC0);
    } else {
        player->actor->waiting = 0;
    }
    return 1;
}
