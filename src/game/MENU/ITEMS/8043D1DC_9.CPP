#include "include_asm.h"
#include "MENU/HOLDERRECAT1CV2.H"
#include "TYPES.H"
#include "MENU/ITEMS/80444030_4.H"

#if defined(VERSION_DE)
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

extern f32 D_800E2798;

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

/* 17/117 aligned edits; remaining: enabled-loop induction and header word stores. */
void Items_ResetGameOptions(GameRecord80445074 *game) {
    s32 i;
    u8 initialHudByte;
    f32 speed;

    game->colorR = 0x80;
    game->colorG = 0xFA;
    game->colorB = 0xFF;
    game->options = 0x80;
    initialHudByte = (u8)game->options;
    speed = D_800E2798;
    game->mode = 0x10;
    game->flags = 0;
    game->next = 0;
    game->flags = 0x04000000;
    game->next = 0x04000000;
    game->next = -1;
    game->flag17 = 1;
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
    for (i = 9; i >= 0; i--) {
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
