#include "span_16E000/code_80423280.h"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "shared/func_80425674_de_layout.h"
#include "shared/world.h"
#include "span_16E000/code_804251F4.h"
#include "stddef.h"
#include "types.h"

extern Shared_Game D_801462C8;

extern s32 func_8022F5C4_de(char *, s32);

extern void func_8022F5A4_de(char *, s32);

/* Upgrades the thirteen weapon levels of player record D_80102B00[index] from the number of its 50
   achievement flags func_80265650_de reports set: every two achievements from 2 raise one more weapon
   to level 2 and, from 28, one more of twelve to level 3, in a fixed weapon order. */



static inline s32 count_achievements(s32 index) {
    extern s32 func_80265650_de(u8 *, s32);
    extern u8 D_80102B00[];
    s32 count;
    s32 i;

    count = 0;
    i = 0;
    do {
        if (func_80265650_de(D_80102B00 + index * 400 + 0x4A, i) == 1) {
            count++;
        }
        i++;
    } while (i < 50);
    return count;
}

extern Preset D_8014DD50;

extern PresetTable *func_8028D474_de(void *table, s32 key);

extern void *func_802BD3A0_de(void *destination, const void *source, int count);

/* Announces the current arena's entry for a slot: selects one of four five-byte name tables from the
   mode byte D_801462D5, indexes it by the argument times 400 and hands that entry to func_80265688_de
   together with the current handle D_8015402C and flag 1; an unrecognised mode does nothing. */

extern char D_80102B7E[];

extern char D_800FEB83[];

extern char D_800FEB88[];

extern char D_800FEB8D[];

extern u8 D_801462D5;

extern s32 D_8015402C;

/* Starts the ambient track for the current stage D_8015402C (stage 4, 9, 22 and 35 select tracks
   0 to 3): returns -1 when the stage has no track or when func_80265650_de reports the slot busy,
   otherwise starts it on arg0's 400-byte slot of D_80102C24 through func_80265688_de and returns
   0x13BC. */

extern u8 D_80102C24[];

/* Awards player p flag 0x31: when the player's 150-byte record in D_80146398 has its byte at
   0x78 equal to one and its byte at 0x91 clear, and the flag set at 0x4A of the player's 400-byte
   record in D_80102B00 lacks bit 0x31 while the set at 0x124 has bits 0 to 3, it sets bit 0x31
   through func_80265688_de and stores 0x31 through the second argument. */

extern u8 D_80146398[];

/* Counts the enabled entries in a fifty-entry player table. */
extern unsigned char D_800FEB4A[];

/* Marks available inventory entries with their slot indices. */
s32 func_8022F4DC_de(void *, s32);

 /* extern */


