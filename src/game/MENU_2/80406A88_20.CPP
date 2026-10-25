#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"

#if defined(VERSION_EU_X)
#ifdef NON_MATCHING
#define func_8043C500_us_rev1 func_8043D324_eu_x
#include "TYPES.H"
#include "MENU/EXTERNS_2.H"


void *func_8043C500_us_rev1(s32 id) {
    switch (id) {
    case 1:
        return D_00435F70;
    case 31:
        return D_0043630C;
    case 32:
        return D_00436634;
    case 7:
        return D_00420E00;
    case 8:
        return D_0043C1D0;
    case 10:
        return D_00429058;
    case 15:
        return D_004290E8;
    case 3:
        return D_00424528;
    case 4:
        return D_0042359C;
    case 6:
        return D_00439390;
    case 5:
        return D_00436FE4;
    case 11:
        return D_00423930;
    case 12:
        return D_00437454;
    case 13:
        return D_0043962C;
    case 16:
        return D_0041DF24;
    case 17:
        return D_0042DB38;
    case 18:
        return D_0043905C;
    case 9:
        return D_00437868;
    case 30:
        return D_00437B98;
    case 20:
        return D_0042BCB0;
    case 21:
        return D_00429B74;
    case 23:
        return D_0041F118;
    case 14:
        return D_0042931C;
    case 19:
        return D_00435C54;
    case 22:
        return D_00423B88;
    case 24:
        return D_00439938;
    case 25:
        return D_0042247C;
    case 27:
        return D_00421E00;
    case 26:
        return D_0042DFF0;
    case 29:
        return D_0041C5EC;
    case 28:
        return D_00421A88;
    case 33:
        return D_0043A014;
    default:
        return 0;
    }
}
#else
INCLUDE_ASM("ovl_80400000", func_8043D324_eu_x);
#endif
#endif

#if defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "TYPES.H"

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
        if (D_801462C8.unlockedLevels & levelBit(level)) {
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

void func_8043D55C_eu_x(LevelSelectOwner *owner) {
    s32 level = firstUnlocked();
    D_80154034 = level;
    if (level != -1) {
        owner->descriptor->flags |= 0x01800000;
    } else {
        owner->descriptor->flags &= 0xFE7FFFFF;
    }
    if (D_801462C8.local) {
        owner->descriptor->flags &= 0xFE7FFFFF;
    }
}
#else
INCLUDE_ASM("ovl_80400000", func_8043D55C_eu_x);
#endif
#endif
