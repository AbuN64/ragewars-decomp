#include "shared/player_status_text.h"
#include "types.h"

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

extern void func_802BD320_de(char *, char *, ...);

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
