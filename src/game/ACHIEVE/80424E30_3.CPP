#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "COMMON/MENULISTSCREEN.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/WORLD.H"
#include "COMMON/RECRECAT4.H"
#include "COMMON/STATERECAT91.H"
#include "ACHIEVE/80424E30.H"
#include "stddef.h"
#include "TYPES.H"
#include "ACHIEVE/80424E30_3.H"
#include "COMMON/PLAYERPROFILES.H"

extern s32 Defs_TestBit(void *, s32);
extern void Defs_SetBitValue(u8 *, s32, s32);
extern s32 Player_HasProfileUnlockFlag(u8 *, s32);
extern s32 Player_TestAchievementFlag7(Profile *, s32);
extern void Player_SetAchievementFlag7(Profile *, s32);

/* Upgrades the thirteen weapon levels of player record D_80102B00[index] from the number of its 50
   achievement flags Defs_TestBit reports set: every two achievements from 2 raise one more weapon
   to level 2 and, from 28, one more of twelve to level 3, in a fixed weapon order. */



static inline s32 count_achievements(s32 index) {
    s32 count;
    s32 i;

    count = 0;
    i = 0;
    do {
        if (Defs_TestBit(D_80102B00[index].achievementFlags, i) == 1) {
            count++;
        }
        i++;
    } while (i < 50);
    return count;
}

extern PresetTable *func_8028D474_de(void *table, s32 key);

extern void *func_802BD3A0_de(void *destination, const void *source, int count);

/* Announces the current arena's entry for a slot: selects one of four five-byte name tables from the
   mode byte D_801462D5, indexes it by the argument times 400 and hands that entry to Defs_SetBitValue
   together with the current handle D_8015402C and flag 1; an unrecognised mode does nothing. */

extern u8 D_80102B7E[];

/* Starts the ambient track for the current stage D_8015402C (stage 4, 9, 22 and 35 select tracks
   0 to 3): returns -1 when the stage has no track or when Defs_TestBit reports the slot busy,
   otherwise starts it on arg0's 400-byte slot of D_80102C24 through Defs_SetBitValue and returns
   0x13BC. */


/* Awards player p flag 0x31: when the player's 150-byte record in D_80146398 has its byte at
   0x78 equal to one and its byte at 0x91 clear, and the flag set at 0x4A of the player's 400-byte
   record in D_80102B00 lacks bit 0x31 while the set at 0x124 has bits 0 to 3, it sets bit 0x31
   through Defs_SetBitValue and stores 0x31 through the second argument. */

extern u8 g_playerSettings[];

/* Counts the enabled entries in a fifty-entry player table. */
extern unsigned char D_800FEB4A[];

/* Marks available inventory entries with their slot indices. */

 /* extern */


