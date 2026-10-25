#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/WORLD.H"
#include "TYPES.H"

#if defined(VERSION_DE)
const unsigned int rodata_func_8043C688_de_800E21E8[35] = {
    0x0043C6C4, 0x0043C6CC, 0x0043C6D4, 0x0043C6DC, 0x0043C6E4, 0x0043C6EC, 0x0043C6F4, 0x0043C6FC,
    0x0043C704, 0x0043C70C, 0x0043C714, 0x00000000, 0x0043C820, 0x0043C828, 0x0043C830, 0x0043C838,
    0x0043C840, 0x0043C848, 0x0043C850, 0x0043C858, 0x0043C860, 0x0043C868, 0x0043C870, 0x00000000,
    0x0043C908, 0x0043C910, 0x0043C918, 0x0043C920, 0x0043C928, 0x0043C930, 0x0043C938, 0x0043C940,
    0x0043C948, 0x0043C950, 0x0043C958,
};
#endif

#if defined(VERSION_DE)
#ifdef NON_MATCHING
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
extern s32 D_auto_004360EC;

s32 *func_8043C314_de(s32 arg0) {
    arg0 -= 1;
    return &D_auto_004360EC;
}
#else
INCLUDE_ASM("ovl_80400000", func_8043C314_de);
#endif
#endif

#if defined(VERSION_DE)
#ifdef NON_MATCHING
/* Fuzzy draft: inline-asm carrier of the original instructions (no C written yet). */
void func_8043C324_de(void) {
    __asm__ volatile (
        ".set noreorder\n"
        ".set noat\n"
        "sltiu      $v0, $a0, 0x21\n"
        "beqz       $v0, .Lauto_8043C544\n"
        "sll       $v0, $a0, 2\n"
        "lui        $at, %hi(data_func_8043C324_de_800DE050)\n"
        "addu       $at, $at, $v0\n"
        "lw         $v0, %lo(data_func_8043C324_de_800DE050)($at)\n"
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
        ".Lauto_8043C544:\n"
        "jr         $ra\n"
        "addu      $v0, $zero, $zero\n"
        ".set at\n"
    );
}
#else
INCLUDE_ASM("ovl_80400000", func_8043C324_de);
#endif
#endif

#if defined(VERSION_DE)
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

