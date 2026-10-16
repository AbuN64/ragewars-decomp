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

extern struct Match D_801468A0;
extern struct Status D_80146398[];
extern u8 D_801462C8[];
extern struct Stage *D_800E4680;

extern s32 func_8042E460_de(u8 *);

void func_8042E1F0_de(void) {
    struct Match *match;
    struct Status *status;
    u8 *settings;
    s32 boss;
    s32 escorted;
    s32 i;
    s32 on;
    s32 slot;

    boss = 0;
    escorted = 0;
    match = &D_801468A0;
    status = D_80146398;
    for (i = 0; i < 8; i++) {
        if (status[i].joined == 1 && status[i].computer == status[i].joined) {
            status[i].joined = 0;
            status[i].computer = 0;
        }
    }
    for (i = 0; i < 7; i++) {
        on = 1;
        settings = D_801462C8;
        if (D_800E4680->opponents[i][0] == 0) {
            continue;
        }
        switch (D_800E4680->opponents[i][0]) {
        case 12:
            match->rules = 1;
            slot = func_8042E460_de(D_800E4680->opponents[i]);
            settings[slot * 0x96 + 0x164] = 2;
            match->limit = 100;
            match->leader = -1;
            break;
        case 13:
            match->rules = on;
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
                match->rules = on;
                settings[slot * 0x96 + 0x164] = on;
                boss = 1;
            } else {
                settings[slot * 0x96 + 0x164] = 0;
            }
            break;
        case 15:
            match->rules = on;
            match->escorts = 0;
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