s32 func_80425674_de(s32 p) {
    Profile *record;
    Shared_Game *settings;
    s32 given;

    record = &D_80102B00[p];
    settings = &D_801462C8;
    given = -1;
    if (settings->controllerMode == 1 && settings->humanWon == 1 && D_8015402C >= 0x23) {
        switch (settings->slots[p].kind) {
        case 0:
            if (Player_TestAchievementFlag7(record, 0x11) == 0) {
                Player_SetAchievementFlag7(record, 0x11);
                given = 0x11;
            }
            break;
        case 1:
            if (Player_TestAchievementFlag7(record, 0x6) == 0) {
                Player_SetAchievementFlag7(record, 0x6);
                given = 0x6;
            }
            break;
        case 2:
            if (Player_TestAchievementFlag7(record, 0x3) == 0) {
                Player_SetAchievementFlag7(record, 0x3);
                given = 0x3;
            }
            break;
        case 3:
            if (Player_TestAchievementFlag7(record, 0x4) == 0) {
                Player_SetAchievementFlag7(record, 0x4);
                given = 0x4;
            }
            break;
        case 4:
            if (Player_TestAchievementFlag7(record, 0xE) == 0) {
                Player_SetAchievementFlag7(record, 0xE);
            }
            break;
        case 5:
            if (Player_TestAchievementFlag7(record, 0x1) == 0) {
                Player_SetAchievementFlag7(record, 0x1);
                given = 0x1;
            }
            break;
        case 6:
            if (Player_TestAchievementFlag7(record, 0x12) == 0) {
                Player_SetAchievementFlag7(record, 0x12);
                given = 0x12;
            }
            break;
        case 7:
            if (Player_TestAchievementFlag7(record, 0x8) == 0) {
                Player_SetAchievementFlag7(record, 0x8);
                given = 0x8;
            }
            break;
        case 8:
            if (Player_TestAchievementFlag7(record, 0x9) == 0) {
                Player_SetAchievementFlag7(record, 0x9);
                given = 0x9;
            }
            break;
        case 9:
            if (Player_TestAchievementFlag7(record, 0xA) == 0) {
                Player_SetAchievementFlag7(record, 0xA);
                given = 0xA;
            }
            break;
        case 17:
            if (Player_TestAchievementFlag7(record, 0x2) == 0) {
                Player_SetAchievementFlag7(record, 0x2);
                given = 0x2;
            }
            break;
        case 18:
            break;
        }
        if (Player_TestAchievementFlag7(record, 0x11) == 1 && Player_TestAchievementFlag7(record, 1) == 1 &&
            Player_TestAchievementFlag7(record, 8) == 1 && Player_TestAchievementFlag7(record, 0xB) == 0) {
            Player_SetAchievementFlag7(record, 0xB);
        }
        if (Player_TestAchievementFlag7(record, 2) == 1 && Player_TestAchievementFlag7(record, 6) == 1 &&
            Player_TestAchievementFlag7(record, 9) == 1 && Player_TestAchievementFlag7(record, 0xC) == 0) {
            Player_SetAchievementFlag7(record, 0xC);
        }
        if (Player_TestAchievementFlag7(record, 3) == 1 && Player_TestAchievementFlag7(record, 0x12) == 1 &&
            Player_TestAchievementFlag7(record, 0xA) == 1 && Player_TestAchievementFlag7(record, 0xD) == 0) {
            Player_SetAchievementFlag7(record, 0xD);
        }
    }
    return given;
}

void func_804259E0_de(s32 index) {
    Profile *record;
    s32 count;

    record = &D_80102B00[index];
    count = count_achievements(index);
    if (count >= 2) {
        record->achievementFlags[0xD] = 2;
    }
    if (count >= 4) {
        record->achievementFlags[0x12] = 2;
    }
    if (count >= 6) {
        record->achievementFlags[0xE] = 2;
    }
    if (count >= 8) {
        record->achievementFlags[0x16] = 2;
    }
    if (count >= 10) {
        record->achievementFlags[0xF] = 2;
    }
    if (count >= 12) {
        record->achievementFlags[0x10] = 2;
    }
    if (count >= 14) {
        record->achievementFlags[0x17] = 2;
    }
    if (count >= 16) {
        record->achievementFlags[0x13] = 2;
    }
    if (count >= 18) {
        record->achievementFlags[0x1E] = 2;
    }
    if (count >= 20) {
        record->achievementFlags[0x14] = 2;
    }
    if (count >= 22) {
        record->achievementFlags[0x11] = 2;
    }
    if (count >= 24) {
        record->achievementFlags[0x15] = 2;
    }
    if (count >= 26) {
        record->achievementFlags[0x1F] = 2;
    }
    if (count >= 28) {
        record->achievementFlags[0xD] = 3;
    }
    if (count >= 30) {
        record->achievementFlags[0x12] = 3;
    }
    if (count >= 32) {
        record->achievementFlags[0xE] = 3;
    }
    if (count >= 34) {
        record->achievementFlags[0x16] = 3;
    }
    if (count >= 36) {
        record->achievementFlags[0xF] = 3;
    }
    if (count >= 38) {
        record->achievementFlags[0x10] = 3;
    }
    if (count >= 40) {
        record->achievementFlags[0x17] = 3;
    }
    if (count >= 42) {
        record->achievementFlags[0x1E] = 3;
    }
    if (count >= 44) {
        record->achievementFlags[0x14] = 3;
    }
    if (count >= 46) {
        record->achievementFlags[0x11] = 3;
    }
    if (count >= 48) {
        record->achievementFlags[0x15] = 3;
    }
    if (count >= 50) {
        record->achievementFlags[0x1F] = 3;
    }
}

