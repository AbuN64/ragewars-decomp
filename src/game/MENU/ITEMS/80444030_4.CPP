#include "include_asm.h"
#include "MENU/HOLDERRECAT1CV2.H"
#include "TYPES.H"
#include "MENU/ITEMS/80444030_4.H"

#if !(defined(VERSION_DE))
#ifdef NON_MATCHING
/* Resets the game record D_801462C8 to its defaults: colors, option bytes, the ten enabled flags,
   and nine 0x96-byte settings records, each re-seeded by the per-record reset. */
typedef struct CPlayerOptions_t {
    u8 pad00[0x78];
    u8 f78;
    u8 f79;
    u8 f7A;
    u8 f7B;
    u8 f7C;
    u8 f7D;
    u8 f7E;
    u8 f7F;
    u8 f80;
    u8 f81;
    u8 f82;
    u8 f83;
    u8 pad84[0x10];
    u8 f94;
    u8 f95;
} CPlayerOptions;

typedef struct GameRecord80445074 {
    u32 flags;
    s32 next;
    s32 mode;
    u8 pad0C;
    u8 field0D;
    u8 pad0E[2];
    s32 buttons;
    s16 options;
    u8 hudCopy;
    u8 flag17;
    u8 colorR;
    u8 colorG;
    u8 colorB;
    u8 flag1B;
    u8 flag1C;
    u8 field1D;
    u8 field1E;
    u8 flag1F;
    f32 speedFactor;
    u8 limits[4];
    u8 flag28;
    u8 flag29;
    u8 flag2A;
    u8 flag2B;
    u8 enabled[10];
    u8 pad36[4];
    CPlayerOptions defaultSlot;
    CPlayerOptions slots[8];
    u8 flag580;
} GameRecord80445074;

extern f32 D_800E2798[];

static __inline__ void resetPlayerSlot(CPlayerOptions *slot, u8 index) {
        slot->f78 = 0;
        slot->f79 = 0x86;
        slot->f7A = 0x84;
        slot->f7C = 0;
        slot->f7B = 0;
        slot->f7D = 1;
        slot->f7E = 0;
        slot->f7F = index;
        slot->f80 = 0;
        slot->f82 = 0;
        slot->f83 = 0;
        slot->f81 = 0;
        slot->f94 = 0;
        slot->f95 = 0;
        RESET_SLOT_80445074((u8 *)slot);
}

/* 4/117 aligned edits; remaining: sched1 ties place the options-byte read and the copy of the constant 1
   later than the ROM. Read as a table element, the default speed D_800E2798 stays ahead of the header stores;
   the flag17 store between the 0x04000000 and -1 stores of next keeps both of them live. */
void Items_ResetGameOptions(GameRecord80445074 *game) {
    s32 i;
    u8 initialHudByte;
    f32 speed;

    game->colorR = 0x80;
    game->colorG = 0xFA;
    game->colorB = 0xFF;
    game->options = 0x80;
    initialHudByte = (u8)game->options;
    speed = D_800E2798[0];
    game->mode = 0x10;
    game->flags = 0;
    game->next = 0;
    game->flags = 0x04000000;
    game->next = 0x04000000;
    game->flag17 = 1;
    game->next = -1;
    game->buttons = 0;
    game->flag1B = 1;
    game->flag1C = 0;
    game->flag1F = 0;
    game->flag580 = 0;
    game->limits[0] = 10;
    game->limits[1] = 10;
    game->limits[2] = 10;
    game->limits[3] = 10;
    game->flag28 = 1;
    game->flag29 = 0;
    game->flag2A = 0;
    game->flag2B = 1;
    game->hudCopy = initialHudByte;
    game->speedFactor = speed;
    for (i = 0; i < 10; i++) {
        game->enabled[i] = 1;
    }
    game->pad36[0] = 0;
    game->pad36[1] = 3;
    game->pad36[2] = 0;
    game->pad36[3] = 3;
    for (i = 0; i < 8; i++) {
        resetPlayerSlot(&game->slots[i], i);
    }
    {
        CPlayerOptions *slot = &game->defaultSlot;
        slot->f79 = 0x86;
        slot->f78 = 0;
        slot->f7A = 0x84;
        slot->f7C = 0;
        slot->f7B = 0;
        slot->f7D = 1;
        slot->f7E = 0;
        slot->f7F = 0;
        slot->f80 = 0;
        slot->f82 = 0;
        slot->f83 = 0;
        slot->f81 = 0;
        slot->f94 = 0;
        slot->f95 = 0;
        RESET_SLOT_80445074((u8 *)slot);
    }
    game->defaultSlot.f78 = 1;
    game->field1D = 0;
    game->field1E = 1;
    game->field0D = 0;
}
#else
INCLUDE_ASM("ovl_80400000", Items_ResetGameOptions);
#endif
#endif

/* Resets the byte fields from offset 0x78 of a record, sets 0x79 to 0x86, 0x7A to 0x84 and 0x7D to
   one, stores the second argument at 0x7F, and calls 
#if defined(VERSION_EU) || defined(VERSION_EU_X)
func_80444F30_eu
#else
Items_SetDefaultPlayerName
#endif
 on the record. */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern void func_80444F30_eu(u8 *);
#else
extern void Items_SetDefaultPlayerName(u8 *);
#endif

void Items_ResetPlayerSettings(u8 *record, u8 value) {
    record[0x79] = 0x86;
    record[0x7A] = 0x84;
    record[0x78] = 0;
    record[0x7C] = 0;
    record[0x7B] = 0;
    record[0x7D] = 1;
    record[0x7E] = 0;
    record[0x7F] = value;
    record[0x80] = 0;
    record[0x82] = 0;
    record[0x83] = 0;
    record[0x81] = 0;
    record[0x94] = 0;
    record[0x95] = 0;
    
#if defined(VERSION_EU) || defined(VERSION_EU_X)
func_80444F30_eu
#else
Items_SetDefaultPlayerName
#endif
(record);
}

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
#include "TYPES.H"

/* Copies an eight-byte preset into offset 0x84 of a record, choosing the preset table by the record's kind byte at 0x7F: kinds 1 to 3 use their own tables, kinds 4 to 7 leave the record unchanged, and any other kind uses the default table. */
extern u8 *D_800D3C44;
extern u8 *D_800D3C48;
extern u8 *D_800D3C4C;
extern u8 *D_800D3C50;

void Items_SetDefaultPlayerName(u8 *record) {
    s32 i;

    switch ((signed char)record[0x7F]) {
    case 0:
    default:
        for (i = 0; i < 8; i++) {
            (record + i)[0x84] = D_800D3C44[i];
        }
        return;
    case 1:
        for (i = 0; i < 8; i++) {
            (record + i)[0x84] = D_800D3C48[i];
        }
        return;
    case 2:
        for (i = 0; i < 8; i++) {
            (record + i)[0x84] = D_800D3C4C[i];
        }
        return;
    case 3:
        for (i = 0; i < 8; i++) {
            (record + i)[0x84] = D_800D3C50[i];
        }
        return;
    case 4:
    case 5:
    case 6:
    case 7:
        return;
    }
}
#endif
