#include "include_asm.h"

#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/EFFECTRENDER.H"

#if defined(VERSION_US_REV1)
/* Minimal callback views established by ROM8043C810..C85C: the owner at+12
   supplies the descriptor whose option flags are at+728. */
#include "MENU/LEVELSELECT_TYPES.H"


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
        if (g_gameSettings.unlockedLevels & levelBit(level)) {
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

void Encoded_UpdateLevelSelectionAvailability(LevelSelectOwner *owner) {
    s32 level = firstUnlocked();
    g_encodedSelectedLevelIndex = level;
    if (level != -1) {
        owner->descriptor->flags |= 0x01800000;
    } else {
        owner->descriptor->flags &= 0xFE7FFFFF;
    }
    if (g_gameSettings.local) {
        owner->descriptor->flags &= 0xFE7FFFFF;
    }
}
#endif
#if VERSION_DE
INCLUDE_ASM("ovl_80400000", Encoded_UpdateLevelSelectionAvailability);
#endif
#if VERSION_EU
INCLUDE_ASM("ovl_80400000", Encoded_UpdateLevelSelectionAvailability);
#endif
#if VERSION_EU_X
INCLUDE_ASM("ovl_80400000", Encoded_UpdateLevelSelectionAvailability);
#endif
#if VERSION_US
INCLUDE_ASM("ovl_80400000", Encoded_UpdateLevelSelectionAvailability);
#endif
#if defined(VERSION_DE)
#ifdef NON_MATCHING
/* Fuzzy draft: inline-asm carrier of the original instructions (no C written yet). */
void Encoded_HandleUnlockedLevelSelection(void) {
    __asm__ volatile (
        ".set noreorder\n"
        ".set noat\n"
        "lui        $v1, %hi(g_encodedSelectedLevelIndex)\n"
        "lw         $v1, %lo(g_encodedSelectedLevelIndex)($v1)\n"
        "addiu      $sp, $sp, -0x20\n"
        "sw         $s1, 0x14($sp)\n"
        "addu       $s1, $a1, $zero\n"
        "sw         $ra, 0x18($sp)\n"
        "sltiu      $v0, $v1, 0xB\n"
        "beqz       $v0, .Lauto_8043C6C4\n"
        "sw        $s0, 0x10($sp)\n"
        "sll        $v0, $v1, 2\n"
        "lui        $at, %hi(jtbl_800DE1B8)\n"
        "addu       $at, $at, $v0\n"
        "lw         $v0, %lo(jtbl_800DE1B8)($at)\n"
        "jr         $v0\n"
        "nop\n"
        ".Lauto_8043C6C4:\n"
        "j          .Lauto_8043C718\n"
        "addiu     $s0, $zero, 0x3E8\n"
        "j          .Lauto_8043C718\n"
        "addiu     $s0, $zero, 0x7D0\n"
        "j          .Lauto_8043C718\n"
        "addiu     $s0, $zero, 0xBB8\n"
        "j          .Lauto_8043C718\n"
        "addiu     $s0, $zero, 0xFA0\n"
        "j          .Lauto_8043C718\n"
        "addiu     $s0, $zero, 0x1388\n"
        "j          .Lauto_8043C718\n"
        "addiu     $s0, $zero, 0x1770\n"
        "j          .Lauto_8043C718\n"
        "addiu     $s0, $zero, 0x1CE9\n"
        "j          .Lauto_8043C718\n"
        "addiu     $s0, $zero, 0x1D4D\n"
        "j          .Lauto_8043C718\n"
        "addiu     $s0, $zero, 0x1DB1\n"
        "j          .Lauto_8043C718\n"
        "addiu     $s0, $zero, 0x1DB2\n"
        "addiu      $s0, $zero, 0x1F40\n"
        ".Lauto_8043C718:\n"
        "lw         $a0, 0x20($s1)\n"
        "jal        Control_IsAButtonPressed\n"
        "nop\n"
        "beqz       $v0, .Lauto_8043C7B8\n"
        "addiu     $v0, $zero, 0x1F40\n"
        "bne        $s0, $v0, .Lauto_8043C75C\n"
        "addiu     $v0, $zero, 0x1\n"
        "lui        $at, %hi(D_80142226)\n"
        "sb         $v0, %lo(D_80142226)($at)\n"
        "jal        Confirming_SelectConfirmingController\n"
        "addu      $a0, $s1, $zero\n"
        "lui        $a0, %hi(g_gameSession)\n"
        "addiu      $a0, $a0, %lo(g_gameSession)\n"
        "jal        SetN64_SetTransitionTarget\n"
        "addiu     $a1, $zero, 0x11\n"
        "j          .Lauto_8043C984\n"
        "addiu     $v0, $zero, 0x1\n"
        ".Lauto_8043C75C:\n"
        "jal        SetN64_IsModeThirteen\n"
        "nop\n"
        "beqz       $v0, .Lauto_8043C784\n"
        "addu      $a1, $s0, $zero\n"
        "lui        $a0, %hi(g_world)\n"
        "addiu      $a0, $a0, %lo(g_world)\n"
        "jal        Scene_SetSelection\n"
        "addiu     $a2, $zero, 0x2\n"
        "j          .Lauto_8043C984\n"
        "addu      $v0, $zero, $zero\n"
        ".Lauto_8043C784:\n"
        "addu       $a0, $s1, $zero\n"
        "lui        $v1, %hi(g_gameSettings)\n"
        "addiu      $v1, $v1, %lo(g_gameSettings)\n"
        "addiu      $v0, $zero, 0x1\n"
        "sb         $zero, 0x1D($v1)\n"
        "jal        Confirming_SelectConfirmingController\n"
        "sb        $v0, 0x1E($v1)\n"
        "lui        $a0, %hi(g_gameSession)\n"
        "addiu      $a0, $a0, %lo(g_gameSession)\n"
        "jal        SetN64_SelectSpawnAndStartSession\n"
        "addu      $a1, $s0, $zero\n"
        "j          .Lauto_8043C984\n"
        "addiu     $v0, $zero, 0x1\n"
        ".Lauto_8043C7B8:\n"
        "lw         $a0, 0x20($s1)\n"
        "jal        Control_IsLeftPressed\n"
        "nop\n"
        "beqz       $v0, .Lauto_8043C89C\n"
        "addu      $a0, $zero, $zero\n"
        "lui        $a2, %hi(jtbl_800DE1E8)\n"
        "addiu      $a2, $a2, %lo(jtbl_800DE1E8)\n"
        "lui        $v1, %hi(g_encodedSelectedLevelIndex)\n"
        "lw         $v1, %lo(g_encodedSelectedLevelIndex)($v1)\n"
        "lui        $a1, %hi(g_menuOptionAvailabilityFlags)\n"
        "lw         $a1, %lo(g_menuOptionAvailabilityFlags)($a1)\n"
        "addiu      $v1, $v1, -0x1\n"
        ".Lauto_8043C7E8:\n"
        "slti       $v0, $v1, 0xB\n"
        "bnez       $v0, .Lauto_8043C7FC\n"
        "nop\n"
        "j          .Lauto_8043C804\n"
        "addu      $v1, $zero, $zero\n"
        ".Lauto_8043C7FC:\n"
        "bltzl      $v1, .Lauto_8043C804\n"
        "addiu     $v1, $zero, 0xA\n"
        ".Lauto_8043C804:\n"
        "sltiu      $v0, $v1, 0xB\n"
        "beqz       $v0, .Lauto_8043C820\n"
        "sll       $v0, $v1, 2\n"
        "addu       $v0, $v0, $a2\n"
        "lw         $v0, 0x0($v0)\n"
        "jr         $v0\n"
        "nop\n"
        ".Lauto_8043C820:\n"
        "j          .Lauto_8043C874\n"
        "lui       $v0, (0x10000 >> 16)\n"
        "j          .Lauto_8043C874\n"
        "lui       $v0, (0x20000 >> 16)\n"
        "j          .Lauto_8043C874\n"
        "lui       $v0, (0x40000 >> 16)\n"
        "j          .Lauto_8043C874\n"
        "lui       $v0, (0x80000 >> 16)\n"
        "j          .Lauto_8043C874\n"
        "lui       $v0, (0x100000 >> 16)\n"
        "j          .Lauto_8043C874\n"
        "lui       $v0, (0x200000 >> 16)\n"
        "j          .Lauto_8043C874\n"
        "lui       $v0, (0x800000 >> 16)\n"
        "j          .Lauto_8043C874\n"
        "lui       $v0, (0x400000 >> 16)\n"
        "j          .Lauto_8043C874\n"
        "lui       $v0, (0x1000000 >> 16)\n"
        "j          .Lauto_8043C874\n"
        "lui       $v0, (0x2000000 >> 16)\n"
        "lui        $v0, (0x4000000 >> 16)\n"
        ".Lauto_8043C874:\n"
        "and        $v0, $a1, $v0\n"
        "bnez       $v0, .Lauto_8043C894\n"
        "addiu     $a0, $a0, 0x1\n"
        "slti       $v0, $a0, 0xB\n"
        "bnel       $v0, $zero, .Lauto_8043C7E8\n"
        "addiu     $v1, $v1, -0x1\n"
        "j          .Lauto_8043C978\n"
        "addiu     $v0, $zero, -0x1\n"
        ".Lauto_8043C894:\n"
        "j          .Lauto_8043C978\n"
        "addu      $v0, $v1, $zero\n"
        ".Lauto_8043C89C:\n"
        "lw         $a0, 0x20($s1)\n"
        "jal        Control_IsRightPressed\n"
        "nop\n"
        "beqz       $v0, .Lauto_8043C984\n"
        "addu      $v0, $zero, $zero\n"
        "addu       $a0, $zero, $zero\n"
        "lui        $a2, %hi(jtbl_800DE218)\n"
        "addiu      $a2, $a2, %lo(jtbl_800DE218)\n"
        "lui        $v1, %hi(g_encodedSelectedLevelIndex)\n"
        "lw         $v1, %lo(g_encodedSelectedLevelIndex)($v1)\n"
        "lui        $a1, %hi(g_menuOptionAvailabilityFlags)\n"
        "lw         $a1, %lo(g_menuOptionAvailabilityFlags)($a1)\n"
        "addiu      $v1, $v1, 0x1\n"
        ".Lauto_8043C8D0:\n"
        "slti       $v0, $v1, 0xB\n"
        "bnez       $v0, .Lauto_8043C8E4\n"
        "nop\n"
        "j          .Lauto_8043C8EC\n"
        "addu      $v1, $zero, $zero\n"
        ".Lauto_8043C8E4:\n"
        "bltzl      $v1, .Lauto_8043C8EC\n"
        "addiu     $v1, $zero, 0xA\n"
        ".Lauto_8043C8EC:\n"
        "sltiu      $v0, $v1, 0xB\n"
        "beqz       $v0, .Lauto_8043C908\n"
        "sll       $v0, $v1, 2\n"
        "addu       $v0, $v0, $a2\n"
        "lw         $v0, 0x0($v0)\n"
        "jr         $v0\n"
        "nop\n"
        ".Lauto_8043C908:\n"
        "j          .Lauto_8043C95C\n"
        "lui       $v0, (0x10000 >> 16)\n"
        "j          .Lauto_8043C95C\n"
        "lui       $v0, (0x20000 >> 16)\n"
        "j          .Lauto_8043C95C\n"
        "lui       $v0, (0x40000 >> 16)\n"
        "j          .Lauto_8043C95C\n"
        "lui       $v0, (0x80000 >> 16)\n"
        "j          .Lauto_8043C95C\n"
        "lui       $v0, (0x100000 >> 16)\n"
        "j          .Lauto_8043C95C\n"
        "lui       $v0, (0x200000 >> 16)\n"
        "j          .Lauto_8043C95C\n"
        "lui       $v0, (0x800000 >> 16)\n"
        "j          .Lauto_8043C95C\n"
        "lui       $v0, (0x400000 >> 16)\n"
        "j          .Lauto_8043C95C\n"
        "lui       $v0, (0x1000000 >> 16)\n"
        "j          .Lauto_8043C95C\n"
        "lui       $v0, (0x2000000 >> 16)\n"
        "lui        $v0, (0x4000000 >> 16)\n"
        ".Lauto_8043C95C:\n"
        "and        $v0, $a1, $v0\n"
        "bnez       $v0, .Lauto_8043C894\n"
        "addiu     $a0, $a0, 0x1\n"
        "slti       $v0, $a0, 0xB\n"
        "bnel       $v0, $zero, .Lauto_8043C8D0\n"
        "addiu     $v1, $v1, 0x1\n"
        "addiu      $v0, $zero, -0x1\n"
        ".Lauto_8043C978:\n"
        "lui        $at, %hi(g_encodedSelectedLevelIndex)\n"
        "sw         $v0, %lo(g_encodedSelectedLevelIndex)($at)\n"
        "addu       $v0, $zero, $zero\n"
        ".Lauto_8043C984:\n"
        "lw         $ra, 0x18($sp)\n"
        "lw         $s1, 0x14($sp)\n"
        "lw         $s0, 0x10($sp)\n"
        "jr         $ra\n"
        "addiu     $sp, $sp, 0x20\n"
        ".set at\n"
    );
}
#else
INCLUDE_ASM("ovl_80400000", Encoded_HandleUnlockedLevelSelection);
#endif
#endif
