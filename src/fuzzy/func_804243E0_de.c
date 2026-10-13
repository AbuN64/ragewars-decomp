#include "types.h"

/* Awards earned end-of-match unlocks and lists the first two new rewards. */
typedef struct Record {
    char pad0[0x26];
    u8 plays[0x24];
    u8 unlocks[0x6C - 0x4A];
    s32 total1;
    char pad70[0x74 - 0x70];
    s32 total2;
    char pad78[0x190 - 0x78];
} Record;

typedef struct Status {
    s16 wins;
    s16 losses;
    s16 score;
    char pad6[0xA - 0x6];
    s16 kills;
    char padC[0x78 - 0xC];
    u8 active;
    char pad79[0x91 - 0x79];
    u8 out;
    char pad92[0x96 - 0x92];
} Status;

typedef struct Rules {
    char pad0[0x14];
    f32 time;
} Rules;

typedef struct Globals {
    char pad0[0x24];
    s8 laps;
    s8 players;
    char pad26[0xD0 - 0x26];
    Status status[8];
    char pad580[0x5D8 - 0x580];
    Rules rules;
} Globals;

typedef struct UnlockRecord {
    u8 bits[0x190];
} UnlockRecord;
typedef struct PlayRecord {
    u8 plays[0x24];
    char pad24[0x190 - 0x24];
} PlayRecord;
typedef struct TotalRecord {
    s32 value;
    char pad4[0x190 - 4];
} TotalRecord;
extern UnlockRecord D_800FEB4A[];
extern PlayRecord D_800FEB26[];
extern TotalRecord D_800FEB6C[];
extern TotalRecord D_800FEB74[];
extern Status D_80146398[];
extern Rules D_801468A0;
extern Globals D_801462C8;
extern u8 D_8014222C;
extern f32 D_800E16B0;
extern f32 D_800DD684;
extern f32 D_800DD688;
extern f32 D_800DD68C;
extern f32 D_800DD690[2];


extern s32 func_80426274_de(void);
extern s32 func_80265650_de(u8 *, s32);
extern void func_80265688_de(u8 *, s32, s32);

void func_804243E0_de(s32 player, s32 *awarded) {
    Status *status;
    Globals *globals;
    Rules *rules;
    
    f32 elapsed;
    
    s32 score;
    s32 count;
    s32 i;
    
    u32 ok;

    count = 0;
    awarded[0] = -1;
    awarded[1] = -1;
    if (func_80426274_de() == 0) {
        return;
    }
    status = &D_80146398[player];
    if (status->active != 1) {
        return;
    }
    if (status->out != 0) {
        return;
    }
    for (i = 0; i < 0x24; i++) {
        if (func_80265650_de(D_800FEB4A[player].bits, i) == 0 && D_800FEB26[player].plays[i] >= 2) {
            func_80265688_de(D_800FEB4A[player].bits, i, 1);
            if (count < 2) {
                awarded[count++] = i;
            }
        }
    }
    if (func_80265650_de(D_800FEB4A[player].bits, 0x24) == 0) {
        rules = &D_801468A0;
        ok = 0;
        if ((D_8014222C - 1U < 5 && status->score >= 15) ||
            (rules->time >= 0.0f && status->score >= 15 &&
             (elapsed = (f32) (s32) (rules->time * D_800E16B0 * D_800DD684), (f32) D_801462C8.laps - elapsed) <= D_800DD688)) {
            ok = 1;
        }
        if (ok == 1) {
            func_80265688_de(D_800FEB4A[player].bits, 0x24, 1);
            if (count < 2) {
                awarded[count++] = 0x24;
            }
        }
    }
    if (func_80265650_de(D_800FEB4A[player].bits, 0x25) == 0) {
        rules = &D_801468A0;
        ok = 0;
        if ((D_8014222C - 1U < 10 && status->score >= 25) ||
            (rules->time >= 0.0f && status->score >= 25 &&
             (elapsed = (f32) (s32) (rules->time * D_800DD68C * D_800DD690[0]), (f32) D_801462C8.laps - elapsed) <= D_800DD690[1])) {
            ok = 1;
        }
        if (ok == 1) {
            func_80265688_de(D_800FEB4A[player].bits, 0x25, 1);
            if (count < 2) {
                awarded[count++] = 0x25;
            }
        }
    }
    if (func_80265650_de(D_800FEB4A[player].bits, 0x26) == 0 && status->score == 0 &&
        (globals = &D_801462C8)->laps >= 10 && globals->players >= 20) {
        func_80265688_de(D_800FEB4A[player].bits, 0x26, 1);
        if (count < 2) {
            awarded[count++] = 0x26;
        }
    }
    if (func_80265650_de(D_800FEB4A[player].bits, 0x27) == 0 && status->wins >= 5) {
        func_80265688_de(D_800FEB4A[player].bits, 0x27, 1);
        if (count < 2) {
            awarded[count++] = 0x27;
        }
    }
    if (func_80265650_de(D_800FEB4A[player].bits, 0x28) == 0 && (globals = &D_801462C8)->players >= 20) {
        score = status->score;
        ok = 1;
        for (i = 0; i < 4; i++) {
            if (ok != 1) {
                break;
            }
            if (player != i && (globals->status[i].active != 1 || globals->status[i].out != 0 ||
                                globals->status[i].score - score < 10)) {
                ok = 0;
            }
        }
        if (ok == 1) {
            func_80265688_de(D_800FEB4A[player].bits, 0x28, 1);
            if (count < 2) {
                awarded[count++] = 0x28;
            }
        }
    }
    if (func_80265650_de(D_800FEB4A[player].bits, 0x29) == 0 && D_800FEB6C[player].value > 1000) {
        func_80265688_de(D_800FEB4A[player].bits, 0x29, 1);
        if (count < 2) {
            awarded[count++] = 0x29;
        }
    }
    if (func_80265650_de(D_800FEB4A[player].bits, 0x2A) == 0 && D_800FEB74[player].value > 1000) {
        func_80265688_de(D_800FEB4A[player].bits, 0x2A, 1);
        if (count < 2) {
            awarded[count++] = 0x2A;
        }
    }
    if (func_80265650_de(D_800FEB4A[player].bits, 0x2B) == 0 && status->kills >= 10 &&
        (globals = &D_801462C8)->laps >= 10 && globals->players >= 20) {
        func_80265688_de(D_800FEB4A[player].bits, 0x2B, 1);
        if (count < 2) {
            awarded[count++] = 0x2B;
        }
    }
    if (func_80265650_de(D_800FEB4A[player].bits, 0x2C) == 0 && status->losses == 0 &&
        (globals = &D_801462C8)->laps >= 10 && globals->players >= 20) {
        func_80265688_de(D_800FEB4A[player].bits, 0x2C, 1);
        if (count < 2) {
            awarded[count] = 0x2C;
        }
    }
}