Preset *func_80425C70_de(s32 key, s32 row, s32 column) {
    PresetTable *table;

    table = func_8028D474_de(&g_world, key);
    if (table == 0) {
        return 0;
    }
    func_802BD3A0_de(&D_8014DD50, &table->rows[row].presets[column], sizeof(Preset));
    return &D_8014DD50;
}

void func_80425D14_de(s32 slot) {
    switch (D_801462C8.controllerMode) {
    case 1:
        Defs_SetBitValue(&D_80102B7E[slot * 0x190], D_8015402C, 1);
        return;
    case 2:
        Defs_SetBitValue(&D_800FEB83[slot * 0x190], D_8015402C, 1);
        return;
    case 3:
        Defs_SetBitValue(&D_800FEB88[slot * 0x190], D_8015402C, 1);
        return;
    case 4:
        Defs_SetBitValue(&D_800FEB8D[slot * 0x190], D_8015402C, 1);
        return;
    }
}

s32 func_80425DFC_de(s32 arg0) {
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
        if (Defs_TestBit(slot, track) == 0) {
            result = 0x13BC;
            Defs_SetBitValue(slot, track, 1);
        }
    }
    return result;
}

void func_80425EE4_de(s32 player, s32 *award) {
    u8 *record;
    s32 all;
    s32 i;

    record = &g_playerSettings[player * 150];
    all = 1;
    if (record[0x78] == 1 && record[0x91] == 0) {
        if (Defs_TestBit(&D_80102B00->name[player * 400] + 0x4A, 0x31) == 0) {
            for (i = 0; i < 4; i++) {
                if (all != 1) {
                    return;
                }
                if (Defs_TestBit(&D_80102B00->name[player * 400] + 0x124, i) == 0) {
                    all = 0;
                }
            }
            if (all == 1) {
                Defs_SetBitValue(&D_80102B00->name[player * 400] + 0x4A, 0x31, 1);
                *award = 0x31;
            }
        }
    }
}

 /* extern */
s32 func_80426004_de(s32 index) {
    s32 recordOffset;
    s32 slot;
    s32 count;
    void *record;
    count = 0;
    slot = 0;
    recordOffset = index * 0x190;
    record = recordOffset + D_800FEB4A;
    do {
        if (Defs_TestBit(recordOffset + D_800FEB4A, slot) == 1) {
            count += 1;
        }
        slot += 1;
        record = recordOffset + D_800FEB4A;
    } while (slot < 0x32);
    return count;
}

void func_80426090_de(Arg *arg0) {
    s32 temp_s0;
    s32 temp_v0;
    s32 i;
    StateRecAt91 *temp_a0;
    Model *model;
    s32 temp_s3;
    temp_a0 = arg0->unk5D8;
    if (temp_a0->unk91 != 1) {
        i = 0;
        if (temp_a0->unk78 != 0) {
            model = (Model *)arg0->unk18;
            temp_s3 = temp_a0->unk7F * 0x190;
                        do {
                temp_s0 = model->slots[i];
                if (temp_s0 >= 0x4C3) {
                    temp_s0 = temp_s0 - 0x4C3;
                    temp_v0 = Player_HasProfileUnlockFlag(temp_s3 + D_80102B00->name, temp_s0);
                    if (temp_v0 == 1) {
                        arg0->slots[temp_s0].available = temp_v0;
                        arg0->slots[temp_s0].slot = i;
                    }
                }
                i += 1;
            } while (i < 8);
        }
    }
}

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800E91BC[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800EDFFC[1] = {
    0x00600061,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800DD97C[1] = {
    0x00426AB0,
};
#endif