void func_8043C54C_de(LevelSelectOwner *owner) {
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
INCLUDE_ASM("ovl_80400000", func_8043C54C_de);
#endif
#endif

#if defined(VERSION_DE)
#ifdef NON_MATCHING
/* Fuzzy draft: inline-asm carrier of the original instructions (no C written yet). */
void func_8043C688_de(void) {
    __asm__ volatile (
        ".set noreorder\n"
        ".set noat\n"
        "lui        $v1, %hi(D_80154034)\n"
        "lw         $v1, %lo(D_80154034)($v1)\n"
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
        "jal        Render_IsAButtonPressed\n"
        "nop\n"
        "beqz       $v0, .Lauto_8043C7B8\n"
        "addiu     $v0, $zero, 0x1F40\n"
        "bne        $s0, $v0, .Lauto_8043C75C\n"
        "addiu     $v0, $zero, 0x1\n"
        "lui        $at, %hi(D_80142226)\n"
        "sb         $v0, %lo(D_80142226)($at)\n"
        "jal        Ovlgame_SelectConfirmingController\n"
        "addu      $a0, $s1, $zero\n"
        "lui        $a0, %hi(D_8011FAC0)\n"
        "addiu      $a0, $a0, %lo(D_8011FAC0)\n"
        "jal        Render_SetTransitionTarget\n"
        "addiu     $a1, $zero, 0x11\n"
        "j          .Lauto_8043C984\n"
        "addiu     $v0, $zero, 0x1\n"
        ".Lauto_8043C75C:\n"
        "jal        func_802934F8_de\n"
        "nop\n"
        "beqz       $v0, .Lauto_8043C784\n"
        "addu      $a1, $s0, $zero\n"
        "lui        $a0, %hi(D_8011FE88)\n"
        "addiu      $a0, $a0, %lo(D_8011FE88)\n"
        "jal        Items_SetSelection\n"
        "addiu     $a2, $zero, 0x2\n"
        "j          .Lauto_8043C984\n"
        "addu      $v0, $zero, $zero\n"
        ".Lauto_8043C784:\n"
        "addu       $a0, $s1, $zero\n"
        "lui        $v1, %hi(D_801462C8)\n"
        "addiu      $v1, $v1, %lo(D_801462C8)\n"
        "addiu      $v0, $zero, 0x1\n"
        "sb         $zero, 0x1D($v1)\n"
        "jal        Ovlgame_SelectConfirmingController\n"
        "sb        $v0, 0x1E($v1)\n"
        "lui        $a0, %hi(D_8011FAC0)\n"
        "addiu      $a0, $a0, %lo(D_8011FAC0)\n"
        "jal        func_80293284_de\n"
        "addu      $a1, $s0, $zero\n"
        "j          .Lauto_8043C984\n"
        "addiu     $v0, $zero, 0x1\n"
        ".Lauto_8043C7B8:\n"
        "lw         $a0, 0x20($s1)\n"
        "jal        func_80264388_de\n"
        "nop\n"
        "beqz       $v0, .Lauto_8043C89C\n"
        "addu      $a0, $zero, $zero\n"
        "lui        $a2, %hi(jtbl_800DE1E8)\n"
        "addiu      $a2, $a2, %lo(jtbl_800DE1E8)\n"
        "lui        $v1, %hi(D_80154034)\n"
        "lw         $v1, %lo(D_80154034)($v1)\n"
        "lui        $a1, %hi(D_801462CC)\n"
        "lw         $a1, %lo(D_801462CC)($a1)\n"
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
        "jal        func_802643A0_de\n"
        "nop\n"
        "beqz       $v0, .Lauto_8043C984\n"
        "addu      $v0, $zero, $zero\n"
        "addu       $a0, $zero, $zero\n"
        "lui        $a2, %hi(jtbl_800DE218)\n"
        "addiu      $a2, $a2, %lo(jtbl_800DE218)\n"
        "lui        $v1, %hi(D_80154034)\n"
        "lw         $v1, %lo(D_80154034)($v1)\n"
        "lui        $a1, %hi(D_801462CC)\n"
        "lw         $a1, %lo(D_801462CC)($a1)\n"
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
        "lui        $at, %hi(D_80154034)\n"
        "sw         $v0, %lo(D_80154034)($at)\n"
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
INCLUDE_ASM("ovl_80400000", func_8043C688_de);
#endif
#endif

#if !(defined(VERSION_DE))
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

#include "COMMON/SHARED_GAMESLOT.H"

#include "COMMON/UNUSED.H"


extern Shared_Game D_801462C8;

extern s32 D_80154034;
#include "COMMON/GAME_SESSION.H"
#include "OVLGAME/SHAREDRECAT224.H"


extern s32 Render_IsAButtonPressed(s32 buttons);


struct GameSession;
extern void func_80293284_de(struct GameSession *menu, s32 target);
extern s32 func_802934F8_de(void);

extern void Items_SetSelection(void *menu, s32 target, s32 arg2);

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
        if (D_801462C8.unlockedLevels & levelBit(level)) {
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

    if (Render_IsAButtonPressed(pad->buttons) != 0) {
        if (target == 8000) {
            D_801462C8.mode1E = 1;
            Ovlgame_SelectConfirmingController(pad);
            Render_SetTransitionTarget(&D_8011FAC0, 0x11);
            return 1;
        }
        if (func_802934F8_de() != 0) {
            Items_SetSelection(&D_8011FE88, target, 2);
            return 0;
        }
        rules = &D_801462C8;
        rules->local = 0;
        rules->mode1E = 1;
        Ovlgame_SelectConfirmingController(pad);
        func_80293284_de(&D_8011FAC0, target);
        return 1;
    }

    if (((s32 (*)(s32))func_80264388_de)(pad->buttons) != 0) {
        D_80154034 = findUnlocked(D_80154034, -1);
    } else if (((s32 (*)(s32))func_802643A0_de)(pad->buttons) != 0) {
        D_80154034 = findUnlocked(D_80154034, 1);
    }
    return 0;
}
#endif
