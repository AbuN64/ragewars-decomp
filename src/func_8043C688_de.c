#include "shared/world.h"
#include "types.h"
typedef struct Shared_MenuSelection {
    u32 unknown0;
    s8 index;
} Shared_MenuSelection;
typedef struct Shared_MenuHandle {
    u8 unknown0[0x1C];
    struct SharedPlayer *owner;
    Shared_MenuSelection *selection;
} Shared_MenuHandle;
typedef struct Shared_MenuInput {
    u32 unknown0[8];
    s32 buttons;
} Shared_MenuInput;

#include "types.h"
typedef struct Shared_GameSlot Shared_GameSlot;
struct Shared_GameSlot {
    u8 enabled;
    u8 unknown01[6];
    u8 slot;
    s8 kind;
    u8 unknown09[0x10];
    u8 controller;
    u8 unknown1A[2];
    u8 role;
    u8 escort;
    u8 secondListMode;
    u8 unknown1F[0x77];
};
typedef struct Shared_Game Shared_Game;
struct Shared_Game {
    u32 flags;
    u8 unknown04[9];
    u8 controllerMode;
    u8 unknown0E[2];
    s32 buttons;
    u8 unknown14[7];
    u8 firstListMode;
    u8 unknown1C;
    u8 local;
    u8 mode1E;
    u8 unknown1F[0x129];
    Shared_GameSlot slots[8];
    u8 unknown5F8[0x34];
    s32 unk62C;
    u8 unknown630[0x40];
    s32 split;
    u32 unknown674[3];
    s32 humanWon;
};

#include "common/unused.h"

#include "types.h"

extern Shared_Game D_801462C8;
extern s32 D_801462CC;

extern s32 D_80154034;
extern char D_8011FAC0[];


extern s32 func_8026437C_de(s32 buttons);


extern void func_80293284_de(void *menu, s32 target);
extern s32 func_802934F8_de(void);

extern void func_8043DE50_de(Shared_MenuInput *pad);
extern void func_8044D528_de(void *menu, s32 target, s32 arg2);

static inline s32 levelBit(s32 level) {
    s32 bit;

    switch (level) {
    default:
    case 0:
        bit = 0x10000;
        break;
    case 1:
        bit = 0x20000;
        break;
    case 2:
        bit = 0x40000;
        break;
    case 3:
        bit = 0x80000;
        break;
    case 4:
        bit = 0x100000;
        break;
    case 5:
        bit = 0x200000;
        break;
    case 6:
        bit = 0x800000;
        break;
    case 7:
        bit = 0x400000;
        break;
    case 8:
        bit = 0x1000000;
        break;
    case 9:
        bit = 0x2000000;
        break;
    case 10:
        bit = 0x4000000;
        break;
    }
    return bit;
}

static inline s32 findUnlocked(s32 level, s32 step) {
    s32 i;

    for (i = 0; i < 11; i++) {
        level += step;
        if (level >= 11) {
            level = 0;
        } else if (level < 0) {
            level = 10;
        }
        if (D_801462CC & levelBit(level)) {
            return level;
        }
    }
    return -1;
}

s32 func_8043C688_de(s32 arg0, Shared_MenuInput *pad) {
    s32 target;
    Shared_Game *rules;

    switch (D_80154034) {
    default:
    case 0:
        target = 1000;
        break;
    case 1:
        target = 2000;
        break;
    case 2:
        target = 3000;
        break;
    case 3:
        target = 4000;
        break;
    case 4:
        target = 5000;
        break;
    case 5:
        target = 6000;
        break;
    case 6:
        target = 7401;
        break;
    case 7:
        target = 7501;
        break;
    case 8:
        target = 7601;
        break;
    case 9:
        target = 7602;
        break;
    case 10:
        target = 8000;
        break;
    }

    if (func_8026437C_de(pad->buttons) != 0) {
        if (target == 8000) {
            D_80142226 = 1;
            func_8043DE50_de(pad);
            func_80293824_de(D_8011FAC0, 0x11);
            return 1;
        }
        if (func_802934F8_de() != 0) {
            func_8044D528_de(&D_8011FE88, target, 2);
            return 0;
        }
        rules = &D_801462C8;
        rules->local = 0;
        rules->mode1E = 1;
        func_8043DE50_de(pad);
        func_80293284_de(D_8011FAC0, target);
        return 1;
    }

    if (((s32 (*)(s32))func_80264388_de)(pad->buttons) != 0) {
        D_80154034 = findUnlocked(D_80154034, -1);
    } else if (((s32 (*)(s32))func_802643A0_de)(pad->buttons) != 0) {
        D_80154034 = findUnlocked(D_80154034, 1);
    }
    return 0;
}
