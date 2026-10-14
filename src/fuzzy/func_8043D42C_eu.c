#include "types.h"

/* Minimal callback views established by ROM8043C810..C85C: the owner at+12
   supplies the descriptor whose option flags are at+728. */
typedef struct LevelSelectDescriptor {
    u8 unknown00[0x2D8];
    u32 flags;
} LevelSelectDescriptor;
typedef struct LevelSelectOwner {
    u32 unknown00[3];
    LevelSelectDescriptor *descriptor;
} LevelSelectOwner;
extern s32 D_80154034;
extern s32 D_801462CC;
extern u8 D_801462E5;

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

/* Choose the first unlocked level, then enable the corresponding widget flags. */
static inline s32 firstUnlocked(void) {
    s32 level = 0;
    s32 i;
    for (i = 0; i < 11; i++) {
        if (D_801462CC & levelBit(level)) {
            return level;
        }
        level++;
        if (level >= 11) {
            level = 0;
        } else if (level < 0) {
            level = 10;
        }
    }
    return -1;
}

void func_8043D42C_eu(LevelSelectOwner *owner) {
    s32 level = firstUnlocked();
    D_80154034 = level;
    if (level != -1) {
        owner->descriptor->flags |= 0x01800000;
    } else {
        owner->descriptor->flags &= 0xFE7FFFFF;
    }
    if (D_801462E5) {
        owner->descriptor->flags &= 0xFE7FFFFF;
    }
}
