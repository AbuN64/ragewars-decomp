#include "shared/gameplay_transition.h"
#include "span_16E000/code_80447BB0.h"
#include "types.h"





























/* Sets up a player in a slot: records whether its record at arg2 is a computer driver, loads the driver's profile at 0x688 through func_8026367C_de from D_8010EEB8 (computers, keeping the record's slot) or from the slot's entry of D_8010F328, clears its race counters and eight lap splits, links it to its vehicle through func_802097E8_de and resets it through func_8021A78C_de and func_802A6F68_de. */




extern char D_8010EEB8[];
extern char D_8010F328[];
extern char D_800C9684[];

extern void func_8026367C_de(char *, char *);
extern void func_802097E8_de(s32, char *);
extern void func_8021A78C_de(char *);
extern void func_802A6F68_de(char *);




void func_80449EE4_de(char *player, s32 slot, Record_func_80449EE4_de *record) {
    s32 i;
    s32 computer;
    u8 team;

    computer = record->computer;
    ((Shared_ActorView *)player)->actorState = 0;
    ((Shared_ActorView *)player)->remote = computer;
    if (computer != 0) {
        func_8026367C_de(player + 0x688, D_8010EEB8);
        ((Shared_ActorView *)player)->mode = record->slot;
    } else {
        func_8026367C_de(player + 0x688, D_8010F328 + slot * 0x224);
        ((Shared_ActorView *)player)->mode = slot;
    }
    ((Shared_ActorView *)player)->controls = (void *)record;
    team = record->team;
    ((Shared_ActorView *)player)->field11BC = 0;
    ((Shared_ActorView *)player)->field11C0 = 0;
    ((Shared_ActorView *)player)->spawn = 0;
    ((Shared_ActorView *)player)->field5F0 = 0;
    ((Shared_ActorView *)player)->field864 = 0;
    ((Shared_ActorView *)player)->field868 = 0;
    ((Shared_ActorView *)player)->self = player;
    player[3] = team;
    func_802097E8_de((s32)((Shared_ActorView *)player)->owner, player);
    ((Shared_ActorView *)player)->special = 0;
    ((Shared_ActorView *)player)->projectileBase = slot * 2;
    ((Shared_ActorView *)player)->projectileIndex = 0;
    ((Shared_ActorView *)player)->field122C = 0;
    ((Shared_ActorView *)player)->field11CC = 0;
    ((Shared_ActorView *)player)->field1218 = 0;
    for (i = 0; i < 8; i++) {
        ((Shared_ActorView *)player)->reset12CC[i] = 0;
        ((Shared_ActorView *)player)->reset12F4[i] = 0;
    }
    ((Shared_ActorView *)player)->field1338 = -1;
    ((Shared_ActorView *)player)->field12C4 = 0;
    ((Shared_ActorView *)player)->field12C8 = 0;
    ((Shared_ActorView *)player)->field1334 = 0;
    ((Shared_ActorView *)player)->field13B4 = (s32 *)D_800C9684;
    ((Shared_ActorView *)player)->field11E8 = 0;
    func_8021A78C_de(player);
    ((Shared_ActorView *)player)->field16D4 = 0;
    ((Shared_ActorView *)player)->field16D8 = 0;
    func_802A6F68_de((char *)player + 0xD40);
}