s32 func_80425674_de(s32 p) {
    extern MatchRewardsRecord D_80102B00[];
    char *record;
    Shared_Game *settings;
    s32 given;

    record = (char *)&D_80102B00[p];
    settings = &D_801462C8;
    given = -1;
    if (settings->controllerMode == 1 && settings->humanWon == 1 && D_8015402C >= 0x23) {
        switch (settings->slots[p].kind) {
        case 0:
            if (func_8022F5C4_de(record, 0x11) == 0) {
                func_8022F5A4_de(record, 0x11);
                given = 0x11;
            }
            break;
        case 1:
            if (func_8022F5C4_de(record, 0x6) == 0) {
                func_8022F5A4_de(record, 0x6);
                given = 0x6;
            }
            break;
        case 2:
            if (func_8022F5C4_de(record, 0x3) == 0) {
                func_8022F5A4_de(record, 0x3);
                given = 0x3;
            }
            break;
        case 3:
            if (func_8022F5C4_de(record, 0x4) == 0) {
                func_8022F5A4_de(record, 0x4);
                given = 0x4;
            }
            break;
        case 4:
            if (func_8022F5C4_de(record, 0xE) == 0) {
                func_8022F5A4_de(record, 0xE);
            }
            break;
        case 5:
            if (func_8022F5C4_de(record, 0x1) == 0) {
                func_8022F5A4_de(record, 0x1);
                given = 0x1;
            }
            break;
        case 6:
            if (func_8022F5C4_de(record, 0x12) == 0) {
                func_8022F5A4_de(record, 0x12);
                given = 0x12;
            }
            break;
        case 7:
            if (func_8022F5C4_de(record, 0x8) == 0) {
                func_8022F5A4_de(record, 0x8);
                given = 0x8;
            }
            break;
        case 8:
            if (func_8022F5C4_de(record, 0x9) == 0) {
                func_8022F5A4_de(record, 0x9);
                given = 0x9;
            }
            break;
        case 9:
            if (func_8022F5C4_de(record, 0xA) == 0) {
                func_8022F5A4_de(record, 0xA);
                given = 0xA;
            }
            break;
        case 17:
            if (func_8022F5C4_de(record, 0x2) == 0) {
                func_8022F5A4_de(record, 0x2);
                given = 0x2;
            }
            break;
        case 18:
            break;
        }
        if (func_8022F5C4_de(record, 0x11) == 1 && func_8022F5C4_de(record, 1) == 1 &&
            func_8022F5C4_de(record, 8) == 1 && func_8022F5C4_de(record, 0xB) == 0) {
            func_8022F5A4_de(record, 0xB);
        }
        if (func_8022F5C4_de(record, 2) == 1 && func_8022F5C4_de(record, 6) == 1 &&
            func_8022F5C4_de(record, 9) == 1 && func_8022F5C4_de(record, 0xC) == 0) {
            func_8022F5A4_de(record, 0xC);
        }
        if (func_8022F5C4_de(record, 3) == 1 && func_8022F5C4_de(record, 0x12) == 1 &&
            func_8022F5C4_de(record, 0xA) == 1 && func_8022F5C4_de(record, 0xD) == 0) {
            func_8022F5A4_de(record, 0xD);
        }
    }
    return given;
}

void func_804259E0_de(s32 index) {
    extern u8 D_80102B00[];
    u8 *record;
    s32 count;

    record = D_80102B00 + index * 400;
    count = count_achievements(index);
    if (count >= 2) {
        record[0x57] = 2;
    }
    if (count >= 4) {
        record[0x5C] = 2;
    }
    if (count >= 6) {
        record[0x58] = 2;
    }
    if (count >= 8) {
        record[0x60] = 2;
    }
    if (count >= 10) {
        record[0x59] = 2;
    }
    if (count >= 12) {
        record[0x5A] = 2;
    }
    if (count >= 14) {
        record[0x61] = 2;
    }
    if (count >= 16) {
        record[0x5D] = 2;
    }
    if (count >= 18) {
        record[0x68] = 2;
    }
    if (count >= 20) {
        record[0x5E] = 2;
    }
    if (count >= 22) {
        record[0x5B] = 2;
    }
    if (count >= 24) {
        record[0x5F] = 2;
    }
    if (count >= 26) {
        record[0x69] = 2;
    }
    if (count >= 28) {
        record[0x57] = 3;
    }
    if (count >= 30) {
        record[0x5C] = 3;
    }
    if (count >= 32) {
        record[0x58] = 3;
    }
    if (count >= 34) {
        record[0x60] = 3;
    }
    if (count >= 36) {
        record[0x59] = 3;
    }
    if (count >= 38) {
        record[0x5A] = 3;
    }
    if (count >= 40) {
        record[0x61] = 3;
    }
    if (count >= 42) {
        record[0x68] = 3;
    }
    if (count >= 44) {
        record[0x5E] = 3;
    }
    if (count >= 46) {
        record[0x5B] = 3;
    }
    if (count >= 48) {
        record[0x5F] = 3;
    }
    if (count >= 50) {
        record[0x69] = 3;
    }
}

Preset *func_80425C70_de(s32 key, s32 row, s32 column) {
    PresetTable *table;

    table = func_8028D474_de(&D_8011FE88, key);
    if (table == 0) {
        return 0;
    }
    func_802BD3A0_de(&D_8014DD50, &table->rows[row].presets[column], sizeof(Preset));
    return &D_8014DD50;
}

