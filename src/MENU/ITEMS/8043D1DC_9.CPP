#include "include_asm.h"
#include "MENU/HOLDERRECAT1CV2.H"
#include "TYPES.H"
#include "MENU/ITEMS/80444030_4.H"

#if defined(VERSION_DE)
#ifdef NON_MATCHING
/* Resets the game record D_801462C8 to its defaults: colors, option bytes, the ten enabled flags,
   and nine 0x96-byte settings records, each re-seeded by the per-record reset. */
typedef struct SlotSettings80445074 {
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
} SlotSettings80445074;

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
    SlotSettings80445074 slots[9];
    u8 flag580;
} GameRecord80445074;

extern f32 D_800E2798;

void func_80445074_eu(GameRecord80445074 *game) {
    s32 i;

    game->colorR = 0x80;
    game->colorG = 0xFA;
    game->colorB = 0xFF;
    game->options = 0x80;
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
    game->hudCopy = (u8)game->options;
    game->speedFactor = D_800E2798;
    for (i = 9; i >= 0; i--) {
        game->enabled[i] = 1;
    }
    game->pad36[0] = 0;
    game->pad36[1] = 3;
    game->pad36[2] = 0;
    game->pad36[3] = 3;
    for (i = 0; i < 8; i++) {
        SlotSettings80445074 *s = &game->slots[i + 1];
        s->f78 = 0;
        s->f79 = 0x86;
        s->f7A = 0x84;
        s->f7C = 0;
        s->f7B = 0;
        s->f7D = 1;
        s->f7E = 0;
        s->f7F = i;
        s->f80 = 0;
        s->f82 = 0;
        s->f83 = 0;
        s->f81 = 0;
        s->f94 = 0;
        s->f95 = 0;
        RESET_SLOT_80445074((u8 *)s);
    }
    {
        SlotSettings80445074 *s = &game->slots[0];
        s->f79 = 0x86;
        s->f78 = 0;
        s->f7A = 0x84;
        s->f7C = 0;
        s->f7B = 0;
        s->f7D = 1;
        s->f7E = 0;
        s->f7F = 0;
        s->f80 = 0;
        s->f82 = 0;
        s->f83 = 0;
        s->f81 = 0;
        s->f94 = 0;
        s->f95 = 0;
        RESET_SLOT_80445074((u8 *)s);
    }
    game->slots[0].f78 = 1;
    game->field1D = 0;
    game->field1E = 1;
    game->field0D = 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_80445074_eu);
#endif
#endif
