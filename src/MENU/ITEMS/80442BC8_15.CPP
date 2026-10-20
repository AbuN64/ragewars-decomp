#include "include_asm.h"
#include "MENU/OBJECT1C8.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/S1_2.H"
#include "COMMON/ACTORRECAT5E0.H"
#include "SYSTEM_2/8025E280.H"
#include "SDK/AUDIO/802BD1A8_19.H"

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_8044342C_de(void) {
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_80443434_de(void) {
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_8044343C_de(void) {
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_80443444_de(void) {
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_8044344C_de(void) {
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_80443454_de(void) {
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_8044345C_de(void) {
    return 0;
}

/* Calls func_8025E384_de and passes what func_8025CC6C_de returns to func_8025CB0C_de; then, when D_801540F0
   is set, calls func_80442384_de with the three arguments, otherwise func_8026495C_de. Returns one. */
extern s32 func_8025CC6C_de();
struct SoundVoicePool;
extern void func_8025CB0C_de(struct SoundVoicePool *);
extern void func_80442384_de(void *, void *, void *);

s32 func_80443464_de(void *first, void *second, void *third) {
    func_8025E384_de();
    func_8025CB0C_de(func_8025CC6C_de());
    if (D_801540F0 == 0) {
        func_8026495C_de();
        return 1;
    }
    func_80442384_de(first, second, third);
    return 1;
}

#ifdef NON_MATCHING
#include "MENU/PLAYER_STATUS_TEXT.H"
#include "TYPES.H"

/* Formats a player's status line into a menu field's text through func_802BD320_de (sprintf): one message when the player is its own partner, otherwise a message chosen by the player's mode at 0x12F0 (0 to 6), naming the partner's character from 0x84 of its record at 0x5D8 when there is a partner. */
typedef struct Player {
    char pad0[0x5D8];
    char *record;
    char pad5DC[0x12EC - 0x5DC];
    struct Player *partner;
    unsigned int mode;
} Player;

typedef struct {
    char pad0[0x10];
    char **text;
} Field;

typedef struct {
    char pad0[0x18];
    Field *field;
} Item;

typedef struct {
    char pad0[0x1C];
    Player *player;
} Owner;


s32 func_804434E0_de(Item *item, Owner *owner) {
    Player *player = owner->player;
    char *text = *item->field->text;
    if (player->partner == player) {
        func_802BD320_de(text, playerStatusText0());
    } else if (player->partner != 0) {
        switch (player->mode) {
        case 0: func_802BD320_de(text, playerStatusText1(), player->partner->record + 0x84); break;
        case 1: func_802BD320_de(text, playerStatusText2(), player->partner->record + 0x84); break;
        case 2: func_802BD320_de(text, playerStatusText3(), player->partner->record + 0x84); break;
        case 3: func_802BD320_de(text, playerStatusText4(), player->partner->record + 0x84); break;
        case 4: func_802BD320_de(text, playerStatusText5(), player->partner->record + 0x84); break;
        case 5: func_802BD320_de(text, playerStatusText6(), player->partner->record + 0x84); break;
        case 6: func_802BD320_de(text, playerStatusText7(), player->partner->record + 0x84); break;
        }
    } else {
        switch (player->mode) {
        case 0: func_802BD320_de(text, playerStatusText8()); break;
        case 1: func_802BD320_de(text, playerStatusText9()); break;
        case 2: func_802BD320_de(text, playerStatusText10()); break;
        case 3: func_802BD320_de(text, playerStatusText11()); break;
        case 4: func_802BD320_de(text, playerStatusText12()); break;
        case 5: func_802BD320_de(text, playerStatusText13()); break;
        case 6: func_802BD320_de(text, playerStatusText14()); break;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_804434E0_de);
#endif