void func_80425D14_de(s32 slot) {
    extern void func_80265688_de(char *, s32, s32);
    switch (D_801462D5) {
    case 1:
        func_80265688_de(&D_80102B7E[slot * 0x190], D_8015402C, 1);
        return;
    case 2:
        func_80265688_de(&D_800FEB83[slot * 0x190], D_8015402C, 1);
        return;
    case 3:
        func_80265688_de(&D_800FEB88[slot * 0x190], D_8015402C, 1);
        return;
    case 4:
        func_80265688_de(&D_800FEB8D[slot * 0x190], D_8015402C, 1);
        return;
    }
}

s32 func_80425DFC_de(s32 arg0) {
    extern void func_80265688_de(u8 *, s32, s32);
    extern s32 func_80265650_de(u8 *, s32);
    s32 result;
    s32 track;
    u8 *slot;

    result = -1;
    switch (D_8015402C) {
    case 4:
        track = 0;
        break;
    case 9:
        track = 1;
        break;
    case 0x16:
        track = 2;
        break;
    case 0x23:
        track = 3;
        break;
    default:
        track = -1;
        break;
    }
    if (track != -1) {
        slot = &D_80102C24[arg0 * 0x190];
        if (func_80265650_de(slot, track) == 0) {
            result = 0x13BC;
            func_80265688_de(slot, track, 1);
        }
    }
    return result;
}

void func_80425EE4_de(s32 player, s32 *award) {
    extern void func_80265688_de(u8 *, s32, s32);
    extern s32 func_80265650_de(u8 *, s32);
    extern u8 D_80102B00[];
    u8 *record;
    s32 all;
    s32 i;

    record = &D_80146398[player * 150];
    all = 1;
    if (record[0x78] == 1 && record[0x91] == 0) {
        if (func_80265650_de(&D_80102B00[player * 400] + 0x4A, 0x31) == 0) {
            for (i = 0; i < 4; i++) {
                if (all != 1) {
                    return;
                }
                if (func_80265650_de(&D_80102B00[player * 400] + 0x124, i) == 0) {
                    all = 0;
                }
            }
            if (all == 1) {
                func_80265688_de(&D_80102B00[player * 400] + 0x4A, 0x31, 1);
                *award = 0x31;
            }
        }
    }
}

 /* extern */
s32 func_80426004_de(s32 arg0) {
    s32 func_80265650_de(void *, s32);
    s32 temp_s2;
    s32 var_s0;
    s32 var_s1;
    void *var_a0;
    var_s1 = 0;
    var_s0 = 0;
    temp_s2 = arg0 * 0x190;
    var_a0 = temp_s2 + D_800FEB4A;
    do {
        if (func_80265650_de(temp_s2 + D_800FEB4A, var_s0) == 1) {
            var_s1 += 1;
        }
        var_s0 += 1;
        var_a0 = temp_s2 + D_800FEB4A;
    } while (var_s0 < 0x32);
    return var_s1;
}

void func_80426090_de(Arg *arg0) {
    extern char D_80102B00[];
    s32 temp_s0;
    s32 temp_s3;
    s32 temp_v0;
    s32 var_s1;
    StateRecAt91 *temp_a0;
    Model *var_s2;
    temp_a0 = arg0->unk5D8;
    if (temp_a0->unk91 != 1) {
        var_s1 = 0;
        if (temp_a0->unk78 != 0) {
            var_s2 = (Model *)arg0->unk18;
            temp_s3 = temp_a0->unk7F * 0x190;
            do {
                temp_s0 = var_s2->slots[var_s1];
                if (temp_s0 >= 0x4C3) {
                    temp_s0 = temp_s0 - 0x4C3;
                    temp_v0 = func_8022F4DC_de(temp_s3 + D_80102B00, temp_s0);
                    if (temp_v0 == 1) {
                        arg0->slots[temp_s0].available = temp_v0;
                        arg0->slots[temp_s0].slot = var_s1;
                    }
                }
                var_s1 += 1;
            } while (var_s1 < 8);
        }
    }
}
