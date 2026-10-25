#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"

#if defined(VERSION_US)
#ifdef NON_MATCHING
/* Fuzzy draft: inline-asm carrier of the original instructions (no C written yet). */
void func_8043C4F4_us(void) {
    __asm__ volatile (
        ".set noreorder\n"
        ".set noat\n"
        "sltiu      $s1, $s1, 0x3133\n"
        "daddiu     $at, $s3, 0x6B65\n"
        ".word 0x042E656F\n"
        "addiu      $a0, $a0, -0x1\n"
        "sltiu      $v0, $a0, 0x21\n"
        "beqz       $v0, .Lauto_8043C724\n"
        "sll       $v0, $a0, 2\n"
        "lui        $at, %hi(jtbl_auto_800DCD00)\n"
        "addu       $at, $at, $v0\n"
        "lw         $v0, %lo(jtbl_auto_800DCD00)($at)\n"
        "jr         $v0\n"
        "nop\n"
        "lui        $v0, %hi(D_00435F70)\n"
        "addiu      $v0, $v0, %lo(D_00435F70)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_0043630C)\n"
        "addiu      $v0, $v0, %lo(D_0043630C)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_00436634)\n"
        "addiu      $v0, $v0, %lo(D_00436634)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_00420E00)\n"
        "addiu      $v0, $v0, %lo(D_00420E00)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_0043C1D0)\n"
        "addiu      $v0, $v0, %lo(D_0043C1D0)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_00429058)\n"
        "addiu      $v0, $v0, %lo(D_00429058)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_004290E8)\n"
        "addiu      $v0, $v0, %lo(D_004290E8)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_00424528)\n"
        "addiu      $v0, $v0, %lo(D_00424528)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_0042359C)\n"
        "addiu      $v0, $v0, %lo(D_0042359C)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_00439390)\n"
        "addiu      $v0, $v0, %lo(D_00439390)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_00436FE4)\n"
        "addiu      $v0, $v0, %lo(D_00436FE4)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_00423930)\n"
        "addiu      $v0, $v0, %lo(D_00423930)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_00437454)\n"
        "addiu      $v0, $v0, %lo(D_00437454)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_0043962C)\n"
        "addiu      $v0, $v0, %lo(D_0043962C)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_0041DF24)\n"
        "addiu      $v0, $v0, %lo(D_0041DF24)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_0042DB38)\n"
        "addiu      $v0, $v0, %lo(D_0042DB38)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_0043905C)\n"
        "addiu      $v0, $v0, %lo(D_0043905C)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_00437868)\n"
        "addiu      $v0, $v0, %lo(D_00437868)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_00437B98)\n"
        "addiu      $v0, $v0, %lo(D_00437B98)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_0042BCB0)\n"
        "addiu      $v0, $v0, %lo(D_0042BCB0)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_00429B74)\n"
        "addiu      $v0, $v0, %lo(D_00429B74)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_0041F118)\n"
        "addiu      $v0, $v0, %lo(D_0041F118)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_0042931C)\n"
        "addiu      $v0, $v0, %lo(D_0042931C)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_00435C54)\n"
        "addiu      $v0, $v0, %lo(D_00435C54)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_00423B88)\n"
        "addiu      $v0, $v0, %lo(D_00423B88)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_00439938)\n"
        "addiu      $v0, $v0, %lo(D_00439938)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_0042247C)\n"
        "addiu      $v0, $v0, %lo(D_0042247C)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_00421E00)\n"
        "addiu      $v0, $v0, %lo(D_00421E00)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_0042DFF0)\n"
        "addiu      $v0, $v0, %lo(D_0042DFF0)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_0041C5EC)\n"
        "addiu      $v0, $v0, %lo(D_0041C5EC)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_00421A88)\n"
        "addiu      $v0, $v0, %lo(D_00421A88)\n"
        "jr         $ra\n"
        "nop\n"
        "lui        $v0, %hi(D_0043A014)\n"
        "addiu      $v0, $v0, %lo(D_0043A014)\n"
        "jr         $ra\n"
        "nop\n"
        ".Lauto_8043C724:\n"
        "jr         $ra\n"
        "addu      $v0, $zero, $zero\n"
        ".set at\n"
    );
}
#else
INCLUDE_ASM("ovl_80400000", func_8043C4F4_us);
#endif
#endif

#if defined(VERSION_US)
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

void func_8043C72C_us(LevelSelectOwner *owner) {
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
INCLUDE_ASM("ovl_80400000", func_8043C72C_us);
#endif
#endif
